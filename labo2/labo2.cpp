///////
// Auteurs: Samuel Harvey et Simon Dumas
// Date: 6 octobre 2022
// 
// Description: Module python servant à exécuter un programme écrit en c++ servant à effectuer la lecture d'un fichier vidéo. Le programme c++ inclut aussi les fonctionnalités de play/pause (P), avance rapide (A), retour au début (R) et quitter pour fermer l'application (Q).
// Le module python prend en entrée le path d'une vidéo et la lit avec les fonctionnalités de contrôle présentes dans le programme initial écrit en c++.
////////

//labo2.cpp est inspiré du fichier du nom de main.cpp trouvé sur Moodle à la remise du projet précédent, lui même tiré du code trouvé à l'adresse: https://docs.microsoft.com/fr-fr/windows/win32/directshow/how-to-play-a-file
//Le fichier main.cpp avait été modifié lors du premier laboratoire de ce cours et a été réutilisé dans le cadre de ce second laboratoire. Celui-ci a été modifié afin que le code puisse être 
//exécuté dans un module python avec en entrée le path de la vidéo à jouer.
#include "fonctions.h"


static PyObject* start(PyObject* self, PyObject* args)
{
    const char* buffer;
    PyArg_ParseTuple(args,"s", &buffer);
    string buffpath = buffer;
    wstring temp(buffpath.begin(), buffpath.end());
    wstring autre = temp;
    LPCWSTR path = autre.c_str();
    string Message;
    PyObject* val;
    IGraphBuilder* pGraph = NULL;
    IMediaControl* pControl = NULL;
    IMediaEvent* pEvent = NULL;
    IMediaSeeking* pSeeking = NULL;

    // Initialize the COM library.
    HRESULT hr = CoInitialize(NULL);
    if (FAILED(hr))
    {
        printf("ERROR - Could not initialize COM library");
        return NULL;
    }

    // Create the filter graph manager and query for interfaces.
    hr = CoCreateInstance(CLSID_FilterGraph, NULL, CLSCTX_INPROC_SERVER,
        IID_IGraphBuilder, (void**)&pGraph);
    if (FAILED(hr))
    {
        printf("ERROR - Could not create the Filter Graph Manager.");
        Message = "Probleme de creation de l'instance direct show";
        const char* buf3 = Message.c_str();
        val = PyBytes_FromString(buf3);
        return val;
    }

    hr = pGraph->QueryInterface(IID_IMediaControl, (void**)&pControl);
    hr = pGraph->QueryInterface(IID_IMediaEvent, (void**)&pEvent);
    hr = pGraph->QueryInterface(IID_IMediaSeeking, (void**)&pSeeking);

    // Build the graph, path étant le path complet de la vidéo que l'on a reçue en entrée du module start()-> ex: labo2.start("C:\\Example.avi")
    hr = pGraph->RenderFile(path, NULL);
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
            pSeeking->Release();
            CoUninitialize();
            cout << "Methode bien fermee!" << endl;
            Message = "Methode bien fermee!"; 
            const char* buf = Message.c_str();
            val = PyBytes_FromString(buf);
            return val;
        }
        cout << "Probleme de lecture..." << endl;
        Message = "Probleme de lecture...";
        const char* buf2 = Message.c_str();
        val = PyBytes_FromString(buf2);
        return val;
    }
    else
    {
        cout << "Probleme d'ouverture du fichier video..." << endl;
        pControl->Release();
        pEvent->Release();
        pGraph->Release();
        pSeeking->Release();
        CoUninitialize();
        Message = "Probleme d'ouverture du fichier video...";
        const char* buf3 = Message.c_str();
        val = PyBytes_FromString(buf3);
        return val;
    }
}

static PyMethodDef methods[] = {

    {"start",start,METH_VARARGS,"start"},
    { NULL, NULL, 0, NULL }
};

static struct PyModuleDef labo2 =
{
    PyModuleDef_HEAD_INIT,
    "labo2", /* name of module */
    "module servant a faire jouer une video et controler sa lecture",          /* module documentation, may be NULL */
    -1,          /* size of per-interpreter state of the module, or -1 if the module keeps state in global variables. */
    methods
};

PyMODINIT_FUNC PyInit_labo2(void)
{
    return PyModule_Create(&labo2);
}