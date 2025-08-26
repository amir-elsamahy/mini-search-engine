#ifndef INVERTEDINDEX_H
#define INVERTEDINDEX_H
#include<iostream>
#include<string>
#include<sstream>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include"../include/Utils.h"
#include<vector>


class InvertedIndex{
    private:
        std::unordered_map<std::string,std::unordered_set<int>> index;

        std:: unordered_map<std:: string,std::unordered_map<int,int>>index2;

    public:

    void addDocumentsimple(int id,const std::string& text);
    void addDocumentwithfreq(int id,const std::string& text);

    std::unordered_set<int> search(const std::string& query);
    std::vector<std::pair<int,int>> searchwithfreq(const std::string& query);



    void clearIndex();

    void PrintIndex();
   

    void Gsearch (const std::string& query);

};




#endif