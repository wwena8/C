# 九 动态内存管理

1 malloc realloc free calloc 堆上申请内存

    原则：谁申请谁释放，防止内存泄露

    要回收一块内存，必须首先拿到该内存块的起始地址
    
2 typedef 针对已有数据类型改名的