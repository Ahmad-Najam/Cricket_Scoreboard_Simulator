//Project: Cricket Match Simulation
//Ahmad Najam
//21I-0265
//PF - (C) 

#include<iostream>
#include<fstream>
#include<iomanip> 
#include<ctime>
#include<cstring>
#include<cstdlib> 
#include<string>
#include<math.h> 
using namespace std; 

void individual (string, int, int, double, string);
void innings (int, int);
void summary (int, int, int);
double livescorecard (string, string, int, int, int, int, int, int, double, int, int, double, string, int, int, int, int, int, int, double, bool);

int fall_of_wickets (int f_o_w[10], int wksi)
{
    cout << "                            FALL OF WICKETS                             " << endl; 
    cout << "------------------------------------------------------------------------" << endl; 
    int j=1;
    for (int i=0; i<wksi; i++)
    {
        cout << "                          " << f_o_w[i] << "-" << j << endl;
        j++;
    }
    return 0;
}

int main()
{
    string player, team_name;
    bool flag=false, anotherflag=false, wicket_flag=false; 
    int i, j, k, l, z, c, w, ovari, balli, over_no; 
    string player_names[2][11];
    int batter[2][11]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int ballcount[2][11]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; 
    int bllrrns[2][5]={0,0,0,0,0,0,0,0,0,0};
    int bllrwkts[2][5]={0,0,0,0,0,0,0,0,0,0};
    int bllrovarida[2][5]={0,0,0,0,0,0,0,0,0,0}; 
    int bllrballi[2][5]={0,0,0,0,0,0,0,0,0,0};
    int fow[10];
    bool boolif=false; 
    
    for (i=0; i<2; i++)
    {
        if (i==0)
        team_name = "Pakistan";
        if (i==1)
        team_name = "India"; 
        for (j=0; j<11; j++)
        {
            cout << "Enter player " << j + 1 << " name playing for team " << team_name << " : ";
            getline(cin,player);
            player_names[i][j]=player; 
        }
        cout<<endl; 
    }
    
    //Use of file handling to read value of N from file. 
    { 
        ofstream file1;
        file1.open("configuration.txt");
        file1 << 20 << endl;                //Number of overs 
        file1.close();                                             
    }
    int N;
    {
        ifstream file2;
        file2.open("configuration.txt");
        file2 >> N;
        file2.close(); 
    }
    cout << "The match is of " << N << " overs" << endl;
    
    srand(time(NULL)); 
    
    //Toss. Any team can win and bat.
    int toss = 0 + rand() % 2;          //batting team
    int ntoss;                          //bowling team
    
    if (toss==0)
    {
        team_name="Pakistan";
        ntoss = 1; 
    }
    if (toss==1)
    {
        team_name="India";
        ntoss = 0;
    }
    
    cout << "Team " << team_name << " won the toss\n" << endl;
    
    int g=0;
    j=0, k=0, l=0, z=10, c=0, w=0, ovari=0, balli=0; 
    int total1=0; 
    int total2=0;
    double req_rr = (total1*1.0)/20.0;  
    //player_names[toss][j] will start playing
    
    cout << "Double-Press ENTER to move to the next ball" << endl;
    cout << "Double-Press TAB, then ENTER to move to a certain over" << endl; 
    cout << endl; 
    
    int wicket_count=0, overs, balls;
    double strike_rate;
    double run_rate = 0.0; 
    
    for (overs=0; overs<N; overs++)
    {
        if (bllrballi[ntoss][balli]==6)
        {
            bllrballi[ntoss][balli]=0; 
        }
        if (z==5)
        {   
            z=10;
            c=0;
            w=0;
            ovari=0;
            balli=0; 
        } 
        
        if (anotherflag == true) 
        {
            cout << endl;                           //TO MAKE IT INTERESING, 
            int randtimes = (over_no - overs)*6;    //suppose over_no==13, overs==3, then 10 overs have randed 
            for (int x=0; x<randtimes; x++) 
            {
                int randomize = 0 + rand() % 7; 
                total1+=randomize;
                if (bllrballi[ntoss][balli]==6)
                {
                    bllrballi[ntoss][balli]=0; 
                }
            }
            overs = over_no;
            anotherflag = false; 
        }
        for (balls=1; balls<7; balls++)
        {
            strike_rate = ((batter[toss][k]*1.0)/(ballcount[toss][l]*1.0))*100.0;
            run_rate = ((total1*1.0)/(overs*1.0));
            if (overs==0)
            {
                run_rate = 0.0; 
            }
            boolif=false; 
            livescorecard(player_names[toss][j],player_names[toss][j + 1],total1,wicket_count,batter[toss][k],ballcount[toss][l],batter[toss][k + 1],ballcount[toss][l + 1],strike_rate,overs,balls,run_rate,player_names[ntoss][z],bllrrns[ntoss][c],bllrwkts[ntoss][w],bllrovarida[ntoss][ovari],bllrballi[ntoss][balli],total1,total2,req_rr,boolif); 
            if (cin.get() == '\n')          //Double-ENTER Key to proceed 
            cout << overs << "." << balls << " : "; 
            {
                int p = -1 + rand() % 8; 
                cout << p; 
                if (p==0||1||2||3||4||5||6)
                {
                    total1+=p;
                    batter[toss][k]+=p; 
                    ballcount[toss][l]+=1;
                    bllrrns[ntoss][c]+=p;
                    bllrballi[ntoss][balli]+=1; 
                    if (p%2==0)
                    {
                        //DO NOT rotate strike
                        //else
                        if (wicket_flag==true)
                        {
                            string strike_rotation = player_names[toss][j]; 
                            player_names[toss][j] = player_names[toss][j + 1];
                            player_names[toss][j + 1] = strike_rotation;
                            int rotate = batter[toss][k]; 
                            batter[toss][k] = batter[toss][k + 1];
                            batter[toss][k + 1] = rotate;
                            int rotato = ballcount[toss][l];
                            ballcount[toss][l] = ballcount[toss][l + 1]; 
                            ballcount[toss][l + 1] = rotato; 
                        }
                    }
                    if (p%2!=0) 
                    {
                        //DO rotate strike
                        if (wicket_flag==true)
                        {
                            //do nothing    
                        }
                        else
                        {
                            string strike_rotation = player_names[toss][j]; 
                            player_names[toss][j] = player_names[toss][j + 1];
                            player_names[toss][j + 1] = strike_rotation;
                            int rotate = batter[toss][k]; 
                            batter[toss][k] = batter[toss][k + 1];
                            batter[toss][k + 1] = rotate;
                            int rotato = ballcount[toss][l];
                            ballcount[toss][l] = ballcount[toss][l + 1]; 
                            ballcount[toss][l + 1] = rotato;
                        }
                    }
                    if (p==-1)  
                    {
                        string strike_rotation = player_names[toss][j]; 
                        player_names[toss][j] = player_names[toss][j + 1];
                        player_names[toss][j + 1] = strike_rotation;
                        int rotate = batter[toss][k]; 
                        batter[toss][k] = batter[toss][k + 1];
                        batter[toss][k + 1] = rotate;
                        int rotato = ballcount[toss][l];
                        ballcount[toss][l] = ballcount[toss][l + 1]; 
                        ballcount[toss][l + 1] = rotato;
                        wicket_flag=true;
                        bllrrns[ntoss][c]+=1; 
                        bllrwkts[ntoss][w]+=1; 
                        //display individual scorecard 
                        individual(player_names[toss][j],batter[toss][k]+1,ballcount[toss][l],strike_rate,player_names[ntoss][z]);
                        total1+=1;
                        fow[g]=total1; 
                        g++;
                        wicket_count++; 
                        j++;    //in case of wicket, next batsman is iterated 
                        k++;
                        l++; 
                        if (wicket_count==10)       //All men down
                        {
                            //break out of nested for loop
                            flag=true; 
                            break; 
                        }
                    }
                    if (wicket_flag==true)
                    {
                        string strike_rotation = player_names[toss][j]; 
                        player_names[toss][j] = player_names[toss][j + 1];
                        player_names[toss][j + 1] = strike_rotation;
                        int rotate = batter[toss][k]; 
                        batter[toss][k] = batter[toss][k + 1];
                        batter[toss][k + 1] = rotate;
                        int rotato = ballcount[toss][l];
                        ballcount[toss][l] = ballcount[toss][l + 1]; 
                        ballcount[toss][l + 1] = rotato;
                        wicket_flag=false; 
                    }
                }
            }
            if (cin.get() == '\t')      //Double-TAB Key to move to a certain over
            {
                cout << "Enter the over number to jump to = ";
                cin >> over_no;
                anotherflag=true; 
                break; 
            }
        }
        cout << endl;
        if (flag==true)
        {
            //break out of main for loop
            break;
        }
        //strike rotation upon over completion
        string strike_rotation = player_names[toss][j]; 
        player_names[toss][j] = player_names[toss][j + 1];
        player_names[toss][j + 1] = strike_rotation;
        int rotate = batter[toss][k]; 
        batter[toss][k] = batter[toss][k + 1];
        batter[toss][k + 1] = rotate;
        int rotato = ballcount[toss][l];
        ballcount[toss][l] = ballcount[toss][l + 1]; 
        ballcount[toss][l + 1] = rotato;
        bllrovarida[ntoss][ovari]+=1; 
        z--;
        c++; 
        w++;
        ovari++; 
    }
    
    cout << "\n1st innings have concluded" << endl;
    cout << "Now its time for 2nd innings" << endl; 
    //display innings scorecard
    innings(total1,wicket_count);
    fall_of_wickets(fow,wicket_count); 
    
    flag=false, anotherflag=false, wicket_flag=false; 
    bool yetanotherone=false; 
    
    g=0, j=0, k=0, l=0, z=10, c=0, w=0, ovari=0, balli=0; 
    
    wicket_count=0;
    strike_rate = 0.0;
    run_rate = 0.0;
    
    if (toss==0)    //if team 0 won the toss, team 1 will bat second
    {
        toss=1;
        ntoss=0;
        team_name="India";
    }
    else if (toss==1)    //if team 1 won the toss, team 0 will bat second
    {
        toss=0; 
        ntoss=1; 
        team_name="Pakistan";
    }
    
    //start working on 2nd innings
    for (overs=0; overs<N; overs++)
    {
        if (bllrballi[ntoss][balli]==6)
        {
            bllrballi[ntoss][balli]=0; 
        }
        if (z==5)
        {   
            z=10;
            c=0;
            w=0;
            ovari=0;
            balli=0; 
        } 
        
        if (anotherflag == true) 
        {
            cout << endl;                           //TO MAKE IT INTERESING, 
            int randtimes = (over_no - overs)*6;    //suppose over_no==13, overs==3, then 10 overs have randed 
            for (int x=0; x<randtimes; x++) 
            {
                int randomize = 0 + rand() % 7; 
                total2+=randomize;
                if (bllrballi[ntoss][balli]==6)
                {
                    bllrballi[ntoss][balli]=0; 
                }
            }
            overs = over_no;
            anotherflag = false; 
        }
        for (balls=1; balls<7; balls++)
        {
            if (total2>total1)
            {
                cout << endl << "MATCH OVER" << endl;
                yetanotherone=true;
                break; 
            }
            strike_rate = ((batter[toss][k]*1.0)/(ballcount[toss][l]*1.0))*100.0;
            run_rate = ((total2*1.0)/(overs*1.0));
            if (overs==0)
            {
                run_rate = 0.0; 
            }
            req_rr = ((total1-total2)*1.0)/((20-overs)*1.0); 
            boolif=true; 
            livescorecard(player_names[toss][j],player_names[toss][j + 1],total2,wicket_count,batter[toss][k],ballcount[toss][l],batter[toss][k + 1],ballcount[toss][l + 1],strike_rate,overs,balls,run_rate,player_names[ntoss][z],bllrrns[ntoss][c],bllrwkts[ntoss][w],bllrovarida[ntoss][ovari],bllrballi[ntoss][balli],total1,total2,req_rr,boolif);             
            if (cin.get() == '\n')          //Double-ENTER Key to proceed 
            cout << overs << "." << balls << " : "; 
            {
                int p = -1 + rand() % 8; 
                cout << p; 
                if (p==0||1||2||3||4||5||6)
                {
                    total2+=p;
                    batter[toss][k]+=p; 
                    ballcount[toss][l]+=1;
                    bllrrns[ntoss][c]+=p;
                    bllrballi[ntoss][balli]+=1; 
                    if (p%2==0)
                    {
                        //DO NOT rotate strike
                        //else
                        if (wicket_flag==true)
                        {
                            string strike_rotation = player_names[toss][j]; 
                            player_names[toss][j] = player_names[toss][j + 1];
                            player_names[toss][j + 1] = strike_rotation;
                            int rotate = batter[toss][k]; 
                            batter[toss][k] = batter[toss][k + 1];
                            batter[toss][k + 1] = rotate;
                            int rotato = ballcount[toss][l];
                            ballcount[toss][l] = ballcount[toss][l + 1]; 
                            ballcount[toss][l + 1] = rotato; 
                        }
                    }
                    if (p%2!=0) 
                    {
                        //DO rotate strike
                        if (wicket_flag==true)
                        {
                            //do nothing    
                        }
                        else
                        {
                            string strike_rotation = player_names[toss][j]; 
                            player_names[toss][j] = player_names[toss][j + 1];
                            player_names[toss][j + 1] = strike_rotation;
                            int rotate = batter[toss][k]; 
                            batter[toss][k] = batter[toss][k + 1];
                            batter[toss][k + 1] = rotate;
                            int rotato = ballcount[toss][l];
                            ballcount[toss][l] = ballcount[toss][l + 1]; 
                            ballcount[toss][l + 1] = rotato;
                        }
                    }
                    if (p==-1)  
                    {
                        string strike_rotation = player_names[toss][j]; 
                        player_names[toss][j] = player_names[toss][j + 1];
                        player_names[toss][j + 1] = strike_rotation;
                        int rotate = batter[toss][k]; 
                        batter[toss][k] = batter[toss][k + 1];
                        batter[toss][k + 1] = rotate;
                        int rotato = ballcount[toss][l];
                        ballcount[toss][l] = ballcount[toss][l + 1]; 
                        ballcount[toss][l + 1] = rotato;
                        wicket_flag=true;
                        bllrrns[ntoss][c]+=1; 
                        bllrwkts[ntoss][w]+=1; 
                        //display individual scorecard 
                        individual(player_names[toss][j],batter[toss][k]+1,ballcount[toss][l],strike_rate,player_names[ntoss][z]);
                        total2+=1;
                        fow[g]=total2; 
                        g++;
                        wicket_count++; 
                        j++;    //in case of wicket, next batsman is iterated 
                        k++;
                        l++; 
                        if (wicket_count==10)       //All men down
                        {
                            //break out of nested for loop
                            flag=true; 
                            break; 
                        }
                    }
                    if (wicket_flag==true)
                    {
                        string strike_rotation = player_names[toss][j]; 
                        player_names[toss][j] = player_names[toss][j + 1];
                        player_names[toss][j + 1] = strike_rotation;
                        int rotate = batter[toss][k]; 
                        batter[toss][k] = batter[toss][k + 1];
                        batter[toss][k + 1] = rotate;
                        int rotato = ballcount[toss][l];
                        ballcount[toss][l] = ballcount[toss][l + 1]; 
                        ballcount[toss][l + 1] = rotato;
                        wicket_flag=false; 
                    }
                }
            }
            if (cin.get() == '\t')      //Double-TAB Key to move to a certain over
            {
                cout << "Enter the over number to jump to = ";
                cin >> over_no;
                anotherflag=true; 
                break; 
            }
        }
        cout << endl;
        if (yetanotherone==true)
        {
            break; 
        }
        if (flag==true)
        {
            //break out of main for loop
            break;
        }
        //strike rotation upon over completion
        string strike_rotation = player_names[toss][j]; 
        player_names[toss][j] = player_names[toss][j + 1];
        player_names[toss][j + 1] = strike_rotation;
        int rotate = batter[toss][k]; 
        batter[toss][k] = batter[toss][k + 1];
        batter[toss][k + 1] = rotate;
        int rotato = ballcount[toss][l];
        ballcount[toss][l] = ballcount[toss][l + 1]; 
        ballcount[toss][l + 1] = rotato;
        bllrovarida[ntoss][ovari]+=1; 
        z--;
        c++; 
        w++;
        ovari++; 
    }
    //stop working on 2nd innings
    
    innings(total2,wicket_count);
    fall_of_wickets(fow, wicket_count); 
    summary(total1,total2,toss);
    
    cout << "\n    MATCH HAS CONCLUDED";
    cout << "\nTHANKYOU SO MUCH FOR JOINING" << endl; 
    cout << endl;
    
    int x; 
    
    cout << "ENTER (1) to see SHORT SUMMARY of the match" << endl;
    cout << "ENTER (2) to see FIRST INNINGS of the match" << endl;
    cout << "ENTER (3) to see SECOND INNINGS of the match" << endl;
    cout << "ENTER (4) to SAVE MATCH DATA" << endl;
    cout << "ENTER (5) to LOAD MATCH DATA" << endl;
    
    cin >> x; 
    
    switch (x)
    {
        case 1:
        cout << "The match summary is as follows : " << endl;
        summary(total1,total2,toss);
        break;
        case 2:
        cout << "The first innings are as follows : " << endl; 
        innings(total1,wicket_count); 
        break;
        case 3:
        cout << "The second innings are as follows : " << endl; 
        innings(total2,wicket_count);
        break;
        case 4:
        cout << "Match data has been saved" << endl;
        break;
        case 5: 
        cout << "Match data has been loaded" << endl; 
        break; 
        default:
        cout << "The Entered number should be between 1 and 5" << endl; 
        break;
    }
    
    return 0;
}

void individual (string name, int score, int gandein, double astrekerate, string ballr)
{
    cout << "\n" << endl;
    cout << "---------------------------------------------------------------------" << endl;
    cout << "\t" << name << "   -------------   " << score << "(" << gandein << ")" << " S-R : " << astrekerate << endl;  
    cout << "\t" << "Wicket by : " << ballr << endl;
    cout << "---------------------------------------------------------------------" << endl;
    cout << endl;
}

void innings (int inn, int w)  
{
    cout << endl; 
    cout << "---------------------------------------------------------------------" << endl;
    cout << "                          TOTAL : " << inn << "/" << w << endl; 
    cout << "---------------------------------------------------------------------" << endl;
}

void summary (int t1, int t2, int t)
{
    cout << "\n" << endl;
    cout << "---------------------------------------------------------------------" << endl;
    cout << "                          FIRST INNINGS                              " << endl;
    cout << "---------------------------------------------------------------------" << endl;
    cout << "                           TOTAL : " << t1 << endl; 
    cout << "---------------------------------------------------------------------" << endl;
    cout << "                         SECOND INNINGS                              " << endl;
    cout << "---------------------------------------------------------------------" << endl;
    cout << "                           TOTAL : " << t2 << endl;
    cout << "---------------------------------------------------------------------" << endl;
    if (t1>t2) 
    {
        if (t==0)  
        {
            cout << "       Pakistan";
        }
        if (t==1) 
        {
            cout << "       India"; 
        }
        cout << " has won the match by " << t1-t2 << " runs" << endl;
    }
    if (t2>t1) 
    {
        if (t==0) 
        {
            cout << "        Pakistan";
        }
        if (t==1)
        {
            cout << "        India"; 
        }
        cout << " has won the match" << endl; 
    }
    cout << "---------------------------------------------------------------------" << endl;
}

double livescorecard (string batter, string runner, int total_runs, int wickets, int bat_run, int bc, int bat_run1, int bc1, double sr, int ov, int blls, double rr, string bllrnm, int blrr, int wkts, int ovr, int bll, int target, int second, double required, bool boolza)
{
    cout << endl; 
    cout << "------------------------------------------------------------------------" << endl; 
    cout << "                   LIVE MATCH\t   " << "Pakistan V India                 " << endl;
    cout << "------------------------------------------------------------------------" << endl;
    cout << "                        NET - TOTAL : " << total_runs                     << endl;
    cout << "------------------------------------------------------------------------" << endl;
    cout << "     WICKETS LOST : " << wickets << "              WICKETS REMAINING : " << 10 - wickets << endl; 
    cout << "------------------------------------------------------------------------" << endl;
    cout << "                      STRIKER : " << batter << endl;           
    cout << "                     RUNS/BALLS : " << bat_run << "(" << bc << ")" << endl;
    cout << "------------------------------------------------------------------------" << endl;
    cout << "                   NON - STRIKER : " << runner << endl; 
    cout << "                     RUNS/BALLS : " << bat_run1 << "(" << bc1 << ")" << endl; 
    cout << "------------------------------------------------------------------------" << endl; 
    cout << "                   STRIKE - RATE : " << sr << "\t\t"                  << endl;  
    cout << "------------------------------------------------------------------------" << endl;
    cout << "       OVERS BOWLED : " << ov << "." << blls - 1 << "\t     OVERS REMAINING : " << 19 - ov << "." << 8 - (blls + 1) << endl; 
    cout << "------------------------------------------------------------------------" << endl; 
    cout << "\t                 RUN - RATE : " << rr << endl;
    cout << "------------------------------------------------------------------------" << endl;
    cout << "\t               BOWLER : " << bllrnm << endl; 
    cout << "\t     RUNS CONCEDED / WICKETS TAKEN : " << blrr << "-" << wkts << endl; 
    cout << "\t               OVERS BOWLED : " << ovr << "." << bll << endl;
    cout << "------------------------------------------------------------------------" << endl;
    
    if (boolza==true)
    {
        cout << "                           TARGET : " << target + 1 << endl; 
        cout << "                         REMAINING : " << (target + 1) - second << endl; 
        cout << "                        REQUIRED RATE : " << required << endl; 
        cout << "------------------------------------------------------------------------" << endl;
    }
    return 0;
}

