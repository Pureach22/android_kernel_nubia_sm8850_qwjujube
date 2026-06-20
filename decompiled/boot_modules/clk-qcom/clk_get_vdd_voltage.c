__int64 __fastcall clk_get_vdd_voltage(__int64 a1, int a2)
{
  __int64 v2; // x9
  __int64 v3; // x10
  __int64 v4; // x11
  int v5; // w8
  __int64 *v6; // x12
  __int64 v7; // x13
  int v8; // w14
  __int64 v9; // x15
  __int64 v10; // x16
  int v11; // w15
  int v12; // w16
  __int64 *v13; // x10
  __int64 v14; // x9
  __int64 v15; // t1
  int v16; // w11

  v2 = *(unsigned int *)(a1 + 32);
  if ( (int)v2 < 1 )
  {
    v5 = -22;
    goto LABEL_18;
  }
  v3 = *(_QWORD *)(a1 + 8);
  if ( (_DWORD)v2 == 1 )
  {
    v4 = 0;
    v5 = -22;
LABEL_14:
    v13 = (__int64 *)(v3 + 8 * v4);
    v14 = v2 - v4;
    do
    {
      v15 = *v13++;
      v16 = *(_DWORD *)(*(_QWORD *)(v15 + 32) + 4LL * a2);
      if ( v5 <= v16 )
        v5 = v16;
      --v14;
    }
    while ( v14 );
    goto LABEL_18;
  }
  v4 = v2 & 0x7FFFFFFE;
  v6 = (__int64 *)(v3 + 8);
  v5 = -22;
  v7 = v4;
  v8 = -22;
  do
  {
    v9 = *(v6 - 1);
    v10 = *v6;
    v6 += 2;
    v11 = *(_DWORD *)(*(_QWORD *)(v9 + 32) + 4LL * a2);
    v12 = *(_DWORD *)(*(_QWORD *)(v10 + 32) + 4LL * a2);
    if ( v5 <= v11 )
      v5 = v11;
    if ( v8 <= v12 )
      v8 = v12;
    v7 -= 2;
  }
  while ( v7 );
  if ( v5 <= v8 )
    v5 = v8;
  if ( v4 != v2 )
    goto LABEL_14;
LABEL_18:
  if ( *(_QWORD *)a1 && v5 <= *(_DWORD *)(*(_QWORD *)(*(_QWORD *)a1 + 32LL) + 4LL * a2) )
    return *(unsigned int *)(*(_QWORD *)(*(_QWORD *)a1 + 32LL) + 4LL * a2);
  return (unsigned int)v5;
}
