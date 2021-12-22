#include <bits/stdc++.h>
using namespace std;

int main(int argc, const char * argv[]) {
    string filename;
    if (argc == 2) {
        filename = string(argv[1]);
    } else {
        cerr << "ERROR: wrong number of input parameters: " << (argc - 1) << endl;
        return 1;
    }



    double Vx, Vy, h0;
    vector <double> x;
    vector <double> h;


    double vxr, vyr, h0r, hr, xr;


    ifstream f(filename);
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
 s = 0;
 h_cur = h0;


 int i = 0;


 while (h_cur>0){


    s = abs(x[i]-s);

    if (Vx==0){
      cout<<0;
      break;
    }
    t = abs(s/Vx);
    h_fly = Vy*t -((g*t*t)/2);

    /*
    if (h_fly>=h_cur){
        h_cur = h_fly;
    }

    else{
    h_cur = h_cur - abs(h_fly);
    }
    */

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
                break;
            }

            else if ((Vx>0)and(i==x.size()-1)){
                cout << i;
                break;
            }

            else{

                if (Vx>0){i++;}
                else{i--;}
            }
        }
        else{
            //врезался
            Vy = Vy - g*t;
            t = 0;
            Vx = -Vx;
            s = x[i];

            if (Vx<0){i--;}
            else{i++;}
        }
    }



 }


}
