#include <iostream>


void Perceptron(int input1,int input2, float bias,float lr,int output,float *weights){


    int outputP=input1*weights[0]+input2*weights[1]+bias*weights[2];

    if(outputP>0){
        outputP=1;
    }
    else
    {
        outputP=0;
    }

    int error = output-outputP;
    weights[0]+=error*input1*lr;
    weights[1]+=error*input2*lr;
    weights[2]+=error*bias*lr;
    std::cout<<input1<<"|"<<input2<<" "<<"Expected:"<<output<<" Calculated:"<<outputP<<" W1: "<<weights[0]<<" W2: "<<weights[1]<<" WB: "<<weights[2]<<" Error:"<<error<<std::endl;
}
float GenWeight(){
    return static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
}
int main() {
    float lr=0.1;
    float bias=1;
    int n = 50;
    float weights[3]={GenWeight(),GenWeight(),GenWeight()};
    for(int i = 0;i<n;i++){
        Perceptron(1,1,bias,lr,1,weights);
        Perceptron(1,0,bias,lr,1,weights);
        Perceptron(0,1,bias,lr,1,weights);
        Perceptron(0,0,bias,lr,0,weights);


    }




    return 0;
}
