#include<bits/stdc++.h>

using namespace std;

vector< pair<string, string> > accounts;

bool compare(vector<string>& elem1, vector<string>& elem2) {
    return elem1[0] < elem2[0];
}

vector<vector<string>> solution(vector<vector<string>> snapshots, vector<vector<string>> transactions) {
    vector<vector<string>> answer;

    for (int i = 0; i < snapshots.size(); i++) {
        string account = snapshots[i][0];
        string amount = snapshots[i][1];
        accounts.push_back({account, amount});
    }

    sort(transactions.begin(), transactions.end(), compare);

    int save_match = 0;
    int withdraw_match = 0;
    int new_acc_num = 1;
    int id_index = 1;
    for (int i = 1; i <= transactions.size(); i++) {
        if (!to_string(id_index).compare(transactions[i-1][0])) {
            if (!transactions[i-1][1].compare("SAVE")){
                for (vector<pair<string, string>>::iterator it = accounts.begin(); it != accounts.end(); it++){
                    if (!transactions[i-1][2].compare(it->first)) {
                        save_match = 1;
                        it->second = to_string(stoi(it->second) + stoi(transactions[i-1][3]));
                    }
                }
                if(save_match == 0){
                    string new_account = "ACCOUNT" + to_string(snapshots.size() + new_acc_num);
                    new_acc_num++;
                    string base_amount = transactions[i-1][3];
                    accounts.push_back({new_account, base_amount});
                }
                save_match = 0;
            }
            else if (!transactions[i-1][1].compare("WITHDRAW")){ // WITHDRAW
                for (vector<pair<string, string>>::iterator it = accounts.begin(); it != accounts.end(); it++){
                    if (!transactions[i-1][2].compare(it->first)) {
                        withdraw_match = 1;
                        it->second = to_string(stoi(it->second) - stoi(transactions[i-1][3]));
                    }
                }
                if(withdraw_match == 0){
                    string new_account = "ACCOUNT" + to_string(snapshots.size() + new_acc_num);
                    new_acc_num++;
                    string base_amount = "-" + transactions[i-1][3];
                    accounts.push_back({new_account, base_amount});
                }
                withdraw_match = 0;
            }
            id_index++;
        }
    }

    for (vector<pair<string, string>>::iterator it = accounts.begin(); it != accounts.end(); it++){
                    answer.push_back({it->first, it->second});
                }


    return answer;
}