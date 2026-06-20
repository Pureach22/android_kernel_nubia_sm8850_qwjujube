__int64 __fastcall ieee80211_ie_build_eht_oper(__int64 a1, _DWORD *a2, __int64 a3)
{
  char v5; // w8
  int v6; // w8
  char v7; // w0
  int v8; // w8
  char v9; // w8
  char v10; // w8
  char v11; // w8
  char v12; // w8
  char v13; // w8

  *(_WORD *)a1 = 2559;
  *(_BYTE *)(a1 + 2) = 106;
  v5 = *(_BYTE *)(a1 + 3) | 1;
  *(_DWORD *)(a1 + 4) = *(_DWORD *)(a3 + 12);
  *(_BYTE *)(a1 + 3) = v5;
  *(_BYTE *)(a1 + 9) = ieee80211_freq_khz_to_channel((unsigned int)(1000 * a2[3]));
  v6 = a2[4];
  if ( v6 )
    v7 = ieee80211_freq_khz_to_channel((unsigned int)(1000 * v6));
  else
    v7 = 0;
  *(_BYTE *)(a1 + 10) = v7;
  v8 = a2[2];
  if ( v8 <= 3 )
  {
    if ( v8 == 2 )
    {
      v11 = 1;
      goto LABEL_22;
    }
    if ( v8 == 3 )
    {
      v11 = 2;
      goto LABEL_22;
    }
    goto LABEL_17;
  }
  if ( v8 == 4 )
  {
    v11 = 3;
    goto LABEL_22;
  }
  if ( v8 != 5 )
  {
    if ( v8 == 13 )
    {
      v9 = *(_BYTE *)(a1 + 9);
      *(_BYTE *)(a1 + 10) = v9;
      if ( *(_DWORD *)(*(_QWORD *)a2 + 4LL) >= a2[3] )
        v10 = v9 + 16;
      else
        v10 = v9 - 16;
      *(_BYTE *)(a1 + 9) = v10;
      v11 = 4;
      goto LABEL_22;
    }
LABEL_17:
    v11 = 0;
    goto LABEL_22;
  }
  v12 = *(_BYTE *)(a1 + 9);
  *(_BYTE *)(a1 + 10) = v12;
  if ( *(_DWORD *)(*(_QWORD *)a2 + 4LL) >= a2[3] )
    v13 = v12 + 8;
  else
    v13 = v12 - 8;
  *(_BYTE *)(a1 + 9) = v13;
  v11 = 3;
LABEL_22:
  *(_BYTE *)(a1 + 8) = v11;
  return a1 + 11;
}
