#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cmp(const void* a, const void* b) {
  if (*(long long*)a > *(long long*)b)return 1;
  if (*(long long*)a < *(long long*)b)return -1;
  return 0;
}

int removeDupl(const long long* arr, int size, long long* res) {
  int cnt = 0;
  if (arr != NULL)
  {
    int ch = 0;
    long long prev = arr[0];
    for (int i = 1; i < size; i++)
    {
      if (arr[i] == prev)
        ch++;
      else {
        if (ch == 0) {
          res[cnt++] = prev;
        }
        ch = 0;
      }
      prev = arr[i];
    }
    res[cnt++] = prev;
  }
  return cnt;
}

int merge(const long long* a, int ak, const long long* b, int bk, long long* res) {
  int ia = 0, ib = 0;
  int ind = 0;
  while (ak > ia || bk > ib) {
    if (ak > ia && bk > ib) {
      if (a[ia] == b[ib]) {
        ia++;
        ib++;
      }
      else if(a[ia] < b[ib])
        res[ind++] = a[ia++];
      else {
        ib++;
      }
    }
    else if (ak > ia && bk <= ib) {
      res[ind++] = a[ia++];
    }
    else if (ak <= ia && bk > ib) {
      break;
    }
  }
  return ind;
}

int main() {
  int n, m;
  scanf("%d", &n);
  long long* a = (long long*)malloc(sizeof(long long) * n);
  //int cnt = 0;
  for (int i = 0; i < n; i++)
  {
    scanf("%lld", &a[i]);
  }
  qsort(a, n, sizeof(long long), cmp);
  scanf("%d", &m);
  long long* b = (long long*)malloc(sizeof(long long) * m);
  for (int i = 0; i < m; i++)
  {
    scanf("%lld", &b[i]);
  }
  qsort(b, m, sizeof(long long), cmp);
  long long* a1 = (long long*)malloc(sizeof(long long) * n);
  int s1 = removeDupl(a, n, a1);
  long long* b1 = (long long*)malloc(sizeof(long long) * m);
  int s2 = removeDupl(b, m, b1);
  free(a);
  free(b);
  long long* res = (long long*)malloc(sizeof(long long) * s1);
  int k = merge(a1, s1, b1, s2, res);
  printf("%d\n", k);
  for (int i = 0; i < k; i++)
  {
    printf("%lld ", res[i]);
  }
  free(a1);
  free(b1);
  free(res);
  return 0;
}