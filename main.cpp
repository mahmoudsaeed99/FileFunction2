#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;

struct index{
    char id[10];
    int offset;
};
int hash_(char id[]){
    return ( (int)id[0] + (int)id[1] )%100;
}
void intialize_file(fstream& f){
    index i;
    i.offset=-1;
    for(int i=0;i<100;i++){
        f.write((char*)&i,sizeof(r));
    }
}
void add(index i, fstream& f){
    int rrn = hash_(i.id);
    int n_rrn =rrn ;
    while(true){
        f.seekp(n_rrn*sizeof(i),ios::beg);
        f.read((char*)&i,sizeof(i));
        if(i.offset==-1){
            break;
        }
        n_rrn-(n_rrn+1)%100;
        if(n_rrn==rrn){
            cout<<"there is no space to add this record in this file "<<endl;
            return;
        }
    }
    f.write((char*)&i,sizeof(i));
}
int search(char id[] , fstream& f){
    index i;
    int rrn =hash_(id);
    int n_rrn =rrn ;
    while(true){
        f.seekg(rrn*sizeof(i),ios::beg);
        f.read((char*)&i,sizeof(i));
        if(strcmp(i.id,id)==0){
            return i.offset;
        }
        if(i.offset==-1){
            return -1;
        }
        n_rrn = (n_rrn+1)%100;
        if(n_rrn==rrn ){
            return -1;
        }
    }
}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
