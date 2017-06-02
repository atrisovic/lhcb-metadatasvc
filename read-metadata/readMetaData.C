#include <map>
#include <string>
#include <stdio.h>
#include "TTree.h"
#include "TFile.h"

void readMetaData(const char* inputfile)
{
    TFile mFile(inputfile);
    std::map<std::string, std::string>* newMap1 =(std::map<std::string, std::string>*) mFile.Get("info");
    std::map<std::string, std::string> newMap=*newMap1;
    std::map<std::string, std::string>::iterator iter;
 
    std::stringstream buffer;
    
    for(iter=newMap.begin(); iter!=newMap.end(); ++iter){
       buffer << iter->first << " : " << iter->second << endl;
       cout << iter->first << " : " << iter->second << endl;
    }
 
    TRootHelpDialog *dialog = new TRootHelpDialog(gClient->GetRoot(), "Info", 550,650);
    dialog-> SetText(buffer.str().c_str());
    dialog-> Popup();
 
}
