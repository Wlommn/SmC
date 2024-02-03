#include "./parse.h"

bool is_function = false;
char postfix[IO_MAX_SIZE * 2];

void clean_spaces(char* str) {
    int len = strlen(str);
    int i = 0, j = 0;
    while (isspace(str[i])) {
        i++;
    }

    if (i > 0) {
        for (; j < len - i + 1; j++) {
            str[j] = str[j + i];
        }
    }

    len = strlen(str);
    j = len - 1;
    while (j >= 0 && isspace(str[j])) {
        str[j] = '\0';
        j--;
    }

    len = strlen(str);
    i = 0;
    while (i < len - 1) {
        if (isspace(str[i]) && isspace(str[i + 1])) {
            for (j = i + 1; j < len; j++) {
                str[j] = str[j + 1];
            }
            len--;
        } else {
            i++;
        }
    }
}

// void input_formatting(char *input) {
//     size_t len = strlen(input);
//     clean_spaces(input);
//     for (size_t i = 0; i < len; i++) {
//         if (input[i] == ' ' && (i != 0  && isdigit(input[i - 1])) && isdigit(input[i + 1])) {
//             input[i] = '*';
//         }
//     }
// }

// bool check_input(char *input) {
//     bool result = true;

//     return result;
// }

char* infix_to_postfix(char *infix) {
    struct lconv *local = localeconv();
    int len = strlen(infix);
    memset(postfix, '\0', IO_MAX_SIZE * 2);
    int j = 0;

    Stack *operator_stack = Init_Stack();

    char dbl_sep = '.';
    if (local->decimal_point[0] == ',') {
        dbl_sep = ',';
    }

    for (int i = 0; i < len; i++) {
        char ch = infix[i];
        

        if (ch == ' ') {
            continue;
        } else if (isdigit(ch) || ch == '.' || ch == ',' || ch == 'x' || ch == 'X') {
            if (ch == '.' || ch == ',') {
                postfix[j++] = dbl_sep;
            } else {
                if (j > 0 && !isdigit(postfix[j - 1])
                    && postfix[j - 1] != dbl_sep
                    && !isspace(postfix[j - 1])) {
                    postfix[j++] = ' ';
                }
                postfix[j++] = ch;
                if ((i + 1) < len && !isdigit(infix[i + 1])
                    && infix[i + 1] != '.'
                    && infix[i + 1] != ','
                    && !isspace(postfix[j - 1])) {
                    postfix[j++] = ' ';
                }
                if (ch == 'x' || ch == 'X') {
                    is_function = true;
                }
            }
        } else if (is_operator(ch)) {
            operators_t op;
            switch (ch) {
                case '+':
                    op = add_op;
                    break;
                case '-':
                    op = sub_op;
                    break;
                case '*':
                    op = mul_op;
                    break;
                case '/':
                    op = div_op;
                    break;
                case '^':
                    op = scale_op;
                    break;
                default:
                    break;
            }

            if (op == sub_op && (i == 0 || (!isdigit(infix[i-1]) && infix[i-1] != ')'))) {
                op = umin_op;
            }

            if (op == add_op && (i == 0 || (!isdigit(infix[i-1]) && infix[i-1] != ')'))) {
                op = uplus_op;
            }

            while (!Is_Stack_Empty(*operator_stack) && Peek_Stack(*operator_stack) != '('
                   && get_priority(Peek_Stack(*operator_stack)) >= get_priority(op)) {
                postfix[j++] = ' ';
                postfix[j++] = (char)Pop_Stack(operator_stack);
            }
            Push_Stack(operator_stack, op);
        } else if (ch == '(') {
            Push_Stack(operator_stack, ch);
        } else if (ch == ')') {
            while (!Is_Stack_Empty(*operator_stack) && Peek_Stack(*operator_stack) != '(') {
                postfix[j++] = ' ';
                postfix[j++] = (char)Pop_Stack(operator_stack);
            }

            if (!Is_Stack_Empty(*operator_stack) && Peek_Stack(*operator_stack) == '(') {
                Pop_Stack(operator_stack);
            }
        } else if (ch == 's' && infix[i+1] == 'i' && infix[i+2] == 'n') {
            Push_Stack(operator_stack, sin_op);
            i+=2;
        } else if (ch == 'c' && infix[i+1] == 'o' && infix[i+2] == 's') {
            Push_Stack(operator_stack, cos_op);
            i+=2;
        } else if (ch == 't' && infix[i+1] == 'a' && infix[i+2] == 'n') {
            Push_Stack(operator_stack, tan_op);
            i+=2;
        } else if (ch == 'a' && infix[i+1] == 's' && infix[i+2] == 'i' && infix[i+3] == 'n') {
            Push_Stack(operator_stack, asin_op);
            i+=3;
        } else if (ch == 'a' && infix[i+1] == 'c' && infix[i+2] == 'o' && infix[i+3] == 's') {
            Push_Stack(operator_stack, acos_op);
            i+=3;
        } else if (ch == 'a' && infix[i+1] == 't' && infix[i+2] == 'a' && infix[i+3] == 'n') {
            Push_Stack(operator_stack, atan_op);
            i+=3;
        } else if (ch == 's' && infix[i+1] == 'q' && infix[i+2] == 'r' && infix[i+3] == 't') {
            Push_Stack(operator_stack, sqrt_op);
            i+=2;
        } else if (ch == 'l' && infix[i+1] == 'o' && infix[i+2] == 'g') {
            Push_Stack(operator_stack, log_op);
            i+=2;
        } else if (ch == 'l' && infix[i+1] == 'n') {
            Push_Stack(operator_stack, ln_op);
            i++;
        } else {
            memset(postfix, '\0', strlen(postfix));
            j = 0;
            break;
        }
    }

    while (!Is_Stack_Empty(*operator_stack)) {
        postfix[j++] = ' ';
        postfix[j++] = (char)Pop_Stack(operator_stack);
    }

    postfix[j] = '\0';
    Delete_Stack(operator_stack);
    return postfix;
}

bool is_operator(char ch) {
    bool result = false;
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
        result = true;       
    }
    return result;
}

int get_priority(operators_t op) {
    int result = 0;
    switch (op) {
        case add_op:
        case sub_op:
            result = 1;
            break;
        case mul_op:
        case div_op:
            result = 2;
            break;
        case scale_op:
            result = 3;
            break;
        case umin_op:
        case uplus_op:
            result = 4;
            break;
        default:
            break;
    }
    return result;
}
