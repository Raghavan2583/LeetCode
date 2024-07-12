int calPoints(char ** ops, int opsSize) {
    int *stack = (int *)malloc(sizeof(int) * opsSize);
    int top = -1;
    int sum = 0;
    for (int i = 0; i < opsSize; i++) {
       if (strcmp(ops[i], "+") == 0) {
            // Calculate the sum of the last two valid rounds
            int last = stack[top];
            int second_last = stack[top - 1];
            int points = last + second_last;
            sum += points;
            // Push the sum onto the stack
            top++;
            stack[top] = points;
    }
    else if (strcmp(ops[i], "D") == 0) {
            // Double the score of the last valid round
            int points = stack[top] * 2;
            sum += points;
            // Push the doubled score onto the stack
            top++;
            stack[top] = points;
    }
    else if (strcmp(ops[i], "C") == 0) {
            // Cancel the last valid round
            sum -= stack[top];
            top--;
   } 
   else 
   {        
    int points = atoi(ops[i]);
    sum += points;
    top++;
    stack[top] = points;
   }}
    free(stack);
    return sum;
}