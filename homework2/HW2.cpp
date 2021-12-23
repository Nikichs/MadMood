#include <bits/stdc++.h>
using namespace std;

int main(int argc, const char * argv[]) {
    if(argc < 2 || argc > 2){
        cout << "error"<< endl;
    }



    double Vx, Vy, h0;
    vector <double> x;
    vector <double> h;


    double vxr, vyr, h0r, hr, xr;


    ifstream f(argv[1]);
    if ((f.is_open()))  // проверка наличия файла с тестом

    {
        int cnt = 0;
        while(!f.eof()){

            if (cnt == 0){
                f>>hr;
                h0 = hr;
            }

            else if (cnt == 1){
                f>>vxr>>vyr;
                Vx = vxr;
                Vy = vyr;
            }

            else{
                f>>xr>>hr;
                x.push_back(xr);
                h.push_back(hr);
            }
            cnt++;
        }
    }

    f.close();



 //double Vx, Vy;
 double g = 9.81;


 double s, t, h_fly, h_cur;
 h_cur = h0;
 t = 0;


 int i = 0;


 while (h_cur>0){

    //cout<<i<<endl;
    //cout<<"...."<<endl;



    if (i==0){
        s = x[i];
        if (Vx<0){
            cout << 0;
            break;
        }
    }

    else{
    s = abs(x[i]-x[i-1]);
    }



    if (Vx==0){
      cout<<0;
      break;
    }

    t = t + abs(s/Vx);
    h_fly = Vy*t -((g*t*t)/2);
    h_cur = h_cur + h_fly;


    //упал в полете
    if (h_cur<=0){
        cout << i;
        break;
    }

    //врезался в стенку/над ней

    else{
        //пролет
        if (h_cur>h[i]){

            if ((Vx<0)and(i==1)){
                cout << 0;
                //cout << "Levo";
                break;

            }

            else if ((Vx>0)and(i==x.size()-1)){
                cout << i;
                //cout << "NeLevo";
                break;
            }

            else{
                if (Vx>0){i++;} //cout<<"forw";}
                else{i--;} //cout<<"Back";}
            }
        }
        else{
            //врезался
            Vx = -Vx;
            //s = x[i];

            //if (Vx<0){i--;}
            //else{i++;}
        }
    }

 }

}
