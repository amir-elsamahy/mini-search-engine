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

 


    vector<pair<int,int>>InvertedIndex:: searchwithfreq(const string& query){
      string word=Cleanword(query);
      
      vector<pair<int,int>> results;

      if(index2.find(word)==index2.end()){
        return results;
      }
      

      for(auto& [docid,freq]: index2[word]){
        results.push_back({docid,freq});

      }



// tie the first number .
     sort(results.begin(),results.end(),[](auto&a,auto&b){
      if (a.second==b.second){
        return a.first<b.first;
      }
      return a.second > b.second;  
     });

     return results;

    }













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





    void InvertedIndex:: Gsearch (const string& query){
        string word;
        stringstream ss(query);
        while(ss>>word){
            string cleanword;
            for(char c: word){
                if(isalnum(c)){
                    cleanword+=tolower(c);
                }
            }
            cout<<"result for \""<<word<<"\" => ";
            if(index.find(cleanword)!=index.end()){
                cout<<"{";
                for( int id: index[cleanword]){
                    cout<<" "<<id<<" ";
               
                }
                cout<<"}";
                cout<<endl;
            }
            else{
                cout<<"NONE"<<endl;
                
            }
        }

    }





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