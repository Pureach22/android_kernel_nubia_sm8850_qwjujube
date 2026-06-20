__int64 __fastcall sde_dbg_dump_sde_dbg_bus(const char **a1, unsigned int a2)
{
  __int64 v2; // x23
  const char *v3; // x22
  size_t v6; // x0
  __int64 v7; // x21
  __int64 result; // x0
  const char *v9; // x22
  unsigned int v10; // w23
  int v11; // w25
  signed int v12; // w8
  int v13; // w9
  int v14; // w10
  int *v15; // x11
  unsigned int v16; // w12
  int v17; // w13
  int v18; // w14
  int v19; // w15
  int v20; // t1
  __int64 v21; // x9
  int v22; // w25
  const char *v23; // x4
  int v24; // w0
  unsigned __int64 v25; // x23
  __int64 v26; // x24
  __int64 v27; // x25
  unsigned int v28; // w22
  unsigned __int64 v29; // x8
  int v30; // w24
  int v31; // w0
  const char *v32; // x24
  unsigned __int64 v33; // [xsp+8h] [xbp-28h]
  char s[8]; // [xsp+10h] [xbp-20h] BYREF
  __int64 v35; // [xsp+18h] [xbp-18h]
  int v36; // [xsp+20h] [xbp-10h]
  __int64 v37; // [xsp+28h] [xbp-8h]

  v37 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = qword_2942A8;
  v3 = *a1;
  v36 = 0;
  *(_QWORD *)s = 0;
  v35 = 0;
  if ( (__int64 *)qword_2942A8 == &qword_2942A8 )
    goto LABEL_17;
  while ( 1 )
  {
    v6 = strnlen((const char *)(v2 + 32), 0x50u);
    if ( v6 >= 0x51 )
    {
      _fortify_panic(2, 80, v6 + 1);
LABEL_36:
      _fortify_panic(4, 80, 81);
    }
    if ( v6 )
    {
      if ( v6 == 80 )
        goto LABEL_36;
      if ( !strcmp((const char *)(v2 + 32), v3) )
        break;
    }
    v2 = *(_QWORD *)v2;
    if ( (__int64 *)v2 == &qword_2942A8 )
      goto LABEL_17;
  }
  if ( !v2 || (v7 = *(_QWORD *)(v2 + 112)) == 0 )
  {
LABEL_17:
    result = printk(&unk_26609A, "_sde_dbg_dump_sde_dbg_bus");
    goto LABEL_30;
  }
  if ( !strcmp(v3, "sde") )
    v7 += *((unsigned int *)a1 + 14);
  result = strcmp(v3, "vbif_rt");
  if ( !(_DWORD)result )
  {
    v24 = readl_relaxed_6(v7 + 4);
    writel_relaxed_6(v24 | 2u, v7 + 4);
    __dsb(0xEu);
    v25 = (unsigned int)readl_relaxed_6(v7 + 516);
    v26 = (unsigned int)readl_relaxed_6(v7 + 400);
    v27 = (unsigned int)readl_relaxed_6(v7 + 404);
    result = dev_err(qword_2942C8, "xin halt:0x%lx, pnd err:0x%lx, src err:0x%lx\n", v25, v26, v27);
    v28 = 0;
    v33 = (v25 >> 16) & ~(v27 | v26);
    do
    {
      v29 = v33;
      if ( (v33 & 1) == 0 )
      {
        writel_relaxed_6(v28, v7 + 416);
        __dsb(0xEu);
        v30 = readl_relaxed_6(v7 + 416);
        v31 = readl_relaxed_6(v7 + 420);
        result = dev_err(qword_2942C8, "Client:%d, errinfo=0x%x, errinfo1=0x%x\n", v28, v30, v31);
        v29 = v33;
      }
      ++v28;
      v33 = v29 >> 1;
    }
    while ( v28 != 14 );
  }
  v9 = a1[5];
  if ( v9 )
  {
    v10 = *((_DWORD *)a1 + 2);
    if ( v10 )
    {
      if ( v10 + 0x7FFFFFFF >= 0x80000001 )
      {
        v12 = v10 & 0xFFFFFFFE;
        v13 = 0;
        v14 = 0;
        v15 = (int *)(v9 + 52);
        v16 = v10 & 0xFFFFFFFE;
        do
        {
          v17 = *(v15 - 10);
          v18 = *(v15 - 8);
          v16 -= 2;
          v19 = *(v15 - 2);
          v20 = *v15;
          v15 += 16;
          v13 += v18 * v17;
          v14 += v20 * v19;
        }
        while ( v16 );
        v11 = v14 + v13;
        if ( v10 == v12 )
          goto LABEL_22;
      }
      else
      {
        v11 = 0;
        v12 = 0;
      }
      do
      {
        v21 = v12++;
        v11 += *(_DWORD *)&v9[32 * v21 + 20] * *(_DWORD *)&v9[32 * v21 + 12];
      }
      while ( v10 != v12 );
LABEL_22:
      snprintf(s, 0x14u, "%s-debugbus", *a1);
      if ( (a2 & 5) != 0 )
        dev_err(qword_2942C8, "======== %s %s dump =========\n", "start", s);
      v22 = 16 * v11;
      v23 = a1[2];
      if ( (a2 & 0xA) != 0 && !v23 )
      {
        v23 = (const char *)vzalloc_noprof(v22);
        a1[2] = v23;
        *((_DWORD *)a1 + 7) = v22 >> 2;
      }
      if ( (a2 & 5) != 0 )
      {
        v32 = v23;
        dev_err(qword_2942C8, "%s: start_addr:0x%pK len:0x%zx offset=0x%x\n", *a1, v23, v22, 0);
        v23 = v32;
      }
      result = sde_dbg_dump_bus_entry(a1, v9, v10, v7, v23, a2, 0);
    }
  }
LABEL_30:
  _ReadStatusReg(SP_EL0);
  return result;
}
