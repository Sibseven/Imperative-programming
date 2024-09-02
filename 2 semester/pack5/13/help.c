void siftDown(int i) 
{ 
    while (2 * i + 1 < topHeap) 
    { 
        int left = 2 * i + 1; 
        int right = 2 * i + 2; 
        int j = left; 
        if(right < topHeap && dist[heap[right]] < dist[heap[left]]) 
        { 
            j = right; 
        } 
        if(dist[heap[i]] <= dist[heap[j]]) break; 
        swap(&vert2heap[heap[i]], &vert2heap[heap[j]]); 
        // swap(&heap2vert[i], &heap2vert[j]); 
        swap(&heap[i], &heap[j]); 
        i = j; 
    } 
} 
 
void siftUp(int i) 
{ 
    while(dist[heap[i]] < dist[heap[(i - 1) / 2]]) 
    { 
        swap(&vert2heap[heap[i]], &vert2heap[heap[(i - 1) / 2]]); 
        // swap(&heap2vert[i], &heap2vert[(i - 1) / 2]); 
        swap(&heap[i], &heap[(i - 1) / 2]); 
        i = (i - 1) / 2; 
    } 
} 
 
int extractMin() 
{ 
    // vert2heap[heap[0]] = -1; 
    int min = heap[0]; 
    heap[0] = heap[topHeap - 1]; 
    // heap2vert[0] = heap[0]; 
    vert2heap[heap[0]] = 0; 
    topHeap--; 
    siftDown(0); 
    return min; 
} 
 
void insert(int key) 
{ 
    heap[topHeap++] = key; 
    vert2heap[key] = topHeap - 1; 
    // heap2vert[topHeap - 1] = key; 
    siftUp(topHeap - 1); 
} 
 