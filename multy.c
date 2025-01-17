#include <Python.h>
#include <math.h>

static PyObject *matrix_mul(PyObject *self, PyObject *args) {
    PyObject* list1;
    PyObject* list2;
    int i, j, k, L;
    double res1, res2;

   
    if (!PyArg_ParseTuple(args, "OO", &list1, &list2)){
        return NULL;
    }

	L = PyList_GET_SIZE(list1);
	
 double **A = (double**)malloc(L * sizeof(double*));
    double **B = (double**)malloc(L * sizeof(double*));
    double **C = (double**)malloc(L * sizeof(double*));
    for (i=0; i<L; i++){
	A[i] = (double*)malloc(L * sizeof(double));
	B[i] = (double*)malloc(L * sizeof(double));
	C[i] = (double*)malloc(L * sizeof(double));
    }

    for (i=0; i<L; i++){
        PyObject* item1 = PySequence_Fast_GET_ITEM(list1, i);
	for (j=0; j<L; j++){
	    res1 = PyFloat_AsDouble(PySequence_Fast_GET_ITEM(item1, j));
	    A[i][j] = res1;
	}
    }


    for (i=0; i<L; i++){
        PyObject* item2 = PySequence_Fast_GET_ITEM(list2, i);
	for (j=0; j<L; j++){
	    res2 = PyFloat_AsDouble(PySequence_Fast_GET_ITEM(item2, j));
	    B[i][j] = res2;
	}
    }


    for(i=0; i<L; i++){
	for(j=0; j<L; j++){
	    C[i][j] = 0;
	    for(k=0; k<L; k++){
		C[i][j] += A[i][k] * B[k][j];
	    }
	}
    }


    PyObject *my_list = PyList_New(0);
    for (i=0; i<L; i++){
	PyObject *new_list = PyList_New(L);
	for (int j=0; j<L; j++){
	    PyObject *the_object = PyFloat_FromDouble(C[i][j]);
	    PyList_SetItem(new_list, j, the_object);
	}
	
	PyList_Append(my_list, new_list); 
    }



    for (i=0;i<L;i++){
	free(A[i]);
	free(B[i]);
	free(C[i]);
    }
    free(A);	
    free(B);	
    free(C);	
    return my_list;
}

static PyObject *sum_matr(PyObject *self, PyObject *args)
{
    PyObject* list1;
    PyObject* list2;
    int i, j, L;
    double res1, res2;

    if (!PyArg_ParseTuple(args, "OO", &list1, &list2)){
        return NULL;
    }
	L = PyList_GET_SIZE(list1);

     double **A = (double**)malloc(L * sizeof(double*));
    double **B = (double**)malloc(L * sizeof(double*));
    double **C = (double**)malloc(L * sizeof(double*));
    for (i=0; i<L; i++){
	A[i] = (double*)malloc(L * sizeof(double));
	B[i] = (double*)malloc(L * sizeof(double));
	C[i] = (double*)malloc(L * sizeof(double));
    }

    for (i=0; i<L; i++){
        PyObject* item1 = PySequence_Fast_GET_ITEM(list1, i);
	for (j = 0; j < L; j++){
	    res1 = PyFloat_AsDouble(PySequence_Fast_GET_ITEM(item1, j));
	    A[i][j] = res1;
	}
    }


    for (i = 0; i < L; i++){
        PyObject* item2 = PySequence_Fast_GET_ITEM(list2, i);
	for (j = 0; j < L; j++){
	    res2 = PyFloat_AsDouble(PySequence_Fast_GET_ITEM(item2, j));
	    B[i][j] = res2;
	}
    }


    for(i = 0; i < L; i++)
{
	for(j = 0; j < L; j++)
	C[i][j] = A[i][j] + B[i][j];
}
   


    PyObject *my_list = PyList_New(0);
    for (i = 0; i < L; i++){
	PyObject *new_list = PyList_New(L);
	for (int j = 0; j < L; j++){
	    PyObject *the_object = PyFloat_FromDouble(C[i][j]);
	    PyList_SetItem(new_list, j, the_object);
	}
	
	PyList_Append(my_list, new_list); 
    }



    for (i = 0; i < L;i++){
	free(A[i]);
	free(B[i]);
	free(C[i]);
    }
    free(A);	
    free(B);	
    free(C);
	
    return my_list;
}
static PyObject *matrix_number(PyObject *self, PyObject *args)
{
    PyObject* list;
    int i, j, c, L;
    float res;


    if (!PyArg_ParseTuple(args, "Oi", &list, &c)){
        return NULL;
    }
	L = PyList_GET_SIZE(list);
	
	
    double **A = (double**)malloc(L * sizeof(double*));
    for (i=0; i<L; i++){
	A[i] = (double*)malloc(L * sizeof(double));
	}

    for (i=0; i<L; i++){
        PyObject* item = PySequence_Fast_GET_ITEM(list, i);
	for (j=0; j<L; j++){
	    res = PyFloat_AsDouble(PySequence_Fast_GET_ITEM(item, j));
	    A[i][j] = res;
	}
    }


    for(i=0; i<L; i++)
{
	for(j=0; j<L; j++)
	A[i][j] = A[i][j] * c;
}
   


    PyObject *my_list = PyList_New(0);
    for (i=0; i<L; i++){
	PyObject *new_list = PyList_New(L);
	for (int j=0; j<L; j++){
	    PyObject *the_object = PyFloat_FromDouble(A[i][j]);
	    PyList_SetItem(new_list, j, the_object);
	}
	
	PyList_Append(my_list, new_list); 
    }



    for (i=0;i<L;i++){
	free(A[i]);
    }
    free(A);	
    return my_list;

}
static PyObject *matrix_transpose(PyObject *self, PyObject *args)
{
    PyObject* list;
    int i, j, c, L;
    float res;    

    if (!PyArg_ParseTuple(args, "O", &list))
    {
        return NULL;
    }
	L = PyList_GET_SIZE(list);

	double **A = (double**)malloc(L * sizeof(double*));
    	for (i=0; i<L; i++)
		{
		A[i] = (double*)malloc(L * sizeof(double));
		}

    for (i=0; i<L; i++){
        PyObject* item = PySequence_Fast_GET_ITEM(list, i);
	for (j=0; j<L; j++){
	    res = PyFloat_AsDouble(PySequence_Fast_GET_ITEM(item, j));
	    A[i][j] = res;
			   }
    		       }

	double **B = (double**)malloc(L * sizeof(double*));
    	for (i=0; i<L; i++)
		{
		B[i] = (double*)malloc(L * sizeof(double));
		}

    for(i = 0; i < L; i++)
{
	for(j = 0; j < L; j++)
	B[j][i] = A[i][j];
}
 	PyObject *my_list = PyList_New(0);
    	for (i=0; i<L; i++){
		PyObject *new_list = PyList_New(L);
		for (int j=0; j<L; j++)
			{
	   		PyObject *the_object = PyFloat_FromDouble(B[i][j]);
	   		PyList_SetItem(new_list, j, the_object);
			}
	
	PyList_Append(my_list, new_list); 
    			}

 

    for (i=0;i<L;i++){
	free(A[i]);
	free(B[i]);
    }
    free(A);	
    free(B);
   return my_list;

}
static PyObject *Rotation(PyObject *self, PyObject *args)
{
PyObject* list1;
PyObject* list2;
int i, j, L, k, n, m;
double res1, res2, C, S, FD, FME, FWCE, A1;

 if (!PyArg_ParseTuple(args, "OO", &list1, &list2)){
        return NULL;
    }

L = PyList_GET_SIZE(list1);

double **A = (double**)malloc(L * sizeof(double*));
double *X = (double*)malloc(L * sizeof(double*));
    for (i = 0; i < L; i++){
	A[i] = (double*)malloc(L * sizeof(double));
	}

 for (i = 0; i < L; i++){
        PyObject* item1 = PySequence_Fast_GET_ITEM(list1, i);
	for (j = 0; j < L; j++){
	    res1 = PyFloat_AsDouble(PySequence_Fast_GET_ITEM(item1, j));
	    A[i][j] = res1;}
   			 }

	for (i = 0; i < L; i++){
  	PyObject *item2 = PySequence_Fast_GET_ITEM(list2, i);
	res2 = PyFloat_AsDouble(item2);
	X[i] = res2;
    		}

for(i = 2; i < L; i++){
for(k=0;k<i;k++){
   for(n=k+1;n<i;n++){
     FD=(sqrt((A[k][k]*A[k][k])+(A[n][k]*A[n][k])));
     C=A[k][k]/FD;
     S=A[n][k]/FD;
     for(m=0;m<i+1;m++){
       A1=A[k][m];
       FME=A[n][m];
       A[k][m]=C*A1+S*FME;
       A[n][m]=-S*A1+C*FME;
     }
   }
  }
  X[i-1]=A[i-1][i]/A[i-1][i-1];
  for(n=i-2;n>=0;n--){
    FWCE=A[n][i];
    for(m=n+1;m<i;m++){
       FWCE-=A[n][m]*X[m];
    }
    FWCE/=A[n][n];
    X[n]=FWCE;
  }
}

PyObject *my_list = PyList_New(L);
    for (i = 0; i < L; i++)
	PyList_SetItem(my_list, i, PyFloat_FromDouble(X[i]));	
 
for(i = 0; i < L; i++)
free(A[i]);
free(A);
free(X);
   return my_list;
}
static PyObject *Zeydel(PyObject *self, PyObject *args)
{
    PyObject* list1;
    PyObject* list2;
    int i, j, L;
    float maxd, maxdp = 0;
    double res1, res2;
    double ESP;

    if (!PyArg_ParseTuple(args, "OOf", &list1, &list2, &ESP)){
        return NULL;
    }
	L = PyList_GET_SIZE(list1);

    double **A = (double**)malloc(L * sizeof(double*));
    double *B = (double*)malloc(L * sizeof(double*));
    double *d = (double*)malloc(L * sizeof(double*));
    double *X = (double*)malloc(L * sizeof(double*));
    for (i = 0; i < L; i++){
	X[i] = 0;
	d[i] = 0;
	A[i] = (double*)malloc(L * sizeof(double));
	}

    for (i = 0; i < L; i++){
        PyObject* item1 = PySequence_Fast_GET_ITEM(list1, i);
	for (j = 0; j < L; j++){
	    res1 = PyFloat_AsDouble(PySequence_Fast_GET_ITEM(item1, j));
	    A[i][j] = res1;
	}
    }
    for (i = 0; i < L; i++){
  	PyObject *item2 = PySequence_Fast_GET_ITEM(list2, i);
	res2 = PyFloat_AsDouble(item2);
	B[i] = res2;
    }

	do
    {
        for (i = 0; i < L; ++i)
        {
            d[i] = X[i];
            X[i] = B[i];
            for (j = 0; j < L; ++j)
            {
                if (i != j)
                {
                    X[i] = X[i] - A[i][j] * X[j];
                }
            }
            X[i] = X[i] / A[i][i];
            d[i] = fabs(d[i] - X[i]);
        }
        maxd = d[0];
        for (i = 1; i < L; ++i)
        {
            if (d[i]>maxd) maxd = d[i];
        }
        if (maxdp == 0)
        {
            maxdp = maxd;
            continue;
        }
        else
        {
            if (maxdp - maxd<0)
            {
                break;
            }
            else
            {
                maxdp = maxd;
            }
        }
    }
    while (maxd > ESP);

    PyObject *my_list = PyList_New(L);
    for (i = 0; i < L; i++)
	PyList_SET_ITEM(my_list, i, PyFloat_FromDouble(X[i]));	


    for (i = 0; i < L; i++){
	free(A[i]);
    }
    free(A);
    free(B);
    free(d);
    free(X);	
    return my_list;
}
static PyMethodDef ownmod_methods[] = {
     {
        "Rotation", 
        Rotation, 
        METH_VARARGS, 
        "Rotation" 
    },
    {
        "matrix_multi", 
        matrix_mul, 
        METH_VARARGS, 
        "matrix multiplication function" 
    },
    {
	"Zeydel",
	Zeydel,
	METH_VARARGS, 
	"Zeydel"
    },
    {
	"sum_matr",
	sum_matr,
	METH_VARARGS, 
	"matrix sum"
    },
    {
	"matrix_number",
	matrix_number,
	 METH_VARARGS,
	"matrix_number"
    },
    {
	"matrix_transpose",
	matrix_transpose,
	 METH_VARARGS,
	"matrix_transpose"
    },
    { NULL, NULL, 0, NULL }
};

static PyModuleDef simple_module = {
    /* Info about module */
    PyModuleDef_HEAD_INIT,
    "pokoev", // pokoev.__name__
    "pokoev multiplication documentation", // pokoev.__doc__
    -1,
    ownmod_methods, // methods are here
    NULL,NULL,NULL
};

PyMODINIT_FUNC PyInit_pokoev(void)
{
    PyObject* m;
    // creating module object
    m = PyModule_Create(&simple_module);
    if (m == NULL)
        return NULL;

    return m;}