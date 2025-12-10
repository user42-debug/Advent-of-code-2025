#include <bits/stdc++.h>
#include "ortools/linear_solver/linear_solver.h"
using namespace std;
using namespace operations_research;

ifstream fin("in_day10.txt");

int main() {
    string line;
    int total = 0;
    int machine_id = 0;

    while (getline(fin, line)) {
        if (line.empty()) continue;

        size_t lbrace = line.find('{');
        size_t rbrace = line.find('}');
        string joltages_str = line.substr(lbrace + 1, rbrace - lbrace - 1);
        stringstream ss(joltages_str);
        vector<int> joltage;
        int val;
        while (ss >> val) {
            joltage.push_back(val);
            if (ss.peek() == ',' || ss.peek() == ' ') ss.ignore();
        }
        int n = joltage.size();
        vector<vector<int>> A_cols;
        size_t pos = 0;
        while ((pos = line.find('(', pos)) != string::npos) {
            size_t end = line.find(')', pos);
            string inside = line.substr(pos + 1, end - pos - 1);
            vector<int> col(n, 0);
            stringstream ssi(inside);
            int x;
            while (ssi >> x) {
                col[x] = 1;
                if (ssi.peek() == ',' || ssi.peek() == ' ') ssi.ignore();
            }
            A_cols.push_back(col);
            pos = end + 1;
        }

        int m = n;
        int num_buttons = A_cols.size();

        MPSolver solver("JoltageMinPresses", MPSolver::CBC_MIXED_INTEGER_PROGRAMMING);

        vector<const MPVariable*> x(num_buttons);
        for (int j = 0; j < num_buttons; j++)
            x[j] = solver.MakeIntVar(0.0, solver.infinity(), "x_" + to_string(j));

        for (int i = 0; i < m; i++) {
            LinearExpr expr;
            for (int j = 0; j < num_buttons; j++) expr += A_cols[j][i] * x[j];
            solver.MakeEquality(expr, joltage[i]);
        }

        LinearExpr objective;
        for (int j = 0; j < num_buttons; j++) objective += x[j];
        solver.Minimize(objective);

        MPSolver::ResultStatus status = solver.Solve();
        if (status != MPSolver::OPTIMAL) {
            cout << "ERROR";
            return 1;
        }

        int min_presses = 0;
        vector<int> solution(num_buttons);
        for (int j = 0; j < num_buttons; j++) {
            solution[j] = static_cast<int>(x[j]->solution_value());
            min_presses += solution[j];
        }

        total += min_presses;
        machine_id++;
    }

    cout << total;
}
