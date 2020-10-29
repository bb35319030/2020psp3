#include <stdio.h>
#include<string.h>
#define DEBUG

#define ALPHABET_LEN    255

char StrOriginal[] = "On a dark deseart highway, cool wind in my hair.";
char StrKey[] = "wind";

char* ForceSearch(char text[], char key[])
{
    //  ここを実装する
    int start;
    int pos;
    int find;
    int text_len = strlen(text);
    int key_len = strlen(key);
    find = 0;
     for(start=0; start < (text_len - key_len); start++){
         for(pos=0; pos < key_len; pos++){
          if(text[start+pos] == key[pos]){
              if(pos==key_len - 1){
                  find=1;
                  break;
              }
              }else{
                  break;
              }

     }
     if(find==1){
                  break;
     }
     }
     if(pos==key_len-1){
         return text + start;
     }else{ 
         return NULL;
     }
}

char* BMSearch(char text[], char key[])
{
    //  ここを実装する
    int index;
    int key_index;
    int find;
    int index_bf;
    int text_len = strlen(text);
    int key_len = strlen(key);
    int table[ALPHABET_LEN];
    find=0;
    for(index=0; index < ALPHABET_LEN; index++) {
        table[index]=key_len;
    }
        for(key_index=0; key_index < key_len; key_index++){
            table[(int)key[key_index]]=key_len - 1 - key_index;
    }
    index = key_len - 1;
    while(index < text_len){
        for(key_index=key_len; key_index > 0; key_index--){
            index_bf=index;
            if(text[index]==key[key_index]){
                index = index -1;
                if(key_index == 1){
                    find=1;
                    break;
                }
            }else{
                index = index + table[(int)key[key_index]];

                if(index <= index_bf){
                    index = index_bf +1;
                }
            }
        }
        if(find==1){
            break;
        }
    }
    if(key_index==1){
         return text + index;
     }else{ 
         return NULL;
     }

    

}

int main(void)
{
    char*   str;
    str = ForceSearch(StrOriginal, StrKey);
    printf("Force Search. Find keyword at:%s\n", str);

    str = BMSearch(StrOriginal, StrKey);
    printf("BM Search. Find keyword at:%s\n", str);

    return 0;
}