#include "stdio.h"
#include "stdlib.h"
#include "string.h"
enum {
    SIZ = 104,
    ALP = 26,
};
 
struct Node {
    unsigned mask;
    struct Node *lnk[ALP];
};
 
struct Node *head;
struct Node *next = 0;
int ansCnt;
char one[ALP+1];
int dc[ALP+1];
int vis[ALP+1];
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
struct Node *getNode(){
    struct Node *p;
    if (next){
        p = next;
        next = next->lnk[0];
    } else {
        p = (struct Node*)malloc(sizeof(struct Node));
    }
    memset(p, 0, sizeof(struct Node));
    return p;
}
void putNode(struct Node *p){
    p->lnk[0] = next;
    next = p;
}
 
void release(struct Node *p){
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
 
struct Node * insert(struct Node *h, char c){
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
 
int match(struct Node *p,const char* s, int d){
    if (p==0) return 0;
    if (d >= strlen(s)){
        return p->mask & (1<<d);
    }
    int t = s[d] - 'A';
    if (dc[t] >= 0)
        return match(p->lnk[dc[t]], s, d+1);
 	int i;
    for (i=0; i<ALP; ++i){
        if (vis[i])
            continue;
        vis[i] = 1;
        dc[t] = i;
        if (match(p->lnk[i], s, d+1)){
            vis[i] = 0;
            dc[t] = -1;
            return 1;
        }
        vis[i] = 0;
        dc[t] = -1;
    }
    return 0;
}
 
int check(){
    int i;
    for (i=0; i<wdsize; ++i){
        if (!match(head, wd[i], 0)){
            return 0;
        }
    }
    return 1;
}
 
void dfs(int d){
    if (d >= tnum){
        ++ansCnt;
        memset(one, '*', sizeof(one));
        int i;
		for (i=0; i<ALP; ++i){
            if (dc[i] < 0) continue;
            one[dc[i]] = i + 'A';
        }
        one[ALP] = 0;
        return ;
    }
    int i;
    for (i=0; i<ALP; ++i){
        if (vis[i])
            continue;
        vis[i] = 1;
        dc[tst[d]] = i;
        if (check()){
            dfs(d+1);
            if (ansCnt >= 2)
                return ;
        }
        vis[i] = 0;
    }
    dc[tst[d]] = -1;
}
 
void solve(int flag){
    memset(vis, 0, sizeof(vis));
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
    int flag = 1;
    scanf("%d ", &n);
    while(n--){
        flag = 1;
        memset(freq, 0, sizeof(freq));
        wdclear();
        p = fgets(buf, SIZ, stdin);   
        while(p && *p != '\n'){
            p = strtok(p, tstr);
            while(p!= NULL){
                wdpush_back(p);
                if (wdbacksize()> 20)
                    flag = 0;
                if (head->mask & (1<<wdbacksize()) != (1<<wdbacksize())){
                    flag = 0;
                }
                int i;
                for (i=0; p[i]; ++i){
                    ++freq[p[i]-'A'];
                }
                p = strtok(NULL, tstr);
            }
            p = fgets(buf, SIZ, stdin);   
        }
        tnum = 0;
        int i;
        for (i=0; i<ALP; ++i){
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
 
    struct Node *p=0;
    release(head);
    head = getNode();
 
    while(n--){
        scanf("%s ", buf);
        t = strlen(buf);
        p = head;
        int i;
        for (i=0; i<t; ++i){
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
