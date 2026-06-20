__int64 __fastcall dp_txrx_get_peer_extd_stats_param(__int64 *a1, int a2, _WORD *a3)
{
  __int64 *v3; // x8
  __int64 v4; // x8
  __int64 result; // x0
  int v6; // w8

  if ( *((_DWORD *)a1 + 102) == 1 )
  {
    v3 = (__int64 *)a1[52];
    if ( v3 )
    {
      v4 = *v3;
      if ( v4 )
        goto LABEL_4;
      return 16;
    }
  }
  v4 = *a1;
  if ( !*a1 )
    return 16;
LABEL_4:
  result = 16;
  if ( a2 > 10 )
  {
    if ( a2 > 13 )
    {
      if ( a2 != 14 )
      {
        if ( a2 != 15 )
          return result;
        result = 0;
        v6 = *(unsigned __int8 *)(v4 + 5848);
        goto LABEL_26;
      }
      v6 = *(_DWORD *)(v4 + 5832);
    }
    else if ( a2 == 11 )
    {
      v6 = *(_DWORD *)(v4 + 5816);
    }
    else
    {
      if ( a2 != 12 )
        return result;
      v6 = *(_DWORD *)(v4 + 5828);
    }
  }
  else if ( a2 > 6 )
  {
    if ( a2 == 7 )
    {
      *a3 = *(_WORD *)(v4 + 3840);
      return 0;
    }
    if ( a2 != 10 )
      return result;
    v6 = *(_DWORD *)(v4 + 5812);
  }
  else if ( a2 == 5 )
  {
    v6 = *(_DWORD *)(v4 + 3804);
  }
  else
  {
    if ( a2 != 6 )
      return result;
    v6 = *(_DWORD *)(v4 + 3808);
  }
  result = 0;
LABEL_26:
  *(_DWORD *)a3 = v6;
  return result;
}
