__int64 __fastcall ieee80211_is_radar_required(__int64 a1)
{
  _QWORD *i; // x8
  __int64 v2; // x10
  __int64 v3; // x10
  __int64 v4; // x10
  __int64 v5; // x10
  __int64 v6; // x10
  __int64 v7; // x10
  __int64 v8; // x10
  __int64 v9; // x10
  __int64 v10; // x10
  __int64 v11; // x10
  __int64 v12; // x10
  __int64 v13; // x10
  __int64 v14; // x10
  __int64 v15; // x10
  __int64 v16; // x10

  for ( i = *(_QWORD **)(a1 + 4616); i != (_QWORD *)(a1 + 4616); i = (_QWORD *)*i )
  {
    if ( (i[204] & 1) != 0 )
    {
      v2 = i[571];
      if ( v2 )
      {
        if ( (*(_BYTE *)(v2 + 456) & 1) != 0 )
          return 1;
      }
      v3 = i[572];
      if ( v3 )
      {
        if ( (*(_BYTE *)(v3 + 456) & 1) != 0 )
          return 1;
      }
      v4 = i[573];
      if ( v4 )
      {
        if ( (*(_BYTE *)(v4 + 456) & 1) != 0 )
          return 1;
      }
      v5 = i[574];
      if ( v5 )
      {
        if ( (*(_BYTE *)(v5 + 456) & 1) != 0 )
          return 1;
      }
      v6 = i[575];
      if ( v6 )
      {
        if ( (*(_BYTE *)(v6 + 456) & 1) != 0 )
          return 1;
      }
      v7 = i[576];
      if ( v7 )
      {
        if ( (*(_BYTE *)(v7 + 456) & 1) != 0 )
          return 1;
      }
      v8 = i[577];
      if ( v8 )
      {
        if ( (*(_BYTE *)(v8 + 456) & 1) != 0 )
          return 1;
      }
      v9 = i[578];
      if ( v9 )
      {
        if ( (*(_BYTE *)(v9 + 456) & 1) != 0 )
          return 1;
      }
      v10 = i[579];
      if ( v10 )
      {
        if ( (*(_BYTE *)(v10 + 456) & 1) != 0 )
          return 1;
      }
      v11 = i[580];
      if ( v11 )
      {
        if ( (*(_BYTE *)(v11 + 456) & 1) != 0 )
          return 1;
      }
      v12 = i[581];
      if ( v12 )
      {
        if ( (*(_BYTE *)(v12 + 456) & 1) != 0 )
          return 1;
      }
      v13 = i[582];
      if ( v13 )
      {
        if ( (*(_BYTE *)(v13 + 456) & 1) != 0 )
          return 1;
      }
      v14 = i[583];
      if ( v14 )
      {
        if ( (*(_BYTE *)(v14 + 456) & 1) != 0 )
          return 1;
      }
      v15 = i[584];
      if ( v15 )
      {
        if ( (*(_BYTE *)(v15 + 456) & 1) != 0 )
          return 1;
      }
      v16 = i[585];
      if ( v16 )
      {
        if ( (*(_BYTE *)(v16 + 456) & 1) != 0 )
          return 1;
      }
    }
  }
  return 0;
}
