#include "./calc.h"

void separate_on_tokens(char **tokens, int *length, char *expression) {
  int expression_len = strlen(expression), count = 0;
  for (int i = 0, j = 0; i < expression_len; i++) {
    char ch = expression[i];
    if (isspace(ch)) {
      count++;
      j = 0;
    } else {
      tokens[count][j++] = ch;
    }
  }
  *length = count + 1;
}

double calc(char *expression, double x) {
  Stack *stack = Init_Stack();
  double op1 = 0.0, op2 = 0.0, result = 0.0;
  char **tokens = calloc(IO_MAX_SIZE, sizeof(char *));
  for (int i = 0; i < IO_MAX_SIZE; i++) {
    tokens[i] = calloc(IO_MAX_SIZE, sizeof(char));
  }
  int length = 0;

  separate_on_tokens(tokens, &length, expression);

  for (int i = 0; i < length; i++) {
    char ch = tokens[i][0];
    if (isdigit(ch)) {
      Push_Stack(stack, atof(tokens[i]));
    } else if (ch == 'x' || ch == 'X') {
      Push_Stack(stack, x);
    } else if (ch == 'P') {
      Push_Stack(stack, PI);
    } else if (is_binary_op(ch)) {
      op2 = Pop_Stack(stack);
      op1 = Pop_Stack(stack);
      Push_Stack(stack, binary_operation(ch, op1, op2));
    } else if (is_unary_op(ch)) {
      op1 = Pop_Stack(stack);
      Push_Stack(stack, unary_operation(ch, op1));
    }
  }

  result = Pop_Stack(stack);
  for (int i = 0; i < IO_MAX_SIZE; i++) {
    free(tokens[i]);
  }
  free(tokens);
  Delete_Stack(stack);
  if (result != 0.0 && !isnan(result)) {
    result = round(result * 1000000.0) / 1000000.0;
  }
  return result;
}

bool is_binary_op(char ch) {
  bool result = false;
  switch ((int)ch) {
    case add_op:
    case sub_op:
    case mul_op:
    case div_op:
    case scale_op:
      result = true;
      break;
    default:
      break;
  }
  return result;
}

double binary_operation(char ch, double op1, double op2) {
  double result = 0.0;
  switch ((int)ch) {
    case add_op:
      result = op1 + op2;
      break;
    case sub_op:
      result = op1 - op2;
      break;
    case mul_op:
      result = op1 * op2;
      break;
    case div_op:
      result = op1 / op2;
      break;
    case scale_op:
      result = pow(op1, op2);
      break;
    default:
      break;
  }
  return result;
}

bool is_unary_op(char ch) {
  bool result = false;
  switch ((int)ch) {
    case umin_op:
    case uplus_op:
    case sin_op:
    case cos_op:
    case tan_op:
    case acos_op:
    case asin_op:
    case atan_op:
    case sqrt_op:
    case log_op:
    case ln_op:
      result = true;
      break;
    default:
      break;
  }
  return result;
}

double unary_operation(char ch, double op) {
  double result = 0.0;
  switch ((int)ch) {
    case umin_op:
      result = op * -1;
      break;
    case uplus_op:
      result = op;
      break;
    case sin_op:
      result = sin(degToRad(op));
      break;
    case cos_op:
      result = cos(degToRad(op));
      break;
    case tan_op:
      result = tan(degToRad(op));
      break;
    case asin_op:
      result = asin(degToRad(op));
      break;
    case acos_op:
      result = acos(degToRad(op));
      break;
    case atan_op:
      result = atan(degToRad(op));
      break;
    case sqrt_op:
      result = sqrt(op);
      break;
    case log_op:
      result = log10(op);
      break;
    case ln_op:
      result = log(op);
      break;
    default:
      break;
  }
  return result;
}
