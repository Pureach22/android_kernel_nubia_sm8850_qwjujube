__int64 __fastcall ieee80211_ie_build_ht_oper(__int64 a1, __int64 a2, _DWORD *a3, __int16 a4, char a5)
{
  __int64 result; // x0
  int v11; // w8
  char v12; // w8
  __int64 v13; // x9

  *(_WORD *)a1 = 5693;
  *(_BYTE *)(a1 + 2) = ieee80211_freq_khz_to_channel((unsigned int)(1000 * *(_DWORD *)(*(_QWORD *)a3 + 4LL)));
  result = a1 + 2;
  v11 = a3[2];
  if ( (unsigned int)(v11 - 2) < 4 )
  {
    if ( a3[3] <= *(_DWORD *)(*(_QWORD *)a3 + 4LL) )
      v12 = 3;
    else
      v12 = 1;
    *(_BYTE *)(a1 + 3) = v12;
    if ( (*(_WORD *)a2 & 2) == 0 )
      goto LABEL_12;
LABEL_10:
    if ( a3[2] >= 2u )
    {
      v12 |= 4u;
      *(_BYTE *)(a1 + 3) = v12;
    }
    goto LABEL_12;
  }
  if ( v11 == 13 )
  {
    __break(0x800u);
    return result;
  }
  v12 = 0;
  *(_BYTE *)(a1 + 3) = 0;
  if ( (*(_WORD *)a2 & 2) != 0 )
    goto LABEL_10;
LABEL_12:
  if ( (a5 & 1) != 0 )
    *(_BYTE *)(a1 + 3) = v12 | 8;
  *(_WORD *)(a1 + 4) = a4;
  *(_WORD *)(a1 + 6) = 0;
  *(_QWORD *)(a1 + 8) = 0;
  *(_QWORD *)(a1 + 16) = 0;
  v13 = *(_QWORD *)(a2 + 5);
  *(_WORD *)(a1 + 16) = *(_WORD *)(a2 + 13);
  *(_QWORD *)(a1 + 8) = v13;
  return a1 + 24;
}
