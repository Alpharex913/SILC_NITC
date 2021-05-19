%{
	#include <stdio.h>
	#include <stdlib.h>
	
	#include "y.tab.h"
	
	#define inttype 0
	#define boolean 1
	#define strtype 2
	#define leaf    3
	
	extern struct t_node* create_t_node(int,char*,int,char*,int,int,struct t_node*,struct t_node*);
	extern int find_class_type(struct class* head,char* name);		
	extern int find_tf_type(struct type_table* head,char* name);		
	extern int find_cf_type(struct class* head,char* name);				
	extern int find_field_type(struct field_list* head,char* name);
	extern int find_type_type(struct type_table* head,char* name);
	extern int find_type(struct symbol* head,char* var);
	extern int find_arg_type(struct symbol* head,char* var);
	extern int find_param_type(struct param_struct* head,char* var);
	extern struct symbol* cst_head;						
	extern struct symbol* gst_head;
	extern struct symbol* line_head;
	extern struct symbol* line_var;	
	extern struct param_struct* param_head;
	extern struct type_table* type_head;
	extern struct field_list* f_list_head;
	extern struct class* class_head;					
	extern void set_f_flag(struct symbol* head,int flag);	

	extern int current_block;
	extern int main_flag;	
	extern int class_flag;							
	extern int saved_block_no;				
	
	int decl_flag=1;
	int end_flag=0;
	int code_flag=0;
	int brac_flag=0;
	int type_flag=0;
	int cl_brac_flag=0;
%}

%option noyywrap

%%


"main"			{
				printf("MAIN_df%d ",decl_flag);
				main_flag=1;
				set_f_flag(gst_head,0);
				return MAIN;
			}

"class"			{					
				printf("CLASS ");		
				class_flag=1;
			
				current_block=0;			

				return CLASS;
			}

"endclass"		{				
				printf("ENDCLASS ");
				class_flag=0;
		
				saved_block_no=current_block;	
				current_block=-1;		

				return ENDCLASS;		
			}

"extends"		{
				printf("EXTENDS ");
				return EXTENDS;
			}


"new"			{					
				printf("NEW ");
				return NEW;
			}

"delete"		{					
				printf("DELETE ");
				return DELETE;
			}

"self"			{					
				printf("SELF ");
				return SELF;
			}

"initialize"		{
				printf("INIT ");
				return INIT;
			}

"alloc"			{
				printf("ALLOC ");
				return ALLOC;
			}

"free"			{
				printf("FREE ");
				return FREE;
			}

"null"			{
				printf("NULL ");
				yylval.tree_node=create_t_node(-1,"-",420,"-VAR",leaf,current_block,NULL,NULL);
				return NUL;
			}

"type"			{
				printf("TYPE ");
				type_flag=1;
				return TYPE;
			}

"endtype"		{
				printf("ENDTYPE ");
				type_flag=0;
				return ENDTYPE;
			}

"decl"			{	
				printf("DECL_df%d ",decl_flag);
				decl_flag=1;
				return DECLARE;
			}

"int"			{	
				printf("INT ");
			 	return INT;
			}

"str"			{	
				printf("STR ");
				return STR;
			}

"enddecl"		{	
				printf("ENDDECL_df%d ",decl_flag);
				decl_flag=0;
				return ENDDECL;
			}

"continue"		{ 
				printf("CONTINUE ");
				return CONTINUE;
			}

"break"			{
				printf("BREAK ");
				return BREAK;
			}

"return"		{
				printf("RETURN ");
				return RETURN;
			}

"while"			{
				printf("WHILE ");
				return WHILE;
			}

"do"			{
				printf("DO ");
				return DO;
			}

"endwhile"		{
				printf("ENDWHILE ");
				return ENDWHILE;
			}

"if"			{
				printf("IF ");
				return IF;
			}

"then"			{
				printf("THEN ");
				return THEN;
			}

"else"			{	
				printf("ELSE ");
				return ELSE;
			}

"endif"			{
				printf("ENDIF ");
				return ENDIF;
			}

"begin"			{	
				printf("BEG_df%d ",decl_flag);
				code_flag=1;
				return BEG;
			}

"end"			{
				printf("END_df%d ",decl_flag);
				code_flag=0;
				end_flag=1;
				return END;
			}

"read"			{
				printf("READ ");
				return READ;
			}

"write"			{
				printf("WRITE ");
				return WRITE;
			}

"breakpoint"		{
				printf("BRKP ");
				return BRKP;
			}

\"(\\.|[^\\"])*\" 	{
				printf("STRING ");
		 		yylval.tree_node=create_t_node(-1,strdup(yytext),strtype,"-VAR",leaf,current_block,NULL,NULL);
				return STRING;
			}


[a-zA-Z_][a-zA-Z0-9_]*	{
				printf("ID_df%d ",decl_flag);
				char* var=strdup(yytext);
				if(decl_flag==1)
				{					
					int check_1;
					if(current_block==-1)
						check_1=find_type(gst_head,var);
					else
						check_1=find_type(line_head,var);	
					if(check_1==-1 && class_flag==1)		
						check_1=find_type(cst_head,var);	
					
					int check_2=find_type(line_var,var);		//checks line
					int check_3=find_param_type(param_head,var);	//checks arg
					int check_4=find_type_type(type_head,var);	//for type
					int check_5=find_field_type(f_list_head,var);	//for field
	
                                        if(((check_1==-1)&&(check_2==-1)&&(brac_flag==0)&&(type_flag==0)) || ((brac_flag==1)&&(check_3==-1)&&(type_flag==0)) || ((type_flag==1)&&(check_4==-1)&&(cl_brac_flag==0)) || ((cl_brac_flag==1)&&(type_flag==1)&&(check_5==-1))) 
                                        {
						yylval.tree_node=create_t_node(-1,"-",-1,var,-1,current_block,NULL,NULL);
                                        }
                                        else
                                        {
						printf("NAME ALREADY IN USE\n");
                                                exit(0);
					}
				}
				if(decl_flag==0)
				{					
					int type=find_arg_type(gst_head,var);
					if(type==-1)					
						type=find_arg_type(cst_head,var);
					if(type==-1)					
						type=find_tf_type(type_head,var);
					if(type==-1)
						type=find_cf_type(class_head,var);	
					if(type==-1)
						type=find_type(line_head,var);
					if(type==-1)
						type=find_type(cst_head,var);		
					if(type==-1)
						type=find_type(gst_head,var);
					if(type==-1)		
						type=find_type_type(type_head,var);
					if(type==-1)
						type=find_class_type(class_head,var);	
					if(type==-1)
					{
						printf("VARIABLE NOT DECLARED\n");
						exit(0);
					}
					else
					{
						yylval.tree_node=create_t_node(-1,"-",type,strdup(yytext),leaf,current_block,NULL,NULL);			
					}
				} 
				return ID;
			}

[0-9]+			{	
				printf("NUM  ");
				yylval.tree_node=create_t_node(atoi(yytext),"-",inttype,"-VAR",leaf,current_block,NULL,NULL);
				return NUM;
			}
	
\/\/.*			{
				printf("(COMMENT) ");
			}

"{"			{
				printf("{ ");
				cl_brac_flag=1;
				return CL_LBRAC;
			}

"}"			{
				printf("} ");
				cl_brac_flag=0;
				return CL_RBRAC;
			}

"["			{
				printf("[ ");
				return SQ_LBRAC;
			}

"]"			{
				printf("] ");
				return SQ_RBRAC;
			}

"("			{
				printf("( ");
				brac_flag=1;
				return LBRAC;
			}

")"			{
				printf(") ");
				brac_flag=0;
				return RBRAC;
			}
	
"+" 			{
				printf("+ ");
				return PLUS;
			}

"-" 			{
				printf("- ");
				return MINUS;
			}
	
"*" 			{
				printf("* ");
				return MUL;
			}

"/" 			{
				printf("/ ");
				return DIV;
			}

"%"			{
				printf("%% ");
				return MOD;
			}

"<"			{
				printf("< ");
				return LT;
			}

">"			{	
				printf("> ");
				return GT;
			}

"!="			{
				printf("!= ");
				return NEQ;
			}

"=="			{
				printf("== ");
				return EQ;
			}

">="			{
				printf(">= ");
				return GEQ;
			}

"<="			{
				printf("<= ");
				return LEQ;
			}

"="			{
				printf("= ");
				return ASSIGN;
			}

"," 			{
				printf(", ");
				return COMMA;
			}

";"			{
				printf("; ");
				return SEMIC;
			}

\n 			{
				printf("\n");
			}

\t			{	
				printf("\t");
			}
			
\.			{
				printf(". ");
				return DOT;
			}

.			{;}

%%
 	
