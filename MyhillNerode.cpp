#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void printMinimizedDFA(int states, int ctr, vector<int>& NewState, vector<vector<int>>& NewTransitionTable, unordered_map<int, int>& GroupNumber) {
    cout << "\n----- Minimized DFA -----\n";
    
    // Print the number of states in minimized DFA
    cout << "Number of states in minimized DFA: " << ctr << endl;
    
    // Create a mapping of original states to their new state name
    vector<vector<int>> stateMapping(ctr);
    for (int i = 0; i < states; i++) {
        stateMapping[NewState[i]].push_back(i);
    }
    
    // Display the mapping from original states to new states
    cout << "\nState Mapping:" << endl;
    for (int i = 0; i < ctr; i++) {
        cout << "New state q'" << i << " contains: ";
        for (size_t j = 0; j < stateMapping[i].size(); j++) {
            cout << "q" << stateMapping[i][j];
            if (j < stateMapping[i].size() - 1) {
                cout << ", ";
            }
        }
        cout << endl;
    }
    
    // Display the transition table
    cout << "\nTransition Table:\n";
    cout << "State\t| a\t| b\n";
    cout << "------------------------\n";
    
    for (int i = 0; i < ctr; i++) {
        cout << "q'" << i << "\t| q'" << NewTransitionTable[i][0] << "\t| q'" << NewTransitionTable[i][1] << endl;
    }
    
    // Display accepting states
    cout << "\nAccepting states: ";
    bool first = true;
    for (int i = 0; i < ctr; i++) {
        // Check if any of the original states in this new state was accepting
        bool isAccepting = false;
        for (int originalState : stateMapping[i]) {
            if (GroupNumber[originalState] == 0) { // 0 represents accepting states in your code
                isAccepting = true;
                break;
            }
        }
        
        if (isAccepting) {
            if (!first) {
                cout << ", ";
            }
            cout << "q'" << i;
            first = false;
        }
    }
    cout << endl;
    
    cout << "-----------------------\n";
}

int main() {

	int states;
	char ch;
	cout << "Enter number of states: ";
	cin >> states;

	vector<vector<int>> input(states, vector<int>(2));
	unordered_map<int, int> GroupNumber;

	for (int i = 0; i < states; i++) {
		cout << "For state q" << i << " and input a:";
		cin >> ch >> input[i][0];
		while (input[i][0] < 0 || input[i][0] >= states) {
			cout << "Invalid Input! Input Again\n";
			cout << "For state q" << i << " and input a:";
			cin >> ch >> input[i][0];
		}

		cout << "For state q" << i << " and input b:";
		cin >> ch >> input[i][1];
		while (input[i][1] < 0 || input[i][1] >= states) {
			cout << "Invalid Input! Input Again\n";
			cout << "For state q" << i << " and input b:";
			cin >> ch >> input[i][1];
		}

		GroupNumber[i] = 1;
	}

	int accepting;
	cout << "Enter number of accepting states: ";
	cin >> accepting;
	for (int i = 0; i < accepting; i++) {
		int t1;
		cout << "Enter accepting state number " << i + 1 << ": ";
		cin >> ch >> t1;
		GroupNumber[t1] = 0;
	}
	

	vector<vector<bool>> distinguishable(states, vector<bool>(states, false));

	// At this place marking the pairs...
	for (int i = 0; i < states; i++) {
		for (int j = 0; j < states; j++) {
			if ((GroupNumber[i] == 0 && GroupNumber[j] == 1) || (GroupNumber[i] == 1 && GroupNumber[j] == 0)) {
				distinguishable[i][j] = true;
			}
		}
	}

	// Marking the remaining pairs if possible....
	bool changed;
	do {
		changed = false;
		for (int i = 0; i < states; i++) {
			for (int j = 0; j < states; j++) {
				if (!distinguishable[i][j]) {
					for (int k = 0; k < 2; k++) {
						int nextState1 = input[i][k];
						int nextState2 = input[j][k];
						if (distinguishable[nextState1][nextState2]) {
							distinguishable[i][j] = true;
							changed = true;
							break;
						}
					}
				}
			}
		}
	} while (changed);

	vector<int> NewState(states, -1);
	int ctr = 0;

	for (int i = 0; i < states; i++) {
		if (NewState[i] == -1) {
			NewState[i] = ctr++;
			for (int j = i + 1; j < states; j++) {
				if (!distinguishable[i][j]) {
					NewState[j] = NewState[i];
				}
			}
		}
	}

	vector<vector<int>> NewTransitionTable(ctr, vector<int>(2, -1));
	for (int i = 0; i < states; i++) {
		for (int j = 0; j < 2; j++) {
			NewTransitionTable[NewState[i]][j] = NewState[input[i][j]];
		}
	}
	
	printMinimizedDFA(states, ctr, NewState, NewTransitionTable, GroupNumber);

	return 0;
}