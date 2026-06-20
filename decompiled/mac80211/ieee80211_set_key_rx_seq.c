__int64 __fastcall ieee80211_set_key_rx_seq(__int64 result, unsigned int a2, int *a3)
{
  int v3; // w8
  unsigned __int16 v4; // w9
  int v5; // w10
  __int64 v6; // x9
  int v7; // w11
  __int64 v8; // x8
  __int64 v9; // x8

  v3 = *(_DWORD *)(result + 8);
  if ( v3 > 1027081 )
  {
    if ( (unsigned int)(v3 - 1027083) < 2 )
    {
      if ( !a2 )
        goto LABEL_15;
      goto LABEL_22;
    }
    if ( v3 != 1027082 )
    {
      v4 = -21491;
      goto LABEL_9;
    }
LABEL_16:
    if ( a2 - 16 > 0xFFFFFFEE )
      goto LABEL_17;
LABEL_22:
    __break(0x800u);
    return result;
  }
  if ( v3 <= 1027079 )
  {
    if ( v3 == 1027074 )
    {
      if ( a2 < 0x10 )
      {
        v9 = result + 28LL * a2 - 464;
        *(_DWORD *)(v9 + 20) = *a3;
        *(_WORD *)(v9 + 24) = *((_WORD *)a3 + 2);
        return result;
      }
      goto LABEL_22;
    }
    if ( v3 != 1027076 )
    {
      v4 = -21498;
LABEL_9:
      if ( v3 != (v4 | 0xF0000) || a2 )
        goto LABEL_22;
LABEL_15:
      v5 = *a3;
      v6 = result - 488;
      *(_WORD *)(v6 + 4) = *((_WORD *)a3 + 2);
      *(_DWORD *)v6 = v5;
      return result;
    }
    goto LABEL_16;
  }
  if ( a2 - 16 <= 0xFFFFFFEE )
    goto LABEL_22;
LABEL_17:
  v7 = *a3;
  v8 = result + 6LL * a2 - 488;
  if ( (a2 & 0x80000000) != 0 )
    v8 = result - 392;
  *(_WORD *)(v8 + 4) = *((_WORD *)a3 + 2);
  *(_DWORD *)v8 = v7;
  return result;
}
