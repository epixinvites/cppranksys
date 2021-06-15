#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <unordered_map>
#include <iomanip>
#include <chrono>
#include "config.h"
using namespace std;
struct student_data{
    string name, class_id;
};
void init_data(ifstream &studentcsv, unordered_map<string, student_data> &v){
    for(string id, name, class_id; getline(studentcsv,id,',') && getline(studentcsv, name, ',') && getline(studentcsv, class_id);){
        v.insert({id,{name,class_id}});
    }
}
void record_ranking(int rank, string id,
                    unordered_map<string, student_data> &data,
                    fstream &rankingcsv) {
  rankingcsv << rank << ',' << data[id].name << ',' << data[id].class_id;
}
int main(){
    ifstream studentcsv (studentdb);
    fstream rankingcsv (rankingdb);
    unordered_map<string, student_data> data;
    init_data(studentcsv,data);
    record_ranking(1, "2", data, rankingcsv);
}
