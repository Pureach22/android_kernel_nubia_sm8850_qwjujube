__int64 __fastcall ieee80211_request_ibss_scan(unsigned __int64 a1, __int64 *a2, char a3, __int64 a4, int a5)
{
  _QWORD *v5; // x8
  int v7; // w10
  int v8; // w9
  __int64 v9; // x11
  __int64 v10; // x12
  __int64 v11; // x10
  __int64 v12; // x11
  __int64 v13; // x11
  __int64 v14; // x11
  __int64 v15; // x12
  __int64 v16; // x13
  __int64 v17; // x14
  __int64 v18; // x10
  __int64 v19; // x12
  __int64 v20; // x13
  _QWORD *v21; // x9

  v5 = *(_QWORD **)(a1 + 1616);
  if ( v5[594] )
    return 4294967280LL;
  if ( !a4 )
  {
    v11 = 0;
    v8 = 0;
    do
    {
      if ( v11 != 3 )
      {
        v12 = *(_QWORD *)(v5[9] + 8 * v11 + 328);
        if ( v12 )
        {
          v13 = *(unsigned int *)(v12 + 20);
          if ( (int)v13 >= 1 )
          {
            v14 = v13 << 6;
            v15 = 0;
            do
            {
              v16 = **(_QWORD **)(v5[9] + 8 * v11 + 328) + v15;
              if ( (*(_BYTE *)(v16 + 12) & 3) == 0 )
              {
                v17 = v5[593] + 8LL * v8++;
                *(_QWORD *)(v17 + 160) = v16;
              }
              v15 += 64;
            }
            while ( v14 != v15 );
          }
        }
      }
      ++v11;
    }
    while ( v11 != 6 );
    if ( !v8 )
      goto LABEL_22;
LABEL_21:
    *(_DWORD *)(v5[593] + 12LL) = v8;
    *(_QWORD *)v5[593] = v5 + 588;
    *(_DWORD *)(v5[593] + 8LL) = 1;
    v18 = a2[3];
    v19 = *a2;
    v20 = a2[1];
    v21 = *(_QWORD **)v5[593];
    v21[2] = a2[2];
    v21[3] = v18;
    *v21 = v19;
    v21[1] = v20;
    *(_BYTE *)(*(_QWORD *)v5[593] + 32LL) = a3;
    return _ieee80211_start_scan(a1, *(_QWORD *)(*(_QWORD *)(a1 + 1616) + 4744LL));
  }
  if ( a5 )
  {
    v7 = 0;
    v8 = 0;
    do
    {
      v9 = *(_QWORD *)(a4 + 8LL * v7);
      if ( (*(_BYTE *)(v9 + 12) & 3) == 0 )
      {
        v10 = v5[593] + 8LL * v8++;
        *(_QWORD *)(v10 + 160) = v9;
      }
      ++v7;
    }
    while ( a5 != v7 );
    if ( v8 )
      goto LABEL_21;
  }
LABEL_22:
  __break(0x800u);
  return 4294967280LL;
}
