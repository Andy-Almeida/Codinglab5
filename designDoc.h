//This file is for documentation purposes only. It will be ignored by the compiler.
//Our Teaching Assistant will manually grade this file.

//Please make sure that you include the entire content of this file as comments.

/* Design Doc: communicate your thought process in English.
 
0. List of members who contributed to the implementation of this project:
   
   GROUP MEMBERS: Andy Almeida, Kao Saephan, Nicholas Valencia, Umaran Ahmadzai, Shanil Prasad
 
1. Describe your algorithm for the sentenceSplitter( ) function in pseudocode.
   void sentenceSplitter (string& fname, vector<string>& sentences) {
      //tokenize sentences by delimiters period, question mark, period + endquotes, questionmark + endquotes, newline char ".", "?", "."", "$" 

      while (not end of fname) {
         tokenize sentences by delimiters
         sentences.push_back(tokenSentences)
      }
      //probably is more to this


2. Describe your algorithm for the wordpairMapping( ) function in pseudocode.
   void wordpairMapping (vector<string>& sentences, map<pair<string,string>, int>& wordpairFreq_map) {
      while(sentence not end){

         for(each index of sentence) {
            tokenize each sentence into words
            store in vector<string> tokenwords

            for(iterate through tokenwords){
               store current word

               for(iterate through tokenwords) {
                  compare currentword to all other words

                  if(no match){
                     
                     if(map doesnt contain pair){
                        add pair
                     }

                     else if(map contains pair, update pair count){
                        update pair count
                     }
                  }
               }
            }
         }
      }
   }
   //probably is more to this or can be optimized


   //THESE NEXT TWO IS ONLY FOR OUR GROUP AND IS NOT PART OF THE DESIGN DOC REQUIREMENT
   //REPEAT THESE NEXT 2 ARE NOT PART OF THE ASSIGNMENT 

   3. freqWordpairMmap(map< pair<string,string>, int> &wordpairFreq_map, multimap<int, pair<string, string> > &freqWordpair_mmap ) {
         //flip pair and count in one loop

         for (each index in wordpairFreq_map) {
            //first part of a map is the "key" and the second part is the "value"
            //we can update the value but not the key. changing the key requires removal and insertion
            get the int value and pair then insert into freqwordPair_map with int as the key and pair as the value 
         }
      }

   4. void printWordpairs(multimap<int, pair<string, string> > &freqWordpair_multimap, string outFname, int topCnt, int botCnt) {
         //all words are already in ascending order
         use multimap's iterator to print least occurance
         use multimap's reverse iterator to print most occurance 
      }   
   

*/
