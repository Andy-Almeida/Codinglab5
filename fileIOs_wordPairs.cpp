/*
Cpp file, Algorithm Implementation
Team: Andy Almeida, Kao Saephan, Nicholas Valencia, Umaran Ahmadzai, Shanil Prasad
*/

#include "fileIOs_wordPairs.h"

bool sentenceSplitter( string& fname, vector<string>& sentences){
    ifstream inFS; //input file stream
    string entireSpeech;

    inFS.open(fname); //opens the file

    //converts the file contents into a string
    stringstream readingSpeech;
    readingSpeech << inFS.rdbuf();
    entireSpeech = readingSpeech.str();

    string const delimiters{".?\n"};

    int position = 0;
    int begin = 0;
    
    //splits the contents of the file into sentences
    while ((begin = entireSpeech.find_first_not_of(delimiters, position)) != (int)string::npos ){
        while (entireSpeech[begin] == ' ' || entireSpeech[begin] == '"') {
            begin = begin + 1;
        }
        
        position = entireSpeech.find_first_of(delimiters, begin + 1);

        sentences.push_back(entireSpeech.substr(begin , position - begin));
    }
    
    //dont need this for-loop, its just for debugging/testing
    for (string currString: sentences){
        cout << currString << endl;
    }
    
    inFS.close();
    return true;
}//End of bool sentenceSplitter



void wordpairMapping( vector<string>& sentences, map< pair<string,string>, int> &wordpairFreq_map){
    fstream fs(filename);
    map<string, int> mp;
    string word;
    while (fs >> word)
    {
        if (!mp.count(word))
            mp.insert(make_pair(word, 1));
        else
            mp[word]++;
    }
    fs.close();
    for (map<string, int> :: iterator p = mp.begin();
         p != mp.end(); p++)
    {
        if (p->second == 1)
            cout << p->first << endl;
    }
   
}//End void wordpairMapping


void freqWordpairMmap(map< pair<string,string>, int> &wordpairFreq_map, multimap<int, pair<string, string> > &freqWordpair_mmap ){
    map< pair<string, string>, int>::iterator it = wordpairFreq_map.begin();
    //pair of strings 
    pair<string, string> p1;
    while(it != wordpairFreq_map.end()){
        //freq is the frequency of the word pair
        int freq = it->second;
        p1 = it->first;
        freqWordpair_mmap.emplace(freq,p1);
        it++;
    }
}//End of void freqWordpairMmap


void printWordpairs(multimap<int, pair<string, string> > &freqWordpair_multimap, string outFname, int topCnt, int botCnt){
   ofstream outF;
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
}//End of void printWordpairs
