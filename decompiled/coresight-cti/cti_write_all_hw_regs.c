__int64 __fastcall cti_write_all_hw_regs(_QWORD *a1)
{
  __int64 v2; // x0
  __int64 v3; // x1
  int v4; // w8
  __int64 v5; // x23
  __int64 v6; // x24
  __int64 v7; // x20
  __int64 v8; // x21
  __int64 v9; // x22
  __int64 v10; // x23
  __int64 v11; // x24
  __int64 v12; // x8

  writel_relaxed(3316436565LL, *a1 + 4016LL);
  __dsb(0xFu);
  v2 = writel_relaxed(0, *a1);
  v4 = *((_DWORD *)a1 + 17);
  if ( (a1[150] & 1) == 0 )
  {
    if ( v4 >= 1 )
    {
      v10 = 0;
      v11 = 0;
      v7 = 20;
      v8 = 324;
      v9 = 320;
      while ( v10 != 512 )
      {
        writel_relaxed(*(unsigned int *)((char *)a1 + v10 + 140), *a1 + v10 + 32);
        v2 = writel_relaxed(*(unsigned int *)((char *)a1 + v10 + 652), *a1 + v10 + 160);
        ++v11;
        v10 += 4;
        if ( v11 >= *((int *)a1 + 17) )
          goto LABEL_14;
      }
      goto LABEL_15;
    }
    v7 = 20;
    v8 = 324;
    v9 = 320;
LABEL_14:
    writel_relaxed(*((unsigned int *)a1 + 291), *a1 + v9);
    writel_relaxed(*((unsigned int *)a1 + 292), *a1 + v8);
    writel_relaxed(*((unsigned int *)a1 + 33), *a1 + v7);
    writel_relaxed(1, *a1);
    v12 = *a1;
    __dsb(0xFu);
    return writel_relaxed(0, v12 + 4016);
  }
  if ( v4 < 1 )
  {
    v7 = 4;
    v8 = 140;
    v9 = 136;
    goto LABEL_14;
  }
  v5 = 0;
  v6 = 2048;
  v7 = 4;
  v8 = 140;
  v9 = 136;
  while ( v6 != 2560 )
  {
    writel_relaxed(*(unsigned int *)((char *)a1 + v6 - 1908), *a1 + v6 - 1024);
    v2 = writel_relaxed(*(unsigned int *)((char *)a1 + v6 - 1396), *a1 + v6);
    ++v5;
    v6 += 4;
    if ( v5 >= *((int *)a1 + 17) )
      goto LABEL_14;
  }
LABEL_15:
  __break(0x5512u);
  return writel_relaxed(v2, v3);
}
