/******************************************************************************

������
  ��������������ÿһ�е�ǰ���ո�ɾ���󣬽����沿�ֽ������
******************************************************************************/

#include <stdio.h>

enum { HeadSpace,COPY };
int main()
{
  int ch, state;     /* state�浱ǰ״̬ */

  state=HeadSpace;     //  ��ʼǰ���ո�״̬
  printf("Input text,   end of Ctrl+z\n") ;
  while ((ch = getchar()) != EOF)
  {
    switch(state) {
    	case HeadSpace:
		   if (ch!=' '&& ch!='\t')    /* ��Ϊ�ո�ʱ*/
		     { putchar(ch); state=COPY; }
		    break;
		case COPY :
		    putchar(ch);
		    if (ch=='\n')  state=HeadSpace;
		    break;
    }
  }
  return 0;
}
