__int64 __fastcall ieee80211_set_bitrate_flags(__int64 result)
{
  __int64 v1; // x8
  __int64 v2; // x10
  __int64 v3; // x12
  int v4; // w13
  int v5; // w16
  __int64 v6; // x13
  __int64 v7; // x14
  int v8; // w15
  __int64 v9; // x17
  __int64 v10; // x14
  __int64 v11; // x15
  int v12; // w13
  int v13; // w17
  __int64 v14; // x16
  unsigned int v15; // w17
  bool v16; // zf

  v1 = 0;
  v2 = result + 328;
  do
  {
    v3 = *(_QWORD *)(v2 + 8 * v1);
    if ( !v3 )
      goto LABEL_3;
    v4 = *(_DWORD *)(v3 + 16);
    if ( v4 > 2 )
    {
      if ( v4 != 5 )
      {
        if ( v4 == 4 )
        {
          if ( (~*(unsigned __int8 *)(v3 + 79) & 3) == 0 )
            goto LABEL_47;
          goto LABEL_3;
        }
        if ( v4 != 3 )
          goto LABEL_47;
        goto LABEL_16;
      }
    }
    else if ( v4 )
    {
      if ( v4 != 1 )
      {
        if ( v4 == 2 )
        {
          if ( (*(_BYTE *)(v3 + 30) & 1) == 0 )
            __break(0x800u);
          if ( (~*(unsigned __int8 *)(v3 + 33) & 0x1E) == 0 )
            goto LABEL_3;
        }
        goto LABEL_47;
      }
LABEL_16:
      v5 = *(_DWORD *)(v3 + 24);
      if ( v5 >= 1 )
      {
        v6 = 0;
        v7 = 0;
        v8 = 3;
        do
        {
          v9 = *(_QWORD *)(v3 + 8);
          result = *(unsigned __int16 *)(v9 + v6 + 4);
          if ( (_DWORD)result == 60 || (_DWORD)result == 240 || (_DWORD)result == 120 )
          {
            --v8;
            *(_DWORD *)(v9 + v6) |= 2u;
            v5 = *(_DWORD *)(v3 + 24);
          }
          ++v7;
          v6 += 12;
        }
        while ( v7 < v5 );
        if ( !v8 )
          goto LABEL_3;
      }
LABEL_47:
      __break(0x800u);
      goto LABEL_3;
    }
    if ( *(int *)(v3 + 24) < 1 )
      goto LABEL_47;
    v10 = 0;
    v11 = 0;
    v12 = 7;
    do
    {
      v14 = *(_QWORD *)(v3 + 8);
      v15 = *(unsigned __int16 *)(v14 + v10 + 4);
      if ( v15 <= 0x3B )
      {
        v16 = v15 == 10 || v15 == 20;
        if ( v16 || v15 == 55 )
        {
LABEL_28:
          --v12;
          v13 = *(_DWORD *)(v14 + v10) | 0xC;
          goto LABEL_29;
        }
      }
      else
      {
        if ( *(unsigned __int16 *)(v14 + v10 + 4) > 0x77u )
        {
          if ( v15 != 120 && v15 != 240 )
            goto LABEL_35;
LABEL_34:
          --v12;
          *(_DWORD *)(v14 + v10) |= 8u;
          v14 = *(_QWORD *)(v3 + 8);
          goto LABEL_35;
        }
        if ( v15 == 60 )
          goto LABEL_34;
        if ( v15 == 110 )
          goto LABEL_28;
      }
LABEL_35:
      v13 = *(_DWORD *)(v14 + v10) | 0x10;
LABEL_29:
      *(_DWORD *)(v14 + v10) = v13;
      ++v11;
      v10 += 12;
    }
    while ( v11 < *(int *)(v3 + 24) );
    if ( v12 && v12 != 3 )
      goto LABEL_47;
LABEL_3:
    ++v1;
  }
  while ( v1 != 6 );
  return result;
}
