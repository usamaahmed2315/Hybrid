//
// mod_a.c
// Models NULL Pointer (Data) memory analysis pattern in kernel space
//
// Copyright (c) 2022 Software Diagnostics Services.All rights reserved.
//

#include <linux/module.h>

void foo(void);
void bar(void);

int init_module(void)
{
    foo();

    return 0;
}

void bar(void)
{
    int *pi = NULL;
    *pi = 1;
}

void foo(void)
{
    bar();
}

MODULE_LICENSE("GPL");
