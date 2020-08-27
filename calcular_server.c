#include "calcular.h"
#include <stdio.h>
 
int * sumar_1_svc(values *argp, struct svc_req *rqstp)
	{
		static int r;
		r = argp->a + argp->b;
		return(&r);
	}
int * restar_1_svc(values *argp, struct svc_req *rqstp)
	{
		static int r;
		r = argp->a - argp->b;
		return(&r);
	}

int * multiplicar_1_svc(values *argp, struct svc_req *rqstp)
	{
		static int r;
		r = argp->a * argp->b;
		return(&r);
	}

