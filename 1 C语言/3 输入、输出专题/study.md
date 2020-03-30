# 三 输入、输出专题

标准io、文件io的区别于联系

1 格式化的输入输出：scanf、printf     man 3 printf

    int printf(const char * restrict format, ...);  
    
    format: "% [修饰字符] 格式字符" 
    
    变参与重载 
    
    int scanf(const char *restrict format, ...);

2 字符输入输出：getchar、putchar

3 字符串输入输出：gets(危险)、puts