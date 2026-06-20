bool __fastcall cfg80211_valid_key_idx(__int64 a1, int a2, char a3)
{
  unsigned int v3; // w8
  unsigned __int64 v4; // x8
  __int64 v5; // x9
  bool v6; // w14
  unsigned int v7; // w15
  bool v8; // cc
  int v9; // w15

  if ( (a3 & 1) != 0 )
    goto LABEL_2;
  if ( (*(_BYTE *)(a1 + 1109) & 0x42) != 0 )
  {
    v3 = 7;
  }
  else
  {
    v4 = *(unsigned int *)(a1 + 1148);
    if ( (int)v4 < 1 )
    {
LABEL_2:
      v3 = 3;
      return a2 >= 0 && v3 >= a2;
    }
    v5 = 0;
    v6 = 1;
    do
    {
      v7 = *(_DWORD *)(*(_QWORD *)(a1 + 1152) + 4 * v5) - 1027078;
      v8 = v7 > 7;
      v9 = (1 << v7) & 0xE1;
      if ( !v8 && v9 != 0 )
        break;
      v6 = ++v5 < v4;
    }
    while ( v4 != v5 );
    if ( v6 )
      v3 = 5;
    else
      v3 = 3;
  }
  return a2 >= 0 && v3 >= a2;
}
