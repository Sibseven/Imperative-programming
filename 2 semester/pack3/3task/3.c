#pragma comment(linker, "/STACK:50000000")
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
char* input_string;
int now_pos = 0;
char* operations;
char* now_token;
int is_EOF = 0;
int minus_solo = 0;
int minus_exp = 0;
void Read_Token(){
    char test = input_string[now_pos];
    while (input_string[now_pos] == ' '){
        now_pos++;
        test = input_string[now_pos];
    }
    if (input_string[now_pos] == '\0'){
        is_EOF = 1;
        return;
    }
    for(int i = 0; i<6; i++){
        if (minus_solo == 1 && input_string[now_pos] == '-'){
            break;
        }
        test = input_string[now_pos];
        if(input_string[now_pos] == operations[i]){
            now_token[0] = operations[i];
            now_token[1] = '\0';
            now_pos ++;
            return;
        }
    }
    test = input_string[now_pos];
    int start = now_pos;
    while (isdigit(input_string[now_pos]))
    {
        now_pos++;
        test = input_string[now_pos];
    }
    strncpy(now_token, &input_string[start], now_pos-start);
    //printf("%s\n", now_token);
    now_token[now_pos-start] = '\0';
    return;
}

void Peek_token(){
    int old_pos = now_pos;
    Read_Token();
    now_pos = old_pos;
    return;
} 
double Operation(char oper, double a, double b){
    switch (oper)
    {
    case '+':
        return a+b;
    case '-':
        return a - b;
    case '*':
        return a*b;
    case '/':
        return a/b;
    }
    
}

double Parse_expression();
double Parse_atom(){
    Peek_token();
    if (now_token[0] == '('){
        Read_Token();
        Peek_token();
        if (now_token[0] == '-'){
            Read_Token();
            Peek_token();
            if(now_token[0] == '('){
                minus_solo = 0;
                minus_exp = 1;
                double res = Parse_expression();
                return -res;
            }
            else{
                minus_solo = 1;
            }
        }
        double res = Parse_expression();
        if (minus_exp == 1){
            res = -res;
            minus_exp = 0;
        }
        Read_Token();
        return res;
    }
    else{
        Read_Token();
        if(now_token[0] == '-'){
            Read_Token();
            if (now_token[0] == '('){
                minus_exp = 1;
                minus_solo = 0;
                double res = Parse_expression();
                return -res;
            }
            else{
                minus_solo = 1;
            }
        }
        char test = now_token[0];
        double res = strtod(now_token, NULL);
        if(minus_solo == 1){
            res = -res;
            minus_solo = 0;
        }
        return(res);
    }
}
double Parse_monome(){
    double res = Parse_atom();
    Peek_token();
    while (now_token[0] == '*' || now_token[0] == '/'){
        Read_Token();
        char oper = now_token[0];
        double add = Parse_atom();
        res = Operation(oper,res, add);
        Peek_token();
    }
    return res;
}
double Parse_expression(){
    double res = Parse_monome();
    Peek_token();
    char test = now_token[0];
    while (now_token[0] == '+' || now_token[0] == '-'){
        Read_Token();
        char oper = now_token[0];
        double add = Parse_monome();
        res = Operation(oper ,res, add);
        Peek_token();
    }
    return res;
}


int main(){
    FILE *input_file = fopen("input.txt", "r");
    freopen("output.txt", "w", stdout);
    operations = (char*) malloc(100* sizeof(char));
    now_token = (char*) malloc(500* sizeof(char));
    operations = "+-*/()";
    input_string = (char*) malloc(510001 * sizeof(char));
    fgets(input_string, 510000, input_file);
    printf("%0.20lf",Parse_expression());
    return 0;
}