#include <iostream>
#include <stack>

using namespace std;
stack<char> input;
stack<string> analysis;

string ACTIONLIST[] = {
        "E->TE'",
        "E'->+TE'",
        "E'->��",
        "T->FT'",
        "T'->*FT'",
        "T'->��",
        "F->(E)",
        "F->i"
};

void printAnalysisStack(stack<string> s) {
    stack<string> temp;
    while (!s.empty()) {
        temp.push(s.top());
        s.pop();
    }
    while (!temp.empty()) {
        cout << temp.top();
        temp.pop();
    }
    cout << "\t\t\t";
}

void printInputStack(stack<char> s) {
    stack<char> temp;
    while (!s.empty()) {
        temp.push(s.top());
        s.pop();
    }
    while (!temp.empty()) {
        cout << temp.top();
        temp.pop();
    }
    cout << "\t\t\t";
}

int main() {
    while (1) {
        input.push('$');
        cout << "��������������ʽ��" << endl;
        string str;
        cin >> str;
        for (int i = str.length() - 1; i >= 0; i--) {
            input.push(str[i]);
        }
        analysis.push("$");
        analysis.push("E");
        cout << "�������̣�" << endl;
        cout << "����ջ\t\t\t���ջ\t\t\t����" << endl;
        while (input.top() != '$') {
            switch (input.top()) {
                case 'i':
                    if (analysis.top() == "E") {
                        analysis.pop();
                        analysis.push("E'");
                        analysis.push("T");
                        printInputStack(input);
                        printAnalysisStack(analysis);
                        cout << ACTIONLIST[0] << endl;
                    } else if (analysis.top() == "T") {
                        analysis.pop();
                        analysis.push("T'");
                        analysis.push("F");
                        printInputStack(input);
                        printAnalysisStack(analysis);
                        cout << ACTIONLIST[3] << endl;
                    } else if (analysis.top() == "F") {
                        analysis.pop();
                        analysis.push("i");
                        printInputStack(input);
                        printAnalysisStack(analysis);
                        cout << ACTIONLIST[7] << endl;
                    } else if (analysis.top() == "i") {
                        analysis.pop();
                        input.pop();
                        printInputStack(input);
                        printAnalysisStack(analysis);
                        cout << "MATCH" << endl;
                    } else {
                        cout << "��LL1�ķ����ʽ" << endl;
                        return 0;
                    }
                    break;
                case '+':
                    if (analysis.top() == "E'") {
                        analysis.pop();
                        analysis.push("E'");
                        analysis.push("T");
                        analysis.push("+");
                        printInputStack(input);
                        printAnalysisStack(analysis);
                        cout << ACTIONLIST[1] << endl;
                    } else if (analysis.top() == "T'") {
                        analysis.pop();
                        printInputStack(input);
                        printAnalysisStack(analysis);
                        cout << ACTIONLIST[5] << endl;
                    } else if (analysis.top() == "+") {
                        analysis.pop();
                        input.pop();
                        printInputStack(input);
                        printAnalysisStack(analysis);
                        cout << "MATCH" << endl;
                    } else {
                        cout << "��LL1�ķ����ʽ" << endl;
                        return 0;
                    }
                    break;
                case '*':
                    if (analysis.top() == "T'") {
                        analysis.pop();
                        analysis.push("T'");
                        analysis.push("F");
                        analysis.push("*");
                        printInputStack(input);
                        printAnalysisStack(analysis);
                        cout << ACTIONLIST[4] << endl;
                    } else if (analysis.top() == "*") {
                        analysis.pop();
                        input.pop();
                        printInputStack(input);
                        printAnalysisStack(analysis);
                        cout << "MATCH" << endl;
                    } else {
                        cout << "��LL1�ķ����ʽ" << endl;
                        return 0;
                    }
                    break;
                case '(':
                    if (analysis.top() == "E") {
                        analysis.pop();
                        analysis.push("E'");
                        analysis.push("T");
                        printInputStack(input);
                        printAnalysisStack(analysis);
                        cout << ACTIONLIST[0] << endl;
                    } else if (analysis.top() == "T") {
                        analysis.pop();
                        analysis.push("T'");
                        analysis.push("F");
                        printInputStack(input);
                        printAnalysisStack(analysis);
                        cout << ACTIONLIST[3] << endl;
                    } else if (analysis.top() == "F") {
                        analysis.pop();
                        analysis.push(")");
                        analysis.push("E");
                        analysis.push("(");
                        printInputStack(input);
                        printAnalysisStack(analysis);
                        cout << ACTIONLIST[6] << endl;
                    } else if (analysis.top() == "(") {
                        analysis.pop();
                        input.pop();
                        printInputStack(input);
                        printAnalysisStack(analysis);
                        cout << "MATCH" << endl;
                    } else {
                        cout << "��LL1�ķ����ʽ" << endl;
                        return 0;
                    }
                    break;
                case ')':
                    if (analysis.top() == "E'") {
                        analysis.pop();
                        printInputStack(input);
                        printAnalysisStack(analysis);
                        cout << ACTIONLIST[2] << endl;
                    } else if (analysis.top() == "T'") {
                        analysis.pop();
                        printInputStack(input);
                        printAnalysisStack(analysis);
                        cout << ACTIONLIST[5] << endl;
                    } else if (analysis.top() == "F") {
                        analysis.pop();
                        analysis.push(")");
                        analysis.push("E");
                        analysis.push("(");
                        printInputStack(input);
                        printAnalysisStack(analysis);
                        cout << ACTIONLIST[6] << endl;
                    } else if (analysis.top() == ")") {
                        analysis.pop();
                        input.pop();
                        printInputStack(input);
                        printAnalysisStack(analysis);
                        cout << "MATCH" << endl;
                    } else {
                        cout << "��LL1�ķ����ʽ" << endl;
                        return 0;
                    }
                    break;
                case '$':
                    if (analysis.top() == "E'") {
                        analysis.pop();
                        printInputStack(input);
                        printAnalysisStack(analysis);
                        cout << ACTIONLIST[2] << endl;
                    } else if (analysis.top() == "T'") {
                        analysis.pop();
                        printInputStack(input);
                        printAnalysisStack(analysis);
                        cout << ACTIONLIST[5] << endl;
                    } else {
                        cout << "��LL1�ķ����ʽ" << endl;
                        return 0;
                    }
                    break;
                default:
                    cout << "�Ƿ��ַ���" << input.top() << endl;
                    return 0;
            }
        }
        cout << "�������������ʽ�Ϸ�" << endl;
        // ���ջ
        while (!input.empty()) {
            input.pop();
        }
        while (!analysis.empty()) {
            analysis.pop();
        }
    }
}
