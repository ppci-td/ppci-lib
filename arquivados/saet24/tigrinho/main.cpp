#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <math.h>
#include <cstring>
#include <chrono>
#include<bits/stdc++.h>

using namespace std;

class Timer
{
public:
    Timer() : beg_(clock_::now()) {}
    void reset() { beg_ = clock_::now(); }
    double elapsed() const { 
        return std::chrono::duration_cast<second_>
            (clock_::now() - beg_).count(); }

private:
    typedef std::chrono::high_resolution_clock clock_;
    typedef std::chrono::duration<double, std::ratio<1> > second_;
    std::chrono::time_point<clock_> beg_;
};


int solve() {
    // // vars
    double EPSILON = log(1e-8);
    unordered_map<string, int> a1;
    unordered_map<string, int> a2;
    vector<string> s;
    int n1, n2, t;
    double prob, sump1, sump2;
    string word;

    // // Reading entries
    cin >> n1;
    // words1 O(n1)
    sump1 = 0;
    for(int i = 0; i < n1; i++){
        cin >> word; 
        if(auto x = a1.find(word); x != a1.end()){
            a1[word]++;
        } else {
            a1.insert(make_pair(word, 1));
        }
    }
    cin >> n2;
    // words2 O(n2)
    for(int i = 0; i < n2; i++){
        cin >> word; 
        if(auto x = a2.find(word); x != a2.end()){
            a2[word]++;
        } else {
            a2.insert(make_pair(word, 1));
        }
    }

    cin >> t;
    double sp1, sp2;
    sp1 = sp2 = log(1);
    // O(ss)
    for(int i = 0; i < t; i++){
        cin >> word;
        if(auto x = a1.find(word); x != a1.end()){
            sp1 += log(a1[word]/(double)n1);
            // cout << "WORD t1 " << word << ": " << a1[word] <<
            // " P: " << a1[word]/(double)n1 <<
            // " logP: " << log(a1[word]/(double)n1);
        }
        else sp1 += EPSILON;
        // cout << " -- " << endl;

        if(auto x = a2.find(word); x != a2.end()){
            sp2 += log(a2[word]/(double)n2);
            // cout  << "WORD t2 " << word <<
            // " P: " << a2[word]/(double)n2 <<
            // " logP: " << log(a2[word]/(double)n2) << endl;
        }
        else sp2 += EPSILON;
    }
    double res = sp1 - sp2;
    // cout << endl << sp1 << " - " << sp2 << " = " << res << endl;
    if( abs(res) < 0.001) cout << "0" << endl;
    else if(res < 0) cout << "2" <<endl;
    else cout << "1" << endl;

    // O(n1 + n2 + ss) == O(len_txt1 + len_txt2 + len_sentence)
    // n1+n2+ss = N ~= O(N)
    return 0;
}

int main(){
    // Timer tmr;
    solve();
    // cout << tmr.elapsed() << endl;
    return 0;
}