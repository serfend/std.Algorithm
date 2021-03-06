#include "stdio.h"
#include "stdlib.h"
#include "string.h"
enum {
    SIZ = 104,
    ALP = 26,
};
 
struct Node {
    unsigned mask;
    Node *lnk[ALP];
};
 
Node *head;
Node *next = 0;
int ansCnt;
char one[ALP+1];
int dc[ALP+1];
bool vis[ALP+1];
char buf[SIZ];
int freq[ALP];
int tst[ALP], tnum;

char** wd; 
void initWd(){
	wd=(char**)malloc(sizeof(char*)*2333);
}
int wdsize=0;
void wdpush_back(char* p){
	int len=strlen(p);
	wd[wdsize]=(char*)malloc(sizeof(char*)*len);
	strcpy(wd[wdsize],p);
	wdsize++;
}
void wdclear(){
	wdsize=0;
	initWd();
}
int wdbacksize(){
	return strlen(wd[wdsize-1]);
}
Node *getNode(){
    Node *p;
    if (next){
        p = next;
        next = next->lnk[0];
    } else {
        p = (Node*)malloc(sizeof(Node));
    }
    memset(p, 0, sizeof(Node));
    return p;
}
void putNode(Node *p){
    p->lnk[0] = next;
    next = p;
}
 
void release(Node *p){
    if (p == 0) return;
    int i;
    for (i=0; i<ALP; ++i){
        if (p->lnk[i]){
            release(p->lnk[i]);
        }
        p->lnk[i] = 0;
    }
    putNode(p);
}
 
Node * insert(Node *h, char c){
    c -= 'A';
    if (h->lnk[c] == 0){
        h->lnk[c] = getNode();
    }
    h = h->lnk[c];
    return h;
}
 
int cmp(const void* a, const void* b){
	
    return freq[*(int*)a] > freq[*(int*)b];
}
 
int match(Node *p,const char* s, int d){
    if (p==0) return false;
    if (d >= strlen(s)){
        return p->mask & (1<<d);
    }
    int t = s[d] - 'A';
    if (dc[t] >= 0)
        return match(p->lnk[dc[t]], s, d+1);
 
    for (int i=0; i<ALP; ++i){
        if (vis[i])
            continue;
        vis[i] = true;
        dc[t] = i;
        if (match(p->lnk[i], s, d+1)){
            vis[i] = false;
            dc[t] = -1;
            return true;
        }
        vis[i] = false;
        dc[t] = -1;
    }
    return false;
}
 
int check(){
    int i;
    for (i=0; i<wdsize; ++i){
        if (!match(head, wd[i], 0)){
            return false;
        }
    }
    return true;
}
 
void dfs(int d){
    if (d >= tnum){
        ++ansCnt;
        memset(one, '*', sizeof(one));
        for (int i=0; i<ALP; ++i){
            if (dc[i] < 0) continue;
            one[dc[i]] = i + 'A';
        }
        one[ALP] = 0;
        return ;
    }
    for (int i=0; i<ALP; ++i){
        if (vis[i])
            continue;
        vis[i] = true;
        dc[tst[d]] = i;
        if (check()){
            dfs(d+1);
            if (ansCnt >= 2)
                return ;
        }
        vis[i] = false;
    }
    dc[tst[d]] = -1;
}
 
void solve(bool flag){
    memset(vis, false, sizeof(vis));
    memset(dc, -1, sizeof(dc));
    ansCnt = 0;
    int t;
    if (flag){
        dfs(0);
        t = ansCnt;
    } else {
        t = -1;
    }
    if (t <= 0){
        printf("#No solution#\n");
    } else if(t > 1){
        printf("#More than one solution#\n");
    } else {
        one[ALP] = 0;
       printf("%s\n", one);
    }
}
 
void fun(){
    int n;
    char *p;
    const char *tstr=" \n\t\r";
    bool flag = true;
    scanf("%d ", &n);
    while(n--){
        flag = true;
        memset(freq, 0, sizeof(freq));
        wdclear();
        p = fgets(buf, SIZ, stdin);   
        while(p && *p != '\n'){
            p = strtok(p, tstr);
            while(p!= NULL){
                wdpush_back(p);
                if (wdbacksize()> 20)
                    flag = false;
                if (head->mask & (1<<wdbacksize()) != (1<<wdbacksize())){
                    flag = false;
                }
                for (int i=0; p[i]; ++i){
                    ++freq[p[i]-'A'];
                }
                p = strtok(NULL, tstr);
            }
            p = fgets(buf, SIZ, stdin);   
        }
        tnum = 0;
        for (int i=0; i<ALP; ++i){
            if (freq[i]){
                tst[tnum++] = i;
            }
        }
        qsort(tst, tnum, sizeof(tst[0]),cmp);
        solve(flag);
    }
}
 
int readIn(){
    int n,t;
    if(scanf("%d ", &n)!=1)
        return 0;
 
    Node *p=0;
    release(head);
    head = getNode();
 
    while(n--){
        scanf("%s ", buf);
        t = strlen(buf);
        p = head;
        for (int i=0; i<t; ++i){
            p = insert(p, buf[i]);
        }
        p->mask |= (1<<t);
    }
 
    return 1;
}
 
int main(){
 
    while(readIn() > 0){
        fun();
    }
 
    return 0;
}
