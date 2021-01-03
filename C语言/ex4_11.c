/**
����4.11�� ����һ��CԴ����(һ������)����ԭ����ʽ������������ƹ�����ɾȥ����Դ���������е�ע�͡�
 */

#include <stdio.h>

enum {COPY, START, COMMENT, END};

/*  remove comments from c program  */
int main(void)
{
    char c;
    int state = COPY;  /*��ʼ״̬copy*/

    printf("input C program end with ctrl+z:\n");
    while ((c=getchar()) != EOF)
        switch (state) {   /*�ڵ�ǰ״̬���ж��¼�*/
        case COPY:   /* ��COPY״̬ */
            if (c == '/')   /* ��������ַ�'/' (���¼�1�����ͽ�״̬ת�Ƶ�START̬��*/
                state = START;  
            else           /* ��������'/'��������ַ�(���¼�2������ִ��������ַ�������������������״̬����  */
                putchar(c);
            break;
        case START:     /* ��START״̬ */
            if (c == '*')   /* ��������ַ�* ���ͽ�״̬ת�Ƶ�COMMENT̬��*/
                state = COMMENT;
            else if(c == '/') {  /* ��������ַ�/ ����ִ������ַ�/ ,������״̬���䣻*/
                putchar('/');
            }
			else {          /* ��������/��*��������ַ� ����ִ��������ַ�������״̬ת�Ƶ�COPY̬��*/
				putchar('/');
				putchar(c);
				state=COPY;
			}
            break;
        case COMMENT:     /* ��COMMENT״̬ */
            if (c == '*')   /* �������* ���ͽ�״̬ת�Ƶ�END̬��*/
                state = END;
            break;
        case END:   /* ��END״̬,  
			          ��������ַ�/ ����״̬ת�Ƶ�COPY̬; 
			          ��������ַ�*,  ����״̬END����; 
			          ������������ַ�,��״̬ת�Ƶ� COMMENT̬ */
            state = (c == '/') ? COPY : ((c == '*') ? END : COMMENT);
        } 	/*  end of switch��end of while  */

    return 0;
}
