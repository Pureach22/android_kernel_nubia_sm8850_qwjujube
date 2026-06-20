__int64 __fastcall dp_txrx_get_peer_extd_stats_param(__int64 *a1, int a2, _WORD *a3)
{
  __int64 v3; // x8
  __int64 result; // x0
  int v5; // w8

  v3 = *a1;
  if ( !*a1 )
    return 16;
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
        v5 = *(unsigned __int8 *)(v3 + 5192);
        goto LABEL_23;
      }
      v5 = *(_DWORD *)(v3 + 5180);
    }
    else if ( a2 == 11 )
    {
      v5 = *(_DWORD *)(v3 + 5164);
    }
    else
    {
      if ( a2 != 12 )
        return result;
      v5 = *(_DWORD *)(v3 + 5176);
    }
  }
  else if ( a2 > 6 )
  {
    if ( a2 == 7 )
    {
      *a3 = *(_WORD *)(v3 + 3672);
      return 0;
    }
    if ( a2 != 10 )
      return result;
    v5 = *(_DWORD *)(v3 + 5160);
  }
  else if ( a2 == 5 )
  {
    v5 = *(_DWORD *)(v3 + 3632);
  }
  else
  {
    if ( a2 != 6 )
      return result;
    v5 = *(_DWORD *)(v3 + 3636);
  }
  result = 0;
LABEL_23:
  *(_DWORD *)a3 = v5;
  return result;
}
