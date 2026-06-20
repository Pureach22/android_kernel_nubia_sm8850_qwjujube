__int64 __fastcall snapshot_rb(_QWORD *a1, __int64 a2, unsigned __int64 a3, __int64 *a4)
{
  __int64 v5; // x21
  __int64 v6; // x22
  unsigned int rptr; // w0
  __int64 v9; // x23
  unsigned int v11; // w24
  unsigned int v12; // w9
  int v13; // w14
  __int64 v14; // x14
  unsigned __int64 v15; // x15
  unsigned int v16; // w8
  int v17; // w10
  int v18; // w12
  __int64 v19; // x27
  int v20; // w26
  int v21; // w28
  int v22; // w9
  int v23; // w25
  signed int v24; // w11
  __int64 v25; // x9
  unsigned __int64 v26; // x8
  unsigned __int64 v27; // x4
  unsigned __int64 v28; // x3
  __int64 v29; // x9
  unsigned __int64 v30; // x10
  unsigned __int64 v31; // x8
  __int64 v32; // x9
  unsigned __int64 v33; // x10
  int *v34; // x10

  if ( a3 <= 0x802B )
  {
    dev_err(*a1, "snapshot: Not enough memory for the rb section\n");
    return 0;
  }
  v6 = *a4;
  v5 = a4[1];
  *(_QWORD *)a2 = 0x200000000000LL;
  *(_DWORD *)(a2 + 12) = *(_DWORD *)(v5 + 20);
  *(_DWORD *)(a2 + 16) = adreno_get_rptr(v5);
  *(_DWORD *)(a2 + 20) = 0x2000;
  *(_DWORD *)(a2 + 8) = 0x2000;
  adreno_rb_readtimestamp((__int64)a1, v5, 3, (_DWORD *)(a2 + 24));
  adreno_rb_readtimestamp((__int64)a1, v5, 2, (_DWORD *)(a2 + 28));
  *(_QWORD *)(a2 + 32) = *(_QWORD *)(*(_QWORD *)(v5 + 8) + 24LL);
  *(_DWORD *)(a2 + 40) = *(_DWORD *)(v5 + 28);
  if ( v5 != a1[2455] )
    goto LABEL_6;
  rptr = adreno_get_rptr(v5);
  if ( (a1[1413] & 1) != 0 )
    goto LABEL_6;
  v9 = *(_QWORD *)(*(_QWORD *)(v5 + 8) + 8LL);
  if ( (a1[1769] & 1) != 0 )
    goto LABEL_5;
  v11 = rptr;
  v12 = rptr;
  while ( 1 )
  {
    if ( (--v12 & 0x80000000) != 0 )
    {
      v12 = 8188;
      if ( *(_DWORD *)(v5 + 20) > 0x1FFCu )
        goto LABEL_5;
    }
    v13 = *(_DWORD *)(v9 + 4LL * v12);
    if ( v13 > 1891270658 )
    {
      if ( v13 != 1891598339 && v13 != 1891270659 )
        goto LABEL_8;
    }
    else if ( v13 != 1882357763 && v13 != 1882685443 )
    {
      goto LABEL_8;
    }
    v14 = *(unsigned int *)(v9 + 4LL * (int)(v12 + 3));
    v15 = *(unsigned int *)(v9 + 4LL * (int)(v12 + 1))
        | ((unsigned __int64)*(unsigned int *)(v9 + 4LL * (int)(v12 + 2)) << 32);
    if ( !__CFADD__(v15, 4 * v14) && *(_QWORD *)v6 >= v15 && 4 * v14 + v15 > *(_QWORD *)v6 )
      break;
LABEL_8:
    if ( v12 == *(_DWORD *)(v5 + 20) )
      goto LABEL_5;
  }
  *(_QWORD *)v6 = v15;
  *(_DWORD *)(v6 + 24) = v14;
  v16 = *(_DWORD *)(v5 + 20);
  if ( v12 != v16 )
  {
    if ( v16 < 0x1FFF || (v17 = *(_DWORD *)(v5 + 20), v12) )
    {
      v17 = v12 - 1;
      if ( !v12 )
        v17 = 8190;
      do
      {
        if ( *(_DWORD *)(v9 + 4LL * (unsigned int)v17) == 1880096769 )
        {
          if ( v17 == v16 || *(_DWORD *)(v9 + 4LL * (v17 + 1)) == 783138543 )
            goto LABEL_38;
        }
        else if ( v17 == v16 )
        {
          break;
        }
        v18 = v17 - 1;
        if ( v17 - 1 < 0 )
          v17 = 8190;
        else
          --v17;
      }
      while ( v16 < 0x1FFF || (v18 & 0x80000000) == 0 );
      v17 = *(_DWORD *)(v5 + 20);
    }
LABEL_38:
    v19 = v17;
    v20 = 0;
    v21 = 0x2000;
    while ( v20 || v16 != (_DWORD)v19 )
    {
      if ( v16 != v11 )
      {
        v34 = (int *)(v9 + 4LL * (int)v16);
        v22 = *v34;
        if ( *v34 == 1880096769 )
        {
          if ( v34[1] == 783138543 )
            v20 = 0;
          goto LABEL_77;
        }
        if ( !v20 )
        {
LABEL_77:
          v23 = v16 + 1;
          goto LABEL_40;
        }
LABEL_47:
        if ( v22 > 1891270658 )
        {
          if ( v22 == 1891598339 || v22 == 1891270659 )
          {
LABEL_55:
            v23 = v16 + 1;
            v24 = v16 + 3;
            v25 = *(unsigned int *)(v9 + 4LL * (int)(v16 + 2));
            v26 = a1[121];
            v27 = *(unsigned int *)(v9 + 4LL * v24);
            v28 = *(unsigned int *)(v9 + 4LL * v23) | (unsigned __int64)(v25 << 32);
            if ( !v26
              || v26 > 0xFFFFFFFFFFFFF000LL
              || (v27 <= 1 ? (v29 = 1) : (v29 = *(unsigned int *)(v9 + 4LL * v24)),
                  __CFADD__(v28, v29)
               || (v30 = *(_QWORD *)(v26 + 24), v30 > v28)
               || v29 + v28 > *(_QWORD *)(v26 + 40) + v30) )
            {
              v31 = a1[2536];
              if ( !v31
                || v31 > 0xFFFFFFFFFFFFF000LL
                || (v27 <= 1 ? (v32 = 1) : (v32 = *(unsigned int *)(v9 + 4LL * v24)),
                    __CFADD__(v28, v32)
                 || (v33 = *(_QWORD *)(v31 + 24), v33 > v28)
                 || v32 + v28 > *(_QWORD *)(v31 + 40) + v33) )
              {
                adreno_parse_ib(a1, v6, *(_QWORD *)(v6 + 224), v28, v27);
              }
            }
            goto LABEL_40;
          }
        }
        else if ( v22 == 1882357763 || v22 == 1882685443 )
        {
          goto LABEL_55;
        }
        goto LABEL_77;
      }
      v20 = 0;
      v23 = v16 + 1;
LABEL_40:
      if ( v23 <= 0 )
        v16 = -(-v23 & 0x1FFF);
      else
        v16 = v23 & 0x1FFF;
      if ( !--v21 )
        goto LABEL_6;
    }
    v22 = *(_DWORD *)(v9 + 4 * v19);
    v20 = 1;
    goto LABEL_47;
  }
  v9 = *(_QWORD *)(*(_QWORD *)(v5 + 8) + 8LL);
LABEL_5:
  adreno_snapshot_dump_all_ibs((__int64)a1, v9, v6);
LABEL_6:
  memcpy((void *)(a2 + 44), *(const void **)(*(_QWORD *)(v5 + 8) + 8LL), 0x8000u);
  return 32812;
}
