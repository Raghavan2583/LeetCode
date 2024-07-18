#define INITIAL_ARRAY_SIZE 20
#define RESIZE_MULTIPLE 2

typedef struct BrowserHistory
{
    char** history;
    int curr;
    int end;
    int currSize;
} BrowserHistory;

int max(int x, int y)
{
    return x > y ? x : y;
}

int min(int x, int y)
{
    return x < y ? x : y;
}

void extendArray(BrowserHistory* obj)
{
    int oldSize = obj->currSize;
    int newSize = obj->currSize * RESIZE_MULTIPLE;
    obj->history = realloc(obj->history, newSize * sizeof(char*));
    for(int i = oldSize; i < newSize; i++)
        obj->history[i] = malloc(sizeof(char*));
    obj->currSize = newSize;
}

BrowserHistory* browserHistoryCreate(char * homepage)
{
    BrowserHistory* bh = malloc(sizeof(BrowserHistory));
    bh->curr = 0;
    bh->history = malloc(INITIAL_ARRAY_SIZE * sizeof(char*));
    for(int i = 0; i < INITIAL_ARRAY_SIZE; i++)
        bh->history[i] = malloc(sizeof(char*));
    bh->currSize = INITIAL_ARRAY_SIZE;
    bh->history[bh->curr] = homepage;
    bh->end = bh->curr;
    return bh;
}

void browserHistoryVisit(BrowserHistory* obj, char * url)
{
    //extend size of array if index is about to go out of bounds
    if(obj->curr == obj->currSize - 1)
        extendArray(obj);
    obj->history[++obj->curr] = url;  
    obj->end = obj->curr;
}

char * browserHistoryBack(BrowserHistory* obj, int steps)
{
    obj->curr = max(0, obj->curr - steps);
    return obj->history[obj->curr];
}

char * browserHistoryForward(BrowserHistory* obj, int steps)
{
    obj->curr = min(obj->end, obj->curr + steps);
    return obj->history[obj->curr];
}

void browserHistoryFree(BrowserHistory* obj)
{
    for(int i = 0; i < obj->currSize; i++)
        free(obj->history[i]);
    free(obj->history);
    free(obj);
}