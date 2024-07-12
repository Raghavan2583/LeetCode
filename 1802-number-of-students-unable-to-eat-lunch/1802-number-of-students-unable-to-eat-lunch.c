int countStudents(int* students, int studentsSize, int* sandwiches, int sandwichesSize) {
    int st = 0, sd = 0, count = 0;
    while(st != studentsSize){
        if(students[st] == sandwiches[sd]) {
            if(st == studentsSize - 1) {
                st = 0;
            } else {
                for(int i = st; i < studentsSize - 1; ++i) {
                    students[i] = students[i + 1];
                }
            }
            --studentsSize;
            ++sd;
            count = 0;
            st = 0;
        } else {
            ++st;
            ++count;
        }
        if(count == studentsSize) {
            break;
        }
    }
    return sandwichesSize - sd;

}