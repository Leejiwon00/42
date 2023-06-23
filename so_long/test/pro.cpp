#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    vector<string> pron;
	pron.push_back("aya"); // = {"aya", "ye", "woo", "ma"};
	pron.push_back("ye");
	pron.push_back("woo");
	pron.push_back("ma");
    vector<string> w;
    for (int i=0;i<pron.size();i++){
        for (int j=i+1;j<pron.size();j++){
            w.push_back(pron[i] + pron[j]);
			w.push_back(pron[j] + pron[i]);
        }
    }
	for (int i=0;i<w.size();i++)
		cout << w[i] << endl;
    for (int i = 0; i<babbling.size();i++){
        for(int j=0;j<w.size();j++){
            if (babbling[i] == w[j])
                answer++;
        }
    }
	for (int i = 0; i<babbling.size();i++){
		for (int k=0;k<pron.size();k++)
		{
			cout << pron[k] << endl;
			if (babbling[i] == pron[k])
                answer++;
		}
    }
    return answer;
}

int main()
{
	vector<string> a;
	a.push_back("ayaye");
	a.push_back("yee");
	a.push_back("u");
	a.push_back("maa");
	a.push_back("wyeoo");
	cout << solution(a);
}