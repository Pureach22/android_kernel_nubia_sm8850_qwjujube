unsigned __int64 __fastcall _init_clocks(_QWORD *a1)
{
  __int64 v1; // x8
  __int64 v2; // x20
  __int64 v3; // x21
  bool v4; // zf
  unsigned __int64 result; // x0
  __int64 v7; // x25
  __int64 v8; // x0
  int v9; // w8
  unsigned int v10; // w9
  __int64 v11; // x22
  __int64 v12; // x23
  unsigned int v13; // w24
  int i; // w8
  __int64 v15; // x8
  int v16; // w9
  unsigned int v17; // w10
  int v18; // w28
  char v19; // w9
  unsigned int v20; // w24
  __int64 v21; // x8
  int v22; // w9
  int v23; // w21
  __int64 v24; // x9
  __int64 v25; // x8
  int v26; // w22
  __int64 *v27; // x0
  __int64 v28; // x8
  __int64 v29; // x2
  __int64 v30; // x9
  __int64 *v31; // x1
  __int64 v32; // x8
  unsigned int v33; // w10
  unsigned __int64 *v34; // x24
  char v35; // w9
  void *v36; // x0

  v1 = a1[489];
  v2 = *(_QWORD *)(v1 + 72);
  v3 = *(unsigned int *)(v1 + 80);
  if ( v2 )
    v4 = (_DWORD)v3 == 0;
  else
    v4 = 1;
  if ( v4 )
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_919F8, "err ", 0xFFFFFFFFLL, "codec", "__init_clocks");
    return 4294967274LL;
  }
  else
  {
    v7 = a1[488];
    v8 = devm_kmalloc(*a1 + 16LL, 72 * v3, 3520);
    *(_QWORD *)(v7 + 64) = v8;
    if ( !v8 )
    {
      if ( (msm_vidc_debug & 1) == 0 )
        return 4294967284LL;
      v36 = &unk_86CDC;
LABEL_65:
      printk(v36, "err ", 0xFFFFFFFFLL, "codec", "__init_clocks");
      return 4294967284LL;
    }
    v9 = 0;
    *(_DWORD *)(v7 + 72) = v3;
    do
    {
      v11 = v9;
      v12 = v2 + 32LL * v9;
      if ( *(_BYTE *)(v12 + 12) == 1 )
        v13 = *(_DWORD *)(v12 + 24);
      else
        v13 = 0;
      *(_QWORD *)(*(_QWORD *)(v7 + 64) + 72LL * v9 + 64) = devm_kmalloc(*a1 + 16LL, 8LL * v13, 3520);
      *(_QWORD *)(*(_QWORD *)(v7 + 64) + 72 * v11 + 8) = *(_QWORD *)v12;
      *(_DWORD *)(*(_QWORD *)(v7 + 64) + 72 * v11 + 16) = *(_DWORD *)(v12 + 8);
      *(_BYTE *)(*(_QWORD *)(v7 + 64) + 72 * v11 + 20) = *(_BYTE *)(v12 + 12);
      *(_DWORD *)(*(_QWORD *)(v7 + 64) + 72 * v11 + 56) = v13;
      if ( v13 )
      {
        for ( i = 0; i != v13; ++i )
          *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v7 + 64) + 72LL * (int)v11 + 64) + 8LL * i) = *(_QWORD *)(*(_QWORD *)(v12 + 16) + 8LL * i);
      }
      v10 = *(_DWORD *)(v7 + 72);
      v9 = v11 + 1;
    }
    while ( (int)v11 + 1 < v10 );
    if ( v10 )
    {
      v15 = *(_QWORD *)(v7 + 64);
      v16 = 0;
      do
      {
        v18 = v16;
        if ( *(_BYTE *)(v15 + 72LL * v16 + 20) == 1 )
        {
          if ( (msm_vidc_debug & 2) != 0 )
          {
            printk(&unk_965F8, "high", 0xFFFFFFFFLL, "codec", "__init_clocks");
            v15 = *(_QWORD *)(v7 + 64);
          }
          if ( *(_DWORD *)(v15 + 72LL * v18 + 56) )
          {
            v19 = msm_vidc_debug;
            v20 = 0;
            do
            {
              if ( (v19 & 2) != 0 )
              {
                printk(&unk_8AC26, "high", 0xFFFFFFFFLL, "codec", "__init_clocks");
                v19 = msm_vidc_debug;
                v15 = *(_QWORD *)(v7 + 64);
              }
              ++v20;
            }
            while ( v20 < *(_DWORD *)(v15 + 72LL * v18 + 56) );
          }
        }
        v17 = *(_DWORD *)(v7 + 72);
        v16 = v18 + 1;
      }
      while ( v18 + 1 < v17 );
      if ( v17 )
      {
        v21 = *(_QWORD *)(v7 + 64);
        v22 = 0;
        while ( 1 )
        {
          v23 = v22;
          v24 = 72LL * v22;
          v25 = v21 + v24;
          *(_QWORD *)(v25 + 40) = v25 + 40;
          *(_QWORD *)(v25 + 48) = v25 + 40;
          v21 = *(_QWORD *)(v7 + 64);
          if ( *(_BYTE *)(v21 + v24 + 20) == 1 )
          {
            if ( *(_DWORD *)(v21 + 72LL * v23 + 56) )
              break;
          }
LABEL_32:
          v22 = v23 + 1;
          if ( (unsigned int)(v23 + 1) >= *(_DWORD *)(v7 + 72) )
            goto LABEL_44;
        }
        v26 = 0;
        while ( 1 )
        {
          v27 = (__int64 *)devm_kmalloc(*a1 + 16LL, 40, 3520);
          if ( !v27 )
            break;
          v28 = *(_QWORD *)(v7 + 64) + 72LL * v23;
          v29 = v28 + 40;
          v30 = *(_QWORD *)(*(_QWORD *)(v28 + 64) + 8LL * v26);
          v27[3] = 0;
          v27[4] = 0;
          v27[2] = v30;
          *v27 = (__int64)v27;
          v27[1] = (__int64)v27;
          v31 = *(__int64 **)(v28 + 48);
          if ( v27 == (__int64 *)(v28 + 40) || v31 == v27 || *v31 != v29 )
          {
            _list_add_valid_or_report(v27);
          }
          else
          {
            *(_QWORD *)(v28 + 48) = v27;
            *v27 = v29;
            v27[1] = (__int64)v31;
            *v31 = (__int64)v27;
          }
          v21 = *(_QWORD *)(v7 + 64);
          if ( (unsigned int)++v26 >= *(_DWORD *)(v21 + 72LL * v23 + 56) )
            goto LABEL_32;
        }
        if ( (msm_vidc_debug & 1) == 0 )
          return 4294967284LL;
        v36 = &unk_96638;
        goto LABEL_65;
      }
    }
LABEL_44:
    v32 = a1[488];
    v33 = *(_DWORD *)(v32 + 72);
    v34 = *(unsigned __int64 **)(v32 + 64);
    if ( v34 < &v34[9 * v33] )
    {
      v35 = msm_vidc_debug;
      do
      {
        if ( (v35 & 2) != 0 )
        {
          printk(&unk_8E924, "high", 0xFFFFFFFFLL, "codec", "__init_clocks");
          v35 = msm_vidc_debug;
          v32 = a1[488];
        }
        v33 = *(_DWORD *)(v32 + 72);
        v34 += 9;
      }
      while ( (unsigned __int64)v34 < *(_QWORD *)(v32 + 64) + 72 * (unsigned __int64)v33 );
      v34 = *(unsigned __int64 **)(v32 + 64);
    }
    if ( v34 >= &v34[9 * v33] )
    {
      return 0;
    }
    else
    {
      while ( 1 )
      {
        result = devm_clk_get(*a1 + 16LL, v34[1]);
        *v34 = result;
        if ( !result || result >= 0xFFFFFFFFFFFFF001LL )
          break;
        v34 += 9;
        if ( (unsigned __int64)v34 >= *(_QWORD *)(a1[488] + 64LL)
                                    + 72 * (unsigned __int64)*(unsigned int *)(a1[488] + 72LL) )
          return 0;
      }
      if ( (msm_vidc_debug & 1) != 0 )
      {
        printk(&unk_8879E, "err ", 0xFFFFFFFFLL, "codec", "__init_clocks");
        result = *v34;
      }
      *v34 = 0;
      if ( result )
        return (unsigned int)result;
      else
        return 4294967274LL;
    }
  }
}
