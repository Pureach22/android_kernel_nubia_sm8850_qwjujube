__int64 __fastcall ieee80211_ie_build_he_oper(__int64 a1, int *a2)
{
  int v3; // w9
  char v4; // w8
  int v5; // w8
  int v7; // w8
  char v8; // w0
  int v10; // w8
  char v11; // w9
  char v12; // w8

  v3 = **(_DWORD **)a2;
  *(_BYTE *)a1 = -1;
  if ( v3 == 3 )
    v4 = 12;
  else
    v4 = 7;
  *(_BYTE *)(a1 + 2) = 36;
  *(_BYTE *)(a1 + 1) = v4;
  if ( **(_DWORD **)a2 == 3 )
    v5 = -2147270672;
  else
    v5 = -2147401744;
  *(_DWORD *)(a1 + 3) = v5;
  *(_WORD *)(a1 + 7) = -1;
  if ( **(_DWORD **)a2 != 3 )
    return a1 + 9;
  *(_BYTE *)(a1 + 13) = 6;
  *(_BYTE *)(a1 + 9) = ieee80211_freq_khz_to_channel((unsigned int)(1000 * *(_DWORD *)(*(_QWORD *)a2 + 4LL)));
  *(_BYTE *)(a1 + 11) = ieee80211_freq_khz_to_channel((unsigned int)(1000 * a2[3]));
  v7 = a2[4];
  if ( v7 )
    v8 = ieee80211_freq_khz_to_channel((unsigned int)(1000 * v7));
  else
    v8 = 0;
  *(_BYTE *)(a1 + 12) = v8;
  v10 = a2[2];
  if ( v10 <= 3 )
  {
    if ( v10 == 2 )
    {
      *(_BYTE *)(a1 + 10) = 1;
      return a1 + 14;
    }
    if ( v10 == 3 )
    {
      *(_BYTE *)(a1 + 10) = 2;
      return a1 + 14;
    }
LABEL_26:
    *(_BYTE *)(a1 + 10) = 0;
    return a1 + 14;
  }
  if ( v10 == 4 )
  {
LABEL_24:
    *(_BYTE *)(a1 + 10) = 3;
    return a1 + 14;
  }
  if ( v10 == 5 )
  {
    v11 = *(_BYTE *)(a1 + 11);
    *(_BYTE *)(a1 + 10) = 3;
    *(_BYTE *)(a1 + 12) = v11;
    if ( *(_DWORD *)(*(_QWORD *)a2 + 4LL) < (unsigned int)a2[3] )
      v12 = -8;
    else
      v12 = 8;
    *(_BYTE *)(a1 + 11) = v11 + v12;
    goto LABEL_24;
  }
  if ( v10 != 13 )
    goto LABEL_26;
  __break(0x800u);
  return a1 + 14;
}
