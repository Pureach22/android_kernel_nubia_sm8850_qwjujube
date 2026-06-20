#include "defs.h"

#define nullptr NULL

// Reconstructed string_change function
unsigned char *string_change(__int64 a1, char *s, unsigned int *a3)
{
  size_t len;
  char *s_copy;
  char *part1, *part2;
  unsigned char *out_buf = NULL;
  size_t out_max;
  char *part1_ptr, *token;
  int v15 = 0;
  unsigned char v14 = 0;
  int v13 = 0;
  int v16 = 1;
  char *colon;

  if (!s || !*s)
  {
    out_buf = kzalloc(1, GFP_KERNEL);
    if (!out_buf)
      goto LABEL_77;
    *out_buf = 0;
    goto LABEL_77;
  }

  len = strlen(s);
  s_copy = kmalloc(len + 1, GFP_KERNEL);
  if (!s_copy)
  {
    out_buf = NULL;
    goto LABEL_77;
  }
  memcpy(s_copy, s, len + 1);

  out_max = 3 * strlen(s);
  out_buf = kmalloc(out_max, GFP_KERNEL);
  if (!out_buf)
  {
    kfree(s_copy);
    goto LABEL_77;
  }

  // Split at the first colon (if any) to separate part1 and part2
  colon = strchr(s_copy, ':');
  if (colon)
  {
    *colon = 0;
    part1 = s_copy;
    part2 = colon + 1;
  }
  else
  {
    part1 = s_copy;
    part2 = NULL;
  }

  // Loop 1: Parse part1 (comma separated hex values)
  part1_ptr = part1;
  if (*part1_ptr)
  {
    while ((token = strsep(&part1_ptr, ",")) != NULL)
    {
      char *trimmed = strim(token);
      if (*trimmed)
      {
        unsigned char val = (unsigned char)simple_strtoul(trimmed, NULL, 16);
        if (v15 >= out_max)
        {
          // overflow check from decomp
          __break(1u);
          goto LABEL_77;
        }
        if (v16)
        {
          v14 = val;
          v13 = 1;
          v16 = 0;
        }
        out_buf[v15++] = val;
      }
    }
  }

  // Loop 2: Parse part2 (dot separated coordinates)
  if (part2 && *part2)
  {
    char *part2_ptr = part2;
    char *segment;
    int v20 = 1;
    int v21 = v15;

    while ((segment = strsep(&part2_ptr, ".")) != NULL)
    {
      char *trimmed_seg = strim(segment);
      if (!*trimmed_seg)
        continue;

      int v23 = (v13 != 0);
      if (v20)
        v23 = 0;

      if (v23)
      {
        if (v21 >= out_max)
        {
          __break(1u);
          goto LABEL_77;
        }
        out_buf[v21++] = v14;
      }

      char *seg_colon = strchr(trimmed_seg, ':');
      char *coords_str = trimmed_seg;
      if (seg_colon)
      {
        *seg_colon = 0;
        char *seg_prefix = strim(trimmed_seg);
        coords_str = seg_colon + 1;
        if (*seg_prefix)
        {
          unsigned char val = (unsigned char)simple_strtoul(seg_prefix, NULL, 16);
          if (v21 >= out_max)
          {
            __break(1u);
            goto LABEL_77;
          }
          out_buf[v21++] = val;
        }
      }

      char *coords_trimmed = strim(coords_str);
      char *c1 = strsep(&coords_trimmed, ",");
      char *c2 = strsep(&coords_trimmed, ",");
      char *c3 = strsep(&coords_trimmed, ",");
      char *c4 = strsep(&coords_trimmed, ",");

      if (c1 && c2 && c3 && c4)
      {
        char *t1 = strim(c1);
        char *t2 = strim(c2);
        char *t3 = strim(c3);
        char *t4 = strim(c4);

        unsigned int x1 = simple_strtoul(t1, NULL, 10);
        unsigned int y1 = simple_strtoul(t2, NULL, 10);
        unsigned int x2 = simple_strtoul(t3, NULL, 10);
        unsigned int y2 = simple_strtoul(t4, NULL, 10);

        int rotation = *(int *)(a1 + 1544);
        int v41 = 0, v44 = 0;
        unsigned short v45 = 0, v42 = 0, v43 = 0;
        unsigned char v46 = 0, v47 = 0;

        printk(unk_33FD8, "change_coordinate", rotation);

        if (rotation == 3)
        {
          v41 = 5 * y1;
          v45 = 10 * (2688 - x2) - 1;
          v44 = 10 * y1;
          v42 = (10 * (2688 - x1)) | 1;
          v43 = 10 * y2 - 1;
          v46 = (2 * v41) | 1;
          v47 = HIBYTE(v44);
        }
        else if (rotation == 1)
        {
          v41 = 5 * (-64 - y2);
          v42 = 10 * x2 - 1;
          v43 = 10 * (1216 - y1) - 1;
          v44 = 10 * (1216 - y2);
          v45 = (10 * x1) | 1;
          v46 = (2 * v41) | 1;
          v47 = HIBYTE(v44);
        }
        else
        {
          v46 = 0;
          v47 = 0;
          v45 = 0;
          v43 = 0;
          v42 = 0;
        }

        if (v21 + 8 > out_max)
        {
          __break(1u);
          goto LABEL_77;
        }

        out_buf[v21] = v46;
        out_buf[v21 + 1] = v47;
        out_buf[v21 + 2] = v45;
        out_buf[v21 + 3] = HIBYTE(v45);
        out_buf[v21 + 4] = v43;
        out_buf[v21 + 5] = HIBYTE(v43);
        out_buf[v21 + 6] = v42;
        out_buf[v21 + 7] = HIBYTE(v42);
        v21 += 8;
      }

      v20 = 0;
    }
    v15 = v21;
  }

  kfree(s_copy);
  *a3 = v15;
  return out_buf;

LABEL_77:
  *a3 = 0;
  return out_buf;
}
