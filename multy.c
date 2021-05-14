#include <Python.h>
#define N 3

static PyObject *matrix_mul(PyObject *self, PyObject *args) {
    PyObject* list1;
    PyObject* list2;
    int i, j, k;
    double res1, res2;

    double **A = (double**)malloc(N * sizeof(double*));
    double **B = (double**)malloc(N * sizeof(double*));
    double **C = (double**)malloc(N * sizeof(double*));
    for (i=0; i<N; i++){
	A[i] = (double*)malloc(N * sizeof(double));
	B[i] = (double*)malloc(N * sizeof(double));
	C[i] = (double*)malloc(N * sizeof(double));
    }

    if (!PyArg_ParseTuple(args, "OO", &list1, &list2)){
        return NULL;
    }

    for (i=0; i<N; i++){
        PyObject* item1 = PySequence_Fast_GET_ITEM(list1, i);
	for (j=0; j<N; j++){
	    res1 = PyFloat_AsDouble(PySequence_Fast_GET_ITEM(item1, j));
	    A[i][j] = res1;
	}
    }


    for (i=0; i<N; i++){
        PyObject* item2 = PySequence_Fast_GET_ITEM(list2, i);
	for (j=0; j<N; j++){
	    res2 = PyFloat_AsDouble(PySequence_Fast_GET_ITEM(item2, j));
	    B[i][j] = res2;
	}
    }


    for(i=0; i<N; i++){
	for(j=0; j<N; j++){
	    C[i][j] = 0;
	    for(k=0; k<N; k++){
		C[i][j] += A[i][k] * B[k][j];
	    }
	}
    }


    PyObject *my_list = PyList_New(0);
    for (i=0; i<N; i++){
	PyObject *new_list = PyList_New(3);
	for (int j=0; j<N; j++){
	    PyObject *the_object = PyLong_FromSsize_t(C[i][j]);
	    PyList_SetItem(new_list, j, the_object);
	}
	
	PyList_Append(my_list, new_list); 
    }

    return my_list;

    for (i=0;i<N;i++){
	free(A[i]);
	free(B[i]);
	free(C[i]);
    }
    free(A);	
    free(B);	
    free(C);	
}

static PyObject *sum_matr(PyObject *self, PyObject *args)
{
    PyObject* list1;
    PyObject* list2;
    int i, j;
    double res1, res2;

    int **A = (int**)malloc(N * sizeof(int*));
    int **B = (int**)malloc(N * sizeof(int*));
    int **C = (int**)malloc(N * sizeof(int*));
    for (i=0; i<N; i++){
	A[i] = (int*)malloc(N * sizeof(int));
	B[i] = (int*)malloc(N * sizeof(int));
	C[i] = (int*)malloc(N * sizeof(int));
    }

    if (!PyArg_ParseTuple(args, "OO", &list1, &list2)){
        return NULL;
    }

    for (i=0; i<N; i++){
        PyObject* item1 = PySequence_Fast_GET_ITEM(list1, i);
	for (j=0; j<N; j++){
	    res1 = PyFloat_AsDouble(PySequence_Fast_GET_ITEM(item1, j));
	    A[i][j] = res1;
	}
    }


    for (i=0; i<N; i++){
        PyObject* item2 = PySequence_Fast_GET_ITEM(list2, i);
	for (j=0; j<N; j++){
	    res2 = PyFloat_AsDouble(PySequence_Fast_GET_ITEM(item2, j));
	    B[i][j] = res2;
	}
    }


    for(i=0; i<N; i++)
{
	for(j=0; j<N; j++)
	C[i][j] = A[i][j] + B[i][j];
}
   


    PyObject *my_list = PyList_New(0);
    for (i=0; i<N; i++){
	PyObject *new_list = PyList_New(3);
	for (int j=0; j<N; j++){
	    PyObject *the_object = PyLong_FromSsize_t(C[i][j]);
	    PyList_SetItem(new_list, j, the_object);
	}
	
	PyList_Append(my_list, new_list); 
    }

    return my_list;

    for (i=0;i<N;i++){
	free(A[i]);
	free(B[i]);
	free(C[i]);
    }
    free(A);	
    free(B);	
    free(C);	

}

static PyMethodDef ownmod_methods[] = {
    {
        "matrix_multi", // name of fucntion in python interpreter
        matrix_mul, // function C declaration
        METH_VARARGS, // special macros about function arguments
        "matrix multiplication function" // doc for function in python interpreter
    },
    {
	"sum_matr",
	sum_matr,
	METH_VARARGS, 
	"matrix sum"
    },
    { NULL, NULL, 0, NULL }
};

static PyModuleDef simple_module = {
    /* Info about module */
    PyModuleDef_HEAD_INIT,
    "pokoev", // matrixMulti.__name__
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