#include "bubbleSort.h"
#include "quickSort.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <chrono>

using namespace std;


int str2Int(string str){
    int str_size = str.size(), res = 0;
    for(int i = str_size - 1; i >= 0; --i){
        res *= 10;
        res += (str[i] - 48);
    }
    return res;
}


vector<int> loadData(ifstream &ifs){
    vector<int> res;
    string str;
    stringstream ss;
    if(getline(ifs, str)){
        int str_size = str.size();
        for(int i = 0; i < str_size; ++i){
            if(str[i] == ','){
                int elem = str2Int(ss.str());
                ss.str("");
                ss.clear(stringstream::goodbit);
                res.push_back(elem);
                ++i;
            }
            else
                ss << str[i];
        }
    }

    return res;
}


void printArray(vector<int> array){
    int array_size = array.size();
    for(int i = 0; i < array_size; ++i)
        cout << array[i] << "\t"; 
    cout << endl;
}


int main(int argc, char *argv[]){
    if(argc != 2 || (!strncmp(argv[1], "quickSort", 9) && !strncmp(argv[1], "bubbleSort", 10))){
        cerr << "ERROR : please input 1 args, 'bubbleSort' or 'quickSort'." << endl;
        exit(1);
    }

    ifstream ifs("testCase.csv");
    if (ifs.fail()){
        cerr << "fail" << endl;
        return -1;
    }
    
    int cnt = 0;
    vector<int> temp_res;
    string task_type = argv[1];
    std::chrono::system_clock::time_point start, end; // 型は auto で可
    double elapsed = 0;

    cout << "start sorts!" << endl;
    while((temp_res = loadData(ifs)).size() != 0){
        if(cnt % 100 == 0){
            cout << "============" << endl;
            cout << "From..." << endl;
            printArray(temp_res);
            cout << "To..." << endl;
        }
        start = std::chrono::system_clock::now(); // 計測開始時間
        if(task_type == "bubbleSort")
            bubbleSort(temp_res);
        else if(task_type == "quickSort")
            quickSort(temp_res, 0, temp_res.size() - 1);
        else{
            cerr << "Non-existing sort you're specifying." << endl;;
            exit(1);
        }
        end = std::chrono::system_clock::now();  // 計測終了時間
        elapsed += std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count(); //処理に要した時間をミリ秒に変換
        if(cnt % 100 == 0){
            printArray(temp_res);
            cout << "Now processing iteration " << cnt << "!" <<  endl;
        }
        ++cnt;
    }
    ofstream ofs;
    if(task_type == "bubbleSort")
        ofs.open("bubbleSort.out", ofstream::out);
    else if(task_type == "quickSort")
        ofs.open("quickSort.out", ofstream::out);
    ofs << elapsed << " milli sec";
    ofs.close();

    return 0;
}
