//Chase Bradshaw

// filereading youtube video: https://www.youtube.com/watch?v=ndVIGhNpzH4

#include <iostream> //input-output stream
#include <fstream> //Library that allows to read and write to files
#include <cmath>   //Library for more advanced math functions, like pow
#include <cstring> //for the toupper method
#include <cstdio>
#include <cctype>
using namespace std;

int getMean (string fileName){
    int strCounter = 0;
    int strLength = 0;
    string line = " ";                      //declare as empty string
    fstream stream;                         //from fstream lib
    stream.open(fileName);               //opens text file
    while (getline(stream,line)){        //gets the line from mystream and store it to line
        //cout<<line<<'\n';
        strLength = strLength+line.length();
        strCounter++;
        //cout<<"line: "<<strCounter<<" size: "<<strLength<<'\n';
    }
    int mean = strLength/strCounter;
    return mean;
    stream.close();
}
int getSum (string fileName){           //reads file to get sum of line lengths
    int sum = 0;
    string line = " ";
    fstream stream;
    stream.open(fileName);
    while(getline(stream,line)){
        sum = sum+line.length();
    }
    return sum;
    stream.close();
}
int getVariance (string fileName, int mean){        //unfarmiliar with the concept of variance
    string line = " ";
    int vAdd = 0;
    int counter = 0;
    fstream stream;
    stream.open(fileName);
    while(getline(stream,line)){
        int tempLen = line.length();
        int tempSqr = pow(tempLen, 2);
        vAdd = vAdd+tempSqr;
        counter++;
    }
    int variance = vAdd/counter;
    return variance;
    stream.close();
}
int getStandardDeviation(int variance){             //just takes the sqare root of the variance
    int standardDeviation = sqrt(variance);
    return standardDeviation;
}
int calculateProbability(string fileName, string fileToWriteTo){            //calculates the probability that a character is an A G C T
    int aCounter = 0;
    int gCounter = 0;                                                       //method works correctly, except for some reason the data is not able to be written to my output file
    int cCounter = 0;
    int tCounter = 0;
    double totalCount = 0;
    string line = " ";
    fstream stream;
    stream.open(fileName);                                              //stream reads from the provided file
    while(getline(stream,line)){
        string parse = line;
        for (int i=0; i<line.length(); ++i){
            string tempStr = parse.substr(i,1);
            if((tempStr=="a")||(tempStr=="A")){
                aCounter++;
                //cout<<"A Counter!";
            }
            if((tempStr=="g")||(tempStr=="G")){
                gCounter++;
                //cout<<"G Counter!";
            }
            if((tempStr=="c")||(tempStr=="C")){
                cCounter++;
                //cout<<"C Counter!";
            }
            if((tempStr=="t")||(tempStr=="T")){
                tCounter++;
                //cout<<"T Counter!";
            }
        }
    }
    stream.close();

    totalCount = aCounter+gCounter+cCounter+tCounter;

    double aProb = aCounter/totalCount;                                         //prob = probability
    double gProb = gCounter/totalCount;
    double cProb = cCounter/totalCount;
    double tProb = tCounter/totalCount;

    ofstream fileWrite;
    fileWrite.open(fileToWriteTo,  std::ios_base::app);
    fileWrite<<'\n';
    fileWrite<<"A Probability: "<< aProb*100<<"%"<<'\n';
    fileWrite<<"G Probability: "<< gProb*100<<"%"<<'\n';
    fileWrite<<"C Probability: "<< cProb*100<<"%"<<'\n';
    fileWrite<<"T Probability: "<< tProb*100<<"%"<<'\n';
                                                                //for whatever reason i cannot get this to write to a file, so i printed it to show it works
    cout<<"A Probability: "<< aProb*100<<"%"<<'\n';
    cout<<"G Probability: "<< gProb*100<<"%"<<'\n';
    cout<<"C Probability: "<< cProb*100<<"%"<<'\n';
    cout<<"T Probability: "<< tProb*100<<"%"<<'\n';


    fileWrite<<'\n';
    fileWrite.close();
    return 1;
}
int calculateDoubleProbability(string fileName, string fileToWriteTo){
    double AACounter=0;                                                         //initialized all variables here
    double ACCounter=0;
    double ATCounter=0;
    double AGCounter=0;
    double CACounter=0;
    double CCCounter=0;
    double CTCounter=0;
    double CGCounter=0;
    double TACounter=0;
    double TCCounter=0;
    double TGCounter=0;
    double TTCounter=0;
    double GACounter=0;
    double GCCounter=0;
    double GGCounter=0;
    double GTCounter=0;
    double totalCounter = 0;
    string line = " ";
    fstream stream;
    stream.open(fileName);
    while(getline(stream,line)){
        string parse = line;
        for (int i=0; i<line.length(); ++i){
            string tempStr = parse.substr(i,2);
            //tempStr=toupper(tempStr);                       //makes string in caps
            if(tempStr=="AA"){
                AACounter++;
            }
            if(tempStr=="AC"){
                ACCounter++;
            }
            if(tempStr=="AT"){
                ATCounter++;
            }
            if(tempStr=="AG"){
                AGCounter++;
            }
            if(tempStr=="CA"){
                CACounter++;
            }
            if(tempStr=="CC"){
                CCCounter++;
            }
            if(tempStr=="CT"){
                CTCounter++;
            }
            if(tempStr=="CG"){
                CGCounter++;
            }
            if(tempStr=="TA"){
                TACounter++;
            }
            if(tempStr=="TC"){
                TCCounter++;
            }
            if(tempStr=="TT"){
                TTCounter++;
            }
            if(tempStr=="TG"){
                TGCounter++;
            }
            if(tempStr=="GA"){
                GACounter++;
            }
            if(tempStr=="GC"){
                GCCounter++;
            }
            if(tempStr=="GT"){
                GTCounter++;
            }
            if(tempStr=="GG"){
                GGCounter++;
            }
        }
    }
        stream.close();
        totalCounter = AACounter+ACCounter+ATCounter+AGCounter+CACounter+CCCounter+CTCounter+CGCounter+GACounter+GCCounter+GTCounter+GGCounter;

        double AAprob = AACounter/totalCounter;
        double ACprob = ACCounter/totalCounter;
        double ATprob = ATCounter/totalCounter;
        double AGprob = AGCounter/totalCounter;

        double CAprob = CACounter/totalCounter;
        double CCprob = CCCounter/totalCounter;
        double CTprob = CTCounter/totalCounter;
        double CGprob = CGCounter/totalCounter;

        double TAprob = TACounter/totalCounter;
        double TCprob = TCCounter/totalCounter;
        double TTprob = TTCounter/totalCounter;
        double TGprob = TGCounter/totalCounter;

        double GAprob = GACounter/totalCounter;
        double GCprob = GCCounter/totalCounter;
        double GTprob = GTCounter/totalCounter;
        double GGprob = GGCounter/totalCounter;

            ofstream myFile;
            myFile.open(fileToWriteTo,  std::ios_base::app);                    //writes to file
            myFile<<"AA Probability: "<<AAprob*100<<"%"<<'\n';
            myFile<<"AC Probability: "<<ACprob*100<<"%"<<'\n';
            myFile<<"AT Probability: "<<ATprob*100<<"%"<<'\n';
            myFile<<"AG Probability: "<<AGprob*100<<"%"<<'\n';
            myFile<<'\n';
            myFile<<"CA Probability: "<<CAprob*100<<"%"<<'\n';
            myFile<<"CC Probability: "<<CCprob*100<<"%"<<'\n';
            myFile<<"CT Probability: "<<CTprob*100<<"%"<<'\n';
            myFile<<"CG Probability: "<<CGprob*100<<"%"<<'\n';
            myFile<<'\n';
            myFile<<"TA Probability: "<<TAprob*100<<"%"<<'\n';
            myFile<<"TC Probability: "<<TCprob*100<<"%"<<'\n';
            myFile<<"TT Probability: "<<TTprob*100<<"%"<<'\n';
            myFile<<"TG Probability: "<<TGprob*100<<"%"<<'\n';
            myFile<<'\n';
            myFile<<"GA Probability: "<<GAprob*100<<"%"<<'\n';
            myFile<<"GC Probability: "<<GCprob*100<<"%"<<'\n';
            myFile<<"GT Probability: "<<GTprob*100<<"%"<<'\n';
            myFile<<"GG Probability: "<<GGprob*100<<"%"<<'\n';
            myFile<<'\n';
            myFile.close();
    }

int calcGaussianDistribution(int mean, int variance){
    int a = rand();    //not sure what to make the range, instructions very unclear
    int b = rand();
    int c = sqrt(-2*log(a))*cos(2*3.14*b);  //couldnt find a constant for pi, just used 3.14 instead
    int d = (variance*c)+mean;
    //cout<<"Gaussian Distribution: "<<d;
    return d;
}
string createNewString(string fileName, int mean){
    int aCount = 0;
    int gCount = 0;
    int cCount = 0;
    int tCount = 0;
    double totalCount = 0;
    string line = " ";
    fstream stream;
    stream.open(fileName);
    while(getline(stream,line)){
        string parse = line;
        for (int i=0; i<line.length(); ++i){
            string tempStr = parse.substr(i,1);
            if((tempStr=="a")||(tempStr=="A")){                                 //coppied from the calculateProbability method

                aCount++;
                //cout<<"A Counter!";
            }
            if((tempStr=="g")||(tempStr=="G")){
                gCount++;
                //cout<<"G Counter!";
            }
            if((tempStr=="c")||(tempStr=="C")){
                cCount++;
                //cout<<"C Counter!";
            }
            if((tempStr=="t")||(tempStr=="T")){
                tCount++;
                //cout<<"T Counter!";
            }
        }

    }
    totalCount = aCount+gCount+cCount+tCount;
    int aPerc = (aCount/totalCount)*100;                                        //multiplied by 100 to make a percent
    int gPerc = (gCount/totalCount)*100;
    int cPerc = (cCount/totalCount)*100;
    int tPerc = (tCount/totalCount)*100;

//cout<<'\n'<<"tPerc: "<<aPerc+gPerc+cPerc;

    string newString = "";                                                      //this was the solution I came up with to create a new random string
    for (int i=0; i<mean; i++){
        int randNum= rand()%100+1;                                              //this code creates a random number (0-100) and then based on its value

        if (randNum<=aPerc){                                                    //selects from a range of proportional values associated with that letter
            newString.append("A");
            //cout<<'\n'<<"randNum: "<<randNum;
            //cout<<'\n'<<"append: "<<"A";
        }
        else if(aPerc<=randNum&&randNum<=(aPerc+gPerc)){
            newString.append("G");
            //cout<<'\n'<<"randNum: "<<randNum;
            //cout<<'\n'<<"append: "<<"G";
        }
        else if(aPerc+gPerc<=randNum&&randNum<=aPerc+gPerc+cPerc){
            newString.append("C");
            //cout<<'\n'<<"randNum: "<<randNum;
            //cout<<'\n'<<"append: "<<"C";
        }
        else if(aPerc+gPerc+cPerc<=randNum){
            newString.append("T");
            //cout<<'\n'<<"randNum: "<<randNum;
            //cout<<'\n'<<"append: "<<"T";
        }
    }
    //cout<<'\n'<<"NEWSTRING: "<<newString;
    return newString;
}

int main(int argc, char* argv[]){                                               //main file command line arguments handled here

    string fileName = "";
    if (argc==1){
        cout<< "Enter textfile to read"<<'\n';
    }
    else{
        fileName = argv[1];
    }

    string newFile = "ChaseBradshaw.txt";

    ofstream fileGuy;                                                           //starts new file writer to write the information that doesnt change
    fileGuy.open(newFile);
    fileGuy<<"Chase Bradshaw"<<'\n'<<"002317872"<<'\n'<<"Section 2";
    fileGuy<<'\n';

    int calcProb = calculateProbability(fileName, newFile);                     //calls each method here

    int sum = getSum(fileName);
    fileGuy<<'\n'<<"Sum: "<<sum<<'\n';

    int mean = getMean(fileName);
    fileGuy<<"Mean: "<<mean<<'\n';

    int variance = getVariance(fileName, mean);
    fileGuy<<"Variance: "<<variance<<'\n';

    int standardDeviation = getStandardDeviation(variance);
    fileGuy<<"Standard Deviation: "<<standardDeviation<<'\n';

    int calcDoubleProb = calculateDoubleProbability(fileName,newFile);
    calcGaussianDistribution(mean, variance);

    fileGuy.close();

    ofstream fileMan;
    fileMan.open(newFile, std::ios_base::app);

    for (int i = 0; i<=1000; i++){
        fileMan<<createNewString(fileName,mean)<<'\n';                          //creates 1000 new strings with the mean and probability of lettes based on the single units
    }
    fileMan.close();
    return 0;
}
