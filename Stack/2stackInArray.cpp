#include<bits/stdc++.h>
using namespace std;



class TwoStack {
public:
	int *arr;
	int size; 
	int top1;
	int top2;

    // Initialize TwoStack.
    TwoStack(int s) {
        // Write your code here.
		this->size = s;
		top1=-1;
		top2=s;
		arr = new int[s];
    }
    
    // Push in stack 1.
    void push1(int num) {
        // Write your code here.
		if(top2-top1>1){
			top1++;
			arr[top1]=num;
		}
    }

    // Push in stack 2.
    void push2(int num) {
        // Write your code here.
		if(top2-top1>1){
			top2--;
			arr[top2]=num;
		}
    }

    // Pop from stack 1 and return popped element.
    int pop1() {
        // Write your code here.
		if(top1>=0){
			int ans = arr[top1];
			top1--;
			return ans;
		}else
			return -1;
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
        // Write your code here.
		if(top2<size){
			int ans = arr[top2];
			top2++;
			return ans;
		}
		else return -1;
    }

};
void stackTop1(TwoStack s){
        if(s.top1==-1)cout << "stack 1 empty" <<'\n';
        else{
            cout << s.arr[s.top1] <<'\n';
        }
    }
//     void stackTop2(){
//         if(top2==size)cout << "stack 2 empty" <<'\n';
//         else{
//             cout << arr[top2] <<'\n';
//         }
// }




int main(){

//2 Stacks in an array.
TwoStack s1s2(6);
s1s2.push1(10);
s1s2.push1(20);
s1s2.push2(50);
s1s2.push2(60);
stackTop1(s1s2);


    return 0;
}