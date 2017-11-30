#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie_manage_program.h"

int main()
{
	movie *M_L=(movie*)malloc(sizeof(movie));
	director *D_L=(director*)malloc(sizeof(director));
	actor *A_L=(actor*)malloc(sizeof(actor));
	m_node * m_newnode = (m_node*)malloc(sizeof(m_node));
	d_node * d_newnode = (d_node*)malloc(sizeof(d_node));
	a_node * a_newnode = (a_node*)malloc(sizeof(a_node));
	M_L=NULL;
	D_L=NULL;
	A_L=NULL;
	m_newnode->actors->next=NULL;
	d_newnode->best_movies->next=NULL;
	a_newnode->best_movies->next=NULL;

	char * value, * command, *opt1, *opt2, *opt3, *opt4;

	welcome();
	prompt(value, command, opt1, opt2, opt3, opt4, M_L, D_L, A_L, m_newnode, d_newnode, a_newnode);
	return 0;
}
