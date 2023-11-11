//created by Aayushi 23rd May 2023
#include <bits/stdc++.h>
using namespace std;

class HybridA
{
public:
  string typeofSignal; //whether signal is linear, fixed, etc.
  double no_of_cp;     //Number of control lines
  double time_Horizon; //Total time

public:
  void setData(string sig, double control_points, double totalTime)
  {
    typeofSignal = sig;
    no_of_cp = control_points;
    time_Horizon = totalTime;
  }

  void calculateLinear()
  {
    cout << "Performing calculation for linear signal" << endl;
    int time_frames = (time_Horizon / no_of_cp);
    int modes = no_of_cp - 1;
    double length = time_Horizon / modes;
    cout << "Total time frames are: " << time_frames << endl;
    cout << "Number of modes are: " << modes << endl;
    cout << "Length of each time frame is: " << length << endl;
    vector<double> gt(no_of_cp);
    gt[0] = 0.0; //start with t0 = 0
    cout << "t0: " << gt[0] << endl;
    for (double i = 1; i < no_of_cp; i++)
    {
      gt[i] = gt[i - 1] + length;
      cout << "t" << i << ": " << gt[i] << endl;
    }
  }

  void calculateFixed()
  {
    cout << "Performing calculation for fixed signal" << endl;
    int time_frames = no_of_cp;
    int modes = no_of_cp;
    double length = time_Horizon / modes;
    cout << "Total time frames are: " << time_frames << endl;
    cout << "Number of modes are: " << modes << endl;
    cout << "Length of each time frame is: " << length << endl;
    vector<double> gt(no_of_cp + 1);
    gt[0] = 0.0; //start with t0 = 0
    cout << "t0: " << gt[0] << endl;
    for (double i = 1; i <= no_of_cp; i++)
    {
      gt[i] = gt[i - 1] + length;
      cout << "t" << i << ": " << gt[i] << endl;
    }
  }

  void ODElinear()
  {
    cout << "Performing ODE calculation for linear signal" << endl;
    vector<double> gt(no_of_cp);
    vector<string> RHS(no_of_cp);
    vector<string> LHS(no_of_cp);
    vector<string> final(no_of_cp);
    int time_frames = (time_Horizon / no_of_cp);
    int modes = no_of_cp - 1;
    double length = time_Horizon / modes;
    gt[0] = 0.0; //start with t0 = 0
    for (double i = 1; i < no_of_cp; i++)
    {
      gt[i] = gt[i - 1] + length;
    }
    if (typeofSignal == "Linear")
    {
      for (int i = 1; i <= no_of_cp - 1; i++)
      {
        if (i == 1)
        {
          //first control point
          RHS[i] = "u_c2 - u_c1";
          LHS[i] = to_string(gt[2]-gt[1]);
          final[i] = "u'(" + to_string(i) + ") = (" + RHS[i] + ") / (" + LHS[i] + ")";
        }
        else
        {
          //intermediate control points
          RHS[i] = "u_c" + to_string(i + 1) + " - u_c" + to_string(i);
          LHS[i] = to_string(gt[2]-gt[1]);
          final[i] = "u'(" + to_string(i) + ") = (" + RHS[i] + ") / (" + LHS[i] + ")";
        }
      }
    }
    string LHS_expression="gt'";
    string RHS_expression="1";
    string final_expression="gt'=1";
    vector<string>c(no_of_cp);
    for(int i=0;i<no_of_cp;i++)
    {
        c[i]="u_c'(" + to_string(i+1) + ") = 0";
    }
    for (int i = 1; i <= no_of_cp - 1; i++)
    {
      cout << final[i] << endl;
    }
    cout<<final_expression<<endl;
    for(int i=0;i<no_of_cp;i++)
    {
        cout<<c[i]<<endl;
    }
  }

  void ODEfixed()
  {
    cout << "Performing calculation for fixed-step signal" << endl;
    vector<string> RHS(no_of_cp + 1);
    vector<string> LHS(no_of_cp + 1);
    vector<string> final(no_of_cp + 1);
    int time_frames = no_of_cp;
    int modes = no_of_cp;
    double length = time_Horizon / modes;
    vector<double> gt(no_of_cp + 1);
    gt[0] = 0.0; //start with t0 = 0
    for (double i = 1; i <= no_of_cp; i++)
    {
      gt[i] = gt[i - 1] + length;
    }
    if (typeofSignal == "Fixed-Step")
    {
      for (int i = 1; i <= no_of_cp; i++)
      {
        if (i == 1)
        {
          //first control point
          RHS[i] = "u_c1 - u_c1";
          LHS[i] = to_string(gt[2]-gt[1]);
          final[i] = "u'(" + to_string(i) + ") = (" + RHS[i] + ") / (" + LHS[i] + ")";
        }
        else
        {
          //intermediate control points
          RHS[i] = "u_c" + to_string(i) + " - u_c" + to_string(i);
          LHS[i] = to_string(gt[2]-gt[1]);
          final[i] = "u'(" + to_string(i) + ") = (" + RHS[i] + ") / (" + LHS[i] + ")";
        }
      }
    }
    string LHS_expression="gt'";
    string RHS_expression="1";
    string final_expression="gt'=1";
    vector<string>c(no_of_cp);
    for(int i=0;i<no_of_cp;i++)
    {
        c[i]="u_c'(" + to_string(i+1) + ") = 0";
    }
    for (int i = 1; i <= no_of_cp; i++)
    {
      cout << final[i] << endl;
    }
    cout<<final_expression<<endl;
    for(int i=0;i<no_of_cp;i++)
    {
        cout<<c[i]<<endl;
    }
  }
  void invariantLinear()
  {  
     cout<<"Calculating Invariant"<<endl;
     int time_frames = (time_Horizon / no_of_cp);
    int modes = no_of_cp - 1;

    //vector<double> gt(no_of_cp);
    //gt[0] = 0.0; // start with t0 = 0

    //for (int i = 1; i < no_of_cp; i++)
    //{
        //gt[i] = gt[i - 1] + (time_Horizon / no_of_cp);
    //}

    vector<string> inv(modes);
    for (int i = 0; i < modes; i++)
    {
        inv[i] = "t" + to_string(i + 1) + " <= gt <= t" + to_string(i + 2);
    }

    for (int i = 0; i < modes; i++)
    {
        cout << inv[i] << endl;
    }
  }
  void invariantFixed()
  {
    cout<<"Calculating Invariant"<<endl;
    int time_frames = (time_Horizon / no_of_cp);
    int modes = no_of_cp;
    vector<string> inv(modes);
    for (int i = 0; i < modes; i++)
    {
        inv[i] = "t" + to_string(i + 1) + " <= gt <= t" + to_string(i + 2);
    }

    for (int i = 0; i < modes; i++)
    {
        cout << inv[i] << endl;
    }
  }
  void guardLinear()
  {   
      cout<<"Calulating Guard"<<endl;
      int time_frames=(time_Horizon/no_of_cp);
      int modes=no_of_cp-1;
      vector<string>guard(modes);
      for(int i=0;i<modes;i++)
      {
          guard[i]="gt >= t" + to_string(i+2) + "&&" + "gt <= t" + to_string(i+2);
      }
      for(int i=0;i<modes;i++)
      {
          cout<<guard[i]<<endl;
      }
  }
  void guardFixed()
  {
      cout<<"Calculating Guard"<<endl;
      int time_frames=(time_Horizon/no_of_cp);
      int modes=no_of_cp;
      vector<string>guard(modes);
      for(int i=0;i<modes;i++)
      {
          guard[i]="gt >= t" + to_string(i+2) + "&&" + "gt <= t" + to_string(i+2);
      }
      for(int i=0;i<modes;i++)
      {
          cout<<guard[i]<<endl;
      }
  }
  void assignment()
  {   
      cout<<"Performing assignment"<<endl;
      string LHS="u_gt'";
      string RHS="u_gt";
      string expression="u_gt'=u_gt";
      cout<<expression<<endl;
  }
};

int main()
{
  HybridA obj;
  string s;
  int n;
  int T;
  cout << "Enter the type of Signal: ";
  cin >> s;
  cout << "Enter the number of control points: ";
  cin >> n;
  cout << "Enter the total time: ";
  cin >> T;
  obj.setData(s, n, T);
  if (s == "Linear")
  {
    obj.calculateLinear();
    obj.ODElinear();
    obj.invariantLinear();
    obj.guardLinear();
    obj.assignment();
  }
  else if (s == "Fixed-Step")
  {
    obj.calculateFixed();
    obj.ODEfixed();
    obj.invariantFixed();
    obj.guardFixed();
    obj.assignment();
  }
  else
  {
    cout << "Invalid signal type entered" << endl;
  }
  return 0;
}
