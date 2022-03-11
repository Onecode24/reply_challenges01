#include <iostream>
#include <fstream>
#include <sstream>
#include "Demon.h"

using namespace std;

bool checkNext(vector<Demon> devil,int i);

int main(){
    string line;
    ifstream file("00-example.txt");
    ofstream ouptup("00-example.out.txt");
    vector<Demon> allDemon,demonLost;
    int endu,enduMax,NbrTour,d,u(0);
    if(file.is_open()){
        getline(file,line);
        stringstream ssline(line);
        ssline >> endu >> enduMax >> NbrTour >> d;
        while(d--){
            int n;
            getline(file,line);
            stringstream ssline(line);
            Demon devil;
            devil.lost=false;
            ssline >> devil.enduLost >> devil.nbrTour >> devil.enduEarn >> n;
            while(ssline >> n){
                devil.reward.push_back(n);
            }
            allDemon.push_back(devil);
        }

        int nbr(allDemon.size());

        while(nbr--){
            int indice(0);
            bool preced=false;
            for(int i(0); i<allDemon.size(); i++){
                if((allDemon[i].enduLost<endu || allDemon[i].nbrTour>indice) && allDemon[i].lost==false){
                    indice=allDemon[i].nbrTour;
                    u=i;
                }

            }
            ouptup << u<< endl;
            allDemon[u].lost=true;
            endu-=allDemon[u].enduLost;
            if(!checkNext(allDemon,endu)){
                NbrTour-=allDemon[u].nbrTour;
                endu+=allDemon[u].enduEarn;
                if(endu>20) endu=20;
            }  
        }

    }

    return 0;
}

bool checkNext(vector<Demon> devil,int i){
    for(int j(0); j<devil.size(); j++){
        if(devil[j].lost==false && devil[j].enduLost<i) return true;
    }
    return false;
}