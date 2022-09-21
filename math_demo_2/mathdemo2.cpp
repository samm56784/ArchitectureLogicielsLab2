#include <Python.h>


static PyObject* random(PyObject* self, PyObject* args)

{

    /* initialize random seed: */

    srand(time(NULL));

    int random = rand() % 10;

    PyObject* python_val = Py_BuildValue("i", random);

    return python_val;

}

static PyMethodDef methods[] = {

    { "random", random, METH_NOARGS,

    "Generate random number betweeen 0-9" },

    { NULL, NULL, 0, NULL }

};
static struct PyModuleDef mathdemo2 =
{
    PyModuleDef_HEAD_INIT,
    "mathdemo2", /* name of module */
    "",          /* module documentation, may be NULL */
    -1,          /* size of per-interpreter state of the module, or -1 if the module keeps state in global variables. */
    methods
};

PyMODINIT_FUNC PyInit_mathdemo2(void)

{

    return PyModule_Create(&mathdemo2);




}