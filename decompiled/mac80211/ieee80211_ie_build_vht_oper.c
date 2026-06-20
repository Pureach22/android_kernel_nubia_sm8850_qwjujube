_BYTE *__fastcall ieee80211_ie_build_vht_oper(__int64 a1, __int64 a2, _DWORD *a3)
{
  int v5; // w8
  char v6; // w0
  _BYTE *result; // x0
  int v8; // w8
  char v9; // w8
  char v10; // w8

  *(_WORD *)a1 = 1472;
  *(_BYTE *)(a1 + 3) = ieee80211_freq_khz_to_channel((unsigned int)(1000 * a3[3]));
  v5 = a3[4];
  if ( v5 )
    v6 = ieee80211_freq_khz_to_channel((unsigned int)(1000 * v5));
  else
    v6 = 0;
  *(_BYTE *)(a1 + 4) = v6;
  result = (_BYTE *)(a1 + 2);
  v8 = a3[2];
  if ( v8 > 4 )
  {
    if ( v8 == 13 )
    {
      __break(0x800u);
      return result;
    }
    if ( v8 == 5 )
    {
      v9 = *(_BYTE *)(a1 + 3);
      *(_BYTE *)(a1 + 2) = 1;
      *(_BYTE *)(a1 + 4) = v9;
      if ( *(_DWORD *)(*(_QWORD *)a3 + 4LL) >= a3[3] )
        v10 = v9 + 8;
      else
        v10 = v9 - 8;
      *(_BYTE *)(a1 + 3) = v10;
      goto LABEL_16;
    }
    goto LABEL_12;
  }
  if ( v8 != 3 && v8 != 4 )
  {
LABEL_12:
    *result = 0;
    goto LABEL_16;
  }
  *result = 1;
LABEL_16:
  *(_WORD *)(a1 + 5) = -1;
  return (_BYTE *)(a1 + 7);
}
