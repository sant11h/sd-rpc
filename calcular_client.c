#include "calcular.h"
#include <stdio.h>
#include <stdlib.h>

int compute(CLIENT *sv, int a, int b, char op)
{
	int *res;
	values p_values;
	
	if (op == '+')
	{
		p_values.a=a;
		p_values.b=b;
		res = sumar_1(&p_values, sv);
	
		if (res == (int *) NULL)
		{
			clnt_perror(sv, "Call failed");
			exit(0);
		}
		return(*res);
	}
	else if (op == '-')
	{
		p_values.a=a;
		p_values.b=b;
		res = restar_1(&p_values, sv);
	
		if (res == (int *) NULL)
		{
			clnt_perror(sv, "Call failed");
			exit(0);
		}
		return(*res);
	}
	else if (op == '*')
	{
		p_values.a=a;
		p_values.b=b;
		res = multiplicar_1(&p_values, sv);
	
		if (res == (int *) NULL)
		{
			clnt_perror(sv, "Call failed");
			exit(0);
		}
		return(*res);
	}

}

void main(int argc, char *argv[])
	{
		char *host;
		int a, b;
		char op;
		CLIENT *sv;
		host = argv[1];

		sv = clnt_create(host, calcular, UNO, "udp");
		if (sv == NULL) 
		{
			clnt_pcreateerror(host);
			exit(1);
		}

		printf("Enter the first number: ");
		scanf("%d", &b);
		printf("Enter the second number: ");
		scanf("%d", &a);
		printf("Enter the operation (+, -, *):");
		scanf(" %c",&op);	

		printf("%d + %d = %d\n", a, b, compute(sv, a, b, op));
		clnt_destroy(sv);
		exit(0);
}

