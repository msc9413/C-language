/******************************************************************************

简述：
  本程序将输入正文每一行的前导空格删除后，将后面部分进行输出
******************************************************************************/

#include <stdio.h>

enum { HeadSpace,COPY };
int main()
{
  int ch, state;     /* state存当前状态 */

  state=HeadSpace;     //  初始前导空格状态
  printf("Input text,   end of Ctrl+z\n") ;
  while ((ch = getchar()) != EOF)
  {
    switch(state) {
    	case HeadSpace:
		   if (ch!=' '&& ch!='\t')    /* 不为空格时*/
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
