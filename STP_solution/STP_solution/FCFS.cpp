#include"FCFS.h"

bool cmp(Process p1, Process p2) {
    return p1.arrived_tunnel_time < p2.arrived_tunnel_time;
}

FCFS::FCFS()
{
    MaxProcesses = P_MAX;
    NumProcesses = 0;
    ProcessTable = new Process[MaxProcesses];
}
FCFS::FCFS(int n)
{
    MaxProcesses = P_MAX;
    NumProcesses = n;
    ProcessTable = new Process[MaxProcesses];
}

void FCFS::inputP(string*name, int* arrivedtime, int* servicetime, int* postservicetime) {
    for (int i = 0; i < NumProcesses; i++) {
        ProcessTable[i].num = i + 1;
        ProcessTable[i].person_name = name[i];
        ProcessTable[i].arrived_tunnel_time = arrivedtime[i];
        ProcessTable[i].servicetime = servicetime[i];
        ProcessTable[i].starttime = 0;
        ProcessTable[i].leave_tunnel_time = 0;
        ProcessTable[i].finishedtime = 0;
        ProcessTable[i].postservicetime = postservicetime[i];
    }
};
void FCFS::getresult()
{
    sort(ProcessTable, ProcessTable + NumProcesses, cmp); 
    int i;
    for (i = 0; i < NumProcesses; i++) {
        if (i == 0) {
            ProcessTable[i].starttime = ProcessTable[i].arrived_tunnel_time;
        }
        else {
            ProcessTable[i].starttime = ProcessTable[i - 1].leave_tunnel_time;
        }

        ProcessTable[i].leave_tunnel_time = ProcessTable[i].starttime + ProcessTable[i].servicetime;
        ProcessTable[i].finishedtime = ProcessTable[i].leave_tunnel_time + ProcessTable[i].postservicetime;
    }

};
void FCFS::printP()
{
    int i;
    cout << "num" << "  " <<"人物名称" <<"    "<<"到达隧道时间" << "  "  << "  " << "从隧道开始出发时间" << "  " << "离开隧道时间" << "  " << "到达目的地时间" << "  " <<endl;
    for (i = 0; i < NumProcesses; i++) {
        cout << ProcessTable[i].num << "     " <<ProcessTable[i].person_name<<"      "<< ProcessTable[i].arrived_tunnel_time << "                    " << ProcessTable[i].starttime << "             " << ProcessTable[i].leave_tunnel_time<<"           "<< ProcessTable[i].finishedtime;
        cout << endl;
    }
}