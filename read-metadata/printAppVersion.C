#include<map>
#include <string>
#include <stdio.h>
#include "TFile.h"
 
int printAppVersion(const char* inputfile)
{
   TFile mFile(inputfile);
   std::map<std::string, std::string>* newMap1 =(std::map<std::string, std::string>*) mFile.Get("info");
   std::map<std::string, std::string> newMap=*newMap1;
   cout << newMap["ApplicationMgr.AppName"] +" "+ newMap["ApplicationMgr.AppVersion"] << endl;
   return 0;
}
