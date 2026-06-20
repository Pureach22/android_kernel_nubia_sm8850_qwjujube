__int64 __fastcall nl80211_parse_mcast_rate(_QWORD *a1, _DWORD *a2, int a3)
{
  __int64 v3; // x10
  __int64 v4; // x8
  __int64 v5; // x9
  unsigned __int16 *v6; // x10
  int v7; // t1
  unsigned int v8; // w8
  __int64 v9; // x11
  __int64 v10; // x9
  __int64 v11; // x10
  unsigned __int16 *v12; // x11
  int v13; // t1
  __int64 v14; // x11
  __int64 v15; // x9
  __int64 v16; // x10
  unsigned __int16 *v17; // x11
  int v18; // t1
  __int64 v19; // x11
  __int64 v20; // x9
  __int64 v21; // x10
  unsigned __int16 *v22; // x11
  int v23; // t1
  __int64 v24; // x11
  __int64 v25; // x9
  __int64 v26; // x10
  unsigned __int16 *v27; // x11
  int v28; // t1
  __int64 v29; // x11
  __int64 v30; // x9
  __int64 v31; // x10
  unsigned __int16 *v32; // x11
  int v33; // t1

  v3 = a1[165];
  if ( !v3 || (v4 = *(unsigned int *)(v3 + 24), (int)v4 < 1) )
  {
LABEL_6:
    v8 = 0;
    v9 = a1[166];
    if ( !v9 )
      goto LABEL_15;
    goto LABEL_7;
  }
  v5 = 0;
  v6 = (unsigned __int16 *)(*(_QWORD *)(v3 + 8) + 4LL);
  while ( 1 )
  {
    v7 = *v6;
    v6 += 6;
    if ( v7 == a3 )
      break;
    if ( v4 == ++v5 )
      goto LABEL_6;
  }
  *a2 = v5 + 1;
  v8 = 1;
  v9 = a1[166];
  if ( v9 )
  {
LABEL_7:
    v10 = *(unsigned int *)(v9 + 24);
    if ( (int)v10 >= 1 )
    {
      v11 = 0;
      v12 = (unsigned __int16 *)(*(_QWORD *)(v9 + 8) + 4LL);
      while ( 1 )
      {
        v13 = *v12;
        v12 += 6;
        if ( v13 == a3 )
          break;
        if ( v10 == ++v11 )
          goto LABEL_15;
      }
      a2[1] = v11 + 1;
      v8 = 1;
    }
  }
LABEL_15:
  v14 = a1[167];
  if ( !v14 || (v15 = *(unsigned int *)(v14 + 24), (int)v15 < 1) )
  {
LABEL_20:
    v19 = a1[168];
    if ( !v19 )
      goto LABEL_29;
    goto LABEL_21;
  }
  v16 = 0;
  v17 = (unsigned __int16 *)(*(_QWORD *)(v14 + 8) + 4LL);
  while ( 1 )
  {
    v18 = *v17;
    v17 += 6;
    if ( v18 == a3 )
      break;
    if ( v15 == ++v16 )
      goto LABEL_20;
  }
  a2[2] = v16 + 1;
  v8 = 1;
  v19 = a1[168];
  if ( v19 )
  {
LABEL_21:
    v20 = *(unsigned int *)(v19 + 24);
    if ( (int)v20 >= 1 )
    {
      v21 = 0;
      v22 = (unsigned __int16 *)(*(_QWORD *)(v19 + 8) + 4LL);
      while ( 1 )
      {
        v23 = *v22;
        v22 += 6;
        if ( v23 == a3 )
          break;
        if ( v20 == ++v21 )
          goto LABEL_29;
      }
      a2[3] = v21 + 1;
      v8 = 1;
    }
  }
LABEL_29:
  v24 = a1[169];
  if ( v24 && (v25 = *(unsigned int *)(v24 + 24), (int)v25 >= 1) )
  {
    v26 = 0;
    v27 = (unsigned __int16 *)(*(_QWORD *)(v24 + 8) + 4LL);
    while ( 1 )
    {
      v28 = *v27;
      v27 += 6;
      if ( v28 == a3 )
        break;
      if ( v25 == ++v26 )
        goto LABEL_34;
    }
    a2[4] = v26 + 1;
    v8 = 1;
    v29 = a1[170];
    if ( !v29 )
      return v8;
  }
  else
  {
LABEL_34:
    v29 = a1[170];
    if ( !v29 )
      return v8;
  }
  v30 = *(unsigned int *)(v29 + 24);
  if ( (int)v30 < 1 )
    return v8;
  v31 = 0;
  v32 = (unsigned __int16 *)(*(_QWORD *)(v29 + 8) + 4LL);
  while ( 1 )
  {
    v33 = *v32;
    v32 += 6;
    if ( v33 == a3 )
      break;
    if ( v30 == ++v31 )
      return v8;
  }
  a2[5] = v31 + 1;
  return 1;
}
