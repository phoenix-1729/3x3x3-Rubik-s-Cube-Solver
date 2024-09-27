#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <string>
#include <chrono>
#include <ctime>
#include <sys/resource.h>
#include <unistd.h>
using namespace std;

const string SOLVED_STATE = "WWWWWWWWWGGGGGGGGGRRRRRRRRRBBBBBBBBBOOOOOOOOOYYYYYYYYY";
const vector<string> MOVES = {
    "U", "Ui", "F", "Fi", "R", "Ri", "B", "Bi", "L", "Li", "D", "Di"
};

string applyMove(const string &state, const string &move) {
    string newState = state;
    if (move == "U") {

        char u1 = newState[0], u2 = newState[1], u3 = newState[2];
        char u4 = newState[3], u5 = newState[4], u6 = newState[5];
        char u7 = newState[6], u8 = newState[7], u9 = newState[8];

        newState[0] = u7; newState[1] = u4; newState[2] = u1;
        newState[3] = u8; newState[5] = u2;
        newState[6] = u9; newState[7] = u6; newState[8] = u3;

        char lub1 = newState[36];
        char lum1 = newState[37];
        char luf1 = newState[38];

        newState[36] = newState[9];
        newState[37] = newState[10];
        newState[38] = newState[11];

        newState[9]  = newState[18];
        newState[10] = newState[19];
        newState[11] = newState[20];

        newState[18] = newState[27];
        newState[19] = newState[28];
        newState[20] = newState[29];

        newState[27] = lub1;
        newState[28] = lum1;
        newState[29] = luf1;

    } else if (move == "Ui") {
        char u1 = newState[0], u2 = newState[1], u3 = newState[2];
        char u4 = newState[3], u5 = newState[4], u6 = newState[5];
        char u7 = newState[6], u8 = newState[7], u9 = newState[8];

        newState[0] = u3; newState[1] = u6; newState[2] = u9;
        newState[3] = u2; newState[5] = u8;
        newState[6] = u1; newState[7] = u4; newState[8] = u7;

        char lub1 = newState[36];
        char lum1 = newState[37];
        char luf1 = newState[38];

        newState[36] = newState[27];
        newState[37] = newState[28];
        newState[38] = newState[29];

        newState[27] = newState[18];
        newState[28] = newState[19];
        newState[29] = newState[20];

        newState[18] = newState[9];
        newState[19] = newState[10];
        newState[20] = newState[11];

        newState[9]  = lub1;
        newState[10] = lum1;
        newState[11] = luf1;
    } else if (move == "F") {
        char f1 = newState[9], f2 = newState[10], f3 = newState[11];
        char f4 = newState[12], f5 = newState[13], f6 = newState[14];
        char f7 = newState[15], f8 = newState[16], f9 = newState[17];

        newState[9] = f7; newState[10] = f4; newState[11] = f1;
        newState[12] = f8; newState[14] = f2;
        newState[15] = f9; newState[16] = f6; newState[17] = f3;

        char lfb1 = newState[6];
        char lfm1 = newState[7];
        char lfu1 = newState[8];

        newState[6] = newState[44];
        newState[7] = newState[41];
        newState[8] = newState[38];

        newState[44] = newState[47];
        newState[41] = newState[46];
        newState[38] = newState[45];

        newState[45] = newState[24];
        newState[46] = newState[21];
        newState[47] = newState[18];

        newState[24] = lfu1;
        newState[21] = lfm1;
        newState[18] = lfb1;
    } else if (move == "Fi") {

        char f1 = newState[9], f2 = newState[10], f3 = newState[11];
        char f4 = newState[12], f5 = newState[13], f6 = newState[14];
        char f7 = newState[15], f8 = newState[16], f9 = newState[17];

        newState[9] = f3; newState[10] = f6; newState[11] = f9;
        newState[12] = f2; newState[14] = f8;
        newState[15] = f1; newState[16] = f4; newState[17] = f7;

        char lfb1 = newState[6];
        char lfm1 = newState[7];
        char lfu1 = newState[8];

        newState[6] = newState[18];
        newState[7] = newState[21];
        newState[8] = newState[24];

        newState[18] = newState[47];
        newState[21] = newState[46];
        newState[24] = newState[45];

        newState[45] = newState[38];
        newState[46] = newState[41];
        newState[47] = newState[44];

        newState[38] = lfu1;
        newState[41] = lfm1;
        newState[44] = lfb1;
    } else if (move == "R") {

        char r1 = newState[18], r2 = newState[19], r3 = newState[20];
        char r4 = newState[21], r5 = newState[22], r6 = newState[23];
        char r7 = newState[24], r8 = newState[25], r9 = newState[26];

        newState[18] = r7; newState[19] = r4; newState[20] = r1;
        newState[21] = r8; newState[23] = r2;
        newState[24] = r9; newState[25] = r6; newState[26] = r3;

        char lrf1 = newState[2];
        char lrm1 = newState[5];
        char lrb1 = newState[8];

        newState[2] = newState[11];
        newState[5] = newState[14];
        newState[8] = newState[17];

        newState[11] = newState[47];
        newState[14] = newState[50];
        newState[17] = newState[53];

        newState[47] = newState[33];
        newState[50] = newState[30];
        newState[53] = newState[27];

        newState[33] = lrf1;
        newState[30] = lrm1;
        newState[27] = lrb1;

    } else if (move == "Ri") {

        char r1 = newState[18], r2 = newState[19], r3 = newState[20];
        char r4 = newState[21], r5 = newState[22], r6 = newState[23];
        char r7 = newState[24], r8 = newState[25], r9 = newState[26];

        newState[18] = r3; newState[19] = r6; newState[20] = r9;
        newState[21] = r2; newState[23] = r8;
        newState[24] = r1; newState[25] = r4; newState[26] = r7;

        char lrf1 = newState[2];
        char lrm1 = newState[5];
        char lrb1 = newState[8];

        newState[2] = newState[33];
        newState[5] = newState[30];
        newState[8] = newState[27];

        newState[33] = newState[47];
        newState[30] = newState[50];
        newState[27] = newState[53];

        newState[47] = newState[11];
        newState[50] = newState[14];
        newState[53] = newState[17];

        newState[11] = lrf1;
        newState[14] = lrm1;
        newState[17] = lrb1;
    } else if (move == "B") { 

        char b1 = newState[27], b2 = newState[28], b3 = newState[29];
        char b4 = newState[30], b5 = newState[31], b6 = newState[32];
        char b7 = newState[33], b8 = newState[34], b9 = newState[35];

        newState[27] = b7; newState[28] = b4; newState[29] = b1;
        newState[30] = b8; newState[32] = b2;
        newState[33] = b9; newState[34] = b6; newState[35] = b3;

        char lbf1 = newState[0];
        char lbm1 = newState[1];
        char lbu1 = newState[2];

        newState[0] = newState[20];
        newState[1] = newState[23];
        newState[2] = newState[26];

        newState[20] = newState[53];
        newState[23] = newState[52];
        newState[26] = newState[51];

        newState[53]  = newState[42];
        newState[52]  = newState[39];
        newState[51]  = newState[36];

        newState[42] = lbf1;
        newState[39] = lbm1;
        newState[36] = lbu1;

    } else if (move == "Bi") { 

        char b1 = newState[27], b2 = newState[28], b3 = newState[29];
        char b4 = newState[30], b5 = newState[31], b6 = newState[32];
        char b7 = newState[33], b8 = newState[34], b9 = newState[35];

        newState[27] = b3; newState[28] = b6; newState[29] = b9;
        newState[30] = b2; newState[32] = b5;
        newState[33] = b1; newState[34] = b4; newState[35] = b7;

        char lbf1 = newState[0];
        char lbm1 = newState[1];
        char lbu1 = newState[2];

        newState[0]  = newState[42];
        newState[1]  = newState[39];
        newState[2]  = newState[36];

        newState[42] = newState[53];
        newState[39] = newState[52];
        newState[36] = newState[51];

        newState[53] = newState[20];
        newState[52] = newState[23];
        newState[51] = newState[26];

        newState[20] = lbf1;
        newState[23] = lbm1;
        newState[26] = lbu1;

    } else if (move == "L") { 

        char l1 = newState[36], l2 = newState[37], l3 = newState[38];
        char l4 = newState[39], l5 = newState[40], l6 = newState[41];
        char l7 = newState[42], l8 = newState[43], l9 = newState[44];

        newState[36] = l3; newState[37] = l6; newState[38] = l9;
        newState[39] = l2; newState[41] = l8;
        newState[42] = l1; newState[43] = l4; newState[44] = l7;

        char luf1 = newState[0];
        char lum1 = newState[3];
        char lub1 = newState[6];

        newState[0] = newState[9];
        newState[3] = newState[12];
        newState[6] = newState[15];

        newState[9] = newState[45];
        newState[12] = newState[48];
        newState[15] = newState[51];

        newState[45] = newState[35];
        newState[48] = newState[32];
        newState[51] = newState[29];

        newState[35] = luf1;
        newState[32] = lum1;
        newState[29] = lub1;
    } else if (move == "Li") { 

        char l1 = newState[36], l2 = newState[37], l3 = newState[38];
        char l4 = newState[39], l5 = newState[40], l6 = newState[41];
        char l7 = newState[42], l8 = newState[43], l9 = newState[44];

        newState[36] = l7; newState[37] = l4; newState[38] = l1;
        newState[39] = l8; newState[41] = l2;
        newState[42] = l9; newState[43] = l6; newState[44] = l3;

        char luf1 = newState[0];
        char lum1 = newState[3];
        char lub1 = newState[6];

        newState[0] = newState[35];
        newState[3] = newState[32];
        newState[6] = newState[29];

        newState[29] = newState[51];
        newState[32] = newState[48];
        newState[35] = newState[45];

        newState[51] = newState[15];
        newState[48] = newState[12];
        newState[45] = newState[9];

        newState[15] = lub1;
        newState[12] = lum1;
        newState[9] = luf1;

    } else if (move == "D") { 
    
        char d1 = newState[45], d2 = newState[46], d3 = newState[47];
        char d4 = newState[48], d5 = newState[49], d6 = newState[50];
        char d7 = newState[51], d8 = newState[52], d9 = newState[53];

        newState[45] = d7; newState[46] = d4; newState[47] = d1;
        newState[48] = d8; newState[50] = d2;
        newState[51] = d9; newState[52] = d6; newState[53] = d3;

        char ldb1 = newState[15];
        char ldm1 = newState[16];
        char ldu1 = newState[17];

        newState[15] = newState[42];
        newState[16] = newState[43];
        newState[17] = newState[44];

        newState[42] = newState[33];
        newState[43] = newState[34];
        newState[44] = newState[35];

        newState[33] = newState[24];
        newState[34] = newState[25];
        newState[35] = newState[26];

        newState[24] = ldb1;
        newState[25] = ldm1;
        newState[26] = ldu1;

    } else if (move == "Di") { 
        char d1 = newState[45], d2 = newState[46], d3 = newState[47];
        char d4 = newState[48], d5 = newState[49], d6 = newState[50];
        char d7 = newState[51], d8 = newState[52], d9 = newState[53];

        newState[45] = d3; newState[46] = d6; newState[47] = d9;
        newState[48] = d2; newState[50] = d8;
        newState[51] = d1; newState[52] = d4; newState[53] = d7;

        char ldb1 = newState[15];
        char ldm1 = newState[16];
        char ldu1 = newState[17];

        newState[15] = newState[24];
        newState[16] = newState[25];
        newState[17] = newState[26];

        newState[24] = newState[33];
        newState[25] = newState[34];
        newState[26] = newState[35];

        newState[33] = newState[42];
        newState[34] = newState[43];
        newState[35] = newState[44];

        newState[42] = ldb1;
        newState[43] = ldm1;
        newState[44] = ldu1;

    }
   
    return newState;
}

string inverseMove(string &move){
    if (move == "U"){
        return "Ui";
    } else if (move == "Ui") {
        return "U";
    } else if (move == "F"){
        return "Fi";
    } else if (move == "Fi"){
        return "F";

    } else if (move == "R"){
        return "Ri";

    } else if (move == "Ri"){
        return "R";

    } else if (move == "B"){
        return "Bi";

    } else if (move == "Bi"){
        return "B";

    } else if (move == "L"){
        return "Li";

    } else if (move == "Li"){
        return "L";

    } else if (move == "D"){
        return "Di";

    } else if (move == "Di"){
        return "D";
    }else{
        return "";
    }
}

string solveCube(const string &start) {
    if (start == SOLVED_STATE) {
        return {"Already Solved!"};
    }

    unordered_map<string, string> forward_parents;
    unordered_map<string, string> backward_parents;

    forward_parents[start] = "N";
    backward_parents[SOLVED_STATE] = "N";

    queue<string> forward_queue;
    queue<string> backward_queue;

    forward_queue.push(start);
    backward_queue.push(SOLVED_STATE);

    while (!forward_queue.empty() && !backward_queue.empty()) {
        if (!forward_queue.empty()) {
            string current = forward_queue.front();
            forward_queue.pop();
            for (const auto &move : MOVES) {
                string next_position = applyMove(current, move);
                if (forward_parents.find(next_position) == forward_parents.end()) {
                    forward_parents[next_position] = move;
                    forward_queue.push(next_position);
                    if (backward_parents.find(next_position) != backward_parents.end()) {
                        string temp = next_position;
                        string X = forward_parents[temp];
                        string ans = "";
                        while (X != "N") {
                            ans = forward_parents[temp] + " " + ans;
                            temp = applyMove(temp, inverseMove(forward_parents[temp]));
                            X = forward_parents[temp];
                        }
                        temp = next_position;
                        X = backward_parents[temp];
                        while (X != "N") {
                            ans = ans + " " + inverseMove(backward_parents[temp]);
                            temp = applyMove(temp, inverseMove(backward_parents[temp]));
                            X = backward_parents[temp];
                        }
                        return ans;
                    }
                }
            }
        }

        if (!backward_queue.empty()) {
            string current = backward_queue.front();
            backward_queue.pop();
            for (const auto &move : MOVES) {
                string next_position = applyMove(current, move);
                if (backward_parents.find(next_position) == backward_parents.end()) {
                    backward_parents[next_position] = move;
                    backward_queue.push(next_position);
                    if (forward_parents.find(next_position) != forward_parents.end()) {
                        string temp = next_position;
                        string X = forward_parents[temp];
                        string ans = "";
                        while (X != "N") {
                            ans = forward_parents[temp] + " " + ans;
                            temp = applyMove(temp, inverseMove(forward_parents[temp]));
                            X = forward_parents[temp];
                        }
                        temp = next_position;
                        X = backward_parents[temp];
                        while (X != "N") {
                            ans = ans + " " +inverseMove(backward_parents[temp]);
                            temp = applyMove(temp, inverseMove(backward_parents[temp]));
                            X = backward_parents[temp];
                        }

                        return ans;
                    }
                }
            }
        }
    }

    return "";
}

string test_case(){
    string state = applyMove(SOLVED_STATE, "U");
    state = applyMove(state, "F");
    state = applyMove(state, "U");
    state = applyMove(state, "R");
    state = applyMove(state, "L");
    state = applyMove(state, "Li");
    state = applyMove(state, "Fi");
    state = applyMove(state, "Bi");
    state = applyMove(state, "D");
    state = applyMove(state, "B");
    state = applyMove(state, "Di");
    state = applyMove(state, "Di");
    state = applyMove(state, "Di");
    state = applyMove(state, "Fi");
    state = applyMove(state, "Ri");
    state = applyMove(state, "L");
    state = applyMove(state, "B");


    return state;
}

int main() {
    string startState = "WWWWWWWWWBBBGGGGGGOOORRRRRRGGGBBBBBBRRROOOOOOYYYYYYYYY";
    string test_case1 = test_case();

    auto start = chrono::high_resolution_clock::now();
    clock_t cpu_start = clock();
    
    string solutionPath = solveCube(test_case1);
    
    auto end = chrono::high_resolution_clock::now();
    clock_t cpu_end = clock();

    chrono::duration<double, milli> duration = end - start;
    double cpu_time = double(cpu_end - cpu_start) / CLOCKS_PER_SEC;

    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    long memory_usage = usage.ru_maxrss;

    pid_t pid = getpid();
    cout << "You can monitor CPU usage for PID " << pid << " using the command:\n";
    cout << "top -pid " << pid << " -l 0\n";

    cout<<"Solution Path is "<<solutionPath<<endl;
    cout << "Time taken: " << duration.count() << " ms" << endl;
    cout << "CPU time used: " << cpu_time << " seconds" << endl;
    cout << "Memory usage: " << memory_usage << " KB" << endl;
    return 0;
}

// TC :: O(b^d), where b is the branching factor (average number of new states generated per state, here is 12) and 
// d is the maximum depth (in this case, likely around 20)
// The space complexity remains approximately 𝑂(𝑚^20) as well, due to the need to store all the unique states and 
// their relationships up to the maximum depth.

// WWWWWWWWWBBBGGGGGGOOORRRRRRGGGBBBBBBRRROOOOOOYYYYYYYYY -- state with moves U U
// WWWWWWWWWRRRGGGGGGBBBRRRRRROOOBBBBBBGGGOOOOOOYYYYYYYYY -- state with moves U 

// Order :: U-F-R-B-L-D

//          36  35  34
//          33  32  31
//          30  29  28
// 43 40 37  1   2  3   21 24 27   54 53 52
// 44 41 38  4   5  6   20 23 26   51 50 49
// 45 42 39  7   8  9   19 22 25   48 47 46
//           10 11 12
//           13 14 15
//           16 17 18

// S  :: W W W W W W W W W  B B B G G G G G G  O O O R R R R R R  G G G B B B B B B  R R R O O O O O O  Y Y Y Y Y Y Y Y Y

//           B  B  B
//           B  B  B
//           G  G  G
// O  O  R   W  W  W   O R R  Y Y Y
// O  O  R   W  W  W   O R R  Y Y Y
// O  O  R   W  W  W   O R R  Y Y Y
//           B  B  B
//           G  G  G
//           G  G  G

// U  :: W W W W W W W W W  O O O G G G G G G  G G G R R R R R R  R R R B B B B B B  B B B O O O O O O  Y Y Y Y Y Y Y Y Y
// Ui :: W W W W W W W W W  R R R G G G G G G  B B B R R R R R R  O O O B B B B B B  G G G O O O O O O  Y Y Y Y Y Y Y Y Y
// F  :: W W W W W W O O R  G G B G G B G G B  W O O W R R W R R  G G G B B B B B B  R R Y O O Y O O Y  R R O Y Y Y Y Y Y
// Fi :: W W W W W W O R R  B G G B G G B G G  Y O O Y R R Y R R  G G G B B B B B B  R R W O O W O O W  R O O Y Y Y Y Y Y 
// R  :: W W B W W G W W G  B B Y G G Y G G Y  R R O R R O R R O  W G G W B B W B B  R R R O O O O O O  Y Y B Y Y B Y Y G 
// Ri :: W W B W W B W W G  B B W G G W G G W  O R R O R R O R R  Y G G Y B B Y B B  R R R O O O O O O  Y Y B Y Y G Y Y G
// B  :: O R R W W W W W W  B B B G G G G G G  O O Y R R Y R R Y  B B G B B G B B G  W R R W O O W O O  Y Y Y Y Y Y R O O
// Bi :: O O R W W W W W W  B B B G G G G G G  O O W R R W R R W  G B B G B B G B B  Y R R Y O O Y O O  Y Y Y Y Y Y R R O 
// L  :: B W W G W W G W W  Y B B Y G G Y G G  O O O R R R R R R  G G W B B W B B W  R O O R O O R O O  B Y Y B Y Y G Y Y
// Li :: B W W B W W G W W  W B B W G G W G G  O O O R R R R R R  G G Y B B Y B B Y  O O R O O R O O R  B Y Y G Y Y G Y Y
// D  :: W W W W W W W W W  B B B G G G O O O  O O O R R R G G G  G G G B B B R R R  R R R O O O B B B  Y Y Y Y Y Y Y Y Y
// Di :: W W W W W W W W W  B B B G G G R R R  O O O R R R B B B  G G G B B B O O O  R R R O O O G G G  Y Y Y Y Y Y Y Y Y
