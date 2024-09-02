


typedef struct deque{
    int head;
    int last;
    int size;
    int cap;
    int* arr;
} deque;
 


void resize(deque *deq){
    int *ndeq = (int *) malloc(sizeof(int), deq->size*2);
    int step = deq->head, step2 = 0;
    while (step < deq->cap){
        ndeq[step2++] = deq->arr[step++];
    }
    while (step < deq->head){
        ndeq[step2++] = deq->arr[step++];
    }
    free(deq->arr);
    deq -> arr = ndeq;
    deq -> head = 0;
    deq -> last = step2 - 1;
    deq -> cap *= 2;
    return;
}

int get(deque *deq, int pos){
    if ((deq -> head+pos) < deq->cap){
        return deq->arr[deq->head+pos];
    }
    else{
        return;
    }
}


void push_front(deque *deq, int val){
    if (deq->size == deq->cap){
        resize(deq);
    }
    deq->arr[(deq->head-1 + deq->cap) % deq->cap] = val;
    deq->head = (deq->head-1 + deq->cap) % deq->cap;
    deq->size++;
    return;
}

void push_back(deque *deq, int val){
    if (deq->size == deq->cap){
        resize(deq);
    }
    deq->arr[(deq->last+1) % deq->cap] = val;
    deq->last = (deq->last+1) % deq->cap;
    deq->size++;
    return;
}