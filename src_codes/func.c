#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define inttype 0
#define boolean 1
#define strtype 2
#define leaf    3
#define div     4
#define mul     5
#define sub     6
#define plus    7
#define assgn   8
#define write   9
#define read    10
#define connect 11
#define greater_than    12
#define less_than       13
#define not_equal       14
#define equal           15
#define greater_equal   16
#define less_equal      17
#define if_part         18
#define else_part       19
#define while_do        20
#define cont_stmt       21
#define brk_stmt        22
#define leaf_arr	23
#define mod 		24
#define function 	25
#define func_call	26
#define ret_stmt	27
#define heap_init_stmt	28
#define heap_alloc_stmt 29
#define heap_free_stmt  30
#define leaf_tf		31	
#define leaf_cf		32	
#define	cf_func_call	33
#define brk_point	34
#define vr_tbl_alloc	35 	
#define class_func_call	36	

int reg_count=0;
int l_reg_count=0;
int label_count=0;

FILE* target_file;

extern int current_block;
extern int end_flag;
extern int decl_flag;
extern int main_flag;
extern int code_flag;

//-------------------------------------------------------------------------------------------

struct field_list
{
	char* name;
	int index; 
	int type;

	char* type_set;

	struct field_list* next;
};	

struct field_list* f_list_head=NULL;

struct field_list* create_field_entry(char* name,int index,char* type_set)
{
	struct field_list* new_node=(struct field_list*)malloc(sizeof(struct field_list));

	new_node->name=name;
	new_node->index=index;
	new_node->type=69;
	
	new_node->type_set=type_set;

	new_node->next=NULL;
}

void print_field_entries(struct field_list* head)
{
	if(head==NULL)
		return;
	else
	{
		printf("	<>|%s : [%d,%s,%d]\n",head->name,head->index,head->type_set,head->type);
	}
	print_field_entries(head->next);
}


int find_field_type(struct field_list* head,char* name)				
{
	if(head==NULL)
		return -1;
	else
	{
		if(strcmp(head->name,name)==0)
			return head->type;
	}
	find_field_type(head->next,name);
}

int find_index(struct field_list* head,char* name)
{
	if(head==NULL)
		return -1;
	else 
	{
		if(strcmp(head->name,name)==0)
			return head->index;
	}
	find_index(head->next,name);
}

//------------------------------------------------------------------------------------------//

struct type_table
{
	char* name;
	int size;
	int type;			

	struct field_list* f_list;
	int tf_flag;

	struct type_table* next;
};

struct type_table* type_head=NULL;

struct type_table* create_t_entry_node(char* name,int size,int type)
{
	struct type_table* new_node=(struct type_table*)malloc(sizeof(struct type_table));

	new_node->name=name;
	new_node->size=size;
	new_node->type=type;		

	new_node->f_list=NULL;
	new_node->tf_flag=0;

	new_node->next=NULL;
}

void print_type_table(struct type_table* head)
{
	if(head==NULL)
		return;
	else
	{
		printf("\n^^^^^^^^^^^^^^^^^^^^^^^^^\n");
		printf("%s : %d %d\n",head->name,head->size,head->type);
		if(head->f_list!=NULL)
			print_field_entries(head->f_list);
		printf("^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	}
	print_type_table(head->next);
}

int find_type_type(struct type_table* head,char* name)				
{
	if(head==NULL)
		return -1;
	else
	{
		if(strcmp(head->name,name)==0)
		{
			return head->type;
		}
	}
	find_type_type(head->next,name);
}

void set_field_type(struct type_table* tt_head, struct field_list* fl_head)
{
	while(fl_head!=NULL)
	{
		if(strcmp(fl_head->type_set,"inttype")==0)
                                fl_head->type=inttype;
                if(strcmp(fl_head->type_set,"strtype")==0)
                                fl_head->type=strtype;

		struct type_table* temp=tt_head;
		while(temp!=NULL)
		{
			if(strcmp(fl_head->type_set,temp->name)==0)
				fl_head->type=temp->type;
			temp=temp->next;
		}

		fl_head=fl_head->next;
	}
}



struct field_list* get_type_field(struct type_table* head,int type)	
{
	if(head==NULL)
		return NULL;
	else
	{
		if(head->type==type)
			return head->f_list;
		get_type_field(head->next,type);
	}
}


int find_field_index(struct type_table* head,int type_type,char* name)	
{
	if(head==NULL)
		return -1;
	else 
	{
		if(head->type==type_type)
			return find_index(head->f_list,name);
	}
	find_field_index(head->next,type_type,name);
}

void turn_on_tf_flag(struct type_table* head,int type)	
{
	if(head==NULL)
		return;
	else
	{
		if(head->type==type)
			head->tf_flag=1;
		else
			turn_on_tf_flag(head->next,type);
	}
}

void turn_off_tf_flag(struct type_table* head)		
{
	if(head==NULL)
		return;
	else
	{
		head->tf_flag=0;
		turn_off_tf_flag(head->next);
	}
}

int find_tf_type(struct type_table* head,char* name)	
{
	if(head==NULL)
		return -1;
	else
	{
		if(head->tf_flag==1)
		{
			int type=find_field_type(head->f_list,name);
			if(type>69)	
			{
				turn_off_tf_flag(type_head);
				turn_on_tf_flag(type_head,type);
			}
			else
				turn_off_tf_flag(type_head);
			return type;
		}
		else
			find_tf_type(head->next,name);
	}
}

int check_type_type(struct type_table* head,int type)			
{
	if(head==NULL)
		return -1;
	else
	{
		if(head->type==type)
			return head->type;
		check_type_type(head->next,type);
	}
}

//--------------------------------------------------------------------------------------------

struct param_struct 
{
	char* name;			//name of variable
	int binding;			//address space
	int type;			//variable type 

	struct param_struct* next;	//next 
};

struct param_struct* param_head=NULL;

struct param_struct* create_param_node(char* name,int binding,int type)
{
	struct param_struct* new_node=(struct param_struct*)malloc(sizeof(struct param_struct));

	new_node->name=name;
	new_node->binding=binding;
	new_node->type=type;

	new_node->next=NULL;

	return new_node;
}

int find_param_type(struct param_struct* head,char* var)
{
	if(head==NULL)
		return -1;
	else
	{
		if(strcmp(head->name,var)==0)
			return head->type;
	}
	find_param_type(head->next,var);
}

void print_param(struct param_struct* head)
{
	if(head==NULL)
                return;
        else
        {
                printf("	>|%s : %d %d \n",head->name,head->type,head->binding);
	}
	
	print_param(head->next);
}


int check_arg_list(struct param_struct* arg_head,struct param_struct* arg_check_head)
{
        if(arg_head==NULL && arg_check_head==NULL)
        {
                return 1;
        }
        else if(arg_head==NULL || arg_check_head==NULL)
        {
                return 0;
        }
        else if(strcmp(arg_head->name,arg_check_head->name)==0)
        {
                check_arg_list(arg_head->next,arg_check_head->next);
        }
}


//-----------------------------------------------------------------------------------------//

struct symbol
{	
	char* name;				//name of variable
	int type;				//type of variable 
	int size;				//size of variable 	
	int binding;				//stores static memory address allocated

	struct param_struct* param_list;	//points to list of parameters 

	int f_label;				//start address of func
	int func_flag;				//function flag

//	int i;					//[i][j]
	int j;		

	struct symbol* next;
};	

struct symbol* extend_head=NULL;		//extended decl for class
struct symbol* cst_head=NULL;			//class 	
struct symbol* gst_head=NULL;			//global 
struct symbol* line_head=NULL;			//line 
struct symbol* line_var=NULL;			//var in line

struct symbol* l_var_count=NULL;		//used for saving local variable count

struct var_decl
{
	struct symbol* lst_head;
}list[100];



struct symbol* create_s_node(char* name,int type,int size,int binding,struct param_struct* param_list,int j)
{
	struct symbol* new_node=(struct symbol*)malloc(sizeof(struct symbol));

	new_node->name=name;
	new_node->type=type;
	new_node->size=size;
	new_node->binding=binding;

	new_node->param_list=param_list;

	new_node->f_label=-1;		
	new_node->func_flag=0;

//	new_node->i=0;				//not in use
	new_node->j=j;

	new_node->next=NULL;

	return new_node;
}


void print_table(struct symbol* head)
{
	if(head==NULL)
		return;
	else 
	{	
		printf(">%s : [%d,%d,%d,%d,%d,%d]\n",head->name,head->type,head->size,head->binding,head->f_label,head->j,current_block);
			if(head->param_list!=NULL)
			{
				print_param(head->param_list);
			}
		print_table(head->next);
	}
}


void set_type(struct symbol* head,int type)
{
	if(head==NULL)
		return;
	else 
		head->type=type;
	set_type(head->next,type);
}

void set_size_to(struct symbol* head,int size)			
{
	if(head==NULL)
		return;
	else 
		head->size=size;
	set_size_to(head->next,size);
}


void set_f_flag(struct symbol* head, int flag)
{
	if(head==NULL)
		return;
	else 
		head->func_flag=flag;
	set_f_flag(head->next,flag);
}


void set_f_flag_to(struct symbol* head,char*var,int flag)
{
	if(head==NULL)
		return;
	else
	{
		if(strcmp(head->name,var)==0)
			head->func_flag=flag;
	set_f_flag_to(head->next,var,flag);
	}
}

struct class;
void turn_off_cf_flag(struct class* head);
void turn_on_cf_flag(struct class* head,int type);
struct class* class_head;

int find_type(struct symbol* head,char* var)
{
	if(head==NULL)
		return -1;	
	else
	{
		if(strcmp(head->name,var)==0)
		{
			if(head->f_label!=-1 && end_flag==0 && decl_flag==0 && main_flag==0 && code_flag==0)
			{
				set_f_flag(gst_head,0);
				set_f_flag(cst_head,0);					
				head->func_flag=1;
			}			
			if(end_flag==1)
			{	
				end_flag=0;
			}
			if(head->type>69)	
			{
				turn_off_tf_flag(type_head); 		
				turn_off_cf_flag(class_head);				
				turn_on_tf_flag(type_head,head->type);
				turn_on_cf_flag(class_head,head->type);			
			}

			return head->type;
		}
	}

	find_type(head->next,var);
}



int find_arg_type(struct symbol* head,char* var)
{
	if(head==NULL)
		return -1;
	else 
	{
		if(head->func_flag==1)
		{
			struct param_struct* temp=head->param_list;
		       	while(temp!=NULL)
			{
				if(strcmp(temp->name,var)==0)
				{
					if(temp->type>69)     
                        		{
						turn_off_tf_flag(type_head);
						turn_off_cf_flag(class_head);			
                                		turn_on_tf_flag(type_head,temp->type); 	 
						turn_on_cf_flag(class_head,temp->type);	
                        		}
					return temp->type;
				}
				temp=temp->next;
			}
		}
	}

	find_arg_type(head->next,var);
}


int find_array_size(struct symbol* head,char* var)
{
        if(head==NULL)
                return 0;
        else
        {
                if(strcmp(head->name,var)==0)
		{
                        return head->j;
		}
        }

        find_array_size(head->next,var);
}


int find_arg_addrs(struct symbol* head,char* var)
{
        if(head==NULL)
                return 0;
        else
        {
                if(head->func_flag==1)
                {
                        struct param_struct* temp=head->param_list;
                        while(temp!=NULL)
                        {
                                if(strcmp(temp->name,var)==0)
                                        return temp->binding;
                                temp=temp->next;
                        }
                }
        }

        find_arg_addrs(head->next,var);
}


struct param_struct* find_func_arg_list(struct symbol* head)	
{
	if(head==NULL)
                return NULL;
        else
        {
		if(head->func_flag==1)
                {
                        return head->param_list;
		}
	}
	return find_func_arg_list(head->next);				
}


int find_var_addrs(struct symbol* head,char* var)
{
        if(head==NULL)
                return 0;
        else
        {
                if(strcmp(head->name,var)==0)
		{
                        return head->binding;
		}
        }

        find_var_addrs(head->next,var);
}


int find_f_label(struct symbol* head,char* f_name)
{
	if(head==NULL)
		return -1;
	else
	{
		if(strcmp(head->name,f_name)==0)
		{
			return head->f_label;
		}
		else
		{
			find_f_label(head->next,f_name);
		}
	}
}


int getlabel();

struct symbol*  copy_extend_head(struct symbol* extend_head,int field_index)
{
	if(extend_head==NULL)
		return NULL;
	else
	{
		struct symbol* new_node=(struct symbol*)malloc(sizeof(struct symbol));
		
		new_node->name=extend_head->name;
		new_node->type=extend_head->type;
		new_node->size=extend_head->size;
		
		
		if(extend_head->binding!=-1)
			new_node->binding=extend_head->binding+field_index;
		else
			new_node->binding=extend_head->binding;
		
		
		new_node->param_list=extend_head->param_list;
		new_node->f_label=extend_head->f_label;

		new_node->func_flag=extend_head->func_flag;
		new_node->j=extend_head->j;

		new_node->next=copy_extend_head(extend_head->next,field_index);

		return new_node;
	}
}



struct symbol* change_f_label(struct symbol* extend_head)
{
	if(extend_head==NULL)
		return NULL;
	else
	{
		struct symbol*new_node=(struct symbol*)malloc(sizeof(struct symbol));

		new_node->name=extend_head->name;
		new_node->type=extend_head->type;
		new_node->size=extend_head->size;
		new_node->binding=extend_head->binding;
		new_node->param_list=extend_head->param_list;

		if(extend_head->f_label!=-1)
			new_node->f_label=getlabel();
		else
			new_node->f_label=extend_head->f_label;

		new_node->func_flag=extend_head->func_flag;
		new_node->j=extend_head->j;

		new_node->next=change_f_label(extend_head->next);

		return new_node;
	}
}


void fix_decl_list(struct symbol* head)
{
	struct symbol* temp_1=head;
	while(temp_1->next!=NULL)
	{
		struct symbol* temp_2=temp_1->next;
		while(temp_2!=NULL)
		{
			if(strcmp(temp_2->name,temp_1->name)==0)
			{
				temp_1->f_label=temp_2->f_label;
				temp_2->f_label=-1;
			}
			temp_2=temp_2->next;
		}
		temp_1=temp_1->next;
	}
}


//--------------------------------------------------------------------------------------------//

struct t_node;

struct class							
{
	char* name;
        int size;
        int type;

        struct symbol* decl_list;
	struct t_node* func_list;
        int cf_flag;

        struct class* next;
};

struct class* create_c_node(char* name,int size,int type)	
{
	struct class* new_node=(struct class*)malloc(sizeof(struct class));

	new_node->name=name;
	new_node->size=size;
	new_node->type=type;

	new_node->decl_list=NULL;
	new_node->func_list=NULL;
	new_node->cf_flag=0;
	
	new_node->next=NULL;

	return new_node;
}


void print_class_list(struct class* head)			
{
	if(head==NULL)
		return;
	else
	{
		printf("->%s : %d %d %d\n",head->name,head->size,head->type,head->cf_flag);
		print_class_list(head->next);
	}
}

int find_class_type(struct class* head,char* name)
{
	if(head==NULL)
		return -1;
	else
	{
		if(strcmp(head->name,name)==0)
			return head->type;			
		return find_class_type(head->next,name);
	}
}

void turn_off_cf_flag(struct class* head)
{
	if(head==NULL)
		return;
	else 
	{
		head->cf_flag=0;
		turn_off_cf_flag(head->next);
	}
}

void turn_on_cf_flag(struct class* head,int type)
{
	if(head==NULL)
		return;
	else
	{
		if(head->type==type)
			head->cf_flag=1;
		else
			turn_on_cf_flag(head->next,type);
	}
}

int find_cf_type(struct class* head,char* name)
{
	if(head==NULL)
		return -1;
	else
	{
		if(head->cf_flag==1)
			return find_type(head->decl_list,name);
		find_cf_type(head->next,name);
	}
}

int check_class_type(struct class* head,int type)			
{
	if(head==NULL)
		return -1;
	else 
	{
		if(head->type==type)
			return head->type;
		check_class_type(head->next,type);
	}
}

struct symbol* get_class_decl_list(struct class* head,char* str)	
{
	if(head==NULL)
		return NULL;
	else
	{
		if(strcmp(head->name,str)==0)
			return head->decl_list;
		get_class_decl_list(head->next,str);
	}
}

struct symbol* get_class_decl_list_by_type(struct class* head,int type)	
{
	if(head==NULL)
		return NULL;
	else
	{
		if(head->type==type)
			return head->decl_list;
		get_class_decl_list_by_type(head->next,type);
	}
}

int find_class_field_index(struct class* head,int class_type,char* name)
{
	if(head==NULL)
		return -1;
	else
	{
		if(head->type==class_type)
			return find_var_addrs(head->decl_list,name);
		find_class_field_index(head->next,class_type,name);
	}
}

struct t_node* get_class_func_list(struct class* head,char* name)
{
	if(head==NULL)
		return NULL;
	else 
	{
		if(strcmp(head->name,name)==0)
			return head->func_list;
		get_class_func_list(head->next,name);
	}
}

int get_class_field_size(struct class* head,char* name)
{
	if(head==NULL)
		return 0;
	else
	{
		if(strcmp(head->name,name)==0)
			return head->size;
		get_class_field_size(head->next,name);
	}
}

int class_func_index(struct class* head,int class_type,char* f_name)
{
	if(head==NULL)
		return -1;
	else 
	{
		if(head->type==class_type)
		{
			struct symbol* temp_list=head->decl_list;
			int index=1;
			while(temp_list!=NULL)
			{
				if(strcmp(temp_list->name,f_name)==0)
				{
					return index;
				}
				temp_list=temp_list->next;
				index++;
			}
		}
		class_func_index(head->next,class_type,f_name);
	}
}

//--------------------------------------------------------------------------------------------//

struct t_node
{	 
	int val;			//stores value for int leaf node
	char* str;			//stores strng for char leaf node
	int type;			//var type 
	char* varname;			//var name 
	int node_type;			//node type 

	int block_no;			//specifies part of the code block number
	
	struct symbol* l_var_list;	//local variable list
		
	struct t_node* left;
	struct t_node* right;
};

struct t_node* extend_func_list=NULL;

void ast_code_gen(struct t_node* head,int start,int exit);
int type_field_code_gen(struct t_node* head);                           
int class_field_code_gen(struct t_node* head);


struct t_node* create_t_node(int val,char* str,int type,char* varname,int node_type,int block_no,struct t_node* left,struct t_node* right)
{
	struct t_node* new_node=(struct t_node*)malloc(sizeof(struct t_node));

	new_node->val=val;
	new_node->str=str;
	new_node->type=type;
	new_node->varname=varname;
	new_node->node_type=node_type;

	new_node->block_no=block_no;

	new_node->l_var_list=NULL;

	new_node->left=left;
	new_node->right=right;

	return new_node;
}

struct t_node* copy_t_node(struct t_node* head)
{
	if(head==NULL)
		return NULL;
	else
	{
		struct t_node* new_node=(struct t_node*)malloc(sizeof(struct t_node));

		new_node->val=head->val;
		new_node->str=head->str;
		new_node->type=head->type;
		new_node->varname=head->varname;
		new_node->node_type=head->node_type;
		
		new_node->block_no=head->block_no;

		new_node->l_var_list=head->l_var_list;

		new_node->left=copy_t_node(head->left);
		new_node->right=copy_t_node(head->right);

		return new_node;
	}
}


void set_class_name(struct t_node* head,char* name)			
{
	if(head==NULL)
		return;
	else
	{
		if(strcmp(head->varname,"-CHANGE-")==0)
			head->varname=name;
		if(strcmp(head->str,"-CHANGE-")==0)
			head->str=name;
		set_class_name(head->left,name);
		set_class_name(head->right,name);
	}
}


void update_func_list(struct t_node* head,char* to_this,char* from_this)
{
	if(head==NULL)
		return;
	else
	{
		if(strcmp(head->str,from_this)==0)
			head->str=to_this;
		update_func_list(head->left,to_this,from_this);
		update_func_list(head->right,to_this,from_this);
	}
}


void remove_dup(struct t_node* head,char* name)
{
	if(head==NULL)
		return;
	else
	{
		if(head->node_type==function)
		{
			if(strcmp(head->varname,name)==0)
			{
				head->varname="-REMOVE-";
			}
		}

		remove_dup(head->left,name);
		remove_dup(head->right,name);
	}
}


void fix_func_list(struct t_node* head)
{
	if(head==NULL)
		return;
	else
	{
		if(head->node_type==connect && (head->left->node_type==function || head->right->node_type==function))
		{
			if(head->left->node_type==function)
			{
				if(strcmp(head->left->varname,"-REMOVE-")!=0)
				{
					remove_dup(head->right,head->left->varname);
				}
			}
			if(head->right->node_type==function)
			{
				if(strcmp(head->right->varname,"-REMOVE-")!=0)
				{
					remove_dup(head->left,head->right->varname);
				}
			}
		}

		fix_func_list(head->left);
		fix_func_list(head->right);
	}
}


//--------------------------------------------------------------------------------------------

int getreg()
{
	return reg_count++;
}

int freereg()
{
	return reg_count--;
}

int getlabel()
{
	return label_count++;
}

//--------------------------------------------------------------------------------------------

void read_code_gen(char* var,int block_no,int offset,int array_flag)
{
	int stack_addrs;
	if(array_flag==0)						
	{
		stack_addrs=find_var_addrs(list[block_no].lst_head,var);

		if(stack_addrs==0)
			stack_addrs=find_arg_addrs(gst_head,var);
		if(stack_addrs==0)
			stack_addrs=find_var_addrs(gst_head,var);
	}
	if(array_flag==1)
		stack_addrs=find_var_addrs(gst_head,var);

        int free_reg=getreg();
        fprintf(target_file,"MOV R%d , \"Read\"\n",free_reg);
        fprintf(target_file,"PUSH R%d\n",free_reg);             	//func_code
        fprintf(target_file,"MOV R%d , -1\n",free_reg);
        fprintf(target_file,"PUSH R%d\n",free_reg);             	//arg_1
	
	if(stack_addrs>4095 && array_flag!=-1)				
		fprintf(target_file,"MOV R%d , %d\n",free_reg,stack_addrs);	
	if(stack_addrs<0 && array_flag!=-1)					
	{
		fprintf(target_file,"MOV R%d , BP\n",free_reg);
		fprintf(target_file,"ADD R%d , %d\n",free_reg,stack_addrs-2);
	}
	if(stack_addrs>0 && stack_addrs<4095 && array_flag!=-1)				
	{
		fprintf(target_file,"MOV R%d , BP\n",free_reg);
		fprintf(target_file,"ADD R%d , %d\n",free_reg,stack_addrs);
	}		

	if(array_flag==1)
		fprintf(target_file,"ADD R%d , R%d\n",free_reg,offset);
	if(array_flag==-1)				
		fprintf(target_file,"MOV R%d , R%d\n",free_reg,offset);	

        fprintf(target_file,"PUSH R%d\n",free_reg);          		//arg_2
        fprintf(target_file,"PUSH R%d\n",free_reg);             	//arg_3
        fprintf(target_file,"PUSH R%d\n",free_reg);             	//return_val
        fprintf(target_file,"CALL 0\n");
        fprintf(target_file,"POP R%d\n",free_reg);                      //return_val
        fprintf(target_file,"POP R%d\n",free_reg);                      //arg_3
        fprintf(target_file,"POP R%d\n",free_reg);                      //arg_2
        fprintf(target_file,"POP R%d\n",free_reg);                      //arg_1
        fprintf(target_file,"POP R%d\n",free_reg);                      //func_code

        freereg();
}


//--------------------------------------------------------------------------------------------

void write_code_gen(int reg)
{
	int free_reg=getreg();
	fprintf(target_file,"MOV R%d , \"Write\"\n",free_reg);
	fprintf(target_file,"PUSH R%d\n",free_reg);			//func_code
	fprintf(target_file,"MOV R%d , -2\n",free_reg);
	fprintf(target_file,"PUSH R%d\n",free_reg);			//arg_1
	fprintf(target_file,"PUSH R%d\n",reg);				//arg_2
	fprintf(target_file,"PUSH R%d\n",free_reg);			//arg_3
	fprintf(target_file,"PUSH R%d\n",free_reg);			//return_val
	fprintf(target_file,"CALL 0\n");
	fprintf(target_file,"POP R%d\n",free_reg);			//return_val
	fprintf(target_file,"POP R%d\n",free_reg);			//arg_3
	fprintf(target_file,"POP R%d\n",free_reg);			//arg_2
	fprintf(target_file,"POP R%d\n",free_reg);			//arg_1
	fprintf(target_file,"POP R%d\n",free_reg);			//func_code

	freereg();
}

//--------------------------------------------------------------------------------------------

void assgn_code_gen(char* var,int block_no,int reg,int offset,int array_flag)
{
	int stack_addrs;
        if(array_flag==0)
	{
		stack_addrs=find_var_addrs(list[block_no].lst_head,var);

                if(stack_addrs==0)
                        stack_addrs=find_arg_addrs(gst_head,var);
		if(stack_addrs==0)				
			stack_addrs=find_arg_addrs(cst_head,var);
		if(stack_addrs==0)
			stack_addrs=find_var_addrs(gst_head,var);

		if(stack_addrs>4095)						
			fprintf(target_file,"MOV [%d] , R%d\n",stack_addrs,reg);
		if(stack_addrs<0)						
		{	
			int f_reg=getreg();
			fprintf(target_file,"MOV R%d , BP\n",f_reg);
			fprintf(target_file,"ADD R%d , %d\n",f_reg,stack_addrs-2);
			fprintf(target_file,"MOV [R%d] , R%d\n",f_reg,reg);
			freereg();
		}
		if(stack_addrs>0 && stack_addrs<4095)				
		{
                        int f_reg=getreg();
                        fprintf(target_file,"MOV R%d , BP\n",f_reg);
                        fprintf(target_file,"ADD R%d , %d\n",f_reg,stack_addrs);
                        fprintf(target_file,"MOV [R%d] , R%d\n",f_reg,reg);
                        freereg();
                }

	}
        if(array_flag==1)
	{
                stack_addrs=find_var_addrs(gst_head,var);
	
		fprintf(target_file,"ADD R%d , %d\n",offset,stack_addrs);
		fprintf(target_file,"MOV [R%d] , R%d\n",offset,reg);
	}
	if(array_flag==-1)		
	{
		fprintf(target_file,"MOV [R%d] , R%d\n",offset,reg);	
	}
	
	freereg();
}


//-------------------------------------------------------------------------------------------

void exit_code_gen()
{
	int free_reg=getreg();
        fprintf(target_file,"MOV R%d , \"Exit\"\n",free_reg);
        fprintf(target_file,"PUSH R%d\n",free_reg);
        fprintf(target_file,"PUSH R%d\n",free_reg);
        fprintf(target_file,"PUSH R%d\n",free_reg);
        fprintf(target_file,"PUSH R%d\n",free_reg);
        fprintf(target_file,"PUSH R%d\n",free_reg);
        fprintf(target_file,"PUSH R%d\n",free_reg);
        fprintf(target_file,"CALL 0\n");
        fprintf(target_file,"POP R0\n");
        fprintf(target_file,"POP R1\n");
        fprintf(target_file,"POP R1\n");
        fprintf(target_file,"POP R1\n");
        fprintf(target_file,"POP R1\n");

        freereg();
}

//-------------------------------------------------------------------------------------------

int expr_code_gen(struct t_node *head);

void push_args(struct t_node* head)
{
	if(head==NULL)
		return;
	else if(head->node_type==connect)
	{
		push_args(head->right);
		push_args(head->left);
	}
	else
	{
		fprintf(target_file,"PUSH R%d\n",expr_code_gen(head));
		freereg();
	}
}		

void pop_args(struct t_node* head)
{
        if(head==NULL)
                return;
        else if(head->node_type==connect)
        {
                pop_args(head->right);
                pop_args(head->left);
        }
        else
        {
                fprintf(target_file,"POP R%d\n",getreg());
                freereg();
        }
}



//--------------------------------------------------------------------------------------------

int expr_code_gen(struct t_node *head)
{
	if(head==NULL)
		return;
	
	int reg;
	int return_reg;

	if(head->node_type==leaf_arr)
	{
		if(head->left==NULL)
		{
			int offset=expr_code_gen(head->right);
			int stack_addrs=find_var_addrs(gst_head,head->varname);
			fprintf(target_file,"ADD R%d , %d\n",offset,stack_addrs);

			fprintf(target_file,"MOV R%d , [R%d]\n",offset,offset);

			return offset;
		}
	}
	else if(head->node_type==leaf_tf)		
	{
		int offset=type_field_code_gen(head);
		
		fprintf(target_file,"MOV R%d , [R%d]\n",offset,offset);

		return offset;
	}	
	else if(head->node_type==leaf_cf)				
	{		
		if(strcmp(head->varname,"self")!=0)
       		{
             		struct t_node* self=create_t_node(-1,"-",420,"self",leaf,head->block_no,NULL,NULL);
            		struct t_node* class_object=create_t_node(-1,"-",420,head->varname,leaf,head->block_no,NULL,NULL);
            		struct t_node* assgn_head=create_t_node(-1,"-",420,"+A",assgn,head->block_no,self,class_object);

                	ast_code_gen(assgn_head,-1,-1);
       	   	}
			
		int offset=class_field_code_gen(head);
	
		fprintf(target_file,"MOV R%d , [R%d]\n",offset,offset);

		return offset;
	}
	else if(head->node_type==leaf)
	{	
		if(head->type==inttype)
		{
			if(strcmp(head->varname,"-VAR")==0)
			{
				reg=getreg();
				fprintf(target_file,"MOV R%d , %d\n",reg,head->val);
				return reg;
			}
			else 
			{	
				int stack_addrs=find_var_addrs(list[head->block_no].lst_head,head->varname);
				if(stack_addrs==0)						
					stack_addrs=find_arg_addrs(cst_head,head->varname);
				if(stack_addrs==0)						
					stack_addrs=find_arg_addrs(gst_head,head->varname);	
				if(stack_addrs==0)
					stack_addrs=find_var_addrs(gst_head,head->varname);
                        	reg=getreg();
				if(stack_addrs>4095)					
                        		fprintf(target_file,"MOV R%d , [%d]\n",reg,stack_addrs);
				if(stack_addrs<0)                                       
                		{
                        		int f_reg=getreg();
                        		fprintf(target_file,"MOV R%d , BP\n",f_reg);
                        		fprintf(target_file,"ADD R%d , %d\n",f_reg,stack_addrs-2);
                        		fprintf(target_file,"MOV R%d , [R%d]\n",reg,f_reg);
                        		freereg();
                		}
                		if(stack_addrs>0 && stack_addrs<4095)			
                		{
                        		int f_reg=getreg();
                        		fprintf(target_file,"MOV R%d , BP\n",f_reg);
                        		fprintf(target_file,"ADD R%d , %d\n",f_reg,stack_addrs);
                        		fprintf(target_file,"MOV R%d , [R%d]\n",reg,f_reg);
                        		freereg();
                		}
                        	return reg;
                	}
		}
		if(head->type==strtype)
		{
			if(strcmp(head->varname,"-VAR")==0)
			{
				reg=getreg();
				fprintf(target_file,"MOV R%d , %s\n",reg,head->str);
				return reg;
			}
			else
                        {
                                int stack_addrs=find_var_addrs(list[head->block_no].lst_head,head->varname);
				if(stack_addrs==0)						
					stack_addrs=find_arg_addrs(cst_head,head->varname);
				if(stack_addrs==0)						
					stack_addrs=find_arg_addrs(gst_head,head->varname);	
				if(stack_addrs==0)
					stack_addrs=find_var_addrs(gst_head,head->varname);
                                reg=getreg();
				if(stack_addrs>4095)				
                                	fprintf(target_file,"MOV R%d , [%d]\n",reg,stack_addrs);
				if(stack_addrs<0)                                       
                                {
                                        int f_reg=getreg();
                                        fprintf(target_file,"MOV R%d , BP\n",f_reg);
                                        fprintf(target_file,"ADD R%d , %d\n",f_reg,stack_addrs-2);
                                        fprintf(target_file,"MOV R%d , [R%d]\n",reg,f_reg);
                                        freereg();
                                }
                                if(stack_addrs>0 && stack_addrs<4095)                  
                                {
                                        int f_reg=getreg();
                                        fprintf(target_file,"MOV R%d , BP\n",f_reg);
                                        fprintf(target_file,"ADD R%d , %d\n",f_reg,stack_addrs);
                                        fprintf(target_file,"MOV R%d , [R%d]\n",reg,f_reg);
                                        freereg();
                                }
                                return reg;
                        }
		}
		if(head->type>=69 && head->type<=420)	
		{
			if(strcmp(head->varname,"-VAR")==0)
                        {
                                reg=getreg();
                                fprintf(target_file,"MOV R%d , %d\n",reg,head->val);
                                return reg;
                        }
                        else
                        {
                                int stack_addrs=find_var_addrs(list[head->block_no].lst_head,head->varname);
                                if(stack_addrs==0)						
                                        stack_addrs=find_arg_addrs(cst_head,head->varname);
				if(stack_addrs==0)						
					stack_addrs=find_arg_addrs(gst_head,head->varname);	
                                if(stack_addrs==0)
                                        stack_addrs=find_var_addrs(gst_head,head->varname);

                                reg=getreg();
                                if(stack_addrs>4095)
                                        fprintf(target_file,"MOV R%d , [%d]\n",reg,stack_addrs);
                                if(stack_addrs<0)
                                {
                                        int f_reg=getreg();
                                        fprintf(target_file,"MOV R%d , BP\n",f_reg);
                                        fprintf(target_file,"ADD R%d , %d\n",f_reg,stack_addrs-2);
                                        fprintf(target_file,"MOV R%d , [R%d]\n",reg,f_reg);
                                        freereg();
                                }
                                if(stack_addrs>0 && stack_addrs<4095)
                                {
                                        int f_reg=getreg();
                                        fprintf(target_file,"MOV R%d , BP\n",f_reg);
                                        fprintf(target_file,"ADD R%d , %d\n",f_reg,stack_addrs);
                                        fprintf(target_file,"MOV R%d , [R%d]\n",reg,f_reg);
                                        freereg();
                                }
                                return reg;
                        }
		}
		if(head->type>420)				/////////////
		{
                	if(strcmp(head->varname,"-VAR")==0)
                   	{
                           	reg=getreg();
                       		fprintf(target_file,"MOV R%d , %d\n",reg,head->val);
                        	return reg;
                    	}
                  	else
                  	{
                       		int stack_addrs=find_var_addrs(list[head->block_no].lst_head,head->varname);
                         	if(stack_addrs==0)
                          		stack_addrs=find_arg_addrs(cst_head,head->varname);
                          	if(stack_addrs==0)
                                    	stack_addrs=find_arg_addrs(gst_head,head->varname);
                           	if(stack_addrs==0)
                                    	stack_addrs=find_var_addrs(gst_head,head->varname);

                            	reg=getreg();
                          	if(stack_addrs>4095)
				{
                                     	fprintf(target_file,"MOV R%d , [%d]\n",reg,stack_addrs);
				}
                           	if(stack_addrs<0)
                         	{
                                   	int f_reg=getreg();
                                  	fprintf(target_file,"MOV R%d , BP\n",f_reg);
                                   	fprintf(target_file,"ADD R%d , %d\n",f_reg,stack_addrs-2);
                                  	fprintf(target_file,"MOV R%d , [R%d]\n",reg,f_reg);
                                  	freereg();
                           	}
                          	if(stack_addrs>0 && stack_addrs<4095)
                         	{
                                   	int f_reg=getreg();
                                 	fprintf(target_file,"MOV R%d , BP\n",f_reg);
                                	fprintf(target_file,"ADD R%d , %d\n",f_reg,stack_addrs);
                                  	fprintf(target_file,"MOV R%d , [R%d]\n",reg,f_reg);
                                 	freereg();
                           	}
                          	return reg;
                    	}
            	}
	}
	else if(head->node_type==func_call)
	{
		//pushing regs in use 
		for(int i=0;i<reg_count;i++)
		{
			fprintf(target_file,"PUSH R%d\n",i);	
		}
		int save_reg_count=reg_count;
	
		//push all arguments
		push_args(head->right);

		//push space for return value
		fprintf(target_file,"PUSH R0\n");               

		fprintf(target_file,"CALL L%d\n",find_f_label(gst_head,head->left->varname));

		//pop return value and store in reg
		int reg=getreg();
		fprintf(target_file,"POP R%d\n",reg);

		//pop all arguments 
                pop_args(head->right);

		//popping saved regs
		for(int i=save_reg_count-1;i>=0;i--)
		{
			fprintf(target_file,"POP R%d\n",i);
		}
		
		return reg;
	}
	else if(head->node_type==cf_func_call)					
	{		
		struct t_node* temp_head=head;
		struct symbol* local_head=cst_head;
		int type=-1;
		
		if(strcmp(temp_head->varname,"self")!=0)
		{
			struct t_node* self=create_t_node(-1,"-",420,"self",leaf,temp_head->block_no,NULL,NULL);
			struct t_node* class_object=create_t_node(-1,"-",420,temp_head->varname,leaf,head->block_no,NULL,NULL);
			struct t_node* assgn_head=create_t_node(-1,"-",420,"+A",assgn,temp_head->block_no,self,class_object);

			ast_code_gen(assgn_head,-1,-1);
		}
		else
		{
			while(temp_head->left->left!=NULL)
			{
				temp_head=temp_head->left;

				type=find_type(cst_head,temp_head->varname);
         		}
		}

		//pushing regs in use
            	for(int i=0;i<reg_count;i++)
                {
                       	fprintf(target_file,"PUSH R%d\n",i);
             	}
                int save_reg_count=reg_count;

		//push all arguments
                push_args(temp_head->right);

		//push space for return value
               	fprintf(target_file,"PUSH R0\n");
		
		if(type==-1)	
		 	type=find_arg_type(gst_head,temp_head->varname);
		if(type==-1)
			type=find_arg_type(cst_head,temp_head->varname);
		if(type==-1)
			type=find_type(list[head->block_no].lst_head,temp_head->varname);
		if(type==-1)
			type=find_type(cst_head,temp_head->varname);
		if(type==-1)
			type=find_type(gst_head,temp_head->varname);

		if(type==-1 || type==420)		
			local_head=cst_head;
		else
			local_head=get_class_decl_list_by_type(class_head,type);

		//get call label
		fprintf(target_file,"CALL L%d\n",find_f_label(local_head,temp_head->left->varname));

		//pop return value and store in reg
		reg=getreg();
		fprintf(target_file,"POP R%d\n",reg);

		//pop all arguments 
		pop_args(temp_head->right);

		//popping saved regs
		for(int i=save_reg_count-1;i>=0;i--)
		{
			fprintf(target_file,"POP R%d\n",i);
		}
		
		return reg;
	}
	else if(head->node_type==class_func_call)
	{
		int bass_addrs;
		int bass_type;

		if(strcmp(head->varname,"self")!=0)
		{
			struct t_node* self=create_t_node(-1,"-",420,"self",leaf,head->block_no,NULL,NULL);
			struct t_node* class_object=create_t_node(-1,"-",420,head->varname,leaf,head->block_no,NULL,NULL);
			struct t_node* assgn_head=create_t_node(-1,"-",420,"+A",assgn,head->block_no,self,class_object);

			ast_code_gen(assgn_head,-1,-1);
		}
	
		bass_addrs=find_var_addrs(list[head->block_no].lst_head,head->varname);
		if(bass_addrs==0)
			bass_addrs=find_arg_addrs(cst_head,head->varname);
		if(bass_addrs==0)
			bass_addrs=find_arg_addrs(gst_head,head->varname);
		if(bass_addrs==0)
			bass_addrs=find_var_addrs(gst_head,head->varname);
		
		bass_type=find_type(list[head->block_no].lst_head,head->varname);
		if(bass_type==-1)
			bass_type=find_type(gst_head,head->varname);
	
		int func_addrs=bass_addrs+class_func_index(class_head,bass_type,head->left->varname);

		//pushing regs in use
		for(int i=0;i<reg_count;i++)
		{
			fprintf(target_file,"PUSH R%d\n",i);
		}
		int save_reg_count=reg_count;

		//push all arguments
		push_args(head->right);	

		//push space for return value
		fprintf(target_file,"PUSH R0\n");

		//get call label
		int temp_reg=getreg();
		fprintf(target_file,"MOV R%d , %d\n",temp_reg,func_addrs);
		fprintf(target_file,"MOV R%d , [R%d]\n",temp_reg,temp_reg);
		fprintf(target_file,"CALL R%d\n",temp_reg);
		freereg();
	
		//pop return value and store in reg
		reg=getreg();
	       	fprintf(target_file,"POP R%d\n",reg);

		//pop all arguments
		pop_args(head->right);

		//popping saved regs
		for(int i=save_reg_count-1;i>=0;i--)
		{
			fprintf(target_file,"POP R%d\n",i);
		}	

		return reg;
	}
	else 
	{
		return_reg=expr_code_gen(head->left);
		switch(head->node_type)
		{
			case plus:
				fprintf(target_file,"ADD R%d , R%d\n",return_reg,expr_code_gen(head->right));
				break;
			case sub:
				fprintf(target_file,"SUB R%d , R%d\n",return_reg,expr_code_gen(head->right));
				break;
			case mul:
				fprintf(target_file,"MUL R%d , R%d\n",return_reg,expr_code_gen(head->right));
				break;
			case div:
				fprintf(target_file,"DIV R%d , R%d\n",return_reg,expr_code_gen(head->right));
				break;
			case mod:
				fprintf(target_file,"MOD R%d , R%d\n",return_reg,expr_code_gen(head->right));
				break;
			case greater_than:
				fprintf(target_file,"GT R%d , R%d\n",return_reg,expr_code_gen(head->right));
				break;
			case less_than:
				fprintf(target_file,"LT R%d , R%d\n",return_reg,expr_code_gen(head->right));
				break;
			case not_equal:
				fprintf(target_file,"NE R%d , R%d\n",return_reg,expr_code_gen(head->right));
				break;
			case equal:
				fprintf(target_file,"EQ R%d , R%d\n",return_reg,expr_code_gen(head->right));
				break;
			case greater_equal:
				fprintf(target_file,"GE R%d , R%d\n",return_reg,expr_code_gen(head->right));
				break;
			case less_equal:
				fprintf(target_file,"LE R%d , R%d\n",return_reg,expr_code_gen(head->right));
				break;
		}
		freereg();
		return return_reg;
	}

}
//-------------------------------------------------------------------------------------------

void continue_code_gen(int start)
{
	if(start!=-1)
		fprintf(target_file,"JMP L%d\n",start);
}


void break_code_gen(int exit)
{
	if(exit!=-1)
		fprintf(target_file,"JMP L%d\n",exit);
}


//-------------------------------------------------------------------------------------------

void if_part_code_gen(struct t_node* head,int cont,int brk)
{
	int else_code=getlabel();
	int exit=getlabel();

	if(cont==-1)
		cont=exit;
	if(brk==-1)
		brk=exit;

//      condition_part
        int result_reg=expr_code_gen(head->left);

	if(head->right->right!=NULL)	
		fprintf(target_file,"JZ R%d , L%d\n",result_reg,else_code); 
	else 
		fprintf(target_file,"JZ R%d , L%d\n",result_reg,exit);

	freereg();

//      do_part 

	ast_code_gen(head->right->left,cont,brk);

//	else_part

	if(head->right->right!=NULL)
	{
		fprintf(target_file,"JMP L%d\n",exit);
		fprintf(target_file,"L%d:\n",else_code);
		ast_code_gen(head->right->right,cont,brk);
	}

	fprintf(target_file,"L%d:\n",exit);

}

//-------------------------------------------------------------------------------------------

void while_code_gen(struct t_node* head)
{
	int boolean_check=getlabel();
	int exit=getlabel();

	fprintf(target_file,"L%d:\n",boolean_check);

//      condition_part
	int result_reg=expr_code_gen(head->left);
	
	fprintf(target_file,"JZ R%d , L%d\n",result_reg,exit);

	freereg();

//      do_part
	ast_code_gen(head->right,boolean_check,exit);

	fprintf(target_file,"JMP L%d\n",boolean_check);

	fprintf(target_file,"L%d:\n",exit);

}

//--------------------------------------------------------------------------------------------


int init_code_gen()
{
        int free_reg=getreg();
        fprintf(target_file,"MOV R%d , \"Heapset\"\n",free_reg);
        fprintf(target_file,"PUSH R%d\n",free_reg);                   	//func_code
        fprintf(target_file,"PUSH R%d\n",free_reg);                   	//arg_1
        fprintf(target_file,"PUSH R%d\n",free_reg);                   	//arg_2
        fprintf(target_file,"PUSH R%d\n",free_reg);                   	//arg_3
        fprintf(target_file,"PUSH R%d\n",free_reg);                   	//return_val
        fprintf(target_file,"CALL 0\n");
        fprintf(target_file,"POP R%d\n",free_reg);                    	//return_val
        fprintf(target_file,"POP R%d\n",free_reg);                   	//arg_3
        fprintf(target_file,"POP R%d\n",free_reg);                 	//arg_2
        fprintf(target_file,"POP R%d\n",free_reg);                    	//arg_1
        fprintf(target_file,"POP R%d\n",free_reg);                	//func_code

	fprintf(target_file,"MOV R%d , 0\n",free_reg);			//return 0

        return free_reg;
}

//--------------------------------------------------------------------------------------------

int alloc_code_gen()
{
	int free_reg_1=getreg();
	int free_reg_2=getreg();

	fprintf(target_file,"MOV R%d , \"Alloc\"\n",free_reg_2);
        fprintf(target_file,"PUSH R%d\n",free_reg_2);                     //func_code
        fprintf(target_file,"PUSH R%d\n",free_reg_2);                     //arg_1
        fprintf(target_file,"PUSH R%d\n",free_reg_2);                     //arg_2
        fprintf(target_file,"PUSH R%d\n",free_reg_2);                     //arg_3
        fprintf(target_file,"PUSH R%d\n",free_reg_2);                     //return_val
        fprintf(target_file,"CALL 0\n");
        fprintf(target_file,"POP R%d\n",free_reg_1);                      //return_val
        fprintf(target_file,"POP R%d\n",free_reg_2);                      //arg_3
        fprintf(target_file,"POP R%d\n",free_reg_2);                      //arg_2
        fprintf(target_file,"POP R%d\n",free_reg_2);                      //arg_1
        fprintf(target_file,"POP R%d\n",free_reg_2);                      //func_code

	freereg();

	return free_reg_1;
}

//-------------------------------------------------------------------------------------------

void free_heap_code_gen(int reg)
{
	int free_reg=getreg();
	fprintf(target_file,"MOV R%d , \"Free\"\n",free_reg);
        fprintf(target_file,"PUSH R%d\n",free_reg);                     //func_code
        fprintf(target_file,"PUSH R%d\n",reg);                     	//arg_1
        fprintf(target_file,"PUSH R%d\n",free_reg);                     //arg_2
        fprintf(target_file,"PUSH R%d\n",free_reg);                     //arg_3
        fprintf(target_file,"PUSH R%d\n",free_reg);                     //return_val
        fprintf(target_file,"CALL 0\n");
        fprintf(target_file,"POP R%d\n",free_reg);                      //return_val
        fprintf(target_file,"POP R%d\n",free_reg);                      //arg_3
        fprintf(target_file,"POP R%d\n",free_reg);                      //arg_2
        fprintf(target_file,"POP R%d\n",free_reg);                      //arg_1
        fprintf(target_file,"POP R%d\n",free_reg);                      //func_code

	freereg();
}

//--------------------------------------------------------------------------------------------

int type_field_code_gen(struct t_node* head)			
{
	int stack_addrs=find_var_addrs(list[head->block_no].lst_head,head->varname);

     	if(stack_addrs==0)						
           	stack_addrs=find_arg_addrs(cst_head,head->varname);
	if(stack_addrs==0)						
		stack_addrs=find_arg_addrs(gst_head,head->varname);
      	if(stack_addrs==0)
             	stack_addrs=find_var_addrs(gst_head,head->varname);

	int type_type=find_arg_type(cst_head,head->varname);		
	if(type_type==-1)
	 	type_type=find_arg_type(gst_head,head->varname);
  	if(type_type==-1)
     		type_type=find_type(list[head->block_no].lst_head,head->varname);
  	if(type_type==-1)
		type_type=find_type(gst_head,head->varname);


	struct t_node* temp=head->left;			

	int offset=find_field_index(type_head,type_type,temp->varname);	

	int f_reg=getreg();

      	if(stack_addrs>4095)
      	{
        	fprintf(target_file,"MOV R%d , [%d]\n",f_reg,stack_addrs);
              	fprintf(target_file,"ADD R%d , %d\n",f_reg,offset);
     	}
    	if(stack_addrs<0)
     	{
        	fprintf(target_file,"MOV R%d , BP\n",f_reg);
        	fprintf(target_file,"ADD R%d , %d\n",f_reg,stack_addrs-2);
        	fprintf(target_file,"MOV R%d , [R%d]\n",f_reg,f_reg);
        	fprintf(target_file,"ADD R%d , %d\n",f_reg,offset);
     	}
     	if(stack_addrs>0 && stack_addrs<4095)
      	{
        	fprintf(target_file,"MOV R%d , BP\n",f_reg);
        	fprintf(target_file,"ADD R%d , %d\n",f_reg,stack_addrs);
        	fprintf(target_file,"MOV R%d , [R%d]\n",f_reg,f_reg);
        	fprintf(target_file,"ADD R%d , %d\n",f_reg,offset);
     	}
	
	if(temp->left!=NULL)			
	{	
		type_type=temp->type;
		temp=temp->left;
		
		while(temp!=NULL)
		{
			stack_addrs=f_reg;
			offset=find_field_index(type_head,type_type,temp->varname);

			fprintf(target_file,"MOV R%d , [R%d]\n",f_reg,f_reg);
			fprintf(target_file,"ADD R%d , %d\n",f_reg,offset);
			
			type_type=temp->type;
			temp=temp->left;			
		}
	}
	
	return f_reg;
}

//--------------------------------------------------------------------------------------------

int class_field_code_gen(struct t_node* head)
{
	int stack_addrs=find_var_addrs(gst_head,"self");

	struct symbol* temp_head=get_class_decl_list(class_head,head->varname);

	int class_type=find_arg_type(temp_head,head->varname);
	if(class_type==-1)
		class_type=find_arg_type(gst_head,head->varname);
	if(class_type==-1)
		class_type=find_type(list[head->block_no].lst_head,head->varname);
	if(class_type==-1)
		class_type=find_type(temp_head,head->varname);
	if(class_type==-1)
		class_type=find_type(gst_head,head->varname);

	struct t_node* temp=head->left;

	int offset;
	if(class_type!=420)
	 	offset=find_class_field_index(class_head,class_type,temp->varname);
	else
		offset=find_var_addrs(cst_head,temp->varname);
	
	int f_reg=getreg();

	if(stack_addrs>4095)
	{
		fprintf(target_file,"MOV R%d , [%d]\n",f_reg,stack_addrs);
		fprintf(target_file,"ADD R%d , %d\n",f_reg,offset);
	}
	if(stack_addrs<0)
	{
		fprintf(target_file,"MOV R%d , BP\n",f_reg);
		fprintf(target_file,"ADD R%d , %d\n",f_reg,stack_addrs-2);
		fprintf(target_file,"MOV R%d , [R%d]\n",f_reg,f_reg);
		fprintf(target_file,"ADD R%d , %d\n",f_reg,offset);
	}
	if(stack_addrs>0 && stack_addrs<4095)
	{
		fprintf(target_file,"MOV R%d , BP\n",f_reg);
		fprintf(target_file,"ADD R%d , %d\n",f_reg,stack_addrs);
		fprintf(target_file,"MOV R%d , [R%d]\n",f_reg,f_reg);
		fprintf(target_file,"ADD R%d , %d\n",f_reg,offset);
	}

	if(temp->left!=NULL)
	{
		class_type=temp->type;
		temp=temp->left;

		while(temp!=NULL)
		{
			stack_addrs=f_reg;
			offset=find_field_index(type_head,class_type,temp->varname);

			fprintf(target_file,"MOV R%d , [R%d]\n",f_reg,f_reg);
			fprintf(target_file,"ADD R%d , %d\n",f_reg,offset);

			class_type=temp->type;
			temp=temp->left;
		}
	}

	return f_reg;
}

//--------------------------------------------------------------------------------------------

void ast_code_gen(struct t_node* head,int start,int exit)
{
	if(head==NULL)
		return;

	switch(head->node_type)
	{
		case connect:
			ast_code_gen(head->left,start,exit);
			ast_code_gen(head->right,start,exit);
			break;
		case read:
			if(head->left->node_type==leaf)
				read_code_gen(head->left->varname,head->left->block_no,0,0);
			else if(head->left->node_type==leaf_arr)
			{	
				if(head->left->left==NULL)
				{
					int offset=expr_code_gen(head->left->right);
					read_code_gen(head->left->varname,head->left->block_no,offset,1);		
					freereg();
				}
			}
			else if(head->left->node_type==leaf_tf)		
			{
				int offset=type_field_code_gen(head->left);
				
				read_code_gen("-",head->left->block_no,offset,-1);	

				freereg();	
			}
			else if(head->left->node_type==leaf_cf)				
			{
				int offset=class_field_code_gen(head->left);

				read_code_gen("-",head->left->block_no,offset,-1);
			
				freereg();
			}
			break;
		case assgn:
			if(head->left->node_type==leaf)
			{
				if(head->left->type>420)
				{
					int r_stack_addrs=find_var_addrs(list[head->right->block_no].lst_head,head->right->varname);
                                //	if(r_stack_addrs==0)
                                //        	r_stack_addrs=find_arg_addrs(cst_head,head->right->varname);
                               	// 	if(r_stack_addrs==0)
                               	//         	r_stack_addrs=find_arg_addrs(gst_head,head->right->varname);
                                	if(r_stack_addrs==0)
                                        	r_stack_addrs=find_var_addrs(gst_head,head->right->varname);

					int l_stack_addrs=find_var_addrs(list[head->left->block_no].lst_head,head->left->varname);

                		//	if(l_stack_addrs==0)
                        	//		l_stack_addrs=find_arg_addrs(gst_head,head->left->varname);
               	 		//	if(l_stack_addrs==0)
                        	//		l_stack_addrs=find_arg_addrs(cst_head,head->left->varname);
                			if(l_stack_addrs==0)
                        			l_stack_addrs=find_var_addrs(gst_head,head->left->varname);
					if(l_stack_addrs>4095 && r_stack_addrs>4095)
					{
						fprintf(target_file,"MOV [%d] , [%d]\n",l_stack_addrs,r_stack_addrs);
						for(int i=1;i<=8;i++)
						{
							fprintf(target_file,"MOV [%d] , [%d]\n",l_stack_addrs+i,r_stack_addrs+i);
						}
					}
				}

				assgn_code_gen(head->left->varname,head->left->block_no,expr_code_gen(head->right),0,0);
			}
			else if(head->left->node_type==leaf_arr)
			{
                                if(head->left->left==NULL)
                                {
					int offset=expr_code_gen(head->left->right);
					assgn_code_gen(head->left->varname,head->left->block_no,expr_code_gen(head->right),offset,1);
					freereg();
				}
			}
			else if(head->left->node_type==leaf_tf)		
		      	{
				int offset=type_field_code_gen(head->left);		

				assgn_code_gen("-",head->left->block_no,expr_code_gen(head->right),offset,-1);								
				freereg();						
		      	}
			else if(head->left->node_type==leaf_cf)				
			{
				int offset=class_field_code_gen(head->left);
			
				assgn_code_gen("-",head->left->block_no,expr_code_gen(head->right),offset,-1);
				freereg();
			}	
			break;
		case write:
			write_code_gen(expr_code_gen(head->left));
			break;
		case if_part:
			if_part_code_gen(head,start,exit);
			break;
		case while_do:
			while_code_gen(head);	
			break;
		case cont_stmt:
			continue_code_gen(start);
			break;
		case brk_stmt:
			break_code_gen(exit);
			break;
		case ret_stmt:
			if(head->left!=NULL)
			{
				int free_reg=getreg();	
				fprintf(target_file,"MOV R%d , BP\n",free_reg);
				fprintf(target_file,"ADD R%d , -2\n",free_reg);
				fprintf(target_file,"MOV [R%d] , R%d\n",free_reg,expr_code_gen(head->left));
				freereg();
			}
			
			//pop out the local variables
                        while(l_var_count!=NULL)
                        {
                            	fprintf(target_file,"POP R0\n");
                              	l_var_count=l_var_count->next;
                        }

			//POP old BP 
		      	fprintf(target_file,"POP BP\n");

                        //return statement
                        fprintf(target_file,"RET\n");
			break;
		case function:
			{
				struct symbol* temp_head=get_class_decl_list(class_head,head->str);
				cst_head=temp_head;					
				int f_label=find_f_label(cst_head,head->varname);	

				if(f_label==-1)						
				{
					temp_head=gst_head;
					f_label=find_f_label(gst_head,head->varname);
				}
				
				if(f_label==-1)
					break;

				set_f_flag_to(temp_head,head->varname,1);		
				fprintf(target_file,"L%d:\n",f_label);						
				//push BP
				fprintf(target_file,"PUSH BP\n");	
				
				//change to new BP
				fprintf(target_file,"MOV BP , SP\n");	
				
				//allocate stack space for local variables
				struct symbol* temp=head->l_var_list;
				while(temp!=NULL)
				{
					fprintf(target_file,"PUSH R0\n");	
					temp=temp->next;
				}

				l_var_count=head->l_var_list;
				
				int save_reg_count=reg_count;
				reg_count=0;

				ast_code_gen(head->left,-1,-1);	

				//pop out local variable
				temp=head->l_var_list;
                        	while(temp!=NULL)
                        	{
                   			fprintf(target_file,"POP R0\n");
                              		temp=temp->next;
                   		}

				//POP old stack				
				fprintf(target_file,"POP BP\n");
				
				reg_count=save_reg_count;

				//return statement
				fprintf(target_file,"RET\n");				

				set_f_flag(temp_head,0);				
				temp_head=NULL;						
				cst_head=NULL;						
			}
			break;
		case heap_init_stmt:				
			assgn_code_gen(head->left->varname,head->left->block_no,init_code_gen(),0,0);
			break;
		case heap_alloc_stmt:
			if(head->left->node_type==leaf)
			{
				assgn_code_gen(head->left->varname,head->left->block_no,alloc_code_gen(),0,0);	
			}
			else if(head->left->node_type==leaf_tf)
			{
				int offset=type_field_code_gen(head->left);

				assgn_code_gen("-",head->left->block_no,alloc_code_gen(),offset,-1);

				freereg();
			}
			else if(head->left->node_type==leaf_cf)
			{
				int offset=class_field_code_gen(head->left);

				assgn_code_gen("-",head->left->block_no,alloc_code_gen(),offset,-1);

				freereg();
			}
			break;
		case heap_free_stmt:
			if(head->left->node_type==leaf)
			{
				free_heap_code_gen(expr_code_gen(head->left));
				freereg();
			}
			else if(head->left->node_type==leaf_tf)
			{	
				free_heap_code_gen(expr_code_gen(head->left));
				freereg();
			}
			else if(head->left->node_type==leaf_cf)
			{
				free_heap_code_gen(expr_code_gen(head->left));
				freereg();
			}
			break;
		case vr_tbl_alloc:
			{
				struct symbol* decl_list=get_class_decl_list(class_head,head->right->varname);
				int index=1;

				int stack_addrs;
				stack_addrs=find_var_addrs(list[head->left->block_no].lst_head,head->left->varname);
				if(stack_addrs==0)
					stack_addrs=find_arg_addrs(gst_head,head->left->varname);
				if(stack_addrs==0)
					stack_addrs=find_arg_addrs(cst_head,head->left->varname);
				if(stack_addrs==0)
					stack_addrs=find_var_addrs(gst_head,head->left->varname);

				while(decl_list!=NULL)
				{
					if(stack_addrs>4095)
					{
						if(decl_list->f_label==-1)
							fprintf(target_file,"MOV [%d] , %d\n",stack_addrs+index,decl_list->f_label);
						else 
							fprintf(target_file,"MOV [%d] , L%d\n",stack_addrs+index,decl_list->f_label);
					}
					if(stack_addrs<0)
					{
						int f_reg=getreg();
						fprintf(target_file,"MOV R%d , BP\n",f_reg);
						fprintf(target_file,"ADD R%d , %d\n",f_reg,stack_addrs-2+index);
						if(decl_list->f_label==-1)
							fprintf(target_file,"MOV [R%d] , %d\n",f_reg,decl_list->f_label);
						else
							fprintf(target_file,"MOV [R%d] , L%d\n",f_reg,decl_list->f_label);
						freereg();
					}
					if(stack_addrs>0 && stack_addrs<4095)
					{
						int f_reg=getreg();
						fprintf(target_file,"MOV R%d , BP\n",f_reg);
						fprintf(target_file,"ADD R%d , %d\n",f_reg,stack_addrs+index);
						if(decl_list->f_label==-1)
							fprintf(target_file,"MOV [R%d] , %d\n",f_reg,decl_list->f_label);
						else 
							fprintf(target_file,"MOV [R%d] , L%d\n",f_reg,decl_list->f_label);
						freereg();
					}				
		
					index++;
					decl_list=decl_list->next;
				} 
			}			
			break;
		case brk_point:
			fprintf(target_file,"BRKP\n");
			break;
	}

}


//--------------------------------------------------------------------------------------------

void main_code_gen(struct t_node* head,int sp_pointer)
{
	
        fprintf(target_file,"0\n2056\n0\n0\n0\n0\n0\n0\n");
	fprintf(target_file,"MOV SP , %d\n",sp_pointer);

	ast_code_gen(head,-1,-1);

	exit_code_gen();
}
		//-------------------------------------------------------//

void func_code_gen(struct t_node* head)
{
	ast_code_gen(head,-1,-1);
}

		//-------------------------------------------------------//

void class_func_code_gen(struct class* head)
{
	if(head==NULL)
		return;
	else
		func_code_gen(head->func_list);
	class_func_code_gen(head->next);
}	

//--------------------------------------------------------------------------------------------

void print_tree(struct t_node* head)
{
        if(head==NULL)
                return;

        print_tree(head->left);

        if(head->node_type==leaf)
	{	
		if(strcmp(head->varname,"-VAR")==0)
		{	
			if(head->type==inttype)
                		printf("[%d]_%d ",head->val,head->block_no);
			else if(head->type==strtype)
				printf("[%s]_%d ",head->str,head->block_no);
			else if(head->type==420)
				printf("null ");
		}
		else 
			printf("[%s]_%d ",head->varname,head->block_no);
	}
	else if(head->node_type==leaf_arr)
	{
		printf("[%s,(arr)]_%d ",head->varname,head->block_no);
	}
	else if(head->node_type==leaf_tf)
	{
		printf("[%s]_%d ",head->varname,head->block_no);
	}
        else
	{
		switch(head->node_type)
		{
			case div:
				printf("/_%d ",head->block_no);
				break;
			case mul:
				printf("*_%d ",head->block_no);
				break;
			case sub:
				printf("-_%d ",head->block_no);
				break;
			case plus:
				printf("+_%d ",head->block_no);
				break;
			case assgn:
				printf("=_%d ",head->block_no);
				break;
			case write:
				printf("write_%d ",head->block_no);
				break;
			case read:
				printf("read_%d ",head->block_no);
				break;
			case connect:
				printf("(-)_%d ",head->block_no);
				break;
			case greater_than:
				printf(">_%d ",head->block_no);
				break;
			case less_than:
				printf("<_%d ",head->block_no);
				break;
			case not_equal:
				printf("!=_%d ",head->block_no);
				break;
			case equal:
				printf("==_%d ",head->block_no);
				break;
			case greater_equal:
				printf(">=_%d ",head->block_no);
				break;
			case less_equal:
				printf("<=_%d ",head->block_no);
				break;
			case if_part:
				printf("if_%d ",head->block_no);
				break;
			case else_part:
				printf("else_%d ",head->block_no);
				break;
			case while_do:
				printf("while_%d ",head->block_no);
				break;
			case cont_stmt:
				printf("continue_%d ",head->block_no);
				break;
			case brk_stmt:
				printf("break_%d ",head->block_no);
				break;
			case ret_stmt:
				printf("return_%d ",head->block_no);
				break;
			case mod:
				printf("%% %d ",head->block_no);
				break;
			case func_call:
				printf("func_call_%d ",head->block_no);
				break;
			case heap_init_stmt:
				printf("init()_%d ",head->block_no);
				break;
			case heap_alloc_stmt:
				printf("alloc()_%d ",head->block_no);
				break;
			case heap_free_stmt:
				printf("free()_%d ",head->block_no);
				break;
			case leaf_cf:
				printf("[%s]_%d ",head->varname,head->block_no);
				break;
			case cf_func_call:
				printf("func_call_%d ",head->block_no);
				break;
			case vr_tbl_alloc:
				printf("vr_tbl_alloc_%d ",head->block_no);
				break;
			case class_func_call:
				printf("class_func_call_%d ",head->block_no);
				break;
			default:
				printf("n_type_%d not found ",head->node_type);
				break;
		}
	}

        print_tree(head->right);
}


