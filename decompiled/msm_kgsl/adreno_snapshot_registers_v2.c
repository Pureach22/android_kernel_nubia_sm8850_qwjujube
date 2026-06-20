unsigned __int64 __fastcall adreno_snapshot_registers_v2(_QWORD *a1, unsigned int *a2, unsigned __int64 a3, _DWORD *a4)
{
  unsigned int v4; // w8
  unsigned int *v5; // x20
  int v7; // w9
  int *v8; // x10
  int v9; // w12
  bool v10; // zf
  int v11; // w13
  int v12; // t1
  int v13; // w13
  unsigned __int64 v14; // x21
  unsigned int v15; // w9
  unsigned int *v16; // x24
  unsigned int i; // w22
  unsigned int v18; // t1

  v4 = *a4;
  if ( *a4 == -1 )
    return 0;
  v5 = a4;
  v7 = 0;
  v8 = a4 + 2;
  v9 = *a4;
  do
  {
    v11 = *(v8 - 1) - v9;
    v10 = *(v8 - 1) == v9;
    v12 = *v8;
    v8 += 2;
    v9 = v12;
    v13 = v11 + 3;
    if ( v10 )
      v13 = 2;
    v7 += v13;
  }
  while ( v9 != -1 );
  v14 = 4 * v7;
  if ( v14 > a3 )
  {
    if ( (unsigned int)__ratelimit(&adreno_snapshot_registers_v2__rs, "adreno_snapshot_registers_v2") )
      dev_err(*a1, "snapshot: not enough snapshot memory for section %s\n", "REGISTERS");
    return 0;
  }
  if ( v4 != -1 )
  {
    do
    {
      v15 = v5[1] - v4;
      if ( v15 )
      {
        v16 = a2 + 2;
        a2[1] = v15 + 1;
      }
      else
      {
        v4 |= 0x80000000;
        v16 = a2 + 1;
      }
      *a2 = v4;
      for ( i = *v5; i <= v5[1]; ++i )
        *v16++ = kgsl_regmap_read(a1 + 1650);
      v18 = v5[2];
      v5 += 2;
      v4 = v18;
      a2 = v16;
    }
    while ( v18 != -1 );
  }
  return v14;
}
