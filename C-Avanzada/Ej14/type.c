#include <stdio.h>
#include "type.h"

fat32_t *new_fat32()
{
    fat32_t *f = (fat32_t *)malloc(sizeof(fat32_t));
    if (f)
        *f = 100;
    return f;
}
ext4_t *new_ext4()
{
    ext4_t *e = (ext4_t *)malloc(sizeof(ext4_t));
    if (e)
        *e = 100;
    return e;
}

ntfs_t *new_ntfs()
{
    ntfs_t *n = (ntfs_t *)malloc(sizeof(ntfs_t));
    if (n)
        *n = 100;
    return n;
}
fat32_t *copy_fat32(fat32_t *file)
{
    fat32_t *f = (fat32_t *)malloc(sizeof(fat32_t));
    if (f && file)
        *f = *file;
    return f;
}
ext4_t *copy_ext4(ext4_t *file)
{
    ext4_t *e = (ext4_t *)malloc(sizeof(ext4_t));
    if (e && file)
        *e = file;
    return e;
}
ntfs_t *copy_ntfs(ntfs_t *file)
{
    ntfs_t *n = (ntfs_t *)malloc(sizeof(ntfs_t));
    if (n && file)
        *n = file;
    return n;
}
void rm_fat32(fat32_t *file)
{
    free(file);
}
void rm_ext4(ext4_t *file)
{
    free(file);
}
void rm_ntfs(ntfs_t *file)
{
    free(file);
}