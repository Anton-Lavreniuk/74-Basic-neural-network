#include <iostream>


void Perceptron(int input1,int input2, int bias,int lr,int output,int *weights){

    int outputP=input1*weights[0]+input2*weights[2]+bias&weights[3];

    if(outputP>0){
        outputP=1;
    }
    else
    {
        outputP=0;
    }

    int error = output-outputP;
    weights[0]=error*input1*lr;
    weights[1]=error*input2*lr;
    weights[2]=error*bias*lr;
    std::cout<<output<<":"<<outputP<<" W1: "<<weights[0]<<" W2: "<<weights[1]<<" WB: "<<weights[2]<<" Error:"<<error<<std::endl;
}

int main() {
    int lr=1;
    auto bias=1;
    int weights[3]={rand(),rand(),rand()};
    for(int i = 0;i<50;i++){
        Perceptron(0,1,bias,lr,1,weights);
        Perceptron(1,1,bias,lr,1,weights);
        Perceptron(1,0,bias,lr,1,weights);
        Perceptron(0,0,bias,lr,0,weights);

    }




    return 0;
}
