#pragma once
#include<iostream>
#include<algorithm> 
#include<string>
#define P_MAX 10
using namespace std;

struct Process {
    int num;//���̱�� 
    string person_name;
    int arrived_tunnel_time;//�������ʱ�� 
    int starttime;//��ʼʱ�� 
    int servicetime;//����ʱ�� 
    int postservicetime;
    int leave_tunnel_time;//�뿪���ʱ��
    int finishedtime;//ȫ�����ʱ�� 
};

//���յ���ʱ���������� 




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