/*
An inorder binary tree traversal can be implemented in a non-recursive way with a stack. For example, suppose that when a 6-node binary tree (with the keys numbered from 1 to 6) is traversed, the stack operations are: push(1); push(2); push(3); pop(); pop(); push(4); pop(); pop(); push(5); push(6); pop(); pop(). Then a unique binary tree (shown in Figure 1) can be generated from this sequence of operations. Your task is to give the postorder traversal sequence of this tree.


Figure 1
Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer N (<=30) which is the total number of nodes in a tree (and hence the nodes are numbered from 1 to N). Then 2N lines follow, each describes a stack operation in the format: "Push X" where X is the index of the node being pushed onto the stack; or "Pop" meaning to pop one node from the stack.

Output Specification:

For each test case, print the postorder traversal sequence of the corresponding tree in one line. A solution is guaranteed to exist. All the numbers must be separated by exactly one space, and there must be no extra space at the end of the line.

Sample Input:
6
Push 1
Push 2
Push 3
Pop
Pop
Push 4
Pop
Pop
Push 5
Push 6
Pop
Pop
Sample Output:
3 4 2 6 5 1
*/
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

void print_data(const vector<char> &as, const vector<int> &ns) {
    int len = ns.size();
    for (int i=0; i<len; i++) {
        if (as[i] == 'i') {
            cout<<"push "<<ns[i]<<endl;
        } else {
            cout<<"pop"<<endl;
        }
    }
}

void build_postorder(vector<char> &actions, vector<int> &nums, int start, int end, vector<int> &postorder) {
    if (start >= end) return;
    if (actions[start] != 'i') return;
    // root node
    postorder.push_back(nums[start]);
    
    // now try to find the seperator idx of 
    // action(must be a pop pair wise with root node push) between two sub tree
    int pushs = 1;
    int idx = start + 1;
    while (pushs != 0 && idx < end) {
        if (actions[idx] == 'i') {
            pushs++;
        } else {
            pushs--;
        }
        idx++;
    }
    
    // right sub tree
    build_postorder(actions, nums, idx, end, postorder);
    
    // left sub tree
    build_postorder(actions, nums, start + 1, idx, postorder);
}
int main() {
    
    int N, len;
    
    scanf("%d", &N);
    len = N * 2;
    
    char buf[10];
    int num;
    
    vector<char> actions(2 * N, '\0');
    vector<int> nums(2 * N, 0);
    
    // read in data
    for (int i=0; i<len; i++) {
        scanf("%s", buf);
    
        if (buf[3] == 'h') {
            scanf("%d", &num);
            nums[i] = num;
            actions[i] = 'i';    // push, input
        } else {
            actions[i] = 'o';    // pop, output
        }
    }
    
    
    vector<int> postorder;
    
    build_postorder(actions, nums, 0, len, postorder);
    if (postorder.size() > 0){
        // print_data(actions, nums);
        for (int i=N - 1; i>=1; i--) {
            printf("%d ", postorder[i]);
        }
        printf("%d", postorder[0]);
    }

    return 0;
}