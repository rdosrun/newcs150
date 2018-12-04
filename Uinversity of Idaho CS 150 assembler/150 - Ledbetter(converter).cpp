/*Made by Richard Ledbetter 
	Fall 2017 
	Revised 2018 - Richard Ledbetter
	please leave your name and date for further revisions
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include "tree.h"
using namespace std;
int line_num = 0;
string binary(int num);//converts num to binary
string parse(string & x, char y);// retruns string up to y and deltles prior chars
string parse(string & x,char y1,char y2,char y3);
double string2double(string num);
string convert(string x);
string int2string(int x);
int main(){
    ofstream out_file;
    out_file.open("outfile.bin");
	//OPENING IN FILE
	string line;
	ifstream in,in2,in3;
    in.open("blinky.txt");//fseek seekset
    in2.open("blinky.txt");
    in3.open("blinky.txt");
    if(!in.is_open()&&!in2.is_open()){
        cout<<"error";
        return 0;
    }
    //INSTRUCTION AND VARIABLE DECLERATION
    string instruct;
    int i =0;
    tree *w = new tree();
    w->root = NULL;
   while(getline(in2,line)){
        node *tmp = new node();
        if(line[line.length()-1]==':'){
        	string use ="";
        	for (int u = 0; u < line.length()-1; ++u)
        	{
        		use = use+line[u];
        	}
            tmp->info_string = use;
            tmp->info_num = i;
            w->add_node(w->root,tmp);
            cout<<"test lookup:"<<w->lookup_node(w->root,tmp->info_string)<<endl<<endl;
        }
        i++;
    }
    //String stream| .find
    //HASH TABLE
    string list[400];
    if (true)
    {
		list[200] = "000111rdddddrrrr";//ADC
		list[201] = "000011rdddddrrrr";//ADD
		list[211] = "001000rdddddrrrr";//AND
		list[284] = "0111kkkkddddkkkk";//ANDI
		list[326] = "1001010ddddd0101";//asr LOWER CASE!!!
		list[281] = "111101kkkkkkksss";//BRBC
		list[297] = "111100kkkkkkksss";//BRBS
		list[284] = "1001010000001110\nkkkkkkkkkkkkkkkk";//CALL
		list[223] = "1001010ddddd0000";//COM
		list[147] = "000101rdddddrrrr";//CP
		list[220] = "0011kkkkddddkkkk";//CPI
		list[230] = "001001rdddddrrrr";//EOR
		list[151] = "10110aadddddaaaa";//IN
		list[231] = "1001010000001100\n0kkkkkkkkkkkkkkk";//JMP
		list[217] = "1110kkkkddddkkkk";//LDI
		list[227] = "1001000ddddd0000\nkkkkkkkkkkkkkkkk";//LDS
		list[241] = "1001010ddddd0110";//LSR
		list[242] = "001011rdddddrrrr";//MOV
		list[218] = "1001010ddddd0001";//NEG
		list[398] = "0000000000000000";//NOP
		list[234] = "001010rdddddrrrr";//ORI
		list[248] = "10111aadddddaaaa";//OUT
		list[239] = "1001000ddddd1111";//POP
		list[320] = "1001001rrrrr1111";//PUSH
		list[366] = "1101kkkkkkkkkkkk";//RCALL
		list[235] = "1001010100001000";//RET
		list[308] = "1001010100011000";//RETI
		list[313] = "1100kkkkkkkkkkkk";//RJMP
		list[250] = "1001001rrrrr0000\nkkkkkkkkkkkkkkkk";//STS
    }

    //READ FILE IN
    int u= 0;
    int tempcount =0;
    while(getline(in,line)){
        cout<<"0"<<endl;
    	tempcount++;
    	string lol = line;
        bool temp= false;
        for (int i = 0; i < line.length(); ++i)
        {
            if (line[i]==':')
            {
                temp = true;
            }
        }
        if (line==""||temp)
        {
            
        }else{
           
        	int counter2 [5]= {0,0,0,0,0};//SAKRD

        	//PARSING LINE
        	//PARSING INSCTRUCTION
            line_num++;
        	while(line[0]<64||line[0]>123){
                for (int j = 0; j < line.length()-1; ++j)
        		{
            		line[j] = line[j+1];
       			}

       			line.erase(line.length()-1);
                if (line.length()==0)
                {
                    break;
                }

        	}

        	instruct = parse(line,' ');
        	//HASH INSCTRUCTION LOOK-UP
            u = 0;
        	for (int i = 0; i < instruct.length(); ++i){
                if(instruct[i]>64&&instruct[i]<123){
        		  u = u + (int)instruct[i];
                }
        	}

    		instruct = list[u];	
		    string R ="";
			string D ="";
		    string K ="";
		    string S ="";
		    string A ="";
    		//VARIABLE ASSIGNMENT AND PARSE
        	if(line[0]=='R'){
        		D = (parse(line,','));
        	}
        	if(line[0]=='R'){
        		R = (parse(line,','));
        	}
       		for (int i = 0; i < instruct.length(); ++i)
       		{
       			if (instruct[i]=='s'&&S=="")
       			{
       				S = (parse(line,' '));
       			}else if (instruct[i]=='a'&&A=="")
       			{
       				A = (parse(line,' '));
       			}else if (instruct[i]=='k'&& K=="")
       			{
       				K = line;//(parse(line,' '));
       			}
       		}
       		if(line[0]=='R'){
        		D = (parse(line,' '));
        	}
        	if(line[0]=='R'){
        		R = (parse(line,' '));
        	}
            cout<<"3"<<endl;
        	//BIT LENGTH REQUIREMENT
        	S = convert(S);
        	counter2[0] = S.length();
        	if (A=="PORTB,"){
            		A="5";
            }else if(A=="DDRB, "){
            		A = "4";
            }
        	A = convert(A);
        	counter2[1] = A.length();
            if (K!="")
            {
            	while(K[0]<48||K[0]>123){
	                for (int j = 0; j < K.length()-1; ++j)
	        		{
	            		K[j] = K[j+1];
	       			}
	       			K.erase(K.length()-1);
        		}
				if(K[1]=='x'){
					int tmp = 0;
					for (int i = 0; i < K.length()-2 ; ++i)
					{
						int use = K[K.length()-(i+1)]-48;
						tmp =tmp + (pow(16,i)*use);
					}
					K = int2string(tmp);
				}
            	else if (K=="DELAYUNIT")
            	{
            		//cout<<K<<" test lookup:"<<int2string(w->lookup_node(w->root ,K))<<endl;
            		K="78";
            	}else {
               	 	K = int2string(w->lookup_node(w->root ,K));
               	}
            }
        	K = convert(K);
        	counter2[2] = K.length();
        	R = convert(R);
        	counter2[3] = R.length();
        	D = convert(D);
        	counter2[4] = D.length();
        	int max_length [5]= {0,0,0,0,0};//SAKRD
        	for (int i = 0; i < instruct.length(); ++i)
        	{// THIS FINDS HOW MANY BITS EACH INPUT IS
        		if (instruct[i]=='s')
        		{
        			max_length[0]++;
        		}else if (instruct[i]=='a')
        		{
        			max_length[1]++;
        		}else if (instruct[i]=='k')
        		{
        			max_length[2]++;
        		}else if (instruct[i]=='r')
        		{
        			max_length[3]++;
        		}else if (instruct[i]=='d')
        		{
        			max_length[4]++;
        		}
        	}
        	for (int i = 0; i <5; ++i)
        	{//THIS SETS THE STARTING POINT TO START READING THE BIT INPUT STRING
        		int tmp = counter2[i];
        		counter2[i] = (counter2[i]-max_length[i]); 
        		max_length[i] = tmp+max_length[i];
        	}
        	for (int i = 0; i < instruct.length(); ++i)
        	{//THIS PLACES THE PROPPER AMOUNT OF BITS IN PLACE OF THE VARIABLE PLACE HOLDER
        		if (instruct[i]=='s'&&counter2[0]>=max_length[0])
        		{
        			instruct[i] = S[counter2[0]];
        			counter2[0]++;
        		}else if (instruct[i]=='a'&&counter2[1]<=max_length[1])
        		{
        			instruct[i] = A[counter2[1]];
        			counter2[1]++;
        		}else if (instruct[i]=='k'&&counter2[2]<=max_length[2])
        		{
        			instruct[i] = K[counter2[2]];
        			counter2[2]++;
        		}else if (instruct[i]=='r'&&counter2[3]<=max_length[3])
        		{
        			instruct[i] = R[counter2[3]];
        			counter2[3]++;
        		}else if (instruct[i]=='d'&&counter2[4]<=max_length[4])
        		{
        			instruct[i] = D[counter2[4]];
        			counter2[4]++;
        		}
        	}
        	//PRINTS BINARY OF INSCTRUCTION
        	for (int i = 1; i <= instruct.length(); ++i)
        	{
        		out_file<<instruct[i-1];
        		if(i%4==0){
        			out_file<<"  ";
        		}
        	}
        	if (instruct!="")
        	{
        		//cout<<lol<<":"<<tempcount;
        		out_file<<endl;
        	}
        	u = 0;
        }
    }
}
string parse(string & x,char y1,char y2,char y3){
    string z= "";
    int i=0;
    while((x[0]!=y1&&x[0]!=y2)&&(x.length()>i&&x[0]!=y3)){
        z=z+x[0];
        x[0]=127;//deletes char
        for (int j = 0; j < x.length()-1; ++j)
        {
            x[j] = x[j+1];
        }
        x.erase(x.length()-1); 
        i++;
    }
    for (int j = 0; j < x.length()-1; ++j)
    {
        x[j] = x[j+1];
    }

    return z;
}
string parse(string &x, char y){
	string z= "";
	int i=0;
    if (x.length()==0)
    {
       return "";
    }
    cout<<"something"<<endl;
	//cout<<x<<" ";
	while(x[0]!=y&&x.length()>i){
		z=z+x[0];
		x[0]=127;//deletes char
		for (int j = 0; j < x.length()-1; ++j)
		{
			x[j] = x[j+1];
		}
		x.erase(x.length()-1); 
		i++;
	}
	z=z+x[0];
	for (int j = 0; j < x.length()-1; ++j)
	{
		x[j] = x[j+1];
	}
	x.erase(x.length()-1);
	return z;
}
string convert(string x){
	int w = string2double(x);
	return binary(w);
}
string int2string(int x){
	string tmp = "";
	while(x>0){
		int rem = x%10;
		x = x/10;
		char rem2 = rem+48;
		tmp = rem2+tmp;
	}
	return tmp;
}
double string2double(string num){
	bool dec = false;
	bool neg = false;
	double x =0.0;
	double count = 10;
	for (int i = 0; i < num.length(); ++i)
	{
		if(num[i]=='-'){
			neg = true;
		}else if(num[i]=='.'){
			dec=false;
		}else if (num[i]>'9'||num[i]<'0')
		{
		}else if(dec ==false){
			x = (x*10)+num[i]-48;
		}else{
			x = x+((double)(num[i]-48)/count);
			count= count*10.0;
		}
	}
	return x;
}
string binary(int num)
{
    int rem = 0;
    string x = "000000000000000";
    string y ="";
    while(num>1){
    	rem = num % 2;
    	if (rem ==1)
    	{
    		y = "1"+y;
    	}else{
    		y = "0"+y;
    	}
    	num = num/2;
    }
    	if (num ==1)
    	{
    		y = "1"+y;
    	}else{
    		y = "0"+y;
    	}
    	x = x+y;
        return x;
}