#include <stdio.h>

unsigned char powerCode[] =
{
    0x55,                                        //push   %ebp
    0x89, 0xe5,                                  //mov    %esp,%ebp
    0x83, 0xec, 0x10,                            //sub    $0x10,%esp
    0xc7, 0x45, 0xfc, 0x01, 0x00, 0x00, 0x00,    //movl   $0x1,-0x4(%ebp)
    0x8b, 0x45, 0x0c,                            //mov    0xc(%ebp),%eax
    0x89, 0x45, 0xf8,                            //mov    %eax,-0x8(%ebp)
    0xeb, 0x0e,                                  //jmp    23 <_power+0x23>
    0x8b, 0x45, 0xfc,                            //mov    -0x4(%ebp),%eax
    0x0f, 0xaf, 0x45, 0x08,                      //imul   0x8(%ebp),%eax
    0x89, 0x45, 0xfc,                            //mov    %eax,-0x4(%ebp)
    0x83, 0x6d, 0xf8, 0x01,                      //subl   $0x1,-0x8(%ebp)
    0x83, 0x7d, 0xf8, 0x00,                      //cmpl   $0x0,-0x8(%ebp)
    0x7f, 0xec,                                  //jg     15 <_power+0x15>
    0x8b, 0x45, 0xfc,                            //mov    -0x4(%ebp),%eax
    0xc9,                                        //leave
    0xc3,                                        //ret
    0x90,                                        //nop
    0x90,                                        //nop
};

int (*power)(int a, int b);
int main()
{
    power = (int (*)(int, int)) powerCode;
    printf("power(2, 3)=%d\n", power(2, 3));
}
