/*
Header File
Team: Andy Almeida, Kao Saephan, Nicholas Valencia, Umaran Ahmadzai, Shanil Prasad

*/


#ifndef fileIOs_wordPairs_h
#define fileIOs_wordPairs_h

//include libraries
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <utility>
#include <sstream>

using namespace std;

bool sentenceSplitter( string& fname, vector<string>& sentences);

void wordpairMapping( vector<string>& sentences, map< pair<string,string>, int> &wordpairFreq_map);

void freqWordpairMmap(map< pair<string,string>, int> &wordpairFreq_map, multimap<int, pair<string, string> > &freqWordpair_mmap );

void printWordpairs(multimap<int, pair<string, string> > &freqWordpair_multimap, string outFname, int topCnt, int botCnt);

#endif 
