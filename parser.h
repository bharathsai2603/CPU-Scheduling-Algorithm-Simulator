#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include <bits/stdc++.h>

using namespace std;

/** This file handles parsing the data we are going to work with **/
/** It also holds all the global variables we parse into         **/



int last_instant=0, process_count;
vector<pair<char, int>> algorithms;
vector<tuple<string,int,int>> processes;
vector<vector<char>>timeline;
unordered_map<string,int>processToIndex;


//Results

vector<int>finishTime;
vector<int>turnAroundTime;
vector<float>normTurn;


void parse_algorithms(string algorithm_chunk)
{
    stringstream stream(algorithm_chunk);
    while (stream.good())
    {
        string temp_str;
        getline(stream, temp_str, ',');
        stringstream ss(temp_str);
        getline(ss, temp_str, '-');
        char algorithm_id = temp_str[0];
        getline(ss, temp_str, '-');
        int quantum = temp_str.size() >= 1 ? stoi(temp_str) : -1;
        algorithms.push_back( make_pair(algorithm_id, quantum) );
    }
}

void parse_processes()
{
    string process_chunk, process_name;
    int process_arrival_time, process_service_time;
    for(int i=0; i<process_count; i++)
    {
        cout<<"Enter process" << i+1 <<" details:";
        cin >> process_chunk;

        stringstream stream(process_chunk);
        string temp_str;
        getline(stream, temp_str, ',');
        process_name = temp_str;
        getline(stream, temp_str, ',');
        process_arrival_time = stoi(temp_str);
        getline(stream, temp_str, ',');
        process_service_time = stoi(temp_str);

        processes.push_back( make_tuple(process_name, process_arrival_time, process_service_time) );
        processToIndex[process_name] = i;
    }
}

void parse()
{
    cout<<"Enter 1 for First Come First Serve"<<endl;
    cout<<"Enter 2 for Round Robin"<<endl;
    cout<<"Enter 3 for Shortest Process Next"<<endl;
    cout<<"Enter 4 for Shortest Remaining Time"<<endl;
    cout<<"Enter 5 for Highest Response Ratio Next"<<endl;
    cout<<"Enter 6 for FeedBack-1"<<endl;
    cout<<"Enter 7 for Feedback-2i"<<endl;
    cout<<"Enter 8 for Aging"<<endl;



    string algorithm_chunk;
    cin >> algorithm_chunk; 
    
    cout<<"Enter simulation time:";
    cin>>last_instant;

    cout<<"Enter n.o of processes:";
    cin>>process_count;

    parse_algorithms(algorithm_chunk);
    parse_processes();
    finishTime.resize(process_count);
    turnAroundTime.resize(process_count);
    normTurn.resize(process_count);
    timeline.resize(last_instant);
    for(int i=0; i<last_instant; i++)
        for(int j=0; j<process_count; j++)
            timeline[i].push_back(' ');

  
}


#endif // PARSER_H_INCLUDED