/*
Cpp file, Algorithm Implementation
Team: Andy Almeida, Kao Saephan, Nicholas Valencia, Umaran Ahmadzai, Shanil Prasad

*/


#include "fileIOs_wordPairs.h"

namespace NS_FILEIOWORDPAIRS{

void sentenceSplitter( string& fname, vector<string>& sentences){

}


void wordpairMapping( vector<string>& sentences, map< pair<string,string>, int> &wordpairFreq_map){
   
}


void freqWordpairMmap(map< pair<string,string>, int> &wordpairFreq_map, multimap<int, pair<string, string> > &freqWordpair_mmap ){
    
}


void printWordpairs(multimap<int, pair<string, string> > &freqWordpair_multimap, string outFname, int topCnt, int botCnt){
   
}
   ofstreamoutF;
   outF.open(outFname);
   multimap<int, pair<string,string> >::reverse_iterator atLastEnd=freqWordpair_multimap.rbegin();
   multimap<int, pair<string,string> >::reverse_iterator atBegTop;

   advance (atBegTop,topCnt);
   atBegTop=freqWordpair_multimap.rbegin();
   //forloop
   for (atBegTop; atBegTop!=atLastEnd; atBegTop++) 
   {
      stringstream firstWord(atBegTop->second.first);
      stringstream secondWord(atBegTop->second.second);
      int trackerC=0;
      trackerC=atBegTop->first;
      outF << firstWord.str() << ", " << secondWord.str() << ">: " << trackerC << endl;
   }
   multimap<int, pair<string, string> >::iterator ending = freqWordpair_multimap.begin();
   multimap<int, pair<string, string> >::iterator beg;


   advance (ending, botCnt);
   beg=freqWordpair_multimap.begin();
   //forloop
   for (beg; beg!=ending; beg++) 
   {
      stringstream firstWord(beg->second.first);
      stringstream secondWord(beg->second.second);
      int trackerC=0;
      trackerC=beg->first;//for counter
      cout << "<" << firstWord.str() << ", " << secondWord.str() << ">: " << trackerC << endl;
   }

   outF.close();
}
