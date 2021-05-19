%option noyywrap

%{
#include <stdio.h>
#include "l_func.c"

extern int l_addrs(int);
extern struct l_node* create_l_node(struct l_node*,int,int);
extern int get_l_addrs(struct l_node*,int);
extern int extract_num(char *);
extern void print_labels(struct l_node*);

int line;
int parse_count;

struct l_node *head=NULL;

%}


%%

[L][0-9]+[:][\n]	{
				if(parse_count==1)
				{
					int label=extract_num(strdup(yytext));
					
					printf("CREATE L%d NODE ",label);
					printf(":%d\n",l_addrs(line+1));
					head=create_l_node(head,label,l_addrs(line+1));
				}
			}

[L][0-9]+		{
				if(parse_count==1)
				{	
					printf("%s",yytext);
				}
				else if(parse_count==2)
				{
					int label=extract_num(strdup(yytext));
					fprintf(yyout,"%d",get_l_addrs(head,label));
				}	
			}

\n 			{//	the line addrs is calculated after reading the newline 
				if(parse_count==1)
				{	
					line++;
					printf(" :%d\n",l_addrs(line));
				}			
				else if(parse_count==2)
					fprintf(yyout,"\n");
			}


.       		{	
				if(parse_count==1)
					printf("%s",yytext);
				else if(parse_count==2)
					fprintf(yyout,"%s",yytext);
			}	

%%

int main(int argc,char* argv[])
{
	parse_count=1;
	line=0;
	yyin=fopen(argv[1],"r");
        yylex();

	printf("Number of lines:%d\n",line);

	print_labels(head);

	parse_count++;
	yyout=fopen("../test.xsm","w");
	yyin=fopen(argv[1],"r");
	yylex();

        return 0;
}

