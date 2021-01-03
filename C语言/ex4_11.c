/**
【例4.11】 输入一个C源程序(一段正文)，按原来格式复制输出，复制过程中删去输入源程序中所有的注释。
 */

#include <stdio.h>

enum {COPY, START, COMMENT, END};

/*  remove comments from c program  */
int main(void)
{
    char c;
    int state = COPY;  /*初始状态copy*/

    printf("input C program end with ctrl+z:\n");
    while ((c=getchar()) != EOF)
        switch (state) {   /*在当前状态中判断事件*/
        case COPY:   /* 在COPY状态 */
            if (c == '/')   /* 如果输入字符'/' (即事件1），就将状态转移到START态；*/
                state = START;  
            else           /* 如果输入除'/'外的其他字符(即事件2），就执行输出该字符（即动作），并保持状态不变  */
                putchar(c);
            break;
        case START:     /* 在START状态 */
            if (c == '*')   /* 如果输入字符* ，就将状态转移到COMMENT态；*/
                state = COMMENT;
            else if(c == '/') {  /* 如果输入字符/ ，就执行输出字符/ ,并保持状态不变；*/
                putchar('/');
            }
			else {          /* 如果输入除/和*外的其他字符 ，就执行输出该字符，并将状态转移到COPY态；*/
				putchar('/');
				putchar(c);
				state=COPY;
			}
            break;
        case COMMENT:     /* 在COMMENT状态 */
            if (c == '*')   /* 如果输入* ，就将状态转移到END态；*/
                state = END;
            break;
        case END:   /* 在END状态,  
			          如果输入字符/ ，将状态转移到COPY态; 
			          如果输入字符*,  保持状态END不变; 
			          如果输入其他字符,将状态转移到 COMMENT态 */
            state = (c == '/') ? COPY : ((c == '*') ? END : COMMENT);
        } 	/*  end of switch，end of while  */

    return 0;
}
