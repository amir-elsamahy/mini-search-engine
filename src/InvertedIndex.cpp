#include<iostream>
#include<string>
#include<sstream>
#include<unordered_map>
#include<vector>
#include<unordered_set>
#include"../include/Utils.h"
#include"../include/InvertedIndex.h"
#include <algorithm>


using namespace std;

                                                                //////// prepare ////////


  void InvertedIndex::addDocumentsimple(int id,const string& text){
      vector <string> words=tokenization(text);

      for(const string& word: words){
        index[word].insert(id);
      }
  }
    



  void InvertedIndex:: addDocumentwithfreq(int id,const std::string& text){
      vector <string> words =tokenization(text);
      for(const string& word :words){
        index2[word][id]++;
        
      }
  }



                                                                      //////// search ////////


  unordered_set<int> InvertedIndex:: search(const string& query){
    string cleanword;
    for(char c: query){
      if(isalnum(c)){
        cleanword+= tolower(c);
      }
    }
    if (index.find(cleanword) != index.end()){
      return index[cleanword];

    }
    else{
      cout<<"result for \""<<query<<"\""<<" => NONE"<<endl;
      return {};

    }
  }


///

void InvertedIndex::Gsearch(const string& query) {
    string word;
    stringstream ss(query);

    while(ss >> word) {
        string cleanword;
        for(char c: word) {
            if(isalnum(c)|| c == '+' || c == '#') {      
                cleanword += tolower(c);
            }
        }
        cout<<"*************************************"<<endl;
        cout << "Result for \"" << word << "\" → ";

        if(index.find(cleanword) != index.end()) {
            cout << "{";
            for(int id : index[cleanword]) {
                cout << " " << id << " ";
            }
            cout << "}";
        } else {
            cout << "NONE";
        }

        cout << endl;
    }
  }


///

  vector<pair<int,int>>InvertedIndex:: searchwithfreq(const string& query){
    string word=Cleanword(query);
    
    vector<pair<int,int>> results;

    if(index2.find(word)==index2.end()){
      return results;
    }
    

    for(const auto& [docid,freq]: index2[word]){
      results.push_back({docid,freq});

    }


      // tie the first number //
    sort(results.begin(),results.end(),[](auto&a,auto&b){
    if (a.second==b.second){
      return a.first<b.first;
    }
    return a.second > b.second;  
    });

    return results;

  }


///


vector<pair<int,int>> InvertedIndex:: Gsearchwithfreq (const string& query){
        vector <string> words=tokenization(query);
        unordered_map<int,int> doc_freq;

        for(const string & word:words){
          if(index2.find(word)!=index2.end()){
            for(auto&[docid,freq]:index2[word]){
              doc_freq[docid]+=freq;
            }
          }
        }

      vector<pair<int,int>> results(doc_freq.begin(),doc_freq.end());

      sort(results.begin(),results.end(),[](auto& a,auto& b){
            
            if(a.second==b.second){
            return a.first<b.first;
            }
            return a.second>b.second;

      });

      return results;

}




                                                                 //////// search output ////////


void InvertedIndex::printSearch(const std::unordered_set<int>& results) {
  cout<<"*************************************"<<endl;
    cout << "Search Results → ";
    if(results.empty()) {
        cout << "NONE";
    } else {
        cout << "{ ";
        for(int id : results) {
            cout << id << " ";
        }
        cout << "}";
    }

    cout << endl;


}

///

void InvertedIndex:: printGsearchwithfreq(vector<pair<int,int>> & search){
      cout<<"*************************************"<<endl;
      for(auto&[docid,freq]:search){
          cout<<"DOC "<<docid<<" → "<<freq<<" times\n";
      }             
}





                                                            //////// clear& print index1 ////////


    void InvertedIndex:: clearIndex(){
      index.clear();
    }





    void InvertedIndex:: PrintIndex(){
        cout<<"Inverted Index:"<<endl;
        for(const auto& pair : index){
            cout<<pair.first<<": ";
              for(int id: pair.second){
                cout<<id<<" ";
              }
              cout<<endl;
        }
    }

















////////////////////////////////////////////////////


// before header

// class InvertedIndex{
//     private:
//     unordered_map<string,unordered_set<int>> index;
//     public:

//     void addDocument(int id,const string& text){
//       vector <string> words=tokenization(text);

//       for(const string& word: words){
//         index[word].insert(id);
//       }
//     }



//     unordered_set<int> search(const string& query){
//       string cleanword;
//       for(char c: query){
//         if(isalnum(c)){
//           cleanword+= tolower(c);
//         }
//       }
//       if (index.find(cleanword) != index.end()){
//         return index[cleanword];

//       }
//       else{
//         cout<<"NONE"<<endl;
//         return {};

//       }
//     }



//     void clearIndex(){
//       index.clear();
//     }


//     void printindex(){
//         cout<<"Inverted Index:"<<endl;
//         for(const auto& pair : index){
//             cout<<pair.first<<": ";
//               for(int id: pair.second){
//                 cout<<id<<" ";
//               }
//               cout<<endl;
//         }
//     }
   

//     void Gsearch (const string& query){
//         string word;
//         stringstream ss(query);
//         while(ss>>word){
//             string cleanword;
//             for(char c: word){
//                 if(isalnum(c)){
//                     cleanword+=tolower(c);
//                 }
//             }
//             cout<<"result for "<<word<<" : ";
//             if(index.find(cleanword)!=index.end()){
//                 for( int id: index[cleanword]){
//                     cout<<id<<" ";
//                 }
//                 cout<<endl;
//             }
//             else{
//                 cout<<"NONE"<<endl;
                
//             }
//         }

//     }

// };