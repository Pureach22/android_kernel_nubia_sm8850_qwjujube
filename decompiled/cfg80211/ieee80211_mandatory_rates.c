__int64 __fastcall ieee80211_mandatory_rates(__int64 a1)
{
  __int64 v1; // x8
  int v2; // w9
  __int64 v3; // x11
  __int64 v4; // x10
  __int64 result; // x0
  __int64 v6; // x14
  unsigned int v7; // w12
  int v8; // w13
  int *v9; // x17
  int v10; // w0
  int v11; // w1
  __int64 v12; // x2
  __int64 v13; // x3
  int v14; // w0
  int v15; // w1
  int *v16; // x11
  int v17; // t1
  __int64 v18; // x14
  int v19; // w13

  if ( !a1 )
  {
    __break(0x800u);
    return 1;
  }
  v1 = *(unsigned int *)(a1 + 24);
  if ( *(_DWORD *)(a1 + 16) )
    v2 = 2;
  else
    v2 = 4;
  if ( (int)v1 < 1 )
    return 0;
  v3 = *(_QWORD *)(a1 + 8);
  if ( (_DWORD)v1 == 1 )
  {
    v4 = 0;
    LODWORD(result) = 0;
LABEL_18:
    v16 = (int *)(v3 + 12LL * (unsigned int)v4);
    do
    {
      v17 = *v16;
      v16 += 3;
      v18 = 1LL << v4++;
      if ( (v17 & v2) != 0 )
        v19 = v18;
      else
        v19 = 0;
      result = v19 | (unsigned int)result;
    }
    while ( v1 != v4 );
    return result;
  }
  v6 = 0;
  v7 = 0;
  v8 = 0;
  v4 = v1 & 0x7FFFFFFE;
  v9 = *(int **)(a1 + 8);
  do
  {
    v10 = *v9;
    v11 = v9[3];
    v12 = 1LL << v6;
    v13 = 2LL << v6;
    v6 += 2;
    v9 += 6;
    if ( (v10 & v2) != 0 )
      v14 = v12;
    else
      v14 = 0;
    if ( (v11 & v2) != 0 )
      v15 = v13;
    else
      v15 = 0;
    v7 |= v14;
    v8 |= v15;
  }
  while ( v4 != v6 );
  result = v8 | v7;
  if ( v4 != v1 )
    goto LABEL_18;
  return result;
}
