#include <stdio.h>
#include <stdlib.h>
#define TEST
typedef enum {false_t,true_t} bool_t;
typedef struct
{
    bool_t isPalyndrome;
     char * palyStr;
     int len;
} palynStr_t;

palynStr_t palyndrome(char *s);
int main(void)
{
    #ifdef TEST
    char *a="abcderartkja???????????";
    char *b="?ab??a";
    char *c="bab??a";
    char *d="?a?";
    char *iter=NULL;
    palynStr_t ans;
    printf("TEST 1\n");
    ans=palyndrome(a);
    if(ans.isPalyndrome)
    {
        iter=ans.palyStr;
        int cnt=0;
        while(cnt!=ans.len)
        {
            printf("%c ",*iter);
            iter++;
            cnt++;
        }
        printf("\n");
    }
    else
    {
        printf("NO\n");
    }
    printf("\nTEST 2\n");
    ans=palyndrome(b);
    if(ans.isPalyndrome)
    {
        iter=ans.palyStr;
        int cnt=0;
        while(cnt!=ans.len)
        {
            printf("%c ",*iter);
            iter++;
            cnt++;
        }
        printf("\n");
    }
    else
    {
        printf("NO\n");
    }
    printf("\nTEST 3\n");
    ans=palyndrome(c);
    if(ans.isPalyndrome)
    {
        iter=ans.palyStr;
        int cnt=0;
        while(cnt!=ans.len)
        {
            printf("%c ",*iter);
            iter++;
            cnt++;
        }
        printf("\n");
    }
    else
    {
        printf("NO\n");
    }
    printf("\nTEST 4\n");
    ans=palyndrome(d);
    if(ans.isPalyndrome)
    {
        iter=ans.palyStr;
        int cnt=0;
        while(cnt!=ans.len)
        {
            printf("%c ",*iter);
            iter++;
            cnt++;
        }
        printf("\n");
    }
    else
    {
        printf("NO\n");
    }
    free(ans.palyStr);
    #endif // TEST
}
palynStr_t palyndrome(char *s)
{
    palynStr_t answer= {false_t,NULL,0};
    bool_t isPalyndrome=true_t;
    char *startString=NULL;
    startString=s;
    char* endString=NULL;
    endString=s;
    int lenStr=1;

    while(*(endString+1)!='\0')
    {
        if((int)*endString==32)
        {
            isPalyndrome=false_t;
            answer.isPalyndrome=false_t;
            return answer;
        }
        endString++;
        lenStr++;

    }

#ifdef TEST
    printf("LEN %d\n",lenStr);

#endif // TEST
int tmpLen=lenStr;
    if(lenStr==1)
    {
        isPalyndrome=false_t;
        answer.isPalyndrome=false_t;
        return answer;
    }
    char* nowString=(char*)calloc(lenStr,sizeof(char));
#ifdef TEST
    char *read=NULL;
    read=nowString;
#endif // TEST
    char *startNowString=NULL;
    char *endNowString=NULL;
    startNowString=nowString;
    endNowString=nowString+lenStr-1;

    if(lenStr%2==0)
    {
        lenStr/=2;
    }
    else
    {
        ++lenStr;
        lenStr/=2;

    }

    while(lenStr!=0)
    {

        if(*startString!=*endString&&*endString!='?'&&*startString!='?')
        {
            isPalyndrome=false_t;
            answer.isPalyndrome=false_t;
            return answer;
        }
        if(startString==endString&&*startString!='?')
        {
            *startNowString=*startString;
            break;
        }
        if(startString==endString&&*startString=='?')
        {
            *startNowString='a';
            break;
        }
        if((*startString=='?')&&(*endString!='?'))
        {
            *startNowString=*endString;
            *endNowString=*endString;
        }
        if((*endString=='?')&&(*startString!='?'))
        {
            *endNowString=*startString;
            *startNowString=*startString;
        }
        if((*startString=='?')&&(*endString=='?'))
        {
            *startNowString='a';
            *endNowString='a';
            startNowString++;
            endNowString--;
            startString++;
            endString--;
            lenStr--;
            continue;
        }
        if(*startString==*endString)
        {
            *startNowString=*startString;
            *endNowString=*startString;
        }

        startNowString++;
        endNowString--;
        startString++;
        endString--;
        lenStr--;
    }
int cnt=0;
#ifdef TEST
    while(cnt!=tmpLen)
    {
        printf("%c ",*read);
        read++;
        cnt++;

    }
#endif // TEST
    if(isPalyndrome)
    {
#ifdef TEST
        printf("\nITS PALYNDROME\n");
#endif // TEST
        answer.isPalyndrome=true_t;
        answer.palyStr=nowString;
        answer.len=tmpLen;
        return answer;
    }
    else
    {
#ifdef TEST
        printf("\nITS NOT PALYNDROME\n");
#endif // TEST
        answer.isPalyndrome=false_t;
        return answer;
    }
}
