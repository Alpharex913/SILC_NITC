%{
	#include <stdio.h>
	#include <stdlib.h>

	#include "func.c"

	#define inttype 0
	#define boolean 1
	#define strtype 2
	#define leaf 	3
	#define div 	4
	#define mul 	5
	#define sub	6
	#define plus    7
	#define assgn	8
	#define write 	9
	#define read	10
	#define connect 11
	#define greater_than	12
	#define less_than	13
	#define not_equal	14
	#define equal		15
	#define greater_equal	16
	#define less_equal	17
	#define if_part 	18
	#define else_part	19
	#define while_do	20
	#define cont_stmt 	21
	#define brk_stmt 	22
	#define leaf_arr	23
	#define mod		24	
	#define function	25
	#define func_call	26
	#define ret_stmt	27
	#define heap_init_stmt  28
	#define heap_alloc_stmt 29
	#define heap_free_stmt	30
	#define leaf_tf		31	
	#define leaf_cf		32	
	#define cf_func_call	33
	#define brk_point	34
	#define vr_tbl_alloc	35	
	#define class_func_call	36	

	extern FILE* yyin;
	extern int yylex();

	int yyerror(char*);
	
	int gv_pointer=4095;
	int lv_pointer=0;
	int arg_pointer=0;
	int field_index=0;
	int current_block=-1;
	int main_flag=0;
	int class_flag=0;		
	int saved_block_no=0;		
	int extend_size=0;		
	int rand_no=1;		
	int extend_flag=0;	
%}

%union 
{
	int integer;
	char* string;
	struct t_node* tree_node;
	struct symbol* gs_node;
	struct param_struct* param_node;
	struct field_list* field_node;
	struct type_table* table_node;
	struct class* class_node;
}

%type <class_node> class_def_block class_def class_def_list
%type <table_node> type_def type_def_list
%type <field_node> field_decl field_decl_list
%type <param_node> param param_list
%type <integer> gl_type l_type 
%type <string> field_type
%type <gs_node> gl_declarations gl_decllist gl_decl gl_varlist
%type <gs_node> l_declarations l_decllist l_decl l_varlist 
%type <tree_node> while_stmt if_stmt slist stmt input_stmt output_stmt assgn_stmt expr ID NUM
%type <tree_node> continue_stmt break_stmt STRING fdef fdef_block arg_list return_stmt
%type <tree_node> init_stmt alloc_stmt free_stmt NUL field field_func method_def new_stmt delete_stmt
%type <tree_node> brkp_stmt ID_extends_ID

%token 	DECLARE INT STR ENDDECL COMMA SQ_LBRAC SQ_RBRAC CL_LBRAC CL_RBRAC MOD MAIN
%token 	STRING ID  NUM  ASSIGN  PLUS MINUS MUL DIV GT LT EQ NEQ GEQ LEQ LBRAC RBRAC SEMIC NL
%token 	BEG END  READ WRITE WHILE DO ENDWHILE IF THEN ELSE ENDIF CONTINUE BREAK RETURN 
%token	TYPE ENDTYPE INIT ALLOC FREE DOT NUL CLASS ENDCLASS SELF NEW DELETE BRKP EXTENDS

%nonassoc GT LT EQ NEQ GEQ LEQ

%left PLUS MINUS
%left MUL DIV MOD

%%


program :	type_def_block class_def_block gl_declarations fdef_block mainblock
       			{
				class_func_code_gen($2);	
				func_code_gen($4);
				return 0;
			}
	|	type_def_block class_def_block gl_declarations mainblock 
			{
				class_func_code_gen($2);
				return 0;
			}
	|	type_def_block class_def_block mainblock
			{
				class_func_code_gen($2);
				return 0;
			}
	|	class_def_block gl_declarations fdef_block mainblock
			{
				class_func_code_gen($1);
				func_code_gen($3);
				return 0;
			}
	|	class_def_block gl_declarations mainblock
			{	
				class_func_code_gen($1);
				return 0;
			}
	|	class_def_block mainblock
			{
				class_func_code_gen($1);
				return 0;
			}
	|	type_def_block gl_declarations fdef_block mainblock	
			{
				func_code_gen($3);
				return 0;
			}
	|	type_def_block gl_declarations mainblock		
			{
				return 0;
			}
	|	type_def_block mainblock
			{
				return 0;
			}
	|	gl_declarations fdef_block mainblock
			{
				func_code_gen($2);
				return 0;
			}
	|	gl_declarations mainblock
			{	
				return 0;
			}

	|	mainblock
			{
				return 0;
			}
	;

type_def_block
	:	TYPE type_def_list ENDTYPE	
			{
				type_head=$2;	
	
				printf("\n");
                                print_type_table(type_head);
			}
	;

type_def_list
	:	type_def_list type_def		
			{
				struct type_table* temp=$1;
				while(temp->next!=NULL)
					temp=temp->next;
				temp->next=$2;
					
				$$=$1;
				type_head=$$;
			}
	|	type_def
			{
				$$=$1;
				type_head=$$;
			}
	;

type_def
	:	ID CL_LBRAC field_decl_list CL_RBRAC 	
			{			
				$$=create_t_entry_node($1->varname,field_index,69+(rand_no++));  

				set_field_type(type_head,$3);
				set_field_type($$,$3);	
				$$->f_list=$3;	

				field_index=0;
				
				f_list_head=NULL;
			}
	;

field_decl_list
	:	field_decl_list field_decl		
			{	
				struct field_list* temp=$1;
				while(temp->next!=NULL)
					temp=temp->next;
				temp->next=$2;
				
				$$=$1;
				f_list_head=$$;
			}			
	|	field_decl
			{	
				$$=$1;
				f_list_head=$$;			
			}
	;

field_decl
	:	field_type ID SEMIC			
			{
				if(field_index>8)
				{
					printf("MAX FIELD ENTRIES : 8\n");
					exit(0);
				}
				else
					$$=create_field_entry($2->varname,field_index++,$1);	
			}
	;

field_type
	:	INT					
			{$$="inttype";}
	|	STR 
			{$$="strtype";}
	|	ID
			{$$=$1->varname;} 
	;	

class_def_block                 
        :       CLASS class_def_list ENDCLASS
                        {
                                class_head=$2;
				$$=class_head;	

    				printf("\n------------------\n");
             			print_class_list(class_head);
				printf("------------------\n");
                        }
        ;

class_def_list
        :       class_def_list class_def
                        {
                                struct class* temp=$1;
                                while(temp->next!=NULL)
                                        temp=temp->next;
                                temp->next=$2;

                                $$=$1;
                                class_head=$$;
                        }
        |       class_def
                        {
                                $$=$1;
                                class_head=$$;
                        }
        ;

class_def
        :       ID CL_LBRAC gl_declarations method_def CL_RBRAC
                        {
				if(field_index>8)
				{
					printf("MAX FIELD ENTRIES : 8\n");
					exit(0);
				}

				set_class_name($4,$1->varname);		

				$$=create_c_node($1->varname,field_index,420+(rand_no++));   
                                $$->decl_list=$3;	
				$$->func_list=$4;				
				
				field_index=0;
                        
				cst_head=NULL;					
				line_var=NULL;
				decl_flag=1;
                        }
        |       ID CL_LBRAC gl_declarations CL_RBRAC
                        {
				if(field_index>8)
				{
					printf("MAX FIELD ENTRIES : 8\n");
					exit(0);
				}

				$$=create_c_node($1->varname,field_index,420+(rand_no++));	
                                $$->decl_list=$3;

				field_index=0;
    
				cst_head=NULL;					
				line_var=NULL;
				decl_flag=1;	
                        }
	|	ID_extends_ID CL_LBRAC gl_declarations method_def CL_RBRAC
			{
				if(field_index>8)
				{
					printf("MAX FIELD ENTRIES : 8\n");
					exit(0);
				}

				set_class_name($4,$1->varname);
				
				$$=create_c_node($1->varname,extend_size+field_index,420+(rand_no++));					
				$$->decl_list=$3;

				if(extend_func_list!=NULL)
				{
					$$->func_list=create_t_node(-1,"-",-1,"+C",connect,current_block,$4,extend_func_list);
					fix_func_list($$->func_list);	
					extend_func_list=NULL;
				}
				else
					$$->func_list=$4;
			
				field_index=0;
				extend_size=0;
				
				cst_head=NULL;
				line_var=NULL;
				decl_flag=1;
			}
	|	ID_extends_ID CL_LBRAC gl_declarations CL_RBRAC
			{
				if(field_index>8)
				{
					printf("MAX FIELD ENTRIES : 8\n");
					exit(0);
				}
				
				$$=create_c_node($1->varname,extend_size+field_index,420+(rand_no++));						
				$$->decl_list=$3;

				if(extend_func_list!=NULL)
				{
					$$->func_list=extend_func_list;
					fix_func_list($$->func_list);
					extend_func_list=NULL;
				}
			
				field_index=0;
				extend_size=0;
			
				cst_head=NULL;
				line_var=NULL;
				decl_flag=1;
			}
        ;

ID_extends_ID
	:	ID EXTENDS ID 
			{
				extend_head=get_class_decl_list(class_head,$3->varname);
				extend_size=get_class_field_size(class_head,$3->varname);
				extend_func_list=copy_t_node(get_class_func_list(class_head,$3->varname));	
				update_func_list(extend_func_list,$1->varname,$3->varname);
				extend_flag=1;

				$$=$1;
			}
	;

method_def
        :       method_def fdef
                        {
				$$=create_t_node(-1,"-",-1,"+C",connect,current_block,$1,$2);
                        }
        |       fdef
                        {$$=$1;}
        ;


gl_declarations
        :       DECLARE gl_decllist ENDDECL 
                        {
				if(class_flag==0)				
                                {
					gv_pointer++;			
					struct symbol* temp=$2;		
					while(temp->next!=NULL)		
						temp=temp->next;				
					temp->next=create_s_node("self",420,9,gv_pointer,NULL,0);
					gv_pointer+=8;

					gst_head=$2;
				
					printf("\n\n|-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-|\n");	
                                	print_table($2);
					printf("|-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-|\n");
		
					current_block=saved_block_no;		
				}
				if(class_flag==1)				
				{
					if(extend_head!=NULL)
					{
						if(extend_size+field_index>8)
						{
							printf("MAX FIELD ENTRIES : 8\n");
							exit(0);
						}
		
						struct symbol* temp_1=change_f_label(extend_head);
						struct symbol* temp_2=temp_1;
						while(temp_2->next!=NULL)
							temp_2=temp_2->next;
						temp_2->next=copy_extend_head($2,field_index);

						fix_decl_list(temp_1);

						cst_head=temp_1;
						$$=temp_1;
						
						extend_head=NULL;
					}
					else
					{
						cst_head=$2;
						$$=$2;
					}
					
					printf("\n\n|-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-|\n");
                        		print_table($$);
                          		printf("|-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-|\n");

                              		current_block++;
					
				}				
                        }
        |       DECLARE ENDDECL 
                        {
				if(class_flag==0)				
                                {
					gst_head=NULL;
			
					current_block=saved_block_no;		
				}
				if(class_flag==0)				
				{
					cst_head=NULL;				
					$$=NULL;
					current_block++;
				}
                        }
        ;

gl_decllist
        :       gl_decllist gl_decl
                        {
				if(class_flag==0)				
                                {
					struct symbol* temp=$1;
                                	while(temp->next!=NULL)
                                        	temp=temp->next;
                                	temp->next=$2;
                                	$$=$1;
                                	gst_head=$$;
					line_var=NULL;
				}
				if(class_flag==1)				
				{
					struct symbol* temp=$1;
					while(temp->next!=NULL)
						temp=temp->next;
					temp->next=$2;
					$$=$1;
					cst_head=$$;				
					line_var=NULL;
				}
                        }
        |       gl_decl
                        {
                                if(class_flag==0)				
				{
					$$=$1;
                                	gst_head=$$;
					line_var=NULL;
				}
				if(class_flag==1)				
				{
					$$=$1;
					cst_head=$$;				
					line_var=NULL;
				}
                        }
        ;

gl_decl
        :       gl_type gl_varlist SEMIC
                        {
                                set_type($2,$1);

				if($1>420)		
				{
					set_size_to($2,9);
					gv_pointer+=8;
				}

                                $$=$2;
                        }
        ;

gl_type
        :       INT
                        {$$=inttype;}
        |       STR     
                        {$$=strtype;}
	|	ID
			{	
				int type=find_type_type(type_head,$1->varname);
				if(type==-1)
					type=find_class_type(class_head,$1->varname);
				if(type==-1)
				{
					printf("NO TYPE/CLASS DEF FOUND\n");
					exit(0);
				}
				else 
					$$=type;				
			}
        ;

gl_varlist
        :       gl_varlist COMMA ID
                        {
				if(class_flag==0)				
                                {
					gv_pointer++;
                                	struct symbol* temp=$1;
                                	while(temp->next!=NULL)
                                        	temp=temp->next;
                               		temp->next=create_s_node($3->varname,-2,1,gv_pointer,NULL,0);
                                
					$$=$1;
                                	line_var=$$;
				}
				if(class_flag==1)				
				{
					struct symbol* temp=$1;
					while(temp->next!=NULL)
						temp=temp->next;		
					temp->next=create_s_node($3->varname,-2,1,field_index++,NULL,0);
					$$=$1;
					line_var=$$;
				}
                        }
        |       ID
                        {
				if(class_flag==0)				
                                {
					gv_pointer++;
                                	$$=create_s_node($1->varname,-2,1,gv_pointer,NULL,0);
                                	line_var=$$;
				}
				if(class_flag==1)				
				{
					$$=create_s_node($1->varname,-2,1,field_index++,NULL,0);
					line_var=$$;
				}
  		      	}

        |       gl_varlist COMMA ID SQ_LBRAC NUM SQ_RBRAC
                        {
				if(class_flag==0)				
                                {
					int size=$5->val;
                                	int start_addrs=gv_pointer+1;
                                	int j=$5->val;

                                	struct symbol* temp=$1;
                                	while(temp->next!=NULL)
                                        	temp=temp->next;
                                	temp->next=create_s_node($3->varname,-2,size,start_addrs,NULL,j);

                                	gv_pointer+=size;
				
					$$=$1;
                                	line_var=$$;
				}
				if(class_flag==1)				
				{
					printf("ARRAY FIELD IN CLASS NOT ALLOWED\n");
					exit(0);
				}
                        }

        |       ID SQ_LBRAC NUM SQ_RBRAC
                        {
				if(class_flag==0)				
                                {
					int size=$3->val;
                                	int start_addrs=gv_pointer+1;
                                	int j=$3->val;
                                	$$=create_s_node($1->varname,-2,size,start_addrs,NULL,j);

                                	gv_pointer+=size;
				
                                	line_var=$$;
				}
				if(class_flag==1)				
				{
					printf("ARRAY FIELD IN CLASS NOT ALLOWED\n");
					exit(0);
				}
                        }

	|	gl_varlist COMMA ID LBRAC param_list RBRAC
			{
				if(class_flag==0)				
				{
					struct symbol* temp=$1;
                                	while(temp->next!=NULL)
                                        	temp=temp->next;

					temp->next=create_s_node($3->varname,-2,0,-1,$5,0);	
					temp->next->f_label=getlabel();
			
                                	arg_pointer=0;

					$$=$1;
                                	line_var=$$;
					param_head=NULL;
				}
				if(class_flag==1)				
				{				
					struct symbol* temp=$1;
					while(temp->next!=NULL)
						temp=temp->next;
		
					temp->next=create_s_node($3->varname,-2,0,-1,$5,0);	
					temp->next->f_label=getlabel();

					arg_pointer=0;

					$$=$1;
					line_var=$$;
					param_head=NULL;
				}
			
			}
	|	ID LBRAC param_list RBRAC
			{
				if(class_flag==0)				
				{
					$$=create_s_node($1->varname,-2,0,-1,$3,0);	
					$$->f_label=getlabel();

					arg_pointer=0;

                                	line_var=$$;
					param_head=NULL;
				}
				if(class_flag==1)				
				{
					$$=create_s_node($1->varname,-2,0,-1,$3,0);
					$$->f_label=getlabel();
				
					arg_pointer=0;
				
					line_var=$$;
					param_head=NULL;
				}
                        }
        ;

fdef_block
	:	fdef_block fdef
			{
				$$=create_t_node(-1,"-",-1,"+C",connect,current_block,$1,$2);
			}
	|	fdef
			{$$=$1;}
	;

fdef	
	:	gl_type ID LBRAC param_list RBRAC CL_LBRAC l_declarations BEG slist END CL_RBRAC
			{
				if(find_type(cst_head,$2->varname)!=$1)		
				{
					if(find_type(gst_head,$2->varname)!=$1)		
					{
						printf("FUNCTION DECLARATION NOT FOUND\n");
						exit(0);
					}
				}
				if(check_arg_list(find_func_arg_list(cst_head),$4)==0)
				{
					if(check_arg_list(find_func_arg_list(gst_head),$4)==0)
                        		{
						printf("PARAM_DECL INCORRECT\n");
                                      		exit(0);
					}
                              	}

				printf("\n---------------------------------\n");
				print_tree($9);	
				printf("\n---------------------------------");

				if(class_flag==1)		
					$$=create_t_node(-1,"-CHANGE-",-1,$2->varname,function,current_block,$9,NULL);
				if(class_flag==0)		
					$$=create_t_node(-1,"-",-1,$2->varname,function,current_block,$9,NULL);
					
				$$->l_var_list=$7;

				current_block++;
				line_head=NULL;
				line_var=NULL;			
				param_head=NULL;			
			} 
	|	gl_type ID LBRAC param_list RBRAC CL_LBRAC BEG slist END CL_RBRAC
			{
				if(find_type(cst_head,$2->varname)!=$1)		
                               	{
					if(find_type(gst_head,$2->varname)!=$1)		
					{
                                        	printf("FUNCTION DECLARATION NOT FOUND\n");
                                        	exit(0);
					}
                                }
				if(check_arg_list(find_func_arg_list(cst_head),$4)==0)
				{
					if(check_arg_list(find_func_arg_list(gst_head),$4)==0)
					{
                                        	printf("PARAM_DECL INCORRECT\n");
                                        	exit(0);
					}
                                }
                              
                        	printf("\n---------------------------------\n");
                        	print_tree($8);
                         	printf("\n---------------------------------");
			
				if(class_flag==1)		
					$$=create_t_node(-1,"-CHANGE-",-1,$2->varname,function,current_block,$8,NULL);
				if(class_flag==0)		
					$$=create_t_node(-1,"-",-1,$2->varname,function,current_block,$8,NULL);

                            	current_block++;
                           	line_head=NULL;
				line_var=NULL;       
				param_head=NULL;					 
                        }
	;


param_list
	:	param_list COMMA param
			{
				struct param_struct* temp=$1;
				while(temp->next!=NULL)
                                        temp=temp->next;
				temp->next=$3;
				
				$$=$1;
				param_head=$$;
			}
	|	param
			{$$=$1;}
	;

param
	:	gl_type	ID
			{
				arg_pointer--;
				$$=create_param_node($2->varname,arg_pointer,$1);
				param_head=$$;
			}
	|		
			{
				$$=NULL;
			}
	;


mainblock 
	:	INT MAIN LBRAC RBRAC CL_LBRAC l_declarations BEG slist END CL_RBRAC
			{
				printf("\n---------------------------------\n");
                                print_tree($8);
				printf("\n---------------------------------\n");

				main_code_gen($8,gv_pointer);
		
				current_block++;
	
				line_head=NULL;
				line_var=NULL;

                        }
	|	INT MAIN LBRAC RBRAC CL_LBRAC BEG slist END CL_RBRAC
                        {
                                printf("\n---------------------------------\n");
                                print_tree($7);
                                printf("\n---------------------------------\n");

                                main_code_gen($7,gv_pointer);
			
				current_block++;
				
				line_head=NULL;
				line_var=NULL;

                        }
	|	INT MAIN LBRAC RBRAC CL_LBRAC l_declarations BEG END CL_RBRAC
			{
				current_block++;
				line_head=NULL;
				line_var=NULL;
			}
	|	INT MAIN LBRAC RBRAC CL_LBRAC BEG END CL_RBRAC
			{
				current_block++;
				line_head=NULL;
				line_var=NULL;
			}
	;

l_declarations
	:	DECLARE l_decllist ENDDECL 
			{
                                list[current_block].lst_head=$2;
				lv_pointer=0;				

                                printf("\n\n|-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-|\n");
                                print_table($2);
				printf("|-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-|\n");

				$$=$2;
		        }
	|	DECLARE ENDDECL 
			{
                                list[current_block].lst_head=NULL;
				lv_pointer=0;
				
				$$=NULL;
                        }
	;

l_decllist
	:	l_decllist l_decl
			{
                                struct symbol* temp=$1;
                                while(temp->next!=NULL)
                                        temp=temp->next;
                                temp->next=$2;
                                $$=$1;
                                line_head=$$;
                        }
	|	l_decl
			{
                                $$=$1;
                                line_head=$$;

                        }
	;

l_decl
	:	l_type l_varlist SEMIC
			{
                                set_type($2,$1);
				
				if($1>420)			
				{
					set_size_to($2,9);
					if(main_flag==1)
						gv_pointer+=8;
					else
						lv_pointer+=8;
				}
	
				$$=$2;
                        }
	;

l_type 
	:	INT
			{$$=inttype;}
	|	STR
			{$$=strtype;}
	|       ID
                        {
				int type=find_type_type(type_head,$1->varname);
				if(type==-1)
				{
					printf("TYPE/CLASS DEF NOT FOUND\n");
					exit(0);
				}
				else
					$$=type;
			}
	;		

l_varlist
	:	l_varlist COMMA ID
			{
				if(main_flag==1)
                                {
					gv_pointer++;
                                	struct symbol* temp=$1;
                                	while(temp->next!=NULL)
                                        	temp=temp->next;
                                	temp->next=create_s_node($3->varname,-2,1,gv_pointer,NULL,0);
                                }
				else 
				{	
					lv_pointer++;
                                        struct symbol* temp=$1;
                                        while(temp->next!=NULL)
                                                temp=temp->next;
                                        temp->next=create_s_node($3->varname,-2,1,lv_pointer,NULL,0);
                                }
				$$=$1;
                                line_var=$$;
                        }
	|	ID
			{
				if(main_flag==1)
                                {
					gv_pointer++;
                                	$$=create_s_node($1->varname,-2,1,gv_pointer,NULL,0);
                                }
				else 
				{
					lv_pointer++;
                                        $$=create_s_node($1->varname,-2,1,lv_pointer,NULL,0);
				}
				line_var=$$;
                      	}
	;

slist
	:	slist stmt
			{	
				$$=create_t_node(-1,"-",-1,"+C",connect,current_block,$1,$2);
			}
	|	stmt
			{$$=$1;}
	;

stmt
	:	input_stmt
			{$$=$1;}
	|	output_stmt
			{$$=$1;}
	|	assgn_stmt
			{$$=$1;}
	|       if_stmt
                        {$$=$1;}
        |       while_stmt
                        {$$=$1;}
	|	continue_stmt
			{$$=$1;}
	|	break_stmt
			{$$=$1;}
	|	return_stmt
			{$$=$1;}
	|	init_stmt
			{$$=$1;}
	|	alloc_stmt
			{$$=$1;}
	|	free_stmt
			{$$=$1;}
	|	new_stmt
			{$$=$1;}				
	|	delete_stmt
			{$$=$1;}				
	|	brkp_stmt
			{$$=$1;}				
	;


brkp_stmt
	:	BRKP SEMIC
			{
				$$=create_t_node(-1,"-",-1,"+BRKP",brk_point,current_block,NULL,NULL);
			}

new_stmt
	:	ID ASSIGN NEW LBRAC ID RBRAC SEMIC 
			{
				
				int type=find_class_type(class_head,$5->varname);
				if($1->type!=type)
				{
					if($1->type<=420 || type<=420)
					{
						printf("TYPE MISMATCH\n");
						exit(0);
					}
					else
						$1->type=type;
				}					

				struct t_node* t1=create_t_node(-1,"-",-1,"+ALLOC",heap_alloc_stmt,current_block,$1,NULL);
				struct t_node* t2=create_t_node(-1,"-",-1,"+VRTBL",vr_tbl_alloc,current_block,$1,$5);

				$$=create_t_node(-1,"-",-1,"+C",connect,current_block,t1,t2);
			}	
	|	field ASSIGN NEW LBRAC ID RBRAC SEMIC 
			{
				int type=find_class_type(class_head,$5->varname);
				if($1->type!=type)
				{
					if($1->type<=420 || type<=420)
					{
						printf("TYPE MISMATCH\n");
						exit(0);
					}
					else
						$1->type=type;
				}
				
				struct t_node* t1=create_t_node(-1,"-",-1,"+ALLOC",heap_alloc_stmt,current_block,$1,NULL);
				struct t_node* t2=create_t_node(-1,"-",-1,"+VRTBL",vr_tbl_alloc,current_block,$1,$5);
				$$=create_t_node(-1,"-",-1,"+C",connect,current_block,t1,t2);
			}
	;

delete_stmt
	:	DELETE LBRAC field RBRAC SEMIC 
			{
				if($3->type<=420)
				{
					printf("NOT USER DEF CLASS\n");
					exit(0);
				}
				else
					$$=create_t_node(-1,"-",-1,"+FREE",heap_free_stmt,current_block,$3,NULL);
			}
	;

continue_stmt
	:	CONTINUE SEMIC
			{$$=create_t_node(-1,"-",-1,"+CONT",cont_stmt,current_block,NULL,NULL);}
	;


break_stmt
	:	BREAK SEMIC 
			{$$=create_t_node(-1,"-",-1,"+BRK",brk_stmt,current_block,NULL,NULL);}
	;				 

return_stmt
	:	RETURN expr SEMIC
			{
				if(main_flag==0)
					$$=create_t_node(-1,"-",-1,"+RET",ret_stmt,current_block,$2,NULL);
				else
					$$=NULL;
			}
	|	RETURN SEMIC
			{
				if(main_flag==0)
					$$=create_t_node(-1,"-",-1,"+RET",ret_stmt,current_block,NULL,NULL);
				else 
					$$=NULL;
			}
	;


init_stmt
	:	ID ASSIGN INIT LBRAC RBRAC SEMIC
			{
				if($1->type != inttype)
				{
					printf("TYPE MISMATCH\n");
					exit(0);
				}
				else
					$$=create_t_node(-1,"-",-1,"+INIT",heap_init_stmt,current_block,$1,NULL);
			}
	;




alloc_stmt
	:	ID ASSIGN ALLOC LBRAC RBRAC SEMIC 
			{
				if($1->type<=69 || $1->type>=420)	
				{
					printf("TYPE MISMATCH\n");
					exit(0);
				}
				else
					$$=create_t_node(-1,"-",-1,"+ALLOC",heap_alloc_stmt,current_block,$1,NULL);	
			}
	;

free_stmt
	:	FREE LBRAC ID RBRAC SEMIC
			{
				if($3->type<=69 || $3->type>=420)
                                {
                                        printf("NOT USER DEFINED TYPE\n");
                                        exit(0);
                                }
                                else
					$$=create_t_node(-1,"-",-1,"+FREE",heap_free_stmt,current_block,$3,NULL);
			}
	;


if_stmt
	:	IF LBRAC expr RBRAC THEN slist ELSE slist ENDIF SEMIC 
			{ 
				if($3->type != boolean)
				{
					printf("TYPE MISMATCH\n");
					exit(0);
				}
				else
				{
					struct t_node* temp;
					temp=create_t_node(-1,"-",-1,"+EL",else_part,current_block,$6,$8);
					$$=create_t_node(-1,"-",-1,"+IF",if_part,current_block,$3,temp);
				}
			}
	|	IF LBRAC expr RBRAC THEN slist ENDIF SEMIC
			{
				if($3->type != boolean)
                                {
                                        printf("TYPE MISMATCH\n");
                                        exit(0);
                                }
                                else
				{
					struct t_node* temp;
					temp=create_t_node(-1,"-",-1,"+EL",else_part,current_block,$6,NULL);
					$$=create_t_node(-1,"-",-1,"+IF",if_part,current_block,$3,temp);
				}
			}
	;

while_stmt
	:	WHILE LBRAC expr RBRAC DO slist ENDWHILE SEMIC 
			{
				if($3->type != boolean)
                                {
                                        printf("TYPE MISMATCH\n");
                                        exit(0);
                                }
                                else
					$$=create_t_node(-1,"-",-1,"+WHILE",while_do,current_block,$3,$6);
			}
	;

input_stmt
	:	READ LBRAC ID RBRAC SEMIC 
			{$$=create_t_node(-1,"-",-1,"+R",read,current_block,$3,NULL);}
	|	READ LBRAC ID SQ_LBRAC expr SQ_RBRAC RBRAC SEMIC
			{
				if($5->type != inttype)
				{
					printf("TYPE MISMATCH\n");
					exit(0);
				}
				else if(find_array_size(gst_head,$3->varname)==0)
                                {
                                        printf("ARRAY DECLARATION NOT FOUND\n");
                                        exit(0);
                                }
				else
				{
					$3->node_type=leaf_arr;
                                	$3->right=$5;
				
					$$=create_t_node(-1,"-",-1,"+R",read,current_block,$3,NULL);
				}
			}
	|	READ LBRAC field RBRAC SEMIC 			
			{$$=create_t_node(-1,"-",-1,"+R",read,current_block,$3,NULL);}
	;

output_stmt
	:	WRITE LBRAC expr RBRAC SEMIC 
			{$$=create_t_node(-1,"-",-1,"+W",write,current_block,$3,NULL);}
	;

assgn_stmt
	:	ID ASSIGN expr SEMIC 
			{
				if(($1->type==inttype) && ($3->type==inttype))
				{
					$$=create_t_node(-1,"-",inttype,"+A",assgn,current_block,$1,$3); 
				}
				else if(($1->type==strtype) && ($3->type==strtype))
				{
                                        $$=create_t_node(-1,"-",strtype,"+A",assgn,current_block,$1,$3);
                                }
				else if($1->type==$3->type)	
				{
					$$=create_t_node(-1,"-",$1->type,"+A",assgn,current_block,$1,$3);
				}
				else if(($1->type>69)&&($1->type<420)&&($3->type==420))	
				{
					$$=create_t_node(-1,"-",$1->type,"+A",assgn,current_block,$1,$3);
				}
				else if(($1->type>420) && ($3->type>420))
				{
					$$=create_t_node(-1,"-",$1->type,"+A",assgn,current_block,$1,$3);
				}
				else 
				{
					printf("TYPE MISMATCH\n");
					exit(0);
				}
			}

	|	ID SQ_LBRAC expr SQ_RBRAC ASSIGN expr SEMIC
			{
				if($3->type!=inttype)
				{
					printf("TYPE MISMATCH\n");
					exit(0);
				}
				else if(find_array_size(gst_head,$1->varname)==0)
                                {
                                        printf("ARRAY DECLARATION NOT FOUND\n");
                                        exit(0);
                                }
				else
					if(($1->type==inttype) && ($6->type==inttype))
                                	{
						$1->node_type=leaf_arr;
                                		$1->right=$3;
					
						$$=create_t_node(-1,"-",inttype,"+A",assgn,current_block,$1,$6);
					}
					else if(($1->type==strtype) && ($6->type==strtype))
                                	{
						$1->node_type=leaf_arr;
                                        	$1->right=$3;

                                        	$$=create_t_node(-1,"-",strtype,"+A",assgn,current_block,$1,$6);
                                	}
					else
                                	{
                                        	printf("TYPE MISMATCH\n");
                                        	exit(0);
                                	}
                     	}
	|	field ASSIGN expr SEMIC			
			{
				if(($1->type==inttype) && ($3->type==inttype))
                                {
                                        $$=create_t_node(-1,"-",inttype,"+A",assgn,current_block,$1,$3);
                                }
                                else if(($1->type==strtype) && ($3->type==strtype))
                                {
                                        $$=create_t_node(-1,"-",strtype,"+A",assgn,current_block,$1,$3);
                                }
				else if($1->type==$3->type)
                                {
                                        $$=create_t_node(-1,"-",$1->type,"+A",assgn,current_block,$1,$3);
                                }
				else if(($1->type>69)&&($1->type<420)&&($3->type==420))		
                                {
                                        $$=create_t_node(-1,"-",$1->type,"+A",assgn,current_block,$1,$3);
                                }
                                else
                                {
                                        printf("TYPE MISMATCH\n");
                                        exit(0);
                                }
			}
	;

expr
	:	expr PLUS expr
			{
				if(($1->type!=inttype) || ($3->type!=inttype))
				{
					printf("TYPE MISMATCH\n");		
					exit(0);
				}
				else
					$$=create_t_node(-1,"-",inttype,"+OP",plus,current_block,$1,$3);
			}
	|	expr MINUS expr
			{
                                if(($1->type!=inttype) || ($3->type!=inttype))
                                {
                                        printf("TYPE MISMATCH\n");
                                        exit(0);
                                }
                                else
                                        $$=create_t_node(-1,"-",inttype,"+OP",sub,current_block,$1,$3);
			}
	|	expr MUL expr 
			{
                                if(($1->type!=inttype) || ($3->type!=inttype))
                                {
                                        printf("--TYPE MISMATCH\n");
                                        exit(0);
                                }
                                else
                                       	$$=create_t_node(-1,"-",inttype,"+OP",mul,current_block,$1,$3);
			}
	|	expr DIV expr
			{
                                if(($1->type!=inttype) || ($3->type!=inttype))
                                {
                                        printf("TYPE MISMATCH\n");
                                        exit(0);
                                }
                                else
                                        $$=create_t_node(-1,"-",inttype,"+OP",div,current_block,$1,$3);
			}
	
	|       expr MOD expr
                        {
                                if(($1->type!=inttype) || ($3->type!=inttype))
                                {
                                        printf("TYPE MISMATCH\n");
                                        exit(0);
                                }
                                else
                                        $$=create_t_node(-1,"-",inttype,"+OP",mod,current_block,$1,$3);
                        }

	|	expr GT expr
			{
				if(($1->type!=inttype) || ($3->type!=inttype))
                                {
                                        printf("TYPE MISMATCH\n");
                                        exit(0);
                                }
                                else
                                        $$=create_t_node(-1,"-",boolean,"+BOP",greater_than,current_block,$1,$3);
			}	

	|	expr LT expr
			{
				if(($1->type!=inttype) || ($3->type!=inttype))
                                {
                                        printf("TYPE MISMATCH\n");
                                        exit(0);
                                }
                                else
                                        $$=create_t_node(-1,"-",boolean,"+BOP",less_than,current_block,$1,$3);
                        }       
	
	|	expr NEQ expr
			{

				if(($1->type==inttype) && ($3->type==inttype))
                                {
                                        $$=create_t_node(-1,"-",boolean,"+BOP",not_equal,current_block,$1,$3);
                                }
                                else if(($1->type==strtype) && ($3->type==strtype))
                                {
                                        $$=create_t_node(-1,"-",boolean,"+BOP",not_equal,current_block,$1,$3);
                                }
				else if(($1->type==$3->type) || (($1->type>69)&&($1->type<420)&&($3->type==420))) 
                                {
					$$=create_t_node(-1,"-",boolean,"+BOP",not_equal,current_block,$1,$3);
                                }
                                else
                                {
                                        printf("TYPE MISMATCH\n");
                                        exit(0);
                                }

                        }   
	
	|	expr EQ expr
			{
				
				if(($1->type==inttype) && ($3->type==inttype))
                                {
                                        $$=create_t_node(-1,"-",boolean,"+BOP",equal,current_block,$1,$3);
                                }
                                else if(($1->type==strtype) && ($3->type==strtype))
                                {
                                        $$=create_t_node(-1,"-",boolean,"+BOP",equal,current_block,$1,$3);
                                }
				else if(($1->type==$3->type) || (($1->type>69)&&($1->type<420)&&($3->type==420))) 
				{
					$$=create_t_node(-1,"-",boolean,"+BOP",equal,current_block,$1,$3);
				}
                                else
                                {
                                        printf("TYPE MISMATCH\n");
                                        exit(0);
                                }

                        }         
	
	|	expr GEQ expr
			{
                                if(($1->type!=inttype) || ($3->type!=inttype))
                                {
                                        printf("TYPE MISMATCH\n");
                                        exit(0);
                                }
                                else
                                        $$=create_t_node(-1,"-",boolean,"+BOP",greater_equal,current_block,$1,$3);
                        }      
	
	|	expr LEQ expr 
			{
                                if(($1->type!=inttype) || ($3->type!=inttype))
                                {
                                        printf("TYPE MISMATCH\n");
                                        exit(0);
                                }
                                else
                                        $$=create_t_node(-1,"-",boolean,"+BOP",less_equal,current_block,$1,$3);
                        }      
				
	|	LBRAC expr RBRAC
			{$$=$2;}
	|	NUM
			{$$=$1;}
	|	NUL 		
			{$$=$1;}
	|	field		
			{$$=$1;}
	|	field_func
			{$$=$1;}				
	|	ID SQ_LBRAC expr SQ_RBRAC
			{
				if($3->type!=inttype)
				{
					printf("TYPE MISMATCH\n");
					exit(0);
				}
				else if(find_array_size(gst_head,$1->varname)==0)
				{
					printf("ARRAY DECLARATION NOT FOUND\n");
					exit(0);
				}
				else					
				{	
					$1->node_type=leaf_arr;
					$1->right=$3;
				
					$$=$1;
				}
			}
	
	|	ID LBRAC arg_list RBRAC		
			{
				int type=find_type(gst_head,$1->varname);	
                                $$=create_t_node(-1,"-",type,"+FOP",func_call,current_block,$1,$3);
			}
	|	ID LBRAC RBRAC
			{
				int type=find_type(gst_head,$1->varname);
				$$=create_t_node(-1,"-",type,"+FOP",func_call,current_block,$1,NULL);
			}
	|	ID
			{$$=$1;}
	|	STRING
			{$$=$1;}
	;

arg_list
	:	arg_list COMMA expr
			{
				if($3->type<0)
                                {
                                        printf("ARGUMENTS TYPE ERROR\n");
                                        exit(0);
                                }
				else
				{
					$$=create_t_node(-1,"-",-1,"+C",connect,current_block,$1,$3);
				}			
			}
	|	expr
			{
				if($1->type<0)
				{
					printf("ARGUMENTS TYPE ERROR\n");
					exit(0);
				}
				else
					$$=$1;
			}	
	;

field	:	field DOT ID 				
			{
				$1->type=$3->type;
				struct t_node* temp=$1;
				while(temp->left!=NULL)
					temp=temp->left;
				temp->left=$3;			
			}
	|	ID DOT ID	
			{
				if(check_type_type(type_head,$1->type)>69)	
					$$=create_t_node(-1,"-",$3->type,$1->varname,leaf_tf,current_block,$3,NULL);
				if(check_class_type(class_head,$1->type)>420)		
					$$=create_t_node(-1,"-",$3->type,$1->varname,leaf_cf,current_block,$3,NULL); 	
			}
	|	SELF DOT ID
			{
				$$=create_t_node(-1,"-",$3->type,"self",leaf_cf,current_block,$3,NULL);
			}
	;

field_func
	:	field DOT ID LBRAC arg_list RBRAC
			{
					if($1->node_type==leaf_cf)		
					{
						printf("NOT ALLOWED\n");
						exit(0);
					}
					$1->type=$3->type;
					$1->node_type=cf_func_call;
					struct t_node* temp=$1;
					while(temp->left!=NULL)
						temp=temp->left;
					temp->left=$3;				
					temp->right=$5;
				
					$$=$1;
			}
	|	ID DOT ID LBRAC arg_list RBRAC 
			{
				if(main_flag==1 && extend_flag==1)
					$$=create_t_node(-1,"-",$3->type,$1->varname,class_func_call,current_block,$3,$5);
				else
					$$=create_t_node(-1,"-",$3->type,$1->varname,cf_func_call,current_block,$3,$5);
			}
	|	ID DOT ID LBRAC RBRAC 
			{
				if(main_flag==1 && extend_flag==1)
					$$=create_t_node(-1,"-",$3->type,$1->varname,class_func_call,current_block,$3,NULL);
				else
					$$=create_t_node(-1,"-",$3->type,$1->varname,cf_func_call,current_block,$3,NULL);
			}
	|	SELF DOT ID LBRAC arg_list RBRAC 
			{
                        	$$=create_t_node(-1,"-",$3->type,"self",cf_func_call,current_block,$3,$5);		
			}
	|	SELF DOT ID LBRAC RBRAC
			{
				$$=create_t_node(-1,"-",$3->type,"self",cf_func_call,current_block,$3,NULL);
			}
	;
	

%%

int yyerror(char *msg)
{
	printf("Error:%s\n",msg);
	exit(0);
}

int main(int argc,char *argv[])
{	
	FILE *fp=fopen(argv[1],"r");
	yyin=fp;
	target_file=fopen("test.o","w");
	
	for(int i=0;i<100;i++)
		list[i].lst_head=NULL;
	
	yyparse();
	return 0;
}
