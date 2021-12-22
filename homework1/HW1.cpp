#include <bits/stdc++.h>
using namespace std;

double cos(double x, double y, double x0, double y0) {
        double scalar = x0*x + y0*y;
        double mod_mult = sqrt(x0*x0 +y0*y0)*sqrt(x*x +y*y);
        if (mod_mult ==0){
            return -1;
        }
        else {return scalar/mod_mult;}
    }

int main()
{


    double xr, yr;
    double x0, y0;
    vector <double> x;
    vector <double> y;
    bool on_line = false;

    ifstream f("in.txt");
    if ((f.is_open()))  // проверка наличия файла с тестом

    {
        int cnt = 0;
        while(!f.eof()){
            f>>xr>>yr;
            if (cnt==0){
                x0 = xr;
                y0 = yr;
            }
            else{
                x.push_back(xr);
                y.push_back(yr);
            }

            cnt++;
        }
    }

    f.close();

    //пустые массивы
    vector <double> x_left;
    vector <double> x_right;
    vector <double> y_left;
    vector <double> y_right;
    vector <double> cos_left;
    vector <double> cos_right;


    for (int i = 0; i<=x.size()-1; i++){
        double D = x0*y[i]-y0*x[i];
        if (D>0){
            x_left.push_back(x[i]);
            y_left.push_back(y[i]);

        }

        else if (D==0){

            if (on_line == false) {
                x_right.push_back(x[i]);
                y_right.push_back(y[i]);
                on_line = true;
            }

        }

        else{

            x_right.push_back(x[i]);
            y_right.push_back(y[i]);
        }
    }


    // левые точки

    if (x_left.size()!=0){
    for (int i = 0; i<=x_left.size()-1;i++){
        cos_left.push_back(cos(x_left[i], y_left[i], x0, y0));
    }
    }
    else if (x_left.size()==0){
        x_left = {0};
        y_left = {0};
        cos_left = {-1};
    }
    //правые

    if (x_right.size()!=0){
        for (int i = 0; i<=x_right.size()-1;i++){
        cos_right.push_back(cos(x_right[i], y_right[i], x0, y0));
    }
    }

    else if (x_right.size()==0){
        x_right = {0};
        y_right = {0};
        cos_right = {-1};
    }

    int left_ind = min_element(cos_left.begin(),cos_left.end()) - cos_left.begin();
    int right_ind = min_element(cos_right.begin(),cos_right.end()) - cos_right.begin();


    cout << "Leftmost: " << x_left[left_ind]<<" "<<y_left[left_ind] << endl;
    cout << "Rightmost: " << x_right[right_ind]<<" "<<y_right[right_ind];
