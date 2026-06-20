unsigned __int64 __fastcall kgsl_snapshot_dump_registers(_QWORD *a1, int *a2, unsigned __int64 a3, __int64 *a4)
{
  unsigned int v4; // w8
  __int64 v7; // x9
  int v9; // w10
  int v10; // w24
  int v11; // w12
  int v12; // w13
  int v13; // w11
  int v14; // w14
  int v15; // w15
  int v16; // w16
  int v17; // w17
  int v18; // w0
  unsigned __int64 v19; // x22
  int v20; // w11
  unsigned int v21; // w10
  int v22; // w12
  int v23; // w13
  unsigned int v24; // w25
  unsigned int *v25; // x9
  unsigned int *v26; // x10
  unsigned int v27; // w23
  unsigned int v28; // w27
  unsigned int *v29; // x28
  unsigned int v30; // w0

  v4 = *((_DWORD *)a4 + 2);
  if ( v4 )
  {
    v7 = *a4;
    v9 = 0;
    if ( v4 == 1 )
    {
      v10 = 0;
    }
    else
    {
      v10 = 0;
      if ( v4 <= 0x40000000 )
      {
        v9 = v4 & 0x7FFFFFFE;
        v11 = 0;
        v12 = 0;
        v13 = 3;
        v14 = v4 & 0x7FFFFFFE;
        do
        {
          v15 = *(_DWORD *)(v7 + 4LL * (v13 - 3));
          v16 = *(_DWORD *)(v7 + 4LL * (v13 - 1));
          v17 = *(_DWORD *)(v7 + 4LL * (v13 - 2));
          v18 = *(_DWORD *)(v7 + 4LL * v13);
          v14 -= 2;
          v13 += 4;
          v11 = v11 - v15 + v17 + 1;
          v12 = v12 - v16 + v18 + 1;
        }
        while ( v14 );
        v10 = v12 + v11;
        if ( v4 == v9 )
          goto LABEL_13;
      }
    }
    v20 = 2 * v9;
    v21 = v4 - v9;
    do
    {
      v22 = *(_DWORD *)(v7 + 4LL * v20);
      --v21;
      v23 = *(_DWORD *)(v7 + 4LL * (v20 + 1));
      v20 += 2;
      v10 = v10 - v22 + v23 + 1;
    }
    while ( v21 );
LABEL_13:
    v19 = (8 * v10) | 4;
    if ( v19 > a3 )
      goto LABEL_14;
    v24 = 0;
    v25 = (unsigned int *)(a2 + 1);
    do
    {
      v26 = (unsigned int *)(*a4 + 4LL * (int)(2 * v24));
      v27 = *v26;
      v28 = v26[1];
      if ( *v26 <= v28 )
      {
        do
        {
          v29 = v25;
          v30 = kgsl_regmap_read((__int64)(a1 + 1650), v27);
          *v29 = v27;
          v29[1] = v30;
          ++v27;
          v25 = v29 + 2;
        }
        while ( v27 <= v28 );
        v4 = *((_DWORD *)a4 + 2);
      }
      ++v24;
    }
    while ( v24 < v4 );
LABEL_22:
    *a2 = v10;
    return v19;
  }
  if ( a3 >= 4 )
  {
    v10 = 0;
    v19 = 4;
    goto LABEL_22;
  }
LABEL_14:
  if ( (unsigned int)__ratelimit(&kgsl_snapshot_dump_registers__rs, "kgsl_snapshot_dump_registers") )
    dev_err(*a1, "snapshot: not enough snapshot memory for section %s\n", "REGISTERS");
  return 0;
}
