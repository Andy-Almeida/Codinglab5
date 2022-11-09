/*
Cpp file, Algorithm Implementation
Team: Andy Almeida, Kao Saephan, Nicholas Valencia, Umaran Ahmadzai, Shanil Prasad

*/


#include "fileIOs_wordPairs.h"

bool sentenceSplitter( string& fname, vector<string>& sentences){
    ifstream inFS; //input file stream
    string entireSpeech;

    inFS.open(fname); //opens the file
    
    //reading in entire file
    stringstream readingSpeech;
    readingSpeech << inFS.rdbuf();
    entireSpeech = readingSpeech.str();
    
    //split file into sentences
    string const delimiters{".?\n"};
    int position = 0;
    int begin = 0;
    
    while ((begin = entireSpeech.find_first_not_of(delimiters, position)) != (int)string::npos ){
        
        while (entireSpeech[begin] == ' ' || entireSpeech[begin] == '"') {
            begin = begin + 1;
        }
        
        position = entireSpeech.find_first_of(delimiters, begin + 1);

        sentences.push_back(entireSpeech.substr(begin , position - begin));
    }

    inFS.close(); //close file
    
    return true;

}


void wordpairMapping( vector<string>& sentences, map< pair<string,string>, int> &wordpairFreq_map){
   //iterate over sentences
    for (int i = 0; i < (int)sentences.size(); i++){
       //lower case everything
       transform(sentences.at(i).begin(), sentences.at(i).end(), sentences.at(i).begin(), ::tolower);
        
       //tokenize sentences
       stringstream check1(sentences.at(i));
       string tempString;
       vector<string> words;
       while (getline(check1, tempString, ' ')){
            words.push_back(tempString);
       }
        
       //sort tokens lexigraphically 
       sort(words.begin(), words.end());
        
        vector<string> uniqueWords;
        for(int n = 0; n < (int)words.size(); n++){
            if(n==0){
                uniqueWords.push_back(words.at(n));
            }
            else if(n!=0 && find(uniqueWords.begin(),uniqueWords.end(),words.at(n))==uniqueWords.end()){
                uniqueWords.push_back(words.at(n));
            }
        }
        //make all possible pairs
        vector<pair<string,string>> tempSet;
        for (int j = 0; j < (int)uniqueWords.size() - 1; j++ ){
            for (int k = j + 1; k < (int)uniqueWords.size(); k++){
                if(words.at(j)!=uniqueWords.at(k)){
                    tempSet.push_back(pair<string,string>(uniqueWords.at(j),uniqueWords.at(k)));
                }
            }
        }
        
       //check if the pair is in the wordpairFreq_map then add or update count
       for(int l = 0; l < (int)tempSet.size(); l++){
            if(wordpairFreq_map.find(tempSet.at(l)) == wordpairFreq_map.end()){ //if not already in map
                wordpairFreq_map.emplace(tempSet.at(l),1);
            }
            else{ //pair already in map
                wordpairFreq_map.at(tempSet.at(l))++;
            }
       }
    }
}


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
}


void printWordpairs(multimap<int, pair<string, string> > &freqWordpair_multimap, string outFname, int topCnt, int botCnt){
  //open output file
   ofstream outF;
   outF.open(outFname);
   
   //declare necessary iterators
   multimap<int, pair<string,string> >::reverse_iterator endBound1;
   multimap<int, pair<string,string> >::reverse_iterator atlastEnd;
   multimap<int, pair<string,string> >::iterator atBegTop;
   multimap<int, pair<string,string> >::iterator endBound2;
   
   //set end bounds for top count iterator
   endBound1 = freqWordpair_multimap.rbegin();
   advance(endBound1, topCnt);
   
   //find top freq of pairs
   for (atlastEnd = freqWordpair_multimap.rbegin(); atlastEnd != endBound1; ++atlastEnd){
       cout << "<" << atlastEnd->second.first << "," << atlastEnd->second.second << ">: " << atlastEnd->first << endl; 
       outF << "<" << atlastEnd->second.first << "," << atlastEnd->second.second << ">: " << atlastEnd->first << endl;
   }
   
   //set end bounds for bottom count interator
   endBound2 = freqWordpair_multimap.begin();
   advance(endBound2, botCnt);
   
   //find bottom freq of pairs
   for (atBegTop = freqWordpair_multimap.begin(); atBegTop != endBound2; ++atBegTop){
       cout << "<" << atBegTop->second.first << "," << atBegTop->second.second << ">: " << atBegTop->first << endl; 
       outF << "<" << atBegTop->second.first << "," << atBegTop->second.second << ">: " << atBegTop->first << endl;
   }
   
   outF.close(); //close output file
}
