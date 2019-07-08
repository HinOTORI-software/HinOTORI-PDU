#include <vcl.h>
#include "UnitBase.h"
#pragma link "UrtNetDrv.lib"
bool initial_evaluate=false,ProgramRunning=true,confirmClose=false;
TContextPopupMenu *ContextPopupMenu=NULL;
//---------------------------------------------------------------------------
int Get_One_Line(char *SendText,int &Offset,char *OutBuf,int OutBufSize,bool AsHex)
{ char *DataPtr;
  int line_size=0;
  SendText=SendText+Offset;

  if(!AsHex)
  { DataPtr=SendText;
    while(*DataPtr!='\0' && *DataPtr!='\r' && *DataPtr!='\n' && line_size<FILE_BLOCK_SIZE)
    { DataPtr++;
      line_size++;
    }
    if(*DataPtr=='\r'){line_size++;DataPtr++;}
    if(*DataPtr=='\n')line_size++;

    if(line_size>0)
    { Offset+=line_size;
      Move(SendText,OutBuf,line_size);
      OutBuf[line_size]='\0';
    }
  }
  else
  {  //去掉头部的换行符号
     while(*SendText=='\r' || *SendText=='\n')
     { SendText++;
       Offset++;
     }
     DataPtr=SendText;
     while(*DataPtr!='\0' && *DataPtr!='\r' && *DataPtr!='\n' && line_size<FILE_BLOCK_SIZE*2)
     { DataPtr++;
       line_size++;
     }
     if(line_size>0)
     { Offset+=line_size;
       line_size=hex_to_data(SendText,OutBuf,line_size);
     }
  }
  return line_size;
}

unsigned char tempbuf[FILE_BLOCK_SIZE*4];
int GetLineFromFile(FILE *f,int &Offset,char *OutBuf,int OutBufSize,bool AsHex)
{ int line_size=0;
  fseek(f,Offset,0);
  if(!AsHex)
  { line_size=fread(&OutBuf[0],1,FILE_BLOCK_SIZE,f);
    Offset+=line_size;
    return line_size;
  }
  else
  { char SendCh=fgetc(f);
    bool matched=true;
    int wordcount=0,textoffset=0;

    //去掉头部的换行符号
    while(SendCh=='\r' || SendCh=='\n')
    { SendCh=fgetc(f);
      Offset++;
    }
    textoffset=ftell(f)-1;
    while(SendCh!='\0' && SendCh!='\r' && SendCh!='\n')
    { if(SendCh==32)matched=true;
      else
      { matched=!matched;
      }
      if(!matched)
      { if(wordcount++>FILE_BLOCK_SIZE) break;
      }
      SendCh=fgetc(f);
      line_size++;
      Offset++;
    }
    if(line_size>0)
    { fseek(f,textoffset,0);
      line_size=fread(tempbuf,1,line_size,f);
      tempbuf[line_size]=0;
      line_size=hex_to_data(tempbuf,OutBuf,line_size);
    }
  }
  return line_size;
}
//---------------------------------------------------------------------------
bool IsHexTextFile(String strfilename)
{ char SendBuf[1024];
  FILE *ff=fopen(strfilename.c_str(),"rb");
  int testcount=0,testsize;
  unsigned char ch;
  if(!ff)return false;
  testsize=fread(&SendBuf[0], 1, 1024, ff);
  fclose(ff);
  while(testcount<testsize)
  { ch=SendBuf[testcount++];
    if(ch!=0 && ch!=32 && ch!=0x0d && ch!=0x0a)
    { if(ch<48 || ch>102)
       return false;
      else if((ch>57&&ch<65)||(ch>70&&ch<97))
         return false;
    }
  }

  return true;
}

//---------------------------------------------------------------------------
long GetFileSize(String srcfile)
{ TSearchRec Tp;
  if(FindFirst(srcfile,faAnyFile,Tp)==0)
  { long filesize=Tp.Size;
    FindClose(Tp);
    return filesize;
  }
  else
  { return -1;
  }
}
