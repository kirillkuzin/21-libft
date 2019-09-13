#include <string.h>

size_t  ft_strlcat(char *dst, const char *src, size_t dstsize)
{
    size_t  i;
    size_t  j;

    i = 0;
    j = 0;
    while (dst[i])
        i++;
    while (j < dstsize)
    {
        dst[i] = src[j];
        i++;
        j++;
    }
    dst[i] = '\0';
    return (i);
}
