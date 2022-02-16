#include <bits/stdc++.h>

using namespace std;

ifstream fin("puzzle.in");

///legend:
///shape: 1-diamond, 2-cylinder, 3-wave
///color: 1-red, 2-green, 3-purple
///solidity: 1-empty, 2-crossed, 3-full

///input must be: shape, color, solidity, number

struct card{
    int form,color,full,number;
}v[12];

int main()
{
    int nrshapes=12; ///default number
    for(int i=1;i<=nrshapes;++i)
        fin>>v[i].form>>v[i].color>>v[i].full>>v[i].number;
    for(int i=1;i<=10;++i){
        for(int j=i+1;j<=11;++j){
            int searchform,searchcolor,searchfull,searchnumber;
            if(v[i].form==v[j].form) searchform=v[i].form;
            else searchform=6-v[i].form-v[j].form;
            if(v[i].color==v[j].color) searchcolor=v[i].color;
            else searchcolor=6-v[i].color-v[j].color;
            if(v[i].full==v[j].full) searchfull=v[i].full;
            else searchfull=6-v[i].full-v[j].full;
            if(v[i].number==v[j].number) searchnumber=v[i].number;
            else searchnumber=6-v[i].number-v[j].number;
            for(int k=j+1;k<=12;++k){
                if(v[k].form==searchform &&
                   v[k].color==searchcolor &&
                   v[k].full==searchfull &&
                   v[k].number==searchnumber) {cout<<i<<' '<<j<<' '<<k<<'\n';break;}
            }
        }
    }
    return 0;
}
