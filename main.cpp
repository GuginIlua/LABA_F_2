using namespace std;
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<char> from;
    vector<char> to;
    vector<char> with;
    vector<char> points;
    vector<char> rpoints;
    vector<char> step;
    string g;
    int ans;
    string alph = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char c;
    char b;
    char a;
    char d;
    char e;
    char f;
    int code;
    int flags=0;
    cout<<"Enter information by yourself or load from file?"<<endl;
    cout<<"1-by yourself"<<endl;
    cout<<"2-from file"<<endl;
    cin>>code;
    if(code==2){
        ifstream in("gram.txt");
        if(in.is_open()==false){
            cout<<"File not found. Would you like to create it?"<<endl;
            cout<<"1-yes"<<endl;
            cout<<"2-no"<<endl;
            cin>>ans;
            if(ans==1){
                ofstream MyFile("gram.txt");
                cout<<"File successfully created"<<endl;
                cout<<"Enter your grammar like this:"<<endl;
                cout<<"X,Y,Z,V,W"<<endl;
                cout<<"0,1,x,y,z"<<endl;
                cout<<"X->yY|zZ"<<endl;
                cout<<"Y->1V"<<endl;
                cout<<"Z->0W|0Y"<<endl;
                cout<<"V->xZ|xW|1"<<endl;
                cout<<"W->1Y|0"<<endl;
                MyFile.close();
                return 0;
            }
            else{
                cout<<"File error"<<endl;
                return 0;
            }
        }
        ifstream an("gram.txt");
        if(an.is_open()){
            while (std::getline(in, g)){
                if(flags==0){
                    for(int i=0;i<g.size();i++){
                        c=g[i];
                        if(c!=','){
                            points.push_back(c);
                        }
                        flags=1;
                    }
                    continue;
                }
                if(flags==1){
                    for(int i=0;i<g.size();i++){
                        c=g[i];
                        if(c!=','){
                            step.push_back(c);
                        }
                }
                    flags=2;
                    continue;
                }
                int flag=0;
                int flag2=0;
                if(g[1]=='-' && g[2]=='>'){
                    flag2=1;
                }
                if(flag2==0){
                    cout<<"Reminder: use ->"<<endl;
                    return 0;
                }
                flag2=0;
                for(int i =0;i<points.size();i++){
                    c=g[0];
                    if(c==points[i]) flag2=1;
                    if(flag2==1) break;
                }
                if(flag2==0){
                    cout<<"Point error"<<endl;
                    return 0;
                }
                flag2=0;
                if(g.size()==4){
                    for(int i =0;i<points.size();i++){
                        c=g[4];
                        if(c==points[i]) flag2=1;
                        if(flag2==1) break;
                    }
                    if(flag2==0){
                        cout<<"Point error"<<endl;
                        return 0;
                    }
                }
                flag2=0;
                if(g.size()==8){
                    for(int i =0;i<points.size();i++){
                        c=g[7];
                        if(c==points[i]) flag2=1;
                        if(flag2==1) break;
                    }
                    if(flag2==0){
                        cout<<"Point error"<<endl;
                        return 0;
                    }
                }
                flag2=0;
                if(g.size()==11){
                    for(int i =0;i<points.size();i++){
                        c=g[10];
                        if(c==points[i]) flag2=1;
                        if(flag2==1) break;
                    }
                    if(flag2==0){
                        cout<<"Point error"<<endl;
                        return 0;
                    }
                }
                flag2=0;
                for(int i =0;i<points.size();i++){
                    c=g[4];
                    if(c==points[i]) flag2=1;
                    if(flag2==1) break;
                }
                if(flag2==0){
                    cout<<"Point error"<<endl;
                    return 0;
                }
                flag2=0;
                for(int i =0;i<step.size();i++){
                    c=g[3];
                    if(c==step[i]) flag2=1;
                    if(flag2==1) break;
                }
                if(flag2==0){
                    cout<<"Transition symbol error"<<endl;
                    return 0;
                }
                flag2=0;
                if(g.size()>5){
                for(int i =0;i<step.size();i++){
                    c=g[6];
                    if(c==step[i] && g[5]=='|') flag2=1;
                    if(flag2==1) break;
                }
                if(flag2==0){
                    cout<<"Transition symbol or '|' error"<<endl;
                    return 0;
                }
                }
                flag2=0;
                if(g.size()>8){
                for(int i =0;i<step.size();i++){
                    c=g[9];
                    if(c==step[i] && g[5]=='|' && g[8]=='|') flag2=1;
                    if(flag2==1) break;
                }
                if(flag2==0){
                    cout<<"Transition symbol or '|' error"<<endl;
                    return 0;
                }
                }
                flag2=0;
                if(g.size()==5 || g.size()==4){
                    if(g[1]=='-' && g[2]=='>'){
                        c=g[0];;
                        from.push_back(c);
                        c=g[3];
                        with.push_back(c);
                        if(g.size()==4){
                            c=points.back();
                            to.push_back(c);
                        }
                        else{
                            c=g[4];
                            to.push_back(c);
                        }
                    }
                    flag=1;
                }
                if(g.size()==7 || g.size()==8){
                    if(g[1]=='-' && g[2]=='>' && g[5]=='|'){
                        c=g[0];
                        from.push_back(c);
                        from.push_back(c);
                        c=g[3];
                        with.push_back(c);
                        c=g[6];
                        with.push_back(c);
                        c=g[4];
                        to.push_back(c);
                        if(g.size()==7){
                            c=points.back();
                            to.push_back(c);
                        }
                        else{
                            c=g[7];
                            to.push_back(c);
                        }
                    }
                    flag=1;
                }
                if(g.size()==10 || g.size()==11){
                    if(g[1]=='-' && g[2]=='>' && g[5]=='|' && g[8]=='|'){
                        c=g[0];
                        from.push_back(c);
                        from.push_back(c);
                        from.push_back(c);
                        c=g[3];
                        with.push_back(c);
                        c=g[6];
                        with.push_back(c);
                        c=g[9];
                        with.push_back(c);
                        c=g[4];
                        to.push_back(c);
                        c=g[7];
                        to.push_back(c);
                        if(g.size()==10){
                            c=points.back();
                            to.push_back(c);
                        }
                        else{
                            c=g[10];
                            to.push_back(c);
                        }
                    }
                    flag=1;
                }
                if(flag=0) cout << "Input error" << endl;
            }
            }
                    }
    if(code==1){
    cout << "Enter points separated by commas (Example: A,B,O(where A-first point and O-end point)"<< endl << "(Note: the point name must be 1 character long): ";
    cin>>g;
    for(int i=0;i<g.size();i++){
        c=g[i];
        if(c!=','){
            points.push_back(c);
        }
    }
    cout << "Enter the transition symbols separated by commas (Example: a,b,c): ";
    cin>>g;
    for(int i=0;i<g.size();i++){
        c=g[i];
        if(c!=','){
            step.push_back(c);
        }
    }
    while(1){
        cout << "Enter grammar using ->(Example A->aO, A->aO|bB(If you have already entered everything - enter ---)): ";
        cin>>g;
        int flag=0;
        int flag2=0;
        if(g=="---") break;
        if(g[1]=='-' && g[2]=='>'){
            flag2=1;
        }
        if(flag2==0){
            cout<<"Reminder: use ->"<<endl;
            continue;
        }
        flag2=0;
        for(int i =0;i<points.size();i++){
            c=g[0];
            if(c==points[i]) flag2=1;
            if(flag2==1) break;
        }
        if(flag2==0){
            cout<<"Point error"<<endl;
            continue;
        }
        flag2=0;
        if(g.size()==4){
            for(int i =0;i<points.size();i++){
                c=g[4];
                if(c==points[i]) flag2=1;
                if(flag2==1) break;
            }
            if(flag2==0){
                cout<<"Point error"<<endl;
                continue;
            }
        }
        flag2=0;
        if(g.size()==8){
            for(int i =0;i<points.size();i++){
                c=g[7];
                if(c==points[i]) flag2=1;
                if(flag2==1) break;
            }
            if(flag2==0){
                cout<<"Point error"<<endl;
                continue;
            }
        }
        flag2=0;
        if(g.size()==11){
            for(int i =0;i<points.size();i++){
                c=g[10];
                if(c==points[i]) flag2=1;
                if(flag2==1) break;
            }
            if(flag2==0){
                cout<<"Point error"<<endl;
                continue;
            }
        }
        flag2=0;
        for(int i =0;i<points.size();i++){
            c=g[4];
            if(c==points[i]) flag2=1;
            if(flag2==1) break;
        }
        if(flag2==0){
            cout<<"Point error"<<endl;
            continue;
        }
        flag2=0;
        for(int i =0;i<step.size();i++){
            c=g[3];
            if(c==step[i]) flag2=1;
            if(flag2==1) break;
        }
        if(flag2==0){
            cout<<"Transition symbol error"<<endl;
            continue;
        }
        flag2=0;
        if(g.size()>5){
        for(int i =0;i<step.size();i++){
            c=g[6];
            if(c==step[i] && g[5]=='|') flag2=1;
            if(flag2==1) break;
        }
        if(flag2==0){
            cout<<"Transition symbol or '|' error"<<endl;
            continue;
        }
        }
        flag2=0;
        if(g.size()>8){
        for(int i =0;i<step.size();i++){
            c=g[9];
            if(c==step[i] && g[5]=='|' && g[8]=='|') flag2=1;
            if(flag2==1) break;
        }
        if(flag2==0){
            cout<<"Transition symbol or '|' error"<<endl;
            continue;
        }
        }
        flag2=0;
        if(g.size()==5 || g.size()==4){
            if(g[1]=='-' && g[2]=='>'){
                c=g[0];;
                from.push_back(c);
                c=g[3];
                with.push_back(c);
                if(g.size()==4){
                    c=points.back();
                    to.push_back(c);
                }
                else{
                    c=g[4];
                    to.push_back(c);
                }
            }
            flag=1;
        }
        if(g.size()==7 || g.size()==8){
            if(g[1]=='-' && g[2]=='>' && g[5]=='|'){
                c=g[0];
                from.push_back(c);
                from.push_back(c);
                c=g[3];
                with.push_back(c);
                c=g[6];
                with.push_back(c);
                c=g[4];
                to.push_back(c);
                if(g.size()==7){
                    c=points.back();
                    to.push_back(c);
                }
                else{
                    c=g[7];
                    to.push_back(c);
                }
            }
            flag=1;
        }
        if(g.size()==10 || g.size()==11){
            if(g[1]=='-' && g[2]=='>' && g[5]=='|' && g[8]=='|'){
                c=g[0];
                from.push_back(c);
                from.push_back(c);
                from.push_back(c);
                c=g[3];
                with.push_back(c);
                c=g[6];
                with.push_back(c);
                c=g[9];
                with.push_back(c);
                c=g[4];
                to.push_back(c);
                c=g[7];
                to.push_back(c);
                if(g.size()==10){
                    c=points.back();
                    to.push_back(c);
                }
                else{
                    c=g[10];
                    to.push_back(c);
                }
            }
            flag=1;
        }
        if(flag=0) cout << "Input error" << endl;
    }
    }
    cout<<"Original machine:"<<endl;
    for(int i=0;i<from.size();i++){
        cout<<from[i]<<"---("<<with[i]<<")--->"<<to[i]<<endl;
    }
    for(int i=0;i<points.size();i++){
        c=points[i];
        for(int j=0;j<alph.size();j++){
            b=alph[j];
            if(b==c){
                alph.erase(j,1);
            }
        }
    }
    a=points.front();
    rpoints.push_back(a);
    flags=0;
    for(int i=0; i<to.size();i++){
        int cnt = count(rpoints.begin(), rpoints.end(), to[i]);
        if(cnt==0){
            rpoints.push_back(to[i]);
        }
    }
    for(int i=0; i<from.size();i++){
        for(int j=0; j<rpoints.size();j++){
            if(from[i]==rpoints[j]){
                flags=1;
            }
        }
        if(flags==0){
            from.erase(from.begin()+i);
            to.erase(to.begin()+i);
            with.erase(with.begin()+i);
            i=0;
        }
        flags=0;
    }
    for(int i=0;i<from.size();i++){
        for(int j=0; j<to.size();j++){
            if(to[i]==to[j]&&with[i]==with[j]&&from[i]!=from[j]){
                c=from[i];
                d=from[j];
                cout<<from[i]<<","<<from[j]<<"->"<<alph[0]<<endl;
                from[j]=alph[0];
                to.erase(to.begin()+i);
                with.erase(with.begin()+i);
                from.erase(from.begin()+i);
                for(int p=0;p<from.size();p++){
                    if(from[p]==c||from[p]==d){
                        from[p]=alph[0];
                    }
                }
                for(int p=0;p<to.size();p++){
                    if(to[p]==c || to[p]==d){
                        to[p]=alph[0];
                    }
                }
                alph.erase(0,1);
            }
        }
    }
    /*for(int i=0; i<from.size();i++){
        for(int j=0; j<to.size();j++){
            if(to[i]==to[j] && with[i]==with[j] && from[i]!=from[j]){
                f=alph[0];
                from.push_back(f);
                with.push_back(with[j]);
                to.push_back(to[j]);
                for(int p=0;p<from.size();p++){
                    if(from[p]==from[i]){
                        from.push_back(f);
                        with.push_back(with[p]);
                        to.push_back(to[p]);
                        to.erase(to.begin()+i);
                        with.erase(with.begin()+i);
                        from.erase(from.begin()+i);
                    }
                    if(from[p]==from[j]){
                        from.push_back(f);
                        with.push_back(with[p]);
                        to.push_back(to[p]);
                        to.erase(to.begin()+j);
                        with.erase(with.begin()+j);
                        from.erase(from.begin()+j);
                    }
                }
                alph.erase(0,1);
                to.erase(to.begin()+i);
                with.erase(with.begin()+i);
                from.erase(from.begin()+i);
                to.erase(to.begin()+j);
                with.erase(with.begin()+j);
                from.erase(from.begin()+j);
            }
        }
    }*/
    cout<<"Min machine:"<<endl;
    for(int i=0;i<from.size();i++){
        cout<<from[i]<<"---("<<with[i]<<")--->"<<to[i]<<endl;
    }
    return 0;
}
