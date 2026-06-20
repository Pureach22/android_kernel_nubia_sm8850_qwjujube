__int64 __fastcall dp_soc_deinit_be(__int64 a1)
{
  _DWORD *v2; // x20
  __int64 result; // x0
  __int64 v4; // x9
  unsigned int v5; // w8
  __int64 v6; // x11
  __int64 v7; // x9
  unsigned int v8; // w8
  __int64 v9; // x11
  __int64 v10; // x9
  unsigned int v11; // w8
  __int64 v12; // x11
  __int64 v13; // x9
  unsigned int v14; // w8
  __int64 v15; // x11
  __int64 v16; // x9
  unsigned int v17; // w8
  __int64 v18; // x11
  __int64 v19; // x9
  unsigned int v20; // w8
  __int64 v21; // x11
  __int64 v22; // x9
  unsigned int v23; // w8
  __int64 v24; // x11
  __int64 v25; // x9
  unsigned int v26; // w8
  __int64 v27; // x11
  __int64 v28; // x9
  unsigned int v29; // w8
  __int64 v30; // x11
  __int64 v31; // x9
  unsigned int v32; // w8
  __int64 v33; // x11

  v2 = (_DWORD *)(a1 + 20480);
  *(_DWORD *)(a1 + 56) = 0;
  result = dp_tx_deinit_bank_profiles();
  if ( v2[537] )
  {
    v4 = *(_QWORD *)(a1 + 22632);
    v5 = 0;
    do
    {
      v6 = v4 + 24LL * (int)v5++;
      *(_QWORD *)(*(_QWORD *)(a1 + 22608) + 24LL * *(unsigned int *)(v6 + 16)) = 0;
    }
    while ( v5 < v2[537] );
  }
  if ( v2[557] )
  {
    v7 = *(_QWORD *)(a1 + 22712);
    v8 = 0;
    do
    {
      v9 = v7 + 24LL * (int)v8++;
      *(_QWORD *)(*(_QWORD *)(a1 + 22608) + 24LL * *(unsigned int *)(v9 + 16)) = 0;
    }
    while ( v8 < v2[557] );
  }
  if ( v2[577] )
  {
    v10 = *(_QWORD *)(a1 + 22792);
    v11 = 0;
    do
    {
      v12 = v10 + 24LL * (int)v11++;
      *(_QWORD *)(*(_QWORD *)(a1 + 22608) + 24LL * *(unsigned int *)(v12 + 16)) = 0;
    }
    while ( v11 < v2[577] );
  }
  if ( v2[597] )
  {
    v13 = *(_QWORD *)(a1 + 22872);
    v14 = 0;
    do
    {
      v15 = v13 + 24LL * (int)v14++;
      *(_QWORD *)(*(_QWORD *)(a1 + 22608) + 24LL * *(unsigned int *)(v15 + 16)) = 0;
    }
    while ( v14 < v2[597] );
  }
  if ( v2[617] )
  {
    v16 = *(_QWORD *)(a1 + 22952);
    v17 = 0;
    do
    {
      v18 = v16 + 24LL * (int)v17++;
      *(_QWORD *)(*(_QWORD *)(a1 + 22608) + 24LL * *(unsigned int *)(v18 + 16)) = 0;
    }
    while ( v17 < v2[617] );
  }
  if ( v2[637] )
  {
    v19 = *(_QWORD *)(a1 + 23032);
    v20 = 0;
    do
    {
      v21 = v19 + 24LL * (int)v20++;
      *(_QWORD *)(*(_QWORD *)(a1 + 22608) + 24LL * *(unsigned int *)(v21 + 16)) = 0;
    }
    while ( v20 < v2[637] );
  }
  if ( v2[657] )
  {
    v22 = *(_QWORD *)(a1 + 23112);
    v23 = 0;
    do
    {
      v24 = v22 + 24LL * (int)v23++;
      *(_QWORD *)(*(_QWORD *)(a1 + 22608) + 24LL * *(unsigned int *)(v24 + 16)) = 0;
    }
    while ( v23 < v2[657] );
  }
  if ( v2[677] )
  {
    v25 = *(_QWORD *)(a1 + 23192);
    v26 = 0;
    do
    {
      v27 = v25 + 24LL * (int)v26++;
      *(_QWORD *)(*(_QWORD *)(a1 + 22608) + 24LL * *(unsigned int *)(v27 + 16)) = 0;
    }
    while ( v26 < v2[677] );
  }
  if ( v2[697] )
  {
    v28 = *(_QWORD *)(a1 + 23272);
    v29 = 0;
    do
    {
      v30 = v28 + 24LL * (int)v29++;
      *(_QWORD *)(*(_QWORD *)(a1 + 22608) + 24LL * *(unsigned int *)(v30 + 16)) = 0;
    }
    while ( v29 < v2[697] );
  }
  if ( v2[717] )
  {
    v31 = *(_QWORD *)(a1 + 23352);
    v32 = 0;
    do
    {
      v33 = v31 + 24LL * (int)v32++;
      *(_QWORD *)(*(_QWORD *)(a1 + 22608) + 24LL * *(unsigned int *)(v33 + 16)) = 0;
    }
    while ( v32 < v2[717] );
  }
  return result;
}
