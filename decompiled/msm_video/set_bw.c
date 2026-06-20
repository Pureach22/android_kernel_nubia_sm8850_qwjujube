__int64 __fastcall set_bw(_QWORD *a1, unsigned __int64 a2, unsigned __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v6; // x8
  unsigned __int64 v7; // x22
  unsigned int v9; // w23
  const char *v10; // x24
  int v11; // w25
  unsigned __int64 v12; // x9
  int v13; // w21
  unsigned __int64 v14; // x8
  unsigned __int64 v15; // x26
  __int64 v16; // x8
  unsigned __int64 v17; // x20
  unsigned int v18; // w0

  if ( a3 | a2 )
  {
    v6 = a1[488];
    v7 = *(_QWORD *)(v6 + 16);
    if ( v7 < v7 + 24LL * *(unsigned int *)(v6 + 24) )
    {
      v9 = 0;
      while ( 1 )
      {
        if ( !v7 || !*(_QWORD *)v7 )
        {
          if ( (msm_vidc_debug & 1) != 0 )
            printk(&unk_8C4AC, "err ", 0xFFFFFFFFLL, "codec", a5);
          goto LABEL_6;
        }
        v10 = *(const char **)(v7 + 8);
        v11 = strcmp(v10, "venus-llcc");
        if ( v11 )
        {
          if ( !strcmp(v10, "venus-ddr") )
          {
            v14 = a1[802];
            v12 = a2;
            v13 = 1;
          }
          else
          {
            v12 = *(unsigned int *)(v7 + 20);
            v13 = 0;
            if ( a1[802] )
              v14 = *(unsigned int *)(v7 + 20);
            else
              v14 = 0;
          }
        }
        else
        {
          v14 = a1[803];
          v13 = 0;
          v12 = a3;
        }
        v15 = *(unsigned int *)(v7 + 20);
        if ( v12 < v15 )
        {
          if ( v12 <= *(unsigned int *)(v7 + 16) )
            v15 = *(unsigned int *)(v7 + 16);
          else
            v15 = v12;
        }
        if ( v15 <= v14 )
        {
          if ( v14 && (v14 - v15) >> 4 <= 0xC34 )
          {
LABEL_26:
            if ( (msm_vidc_debug & 4) != 0 )
              printk(&unk_82731, "low ", 0xFFFFFFFFLL, "codec", v10);
            goto LABEL_6;
          }
        }
        else if ( v14 && (v15 - v14) >> 4 <= 0xC34 )
        {
          goto LABEL_26;
        }
        v9 = _vote_bandwidth(v7, v15);
        if ( v13 )
        {
          a1[802] = v15;
        }
        else if ( !v11 )
        {
          a1[803] = v15;
        }
LABEL_6:
        v7 += 24LL;
        if ( v7 >= *(_QWORD *)(a1[488] + 16LL) + 24 * (unsigned __int64)*(unsigned int *)(a1[488] + 24LL) )
          return v9;
      }
    }
    return 0;
  }
  v16 = a1[488];
  a1[803] = 0;
  a1[802] = 0;
  v17 = *(_QWORD *)(v16 + 16);
  if ( v17 >= v17 + 24LL * *(unsigned int *)(v16 + 24) )
    return 0;
  while ( 1 )
  {
    v18 = _vote_bandwidth(v17, 0);
    if ( v18 )
      break;
    v17 += 24LL;
    if ( v17 >= *(_QWORD *)(a1[488] + 16LL) + 24 * (unsigned __int64)*(unsigned int *)(a1[488] + 24LL) )
      return 0;
  }
  return v18;
}
