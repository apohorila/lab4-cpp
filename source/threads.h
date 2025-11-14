#pragma once
#include "struct.h"
#include <chrono>
#include <vector>
#include <fstream>
#include <thread> 
#include <iostream>
#include <string>


using namespace std;
using namespace std::chrono;

void process_commands(const string& filename, DataStructure& dataStruct){
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Cannot open file " << filename << endl;
        return;
    }
    string command;
    while (file >> command){
        if (command == "write"){
            int field, value;
            file >> field >> value;
            if (field == 0){
                dataStruct.set0(value);
            }
            else if (field == 1){
                dataStruct.set1(value);
            }else {
                dataStruct.set2(value);
            }
        } else if (command == "read"){
            int field;
            file >> field;
            if (field == 0){
                dataStruct.get0();
            }else if (field == 1){
                dataStruct.get1();
            } else {
                dataStruct.get2();
            }
        } else if (command == "string") {
            string result = dataStruct;
        }else {
            cout << "Undefined command" <<endl;
        }
    }
}


void execute_threads(const vector<string>& file_names) {
    DataStructure dataStruct;
    
    vector<thread> threads;
    threads.reserve(file_names.size());

    for (const string& name : file_names) {
        threads.emplace_back(process_commands, cref(name), ref(dataStruct));
    }

    for (auto& t : threads) {
        if (t.joinable()) {
            t.join();
        }
    }
}

void funcForAllMethods( const vector<string>& files1, const vector<string>& files2, const vector<string>& files3) 
{

    DataStructure obj1;
    cout << "\n1. Single-threaded execution (" << files1.size() << " file):" << endl;
    auto start1 = high_resolution_clock::now();
    for (const auto& file : files1) {
        process_commands(file, obj1);
    }
    auto end1 = high_resolution_clock::now();
    long long time1_ms = duration_cast<milliseconds>(end1 - start1).count();
    double time1_s = (double)time1_ms/1000.0;
    cout << "Time taken: " << time1_s << " s" << endl;
    
    cout << "\n2. Two-threaded execution (" << files2.size() << " files):" << endl;
    auto start2 = high_resolution_clock::now();
    execute_threads(files2); 
    auto end2 = high_resolution_clock::now();
    long long time2_ms = duration_cast<milliseconds>(end2 - start2).count();
    double time2_s = (double)time2_ms/1000.0;
    cout << "Time taken: " << time2_s << " s" << endl;

    cout << "\n3. Three-threaded execution (" << files3.size() << " files):" << endl;
    auto start3 = high_resolution_clock::now();
    execute_threads(files3); 
    auto end3 = high_resolution_clock::now();
    long long time3_ms = duration_cast<milliseconds>(end3 - start3).count();
    double time3_s = (double)time3_ms/1000.0;
    cout << "Time taken: " << time3_s << " s" << endl;
    
}