#include <iostream>
#include <vector>

using namespace std;

vector<unsigned long> construct_vector(vector<unsigned long> array, vector<unsigned long> previous_lis, unsigned long current_end_index) {
    if(previous_lis[current_end_index] == -1) {
        vector<unsigned long> result;
        result.push_back(array[current_end_index]);
        return result;
    }
    vector<unsigned long> result = construct_vector(array, previous_lis, previous_lis[current_end_index]);
    result.push_back(array[current_end_index]);
    return result;
}

vector<unsigned long> lis(vector<unsigned long> array) {
    unsigned long length = array.size();
    vector<unsigned long> previous_lis(length), lis_lengths(length);
    lis_lengths[0] = 1;
    previous_lis[0] = -1;
    for(unsigned long i = 1; i < length; i++) {
        lis_lengths[i] = 1;
        previous_lis[i] = -1;
        for(unsigned long j = 0; j < i; j++) {
            if(array[j] < array[i] && lis_lengths[i] < lis_lengths[j] + 1) {
                lis_lengths[i] = lis_lengths[j] + 1;
                previous_lis[i] = j;
            }
        }
    }

    unsigned long max_index = 0;
    for(unsigned long i = 0; i < length; i++) {
        if(lis_lengths[i] > lis_lengths[max_index]) {
            max_index = i;
        }
    }

    return construct_vector(array, previous_lis, max_index);
}

int main() {
    vector<unsigned long> a;
    cout << "The current working array is: " << endl;
    for(unsigned long i = 0; i < 30; i++) {
        int current_val = rand() % 100;
        a.push_back(current_val);
        cout << current_val << " ";
    }

    vector<unsigned long> result = lis(a);
    cout << endl << endl << "The length of the longest increasing sub-sequence is " << result.size() << " and it is: " << endl;
    for(unsigned long i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
