#include <Python.h>
#include "fonctions.h"
using namespace std;
static PyObject* start(PyObject* self, PyObject* args)
{

    IGraphBuilder* pGraph = NULL;
    IMediaControl* pControl = NULL;
    IMediaEvent* pEvent = NULL;
    IMediaSeeking* pSeeking = NULL;
    // Initialize the COM library.
    HRESULT hr = CoInitialize(NULL);
    if (FAILED(hr))
    {
        printf("ERROR - Could not initialize COM library");
        return 0;
    }

    // Create the filter graph manager and query for interfaces.
    hr = CoCreateInstance(CLSID_FilterGraph, NULL, CLSCTX_INPROC_SERVER,
        IID_IGraphBuilder, (void**)&pGraph);
    if (FAILED(hr))
    {
        printf("ERROR - Could not create the Filter Graph Manager.");
        return 0;
    }

    hr = pGraph->QueryInterface(IID_IMediaControl, (void**)&pControl);
    hr = pGraph->QueryInterface(IID_IMediaEvent, (void**)&pEvent);
    hr = pGraph->QueryInterface(IID_IMediaSeeking, (void**)&pSeeking);
    // Build the graph. IMPORTANT: Change this string to a file on your system.

    hr = pGraph->RenderFile(L"C:\\Example.avi", NULL);
    if (SUCCEEDED(hr))
    {
        // Run the graph.
        hr = pControl->Run();
        if (SUCCEEDED(hr))
        {
            //cas video marche et est en cours de lecture
            ToucheEntrée(hr, pGraph, pControl, pEvent, pSeeking);//passer en entrée hr 
            pControl->Release();
            pEvent->Release();
            pGraph->Release();
            CoUninitialize();
            return 0L;
        }
        return NULL;
    }
    else
    {
        cout << "Erreur d'ouverture du fichier video..." << endl;
        pControl->Release();
        pEvent->Release();
        pGraph->Release();
        CoUninitialize();
        return NULL;
    }
    return NULL;
}

static PyMethodDef methods[] = {

    {"start",start,METH_VARARGS,"start"},
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