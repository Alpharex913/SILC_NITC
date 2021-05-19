#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct l_node
{
	int label;
	int addrs;

	struct l_node *left,*right;
};

struct l_node* new_l_node(int label,int addrs)
{
	struct l_node *new_node=(struct l_node*)malloc(sizeof(struct l_node));
	
	new_node->label=label;
	new_node->addrs=addrs;
	
	new_node->left=NULL;
	new_node->right=NULL;
}


struct l_node* create_l_node(struct l_node *head,int label,int addrs)
{
	if(head==NULL)
	{
		return new_l_node(label,addrs);
	}
	if(label<=(head->label))
		head->left=create_l_node(head->left,label,addrs);
	if(label>(head->label))
		head->right=create_l_node(head->right,label,addrs);
	return head;
}	


int get_l_addrs(struct l_node *head,int label)
{
	if(head==NULL)
		return 0;
	if(head->label==label)
		return head->addrs;
	if(label<(head->label))
		return get_l_addrs(head->left,label);
	if(label>(head->label))
		return get_l_addrs(head->right,label);
}



int l_addrs(int line_no)
{
	int base_addrs=2048;
	if(line_no<=8)
		return (base_addrs + (line_no-1));
	else
		return (base_addrs + 8 + (((line_no-1)-8)*2));
}

int  extract_num(char *str)
{
	char label[100];
	
	int i=1;
	int j=0;

	while(isdigit(str[i]))
	{
		label[j++]=str[i++];
	}

	label[j]='\0';

	return atoi(label);
}


void print_labels(struct l_node *head)
{
	if(head==NULL)
		return;
	
	print_labels(head->left);
	
	printf("L%d : %d\n",head->label,head->addrs);

	print_labels(head->right);
}
