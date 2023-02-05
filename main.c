#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<stdlib.h>
#include<dir.h>
#include <string.h>
#include <conio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <ctype.h>
#include<math.h>
#include <windows.h>
#include <dirent.h>

void make_file();
void insert_in_file();
void cat_file();
void remove_file();
void copy_file();
void cut_file();
void paste_file();
void find_file();
void replace_file();
void grep_file();
void undo_file();
void auto_indent();
void compare_file();
void tree_file();
void listFilesRecursively(char *path);
int main() {
//  while (1) {
    int comand_char = 0;
    int temp;
    char create_file[] = {"createfile-"};
    char insert_file[] = {"insertstr-"};
    char cat[] = {"cat-"};
    char remove[] = {"removestr-"};
    char copy[] = {"copystr-"};
    char cut[] = {"cutstr-"};
    char paste[] = {"pastestr-"};
    char find[] = {"findstr-"};
    char replace [] = {"replacestr-"};
    char grep [] = {"grep-"};
    char undo [] = {"undo-"};
    char indent[] = {"auto-"};
    char compare [] = {"compare-"};
    char tree [] = {"tree-"};
    char command[50] = {0};
    temp = comand_char;
    while (command[temp] != '-') {
        temp = comand_char;
        scanf("%c", &command[comand_char]);
        comand_char++;
    }
    char decide[temp];
    command[comand_char] = '\0';
    strcpy(decide, command);
    if (strcmp(decide, create_file) == 0) {
        make_file();
    } else if (strcmp(decide, insert_file) == 0) {
        insert_in_file();
    } else if (strcmp(decide, cat) == 0) {
        cat_file();
    } else if (strcmp(decide, remove) == 0) {
        remove_file();
    }else if (strcmp(decide, copy) == 0) {
        copy_file();
    }else if (strcmp(decide, cut) == 0) {
        cut_file();
    }else if (strcmp(decide, paste) == 0) {
        paste_file();
    }else if (strcmp(decide, find) == 0) {
        find_file();
    }else if (strcmp(decide, replace) == 0) {
        replace_file();
    }else if (strcmp(decide, grep) == 0) {
        grep_file();
    }else if (strcmp(decide, undo) == 0) {
        undo_file();
    }else if (strcmp(decide, indent) == 0) {
        auto_indent();
    }else if (strcmp(decide, compare) == 0) {
        compare_file();
    }else if (strcmp(decide, tree) == 0) {
        tree_file();
    }



}
//}

void make_file()
{   char create[300] ={0};
    scanf("%[^\n]s",create);
    //create[6]; --> start
    int i = 5;
    int find_ = 0;
    char string_address [300] = {0};
    char string_create_file [300] = {0};
    while(create[i] != '\0')
    {   if(create[i] == '\\')
            find_ = i;
        i++;
    }
    i --;
    find_ --;
    if(create[5] != '"') {
        for (int j = 5; j <= find_; j++) {
            string_address[j - 5] = create[j];
        }
        for (int k = 5; k <= i; k++) {
            string_create_file[k - 5] = create[k];
        }
        FILE *fp;
        mkdir(string_address);
        if (access(string_create_file, F_OK) != -1)
            printf("your file exists\n");
        else {
            fp = fopen(string_create_file, "w");
            printf("done\n");
            fclose(fp);
        }
    }
    else
    {
        for (int j = 6; j <= find_; j++) {
            string_address[j - 6] = create[j];
        }
        for (int k = 6; k < i; k++) {
            string_create_file[k - 6] = create[k];
        }
        FILE *fp;
        mkdir(string_address);
        if (access(string_create_file, F_OK) != -1)
            printf("file exists\n");
        else {
            fp = fopen(string_create_file, "w");
            printf("done\n");
            fclose(fp);
        }
    }
}
void insert_in_file()
{

    char insert [300] = {0};
    char insert_file[300] = {0};
    char content[300] = {0};
    int line = 0;
    int col = 0;
    scanf("%[^\n]s",insert);
    int i = 5;
    int find_ = 0;
    while(insert[i] != '-')//address of file
    {
        i++;
    }
    for(int q = 5 ; q < i ; q++ )
    {
        insert_file[q-5] = insert[q];
    }
    i = i + 5 ;
    int w = 0;
    for(i ; insert[i]!= '-' ; i++)
        w++;
    i = i - w  ;
    if(insert[i] != '"') {
        for (int q = 0; q < w - 1; q++, i++)
            content[q] = insert[i + 1];
        i = i + 6;
    }
    else
    {
        for (int q = 0; q < w - 2; q++, i++)
            content[q] = insert[i + 1];
        i = i + 7;
    }
    int c1=0,c2=0;
    int check = i;
    int power = 0;
    while(isdigit(insert[check])!=0) {
        line +=insert[check]-48;
        check++;
        if(isdigit(insert[check])!=0)
            line*=10;
    }
    i = check +1;
    while(isdigit(insert[i])!=0) {
        col +=insert[i]-48;
        i++;
        if(isdigit(insert[i])!=0)
            col*=10;
    }
//    line = insert[i] - 48;
//    col = insert[i+2] -48;
    line-=1;
    FILE *fp;
    if (access(insert_file, F_OK) != -1)
    {   printf("processing\n");
        char data[300][1000];
        FILE  * file;
        file = fopen(insert_file , "r");
        int line_=0;
        while(!feof(file) && !ferror(file))
        {
            if(fgets(data[line_] , 1000 , file) != NULL)
                line_ ++;
        }
        fclose(file);
        char undo_address[] = {"C:\\Users\\F1\\Desktop\\undo\\undo.txt"};
        FILE  * undo;
        undo = fopen(undo_address , "w");
        for(int e = 0 ; e < line_  ; e++)
            fprintf(undo,"%s", data[e]);
        fclose(undo);
        char *test = content;
        char part1[300];
        char part2[300];
        int lenght = strlen(data[line]);
        int condition_col = strlen(content);
        int emtiazi=0;
        int poof;
        for(int g = 0 ; content[g] != '\0' ; g++) {
            if (content[g] == '\\') {
                emtiazi++;
                poof = g;
            }
        }
        if(emtiazi==1)
        {
            for(int j = poof ; content[j] != '\0' ; j++ )
                content[j] = content[j+1];
            content[poof] = '\n';
        }
        else
        {
            for(int j = poof ; content[j] != '\0' ; j++ )
                content[j] = content[j+1];
        }
        if(col>lenght)
        {
            if(line >line_)
            {
                for(int x = line_ ; x < line + 3 ; x++) {
                    data[x][0] = '\n';
                    line_++;
                }
                line++;

            }
            for(int t = lenght-1; t < (col-lenght)+condition_col+1 ; t++)
                data[line][t] = ' ';
            data[line][(col-lenght)+condition_col+1] = '\n';
            for(int y = 0; y < col ; y++)
            {
                part1[y] = data[line][y];
            }
            for(int y = col; y < (col-lenght)+condition_col+2 ; y++)
            {
                part2[y-col] = data[line][y];
            }
            strcat(part1,test);
            strcat(part1,part2);
            strcpy(data[line],part1);
            FILE  * newfile;
            newfile = fopen(insert_file , "w");
            for(int e = 0 ; e < line_  ; e++)
                fprintf(newfile,"%s", data[e]);

            printf("done\n");
        }
        else{
            for(int y = 0; y < col ; y++)
            {
                part1[y] = data[line][y];
            }
            for(int y = col; y < lenght ; y++)
            {
                part2[y-col] = data[line][y];
            }
            strcat(part1,test);
            strcat(part1,part2);
            strcpy(data[line],part1);
            FILE  * newfile;
            newfile = fopen(insert_file , "w");

            for(int e = 0 ; e < line_  ; e++) {
                fprintf(newfile,"%s", data[e]);
            }
            printf("done\n");
        }

    }
    else
    {
        printf("file doesnt exists\n");
    }
}
void cat_file()
{   char ch;
    char input[300];
    char file_address[300];
    scanf("%[^\n]s",input);
    int i = 5;
    for(i ; input[i] != '\0' ; i++)
        file_address[i-5] = input[i];
    FILE * fp;
    fp = fopen(file_address , "r");
    do {
        ch = fgetc(fp);
        printf("%c", ch);

        // Checking if character is not EOF.
        // If it is EOF stop reading.
    } while (ch != EOF);
    fclose(fp);
    printf("\n");
}
void remove_file()
{
    char input[300];
    char file_address[300];
    int line = 0;
    int col = 0;
    char direction;
    int remove_count = 0;
    scanf("%[^\n]s",input);
    int i = 5;
    while(input[i] != '-')//address of file
    {
        i++;
    }
    for(int q = 5 ; q < i ; q++ )
    {
        file_address[q-5] = input[q];
    }
    i = i + 5;
    int check = i;
    while(isdigit(input[check])!=0) {
        line +=input[check]-48;
        check++;
        if(isdigit(input[check])!=0)
            line*=10;
    }
    i = check +1;
    while(isdigit(input[i])!=0) {
        col +=input[i]-48;
        i++;
        if(isdigit(input[i])!=0)
            col*=10;
    }
    //line = input[i]-48;
    line--;
    //col = input[i+2]-48;
    i = i +6;
    while(isdigit(input[i])!=0) {
        remove_count +=input[i]-48;
        i++;
        if(isdigit(input[i])!=0)
            remove_count*=10;
    }
    // remove_count = input[i+9]-48;
    direction = input[i + 1];
    char data[300][1000];
    FILE  * file;
    file = fopen(file_address , "r");
    int line_file = 0;
    while(!feof(file) && !ferror(file))
    {
        if(fgets(data[line_file] , 1000 , file) != NULL)
            line_file ++;
    }
    fclose(file);
    char undo_address[] = {"C:\\Users\\F1\\Desktop\\undo\\undo.txt"};
    FILE  * undo;
    undo = fopen(undo_address , "w");
    for(int e = 0 ; e < line_file  ; e++)
        fprintf(undo,"%s", data[e]);
    fclose(undo);
    int length = strlen(data[line]);

    if(direction =='f')
    {
        if ((length -(col+1)) >= remove_count)
        {
            for (int c = col; c < length+1; c++)
                data[line][c] = data[line][c +remove_count];
        }
        else
        {
            for (int c = col; c < length+1; c++)
                data[line][c] = data[line][c +(length - col)];
            remove_count = remove_count - (length-col);
            while(remove_count != 0)
            {   line ++;
                int length2 = strlen(data[line]);
                if (length2 > remove_count)
                {
                    for (int c = 0; c < length2; c++)
                        data[line][c] = data[line][c +remove_count];
                    remove_count = 0;
                }
                else
                {
                    for (int c = 0; c < length2; c++)
                        data[line][c] = data[line][c +length2];
                    remove_count = remove_count - length2;
                }
            }

        }
    }
    else
    {
        if ((col) >= remove_count)
        {
            for (int c = col-remove_count; c < length+1; c++)
                data[line][c] = data[line][c +remove_count];
        }
        else
        {
            for (int c = 0; c < length+1; c++)
                data[line][c] = data[line][c +col];
            remove_count = remove_count - col;
            while(remove_count != 0)
            {   line --;
                int length2 = strlen(data[line]);
                if (length2 > remove_count)
                {
                    for (int c = length2-remove_count; c < length2; c++)
                        data[line][c] = data[line][c +remove_count];
                    remove_count = 0;
                }
                else
                {
                    for (int c = 0; c < length2+1; c++)
                        data[line][c] = data[line][c + remove_count+1];
                    remove_count = remove_count - length2;
                }
            }

        }
    }
    FILE  * newfile;
    newfile = fopen(file_address , "w");
    for(int e = 0 ; e < line_file  ; e++)
        fprintf(newfile,"%s", data[e]);

    printf("done\n");
}
void copy_file()
{
    char input[300];
    char file_address[300];
    int line = 0;
    int col = 0;
    char direction;
    int remove_count = 0;
    scanf("%[^\n]s",input);
    int i = 5;
    while(input[i] != '-')//address of file
    {
        i++;
    }
    for(int q = 5 ; q < i ; q++ )
    {
        file_address[q-5] = input[q];
    }
    i = i + 5;
    int check = i;
    while(isdigit(input[check])!=0) {
        line +=input[check]-48;
        check++;
        if(isdigit(input[check])!=0)
            line*=10;
    }
    i = check +1;
    while(isdigit(input[i])!=0) {
        col +=input[i]-48;
        i++;
        if(isdigit(input[i])!=0)
            col*=10;
    }
    //line = input[i]-48;
    line--;
    //col = input[i+2]-48;
    i = i +6;
    while(isdigit(input[i])!=0) {
        remove_count +=input[i]-48;
        i++;
        if(isdigit(input[i])!=0)
            remove_count*=10;
    }
    // remove_count = input[i+9]-48;
    direction = input[i + 1];
    char data[300][1000];
    FILE  * file;
    file = fopen(file_address , "r");
    int line_file = 0;
    while(!feof(file) && !ferror(file))
    {
        if(fgets(data[line_file] , 1000 , file) != NULL)
            line_file ++;
    }
    fclose(file);
    int length = strlen(data[line]);
//---------------------------------------------------------------------
    char to_be_copyed[300];
    if(direction =='f')
    {
        if ((length -(col+1)) >= remove_count)
        {
            for (int c = col; c < remove_count; c++)
                to_be_copyed[c-col] = data[line][c];
        }
        else
        {
            for (int c = col; c < length; c++)
                to_be_copyed[c-col] = data[line][c];
            remove_count = remove_count - (length-col);
            int resume = (length-col);
            while(remove_count != 0)
            {   line ++;
                int length2 = strlen(data[line]);
                if (length2 > remove_count)
                {
                    for (int c = 0; c < remove_count; c++)
                        to_be_copyed[resume+c] = data[line][c];
                    remove_count = 0;
                }
                else
                {
                    for (int c = 0; c < length2; c++)
                        to_be_copyed[resume+c] = data[line][c];
                    remove_count = remove_count - length2;
                    resume += length2;
                }
            }

        }
    }
    else
    {
        if ((col) >= remove_count)
        {
            for (int c = col-remove_count; c < remove_count; c++)
                to_be_copyed[c] = data[line][c];
        }
        else
        {
            for (int c = 0; c < col; c++)
                to_be_copyed[c] = data[line][c];
            int resume = col;
            remove_count = remove_count - col;
            while(remove_count != 0)
            {   line --;
                int length2 = strlen(data[line]);
                if (length2 > remove_count)
                {
                    for (int c = length2-1; c > length2-remove_count-1; c--)
                        to_be_copyed[resume+length2-c-1] = data[line][c];
                    remove_count = 0;
                }
                else
                {
                    for (int c = length2-1; c >= 0 ; c--)
                        to_be_copyed[resume+length2-c-1] = data[line][c];
                    remove_count = remove_count - length2;
                    resume += length2;
                }
            }

        }
    }
    const char* output = to_be_copyed;
    const size_t len = strlen(output) + 1;
    HGLOBAL hMem =  GlobalAlloc(GMEM_MOVEABLE, len);
    memcpy(GlobalLock(hMem), output, len);
    GlobalUnlock(hMem);
    OpenClipboard(0);
    EmptyClipboard();
    SetClipboardData(CF_TEXT, hMem);
    CloseClipboard();

    printf("done\n");
}
void cut_file()
{
    char input[300];
    char file_address[300];
    int line = 0;
    int col = 0;
    char direction;
    int remove_count = 0;
    scanf("%[^\n]s",input);
    int i = 5;
    while(input[i] != '-')//address of file
    {
        i++;
    }
    for(int q = 5 ; q < i ; q++ )
    {
        file_address[q-5] = input[q];
    }
    i = i + 5;
    int check = i;
    while(isdigit(input[check])!=0) {
        line +=input[check]-48;
        check++;
        if(isdigit(input[check])!=0)
            line*=10;
    }
    i = check +1;
    while(isdigit(input[i])!=0) {
        col +=input[i]-48;
        i++;
        if(isdigit(input[i])!=0)
            col*=10;
    }
    //line = input[i]-48;
    line--;
    //col = input[i+2]-48;
    i = i +6;
    while(isdigit(input[i])!=0) {
        remove_count +=input[i]-48;
        i++;
        if(isdigit(input[i])!=0)
            remove_count*=10;
    }
    // remove_count = input[i+9]-48;
    direction = input[i + 1];
    char data[300][1000];
    FILE  * file;
    file = fopen(file_address , "r");
    int line_file = 0;
    while(!feof(file) && !ferror(file))
    {
        if(fgets(data[line_file] , 1000 , file) != NULL)
            line_file ++;
    }
    fclose(file);
    char undo_address[] = {"C:\\Users\\F1\\Desktop\\undo\\undo.txt"};
    FILE  * undo;
    undo = fopen(undo_address , "w");
    for(int e = 0 ; e < line_file  ; e++)
        fprintf(undo,"%s", data[e]);
    fclose(undo);
    int length = strlen(data[line]);
//-------------------------------------------------------------------
    char to_be_copyed[300];
    if(direction =='f')
    {
        if ((length -(col+1)) >= remove_count) {
            for (int c = col; c < length ; c++) {
                if(c<remove_count)
                    to_be_copyed[c-col] = data[line][c];
                data[line][c] = data[line][c + remove_count];
            }
        }
        else
        {
            for (int c = col; c < length; c++) {
                to_be_copyed[c-col] = data[line][c];
                data[line][c] = data[line][c + (length - col)];
            }
            remove_count = remove_count - (length-col);
            int resume = (length-col);
            while(remove_count != 0)
            {   line ++;
                int length2 = strlen(data[line]);
                if (length2 > remove_count)
                {
                    for (int c = 0; c < length2; c++){
                        if(c<remove_count)
                            to_be_copyed[resume+c] = data[line][c];
                        data[line][c] = data[line][c +remove_count];
                    }
                    remove_count = 0;
                }
                else
                {
                    for (int c = 0; c < length2; c++) {
                        to_be_copyed[resume+c] = data[line][c];
                        data[line][c] = data[line][c + length2];
                    }
                    remove_count = remove_count - length2;
                    resume += length2;
                }
            }

        }
    }
    else
    {
        if ((col) >= remove_count) {
            for (int c = col - remove_count; c < length + 1; c++) {
                if(c < remove_count)
                    to_be_copyed[c] = data[line][c];
                data[line][c] = data[line][c + remove_count];
            }
        }
        else
        {
            for (int c = 0; c < length+1; c++) {
                if(c<col)
                    to_be_copyed[c] = data[line][c];
                data[line][c] = data[line][c + col];
            }
            int resume = col;
            remove_count = remove_count - col;
            while(remove_count != 0)
            {   line --;
                int length2 = strlen(data[line]);
                if (length2 > remove_count)
                {
                    for (int c = length2-1; c > length2-remove_count-1; c--)
                        to_be_copyed[resume+length2-c-1] = data[line][c];
                    for (int c = length2-remove_count; c < length2; c++) {
                        data[line][c] = data[line][c + remove_count];
                    }
                    remove_count = 0;
                }
                else
                {
                    for (int c = length2-1; c >= 0 ; c--)
                        to_be_copyed[resume+length2-c-1] = data[line][c];
                    for (int c = 0; c < length2+1; c++)
                        data[line][c] = data[line][c + remove_count+1];
                    remove_count = remove_count - length2;
                    resume += length2;
                }
            }

        }
    }
    FILE  * newfile;
    newfile = fopen(file_address , "w");
    for(int e = 0 ; e < line_file  ; e++)
        fprintf(newfile,"%s", data[e]);
    const char* output = to_be_copyed;
    const size_t len = strlen(output) + 1;
    HGLOBAL hMem =  GlobalAlloc(GMEM_MOVEABLE, len);
    memcpy(GlobalLock(hMem), output, len);
    GlobalUnlock(hMem);
    OpenClipboard(0);
    EmptyClipboard();
    SetClipboardData(CF_TEXT, hMem);
    CloseClipboard();
    printf("done\n");
}
void paste_file()
{
    char insert [300] = {0};
    char insert_file[300] = {0};
//    char content[300] = {0};
    int line = 0;
    int col = 0;
    scanf("%[^\n]s",insert);
    int i = 5;
    int find_ = 0;
    while(insert[i] != '-')//address of file
    {
        i++;
    }
    for(int q = 5 ; q < i ; q++ )
    {
        insert_file[q-5] = insert[q];
    }
    i = i + 5 ;
    int c1=0,c2=0;
    int check = i;
    int power = 0;
    while(isdigit(insert[check])!=0) {
        line +=insert[check]-48;
        check++;
        if(isdigit(insert[check])!=0)
            line*=10;
    }
    i = check +1;
    while(isdigit(insert[i])!=0) {
        col +=insert[i]-48;
        i++;
        if(isdigit(insert[i])!=0)
            col*=10;
    }
//    line = insert[i] - 48;
//    col = insert[i+2] -48;
    line-=1;
    FILE *fp;
    char content[300];
    HANDLE h;
    OpenClipboard(NULL);
    h = GetClipboardData(CF_TEXT);
    char *paste = (char *)h;
    for(int b = 0 ; *(paste+b)!='\0';b++)
        content[b] = *(paste+b);
    CloseClipboard();
    if (access(insert_file, F_OK) != -1)
    {   printf("processing\n");
        char data[300][1000];
        FILE  * file;
        file = fopen(insert_file , "r");
        int line_=0;
        while(!feof(file) && !ferror(file))
        {
            if(fgets(data[line_] , 1000 , file) != NULL)
                line_ ++;
        }
        fclose(file);
        char undo_address[] = {"C:\\Users\\F1\\Desktop\\undo\\undo.txt"};
        FILE  * undo;
        undo = fopen(undo_address , "w");
        for(int e = 0 ; e < line_  ; e++)
            fprintf(undo,"%s", data[e]);
        fclose(undo);
        char *test = content;
        char part1[300];
        char part2[300];
        int lenght = strlen(data[line]);
        int condition_col = strlen(content);

        if(col>lenght)
        {
            if(line >line_)
            {
                for(int x = line_ ; x < line + 3 ; x++) {
                    data[x][0] = '\n';
                    line_++;
                }
                line++;

            }
            for(int t = lenght-1; t < (col-lenght)+condition_col+1 ; t++)
                data[line][t] = ' ';
            data[line][(col-lenght)+condition_col+1] = '\n';
            for(int y = 0; y < col ; y++)
            {
                part1[y] = data[line][y];
            }
            for(int y = col; y < (col-lenght)+condition_col+2 ; y++)
            {
                part2[y-col] = data[line][y];
            }
            strcat(part1,test);
            strcat(part1,part2);
            strcpy(data[line],part1);
            FILE  * newfile;
            newfile = fopen(insert_file , "w");
            for(int e = 0 ; e < line_  ; e++)
                fprintf(newfile,"%s", data[e]);

            printf("done\n");
        }
        else{
            for(int y = 0; y < col ; y++)
            {
                part1[y] = data[line][y];
            }
            for(int y = col; y < lenght ; y++)
            {
                part2[y-col] = data[line][y];
            }
            strcat(part1,test);
            strcat(part1,part2);
            strcpy(data[line],part1);
            FILE  * newfile;
            newfile = fopen(insert_file , "w");
            for(int e = 0 ; e < line_  ; e++)
                fprintf(newfile,"%s", data[e]);

            printf("done\n");
        }

    }
    else
    {
        printf("file doesnt exist\n");
    }
}
void find_file()
{
    int temper=0;
    char input[500]={0};
    char to_search[500]={0};
    char file_address[500] = {0};
    gets(input);
    int input_size = strlen(input);
    if(input[4] == '"')
    {
        int i ;
        for( i = 5 ; input[i] != '-'&&input[i]!='"' ; i++)
        {
            to_search[i-5] = input[i];
        }
        i += 7;
        int q;
        int buffer = 0;
        for( q = i ; (input[q-1]!='-'&&input[q-1]!='\0');q++)
            file_address[q-i] = input[q];
        file_address[q-i-1] = '\0';
        i = q+1;
    }
    else
    {   int i ;
        for( i = 5 ; input[i] != '-' ; i++)
        {
            to_search[i-5] = input[i];
        }
        i += 6;
        int q;
        int buffer = 0;
        for( q = i ; (input[q]!='-'&&input[q]!='\0');q++)
            file_address[q-i] = input[q];
        file_address[q-i] = '\0';
        i = q+1;
    }
    int at_amount;
    int condition[4]={0};
    if(strstr(input,"-count"))
        condition[0]=1;
    if(strstr(input,"-all"))
    {
        condition[3] = 1;
    }
    if(strstr(input,"-byword"))
    {
        condition[2] = 1;
    }
    if(strstr(input,"-at"))
    {
        condition[1] = 1;
        char * p = strstr(input,"-at");
        at_amount = atoi(p + 3);
    }
    char s1[1000];
    char temp[100];
    FILE * read = fopen(file_address , "r");
    while(1)
    {
        if(fgets(temp , 100 ,read)==NULL)
        {
            break;
        }
        else
        {
            strcat(s1,temp);
        }
    }


    char s2[200]={0} ;
    strcpy(s2,to_search);
    char* p;
    int count_word=0;
    int space_count=0;
    char result[100]={0};
    char before[1000]={0};
    int second = 0;
    int at_count = 0;
    int all_count1[500] = {0};
    int all_count2[500] = {0};
    int buffer = 0;
    p = strstr(s1, s2);
    if(p != NULL) {
        for (int q = 0; *(p + q) != '\0'; q++)
            second++;
        if (condition[1] == 0) {
            char *temp;
            temp = strstr(s1, s2);
            while (temp) {
                space_count = 0;
                at_count = 0;
                for (int q = 0; *(temp + q) != '\0'; q++)
                    at_count++;
                for (int t = 0; t < strlen(s1) - at_count; t++) {
                    before[t] = s1[t];
                }
                for (int u = 0; before[u] != '\0'; u++) {
                    if (before[u] != ' ' && before[u] != '\n')
                        temper = 0;
                    if ((before[u] == ' ' || before[u] == '\n') && (temper == 0)) {
                        space_count++;
                        temper = 1;
                    }
                }
                all_count1[buffer] = ++space_count;
                all_count2[buffer] = strlen(s1) - at_count;
                buffer++;
                count_word++;
                temp = strstr(temp + 1, s2);
            }
            space_count = 0;
            for (int t = 0; t < (strlen(s1) - second); t++) {
                before[t] = s1[t];
            }
            for (int u = 0; before[u] != '\0'; u++) {
                if (before[u] != ' ' && before[u] != '\n')
                    temper = 0;
                if ((before[u] == ' ' || before[u] == '\n') && (temper == 0)) {
                    space_count++;
                    temper = 1;
                }
            }

            if (condition[0] == 1)
                printf("%d", count_word);
            else if ((condition[2] == 1) && (condition[3] == 0)) {
                printf("%d", +all_count1[0]);
            } else if ((condition[2] == 0) && (condition[3] == 1)) {
                for (int p = 0; p < buffer; p++)
                    printf("%d ", all_count2[p]);
            } else if ((condition[2] == 1) && (condition[3] == 1)) {
                for (int c = 0; c < buffer; c++)
                    printf("%d ", all_count1[c]);
            } else {
                printf("%d", strlen(s1) - second);
            }

        }
            //------------------------------------------------------------------------------


        else {
            char *temp;
            temp = strstr(s1, s2);
            while (temp) {
                space_count = 0;
                at_count = 0;
                for (int q = 0; *(temp + q) != '\0'; q++)
                    at_count++;
                for (int t = 0; t < strlen(s1) - at_count; t++) {
                    before[t] = s1[t];
                }
                for (int u = 0; before[u] != '\0'; u++) {
                    if (before[u] != ' ' && before[u] != '\n')
                        temper = 0;
                    if ((before[u] == ' ' || before[u] == '\n') && (temper == 0)) {
                        space_count++;
                        temper = 1;
                    }
                }
                all_count1[buffer] = ++space_count;
                all_count2[buffer] = strlen(s1) - at_count;
                buffer++;
                count_word++;
                temp = strstr(temp + 1, s2);
                if (count_word == at_amount) {
                    break;
                }

            }
            space_count = 0;
            for (int t = 0; t < (strlen(s1) - at_count); t++) {
                before[t] = s1[t];
            }
            for (int u = 0; before[u] != '\0'; u++) {
                if (before[u] != ' ' && before[u] != '\n')
                    temper = 0;
                if ((before[u] == ' ' || before[u] == '\n') && (temper == 0)) {
                    space_count++;
                    temper = 1;
                }
            }

            if (condition[0] == 1)
                printf("%d", count_word);
            else if ((condition[2] == 1) && (condition[1] == 0)) {
                printf("%d", all_count1[0]);
            } else if ((condition[2] == 0) && (condition[1] == 1)) {
                printf("%d ", all_count2[at_amount - 1]);
            } else if ((condition[2] == 1) && (condition[1] == 1)) {
                printf("%d ", all_count1[at_amount - 1]);

            } else {
                printf("%d", strlen(s1) - second);
            }

        }
    }
    else
    {
        printf("-1");
    }
}
void replace_file()
{
    char input[500]={0};
    char to_search[500]={0};
    char to_replace[500] = {0};
    char file_address[500] = {0};
    gets(input);
    int input_size = strlen(input);
    if(input[5] == '"')
    {
        int i ;
        for( i = 6 ; input[i] != '-'&&input[i]!='"' ; i++)
        {
            to_search[i-6] = input[i];
        }
        i += 8;
        int u;
        for( u = i  ; input[u] != '-'&&input[u]!='"' ; u++)
        {
            to_replace[u-i] = input[u];
        }
        i = u;
        i += 7;
        int q;
        int buffer = 0;
        for( q = i ; (input[q-1]!='-'&&input[q-1]!='\0');q++)
            file_address[q-i] = input[q];
        file_address[q-i-1] = '\0';
        i = q+1;
    }
    else
    {   int i ;
        for( i = 6 ; input[i] != '-'&&input[i]!='"' ; i++)
        {
            to_search[i-6] = input[i];
        }
        i += 7;
        for( int u = i  ; input[u] != '-'&&input[u]!='"' ; u++,i++)
        {
            to_replace[u-i] = input[u];
        }
        i += 6;
        int q;
        int buffer = 0;
        for( q = i ; (input[q-1]!='-'&&input[q-1]!='\0');q++)
            file_address[q-i] = input[q];
        file_address[q-i-1] = '\0';
        i = q+1;
    }
    int at_amount = 1;
    char condition[2]={0};
    if(strstr(input,"-at"))
    {
        condition[0] = 1;
        char * p = strstr(input,"-at");
        at_amount = atoi(p + 3);
    }
    if(strstr(input,"all"))
    {
        condition[1] = 1;
    }
    char s1[1000];
    char temp_[100];
    FILE * read = fopen(file_address , "r");
    if (access(file_address, F_OK) == -1) {
        printf("file doesnt exist\n");

    }
    else
    {
        while(1)
        {
            if(fgets(temp_ , 100 ,read)==NULL)
            {
                break;
            }
            else
            {
                strcat(s1,temp_);
            }
        }
        char undo_address[] = {"C:\\Users\\F1\\Desktop\\undo\\undo.txt"};
        FILE  * undo;
        undo = fopen(undo_address , "w");
        fprintf(undo,"%s", s1);
        fclose(undo);
        //-------------------------------------------
        char s2[200]={0} ;
        char s3[200]={0} ;
        strcpy(s2,to_search);
        strcpy(s3,to_replace);
        char* p;
        char after[500]={0};
        int count_word=1;
        int space_count=0;
        char result[100]={0};
        char before[1000]={0};
        int second = 0;
        int at_count = 0;
        int all_count[500] = {0};
        int buffer = 0;
        char check[500]={0};
        p = strstr(s1, s2);
        char *temp;
        temp = strstr(s1, s2);
        if(p) {
            for (int q = 0; *(p + q) != '\0'; q++)
                second++;
            if((condition[0]==1)&&(condition[1]==1))
                printf("wrong input\n");
            else {
                if (condition[1] == 1) {
                    while (temp) {

                        int fixer = 0;
                        space_count = 0;
                        at_count = 0;
                        for (int q = 0; *(temp + q) != '\0'; q++)
                            at_count++;
                        for (int t = 0; t < strlen(s1) - at_count; t++) {
                            before[t] = s1[t];
                        }
                        buffer++;


                        for (int i = strlen(s2); i < strlen(s1); i++) {
                            after[i - strlen(s2)] = *(temp + i);
                        }
                        strcpy(check, before);
                        strcat(check, s3);
                        strcat(check, after);
                        strcpy(s1, check);
                        if ((count_word == at_amount) && (condition[1] == 0)) {
                            break;
                        }
                        count_word++;
                        temp = strstr(temp + 1, s2);

                    }
                }
                else
                {
                    while (temp) {

                        int fixer = 0;
                        space_count = 0;
                        at_count = 0;
                        for (int q = 0; *(temp + q) != '\0'; q++)
                            at_count++;
                        for (int t = 0; t < strlen(s1) - at_count; t++) {
                            before[t] = s1[t];
                        }
                        buffer++;


                        for (int i = strlen(s2); i < strlen(s1); i++) {
                            after[i - strlen(s2)] = *(temp + i);
                        }

                        if ((count_word == at_amount) && (condition[1] == 0)) {
                            strcpy(check, before);
                            strcat(check, s3);
                            strcat(check, after);
                            strcpy(s1, check);
                            break;
                        }
                        count_word++;
                        temp = strstr(temp + 1, s2);

                    }

                }
                fclose(read);
                FILE * fp = fopen(file_address , "w");
                fprintf(fp,"%s",s1);
                fclose(fp);
                printf("done");

            }


        }
        else
        {
            printf("the content you are searching for is not available in the text\n");
        }
    }
}
void grep_file()
{
    char input[500];
    gets(input);
    char to_search[500]={0};
    char file_address[20][500]={0};
    int condition[2]={0};
    int i = 0;
    int help = 0;
    if(input[0]=='-')
    {
        if(input[4] != ' ')
        {
            i = 5;
            int u;
            for( u = i ; input[u] != '"' ; u++)
                to_search[u-i] = input[u];
            i = u;
            i += 7;
            while(input[i] != '\0') {
                for (u = i; input[u] != ' ' && input[u] != '\0'; u++)
                    file_address[help][u - i] = input[u];
                i = u + 1;
                help++;
            }
        }
        else
        {
            i = 5;
            int u;
            for( u = i ; input[u] != '-' ; u++)
                to_search[u-i] = input[u];
            i = u;
            i += 6;
            while(input[i] != '\0') {
                for (u = i; input[u] != ' ' && input[u] != '\0'; u++)
                    file_address[help][u - i] = input[u];
                i = u + 1;
                help++;
            }

        }

    }
    else
    {
        char *j = {"I"};
        char *c = {"C"};
        if(input[0] == *j)
            condition[0] = 1;
        else if(input[0] == *c)
            condition[1] = 1;
        i = 7;
        int u ;
        for(u = i ; input[u] != '-' ; u++)
            to_search[u-i] = input [u];
        i = u ;
        i += 6 ;
        while(input[i] != '\0') {
            for (u = i; input[u] != ' ' && input[u] != '\0'; u++)
                file_address[help][u - i] = input[u];
            i = u + 1;
            help++;
        }

    }
    if(condition[0]==0 && condition[1]==0)
    {
        for(int k = 0 ; k < help ; k++) {
            char data[300][1000]={0};
            FILE *file;
            file = fopen(file_address[k], "r");
            int line_ = 0;
            while (!feof(file) && !ferror(file)) {
                if (fgets(data[line_], 1000, file) != NULL)
                    line_++;
            }
            fclose(file);
            for(int b= 0 ; b < line_ ; b++){
                if(strstr(data[b],to_search))
                    printf("%s",data[b]);
            }
        }

    }
    else if(condition[0]==1 && condition[1]==0)
    {
        int line_amount = 0 ;
        for(int k = 0 ; k < help ; k++) {
            char data[300][1000]={0};
            FILE *file;
            file = fopen(file_address[k], "r");
            int line_ = 0;
            while (!feof(file) && !ferror(file)) {
                if (fgets(data[line_], 1000, file) != NULL)
                    line_++;
            }
            fclose(file);
            for(int b= 0 ; b < line_ ; b++){
                if(strstr(data[b],to_search))
                {
                    int checker = 0;
                    for(int y = 0 ; file_address[k][y] != '\0' ; y++)
                    {
                        if(file_address[k][y]=='\\')
                            checker = y;
                    }
                    char name[100]={0};
                    for(int d = checker+1 ; file_address[k][d] != '\0' ; d++ )
                        name[d-checker-1] = file_address[k][d];
                    printf("%s\n",name);
                    break;
                }
            }
        }
    }
    else if(condition[0]==0 && condition[1]==1)
    {
        int line_amount = 0 ;
        for(int k = 0 ; k < help ; k++) {
            char data[300][1000]={0};
            FILE *file;
            file = fopen(file_address[k], "r");
            int line_ = 0;
            while (!feof(file) && !ferror(file)) {
                if (fgets(data[line_], 1000, file) != NULL)
                    line_++;
            }
            fclose(file);
            for(int b= 0 ; b < line_ ; b++){
                if(strstr(data[b],to_search))
                    line_amount++;
            }
        }
        printf("%d",line_amount);
    }












}
void undo_file()
{
    char undo_address[] = {"C:\\Users\\F1\\Desktop\\undo\\undo.txt"};
    char input [500];
    gets(input);
    char file_address[500] = {0};
    int i = 5;
    for(int u = i ; input[u] != '\0' ; u++)
        file_address[u-i] = input [u];
    char data[300][1000];
    FILE  * file;
    file = fopen(undo_address , "r");
    int line_=0;
    while(!feof(file) && !ferror(file))
    {
        if(fgets(data[line_] , 1000 , file) != NULL)
            line_ ++;
    }
    fclose(file);
    FILE  * overwrite;
    overwrite = fopen(file_address , "w");
    for(int e = 0 ; e < line_  ; e++)
        fprintf(overwrite,"%s", data[e]);
    printf("done");
}
void auto_indent()
{
    char input[500];
    gets(input);
    char file_address[500];
    int i = 12;
    int x = 0;
    for( x = i ; input[x] != '\0' ; x++ )
        file_address[x-i] = input[x];
    FILE  * file;
    FILE  * write;
    char test[300][1000];
    FILE  * choob;
    choob = fopen(file_address , "r");
    int linet=0;
    while(!feof(choob) && !ferror(choob))
    {
        if(fgets(test[linet] , 1000 , choob) != NULL)
            linet ++;
    }
    fclose(choob);
    char undo_address[] = {"C:\\Users\\F1\\Desktop\\undo\\undo.txt"};
    FILE  * undo;
    undo = fopen(undo_address , "w");
    for(int e = 0 ; e < linet  ; e++)
        fprintf(undo,"%s", test[e]);
    fclose(undo);
    char data[300][1000];
    file = fopen(file_address, "r");
    write = fopen("C:\\Users\\F1\\Desktop\\root\\auto-indent\\indent.txt", "w");
    while(!feof(file) && !ferror(file))
    {
        int feshar = 0;
        int tab = 0;
        int temp = 0;
        int checker = 0;
        char check[1000] = {0};
        fgets(check , 1000 , file);
        for(int h = 0 ; check[h] != '\0' ; h++) {
            if(check[h]=='\n')
                continue;
            if (check[h] == '{') {
//                if(check[h+1] == '}')
//                    tab--;

                tab++;
                if(check[h-1] != ' ')
                    fprintf(write, "%c", ' ');
                fprintf(write, "%c", check[h]);
                fprintf(write, "%c", '\n');
                temp = 1;
                for (int g = 0; g < tab; g++)
                    fprintf(write, "%c", '\t');

            }
            else if (check[h] == '}') {
                tab--;
                fprintf(write, "%c", '\n');
                for (int g = 0; g < tab; g++) {
                    fprintf(write, "%c", '\t');

                }
                fprintf(write, "%c", check[h]);
                if(check[h+1]=='{')
                    fprintf(write, "%c", '\n');


                temp = 0;
            }
            else if ((check[h] != ' ')) {
                feshar = 0;
                if(check[h]=='(')
                {
                    fprintf(write, "%c", check[h]);
                }
                else if(check[h]==')')
                {
                    fprintf(write, "%c", check[h]);
                    if(check[h+1] != ';' && check[h+1] != ' ')
                    fprintf(write, "%c", ' ');
                }
                else
                {
                    fprintf(write, "%c", check[h]);
                    checker = 0;
                }

            }
            else
            {

                if(feshar == 0)
                {fprintf(write, "%c", check[h]);}
                feshar++;
            }
        }
    }
    fclose(file);
    fclose(write);
    char sag[300][1000];
    FILE  * feshar;
    feshar = fopen("C:\\Users\\F1\\Desktop\\root\\auto-indent\\indent.txt" , "r");
    int line_=0;
    while(!feof(feshar) && !ferror(feshar))
    {
        if(fgets(sag[line_] , 1000 , feshar) != NULL)
            line_ ++;
    }
    fclose(feshar);
    FILE * dard;
    dard = fopen(file_address, "w");
    for(int e = 0 ; e < line_  ; e++) {
        fprintf(dard,"%s", sag[e]);
    }
    printf("done");
}
void compare_file()
{
    char input [500] = {0};
    gets(input);
    char file_address1[500]={0};
    char file_address2[500]={0};
    int i = 5;
    int u;
    for(  u = i ; input[u] != ' ' ; u++)
    file_address1[u-i] = input [u];
    i = u + 1;
    for( u = i ; input[u] != '\0' ; u++)
        file_address2[u-i] = input [u];
    char data1[300][1000];
    FILE  * file1;
    file1 = fopen(file_address1 , "r");
    int line_1=0;
    while(!feof(file1) && !ferror(file1))
    {
        if(fgets(data1[line_1] , 1000 , file1) != NULL)
            line_1 ++;
    }
    fclose(file1);
    char data2[300][1000];
    FILE  * file2;
    file2 = fopen(file_address2 , "r");
    int line_2=0;
    while(!feof(file2) && !ferror(file2))
    {
        if(fgets(data2[line_2] , 1000 , file2) != NULL)
            line_2 ++;
    }
    fclose(file2);
    if(line_1>line_2)
    {
        for(int r = 0 ; r < line_2 ; r++ )
            if(strcmp(data1[r],data2[r]))
            {
                printf("======== #%d ========\n",r+1);
                printf("%s\n",data2[r]);
                printf("%s\n",data1[r]);
            }
        for(int e  = line_2 ; e < line_1 ; e++) {
            printf("<<<<<<<< #%d - #%d <<<<<<<<\n", e+1 ,e+1);
            printf("%s\n",data1[e]);

        }

    }
    else if (line_1 == line_2)
    {
        for(int r = 0 ; r < line_2 ; r++ )
            if(strcmp(data1[r],data2[r]))
            {
                printf("======== #%d ========\n",r+1);
                printf("%s\n",data2[r]);
                printf("%s\n",data1[r]);
            }
    }
    else
    {
        for(int r = 0 ; r < line_1 ; r++ )
            if(strcmp(data1[r],data2[r]))
            {
                printf("======== #%d ========\n",r+1);
                printf("%s\n",data2[r]);
                printf("%s\n",data1[r]);
            }
        for(int e  = line_1 ; e < line_2 ; e++) {
            printf(">>>>>>>> #%d - #%d >>>>>>>>\n", e+1 ,e+1);
            printf("%s\n",data2[e]);

        }
    }
}
int depth ;
void tree_file()
{
    scanf("%d",&depth);
    if(depth==-1)
    {
        depth = 1000;
        char path[100]={"C:\\Users\\F1\\Desktop\\root"};
        listFilesRecursively(path);
    }
    else if(depth>-1)
    {
        char path[100]={"C:\\Users\\F1\\Desktop\\root"};
        listFilesRecursively(path);
    }
    else
    {
        printf("wrong depth\n");
    }
}
void listFilesRecursively(char *basePath)
{
    char path[1000];
    struct dirent *dp;
    DIR *dir = opendir(basePath);
    if (!dir)
        return;

    while ((dp = readdir(dir)) != NULL)
    {
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0)
        {
            int w = 0;
            strcpy(path, basePath);
            strcat(path, "\\");
            strcat(path, dp->d_name);

            for(int q = 0 ; path[q] != '\0' ;q++)
            {
                if(path[q] == '\\') {
                    w++;
                }
            }
            for(int y = 0 ; y<w-5 ;y++) {
                printf("--");
            }
            printf("%s\n", dp->d_name);
            if(w-4<=depth)//3 -> 0   4 -> 1 ....   &
                listFilesRecursively(path);
        }
    }

    closedir(dir);
}
// CPP program to illustrate strstr()
#include <string.h>
#include <stdio.h>
//find and all its types
/*
#include <stdio.h>
#include <string.h>
#include <dirent.h>

void listFilesRecursively(char *path);


int main()
{
    // Directory path to list files
    char path[100]={"C:\\Users\\F1\\Desktop\\root"};
    listFilesRecursively(path);

    return 0;
}
void listFilesRecursively(char *basePath)
{
    char path[1000];
    struct dirent *dp;
    DIR *dir = opendir(basePath);
    if (!dir)
        return;

    while ((dp = readdir(dir)) != NULL)
    {
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0)
        {
            printf("%s\n", dp->d_name);
            strcpy(path, basePath);
            strcat(path, "\\");
            strcat(path, dp->d_name);
            int w = 0;
            for(int q = 0 ; path[q] != '\0' ;q++)
            {
                if(path[q] == '\\')
                    w++;
            }
            if(w<=3)//3 -> 0   4 -> 1 ....   &
                listFilesRecursively(path);
        }
    }

    closedir(dir);
}*/


