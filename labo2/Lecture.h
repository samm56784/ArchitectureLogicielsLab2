#pragma once
#pragma once
#pragma comment(lib,"Strmiids.lib")
#include <dshow.h>
#include <iostream>
#include <Python.h>
#include <conio.h>
using namespace std;
enum state
{
	INITIAL,PLAYING, PAUSED, STOPPED
};

class Lecture
{
public:
	state ?tat;
	IGraphBuilder* pGraph;
	IMediaControl* pControl;
	IMediaEvent* pEvent;
	IMediaSeeking* pSeeking;
	string Message;
	HRESULT hr;
	Lecture();
	PyObject* start(PyObject*, PyObject*);
	void play();
	void pause();
	void fastforward();
	void rewind();
	void quit();
	void  setEndTime();
	REFERENCE_TIME getEndTime();
	~Lecture();

private:
	REFERENCE_TIME rtNow = 0, rtEnd;
};