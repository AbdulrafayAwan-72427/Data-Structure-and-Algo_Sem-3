#include<iostream>
using namespace std;
int main()
{
    const float acc = 30;
    const float time = 5;
    float ini_vel;

    cout<<"Enter Initial Velocity"<<endl;
    cin>>ini_vel;
    cout<<"Final Velocity is : "<<ini_vel+acc*time<<endl;

}