//---------------------------------------------------------------------------
#ifndef Unit_BASE_H
#define Unit_BASE_H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "UrtNetDrv.h"
#include "IniFiles.hpp"
#include <stdio.h>
//---------------------------------------------------------------------------
#define DEFAULT_PORT 8080
#define MAX_BUF_SIZE 65535
#define FILE_BLOCK_SIZE   4096
#define CompanyName_CN   "PMO"
//#define HomePageUrl_C   "http://www.pmo.ac.cn"
#define HomePageUrl_C   "HinOTORI"
#define CompanyName   "HinOTORI"
#define HomePageUrl_E    "http://www.pmo.ac.cn"
#define show_hint(hint) {HintLabel->Caption=(hint);HintLabel->Update();}
#define append_hint(hint) {HintLabel->Caption=HintLabel->Caption+(hint);HintLabel->Update();}
extern bool isEnglish,initial_evaluate,ProgramRunning,confirmClose;
extern TContextPopupMenu *ContextPopupMenu;
int Get_One_Line(char *SendText,int &Offset,char *OutBuf,int OutBufSize,bool AsHex);
int GetLineFromFile(FILE *f,int &Offset,char *OutBuf,int OutBufSize,bool AsHex);
long GetFileSize(String srcfile);
//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------
 