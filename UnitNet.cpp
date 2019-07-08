//---------------------------------------------------------------------------

#include <vcl.h>
#include <iostream.h>
#include <fstream.h>
#pragma hdrstop
#include "UnitNet.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormNet *FormNet;

#define ProjectTitle_C   "HinOTORI Telescope PDU System"
#define ProjectTitle_E   "NetAssistant"

#define ProjectName  "TCP232"
#define ProjectVersion "1.0"
static unsigned char SendBuf[MAX_BUF_SIZE+1];
static int default_port=DEFAULT_PORT;
//---------------------------------------------------------------------------
__fastcall TFormNet::TFormNet(TComponent* Owner)
        : TForm(Owner)
{UpdateConfig(false);
 ReceivedSize=0;
 SendedSize=0;
 Caption=ProjectTitle_C;
 Wnd_cmForm(this,Caption,true);

 Wnd_SetMode(1,1);

 transmitting=false;

 IPEdit_IPAddress=new TcmIPEdit(this);
 IPEdit_IPAddress->Parent=Edit_IPAddess->Parent;
 IPEdit_IPAddress->Left=Edit_IPAddess->Left;
 IPEdit_IPAddress->Top=Edit_IPAddess->Top;
 IPEdit_IPAddress->Height=Edit_IPAddess->Height;
 IPEdit_IPAddress->Width=Edit_IPAddess->Width;
 Edit_IPAddess->Visible=false;
 IPEdit_IPAddress2=new TcmIPEdit(this);
 IPEdit_IPAddress2->Parent=Edit_IPAddess2->Parent;
 IPEdit_IPAddress2->Left=Edit_IPAddess2->Left;
 IPEdit_IPAddress2->Top=Edit_IPAddess2->Top;
 IPEdit_IPAddress2->Height=Edit_IPAddess2->Height;
 IPEdit_IPAddress2->Width=Edit_IPAddess2->Width;
 Edit_IPAddess2->Visible=false;

  ////网络设置设置////////////////////////////
 MySocket=new TcmSocket(this);
 MySocket->OnAccept=MySocketAccept;
 MySocket->OnActiveChanged=MySocketActiveChanged;
 MySocket->OnDiscard=MySocketDiscard;
 MySocket->OnError=MySocketError;
 MySocket->OnReceive=MySocketReceive;

 MySocket->MaxBufSize=MAX_BUF_SIZE;
 IPEdit_IPAddress->IPdata=MySocket->get_ip_data();
 IPEdit_IPAddress2->IPdata=IPEdit_IPAddress->IPdata;

 //ComboBox_Protocol->ItemIndex=1;    ////初始化
 //MySocket->Protocol=cmTcpServer;

 //MemoSend->Text="HinOTORI";
 ComboBox_Protocol->ItemIndex=2;
 MySocket->Protocol=cmTcpClient;
 Edit_PortNUM->Text=IntToStr(default_port);
 Edit_PortNUM2->Text=IntToStr(default_port);

 Edit_IPAddess->Text="192.168.10.3";

 MemoSend->Text=HomePageUrl_C;

 TextRecv->PopupMenu=ContextPopupMenu;
 MemoSend->PopupMenu=ContextPopupMenu;

 Net_SyncButtonState();

 //ifstream readFile("E:\\PDUEquipmentsName.txt");
 /*
 FILE *licFile = fopen("PDUname1.txt", "r");
 if (licFile == NULL)
   {
     Application->MessageBox("打开设备名称文件失败!","Warning",MB_OK|MB_ICONWARNING);
   }
 else
 {
     //String  sLine[8];
      // memset(sLine, 0, 8);
       //while (getline(licFile,sline[0])
       //{
       //;
       //}
     int i;
     String  sLine[8];
     for(i=0;!feof(licFile);i++)
     fscanf(licFile,"%s",sLine[i]);
 }
  fclose(licFile);*/
    /*
  FILE *fp ;
  char a[100];
  if((fp = fopen("PDUname1.txt", "r") )== NULL)
   {
     Application->MessageBox("打开设备名称文件失败!","Warning",MB_OK|MB_ICONWARNING);
   }
  else
   {  int i;
     for(i=0;!feof(fp);i++)
     fscanf(fp,"%s",a[i]);
   }
    fclose(fp);
     */

    char namechar[20];
    String  namestr[32];
	int linenum = 0;

	FILE *fp = fopen("E:\\PDUEquipmentsName.txt", "r");
	if(NULL == fp)
	{
        Application->MessageBox("打开设备名称文件失败!","Warning",MB_OK|MB_ICONWARNING);

	}

    else
    {
	  for(linenum=0;linenum<16;linenum++)
	  {
		//memset(szTest, 0, sizeof(szTest));
		//fgets(szTest, sizeof(szTest) - 1, fp); // 包含了换行符
        //getline(fp,szTest);//读入string
        fgets(namechar,20,fp) ;
        namestr[linenum++]=namechar;

      }
    }
    fclose(fp);
  /*
 CH1ON->Caption=namestr[0]+" ON";;      ////0  4  8  12  16  20  24  28
 CH1OFF->Caption=namestr[0]+" OFF";
 CH2ON->Caption=namestr[2]+" ON";
 CH2OFF->Caption=namestr[2]+" OFF";
 CH3ON->Caption=namestr[4]+" ON";
 CH3OFF->Caption=namestr[4]+" OFF";
 CH4ON->Caption=namestr[6]+" ON";
 CH4OFF->Caption=namestr[6]+" OFF";
 CH5ON->Caption=namestr[8]+" ON";
 CH5OFF->Caption=namestr[8]+" OFF";
 CH6ON->Caption=namestr[10]+" ON";
 CH6OFF->Caption=namestr[10]+" OFF";
 CH7ON->Caption=namestr[12]+" ON";
 CH7OFF->Caption=namestr[12]+" OFF";
 CH8ON->Caption=namestr[14]+" ON";
 CH8OFF->Caption=namestr[14]+" OFF";
  */
 Read1->Caption= namestr[0];
 Read2->Caption= namestr[2];
 Read3->Caption= namestr[4];
 Read4->Caption= namestr[6];
 Read5->Caption= namestr[8];
 Read6->Caption= namestr[10];
 Read7->Caption= namestr[12];
 Read8->Caption= namestr[14];

 GroupCH1->Caption= namestr[0];
 GroupCH2->Caption= namestr[2];
 GroupCH3->Caption= namestr[4];
 GroupCH4->Caption= namestr[6];
 GroupCH5->Caption= namestr[8];
 GroupCH6->Caption= namestr[10];
 GroupCH7->Caption= namestr[12];
 GroupCH8->Caption= namestr[14];












 Caption=ProjectTitle_C;
 Application->Title=Caption;
 Application->OnHint=OnHint;


 TrayIcon=new TcmTrayIcon(this);
 TrayIcon->RestoreOnDBCLick=true;
 TrayIcon->PopupMenu=PopupMenu1;
 TrayIcon->Visible=true;
 TrayIcon->Hint=this->Caption;

 

 ContextPopupMenu=new TContextPopupMenu(this);
}
//---------------------------------------------------------------------------
void __fastcall TFormNet::OnHint(TObject *Sender)
{ String strHint;
  if(Application->Hint.Length()>0)
  { strHint=Application->Hint;
  }
  else
  { strHint="Ready!";
  }
  HintLabel->Caption=strHint;
  HintLabel->Update();
}
//---------------------------------------------------------------------------
void TFormNet::UpdateConfig(bool bWriteOrRead)
{ String SectionName="NetSettings",configfile=ChangeFileExt(Application->ExeName,".cfg");
  TIniFile *MyIniFile=new TIniFile(configfile);
  if(bWriteOrRead)
  { SectionName="Options";
    MyIniFile->WriteInteger(SectionName,"LocalPort",MySocket->LocalPort);
    MyIniFile->WriteBool(SectionName,"ReceiveShowHex",CheckBox_ReceiveShowHex->Checked);
    MyIniFile->WriteBool(SectionName,"ReceiveAutoReturn",CheckBox_ReceiveAutoReturn->Checked);
    if(isNumeric(Edit_SendInterval->Text.c_str()))SendInterval=StrToInt(Edit_SendInterval->Text);
    MyIniFile->WriteInteger(SectionName,"SendInterval",SendInterval);
    if(isNumeric(Edit_PortNUM->Text.c_str()))default_port=StrToInt(Edit_PortNUM->Text);
    MyIniFile->WriteInteger(SectionName,"LocalPort",default_port);
    MyIniFile->WriteInteger(SectionName,"ChecksumMode",ChecksumMode);
    MyIniFile->WriteInteger(SectionName,"FixedCheckSum",FixedCheckSum); 
  }
  else
  { SectionName="Options";
    CheckBox_ReceiveShowHex->Checked=MyIniFile->ReadBool(SectionName,"ReceiveShowHex",true);
    CheckBox_ReceiveAutoReturn->Checked=MyIniFile->ReadBool(SectionName,"ReceiveAutoReturn",false);
    SendInterval=MyIniFile->ReadInteger(SectionName,"SendInterval",1000);
    Edit_SendInterval->Text=IntToStr(SendInterval);
    default_port=MyIniFile->ReadInteger(SectionName,"LocalPort",DEFAULT_PORT);
    ChecksumMode=MyIniFile->ReadInteger(SectionName,"ChecksumMode",0); \
    FixedCheckSum=MyIniFile->ReadInteger(SectionName,"FixedCheckSum",0x0D);
  }
  delete MyIniFile;
}
//---------------------------------------------------------------------------
String TFormNet::ConnectBtnCaption(void)
{ if(MySocket->Active)
  { return "Disconnect ";
  }
  else if(MySocket->Protocol==cmTcpServer)
  { return "Begin to monitor ";
  }
  else
  { return "Connecting ";
  }
}
//---------------------------------------------------------------------------
void TFormNet::Net_SyncButtonState(void)
{ if(MySocket->Active)
  { cmBtn_NetConnect->Glyph=NULL;
    ImageList1->GetBitmap(1,cmBtn_NetConnect->Glyph);
    cmBtn_NetConnect->Caption=ConnectBtnCaption();

    if(MySocket->Protocol==cmUDP)
    { Label_IP2->Caption="Destination Host:";
      Label_portNUM2->Caption="Port:";
      Label_portNUM2->Visible=true;
      IPEdit_IPAddress2->Visible=true;
      IPEdit_IPAddress2->Enabled=true;
      Edit_PortNUM2->Visible=true;
      Edit_PortNUM2->Enabled=true;
      ComboBox_Connections->Visible=false;
    }
    else if(MySocket->Protocol==cmTcpServer)
    { Label_IP2->Caption="Connecting Object:";
      IPEdit_IPAddress2->Visible=false;
      Label_portNUM2->Visible=false;
      Edit_PortNUM2->Visible=false;
      ComboBox_Connections->Visible=true;
      ComboBox_Connections->Items->Text=" All Connections";
      ComboBox_Connections->ItemIndex=0;
    }
    else if(MySocket->Protocol==cmTcpClient)
    { Label_IP2->Caption="Local host:";
      Label_portNUM2->Caption="Port:";
      IPEdit_IPAddress2->Visible=true;
      IPEdit_IPAddress2->IP=MySocket->LocalHost;
      IPEdit_IPAddress2->Enabled=false;
      Label_portNUM2->Visible=true;
      Edit_PortNUM2->Visible=true;
      Edit_PortNUM2->Text=IntToStr(MySocket->LocalPort);
      Edit_PortNUM2->Enabled=false;
      ComboBox_Connections->Visible=false;
    }

  }
  else
  { cmBtn_NetConnect->Glyph=NULL;
    ImageList1->GetBitmap(0,cmBtn_NetConnect->Glyph);
    cmBtn_NetConnect->Caption=ConnectBtnCaption();
  }

  ComboBox_Protocol->Enabled=!MySocket->Active;
  IPEdit_IPAddress->Enabled=!MySocket->Active;
  Edit_PortNUM->Enabled=!MySocket->Active;
  PanelToolBar->Visible=MySocket->Active;

  Label_Protocol->Caption="（1）Protocol Type";
  if(MySocket->Protocol==cmUDP || MySocket->Protocol==cmTcpServer)
  { Label_IPAddress->Caption="（2）Local IP Address";
    Label_PortNum->Caption="（3）Local Port Number";
  }
  else if(MySocket->Protocol==cmTcpClient)
  { Label_IPAddress->Caption="（2）Server IP Address";
    Label_PortNum->Caption="（3）Server Port Number";
  }

}
//---------------------------------------------------------------------------
void __fastcall TFormNet::Btn_SendClick(TObject *Sender)
{

   CheckBox_SendAsHex->Checked=True;
   MemoSend->Text="11 05 00 00 FF 00 8E AA" ;

  int DataSize=0,Offset=0,lastOffset=0,recycleCount=0;
  bool SendOK=false;
  char *DataPtr=NULL;
  transmitting=true;
  MemoSend->Enabled=false;
  Edit_SendInterval->Enabled=false;
  ComboBox_Protocol->Enabled=false;
  IPEdit_IPAddress->Enabled=false;
  Edit_PortNUM->Enabled=false;
  CheckBox_FileInput->Enabled=false;
  cmBtn_NetConnect->Enabled=false;


  if(isNumeric(Edit_SendInterval->Text.c_str()))SendInterval=StrToInt(Edit_SendInterval->Text);
  else Edit_SendInterval->Text=IntToStr(SendInterval);
///////////////////////////////////////////////
  while(transmitting && ProgramRunning)
  {
    lastOffset=Offset;
    DataSize=Get_One_Line(MemoSend->Text.c_str(),Offset,&SendBuf[0],MAX_BUF_SIZE,CheckBox_SendAsHex->Checked);
    if(DataSize<1)
    { if(CheckBox_SendRecycled->Checked)
      { Offset=0;
        lastOffset=0;
        DataSize=Get_One_Line(MemoSend->Text.c_str(),Offset,&SendBuf[0],MAX_BUF_SIZE,CheckBox_SendAsHex->Checked);
        if(DataSize<1) break;
      }else break;
    }

    if(recycleCount++)MyAsyncSleep(SendInterval);

    show_hint("Senting data now...");
    if(CheckBox_SendAutoChecksum->Checked)
    { if(ChecksumMode==2)
      { SendBuf[DataSize++]=FixedCheckSum;
      }
      else
      { DataSize++;
        set_checksum(&SendBuf[0],DataSize,ChecksumMode);
      }
    }
    DataPtr=&SendBuf[0];
    if(MySocket->Protocol==cmTcpClient)
    { SendOK=MySocket->Send(DataPtr,DataSize);
    }
    else if(MySocket->Protocol==cmUDP)
    { if(!isNumeric(Edit_PortNUM2->Text.c_str()))
      { Application->MessageBox("Invalid Target Port Numner !","Warning",MB_OK+MB_ICONSTOP);
        break;
      }
      SendOK=MySocket->SendTo(IPEdit_IPAddress2->IPdata,str_to_int(Edit_PortNUM2->Text.c_str()),DataPtr,DataSize);
    }
    else if (MySocket->Protocol==cmTcpServer)
    { if(ComboBox_Connections->Items->Count<=1)
      { Application->MessageBox("No Connecting Object now!","Warning",MB_OK|MB_ICONWARNING);
        break;
      }
      else if(ComboBox_Connections->ItemIndex==0)
      { for(MySocket->Connections->node=MySocket->Connections->first;MySocket->Connections->node;MySocket->Connections->node=MySocket->Connections->node->next)
        { SendOK=MySocket->SendTo(MySocket->Connections->node->socket,DataPtr,DataSize);
        }
      }
      else
      { MySocket->Connections->node=MySocket->Connections->first;
        for(int i=1;i<ComboBox_Connections->ItemIndex;i++)
        { if(MySocket->Connections->node)MySocket->Connections->node=MySocket->Connections->node->next;
        }
        if(MySocket->Connections->node)
        { SendOK=MySocket->SendTo(MySocket->Connections->node->socket,DataPtr,DataSize);
        }
        else
        { Application->MessageBox("Invalid Connecting Object!","Warning",MB_OK|MB_ICONWARNING);
          //ComboBox_Connections->Items->Delete(ComboBox_Connections->ItemIndex);
          //ComboBox_Connections->ItemIndex=0;
          //不能这样简单的删除,需要同时删除内部结点
          break;
        }
      }
    }


    SendedSize+=DataSize;
    if(SendOK) {show_hint(String("Sent Successfully")+get_summary(MemoSend->Text.c_str(),lastOffset,Offset));}
    else {show_hint("Fail to send!"); break;}
    StaticTextSend->Caption=String("Send : ")+SendedSize;
     Application->ProcessMessages();
  }
///////////////////////////////////////
  Edit_SendInterval->Enabled=true;
  ComboBox_Protocol->Enabled=true;
  IPEdit_IPAddress->Enabled=true;
  Edit_PortNUM->Enabled=true;
  cmBtn_NetConnect->Enabled=true;
  MemoSend->Enabled=true;
  CheckBox_FileInput->Enabled=true;
  transmitting=false;
  if(CheckBox_ClearAfterSend->Checked)MemoSend->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TFormNet::Net_BtnClick_SendFromFile(TObject *Sender)
{
  if(transmitting)
  { transmitting=false;
    return;
  }
  if(!MySocket->Active)
  { char *msgError="Network not connected yet! \n\n Fail to send！";
    Application->MessageBox(msgError,"Warning",MB_OK | MB_ICONSTOP);
    return;
  }
  int DataSize,Offset=0,recycleCount=0;
  bool SendOK=false;
  char *DataPtr=NULL;

  FILE *sf=fopen(SendFileName.c_str(),"rb");
  if(!sf)
  { Application->MessageBox("Can not open data file！","Warning",MB_OK | MB_ICONSTOP);
    return;
  }

  transmitting=true;
  MemoSend->Enabled=false;
  Edit_SendInterval->Enabled=false;
  ComboBox_Protocol->Enabled=false;
  IPEdit_IPAddress->Enabled=false;
  Edit_PortNUM->Enabled=false;
  cmBtn_NetConnect->Enabled=false;
  CheckBox_FileInput->Enabled=false;


  show_hint("Sending date now...");

  if(isNumeric(Edit_SendInterval->Text.c_str()))SendInterval=StrToInt(Edit_SendInterval->Text);
  else Edit_SendInterval->Text=IntToStr(SendInterval);
///////////////////////////////////////////////  
  while(transmitting && ProgramRunning)
  {
    DataSize=GetLineFromFile(sf,Offset,&SendBuf[0],MAX_BUF_SIZE,CheckBox_SendAsHex->Checked);
    if(DataSize<1)
    { if(CheckBox_SendRecycled->Checked)
      { Offset=0;
        DataSize=GetLineFromFile(sf,Offset,&SendBuf[0],MAX_BUF_SIZE,CheckBox_SendAsHex->Checked);
        if(DataSize<1) break;
      }else break;
    }

    if(recycleCount++)MyAsyncSleep(SendInterval);

    if(CheckBox_SendAutoChecksum->Checked)
    { if(ChecksumMode==2)
      { SendBuf[DataSize++]=FixedCheckSum;
      }
      else
      { DataSize++;
        set_checksum(&SendBuf[0],DataSize,ChecksumMode);
      }
    }
    DataPtr=&SendBuf[0];
    if(MySocket->Protocol==cmTcpClient)
    { SendOK=MySocket->Send(DataPtr,DataSize);
    }
    else if(MySocket->Protocol==cmUDP)
    { if(!isNumeric(Edit_PortNUM2->Text.c_str()))
      { Application->MessageBox("Invalid Object Port Number!","Warning",MB_OK+MB_ICONSTOP);
        break;
      }
      SendOK=MySocket->SendTo(IPEdit_IPAddress2->IPdata,str_to_int(Edit_PortNUM2->Text.c_str()),DataPtr,DataSize);
    }
    else if (MySocket->Protocol==cmTcpServer)
    { if(ComboBox_Connections->Items->Count<=1)
      { Application->MessageBox("No Connecting Object!","Warning",MB_OK|MB_ICONWARNING);
        break;
      }
      else if(ComboBox_Connections->ItemIndex==0)
      { for(MySocket->Connections->node=MySocket->Connections->first;MySocket->Connections->node;MySocket->Connections->node=MySocket->Connections->node->next)
        { SendOK=MySocket->SendTo(MySocket->Connections->node->socket,DataPtr,DataSize);
        }
      }
      else
      { MySocket->Connections->node=MySocket->Connections->first;
        for(int i=1;i<ComboBox_Connections->ItemIndex;i++)
        { if(MySocket->Connections->node)MySocket->Connections->node=MySocket->Connections->node->next;
        }
        if(MySocket->Connections->node)
        { SendOK=MySocket->SendTo(MySocket->Connections->node->socket,DataPtr,DataSize);
        }
        else
        { Application->MessageBox("Invalid connecting object!","Warning",MB_OK|MB_ICONWARNING);
          ComboBox_Connections->Items->Delete(ComboBox_Connections->ItemIndex);
          ComboBox_Connections->ItemIndex=0;
          break;
        }
      }
    }

    SendedSize+=DataSize;
    if(!SendOK) {show_hint("Fail to Send!"); break;}
    StaticTextSend->Caption=String("Send : ")+SendedSize;
    Application->ProcessMessages();
  }
///////////////////////////////////////
  Edit_SendInterval->Enabled=true;
  ComboBox_Protocol->Enabled=true;
  IPEdit_IPAddress->Enabled=true;
  Edit_PortNUM->Enabled=true;
  cmBtn_NetConnect->Enabled=true;
  MemoSend->Enabled=true;
  CheckBox_FileInput->Enabled=true;
  transmitting=false;
  fclose(sf);
  show_hint("sending finished!");
}


//---------------------------------------------------------------------------
void __fastcall TFormNet::cmBtn_NetConnectClick(TObject *Sender)
{ if(MySocket->Active)
  { MySocket->Active=false;
  }
  else
  { if(!isNumeric(Edit_PortNUM->Text.c_str()))
    { Application->MessageBox("Invalid Port Number!","Warning",MB_OK+MB_ICONSTOP);
      return;
    }
    if(MySocket->Protocol==cmUDP || MySocket->Protocol==cmTcpServer)
    { MySocket->LocalHost=IPEdit_IPAddress->IP;
      MySocket->LocalPort=StrToInt(Edit_PortNUM->Text);
      MySocket->RemoteHost=NULL;
      MySocket->RemotePort=NULL;
    }
    else if(MySocket->Protocol==cmTcpClient)
    { MySocket->LocalHost=NULL;
      MySocket->LocalPort=NULL;
      IPEdit_IPAddress->IP="192.168.10.3";  ////初始化IP地址
      MySocket->RemoteHost=IPEdit_IPAddress->IP;
      MySocket->RemotePort=StrToInt(Edit_PortNUM->Text);
    } else return;
    MySocket->Active=true;
  }

}
//---------------------------------------------------------------------------
void __fastcall TFormNet::MySocketAccept(TObject *sender, int socket, DWORD IP, WORD Port)
{ String peer=MySocket->HostIP(IP)+":"+Port ;
  ComboBox_Connections->Items->Add(MySocket->HostIP(IP)+":"+Port);
  ComboBox_Connections->ItemIndex=1;
}
//---------------------------------------------------------------------------
void __fastcall TFormNet::MySocketActiveChanged(TObject *Sender)
{ Net_SyncButtonState();
}
//---------------------------------------------------------------------------
void __fastcall TFormNet::MySocketDiscard(TObject *sender, int socket,DWORD IP, WORD Port)
{ String ObjItem=MySocket->HostIP(IP)+":"+Port;
  for(int i=0;i<ComboBox_Connections->Items->Count;i++)
  { if(ComboBox_Connections->Items->Strings[i]==ObjItem)
    { if(i==ComboBox_Connections->ItemIndex)ComboBox_Connections->ItemIndex=0;
      ComboBox_Connections->Items->Delete(i);
      return;
    }
  }
}
//---------------------------------------------------------------------------
void __fastcall TFormNet::MySocketError(TObject *sender, int ErroCode,char *ErrorMsg)
{ show_hint(ErrorMsg);
  //TextRecv->Lines->Append(ErrorMsg);
}
//---------------------------------------------------------------------------
DWORD Last_RemoteIP;
WORD Last_RemotePort;
void __fastcall TFormNet::MySocketReceive(TObject *Sender, int PeerSocket,WORD PeerPort, DWORD PeerIP, char *pBuf, int DataLen)
{ ReceivedSize+=DataLen;
  StaticTextRecv->Caption=String("Receive : ")+ReceivedSize;
  if(CheckBox_PauseReceive->Checked)return;

  if(CheckBox_FileOutput->Checked)
  { FILE *ff=fopen(RecvFileName.c_str(),"a+b");
    if(ff)
    { if(Last_RemoteIP!=PeerIP || Last_RemotePort!=PeerPort)
      { String recvHint;
        Last_RemoteIP=PeerIP;
        Last_RemotePort=PeerPort;
        recvHint="【Receive from "+MySocket->HostIP(PeerIP)+" : "+PeerPort+"】：\r\n";
        fprintf(ff,recvHint.c_str());
      }

      if(CheckBox_ReceiveShowHex->Checked)
      { DataLen=data_to_hex((char *)pBuf,DataLen,&SendBuf[0],MAX_BUF_SIZE);
        pBuf=SendBuf;
      }

      fwrite(pBuf,DataLen,1,ff);
      if(CheckBox_ReceiveAutoReturn->Checked) fprintf(ff,"\r\n");
      fclose(ff);
    }
  }
  else
  { if(Last_RemoteIP!=PeerIP || Last_RemotePort!=PeerPort)
    { Last_RemoteIP=PeerIP;
      Last_RemotePort=PeerPort;
      //TextRecv->Lines->Append("【Receive from "+MySocket->HostIP(PeerIP)+" : "+PeerPort+"】：\r\n");
      TextRecv->Lines->Add("【Receive from "+MySocket->HostIP(PeerIP)+" : "+PeerPort+"】：\r\n");
    }

    if(CheckBox_ReceiveShowHex->Checked)
    { data_to_hex(pBuf,DataLen,&SendBuf[0],MAX_BUF_SIZE);
      pBuf=SendBuf;

    }
   /* else
    {  format_text(pBuf,DataLen,&SendBuf[0],MAX_BUF_SIZE);
       pBuf=SendBuf;
    } */
    int last_line=TextRecv->Lines->Count-1;
    if(last_line<0) TextRecv->Lines->Add(pBuf);
    else

      TextRecv->Lines->Strings[last_line]=TextRecv->Lines->Strings[last_line]+pBuf;
    /////判断返回的状态！ 返回值！


    //if(TextRecv->Lines->Strings[last_line]=="11 05 00 00 FF 00 8E AA" ) (NOW1->Text="ON"; ) // 可以判断
    //if(TextRecv->Lines->Strings[last_line]=="11 01 01 01 94 88" )       // 不能判断


      if(TextRecv->Lines->Strings[last_line]=="11 05 00 00 FF 00 8E AA" ) {NOW1->Text="ON"; } // 可以判断
      if(TextRecv->Lines->Strings[last_line]=="11 05 00 00 00 00 CF 5A" ) {NOW1->Text="OFF"; }

      if(TextRecv->Lines->Strings[last_line]=="11 05 00 01 FF 00 DF 6A" ) {NOW2->Text="ON"; }
      if(TextRecv->Lines->Strings[last_line]=="11 05 00 01 00 00 9E 9A" ) {NOW2->Text="OFF"; }

      if(TextRecv->Lines->Strings[last_line]=="11 05 00 02 FF 00 2F 6A" ) {NOW3->Text="ON"; }
      if(TextRecv->Lines->Strings[last_line]=="11 05 00 02 00 00 6E 9A" ) {NOW3->Text="OFF"; }

      if(TextRecv->Lines->Strings[last_line]=="11 05 00 03 FF 00 7E AA" ) {NOW4->Text="ON"; }
      if(TextRecv->Lines->Strings[last_line]=="11 05 00 03 00 00 3F 5A" ) {NOW4->Text="OFF"; }

      if(TextRecv->Lines->Strings[last_line]=="11 05 00 04 FF 00 CF 6B" ) {NOW5->Text="ON"; }
      if(TextRecv->Lines->Strings[last_line]=="11 05 00 04 00 00 8E 9B" ) {NOW5->Text="OFF"; }

      if(TextRecv->Lines->Strings[last_line]=="11 05 00 05 FF 00 9E AB" ) {NOW6->Text="ON"; }
      if(TextRecv->Lines->Strings[last_line]=="11 05 00 05 00 00 DF 5B" ) {NOW6->Text="OFF"; }

      if(TextRecv->Lines->Strings[last_line]=="11 05 00 06 FF 00 6E AB" ) {NOW7->Text="ON"; }
      if(TextRecv->Lines->Strings[last_line]=="11 05 00 06 00 00 2F 5B" ) {NOW7->Text="OFF"; }

      if(TextRecv->Lines->Strings[last_line]=="11 05 00 07 FF 00 3F 6B" ) {NOW8->Text="ON"; }
      if(TextRecv->Lines->Strings[last_line]=="11 05 00 07 00 00 7E 9B" ) {NOW8->Text="OFF"; }

      if(TextRecv->Lines->Strings[last_line]=="11 01 01 01 94 88" )
         {

              //if (MemoSend->Text=="11 01 00 00 00 01 FF 5A") {Application->MessageBox("通道1!","Warning",MB_OK|MB_ICONWARNING);}
              if (MemoSend->Text=="11 01 00 00 00 01 FF 5A") {RD1->Text="   ON";RD1->Color=clGreen;}
              if (MemoSend->Text=="11 01 00 01 00 01 AE 9A") {RD2->Text="   ON";RD2->Color=clGreen;}
              if (MemoSend->Text=="11 01 00 02 00 01 5E 9A") {RD3->Text="   ON";RD3->Color=clGreen;}
              if (MemoSend->Text=="11 01 00 03 00 01 0F 5A") {RD4->Text="   ON";RD4->Color=clGreen;}
              if (MemoSend->Text=="11 01 00 04 00 01 BE 9B") {RD5->Text="   ON";RD5->Color=clGreen;}
              if (MemoSend->Text=="11 01 00 05 00 01 EF 5B") {RD6->Text="   ON";RD6->Color=clGreen;}
              if (MemoSend->Text=="11 01 00 06 00 01 1F 5B") {RD7->Text="   ON";RD7->Color=clGreen;}
              if (MemoSend->Text=="11 01 00 07 00 01 4E 9B") {RD8->Text="   ON";RD8->Color=clGreen;}
         }


      if(TextRecv->Lines->Strings[last_line]=="11 01 01 00 55 48" )
         {

              if (MemoSend->Text=="11 01 00 00 00 01 FF 5A") {RD1->Text="  OFF";RD1->Color=clRed;}
              if (MemoSend->Text=="11 01 00 01 00 01 AE 9A") {RD2->Text="  OFF";RD2->Color=clRed;}
              if (MemoSend->Text=="11 01 00 02 00 01 5E 9A") {RD3->Text="  OFF";RD3->Color=clRed;}
              if (MemoSend->Text=="11 01 00 03 00 01 0F 5A") {RD4->Text="  OFF";RD4->Color=clRed;}
              if (MemoSend->Text=="11 01 00 04 00 01 BE 9B") {RD5->Text="  OFF";RD5->Color=clRed;}
              if (MemoSend->Text=="11 01 00 05 00 01 EF 5B") {RD6->Text="  OFF";RD6->Color=clRed;}
              if (MemoSend->Text=="11 01 00 06 00 01 1F 5B") {RD7->Text="  OFF";RD7->Color=clRed;}
              if (MemoSend->Text=="11 01 00 07 00 01 4E 9B") {RD8->Text="  OFF";RD8->Color=clRed;}
         }


    if(CheckBox_ReceiveAutoReturn->Checked)TextRecv->Lines->Append("");
  }
}
//------------------------------------------------------------------------------
void TFormNet::MyAsyncSleep(int MSec)
{ TDateTime duetime=Now() + (double)MSec / MSecsPerDay;
  do Application->ProcessMessages();
  while(transmitting && ProgramRunning && Now()<duetime);
}
//---------------------------------------------------------------------------
String TFormNet::get_summary(char *SendText,int OffsetBegin,int OffsetEnd)
{ if (!SendText)return "no data";
  String summary=String(SendText+OffsetBegin);
  int size=OffsetEnd-OffsetBegin;
  int max_size=HintLabel->Width / HintLabel->Font->Size;
  if(size>max_size)
  { summary.SetLength(max_size);
    summary=summary+"...";
  }
  else
  { summary.SetLength(size);
    summary=summary+"";
  }
  return summary;
}
//---------------------------------------------------------------------------
void __fastcall TFormNet::ComboBox_ProtocolChange(TObject *Sender)
{ switch (((TComboBox *)Sender)->ItemIndex)
  {case 0: MySocket->Protocol=cmUDP;break;
   case 1: MySocket->Protocol=cmTcpServer;break;
   case 2: MySocket->Protocol=cmTcpClient;break;
   default:return;
  }
  Net_SyncButtonState();
}
//---------------------------------------------------------------------------
void __fastcall TFormNet::Btn_SendMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{ TPanel *colorBtn=(TPanel *)Sender;
  colorBtn->BevelInner=bvNone;
  colorBtn->BevelOuter=bvLowered;
}
//---------------------------------------------------------------------------
void __fastcall TFormNet::Btn_SendMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{ TPanel *colorBtn=(TPanel *)Sender;
  colorBtn->BevelInner=bvRaised;
  colorBtn->BevelOuter=bvRaised;
}
//---------------------------------------------------------------------------
void __fastcall TFormNet::CheckBox_FileOutputClick(TObject *Sender)
{ if( ((TCheckBox *)Sender)->Checked )
  {  bool flag=false;
    TSaveDialog *dlg=new TSaveDialog(this);
    dlg->Title  = "Receive area content save as...";
    dlg->Filter = "Text files|*.txt|Data files|*.dat|All files|*.*";
    if(dlg->Execute())
    { RecvFileName=dlg->FileName;
      String NameExt=ExtractFileExt(RecvFileName);
      if(NameExt.IsEmpty())
      { if(dlg->FilterIndex==1)RecvFileName=RecvFileName+".txt";
        else if(dlg->FilterIndex==2)RecvFileName=RecvFileName+".bin";
      }
      if(!FileExists(RecvFileName))
      { fclose(fopen(RecvFileName.c_str(),"w"));\
        flag=true;
      }
      else if(GetFileSize(RecvFileName)>0)
      { //char *msgWarning="该文件数据已经存在，是否覆盖原有内容或者追加数据？";
        char *msgWarning="The file already existed, Overwrite the current one or add date ";
        Wnd_SetUserButton("","Overwrite","Superaddition","Cancel");
        switch(Wnd_MessageDlg(msgWarning,"Warning",MB_USERBUTTON | MB_ICONSTOP))
        { case 1:/*追加数据*/ flag=true;break;
          case 2:fclose(fopen(RecvFileName.c_str(),"w"));flag=true;break;
        }
      }
      else flag=true;
    }
    dlg->Free();
    if(flag)
    { //TextRecv->Text=(String)("接收转向至文件：\n")+RecvFileName+" ...";
      TextRecv->Text=(String)("Let the file receive data：\n")+RecvFileName+" ...";
      TextRecv->ReadOnly=true;
      TextRecv->Color=(TColor)0xdfdfdf;
    }
    else
    {  ((TCheckBox *)Sender)->Checked=false;
    }
  }
  else
  { TextRecv->Clear();
    TextRecv->ReadOnly=false;
    TextRecv->Color=clWhite;
  }

}
//---------------------------------------------------------------------------

void __fastcall TFormNet::CheckBox_ReceiveAutoReturnClick(TObject *Sender)
{  //如果自动换行，先结束上一行
  if( ((TCheckBox *)Sender)->Checked)
  { int size=TextRecv->Text.Length();
    if (size>0 && TextRecv->Text[size]!='\n')
    TextRecv->Lines->Add("");
  }
}
//---------------------------------------------------------------------------

void __fastcall TFormNet::CheckBox_PauseReceiveClick(TObject *Sender)
{ if( ((TCheckBox *)Sender)->Checked )
  { TextRecv->Color=(TColor)0x8f8f8f;
    TextRecv->Cursor=crNo;
  }
  else
  { TextRecv->Color=clWhite;
    TextRecv->Cursor=crDefault;
  }
}
//---------------------------------------------------------------------------

void __fastcall TFormNet::CheckBox_FileInputClick(TObject *Sender)
{ if( ((TCheckBox *)Sender)->Checked )
  { TOpenDialog *dlg=new TOpenDialog(this);
    dlg->Filter = "Text files|*.txt|Data files|*.dat|All files|*.*";
    if(dlg->Execute())
    { SendFileName=dlg->FileName;
      dlg->Free();
    }
    else
    { ((TCheckBox *)Sender)->Checked=false;
      dlg->Free();
      return;
    }

    FILE *f=fopen(SendFileName.c_str(),"rb");
    if(f)
    { //MemoSend->Text=(String)("启用外部文件数据源：\n")+SendFileName+" ...";
      MemoSend->Text=(String)("use external file data source：\n")+SendFileName+" ...";
      MemoSend->ReadOnly=true;
      MemoSend->Color=(TColor)0xdfdfdf;
    }
    else
    { ((TCheckBox *)Sender)->Checked=false;
      ShowMessage("Can not open file!");
      return;
    }
  }
  else
  { MemoSend->Color=clWhite;
    MemoSend->Clear();
    MemoSend->ReadOnly=false;
  }
}
//---------------------------------------------------------------------------
void __fastcall TFormNet::EditNumKeyPress(TObject *Sender,char &Key)
{ if (Key>1&&Key<3 || (Key>3 && Key<8) || (Key>8 && Key<22)|| (Key>22 && Key<'0') || Key>'9')
    Key=0;
}
//---------------------------------------------------------------------------

void __fastcall TFormNet::Label_SaveDataClick(TObject *Sender)
{  if(CheckBox_FileOutput->Checked)
  { //char *msgError="接收转向至文件时无法执行该操作！";
    char *msgError="Can not perform the operation when transfering the receiving data to file ";
    Application->MessageBox(msgError,"Warning",MB_ICONWARNING | MB_OK);
    return;
  }
  else
  { TSaveDialog *dlg=new TSaveDialog(this);
    //dlg->Title  = "接收区显示内容另存为...";
    dlg->Title  = "receiving area content save as ...";
    dlg->Filter = "Text files|*.txt|Data files|*.dat|All files|*.*";
    if(dlg->Execute())
    { String FileName=dlg->FileName;
      String NameExt=ExtractFileExt(FileName);
      if(NameExt.IsEmpty())
      { if(dlg->FilterIndex==1)FileName=FileName+".txt";
        else if(dlg->FilterIndex==2)FileName=FileName+".dat";
      }
      TextRecv->Lines->SaveToFile(FileName);
    }
    dlg->Free();
  }
}
//---------------------------------------------------------------------------

void __fastcall TFormNet::Label_ClearRecvClick(TObject *Sender)
{ if(CheckBox_FileOutput->Checked)
  { //char *msgError="接收转向至文件时无法执行该操作！";
    char *msgError="Can not perform the operation when transfering the receiving data to file!";
    Application->MessageBox(msgError,"Warning",MB_ICONWARNING | MB_OK);
    return;
  }
  else
  { TextRecv->Clear();
  }
}
//---------------------------------------------------------------------------

void __fastcall TFormNet::Label_LoaddataClick(TObject *Sender)
{ String file_name;
  if(CheckBox_FileInput->Checked)
  { //char *msgError="启用外部数据源时无法执行该操作！";
    char *msgError="Can not perform the operation when using external file data source!";
    Application->MessageBox(msgError,"Warning",MB_ICONWARNING | MB_OK);
    return;
  }

  TOpenDialog *dlg=new TOpenDialog(this);
  dlg->Filter = "Text files|*.txt|Data files|*.dat|All files|*.*";
  if(dlg->Execute())
  { file_name=dlg->FileName;
    dlg->Free();
  }
  else
  { dlg->Free();
    return;
  }

  FILE *f=fopen(file_name.c_str(),"rb");
  if(f==NULL)
  {ShowMessage("Can not open file!");
   return;
  }
  show_hint(String("Open file..")+file_name);
  int buf_size=fread(&SendBuf[0], 1, MAX_BUF_SIZE, f);
  fclose(f);
  bool text_file=true;
  bool text_is_hex=true;
  for(int i=0;i<buf_size;i++)
  { if(SendBuf[i]<33)
    { if(SendBuf[i]!=9 && SendBuf[i]!=10 && SendBuf[i]!=13 && SendBuf[i]!=32)
      {  text_file=false;
         text_is_hex=false;
         break;
      }
    }
    else if(text_is_hex)
    { if( SendBuf[i]<'0' || (SendBuf[i]>'9' && SendBuf[i]<'A') || (SendBuf[i]>'F' && SendBuf[i]<'a') || SendBuf[i]>'f')
      text_is_hex=false;
    }
  }

  if(buf_size<1) buf_size=0;
  else if(text_file)
  { if(CheckBox_SendAsHex->Checked && !text_is_hex)
    {  initial_evaluate=true;
       CheckBox_SendAsHex->Checked=false;
       //SendAsHex=false;
       initial_evaluate=false;
    }
  }
//  else if(Application->MessageBox("是否以16进制数据载入?","Warning",MB_YESNO)==IDYES)
  else if(Application->MessageBox("load in hexadecimal data?","Warning",MB_YESNO)==IDYES)
  {  int data_len=(buf_size>MAX_BUF_SIZE/3)?MAX_BUF_SIZE/3:buf_size;
     BYTE *pTempSrc=&SendBuf[MAX_BUF_SIZE/3 *2];
     Move(&SendBuf[0],pTempSrc,data_len);
     buf_size=data_to_hex(pTempSrc,data_len,&SendBuf[0],MAX_BUF_SIZE);

     initial_evaluate=true;
     CheckBox_SendAsHex->Checked=true;
     //SendAsHex=true;
     initial_evaluate=false;
  }
  SendBuf[buf_size]=0;
  MemoSend->Text=(char *)&SendBuf[0];

}
//---------------------------------------------------------------------------

void __fastcall TFormNet::Label_ClearSendClick(TObject *Sender)
{ if(CheckBox_FileInput->Checked)
  {  //char *msgError="启用外部数据源时无法执行该操作！";
    char *msgError="Can not perform the operation when using external file data source!";
    Application->MessageBox(msgError,"Warning",MB_ICONWARNING | MB_OK);
    return;
  }
  MemoSend->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TFormNet::Btn_ResetCounterClick(TObject *Sender)
{ ReceivedSize=SendedSize=0;
  //StaticTextRecv->Caption="接收 : 0";
  StaticTextRecv->Caption="Receive : 0";
  //StaticTextSend->Caption="发送 : 0";
  StaticTextSend->Caption="Send : 0";
}
//---------------------------------------------------------------------------

void __fastcall TFormNet::MemoSendKeyPress(TObject *Sender, char &Key)
{ if(Key==10)Key=0;
  else if(Key==1)
  { MemoSend->SelectAll();
  }
  else if(CheckBox_SendAsHex->Checked)
  {  if( Key<3 || (Key>3 && Key<8) || (Key>8 && Key<13) ||(Key>13 && Key<22)|| (Key>22 && Key<32) ||(Key>32 && Key<'0') || (Key>'9' && Key<'A') || (Key>'F' && Key<'a') || Key>'f')
       Key=0;
  }
}
//---------------------------------------------------------------------------


void __fastcall TFormNet::MN_AboutClick(TObject *Sender)
{  char *p1,*p2;
   p1="HinOTORI Telescope PDU System";
   p2="About...";
   Wnd_MessageDlg(p1,p2,MB_OK | MB_ICONAPPLICATION);
}
//---------------------------------------------------------------------------


void __fastcall TFormNet::CheckBox_SendAutoChecksumClick(TObject *Sender)
{ if( ((TCheckBox *)Sender)->Checked)
   { Edit_FixChecksum->Text=IntToHex(FixedCheckSum,2);
     RadioGroupChecksum->ItemIndex=ChecksumMode;
     //if(Wnd_ControlDlg(PanelChecksumSel,"附加位设置",MB_YESNO)==IDYES)
     if(Wnd_ControlDlg(PanelChecksumSel,"Additional bit setting up",MB_YESNO)==IDYES)
     { ChecksumMode=RadioGroupChecksum->ItemIndex;
       FixedCheckSum=hex_to_int(Edit_FixChecksum->Text.c_str());
     }
     else RadioGroupChecksum->ItemIndex=ChecksumMode;
   }

}
//---------------------------------------------------------------------------

void __fastcall TFormNet::MN_SaveConfigClick(TObject *Sender)
{ UpdateConfig(true);
}
//---------------------------------------------------------------------------


void __fastcall TFormNet::MN_VisitSiteClick(TObject *Sender)
{ ShellExecute(Handle,NULL,HomePageUrl_C,NULL,NULL,SW_SHOWNORMAL);
}
//---------------------------------------------------------------------------
void __fastcall TFormNet::MN_ExitClick(TObject *Sender)
{ Close();
}
//---------------------------------------------------------------------------
void __fastcall TFormNet::FormClose(TObject *Sender, TCloseAction &Action)
{ ProgramRunning=false;
  MySocket->Active=false;
  UpdateConfig(true);
}
//---------------------------------------------------------------------------
void _fastcall TFormNet::Wnd_Proc(TMessage &Msg)
{/*由于在注销或者关机时，不容许FormCloseQuerry事件，
   WMQueryEndSession消息会遍历所有的窗口，只要有一个窗口不同意EndSession,那么就会取消关机动作。
   因此如果在收到 WMQueryEndSession询问时，即使你同意（设置Msg.result:=1)，也不能马上手动关闭某些资源，因为这个关机动作可能会被取消，而那些被被关闭的资源可能就无法恢复了。*/
  if(Msg.Msg == WM_QUERYENDSESSION)
  { Msg.Result=true;
    //这里不能关闭任何资源，因为关机动作可能被其他窗口拒绝
    //但是需要保存的数据要保存一下。
    //关机或注销时，系统不会去一个个释放窗体及组件，也不触发如FormDestroy等事件，整个内存直接被reset.
  }
  else if(Msg.Msg == WM_ENDSESSION)
  {
  }
}
//---------------------------------------------------------------------------
void __fastcall TFormNet::FormCloseQuery(TObject *Sender, bool &CanClose)
{ //CanClose=(Wnd_MessageDlg("退出确认？","Confirm",MB_YESNO|MB_ICONQUESTION)==ID_YES);
    CanClose=(Wnd_MessageDlg("Quit？","Confirm",MB_YESNO|MB_ICONQUESTION)==ID_YES);
}
//---------------------------------------------------------------------------




void __fastcall TFormNet::CH1OFFClick(TObject *Sender)
{
   CheckBox_SendAsHex->Checked=True;
   MemoSend->Text="11 05 00 00 00 00 CF 5A" ;
   MemoSend->Refresh();
  int DataSize=0,Offset=0,lastOffset=0,recycleCount=0;
  bool SendOK=false;
  char *DataPtr=NULL;
  transmitting=true;
  MemoSend->Enabled=false;
  Edit_SendInterval->Enabled=false;
  ComboBox_Protocol->Enabled=false;
  IPEdit_IPAddress->Enabled=false;
  Edit_PortNUM->Enabled=false;
  CheckBox_FileInput->Enabled=false;
  cmBtn_NetConnect->Enabled=false;


  if(isNumeric(Edit_SendInterval->Text.c_str()))SendInterval=StrToInt(Edit_SendInterval->Text);
  else Edit_SendInterval->Text=IntToStr(SendInterval);
///////////////////////////////////////////////
  while(transmitting && ProgramRunning)
  {
    lastOffset=Offset;
    DataSize=Get_One_Line(MemoSend->Text.c_str(),Offset,&SendBuf[0],MAX_BUF_SIZE,CheckBox_SendAsHex->Checked);
    if(DataSize<1)
    { if(CheckBox_SendRecycled->Checked)
      { Offset=0;
        lastOffset=0;
        DataSize=Get_One_Line(MemoSend->Text.c_str(),Offset,&SendBuf[0],MAX_BUF_SIZE,CheckBox_SendAsHex->Checked);
        if(DataSize<1) break;
      }else break;
    }

    if(recycleCount++)MyAsyncSleep(SendInterval);

    //show_hint("正在发送数据...");
    show_hint("Sending data now...");
    if(CheckBox_SendAutoChecksum->Checked)
    { if(ChecksumMode==2)
      { SendBuf[DataSize++]=FixedCheckSum;
      }
      else
      { DataSize++;
        set_checksum(&SendBuf[0],DataSize,ChecksumMode);
      }
    }
    DataPtr=&SendBuf[0];
    if(MySocket->Protocol==cmTcpClient)
    { SendOK=MySocket->Send(DataPtr,DataSize);
    }
    else if(MySocket->Protocol==cmUDP)
    { if(!isNumeric(Edit_PortNUM2->Text.c_str()))
      { //Application->MessageBox("无效的目标端口号!","Warning",MB_OK+MB_ICONSTOP);
        Application->MessageBox("Invalid object port number!","Warning",MB_OK+MB_ICONSTOP);
        break;
      }
      SendOK=MySocket->SendTo(IPEdit_IPAddress2->IPdata,str_to_int(Edit_PortNUM2->Text.c_str()),DataPtr,DataSize);
    }
    else if (MySocket->Protocol==cmTcpServer)
    { if(ComboBox_Connections->Items->Count<=1)
      { //Application->MessageBox("当前没有连接对象!","Warning",MB_OK|MB_ICONWARNING);
        Application->MessageBox("No connecting objects now!","Warning",MB_OK|MB_ICONWARNING);
        break;
      }
      else if(ComboBox_Connections->ItemIndex==0)
      { for(MySocket->Connections->node=MySocket->Connections->first;MySocket->Connections->node;MySocket->Connections->node=MySocket->Connections->node->next)
        { SendOK=MySocket->SendTo(MySocket->Connections->node->socket,DataPtr,DataSize);
        }
      }
      else
      { MySocket->Connections->node=MySocket->Connections->first;
        for(int i=1;i<ComboBox_Connections->ItemIndex;i++)
        { if(MySocket->Connections->node)MySocket->Connections->node=MySocket->Connections->node->next;
        }
        if(MySocket->Connections->node)
        { SendOK=MySocket->SendTo(MySocket->Connections->node->socket,DataPtr,DataSize);
        }
        else
        { //Application->MessageBox("无效的连接对象!","Warning",MB_OK|MB_ICONWARNING);
           Application->MessageBox("Invalid connecting object!","Warning",MB_OK|MB_ICONWARNING);
          //ComboBox_Connections->Items->Delete(ComboBox_Connections->ItemIndex);
          //ComboBox_Connections->ItemIndex=0;
          //不能这样简单的删除,需要同时删除内部结点
          break;
        }
      }
    }


    SendedSize+=DataSize;
    //if(SendOK) {show_hint(String("成功发送 ")+get_summary(MemoSend->Text.c_str(),lastOffset,Offset));}
    //else {show_hint("发送失败!"); break;}
    //StaticTextSend->Caption=String("发送 : ")+SendedSize;

    if(SendOK) {show_hint(String("send successfully ")+get_summary(MemoSend->Text.c_str(),lastOffset,Offset));}
    else {show_hint("Fail to send!"); break;}
    StaticTextSend->Caption=String("Send : ")+SendedSize;
     Application->ProcessMessages();
  }
///////////////////////////////////////
  Edit_SendInterval->Enabled=true;
  ComboBox_Protocol->Enabled=true;
  IPEdit_IPAddress->Enabled=true;
  Edit_PortNUM->Enabled=true;
  cmBtn_NetConnect->Enabled=true;
  MemoSend->Enabled=true;
  CheckBox_FileInput->Enabled=true;
  transmitting=false;
  if(CheckBox_ClearAfterSend->Checked)MemoSend->Clear();
  //NOW1->Text="OFF";
  Read1->Click();
}
//---------------------------------------------------------------------------

void __fastcall TFormNet::CH2ONClick(TObject *Sender)
{
   CheckBox_SendAsHex->Checked=True;
   MemoSend->Text="11 05 00 01 FF 00 DF 6A" ;
   MemoSend->Refresh();
  int DataSize=0,Offset=0,lastOffset=0,recycleCount=0;
  bool SendOK=false;
  char *DataPtr=NULL;
  transmitting=true;
  MemoSend->Enabled=false;
  Edit_SendInterval->Enabled=false;
  ComboBox_Protocol->Enabled=false;
  IPEdit_IPAddress->Enabled=false;
  Edit_PortNUM->Enabled=false;
  CheckBox_FileInput->Enabled=false;
  cmBtn_NetConnect->Enabled=false;


  if(isNumeric(Edit_SendInterval->Text.c_str()))SendInterval=StrToInt(Edit_SendInterval->Text);
  else Edit_SendInterval->Text=IntToStr(SendInterval);
///////////////////////////////////////////////
  while(transmitting && ProgramRunning)
  {
    lastOffset=Offset;
    DataSize=Get_One_Line(MemoSend->Text.c_str(),Offset,&SendBuf[0],MAX_BUF_SIZE,CheckBox_SendAsHex->Checked);
    if(DataSize<1)
    { if(CheckBox_SendRecycled->Checked)
      { Offset=0;
        lastOffset=0;
        DataSize=Get_One_Line(MemoSend->Text.c_str(),Offset,&SendBuf[0],MAX_BUF_SIZE,CheckBox_SendAsHex->Checked);
        if(DataSize<1) break;
      }else break;
    }

    if(recycleCount++)MyAsyncSleep(SendInterval);

    //show_hint("正在发送数据...");
    show_hint("Sending data now...");
    if(CheckBox_SendAutoChecksum->Checked)
    { if(ChecksumMode==2)
      { SendBuf[DataSize++]=FixedCheckSum;
      }
      else
      { DataSize++;
        set_checksum(&SendBuf[0],DataSize,ChecksumMode);
      }
    }
    DataPtr=&SendBuf[0];
    if(MySocket->Protocol==cmTcpClient)
    { SendOK=MySocket->Send(DataPtr,DataSize);
    }
    else if(MySocket->Protocol==cmUDP)
    { if(!isNumeric(Edit_PortNUM2->Text.c_str()))
      {// Application->MessageBox("无效的目标端口号!","Warning",MB_OK+MB_ICONSTOP);
        Application->MessageBox("Invalid object port number!","Warning",MB_OK+MB_ICONSTOP);
        break;
      }
      SendOK=MySocket->SendTo(IPEdit_IPAddress2->IPdata,str_to_int(Edit_PortNUM2->Text.c_str()),DataPtr,DataSize);
    }
    else if (MySocket->Protocol==cmTcpServer)
    { if(ComboBox_Connections->Items->Count<=1)
      { //Application->MessageBox("当前没有连接对象!","Warning",MB_OK|MB_ICONWARNING);
        Application->MessageBox("No connecting object now!","Warning",MB_OK|MB_ICONWARNING);
        break;
      }
      else if(ComboBox_Connections->ItemIndex==0)
      { for(MySocket->Connections->node=MySocket->Connections->first;MySocket->Connections->node;MySocket->Connections->node=MySocket->Connections->node->next)
        { SendOK=MySocket->SendTo(MySocket->Connections->node->socket,DataPtr,DataSize);
        }
      }
      else
      { MySocket->Connections->node=MySocket->Connections->first;
        for(int i=1;i<ComboBox_Connections->ItemIndex;i++)
        { if(MySocket->Connections->node)MySocket->Connections->node=MySocket->Connections->node->next;
        }
        if(MySocket->Connections->node)
        { SendOK=MySocket->SendTo(MySocket->Connections->node->socket,DataPtr,DataSize);
        }
        else
        { //Application->MessageBox("无效的连接对象!","Warning",MB_OK|MB_ICONWARNING);
          Application->MessageBox("Invalid connecting object!","Warning",MB_OK|MB_ICONWARNING);
          //ComboBox_Connections->Items->Delete(ComboBox_Connections->ItemIndex);
          //ComboBox_Connections->ItemIndex=0;
          //不能这样简单的删除,需要同时删除内部结点
          break;
        }
      }
    }


    SendedSize+=DataSize;
    if(SendOK) {show_hint(String("send successfully ")+get_summary(MemoSend->Text.c_str(),lastOffset,Offset));}
    else {show_hint("Fail to send!"); break;}
    StaticTextSend->Caption=String("send : ")+SendedSize;
     Application->ProcessMessages();
  }
///////////////////////////////////////
  Edit_SendInterval->Enabled=true;
  ComboBox_Protocol->Enabled=true;
  IPEdit_IPAddress->Enabled=true;
  Edit_PortNUM->Enabled=true;
  cmBtn_NetConnect->Enabled=true;
  MemoSend->Enabled=true;
  CheckBox_FileInput->Enabled=true;
  transmitting=false;
  if(CheckBox_ClearAfterSend->Checked)MemoSend->Clear();
  //NOW2->Text="ON";
  Read2->Click();

  
}
//---------------------------------------------------------------------------

void __fastcall TFormNet::CH2OFFClick(TObject *Sender)
{
   CheckBox_SendAsHex->Checked=True;
   MemoSend->Text="11 05 00 01 00 00 9E 9A" ;
   MemoSend->Refresh();
  int DataSize=0,Offset=0,lastOffset=0,recycleCount=0;
  bool SendOK=false;
  char *DataPtr=NULL;
  transmitting=true;
  MemoSend->Enabled=false;
  Edit_SendInterval->Enabled=false;
  ComboBox_Protocol->Enabled=false;
  IPEdit_IPAddress->Enabled=false;
  Edit_PortNUM->Enabled=false;
  CheckBox_FileInput->Enabled=false;
  cmBtn_NetConnect->Enabled=false;


  if(isNumeric(Edit_SendInterval->Text.c_str()))SendInterval=StrToInt(Edit_SendInterval->Text);
  else Edit_SendInterval->Text=IntToStr(SendInterval);
///////////////////////////////////////////////
  while(transmitting && ProgramRunning)
  {
    lastOffset=Offset;
    DataSize=Get_One_Line(MemoSend->Text.c_str(),Offset,&SendBuf[0],MAX_BUF_SIZE,CheckBox_SendAsHex->Checked);
    if(DataSize<1)
    { if(CheckBox_SendRecycled->Checked)
      { Offset=0;
        lastOffset=0;
        DataSize=Get_One_Line(MemoSend->Text.c_str(),Offset,&SendBuf[0],MAX_BUF_SIZE,CheckBox_SendAsHex->Checked);
        if(DataSize<1) break;
      }else break;
    }

    if(recycleCount++)MyAsyncSleep(SendInterval);

    show_hint("Sending data now...");
    if(CheckBox_SendAutoChecksum->Checked)
    { if(ChecksumMode==2)
      { SendBuf[DataSize++]=FixedCheckSum;
      }
      else
      { DataSize++;
        set_checksum(&SendBuf[0],DataSize,ChecksumMode);
      }
    }
    DataPtr=&SendBuf[0];
    if(MySocket->Protocol==cmTcpClient)
    { SendOK=MySocket->Send(DataPtr,DataSize);
    }
    else if(MySocket->Protocol==cmUDP)
    { if(!isNumeric(Edit_PortNUM2->Text.c_str()))
      { Application->MessageBox("Invalid object port number!","Warning",MB_OK+MB_ICONSTOP);
        break;
      }
      SendOK=MySocket->SendTo(IPEdit_IPAddress2->IPdata,str_to_int(Edit_PortNUM2->Text.c_str()),DataPtr,DataSize);
    }
    else if (MySocket->Protocol==cmTcpServer)
    { if(ComboBox_Connections->Items->Count<=1)
      { Application->MessageBox("No connecting object now!","Warning",MB_OK|MB_ICONWARNING);
        break;
      }
      else if(ComboBox_Connections->ItemIndex==0)
      { for(MySocket->Connections->node=MySocket->Connections->first;MySocket->Connections->node;MySocket->Connections->node=MySocket->Connections->node->next)
        { SendOK=MySocket->SendTo(MySocket->Connections->node->socket,DataPtr,DataSize);
        }
      }
      else
      { MySocket->Connections->node=MySocket->Connections->first;
        for(int i=1;i<ComboBox_Connections->ItemIndex;i++)
        { if(MySocket->Connections->node)MySocket->Connections->node=MySocket->Connections->node->next;
        }
        if(MySocket->Connections->node)
        { SendOK=MySocket->SendTo(MySocket->Connections->node->socket,DataPtr,DataSize);
        }
        else
        { Application->MessageBox("Invalid connecting object!","Warning",MB_OK|MB_ICONWARNING);
          //ComboBox_Connections->Items->Delete(ComboBox_Connections->ItemIndex);
          //ComboBox_Connections->ItemIndex=0;
          //不能这样简单的删除,需要同时删除内部结点
          break;
        }
      }
    }


    SendedSize+=DataSize;
    if(SendOK) {show_hint(String("send successfully ")+get_summary(MemoSend->Text.c_str(),lastOffset,Offset));}
    else {show_hint("Fail to send!"); break;}
    StaticTextSend->Caption=String("Send : ")+SendedSize;
     Application->ProcessMessages();
  }
///////////////////////////////////////
  Edit_SendInterval->Enabled=true;
  ComboBox_Protocol->Enabled=true;
  IPEdit_IPAddress->Enabled=true;
  Edit_PortNUM->Enabled=true;
  cmBtn_NetConnect->Enabled=true;
  MemoSend->Enabled=true;
  CheckBox_FileInput->Enabled=true;
  transmitting=false;
  if(CheckBox_ClearAfterSend->Checked)MemoSend->Clear();
  //NOW2->Text="OFF";
  Read2->Click();

}
//---------------------------------------------------------------------------

void __fastcall TFormNet::CH1ONClick(TObject *Sender)
{
  CheckBox_SendAsHex->Checked=True;
  MemoSend->Text="11 05 00 00 FF 00 8E AA" ;
  MemoSend->Refresh();
    int DataSize=0,Offset=0,lastOffset=0,recycleCount=0;
  bool SendOK=false;
  char *DataPtr=NULL;
  transmitting=true;
  MemoSend->Enabled=false;
  Edit_SendInterval->Enabled=false;
  ComboBox_Protocol->Enabled=false;
  IPEdit_IPAddress->Enabled=false;
  Edit_PortNUM->Enabled=false;
  CheckBox_FileInput->Enabled=false;
  cmBtn_NetConnect->Enabled=false;


  if(isNumeric(Edit_SendInterval->Text.c_str()))SendInterval=StrToInt(Edit_SendInterval->Text);
  else Edit_SendInterval->Text=IntToStr(SendInterval);
///////////////////////////////////////////////
  while(transmitting && ProgramRunning)
  {
    lastOffset=Offset;
    DataSize=Get_One_Line(MemoSend->Text.c_str(),Offset,&SendBuf[0],MAX_BUF_SIZE,CheckBox_SendAsHex->Checked);
    if(DataSize<1)
    { if(CheckBox_SendRecycled->Checked)
      { Offset=0;
        lastOffset=0;
        DataSize=Get_One_Line(MemoSend->Text.c_str(),Offset,&SendBuf[0],MAX_BUF_SIZE,CheckBox_SendAsHex->Checked);
        if(DataSize<1) break;
      }else break;
    }

    if(recycleCount++)MyAsyncSleep(SendInterval);

    show_hint("Sending data now...");
    if(CheckBox_SendAutoChecksum->Checked)
    { if(ChecksumMode==2)
      { SendBuf[DataSize++]=FixedCheckSum;
      }
      else
      { DataSize++;
        set_checksum(&SendBuf[0],DataSize,ChecksumMode);
      }
    }
    DataPtr=&SendBuf[0];
    if(MySocket->Protocol==cmTcpClient)
    { SendOK=MySocket->Send(DataPtr,DataSize);
    }
    else if(MySocket->Protocol==cmUDP)
    { if(!isNumeric(Edit_PortNUM2->Text.c_str()))
      { Application->MessageBox("Invalid object port number!","Warning",MB_OK+MB_ICONSTOP);
        break;
      }
      SendOK=MySocket->SendTo(IPEdit_IPAddress2->IPdata,str_to_int(Edit_PortNUM2->Text.c_str()),DataPtr,DataSize);
    }
    else if (MySocket->Protocol==cmTcpServer)
    { if(ComboBox_Connections->Items->Count<=1)
      { Application->MessageBox("No connecting object now!","Warning",MB_OK|MB_ICONWARNING);
        break;
      }
      else if(ComboBox_Connections->ItemIndex==0)
      { for(MySocket->Connections->node=MySocket->Connections->first;MySocket->Connections->node;MySocket->Connections->node=MySocket->Connections->node->next)
        { SendOK=MySocket->SendTo(MySocket->Connections->node->socket,DataPtr,DataSize);
        }
      }
      else
      { MySocket->Connections->node=MySocket->Connections->first;
        for(int i=1;i<ComboBox_Connections->ItemIndex;i++)
        { if(MySocket->Connections->node)MySocket->Connections->node=MySocket->Connections->node->next;
        }
        if(MySocket->Connections->node)
        { SendOK=MySocket->SendTo(MySocket->Connections->node->socket,DataPtr,DataSize);
        }
        else
        { Application->MessageBox("Invalid connecting object!","Warning",MB_OK|MB_ICONWARNING);
          //ComboBox_Connections->Items->Delete(ComboBox_Connections->ItemIndex);
          //ComboBox_Connections->ItemIndex=0;
          //不能这样简单的删除,需要同时删除内部结点
          break;
        }
      }
    }


    SendedSize+=DataSize;
    if(SendOK) {show_hint(String("Send sucessfully ")+get_summary(MemoSend->Text.c_str(),lastOffset,Offset));}
    else {show_hint("Fail to send!"); break;}
    StaticTextSend->Caption=String("Send")+SendedSize;
     Application->ProcessMessages();

  }
///////////////////////////////////////
  Edit_SendInterval->Enabled=true;
  ComboBox_Protocol->Enabled=true;
  IPEdit_IPAddress->Enabled=true;
  Edit_PortNUM->Enabled=true;
  cmBtn_NetConnect->Enabled=true;
  MemoSend->Enabled=true;
  CheckBox_FileInput->Enabled=true;
  transmitting=false;
  if(CheckBox_ClearAfterSend->Checked)MemoSend->Clear();
  //NOW1->Text="ON";

  //Read1Click()；
  //TFormNet::Read1Click(TObject *Sender);
  //TFormNet::Read1Click();
  //__fastcall TFormNet::Read1Click(TObject *Sender);
  //callOnClick(Read1);
  Read1->Click();

}
//---------------------------------------------------------------------------

void __fastcall TFormNet::CH3ONClick(TObject *Sender)
{
   CheckBox_SendAsHex->Checked=True;
   MemoSend->Text="11 05 00 02 FF 00 2F 6A" ;
   MemoSend->Refresh();
  int DataSize=0,Offset=0,lastOffset=0,recycleCount=0;
  bool SendOK=false;
  char *DataPtr=NULL;
  transmitting=true;
  MemoSend->Enabled=false;
  Edit_SendInterval->Enabled=false;
  ComboBox_Protocol->Enabled=false;
  IPEdit_IPAddress->Enabled=false;
  Edit_PortNUM->Enabled=false;
  CheckBox_FileInput->Enabled=false;
  cmBtn_NetConnect->Enabled=false;


  if(isNumeric(Edit_SendInterval->Text.c_str()))SendInterval=StrToInt(Edit_SendInterval->Text);
  else Edit_SendInterval->Text=IntToStr(SendInterval);
///////////////////////////////////////////////
  while(transmitting && ProgramRunning)
  {
    lastOffset=Offset;
    DataSize=Get_One_Line(MemoSend->Text.c_str(),Offset,&SendBuf[0],MAX_BUF_SIZE,CheckBox_SendAsHex->Checked);
    if(DataSize<1)
    { if(CheckBox_SendRecycled->Checked)
      { Offset=0;
        lastOffset=0;
        DataSize=Get_One_Line(MemoSend->Text.c_str(),Offset,&SendBuf[0],MAX_BUF_SIZE,CheckBox_SendAsHex->Checked);
        if(DataSize<1) break;
      }else break;
    }

    if(recycleCount++)MyAsyncSleep(SendInterval);

    show_hint("Sending data now...");
    if(CheckBox_SendAutoChecksum->Checked)
    { if(ChecksumMode==2)
      { SendBuf[DataSize++]=FixedCheckSum;
      }
      else
      { DataSize++;
        set_checksum(&SendBuf[0],DataSize,ChecksumMode);
      }
    }
    DataPtr=&SendBuf[0];
    if(MySocket->Protocol==cmTcpClient)
    { SendOK=MySocket->Send(DataPtr,DataSize);
    }
    else if(MySocket->Protocol==cmUDP)
    { if(!isNumeric(Edit_PortNUM2->Text.c_str()))
      { Application->MessageBox("Invalid object port number!","Warning",MB_OK+MB_ICONSTOP);
        break;
      }
      SendOK=MySocket->SendTo(IPEdit_IPAddress2->IPdata,str_to_int(Edit_PortNUM2->Text.c_str()),DataPtr,DataSize);
    }
    else if (MySocket->Protocol==cmTcpServer)
    { if(ComboBox_Connections->Items->Count<=1)
      { Application->MessageBox("No connecting object now!","Warning",MB_OK|MB_ICONWARNING);
        break;
      }
      else if(ComboBox_Connections->ItemIndex==0)
      { for(MySocket->Connections->node=MySocket->Connections->first;MySocket->Connections->node;MySocket->Connections->node=MySocket->Connections->node->next)
        { SendOK=MySocket->SendTo(MySocket->Connections->node->socket,DataPtr,DataSize);
        }
      }
      else
      { MySocket->Connections->node=MySocket->Connections->first;
        for(int i=1;i<ComboBox_Connections->ItemIndex;i++)
        { if(MySocket->Connections->node)MySocket->Connections->node=MySocket->Connections->node->next;
        }
        if(MySocket->Connections->node)
        { SendOK=MySocket->SendTo(MySocket->Connections->node->socket,DataPtr,DataSize);
        }
        else
        { Application->MessageBox("Invalid connecting object!","Warning",MB_OK|MB_ICONWARNING);
          //ComboBox_Connections->Items->Delete(ComboBox_Connections->ItemIndex);
          //ComboBox_Connections->ItemIndex=0;
          //不能这样简单的删除,需要同时删除内部结点
          break;
        }
      }
    }


    SendedSize+=DataSize;
    if(SendOK) {show_hint(String("send successfully ")+get_summary(MemoSend->Text.c_str(),lastOffset,Offset));}
    else {show_hint("Fail to send!"); break;}
    StaticTextSend->Caption=String("Send : ")+SendedSize;
     Application->ProcessMessages();
  }
///////////////////////////////////////
  Edit_SendInterval->Enabled=true;
  ComboBox_Protocol->Enabled=true;
  IPEdit_IPAddress->Enabled=true;
  Edit_PortNUM->Enabled=true;
  cmBtn_NetConnect->Enabled=true;
  MemoSend->Enabled=true;
  CheckBox_FileInput->Enabled=true;
  transmitting=false;
  if(CheckBox_ClearAfterSend->Checked)MemoSend->Clear();
  //NOW3->Text="ON";
  Read3->Click();

}
//---------------------------------------------------------------------------

void __fastcall TFormNet::CH3OFFClick(TObject *Sender)
{
   CheckBox_SendAsHex->Checked=True;
   MemoSend->Text="11 05 00 02 00 00 6E 9A" ;
   MemoSend->Refresh();
  int DataSize=0,Offset=0,lastOffset=0,recycleCount=0;
  bool SendOK=false;
  char *DataPtr=NULL;
  transmitting=true;
  MemoSend->Enabled=false;
  Edit_SendInterval->Enabled=false;
  ComboBox_Protocol->Enabled=false;
  IPEdit_IPAddress->Enabled=false;
  Edit_PortNUM->Enabled=false;
  CheckBox_FileInput->Enabled=false;
  cmBtn_NetConnect->Enabled=false;


  if(isNumeric(Edit_SendInterval->Text.c_str()))SendInterval=StrToInt(Edit_SendInterval->Text);
  else Edit_SendInterval->Text=IntToStr(SendInterval);
///////////////////////////////////////////////
  while(transmitting && ProgramRunning)
  {
    lastOffset=Offset;
    DataSize=Get_One_Line(MemoSend->Text.c_str(),Offset,&SendBuf[0],MAX_BUF_SIZE,CheckBox_SendAsHex->Checked);
    if(DataSize<1)
    { if(CheckBox_SendRecycled->Checked)
      { Offset=0;
        lastOffset=0;
        DataSize=Get_One_Line(MemoSend->Text.c_str(),Offset,&SendBuf[0],MAX_BUF_SIZE,CheckBox_SendAsHex->Checked);
        if(DataSize<1) break;
      }else break;
    }

    if(recycleCount++)MyAsyncSleep(SendInterval);

    show_hint("Sending data now...");
    if(CheckBox_SendAutoChecksum->Checked)
    { if(ChecksumMode==2)
      { SendBuf[DataSize++]=FixedCheckSum;
      }
      else
      { DataSize++;
        set_checksum(&SendBuf[0],DataSize,ChecksumMode);
      }
    }
    DataPtr=&SendBuf[0];
    if(MySocket->Protocol==cmTcpClient)
    { SendOK=MySocket->Send(DataPtr,DataSize);
    }
    else if(MySocket->Protocol==cmUDP)
    { if(!isNumeric(Edit_PortNUM2->Text.c_str()))
      { Application->MessageBox("Invalid object port number!","Warning",MB_OK+MB_ICONSTOP);
        break;
      }
      SendOK=MySocket->SendTo(IPEdit_IPAddress2->IPdata,str_to_int(Edit_PortNUM2->Text.c_str()),DataPtr,DataSize);
    }
    else if (MySocket->Protocol==cmTcpServer)
    { if(ComboBox_Connections->Items->Count<=1)
      { Application->MessageBox("No connecting object now!","Warning",MB_OK|MB_ICONWARNING);
        break;
      }
      else if(ComboBox_Connections->ItemIndex==0)
      { for(MySocket->Connections->node=MySocket->Connections->first;MySocket->Connections->node;MySocket->Connections->node=MySocket->Connections->node->next)
        { SendOK=MySocket->SendTo(MySocket->Connections->node->socket,DataPtr,DataSize);
        }
      }
      else
      { MySocket->Connections->node=MySocket->Connections->first;
        for(int i=1;i<ComboBox_Connections->ItemIndex;i++)
        { if(MySocket->Connections->node)MySocket->Connections->node=MySocket->Connections->node->next;
        }
        if(MySocket->Connections->node)
        { SendOK=MySocket->SendTo(MySocket->Connections->node->socket,DataPtr,DataSize);
        }
        else
        { Application->MessageBox("Invalid connecting object!","Warning",MB_OK|MB_ICONWARNING);
          //ComboBox_Connections->Items->Delete(ComboBox_Connections->ItemIndex);
          //ComboBox_Connections->ItemIndex=0;
          //不能这样简单的删除,需要同时删除内部结点
          break;
        }
      }
    }


    SendedSize+=DataSize;
    if(SendOK) {show_hint(String("Send successfully!")+get_summary(MemoSend->Text.c_str(),lastOffset,Offset));}
    else {show_hint("Fail to send!"); break;}
    StaticTextSend->Caption=String("Send : ")+SendedSize;
     Application->ProcessMessages();
  }
///////////////////////////////////////
  Edit_SendInterval->Enabled=true;
  ComboBox_Protocol->Enabled=true;
  IPEdit_IPAddress->Enabled=true;
  Edit_PortNUM->Enabled=true;
  cmBtn_NetConnect->Enabled=true;
  MemoSend->Enabled=true;
  CheckBox_FileInput->Enabled=true;
  transmitting=false;
  if(CheckBox_ClearAfterSend->Checked)MemoSend->Clear();
  //NOW3->Text="OFF";
  Read3->Click();
  
}
//---------------------------------------------------------------------------

void __fastcall TFormNet::CH4ONClick(TObject *Sender)
{
   CheckBox_SendAsHex->Checked=True;
   MemoSend->Text="11 05 00 03 FF 00 7E AA" ;
   MemoSend->Refresh();
  int DataSize=0,Offset=0,lastOffset=0,recycleCount=0;
  bool SendOK=false;
  char *DataPtr=NULL;
  transmitting=true;
  MemoSend->Enabled=false;
  Edit_SendInterval->Enabled=false;
  ComboBox_Protocol->Enabled=false;
  IPEdit_IPAddress->Enabled=false;
  Edit_PortNUM->Enabled=false;
  CheckBox_FileInput->Enabled=false;
  cmBtn_NetConnect->Enabled=false;


  if(isNumeric(Edit_SendInterval->Text.c_str()))SendInterval=StrToInt(Edit_SendInterval->Text);
  else Edit_SendInterval->Text=IntToStr(SendInterval);
///////////////////////////////////////////////
  while(transmitting && ProgramRunning)
  {
    lastOffset=Offset;
    DataSize=Get_One_Line(MemoSend->Text.c_str(),Offset,&SendBuf[0],MAX_BUF_SIZE,CheckBox_SendAsHex->Checked);
    if(DataSize<1)
    { if(CheckBox_SendRecycled->Checked)
      { Offset=0;
        lastOffset=0;
        DataSize=Get_One_Line(MemoSend->Text.c_str(),Offset,&SendBuf[0],MAX_BUF_SIZE,CheckBox_SendAsHex->Checked);
        if(DataSize<1) break;
      }else break;
    }

    if(recycleCount++)MyAsyncSleep(SendInterval);

    show_hint("Sending data now......");
    if(CheckBox_SendAutoChecksum->Checked)
    { if(ChecksumMode==2)
      { SendBuf[DataSize++]=FixedCheckSum;
      }
      else
      { DataSize++;
        set_checksum(&SendBuf[0],DataSize,ChecksumMode);
      }
    }
    DataPtr=&SendBuf[0];
    if(MySocket->Protocol==cmTcpClient)
    { SendOK=MySocket->Send(DataPtr,DataSize);
    }
    else if(MySocket->Protocol==cmUDP)
    { if(!isNumeric(Edit_PortNUM2->Text.c_str()))
      { Application->MessageBox("Invalid object port number!","Warning",MB_OK+MB_ICONSTOP);
        break;
      }
      SendOK=MySocket->SendTo(IPEdit_IPAddress2->IPdata,str_to_int(Edit_PortNUM2->Text.c_str()),DataPtr,DataSize);
    }
    else if (MySocket->Protocol==cmTcpServer)
    { if(ComboBox_Connections->Items->Count<=1)
      { Application->MessageBox("No connecting object now!","Warning",MB_OK|MB_ICONWARNING);
        break;
      }
      else if(ComboBox_Connections->ItemIndex==0)
      { for(MySocket->Connections->node=MySocket->Connections->first;MySocket->Connections->node;MySocket->Connections->node=MySocket->Connections->node->next)
        { SendOK=MySocket->SendTo(MySocket->Connections->node->socket,DataPtr,DataSize);
        }
      }
      else
      { MySocket->Connections->node=MySocket->Connections->first;
        for(int i=1;i<ComboBox_Connections->ItemIndex;i++)
        { if(MySocket->Connections->node)MySocket->Connections->node=MySocket->Connections->node->next;
        }
        if(MySocket->Connections->node)
        { SendOK=MySocket->SendTo(MySocket->Connections->node->socket,DataPtr,DataSize);
        }
        else
        { Application->MessageBox("Invalid connecting object!","Warning",MB_OK|MB_ICONWARNING);
          //ComboBox_Connections->Items->Delete(ComboBox_Connections->ItemIndex);
          //ComboBox_Connections->ItemIndex=0;
          //不能这样简单的删除,需要同时删除内部结点
          break;
        }
      }
    }


    SendedSize+=DataSize;
    if(SendOK) {show_hint(String("Send Successfully ")+get_summary(MemoSend->Text.c_str(),lastOffset,Offset));}
    else {show_hint("Fail to send!"); break;}
    StaticTextSend->Caption=String("Send : ")+SendedSize;
     Application->ProcessMessages();
  }
///////////////////////////////////////
  Edit_SendInterval->Enabled=true;
  ComboBox_Protocol->Enabled=true;
  IPEdit_IPAddress->Enabled=true;
  Edit_PortNUM->Enabled=true;
  cmBtn_NetConnect->Enabled=true;
  MemoSend->Enabled=true;
  CheckBox_FileInput->Enabled=true;
  transmitting=false;
  if(CheckBox_ClearAfterSend->Checked)MemoSend->Clear();
 //NOW4->Text="ON";
  Read4->Click();

}
//---------------------------------------------------------------------------

void __fastcall TFormNet::CH4OFFClick(TObject *Sender)
{
   CheckBox_SendAsHex->Checked=True;
   MemoSend->Text="11 05 00 03 00 00 3F 5A" ;
   MemoSend->Refresh();
  int DataSize=0,Offset=0,lastOffset=0,recycleCount=0;
  bool SendOK=false;
  char *DataPtr=NULL;
  transmitting=true;
  MemoSend->Enabled=false;
  Edit_SendInterval->Enabled=false;
  ComboBox_Protocol->Enabled=false;
  IPEdit_IPAddress->Enabled=false;
  Edit_PortNUM->Enabled=false;
  CheckBox_FileInput->Enabled=false;
  cmBtn_NetConnect->Enabled=false;


  if(isNumeric(Edit_SendInterval->Text.c_str()))SendInterval=StrToInt(Edit_SendInterval->Text);
  else Edit_SendInterval->Text=IntToStr(SendInterval);
///////////////////////////////////////////////
  while(transmitting && ProgramRunning)
  {
    lastOffset=Offset;
    DataSize=Get_One_Line(MemoSend->Text.c_str(),Offset,&SendBuf[0],MAX_BUF_SIZE,CheckBox_SendAsHex->Checked);
    if(DataSize<1)
    { if(CheckBox_SendRecycled->Checked)
      { Offset=0;
        lastOffset=0;
        DataSize=Get_One_Line(MemoSend->Text.c_str(),Offset,&SendBuf[0],MAX_BUF_SIZE,CheckBox_SendAsHex->Checked);
        if(DataSize<1) break;
      }else break;
    }

    if(recycleCount++)MyAsyncSleep(SendInterval);

    show_hint("Sending data now...");
    if(CheckBox_SendAutoChecksum->Checked)
    { if(ChecksumMode==2)
      { SendBuf[DataSize++]=FixedCheckSum;
      }
      else
      { DataSize++;
        set_checksum(&SendBuf[0],DataSize,ChecksumMode);
      }
    }
    DataPtr=&SendBuf[0];
    if(MySocket->Protocol==cmTcpClient)
    { SendOK=MySocket->Send(DataPtr,DataSize);
    }
    else if(MySocket->Protocol==cmUDP)
    { if(!isNumeric(Edit_PortNUM2->Text.c_str()))
      { Application->MessageBox("Invalid object port number!","Warning",MB_OK+MB_ICONSTOP);
        break;
      }
      SendOK=MySocket->SendTo(IPEdit_IPAddress2->IPdata,str_to_int(Edit_PortNUM2->Text.c_str()),DataPtr,DataSize);
    }
    else if (MySocket->Protocol==cmTcpServer)
    { if(ComboBox_Connections->Items->Count<=1)
      { Application->MessageBox("No connecting object now!","Warning",MB_OK|MB_ICONWARNING);
        break;
      }
      else if(ComboBox_Connections->ItemIndex==0)
      { for(MySocket->Connections->node=MySocket->Connections->first;MySocket->Connections->node;MySocket->Connections->node=MySocket->Connections->node->next)
        { SendOK=MySocket->SendTo(MySocket->Connections->node->socket,DataPtr,DataSize);
        }
      }
      else
      { MySocket->Connections->node=MySocket->Connections->first;
        for(int i=1;i<ComboBox_Connections->ItemIndex;i++)
        { if(MySocket->Connections->node)MySocket->Connections->node=MySocket->Connections->node->next;
        }
        if(MySocket->Connections->node)
        { SendOK=MySocket->SendTo(MySocket->Connections->node->socket,DataPtr,DataSize);
        }
        else
        { Application->MessageBox("Invalid connecting object!","Warning",MB_OK|MB_ICONWARNING);
          //ComboBox_Connections->Items->Delete(ComboBox_Connections->ItemIndex);
          //ComboBox_Connections->ItemIndex=0;
          //不能这样简单的删除,需要同时删除内部结点
          break;
        }
      }
    }


    SendedSize+=DataSize;
    if(SendOK) {show_hint(String("Send successfully ")+get_summary(MemoSend->Text.c_str(),lastOffset,Offset));}
    else {show_hint("Fail to send!"); break;}
    StaticTextSend->Caption=String("Send : ")+SendedSize;
     Application->ProcessMessages();
  }
///////////////////////////////////////
  Edit_SendInterval->Enabled=true;
  ComboBox_Protocol->Enabled=true;
  IPEdit_IPAddress->Enabled=true;
  Edit_PortNUM->Enabled=true;
  cmBtn_NetConnect->Enabled=true;
  MemoSend->Enabled=true;
  CheckBox_FileInput->Enabled=true;
  transmitting=false;
  if(CheckBox_ClearAfterSend->Checked)MemoSend->Clear();
  //NOW4->Text="OFF";
  Read4->Click();                 

  
}
//---------------------------------------------------------------------------


void __fastcall TFormNet::CH5ONClick(TObject *Sender)
{
   CheckBox_SendAsHex->Checked=True;
   MemoSend->Text="11 05 00 04 FF 00 CF 6B" ;
   MemoSend->Refresh();
  int DataSize=0,Offset=0,lastOffset=0,recycleCount=0;
  bool SendOK=false;
  char *DataPtr=NULL;
  transmitting=true;
  MemoSend->Enabled=false;
  Edit_SendInterval->Enabled=false;
  ComboBox_Protocol->Enabled=false;
  IPEdit_IPAddress->Enabled=false;
  Edit_PortNUM->Enabled=false;
  CheckBox_FileInput->Enabled=false;
  cmBtn_NetConnect->Enabled=false;


  if(isNumeric(Edit_SendInterval->Text.c_str()))SendInterval=StrToInt(Edit_SendInterval->Text);
  else Edit_SendInterval->Text=IntToStr(SendInterval);
///////////////////////////////////////////////
  while(transmitting && ProgramRunning)
  {
    lastOffset=Offset;
    DataSize=Get_One_Line(MemoSend->Text.c_str(),Offset,&SendBuf[0],MAX_BUF_SIZE,CheckBox_SendAsHex->Checked);
    if(DataSize<1)
    { if(CheckBox_SendRecycled->Checked)
      { Offset=0;
        lastOffset=0;
        DataSize=Get_One_Line(MemoSend->Text.c_str(),Offset,&SendBuf[0],MAX_BUF_SIZE,CheckBox_SendAsHex->Checked);
        if(DataSize<1) break;
      }else break;
    }

    if(recycleCount++)MyAsyncSleep(SendInterval);

    show_hint("Sending data now...");
    if(CheckBox_SendAutoChecksum->Checked)
    { if(ChecksumMode==2)
      { SendBuf[DataSize++]=FixedCheckSum;
      }
      else
      { DataSize++;
        set_checksum(&SendBuf[0],DataSize,ChecksumMode);
      }
    }
    DataPtr=&SendBuf[0];
    if(MySocket->Protocol==cmTcpClient)
    { SendOK=MySocket->Send(DataPtr,DataSize);
    }
    else if(MySocket->Protocol==cmUDP)
    { if(!isNumeric(Edit_PortNUM2->Text.c_str()))
      { Application->MessageBox("Invalid object port number!","Warning",MB_OK+MB_ICONSTOP);
        break;
      }
      SendOK=MySocket->SendTo(IPEdit_IPAddress2->IPdata,str_to_int(Edit_PortNUM2->Text.c_str()),DataPtr,DataSize);
    }
    else if (MySocket->Protocol==cmTcpServer)
    { if(ComboBox_Connections->Items->Count<=1)
      { Application->MessageBox("No connecting object now!","Warning",MB_OK|MB_ICONWARNING);
        break;
      }
      else if(ComboBox_Connections->ItemIndex==0)
      { for(MySocket->Connections->node=MySocket->Connections->first;MySocket->Connections->node;MySocket->Connections->node=MySocket->Connections->node->next)
        { SendOK=MySocket->SendTo(MySocket->Connections->node->socket,DataPtr,DataSize);
        }
      }
      else
      { MySocket->Connections->node=MySocket->Connections->first;
        for(int i=1;i<ComboBox_Connections->ItemIndex;i++)
        { if(MySocket->Connections->node)MySocket->Connections->node=MySocket->Connections->node->next;
        }
        if(MySocket->Connections->node)
        { SendOK=MySocket->SendTo(MySocket->Connections->node->socket,DataPtr,DataSize);
        }
        else
        { Application->MessageBox("Invalid connecting object!","Warning",MB_OK|MB_ICONWARNING);
          //ComboBox_Connections->Items->Delete(ComboBox_Connections->ItemIndex);
          //ComboBox_Connections->ItemIndex=0;
          //不能这样简单的删除,需要同时删除内部结点
          break;
        }
      }
    }


    SendedSize+=DataSize;
    if(SendOK) {show_hint(String("Send successfully ")+get_summary(MemoSend->Text.c_str(),lastOffset,Offset));}
    else {show_hint("Fail to send!"); break;}
    StaticTextSend->Caption=String("Send : ")+SendedSize;
     Application->ProcessMessages();
  }
///////////////////////////////////////
  Edit_SendInterval->Enabled=true;
  ComboBox_Protocol->Enabled=true;
  IPEdit_IPAddress->Enabled=true;
  Edit_PortNUM->Enabled=true;
  cmBtn_NetConnect->Enabled=true;
  MemoSend->Enabled=true;
  CheckBox_FileInput->Enabled=true;
  transmitting=false;
  if(CheckBox_ClearAfterSend->Checked)MemoSend->Clear();
  //NOW5->Text="ON";
  Read5->Click();
  
}
//---------------------------------------------------------------------------

void __fastcall TFormNet::CH5OFFClick(TObject *Sender)
{
   CheckBox_SendAsHex->Checked=True;
   MemoSend->Text="11 05 00 04 00 00 8E 9B" ;
   MemoSend->Refresh();
  int DataSize=0,Offset=0,lastOffset=0,recycleCount=0;
  bool SendOK=false;
  char *DataPtr=NULL;
  transmitting=true;
  MemoSend->Enabled=false;
  Edit_SendInterval->Enabled=false;
  ComboBox_Protocol->Enabled=false;
  IPEdit_IPAddress->Enabled=false;
  Edit_PortNUM->Enabled=false;
  CheckBox_FileInput->Enabled=false;
  cmBtn_NetConnect->Enabled=false;


  if(isNumeric(Edit_SendInterval->Text.c_str()))SendInterval=StrToInt(Edit_SendInterval->Text);
  else Edit_SendInterval->Text=IntToStr(SendInterval);
///////////////////////////////////////////////
  while(transmitting && ProgramRunning)
  {
    lastOffset=Offset;
    DataSize=Get_One_Line(MemoSend->Text.c_str(),Offset,&SendBuf[0],MAX_BUF_SIZE,CheckBox_SendAsHex->Checked);
    if(DataSize<1)
    { if(CheckBox_SendRecycled->Checked)
      { Offset=0;
        lastOffset=0;
        DataSize=Get_One_Line(MemoSend->Text.c_str(),Offset,&SendBuf[0],MAX_BUF_SIZE,CheckBox_SendAsHex->Checked);
        if(DataSize<1) break;
      }else break;
    }

    if(recycleCount++)MyAsyncSleep(SendInterval);

    show_hint("Sending data now...");
    if(CheckBox_SendAutoChecksum->Checked)
    { if(ChecksumMode==2)
      { SendBuf[DataSize++]=FixedCheckSum;
      }
      else
      { DataSize++;
        set_checksum(&SendBuf[0],DataSize,ChecksumMode);
      }
    }
    DataPtr=&SendBuf[0];
    if(MySocket->Protocol==cmTcpClient)
    { SendOK=MySocket->Send(DataPtr,DataSize);
    }
    else if(MySocket->Protocol==cmUDP)
    { if(!isNumeric(Edit_PortNUM2->Text.c_str()))
      { Application->MessageBox("Invalid object port number!","Warning",MB_OK+MB_ICONSTOP);
        break;
      }
      SendOK=MySocket->SendTo(IPEdit_IPAddress2->IPdata,str_to_int(Edit_PortNUM2->Text.c_str()),DataPtr,DataSize);
    }
    else if (MySocket->Protocol==cmTcpServer)
    { if(ComboBox_Connections->Items->Count<=1)
      { Application->MessageBox("No connecting object now!","Warning",MB_OK|MB_ICONWARNING);
        break;
      }
      else if(ComboBox_Connections->ItemIndex==0)
      { for(MySocket->Connections->node=MySocket->Connections->first;MySocket->Connections->node;MySocket->Connections->node=MySocket->Connections->node->next)
        { SendOK=MySocket->SendTo(MySocket->Connections->node->socket,DataPtr,DataSize);
        }
      }
      else
      { MySocket->Connections->node=MySocket->Connections->first;
        for(int i=1;i<ComboBox_Connections->ItemIndex;i++)
        { if(MySocket->Connections->node)MySocket->Connections->node=MySocket->Connections->node->next;
        }
        if(MySocket->Connections->node)
        { SendOK=MySocket->SendTo(MySocket->Connections->node->socket,DataPtr,DataSize);
        }
        else
        { Application->MessageBox("Invalid connecting object!","Warning",MB_OK|MB_ICONWARNING);
          //ComboBox_Connections->Items->Delete(ComboBox_Connections->ItemIndex);
          //ComboBox_Connections->ItemIndex=0;
          //不能这样简单的删除,需要同时删除内部结点
          break;
        }
      }
    }


    SendedSize+=DataSize;
    if(SendOK) {show_hint(String("Send successfully ")+get_summary(MemoSend->Text.c_str(),lastOffset,Offset));}
    else {show_hint("Fail to send !"); break;}
    StaticTextSend->Caption=String("Send : ")+SendedSize;
     Application->ProcessMessages();
  }
///////////////////////////////////////
  Edit_SendInterval->Enabled=true;
  ComboBox_Protocol->Enabled=true;
  IPEdit_IPAddress->Enabled=true;
  Edit_PortNUM->Enabled=true;
  cmBtn_NetConnect->Enabled=true;
  MemoSend->Enabled=true;
  CheckBox_FileInput->Enabled=true;
  transmitting=false;
  if(CheckBox_ClearAfterSend->Checked)MemoSend->Clear();
 // NOW5->Text="OFF";
  Read5->Click();
  
}
//---------------------------------------------------------------------------

void __fastcall TFormNet::CH6ONClick(TObject *Sender)
{
   CheckBox_SendAsHex->Checked=True;
   MemoSend->Text="11 05 00 05 FF 00 9E AB" ;
   MemoSend->Refresh();
  int DataSize=0,Offset=0,lastOffset=0,recycleCount=0;
  bool SendOK=false;
  char *DataPtr=NULL;
  transmitting=true;
  MemoSend->Enabled=false;
  Edit_SendInterval->Enabled=false;
  ComboBox_Protocol->Enabled=false;
  IPEdit_IPAddress->Enabled=false;
  Edit_PortNUM->Enabled=false;
  CheckBox_FileInput->Enabled=false;
  cmBtn_NetConnect->Enabled=false;


  if(isNumeric(Edit_SendInterval->Text.c_str()))SendInterval=StrToInt(Edit_SendInterval->Text);
  else Edit_SendInterval->Text=IntToStr(SendInterval);
///////////////////////////////////////////////
  while(transmitting && ProgramRunning)
  {
    lastOffset=Offset;
    DataSize=Get_One_Line(MemoSend->Text.c_str(),Offset,&SendBuf[0],MAX_BUF_SIZE,CheckBox_SendAsHex->Checked);
    if(DataSize<1)
    { if(CheckBox_SendRecycled->Checked)
      { Offset=0;
        lastOffset=0;
        DataSize=Get_One_Line(MemoSend->Text.c_str(),Offset,&SendBuf[0],MAX_BUF_SIZE,CheckBox_SendAsHex->Checked);
        if(DataSize<1) break;
      }else break;
    }

    if(recycleCount++)MyAsyncSleep(SendInterval);

    show_hint("Sending data now...");
    if(CheckBox_SendAutoChecksum->Checked)
    { if(ChecksumMode==2)
      { SendBuf[DataSize++]=FixedCheckSum;
      }
      else
      { DataSize++;
        set_checksum(&SendBuf[0],DataSize,ChecksumMode);
      }
    }
    DataPtr=&SendBuf[0];
    if(MySocket->Protocol==cmTcpClient)
    { SendOK=MySocket->Send(DataPtr,DataSize);
    }
    else if(MySocket->Protocol==cmUDP)
    { if(!isNumeric(Edit_PortNUM2->Text.c_str()))
      { Application->MessageBox("Invalid object port number!","Warning",MB_OK+MB_ICONSTOP);
        break;
      }
      SendOK=MySocket->SendTo(IPEdit_IPAddress2->IPdata,str_to_int(Edit_PortNUM2->Text.c_str()),DataPtr,DataSize);
    }
    else if (MySocket->Protocol==cmTcpServer)
    { if(ComboBox_Connections->Items->Count<=1)
      { Application->MessageBox("No connecting object now!","Warning",MB_OK|MB_ICONWARNING);
        break;
      }
      else if(ComboBox_Connections->ItemIndex==0)
      { for(MySocket->Connections->node=MySocket->Connections->first;MySocket->Connections->node;MySocket->Connections->node=MySocket->Connections->node->next)
        { SendOK=MySocket->SendTo(MySocket->Connections->node->socket,DataPtr,DataSize);
        }
      }
      else
      { MySocket->Connections->node=MySocket->Connections->first;
        for(int i=1;i<ComboBox_Connections->ItemIndex;i++)
        { if(MySocket->Connections->node)MySocket->Connections->node=MySocket->Connections->node->next;
        }
        if(MySocket->Connections->node)
        { SendOK=MySocket->SendTo(MySocket->Connections->node->socket,DataPtr,DataSize);
        }
        else
        { Application->MessageBox("Invalid connecting object!","Warning",MB_OK|MB_ICONWARNING);
          //ComboBox_Connections->Items->Delete(ComboBox_Connections->ItemIndex);
          //ComboBox_Connections->ItemIndex=0;
          //不能这样简单的删除,需要同时删除内部结点
          break;
        }
      }
    }


    SendedSize+=DataSize;
    if(SendOK) {show_hint(String("Sent sucessfully ")+get_summary(MemoSend->Text.c_str(),lastOffset,Offset));}
    else {show_hint("Fail to send!"); break;}
    StaticTextSend->Caption=String("Send : ")+SendedSize;
     Application->ProcessMessages();
  }
///////////////////////////////////////
  Edit_SendInterval->Enabled=true;
  ComboBox_Protocol->Enabled=true;
  IPEdit_IPAddress->Enabled=true;
  Edit_PortNUM->Enabled=true;
  cmBtn_NetConnect->Enabled=true;
  MemoSend->Enabled=true;
  CheckBox_FileInput->Enabled=true;
  transmitting=false;
  if(CheckBox_ClearAfterSend->Checked)MemoSend->Clear();
 // NOW6->Text="ON";
  Read6->Click(); 

}
//---------------------------------------------------------------------------

void __fastcall TFormNet::CH6OFFClick(TObject *Sender)
{
   CheckBox_SendAsHex->Checked=True;
   MemoSend->Text="11 05 00 05 00 00 DF 5B" ;
   MemoSend->Refresh();
  int DataSize=0,Offset=0,lastOffset=0,recycleCount=0;
  bool SendOK=false;
  char *DataPtr=NULL;
  transmitting=true;
  MemoSend->Enabled=false;
  Edit_SendInterval->Enabled=false;
  ComboBox_Protocol->Enabled=false;
  IPEdit_IPAddress->Enabled=false;
  Edit_PortNUM->Enabled=false;
  CheckBox_FileInput->Enabled=false;
  cmBtn_NetConnect->Enabled=false;


  if(isNumeric(Edit_SendInterval->Text.c_str()))SendInterval=StrToInt(Edit_SendInterval->Text);
  else Edit_SendInterval->Text=IntToStr(SendInterval);
///////////////////////////////////////////////
  while(transmitting && ProgramRunning)
  {
    lastOffset=Offset;
    DataSize=Get_One_Line(MemoSend->Text.c_str(),Offset,&SendBuf[0],MAX_BUF_SIZE,CheckBox_SendAsHex->Checked);
    if(DataSize<1)
    { if(CheckBox_SendRecycled->Checked)
      { Offset=0;
        lastOffset=0;
        DataSize=Get_One_Line(MemoSend->Text.c_str(),Offset,&SendBuf[0],MAX_BUF_SIZE,CheckBox_SendAsHex->Checked);
        if(DataSize<1) break;
      }else break;
    }

    if(recycleCount++)MyAsyncSleep(SendInterval);

    show_hint("Sending data now...");
    if(CheckBox_SendAutoChecksum->Checked)
    { if(ChecksumMode==2)
      { SendBuf[DataSize++]=FixedCheckSum;
      }
      else
      { DataSize++;
        set_checksum(&SendBuf[0],DataSize,ChecksumMode);
      }
    }
    DataPtr=&SendBuf[0];
    if(MySocket->Protocol==cmTcpClient)
    { SendOK=MySocket->Send(DataPtr,DataSize);
    }
    else if(MySocket->Protocol==cmUDP)
    { if(!isNumeric(Edit_PortNUM2->Text.c_str()))
      { Application->MessageBox("Invalid object port number!","Warning",MB_OK+MB_ICONSTOP);
        break;
      }
      SendOK=MySocket->SendTo(IPEdit_IPAddress2->IPdata,str_to_int(Edit_PortNUM2->Text.c_str()),DataPtr,DataSize);
    }
    else if (MySocket->Protocol==cmTcpServer)
    { if(ComboBox_Connections->Items->Count<=1)
      { Application->MessageBox("No connecting object now!","Warning",MB_OK|MB_ICONWARNING);
        break;
      }
      else if(ComboBox_Connections->ItemIndex==0)
      { for(MySocket->Connections->node=MySocket->Connections->first;MySocket->Connections->node;MySocket->Connections->node=MySocket->Connections->node->next)
        { SendOK=MySocket->SendTo(MySocket->Connections->node->socket,DataPtr,DataSize);
        }
      }
      else
      { MySocket->Connections->node=MySocket->Connections->first;
        for(int i=1;i<ComboBox_Connections->ItemIndex;i++)
        { if(MySocket->Connections->node)MySocket->Connections->node=MySocket->Connections->node->next;
        }
        if(MySocket->Connections->node)
        { SendOK=MySocket->SendTo(MySocket->Connections->node->socket,DataPtr,DataSize);
        }
        else
        { Application->MessageBox("Invalid connecting object!","Warning",MB_OK|MB_ICONWARNING);
          //ComboBox_Connections->Items->Delete(ComboBox_Connections->ItemIndex);
          //ComboBox_Connections->ItemIndex=0;
          //不能这样简单的删除,需要同时删除内部结点
          break;
        }
      }
    }


    SendedSize+=DataSize;
    if(SendOK) {show_hint(String("Sent sucessfully ")+get_summary(MemoSend->Text.c_str(),lastOffset,Offset));}
    else {show_hint("Fail to send!"); break;}
    StaticTextSend->Caption=String("Send : ")+SendedSize;
     Application->ProcessMessages();
  }
///////////////////////////////////////
  Edit_SendInterval->Enabled=true;
  ComboBox_Protocol->Enabled=true;
  IPEdit_IPAddress->Enabled=true;
  Edit_PortNUM->Enabled=true;
  cmBtn_NetConnect->Enabled=true;
  MemoSend->Enabled=true;
  CheckBox_FileInput->Enabled=true;
  transmitting=false;
  if(CheckBox_ClearAfterSend->Checked)MemoSend->Clear();
  //NOW6->Text="OFF";
  Read6->Click(); 


}
//---------------------------------------------------------------------------

void __fastcall TFormNet::CH7ONClick(TObject *Sender)
{
   CheckBox_SendAsHex->Checked=True;
   MemoSend->Text="11 05 00 06 FF 00 6E AB" ;
   MemoSend->Refresh();
  int DataSize=0,Offset=0,lastOffset=0,recycleCount=0;
  bool SendOK=false;
  char *DataPtr=NULL;
  transmitting=true;
  MemoSend->Enabled=false;
  Edit_SendInterval->Enabled=false;
  ComboBox_Protocol->Enabled=false;
  IPEdit_IPAddress->Enabled=false;
  Edit_PortNUM->Enabled=false;
  CheckBox_FileInput->Enabled=false;
  cmBtn_NetConnect->Enabled=false;


  if(isNumeric(Edit_SendInterval->Text.c_str()))SendInterval=StrToInt(Edit_SendInterval->Text);
  else Edit_SendInterval->Text=IntToStr(SendInterval);
///////////////////////////////////////////////
  while(transmitting && ProgramRunning)
  {
    lastOffset=Offset;
    DataSize=Get_One_Line(MemoSend->Text.c_str(),Offset,&SendBuf[0],MAX_BUF_SIZE,CheckBox_SendAsHex->Checked);
    if(DataSize<1)
    { if(CheckBox_SendRecycled->Checked)
      { Offset=0;
        lastOffset=0;
        DataSize=Get_One_Line(MemoSend->Text.c_str(),Offset,&SendBuf[0],MAX_BUF_SIZE,CheckBox_SendAsHex->Checked);
        if(DataSize<1) break;
      }else break;
    }

    if(recycleCount++)MyAsyncSleep(SendInterval);

    show_hint("Sending data now...");
    if(CheckBox_SendAutoChecksum->Checked)
    { if(ChecksumMode==2)
      { SendBuf[DataSize++]=FixedCheckSum;
      }
      else
      { DataSize++;
        set_checksum(&SendBuf[0],DataSize,ChecksumMode);
      }
    }
    DataPtr=&SendBuf[0];
    if(MySocket->Protocol==cmTcpClient)
    { SendOK=MySocket->Send(DataPtr,DataSize);
    }
    else if(MySocket->Protocol==cmUDP)
    { if(!isNumeric(Edit_PortNUM2->Text.c_str()))
      { Application->MessageBox("Invalid object port number!","Warning",MB_OK+MB_ICONSTOP);
        break;
      }
      SendOK=MySocket->SendTo(IPEdit_IPAddress2->IPdata,str_to_int(Edit_PortNUM2->Text.c_str()),DataPtr,DataSize);
    }
    else if (MySocket->Protocol==cmTcpServer)
    { if(ComboBox_Connections->Items->Count<=1)
      { Application->MessageBox("No connecting object now!","Warning",MB_OK|MB_ICONWARNING);
        break;
      }
      else if(ComboBox_Connections->ItemIndex==0)
      { for(MySocket->Connections->node=MySocket->Connections->first;MySocket->Connections->node;MySocket->Connections->node=MySocket->Connections->node->next)
        { SendOK=MySocket->SendTo(MySocket->Connections->node->socket,DataPtr,DataSize);
        }
      }
      else
      { MySocket->Connections->node=MySocket->Connections->first;
        for(int i=1;i<ComboBox_Connections->ItemIndex;i++)
        { if(MySocket->Connections->node)MySocket->Connections->node=MySocket->Connections->node->next;
        }
        if(MySocket->Connections->node)
        { SendOK=MySocket->SendTo(MySocket->Connections->node->socket,DataPtr,DataSize);
        }
        else
        { Application->MessageBox("Invalid connecting object!","Warning",MB_OK|MB_ICONWARNING);
          //ComboBox_Connections->Items->Delete(ComboBox_Connections->ItemIndex);
          //ComboBox_Connections->ItemIndex=0;
          //不能这样简单的删除,需要同时删除内部结点
          break;
        }
      }
    }


    SendedSize+=DataSize;
    if(SendOK) {show_hint(String("Sent sucessfully ")+get_summary(MemoSend->Text.c_str(),lastOffset,Offset));}
    else {show_hint("Fail to send!"); break;}
    StaticTextSend->Caption=String("Send : ")+SendedSize;
     Application->ProcessMessages();
  }
///////////////////////////////////////
  Edit_SendInterval->Enabled=true;
  ComboBox_Protocol->Enabled=true;
  IPEdit_IPAddress->Enabled=true;
  Edit_PortNUM->Enabled=true;
  cmBtn_NetConnect->Enabled=true;
  MemoSend->Enabled=true;
  CheckBox_FileInput->Enabled=true;
  transmitting=false;
  if(CheckBox_ClearAfterSend->Checked)MemoSend->Clear();
 // NOW7->Text="ON";
  Read7->Click(); 

}
//---------------------------------------------------------------------------

void __fastcall TFormNet::CH7OFFClick(TObject *Sender)
{
   CheckBox_SendAsHex->Checked=True;
   MemoSend->Text="11 05 00 06 00 00 2F 5B" ;
   MemoSend->Refresh();
  int DataSize=0,Offset=0,lastOffset=0,recycleCount=0;
  bool SendOK=false;
  char *DataPtr=NULL;
  transmitting=true;
  MemoSend->Enabled=false;
  Edit_SendInterval->Enabled=false;
  ComboBox_Protocol->Enabled=false;
  IPEdit_IPAddress->Enabled=false;
  Edit_PortNUM->Enabled=false;
  CheckBox_FileInput->Enabled=false;
  cmBtn_NetConnect->Enabled=false;


  if(isNumeric(Edit_SendInterval->Text.c_str()))SendInterval=StrToInt(Edit_SendInterval->Text);
  else Edit_SendInterval->Text=IntToStr(SendInterval);
///////////////////////////////////////////////
  while(transmitting && ProgramRunning)
  {
    lastOffset=Offset;
    DataSize=Get_One_Line(MemoSend->Text.c_str(),Offset,&SendBuf[0],MAX_BUF_SIZE,CheckBox_SendAsHex->Checked);
    if(DataSize<1)
    { if(CheckBox_SendRecycled->Checked)
      { Offset=0;
        lastOffset=0;
        DataSize=Get_One_Line(MemoSend->Text.c_str(),Offset,&SendBuf[0],MAX_BUF_SIZE,CheckBox_SendAsHex->Checked);
        if(DataSize<1) break;
      }else break;
    }

    if(recycleCount++)MyAsyncSleep(SendInterval);

    show_hint("Sending data now...");
    if(CheckBox_SendAutoChecksum->Checked)
    { if(ChecksumMode==2)
      { SendBuf[DataSize++]=FixedCheckSum;
      }
      else
      { DataSize++;
        set_checksum(&SendBuf[0],DataSize,ChecksumMode);
      }
    }
    DataPtr=&SendBuf[0];
    if(MySocket->Protocol==cmTcpClient)
    { SendOK=MySocket->Send(DataPtr,DataSize);
    }
    else if(MySocket->Protocol==cmUDP)
    { if(!isNumeric(Edit_PortNUM2->Text.c_str()))
      { Application->MessageBox("Invalid object port number!","Warning",MB_OK+MB_ICONSTOP);
        break;
      }
      SendOK=MySocket->SendTo(IPEdit_IPAddress2->IPdata,str_to_int(Edit_PortNUM2->Text.c_str()),DataPtr,DataSize);
    }
    else if (MySocket->Protocol==cmTcpServer)
    { if(ComboBox_Connections->Items->Count<=1)
      { Application->MessageBox("No connecting object now!","Warning",MB_OK|MB_ICONWARNING);
        break;
      }
      else if(ComboBox_Connections->ItemIndex==0)
      { for(MySocket->Connections->node=MySocket->Connections->first;MySocket->Connections->node;MySocket->Connections->node=MySocket->Connections->node->next)
        { SendOK=MySocket->SendTo(MySocket->Connections->node->socket,DataPtr,DataSize);
        }
      }
      else
      { MySocket->Connections->node=MySocket->Connections->first;
        for(int i=1;i<ComboBox_Connections->ItemIndex;i++)
        { if(MySocket->Connections->node)MySocket->Connections->node=MySocket->Connections->node->next;
        }
        if(MySocket->Connections->node)
        { SendOK=MySocket->SendTo(MySocket->Connections->node->socket,DataPtr,DataSize);
        }
        else
        { Application->MessageBox("Invalid connecting object!","Warning",MB_OK|MB_ICONWARNING);
          //ComboBox_Connections->Items->Delete(ComboBox_Connections->ItemIndex);
          //ComboBox_Connections->ItemIndex=0;
          //不能这样简单的删除,需要同时删除内部结点
          break;
        }
      }
    }


    SendedSize+=DataSize;
    if(SendOK) {show_hint(String("Sent sucessfully ")+get_summary(MemoSend->Text.c_str(),lastOffset,Offset));}
    else {show_hint("Fail to send!"); break;}
    StaticTextSend->Caption=String("Send : ")+SendedSize;
     Application->ProcessMessages();
  }
///////////////////////////////////////
  Edit_SendInterval->Enabled=true;
  ComboBox_Protocol->Enabled=true;
  IPEdit_IPAddress->Enabled=true;
  Edit_PortNUM->Enabled=true;
  cmBtn_NetConnect->Enabled=true;
  MemoSend->Enabled=true;
  CheckBox_FileInput->Enabled=true;
  transmitting=false;
  if(CheckBox_ClearAfterSend->Checked)MemoSend->Clear();
 // NOW7->Text="OFF";
  Read7->Click(); 

}
//---------------------------------------------------------------------------

void __fastcall TFormNet::CH8ONClick(TObject *Sender)
{
   CheckBox_SendAsHex->Checked=True;
   MemoSend->Text="11 05 00 07 FF 00 3F 6B" ;
   MemoSend->Refresh();
  int DataSize=0,Offset=0,lastOffset=0,recycleCount=0;
  bool SendOK=false;
  char *DataPtr=NULL;
  transmitting=true;
  MemoSend->Enabled=false;
  Edit_SendInterval->Enabled=false;
  ComboBox_Protocol->Enabled=false;
  IPEdit_IPAddress->Enabled=false;
  Edit_PortNUM->Enabled=false;
  CheckBox_FileInput->Enabled=false;
  cmBtn_NetConnect->Enabled=false;


  if(isNumeric(Edit_SendInterval->Text.c_str()))SendInterval=StrToInt(Edit_SendInterval->Text);
  else Edit_SendInterval->Text=IntToStr(SendInterval);
///////////////////////////////////////////////
  while(transmitting && ProgramRunning)
  {
    lastOffset=Offset;
    DataSize=Get_One_Line(MemoSend->Text.c_str(),Offset,&SendBuf[0],MAX_BUF_SIZE,CheckBox_SendAsHex->Checked);
    if(DataSize<1)
    { if(CheckBox_SendRecycled->Checked)
      { Offset=0;
        lastOffset=0;
        DataSize=Get_One_Line(MemoSend->Text.c_str(),Offset,&SendBuf[0],MAX_BUF_SIZE,CheckBox_SendAsHex->Checked);
        if(DataSize<1) break;
      }else break;
    }

    if(recycleCount++)MyAsyncSleep(SendInterval);

    show_hint("Sending data now...");
    if(CheckBox_SendAutoChecksum->Checked)
    { if(ChecksumMode==2)
      { SendBuf[DataSize++]=FixedCheckSum;
      }
      else
      { DataSize++;
        set_checksum(&SendBuf[0],DataSize,ChecksumMode);
      }
    }
    DataPtr=&SendBuf[0];
    if(MySocket->Protocol==cmTcpClient)
    { SendOK=MySocket->Send(DataPtr,DataSize);
    }
    else if(MySocket->Protocol==cmUDP)
    { if(!isNumeric(Edit_PortNUM2->Text.c_str()))
      { Application->MessageBox("Invalid object port number!","Warning",MB_OK+MB_ICONSTOP);
        break;
      }
      SendOK=MySocket->SendTo(IPEdit_IPAddress2->IPdata,str_to_int(Edit_PortNUM2->Text.c_str()),DataPtr,DataSize);
    }
    else if (MySocket->Protocol==cmTcpServer)
    { if(ComboBox_Connections->Items->Count<=1)
      { Application->MessageBox("No connecting object now!","Warning",MB_OK|MB_ICONWARNING);
        break;
      }
      else if(ComboBox_Connections->ItemIndex==0)
      { for(MySocket->Connections->node=MySocket->Connections->first;MySocket->Connections->node;MySocket->Connections->node=MySocket->Connections->node->next)
        { SendOK=MySocket->SendTo(MySocket->Connections->node->socket,DataPtr,DataSize);
        }
      }
      else
      { MySocket->Connections->node=MySocket->Connections->first;
        for(int i=1;i<ComboBox_Connections->ItemIndex;i++)
        { if(MySocket->Connections->node)MySocket->Connections->node=MySocket->Connections->node->next;
        }
        if(MySocket->Connections->node)
        { SendOK=MySocket->SendTo(MySocket->Connections->node->socket,DataPtr,DataSize);
        }
        else
        { Application->MessageBox("Invalid connecting object!","Warning",MB_OK|MB_ICONWARNING);
          //ComboBox_Connections->Items->Delete(ComboBox_Connections->ItemIndex);
          //ComboBox_Connections->ItemIndex=0;
          //不能这样简单的删除,需要同时删除内部结点
          break;
        }
      }
    }


    SendedSize+=DataSize;
    if(SendOK) {show_hint(String("Sent sucessfully ")+get_summary(MemoSend->Text.c_str(),lastOffset,Offset));}
    else {show_hint("Fail to send!"); break;}
    StaticTextSend->Caption=String("Send : ")+SendedSize;
     Application->ProcessMessages();
  }
///////////////////////////////////////
  Edit_SendInterval->Enabled=true;
  ComboBox_Protocol->Enabled=true;
  IPEdit_IPAddress->Enabled=true;
  Edit_PortNUM->Enabled=true;
  cmBtn_NetConnect->Enabled=true;
  MemoSend->Enabled=true;
  CheckBox_FileInput->Enabled=true;
  transmitting=false;
  if(CheckBox_ClearAfterSend->Checked)MemoSend->Clear();
 // NOW8->Text="ON";
  Read8->Click(); 

}
//---------------------------------------------------------------------------

void __fastcall TFormNet::CH8OFFClick(TObject *Sender)
{
   CheckBox_SendAsHex->Checked=True;
   MemoSend->Text="11 05 00 07 00 00 7E 9B" ;
   MemoSend->Refresh();
  int DataSize=0,Offset=0,lastOffset=0,recycleCount=0;
  bool SendOK=false;
  char *DataPtr=NULL;
  transmitting=true;
  MemoSend->Enabled=false;
  Edit_SendInterval->Enabled=false;
  ComboBox_Protocol->Enabled=false;
  IPEdit_IPAddress->Enabled=false;
  Edit_PortNUM->Enabled=false;
  CheckBox_FileInput->Enabled=false;
  cmBtn_NetConnect->Enabled=false;


  if(isNumeric(Edit_SendInterval->Text.c_str()))SendInterval=StrToInt(Edit_SendInterval->Text);
  else Edit_SendInterval->Text=IntToStr(SendInterval);
///////////////////////////////////////////////
  while(transmitting && ProgramRunning)
  {
    lastOffset=Offset;
    DataSize=Get_One_Line(MemoSend->Text.c_str(),Offset,&SendBuf[0],MAX_BUF_SIZE,CheckBox_SendAsHex->Checked);
    if(DataSize<1)
    { if(CheckBox_SendRecycled->Checked)
      { Offset=0;
        lastOffset=0;
        DataSize=Get_One_Line(MemoSend->Text.c_str(),Offset,&SendBuf[0],MAX_BUF_SIZE,CheckBox_SendAsHex->Checked);
        if(DataSize<1) break;
      }else break;
    }

    if(recycleCount++)MyAsyncSleep(SendInterval);

    show_hint("Sending data now...");
    if(CheckBox_SendAutoChecksum->Checked)
    { if(ChecksumMode==2)
      { SendBuf[DataSize++]=FixedCheckSum;
      }
      else
      { DataSize++;
        set_checksum(&SendBuf[0],DataSize,ChecksumMode);
      }
    }
    DataPtr=&SendBuf[0];
    if(MySocket->Protocol==cmTcpClient)
    { SendOK=MySocket->Send(DataPtr,DataSize);
    }
    else if(MySocket->Protocol==cmUDP)
    { if(!isNumeric(Edit_PortNUM2->Text.c_str()))
      { Application->MessageBox("Invalid object port number!","Warning",MB_OK+MB_ICONSTOP);
        break;
      }
      SendOK=MySocket->SendTo(IPEdit_IPAddress2->IPdata,str_to_int(Edit_PortNUM2->Text.c_str()),DataPtr,DataSize);
    }
    else if (MySocket->Protocol==cmTcpServer)
    { if(ComboBox_Connections->Items->Count<=1)
      { Application->MessageBox("No connecting object now!","Warning",MB_OK|MB_ICONWARNING);
        break;
      }
      else if(ComboBox_Connections->ItemIndex==0)
      { for(MySocket->Connections->node=MySocket->Connections->first;MySocket->Connections->node;MySocket->Connections->node=MySocket->Connections->node->next)
        { SendOK=MySocket->SendTo(MySocket->Connections->node->socket,DataPtr,DataSize);
        }
      }
      else
      { MySocket->Connections->node=MySocket->Connections->first;
        for(int i=1;i<ComboBox_Connections->ItemIndex;i++)
        { if(MySocket->Connections->node)MySocket->Connections->node=MySocket->Connections->node->next;
        }
        if(MySocket->Connections->node)
        { SendOK=MySocket->SendTo(MySocket->Connections->node->socket,DataPtr,DataSize);
        }
        else
        { Application->MessageBox("Invalid connecting object!","Warning",MB_OK|MB_ICONWARNING);
          //ComboBox_Connections->Items->Delete(ComboBox_Connections->ItemIndex);
          //ComboBox_Connections->ItemIndex=0;
          //不能这样简单的删除,需要同时删除内部结点
          break;
        }
      }
    }


    SendedSize+=DataSize;
    if(SendOK) {show_hint(String("Sent sucessfully ")+get_summary(MemoSend->Text.c_str(),lastOffset,Offset));}
    else {show_hint("Fail to send!"); break;}
    StaticTextSend->Caption=String("Send : ")+SendedSize;
     Application->ProcessMessages();
  }
///////////////////////////////////////
  Edit_SendInterval->Enabled=true;
  ComboBox_Protocol->Enabled=true;
  IPEdit_IPAddress->Enabled=true;
  Edit_PortNUM->Enabled=true;
  cmBtn_NetConnect->Enabled=true;
  MemoSend->Enabled=true;
  CheckBox_FileInput->Enabled=true;
  transmitting=false;
  if(CheckBox_ClearAfterSend->Checked)MemoSend->Clear();
 // NOW8->Text="OFF";
  Read8->Click(); 

}
//---------------------------------------------------------------------------

void __fastcall TFormNet::SendClick(TObject *Sender)
{
 if(CheckBox_FileInput->Checked)
  { Net_BtnClick_SendFromFile(Sender);
    return;
  }

  if(transmitting)
  { transmitting=false;
    Btn_Send->Caption="发送";
    return;
  }
  if(!MySocket->Active)
  { char *msgError="网络尚未连接! \n\n发送失败！";
    Application->MessageBox(msgError,"Warning",MB_OK | MB_ICONSTOP);
    return;
  }

  int DataSize=0,Offset=0,lastOffset=0,recycleCount=0;
  bool SendOK=false;
  char *DataPtr=NULL;
  transmitting=true;
  MemoSend->Enabled=false;
  Edit_SendInterval->Enabled=false;
  ComboBox_Protocol->Enabled=false;
  IPEdit_IPAddress->Enabled=false;
  Edit_PortNUM->Enabled=false;
  CheckBox_FileInput->Enabled=false;
  cmBtn_NetConnect->Enabled=false;


  if(isNumeric(Edit_SendInterval->Text.c_str()))SendInterval=StrToInt(Edit_SendInterval->Text);
  else Edit_SendInterval->Text=IntToStr(SendInterval);
///////////////////////////////////////////////
  while(transmitting && ProgramRunning)
  {
    lastOffset=Offset;
    DataSize=Get_One_Line(MemoSend->Text.c_str(),Offset,&SendBuf[0],MAX_BUF_SIZE,CheckBox_SendAsHex->Checked);
    if(DataSize<1)
    { if(CheckBox_SendRecycled->Checked)
      { Offset=0;
        lastOffset=0;
        DataSize=Get_One_Line(MemoSend->Text.c_str(),Offset,&SendBuf[0],MAX_BUF_SIZE,CheckBox_SendAsHex->Checked);
        if(DataSize<1) break;
      }else break;
    }

    if(recycleCount++)MyAsyncSleep(SendInterval);

    show_hint("Sending data now...");
    if(CheckBox_SendAutoChecksum->Checked)
    { if(ChecksumMode==2)
      { SendBuf[DataSize++]=FixedCheckSum;
      }
      else
      { DataSize++;
        set_checksum(&SendBuf[0],DataSize,ChecksumMode);
      }
    }
    DataPtr=&SendBuf[0];
    if(MySocket->Protocol==cmTcpClient)
    { SendOK=MySocket->Send(DataPtr,DataSize);
    }
    else if(MySocket->Protocol==cmUDP)
    { if(!isNumeric(Edit_PortNUM2->Text.c_str()))
      { Application->MessageBox("Invalid object port number!","Warning",MB_OK+MB_ICONSTOP);
        break;
      }
      SendOK=MySocket->SendTo(IPEdit_IPAddress2->IPdata,str_to_int(Edit_PortNUM2->Text.c_str()),DataPtr,DataSize);
    }
    else if (MySocket->Protocol==cmTcpServer)
    { if(ComboBox_Connections->Items->Count<=1)
      { Application->MessageBox("No connecting object now!","Warning",MB_OK|MB_ICONWARNING);
        break;
      }
      else if(ComboBox_Connections->ItemIndex==0)
      { for(MySocket->Connections->node=MySocket->Connections->first;MySocket->Connections->node;MySocket->Connections->node=MySocket->Connections->node->next)
        { SendOK=MySocket->SendTo(MySocket->Connections->node->socket,DataPtr,DataSize);
        }
      }
      else
      { MySocket->Connections->node=MySocket->Connections->first;
        for(int i=1;i<ComboBox_Connections->ItemIndex;i++)
        { if(MySocket->Connections->node)MySocket->Connections->node=MySocket->Connections->node->next;
        }
        if(MySocket->Connections->node)
        { SendOK=MySocket->SendTo(MySocket->Connections->node->socket,DataPtr,DataSize);
        }
        else
        { Application->MessageBox("Invalid connecting object!","Warning",MB_OK|MB_ICONWARNING);
          //ComboBox_Connections->Items->Delete(ComboBox_Connections->ItemIndex);
          //ComboBox_Connections->ItemIndex=0;
          //不能这样简单的删除,需要同时删除内部结点
          break;
        }
      }
    }


    SendedSize+=DataSize;
    if(SendOK) {show_hint(String("Send successfully ")+get_summary(MemoSend->Text.c_str(),lastOffset,Offset));}
    else {show_hint("Fail to send!"); break;}
    StaticTextSend->Caption=String("Send : ")+SendedSize;
     Application->ProcessMessages();
  }
///////////////////////////////////////
  Edit_SendInterval->Enabled=true;
  ComboBox_Protocol->Enabled=true;
  IPEdit_IPAddress->Enabled=true;
  Edit_PortNUM->Enabled=true;
  cmBtn_NetConnect->Enabled=true;
  MemoSend->Enabled=true;
  CheckBox_FileInput->Enabled=true;
  transmitting=false;
  if(CheckBox_ClearAfterSend->Checked)MemoSend->Clear();

}
//---------------------------------------------------------------------------

void __fastcall TFormNet::Read1Click(TObject *Sender)
{
  CheckBox_SendAsHex->Checked=True;
  MemoSend->Text="11 01 00 00 00 01 FF 5A" ;
    MemoSend->Refresh();
  int DataSize=0,Offset=0,lastOffset=0,recycleCount=0;
  bool SendOK=false;
  char *DataPtr=NULL;
  transmitting=true;
  MemoSend->Enabled=false;
  Edit_SendInterval->Enabled=false;
  ComboBox_Protocol->Enabled=false;
  IPEdit_IPAddress->Enabled=false;
  Edit_PortNUM->Enabled=false;
  CheckBox_FileInput->Enabled=false;
  cmBtn_NetConnect->Enabled=false;


  if(isNumeric(Edit_SendInterval->Text.c_str()))SendInterval=StrToInt(Edit_SendInterval->Text);
  else Edit_SendInterval->Text=IntToStr(SendInterval);
///////////////////////////////////////////////
  while(transmitting && ProgramRunning)
  {
    lastOffset=Offset;
    DataSize=Get_One_Line(MemoSend->Text.c_str(),Offset,&SendBuf[0],MAX_BUF_SIZE,CheckBox_SendAsHex->Checked);
    if(DataSize<1)
    { if(CheckBox_SendRecycled->Checked)
      { Offset=0;
        lastOffset=0;
        DataSize=Get_One_Line(MemoSend->Text.c_str(),Offset,&SendBuf[0],MAX_BUF_SIZE,CheckBox_SendAsHex->Checked);
        if(DataSize<1) break;
      }else break;
    }

    if(recycleCount++)MyAsyncSleep(SendInterval);

    show_hint("Sending data now...");
    if(CheckBox_SendAutoChecksum->Checked)
    { if(ChecksumMode==2)
      { SendBuf[DataSize++]=FixedCheckSum;
      }
      else
      { DataSize++;
        set_checksum(&SendBuf[0],DataSize,ChecksumMode);
      }
    }
    DataPtr=&SendBuf[0];
    if(MySocket->Protocol==cmTcpClient)
    { SendOK=MySocket->Send(DataPtr,DataSize);
    }
    else if(MySocket->Protocol==cmUDP)
    { if(!isNumeric(Edit_PortNUM2->Text.c_str()))
      { Application->MessageBox("Invalid object port number!","Warning",MB_OK+MB_ICONSTOP);
        break;
      }
      SendOK=MySocket->SendTo(IPEdit_IPAddress2->IPdata,str_to_int(Edit_PortNUM2->Text.c_str()),DataPtr,DataSize);
    }
    else if (MySocket->Protocol==cmTcpServer)
    { if(ComboBox_Connections->Items->Count<=1)
      { Application->MessageBox("No connecting object now!","Warning",MB_OK|MB_ICONWARNING);
        break;
      }
      else if(ComboBox_Connections->ItemIndex==0)
      { for(MySocket->Connections->node=MySocket->Connections->first;MySocket->Connections->node;MySocket->Connections->node=MySocket->Connections->node->next)
        { SendOK=MySocket->SendTo(MySocket->Connections->node->socket,DataPtr,DataSize);
        }
      }
      else
      { MySocket->Connections->node=MySocket->Connections->first;
        for(int i=1;i<ComboBox_Connections->ItemIndex;i++)
        { if(MySocket->Connections->node)MySocket->Connections->node=MySocket->Connections->node->next;
        }
        if(MySocket->Connections->node)
        { SendOK=MySocket->SendTo(MySocket->Connections->node->socket,DataPtr,DataSize);
        }
        else
        { Application->MessageBox("Invalid connecting object!","Warning",MB_OK|MB_ICONWARNING);
          //ComboBox_Connections->Items->Delete(ComboBox_Connections->ItemIndex);
          //ComboBox_Connections->ItemIndex=0;
          //不能这样简单的删除,需要同时删除内部结点
          break;
        }
      }
    }


    SendedSize+=DataSize;
    if(SendOK) {show_hint(String("Send sucessfully ")+get_summary(MemoSend->Text.c_str(),lastOffset,Offset));}
    else {show_hint("Fail to send!"); break;}
    StaticTextSend->Caption=String("Send")+SendedSize;
     Application->ProcessMessages();

  }
///////////////////////////////////////
  Edit_SendInterval->Enabled=true;
  ComboBox_Protocol->Enabled=true;
  IPEdit_IPAddress->Enabled=true;
  Edit_PortNUM->Enabled=true;
  cmBtn_NetConnect->Enabled=true;
  MemoSend->Enabled=true;
  CheckBox_FileInput->Enabled=true;
  transmitting=false;
  if(CheckBox_ClearAfterSend->Checked)MemoSend->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TFormNet::Read2Click(TObject *Sender)
{
  CheckBox_SendAsHex->Checked=True;
  MemoSend->Text="11 01 00 01 00 01 AE 9A" ;
   MemoSend->Refresh();
  int DataSize=0,Offset=0,lastOffset=0,recycleCount=0;
  bool SendOK=false;
  char *DataPtr=NULL;
  transmitting=true;
  MemoSend->Enabled=false;
  Edit_SendInterval->Enabled=false;
  ComboBox_Protocol->Enabled=false;
  IPEdit_IPAddress->Enabled=false;
  Edit_PortNUM->Enabled=false;
  CheckBox_FileInput->Enabled=false;
  cmBtn_NetConnect->Enabled=false;


  if(isNumeric(Edit_SendInterval->Text.c_str()))SendInterval=StrToInt(Edit_SendInterval->Text);
  else Edit_SendInterval->Text=IntToStr(SendInterval);
///////////////////////////////////////////////
  while(transmitting && ProgramRunning)
  {
    lastOffset=Offset;
    DataSize=Get_One_Line(MemoSend->Text.c_str(),Offset,&SendBuf[0],MAX_BUF_SIZE,CheckBox_SendAsHex->Checked);
    if(DataSize<1)
    { if(CheckBox_SendRecycled->Checked)
      { Offset=0;
        lastOffset=0;
        DataSize=Get_One_Line(MemoSend->Text.c_str(),Offset,&SendBuf[0],MAX_BUF_SIZE,CheckBox_SendAsHex->Checked);
        if(DataSize<1) break;
      }else break;
    }

    if(recycleCount++)MyAsyncSleep(SendInterval);

    show_hint("Sending data now...");
    if(CheckBox_SendAutoChecksum->Checked)
    { if(ChecksumMode==2)
      { SendBuf[DataSize++]=FixedCheckSum;
      }
      else
      { DataSize++;
        set_checksum(&SendBuf[0],DataSize,ChecksumMode);
      }
    }
    DataPtr=&SendBuf[0];
    if(MySocket->Protocol==cmTcpClient)
    { SendOK=MySocket->Send(DataPtr,DataSize);
    }
    else if(MySocket->Protocol==cmUDP)
    { if(!isNumeric(Edit_PortNUM2->Text.c_str()))
      { Application->MessageBox("Invalid object port number!","Warning",MB_OK+MB_ICONSTOP);
        break;
      }
      SendOK=MySocket->SendTo(IPEdit_IPAddress2->IPdata,str_to_int(Edit_PortNUM2->Text.c_str()),DataPtr,DataSize);
    }
    else if (MySocket->Protocol==cmTcpServer)
    { if(ComboBox_Connections->Items->Count<=1)
      { Application->MessageBox("No connecting object now!","Warning",MB_OK|MB_ICONWARNING);
        break;
      }
      else if(ComboBox_Connections->ItemIndex==0)
      { for(MySocket->Connections->node=MySocket->Connections->first;MySocket->Connections->node;MySocket->Connections->node=MySocket->Connections->node->next)
        { SendOK=MySocket->SendTo(MySocket->Connections->node->socket,DataPtr,DataSize);
        }
      }
      else
      { MySocket->Connections->node=MySocket->Connections->first;
        for(int i=1;i<ComboBox_Connections->ItemIndex;i++)
        { if(MySocket->Connections->node)MySocket->Connections->node=MySocket->Connections->node->next;
        }
        if(MySocket->Connections->node)
        { SendOK=MySocket->SendTo(MySocket->Connections->node->socket,DataPtr,DataSize);
        }
        else
        { Application->MessageBox("Invalid connecting object!","Warning",MB_OK|MB_ICONWARNING);
          //ComboBox_Connections->Items->Delete(ComboBox_Connections->ItemIndex);
          //ComboBox_Connections->ItemIndex=0;
          //不能这样简单的删除,需要同时删除内部结点
          break;
        }
      }
    }


    SendedSize+=DataSize;
    if(SendOK) {show_hint(String("Send sucessfully ")+get_summary(MemoSend->Text.c_str(),lastOffset,Offset));}
    else {show_hint("Fail to send!"); break;}
    StaticTextSend->Caption=String("Send")+SendedSize;
     Application->ProcessMessages();

  }
///////////////////////////////////////
  Edit_SendInterval->Enabled=true;
  ComboBox_Protocol->Enabled=true;
  IPEdit_IPAddress->Enabled=true;
  Edit_PortNUM->Enabled=true;
  cmBtn_NetConnect->Enabled=true;
  MemoSend->Enabled=true;
  CheckBox_FileInput->Enabled=true;
  transmitting=false;
  if(CheckBox_ClearAfterSend->Checked)MemoSend->Clear();    
}
//---------------------------------------------------------------------------

void __fastcall TFormNet::Read3Click(TObject *Sender)
{
  CheckBox_SendAsHex->Checked=True;
  MemoSend->Text="11 01 00 02 00 01 5E 9A" ;
   MemoSend->Refresh();
  int DataSize=0,Offset=0,lastOffset=0,recycleCount=0;
  bool SendOK=false;
  char *DataPtr=NULL;
  transmitting=true;
  MemoSend->Enabled=false;
  Edit_SendInterval->Enabled=false;
  ComboBox_Protocol->Enabled=false;
  IPEdit_IPAddress->Enabled=false;
  Edit_PortNUM->Enabled=false;
  CheckBox_FileInput->Enabled=false;
  cmBtn_NetConnect->Enabled=false;


  if(isNumeric(Edit_SendInterval->Text.c_str()))SendInterval=StrToInt(Edit_SendInterval->Text);
  else Edit_SendInterval->Text=IntToStr(SendInterval);
///////////////////////////////////////////////
  while(transmitting && ProgramRunning)
  {
    lastOffset=Offset;
    DataSize=Get_One_Line(MemoSend->Text.c_str(),Offset,&SendBuf[0],MAX_BUF_SIZE,CheckBox_SendAsHex->Checked);
    if(DataSize<1)
    { if(CheckBox_SendRecycled->Checked)
      { Offset=0;
        lastOffset=0;
        DataSize=Get_One_Line(MemoSend->Text.c_str(),Offset,&SendBuf[0],MAX_BUF_SIZE,CheckBox_SendAsHex->Checked);
        if(DataSize<1) break;
      }else break;
    }

    if(recycleCount++)MyAsyncSleep(SendInterval);

    show_hint("Sending data now...");
    if(CheckBox_SendAutoChecksum->Checked)
    { if(ChecksumMode==2)
      { SendBuf[DataSize++]=FixedCheckSum;
      }
      else
      { DataSize++;
        set_checksum(&SendBuf[0],DataSize,ChecksumMode);
      }
    }
    DataPtr=&SendBuf[0];
    if(MySocket->Protocol==cmTcpClient)
    { SendOK=MySocket->Send(DataPtr,DataSize);
    }
    else if(MySocket->Protocol==cmUDP)
    { if(!isNumeric(Edit_PortNUM2->Text.c_str()))
      { Application->MessageBox("Invalid object port number!","Warning",MB_OK+MB_ICONSTOP);
        break;
      }
      SendOK=MySocket->SendTo(IPEdit_IPAddress2->IPdata,str_to_int(Edit_PortNUM2->Text.c_str()),DataPtr,DataSize);
    }
    else if (MySocket->Protocol==cmTcpServer)
    { if(ComboBox_Connections->Items->Count<=1)
      { Application->MessageBox("No connecting object now!","Warning",MB_OK|MB_ICONWARNING);
        break;
      }
      else if(ComboBox_Connections->ItemIndex==0)
      { for(MySocket->Connections->node=MySocket->Connections->first;MySocket->Connections->node;MySocket->Connections->node=MySocket->Connections->node->next)
        { SendOK=MySocket->SendTo(MySocket->Connections->node->socket,DataPtr,DataSize);
        }
      }
      else
      { MySocket->Connections->node=MySocket->Connections->first;
        for(int i=1;i<ComboBox_Connections->ItemIndex;i++)
        { if(MySocket->Connections->node)MySocket->Connections->node=MySocket->Connections->node->next;
        }
        if(MySocket->Connections->node)
        { SendOK=MySocket->SendTo(MySocket->Connections->node->socket,DataPtr,DataSize);
        }
        else
        { Application->MessageBox("Invalid connecting object!","Warning",MB_OK|MB_ICONWARNING);
          //ComboBox_Connections->Items->Delete(ComboBox_Connections->ItemIndex);
          //ComboBox_Connections->ItemIndex=0;
          //不能这样简单的删除,需要同时删除内部结点
          break;
        }
      }
    }


    SendedSize+=DataSize;
    if(SendOK) {show_hint(String("Send sucessfully ")+get_summary(MemoSend->Text.c_str(),lastOffset,Offset));}
    else {show_hint("Fail to send!"); break;}
    StaticTextSend->Caption=String("Send")+SendedSize;
     Application->ProcessMessages();

  }
///////////////////////////////////////
  Edit_SendInterval->Enabled=true;
  ComboBox_Protocol->Enabled=true;
  IPEdit_IPAddress->Enabled=true;
  Edit_PortNUM->Enabled=true;
  cmBtn_NetConnect->Enabled=true;
  MemoSend->Enabled=true;
  CheckBox_FileInput->Enabled=true;
  transmitting=false;
  if(CheckBox_ClearAfterSend->Checked)MemoSend->Clear();    
}
//---------------------------------------------------------------------------

void __fastcall TFormNet::Read4Click(TObject *Sender)
{
  CheckBox_SendAsHex->Checked=True;
  MemoSend->Text="11 01 00 03 00 01 0F 5A" ;
    MemoSend->Refresh();
  int DataSize=0,Offset=0,lastOffset=0,recycleCount=0;
  bool SendOK=false;
  char *DataPtr=NULL;
  transmitting=true;
  MemoSend->Enabled=false;
  Edit_SendInterval->Enabled=false;
  ComboBox_Protocol->Enabled=false;
  IPEdit_IPAddress->Enabled=false;
  Edit_PortNUM->Enabled=false;
  CheckBox_FileInput->Enabled=false;
  cmBtn_NetConnect->Enabled=false;


  if(isNumeric(Edit_SendInterval->Text.c_str()))SendInterval=StrToInt(Edit_SendInterval->Text);
  else Edit_SendInterval->Text=IntToStr(SendInterval);
///////////////////////////////////////////////
  while(transmitting && ProgramRunning)
  {
    lastOffset=Offset;
    DataSize=Get_One_Line(MemoSend->Text.c_str(),Offset,&SendBuf[0],MAX_BUF_SIZE,CheckBox_SendAsHex->Checked);
    if(DataSize<1)
    { if(CheckBox_SendRecycled->Checked)
      { Offset=0;
        lastOffset=0;
        DataSize=Get_One_Line(MemoSend->Text.c_str(),Offset,&SendBuf[0],MAX_BUF_SIZE,CheckBox_SendAsHex->Checked);
        if(DataSize<1) break;
      }else break;
    }

    if(recycleCount++)MyAsyncSleep(SendInterval);

    show_hint("Sending data now...");
    if(CheckBox_SendAutoChecksum->Checked)
    { if(ChecksumMode==2)
      { SendBuf[DataSize++]=FixedCheckSum;
      }
      else
      { DataSize++;
        set_checksum(&SendBuf[0],DataSize,ChecksumMode);
      }
    }
    DataPtr=&SendBuf[0];
    if(MySocket->Protocol==cmTcpClient)
    { SendOK=MySocket->Send(DataPtr,DataSize);
    }
    else if(MySocket->Protocol==cmUDP)
    { if(!isNumeric(Edit_PortNUM2->Text.c_str()))
      { Application->MessageBox("Invalid object port number!","Warning",MB_OK+MB_ICONSTOP);
        break;
      }
      SendOK=MySocket->SendTo(IPEdit_IPAddress2->IPdata,str_to_int(Edit_PortNUM2->Text.c_str()),DataPtr,DataSize);
    }
    else if (MySocket->Protocol==cmTcpServer)
    { if(ComboBox_Connections->Items->Count<=1)
      { Application->MessageBox("No connecting object now!","Warning",MB_OK|MB_ICONWARNING);
        break;
      }
      else if(ComboBox_Connections->ItemIndex==0)
      { for(MySocket->Connections->node=MySocket->Connections->first;MySocket->Connections->node;MySocket->Connections->node=MySocket->Connections->node->next)
        { SendOK=MySocket->SendTo(MySocket->Connections->node->socket,DataPtr,DataSize);
        }
      }
      else
      { MySocket->Connections->node=MySocket->Connections->first;
        for(int i=1;i<ComboBox_Connections->ItemIndex;i++)
        { if(MySocket->Connections->node)MySocket->Connections->node=MySocket->Connections->node->next;
        }
        if(MySocket->Connections->node)
        { SendOK=MySocket->SendTo(MySocket->Connections->node->socket,DataPtr,DataSize);
        }
        else
        { Application->MessageBox("Invalid connecting object!","Warning",MB_OK|MB_ICONWARNING);
          //ComboBox_Connections->Items->Delete(ComboBox_Connections->ItemIndex);
          //ComboBox_Connections->ItemIndex=0;
          //不能这样简单的删除,需要同时删除内部结点
          break;
        }
      }
    }


    SendedSize+=DataSize;
    if(SendOK) {show_hint(String("Send sucessfully ")+get_summary(MemoSend->Text.c_str(),lastOffset,Offset));}
    else {show_hint("Fail to send!"); break;}
    StaticTextSend->Caption=String("Send")+SendedSize;
     Application->ProcessMessages();

  }
///////////////////////////////////////
  Edit_SendInterval->Enabled=true;
  ComboBox_Protocol->Enabled=true;
  IPEdit_IPAddress->Enabled=true;
  Edit_PortNUM->Enabled=true;
  cmBtn_NetConnect->Enabled=true;
  MemoSend->Enabled=true;
  CheckBox_FileInput->Enabled=true;
  transmitting=false;
  if(CheckBox_ClearAfterSend->Checked)MemoSend->Clear();    
}
//---------------------------------------------------------------------------

void __fastcall TFormNet::Read5Click(TObject *Sender)
{
  CheckBox_SendAsHex->Checked=True;
  MemoSend->Text="11 01 00 04 00 01 BE 9B" ;
   MemoSend->Refresh();
  int DataSize=0,Offset=0,lastOffset=0,recycleCount=0;
  bool SendOK=false;
  char *DataPtr=NULL;
  transmitting=true;
  MemoSend->Enabled=false;
  Edit_SendInterval->Enabled=false;
  ComboBox_Protocol->Enabled=false;
  IPEdit_IPAddress->Enabled=false;
  Edit_PortNUM->Enabled=false;
  CheckBox_FileInput->Enabled=false;
  cmBtn_NetConnect->Enabled=false;


  if(isNumeric(Edit_SendInterval->Text.c_str()))SendInterval=StrToInt(Edit_SendInterval->Text);
  else Edit_SendInterval->Text=IntToStr(SendInterval);
///////////////////////////////////////////////
  while(transmitting && ProgramRunning)
  {
    lastOffset=Offset;
    DataSize=Get_One_Line(MemoSend->Text.c_str(),Offset,&SendBuf[0],MAX_BUF_SIZE,CheckBox_SendAsHex->Checked);
    if(DataSize<1)
    { if(CheckBox_SendRecycled->Checked)
      { Offset=0;
        lastOffset=0;
        DataSize=Get_One_Line(MemoSend->Text.c_str(),Offset,&SendBuf[0],MAX_BUF_SIZE,CheckBox_SendAsHex->Checked);
        if(DataSize<1) break;
      }else break;
    }

    if(recycleCount++)MyAsyncSleep(SendInterval);

    show_hint("Sending data now...");
    if(CheckBox_SendAutoChecksum->Checked)
    { if(ChecksumMode==2)
      { SendBuf[DataSize++]=FixedCheckSum;
      }
      else
      { DataSize++;
        set_checksum(&SendBuf[0],DataSize,ChecksumMode);
      }
    }
    DataPtr=&SendBuf[0];
    if(MySocket->Protocol==cmTcpClient)
    { SendOK=MySocket->Send(DataPtr,DataSize);
    }
    else if(MySocket->Protocol==cmUDP)
    { if(!isNumeric(Edit_PortNUM2->Text.c_str()))
      { Application->MessageBox("Invalid object port number!","Warning",MB_OK+MB_ICONSTOP);
        break;
      }
      SendOK=MySocket->SendTo(IPEdit_IPAddress2->IPdata,str_to_int(Edit_PortNUM2->Text.c_str()),DataPtr,DataSize);
    }
    else if (MySocket->Protocol==cmTcpServer)
    { if(ComboBox_Connections->Items->Count<=1)
      { Application->MessageBox("No connecting object now!","Warning",MB_OK|MB_ICONWARNING);
        break;
      }
      else if(ComboBox_Connections->ItemIndex==0)
      { for(MySocket->Connections->node=MySocket->Connections->first;MySocket->Connections->node;MySocket->Connections->node=MySocket->Connections->node->next)
        { SendOK=MySocket->SendTo(MySocket->Connections->node->socket,DataPtr,DataSize);
        }
      }
      else
      { MySocket->Connections->node=MySocket->Connections->first;
        for(int i=1;i<ComboBox_Connections->ItemIndex;i++)
        { if(MySocket->Connections->node)MySocket->Connections->node=MySocket->Connections->node->next;
        }
        if(MySocket->Connections->node)
        { SendOK=MySocket->SendTo(MySocket->Connections->node->socket,DataPtr,DataSize);
        }
        else
        { Application->MessageBox("Invalid connecting object!","Warning",MB_OK|MB_ICONWARNING);
          //ComboBox_Connections->Items->Delete(ComboBox_Connections->ItemIndex);
          //ComboBox_Connections->ItemIndex=0;
          //不能这样简单的删除,需要同时删除内部结点
          break;
        }
      }
    }


    SendedSize+=DataSize;
    if(SendOK) {show_hint(String("Send sucessfully ")+get_summary(MemoSend->Text.c_str(),lastOffset,Offset));}
    else {show_hint("Fail to send!"); break;}
    StaticTextSend->Caption=String("Send")+SendedSize;
     Application->ProcessMessages();

  }
///////////////////////////////////////
  Edit_SendInterval->Enabled=true;
  ComboBox_Protocol->Enabled=true;
  IPEdit_IPAddress->Enabled=true;
  Edit_PortNUM->Enabled=true;
  cmBtn_NetConnect->Enabled=true;
  MemoSend->Enabled=true;
  CheckBox_FileInput->Enabled=true;
  transmitting=false;
  if(CheckBox_ClearAfterSend->Checked)MemoSend->Clear();    
}
//---------------------------------------------------------------------------

void __fastcall TFormNet::Read6Click(TObject *Sender)
{
  CheckBox_SendAsHex->Checked=True;
  MemoSend->Text="11 01 00 05 00 01 EF 5B" ;
   MemoSend->Refresh();
  int DataSize=0,Offset=0,lastOffset=0,recycleCount=0;
  bool SendOK=false;
  char *DataPtr=NULL;
  transmitting=true;
  MemoSend->Enabled=false;
  Edit_SendInterval->Enabled=false;
  ComboBox_Protocol->Enabled=false;
  IPEdit_IPAddress->Enabled=false;
  Edit_PortNUM->Enabled=false;
  CheckBox_FileInput->Enabled=false;
  cmBtn_NetConnect->Enabled=false;


  if(isNumeric(Edit_SendInterval->Text.c_str()))SendInterval=StrToInt(Edit_SendInterval->Text);
  else Edit_SendInterval->Text=IntToStr(SendInterval);
///////////////////////////////////////////////
  while(transmitting && ProgramRunning)
  {
    lastOffset=Offset;
    DataSize=Get_One_Line(MemoSend->Text.c_str(),Offset,&SendBuf[0],MAX_BUF_SIZE,CheckBox_SendAsHex->Checked);
    if(DataSize<1)
    { if(CheckBox_SendRecycled->Checked)
      { Offset=0;
        lastOffset=0;
        DataSize=Get_One_Line(MemoSend->Text.c_str(),Offset,&SendBuf[0],MAX_BUF_SIZE,CheckBox_SendAsHex->Checked);
        if(DataSize<1) break;
      }else break;
    }

    if(recycleCount++)MyAsyncSleep(SendInterval);

    show_hint("Sending data now...");
    if(CheckBox_SendAutoChecksum->Checked)
    { if(ChecksumMode==2)
      { SendBuf[DataSize++]=FixedCheckSum;
      }
      else
      { DataSize++;
        set_checksum(&SendBuf[0],DataSize,ChecksumMode);
      }
    }
    DataPtr=&SendBuf[0];
    if(MySocket->Protocol==cmTcpClient)
    { SendOK=MySocket->Send(DataPtr,DataSize);
    }
    else if(MySocket->Protocol==cmUDP)
    { if(!isNumeric(Edit_PortNUM2->Text.c_str()))
      { Application->MessageBox("Invalid object port number!","Warning",MB_OK+MB_ICONSTOP);
        break;
      }
      SendOK=MySocket->SendTo(IPEdit_IPAddress2->IPdata,str_to_int(Edit_PortNUM2->Text.c_str()),DataPtr,DataSize);
    }
    else if (MySocket->Protocol==cmTcpServer)
    { if(ComboBox_Connections->Items->Count<=1)
      { Application->MessageBox("No connecting object now!","Warning",MB_OK|MB_ICONWARNING);
        break;
      }
      else if(ComboBox_Connections->ItemIndex==0)
      { for(MySocket->Connections->node=MySocket->Connections->first;MySocket->Connections->node;MySocket->Connections->node=MySocket->Connections->node->next)
        { SendOK=MySocket->SendTo(MySocket->Connections->node->socket,DataPtr,DataSize);
        }
      }
      else
      { MySocket->Connections->node=MySocket->Connections->first;
        for(int i=1;i<ComboBox_Connections->ItemIndex;i++)
        { if(MySocket->Connections->node)MySocket->Connections->node=MySocket->Connections->node->next;
        }
        if(MySocket->Connections->node)
        { SendOK=MySocket->SendTo(MySocket->Connections->node->socket,DataPtr,DataSize);
        }
        else
        { Application->MessageBox("Invalid connecting object!","Warning",MB_OK|MB_ICONWARNING);
          //ComboBox_Connections->Items->Delete(ComboBox_Connections->ItemIndex);
          //ComboBox_Connections->ItemIndex=0;
          //不能这样简单的删除,需要同时删除内部结点
          break;
        }
      }
    }


    SendedSize+=DataSize;
    if(SendOK) {show_hint(String("Send sucessfully ")+get_summary(MemoSend->Text.c_str(),lastOffset,Offset));}
    else {show_hint("Fail to send!"); break;}
    StaticTextSend->Caption=String("Send")+SendedSize;
     Application->ProcessMessages();

  }
///////////////////////////////////////
  Edit_SendInterval->Enabled=true;
  ComboBox_Protocol->Enabled=true;
  IPEdit_IPAddress->Enabled=true;
  Edit_PortNUM->Enabled=true;
  cmBtn_NetConnect->Enabled=true;
  MemoSend->Enabled=true;
  CheckBox_FileInput->Enabled=true;
  transmitting=false;
  if(CheckBox_ClearAfterSend->Checked)MemoSend->Clear();    
}
//---------------------------------------------------------------------------

void __fastcall TFormNet::Read7Click(TObject *Sender)
{
  CheckBox_SendAsHex->Checked=True;
  MemoSend->Text="11 01 00 06 00 01 1F 5B" ;
    MemoSend->Refresh();
  int DataSize=0,Offset=0,lastOffset=0,recycleCount=0;
  bool SendOK=false;
  char *DataPtr=NULL;
  transmitting=true;
  MemoSend->Enabled=false;
  Edit_SendInterval->Enabled=false;
  ComboBox_Protocol->Enabled=false;
  IPEdit_IPAddress->Enabled=false;
  Edit_PortNUM->Enabled=false;
  CheckBox_FileInput->Enabled=false;
  cmBtn_NetConnect->Enabled=false;


  if(isNumeric(Edit_SendInterval->Text.c_str()))SendInterval=StrToInt(Edit_SendInterval->Text);
  else Edit_SendInterval->Text=IntToStr(SendInterval);
///////////////////////////////////////////////
  while(transmitting && ProgramRunning)
  {
    lastOffset=Offset;
    DataSize=Get_One_Line(MemoSend->Text.c_str(),Offset,&SendBuf[0],MAX_BUF_SIZE,CheckBox_SendAsHex->Checked);
    if(DataSize<1)
    { if(CheckBox_SendRecycled->Checked)
      { Offset=0;
        lastOffset=0;
        DataSize=Get_One_Line(MemoSend->Text.c_str(),Offset,&SendBuf[0],MAX_BUF_SIZE,CheckBox_SendAsHex->Checked);
        if(DataSize<1) break;
      }else break;
    }

    if(recycleCount++)MyAsyncSleep(SendInterval);

    show_hint("Sending data now...");
    if(CheckBox_SendAutoChecksum->Checked)
    { if(ChecksumMode==2)
      { SendBuf[DataSize++]=FixedCheckSum;
      }
      else
      { DataSize++;
        set_checksum(&SendBuf[0],DataSize,ChecksumMode);
      }
    }
    DataPtr=&SendBuf[0];
    if(MySocket->Protocol==cmTcpClient)
    { SendOK=MySocket->Send(DataPtr,DataSize);
    }
    else if(MySocket->Protocol==cmUDP)
    { if(!isNumeric(Edit_PortNUM2->Text.c_str()))
      { Application->MessageBox("Invalid object port number!","Warning",MB_OK+MB_ICONSTOP);
        break;
      }
      SendOK=MySocket->SendTo(IPEdit_IPAddress2->IPdata,str_to_int(Edit_PortNUM2->Text.c_str()),DataPtr,DataSize);
    }
    else if (MySocket->Protocol==cmTcpServer)
    { if(ComboBox_Connections->Items->Count<=1)
      { Application->MessageBox("No connecting object now!","Warning",MB_OK|MB_ICONWARNING);
        break;
      }
      else if(ComboBox_Connections->ItemIndex==0)
      { for(MySocket->Connections->node=MySocket->Connections->first;MySocket->Connections->node;MySocket->Connections->node=MySocket->Connections->node->next)
        { SendOK=MySocket->SendTo(MySocket->Connections->node->socket,DataPtr,DataSize);
        }
      }
      else
      { MySocket->Connections->node=MySocket->Connections->first;
        for(int i=1;i<ComboBox_Connections->ItemIndex;i++)
        { if(MySocket->Connections->node)MySocket->Connections->node=MySocket->Connections->node->next;
        }
        if(MySocket->Connections->node)
        { SendOK=MySocket->SendTo(MySocket->Connections->node->socket,DataPtr,DataSize);
        }
        else
        { Application->MessageBox("Invalid connecting object!","Warning",MB_OK|MB_ICONWARNING);
          //ComboBox_Connections->Items->Delete(ComboBox_Connections->ItemIndex);
          //ComboBox_Connections->ItemIndex=0;
          //不能这样简单的删除,需要同时删除内部结点
          break;
        }
      }
    }


    SendedSize+=DataSize;
    if(SendOK) {show_hint(String("Send sucessfully ")+get_summary(MemoSend->Text.c_str(),lastOffset,Offset));}
    else {show_hint("Fail to send!"); break;}
    StaticTextSend->Caption=String("Send")+SendedSize;
     Application->ProcessMessages();

  }
///////////////////////////////////////
  Edit_SendInterval->Enabled=true;
  ComboBox_Protocol->Enabled=true;
  IPEdit_IPAddress->Enabled=true;
  Edit_PortNUM->Enabled=true;
  cmBtn_NetConnect->Enabled=true;
  MemoSend->Enabled=true;
  CheckBox_FileInput->Enabled=true;
  transmitting=false;
  if(CheckBox_ClearAfterSend->Checked)MemoSend->Clear();    
}
//---------------------------------------------------------------------------

void __fastcall TFormNet::Read8Click(TObject *Sender)
{
  CheckBox_SendAsHex->Checked=True;
  MemoSend->Text="11 01 00 07 00 01 4E 9B" ;
    MemoSend->Refresh();
  int DataSize=0,Offset=0,lastOffset=0,recycleCount=0;
  bool SendOK=false;
  char *DataPtr=NULL;
  transmitting=true;
  MemoSend->Enabled=false;
  Edit_SendInterval->Enabled=false;
  ComboBox_Protocol->Enabled=false;
  IPEdit_IPAddress->Enabled=false;
  Edit_PortNUM->Enabled=false;
  CheckBox_FileInput->Enabled=false;
  cmBtn_NetConnect->Enabled=false;


  if(isNumeric(Edit_SendInterval->Text.c_str()))SendInterval=StrToInt(Edit_SendInterval->Text);
  else Edit_SendInterval->Text=IntToStr(SendInterval);
///////////////////////////////////////////////
  while(transmitting && ProgramRunning)
  {
    lastOffset=Offset;
    DataSize=Get_One_Line(MemoSend->Text.c_str(),Offset,&SendBuf[0],MAX_BUF_SIZE,CheckBox_SendAsHex->Checked);
    if(DataSize<1)
    { if(CheckBox_SendRecycled->Checked)
      { Offset=0;
        lastOffset=0;
        DataSize=Get_One_Line(MemoSend->Text.c_str(),Offset,&SendBuf[0],MAX_BUF_SIZE,CheckBox_SendAsHex->Checked);
        if(DataSize<1) break;
      }else break;
    }

    if(recycleCount++)MyAsyncSleep(SendInterval);

    show_hint("Sending data now...");
    if(CheckBox_SendAutoChecksum->Checked)
    { if(ChecksumMode==2)
      { SendBuf[DataSize++]=FixedCheckSum;
      }
      else
      { DataSize++;
        set_checksum(&SendBuf[0],DataSize,ChecksumMode);
      }
    }
    DataPtr=&SendBuf[0];
    if(MySocket->Protocol==cmTcpClient)
    { SendOK=MySocket->Send(DataPtr,DataSize);
    }
    else if(MySocket->Protocol==cmUDP)
    { if(!isNumeric(Edit_PortNUM2->Text.c_str()))
      { Application->MessageBox("Invalid object port number!","Warning",MB_OK+MB_ICONSTOP);
        break;
      }
      SendOK=MySocket->SendTo(IPEdit_IPAddress2->IPdata,str_to_int(Edit_PortNUM2->Text.c_str()),DataPtr,DataSize);
    }
    else if (MySocket->Protocol==cmTcpServer)
    { if(ComboBox_Connections->Items->Count<=1)
      { Application->MessageBox("No connecting object now!","Warning",MB_OK|MB_ICONWARNING);
        break;
      }
      else if(ComboBox_Connections->ItemIndex==0)
      { for(MySocket->Connections->node=MySocket->Connections->first;MySocket->Connections->node;MySocket->Connections->node=MySocket->Connections->node->next)
        { SendOK=MySocket->SendTo(MySocket->Connections->node->socket,DataPtr,DataSize);
        }
      }
      else
      { MySocket->Connections->node=MySocket->Connections->first;
        for(int i=1;i<ComboBox_Connections->ItemIndex;i++)
        { if(MySocket->Connections->node)MySocket->Connections->node=MySocket->Connections->node->next;
        }
        if(MySocket->Connections->node)
        { SendOK=MySocket->SendTo(MySocket->Connections->node->socket,DataPtr,DataSize);
        }
        else
        { Application->MessageBox("Invalid connecting object!","Warning",MB_OK|MB_ICONWARNING);
          //ComboBox_Connections->Items->Delete(ComboBox_Connections->ItemIndex);
          //ComboBox_Connections->ItemIndex=0;
          //不能这样简单的删除,需要同时删除内部结点
          break;
        }
      }
    }


    SendedSize+=DataSize;
    if(SendOK) {show_hint(String("Send sucessfully ")+get_summary(MemoSend->Text.c_str(),lastOffset,Offset));}
    else {show_hint("Fail to send!"); break;}
    StaticTextSend->Caption=String("Send")+SendedSize;
     Application->ProcessMessages();

  }
///////////////////////////////////////
  Edit_SendInterval->Enabled=true;
  ComboBox_Protocol->Enabled=true;
  IPEdit_IPAddress->Enabled=true;
  Edit_PortNUM->Enabled=true;
  cmBtn_NetConnect->Enabled=true;
  MemoSend->Enabled=true;
  CheckBox_FileInput->Enabled=true;
  transmitting=false;
  if(CheckBox_ClearAfterSend->Checked)MemoSend->Clear();    
}
//---------------------------------------------------------------------------

