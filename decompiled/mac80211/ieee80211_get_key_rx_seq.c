__int64 __fastcall ieee80211_get_key_rx_seq(__int64 result, unsigned int a2, __int64 a3)
{
  int v3; // w8
  unsigned __int16 v4; // w9
  __int64 v5; // x8
  __int16 v6; // w9
  int v7; // w8

  v3 = *(_DWORD *)(result + 8);
  if ( v3 <= 1027081 )
  {
    if ( v3 > 1027079 )
    {
      if ( a2 - 16 <= 0xFFFFFFEE )
        goto LABEL_23;
      goto LABEL_18;
    }
    if ( v3 == 1027074 )
    {
      if ( a2 < 0x10 )
      {
        *(_DWORD *)a3 = *(_DWORD *)(result + 28LL * a2 - 444);
        *(_WORD *)(a3 + 4) = *(_WORD *)(result + 28LL * a2 - 440);
        return result;
      }
      goto LABEL_23;
    }
    if ( v3 != 1027076 )
    {
      v4 = -21498;
      goto LABEL_9;
    }
    goto LABEL_17;
  }
  if ( (unsigned int)(v3 - 1027083) < 2 )
  {
    if ( !a2 )
    {
LABEL_16:
      v5 = result - 488;
LABEL_20:
      v6 = *(_WORD *)(v5 + 4);
      v7 = *(_DWORD *)v5;
      *(_WORD *)(a3 + 4) = v6;
      *(_DWORD *)a3 = v7;
      return result;
    }
    goto LABEL_23;
  }
  if ( v3 == 1027082 )
  {
LABEL_17:
    if ( a2 - 16 > 0xFFFFFFEE )
    {
LABEL_18:
      v5 = result + 6LL * a2 - 488;
      if ( (a2 & 0x80000000) != 0 )
        v5 = result - 392;
      goto LABEL_20;
    }
LABEL_23:
    __break(0x800u);
    return result;
  }
  v4 = -21491;
LABEL_9:
  if ( v3 == (v4 | 0xF0000) )
  {
    if ( a2 )
      goto LABEL_23;
    goto LABEL_16;
  }
  return result;
}
