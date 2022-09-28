#pragma once
#pragma comment(lib,"Strmiids.lib")
#include <dshow.h>
#include <iostream>
#include <Python.h>
#include <conio.h>
using namespace std;
void ToucheEntrée(HRESULT, IGraphBuilder*, IMediaControl*, IMediaEvent*, IMediaSeeking*);