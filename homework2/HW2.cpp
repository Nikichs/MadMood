#include <bits/stdc++.h>
using namespace std;

int main()
{


double Vx, Vy, h0;
vector <double> x;
vector <double> h;


double vxr, vyr, h0r, hr, xr;


ifstream f("in.txt");
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


 //int x[] = {3, 1, 6, 9};
 //int h[] = {2, 3, 1, 4};
 //double Vx = 1;
 //double Vy = 2;
 //double h0 = 10;
 double s, t, h_fly, h_cur;
 s = 0;
 h_cur = h0;


 int i = 0;


 while (h_cur>0){


    s = abs(x[i]-s);
    t = s/Vx;
    h_fly = Vy*t -((g*t*t)/2);

    h_cur = h_cur - h_fly;


    //упал в полете
    if (h_cur<=0){
        cout << i+1;
        break;
    }

    //врезался в стенку/над ней

    else{


        //пролет
        if (h_cur>h[i]){
                // границы перелетел

            //cout<<"perelet " << i <<" "<<x[i]<<endl;


            //i = 4 => length(x)...

            if ((Vx<0)and(i==1)){
                cout << 0;
                break;
            }

            else if ((Vx>0)and(i==x.size())){
                cout << i+1;
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
