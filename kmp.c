#include <string.h>
#include <stdio.h>

/* next[i] = 模式串 p[0..i-1] 的最长相等前后缀长度
   同时也是失配时应该回退到的位置 */
void GetNext(char *p, int *next) {
    int n = strlen(p);
    next[0] = -1;  // 约定：第一个字符失配，主串指针后移
    next[1] = 0;
    int i = 1, j = 0;
    while (i < n - 1) {
        if (j == -1 || p[i] == p[j]) {
            i++; j++;
            next[i] = j;
        } else {
            j = next[j];
        }
    }
}

/* 返回 b 在 a 中首次出现的位置（0起始），未找到返回 -1 */
int kmp(char *a, char *b) {
    int n = strlen(a);
    int m = strlen(b);
    if (m == 0) return 0;
    if (n < m)  return -1;

    int next[256];
    GetNext(b, next);

    int i = 0, j = 0;
    while (i < n && j < m) {
        if (j == -1 || a[i] == b[j]) {
            i++; j++;
        } else {
            j = next[j];
        }
    }
    return (j == m) ? (i - m) : -1;
}

int main(void) {
    printf("测试1: text=ababcabcacbab, pat=abcac  -> %d (预期5)\n",
           kmp("ababcabcacbab", "abcac"));
    printf("测试2: pat在开头              -> %d (预期0)\n",
           kmp("hello", "he"));
    printf("测试3: pat在末尾              -> %d (预期3)\n",
           kmp("abcde", "de"));
    printf("测试4: 找不到                 -> %d (预期-1)\n",
           kmp("abcde", "xy"));
    printf("测试5: 单字符匹配             -> %d (预期2)\n",
           kmp("abx", "x"));
    printf("测试6: pat比text长            -> %d (预期-1)\n",
           kmp("ab", "abc"));
    printf("测试7: 空模式串               -> %d (预期0)\n",
           kmp("abc", ""));
    return 0;
}
