#pragma once
#include<iostream>
#include<algorithm> 
#include<string>
#define P_MAX 10
using namespace std;

struct Process {
    int num;//进程编号 
    string person_name;
    int arrived_tunnel_time;//到达隧道时间 
    int starttime;//开始时间 
    int servicetime;//服务时间 
    int postservicetime;
    int leave_tunnel_time;//离开隧道时间
    int finishedtime;//全部完成时间 
};

//按照到达时间升序排列 




class FCFS
{
public:
    FCFS();
    FCFS(int n);
    void inputP(string*name, int* arrivedtime, int* servicetime, int* postservicetime);
    void getresult();
    void printP();
    ~FCFS() {};
   

private:
    int MaxProcesses;
    int NumProcesses;
    Process* ProcessTable;

};