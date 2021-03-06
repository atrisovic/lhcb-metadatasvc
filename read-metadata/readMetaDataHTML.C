#include <stdio.h>
#include <map>
#include <string>
#include "TTree.h"
#include "TFile.h"
 
#include "TDatime.h"
#include "TTimeStamp.h"
#include "TGComboBox.h"
#include "TGNumberEntry.h"
#include "TGLabel.h"
#include "TGColorSelect.h"
#include "TGHtml.h"
#include "TApplication.h"
#include "TROOT.h"
#include "TColor.h"
 
 
class Widget {
private:
    TString        fHeader;       // HTML header
    TString        fFooter;       // HTML footer
    TString        fHtml_text;    // output HTML string
 
    TGMainFrame    *fMain;       // main frame
    TGHtml         *fHtml;       // html widget to display HTML calendar
public:
    void MakeHeader();
    void MakeFooter();
    Widget(std::map<std::string, std::string> md);
    virtual ~Widget();
    TString Html() const {return fHtml_text; }
    ClassDef(Widget, 0);
};
void Widget::MakeHeader()
{
   fHeader = "<html><head><title>Meta Data Viewer</title></head>";
   fHeader += "<body>\n";
   fHeader += "<center><H2>Meta Data Viewer</H2></center>";
}
void Widget::MakeFooter()
{
   fFooter = "</body></html>";
}
 
Widget::Widget(std::map<std::string, std::string> md)
{
    MakeHeader();
    MakeFooter();
 
    std::map<std::string, std::string>::iterator iter;
 
        fHtml_text = fHeader;
    fHtml_text += "<table border='1' style='width:100%'>";
         
    for(iter=md.begin(); iter!=md.end(); iter++){
        fHtml_text +="<tr><td><font color='black'><b>";
        fHtml_text += iter->first; 
        fHtml_text+="</b></font></td><td><font color='blue'><b>"; 
        fHtml_text+=iter->second;
        fHtml_text+="</b></font></td></tr>";            
    }
    fHtml_text += "</table>";
    fHtml_text += fFooter;
     
    // Main  window.
    fMain = new TGMainFrame(gClient->GetRoot(), 10, 10, kVerticalFrame);
    fMain->SetCleanup(kDeepCleanup); // delete all subframes on exit
    // create HTML widget
    fHtml = new TGHtml(fMain, 1, 1);
    fMain->AddFrame(fHtml, new TGLayoutHints(kLHintsExpandX | kLHintsExpandY,
                                    5, 5, 2, 2));
    // parse HTML context of HTML calendar table
    fHtml->ParseText((char*)fHtml_text.Data());
    // terminate ROOT session when window is closed
    fMain->Connect("CloseWindow()", "TApplication", gApplication, "Terminate()");
    fMain->DontCallClose();
 
    fMain->MapSubwindows();
    fMain->Resize(700, 700);
 
    // set  minimum size of main window
    fMain->SetWMSizeHints(fMain->GetDefaultWidth(), fMain->GetDefaultHeight(),
                 1000, 1000, 0 ,0);
    fMain->MapRaised();
}
Widget::~Widget()
{
    delete fMain;
}
 
class MetaData1{
private:
    std::map <std::string, std::string> m;
public:
    MetaData1();
        std::map <std::string, std::string> getMetaData1();
    virtual ~MetaData1(){};
    ClassDef(MetaData1, 0);
};
MetaData1::MetaData1( )
{
}
std::map <std::string, std::string> MetaData1::getMetaData1()
{
    return m;
}
 
void readMetaData(const char* inputfile)
{
   TFile mFile(inputfile);
   std::map<std::string, std::string>* mdMap =(std::map<std::string, std::string>*) mFile.Get("info");
   std::map<std::string, std::string> newMap=*mdMap;
   cout << "Size: " << newMap.size() << endl;
   new Widget(newMap);
}
