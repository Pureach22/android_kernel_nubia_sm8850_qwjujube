bool __fastcall cfg80211_beaconing_iface_active(__int64 a1)
{
  int v1; // w8
  unsigned int v3; // w10
  _DWORD *v4; // x9
  bool v5; // cf

  v1 = *(_DWORD *)(a1 + 8);
  if ( v1 <= 4 )
  {
    switch ( v1 )
    {
      case 0:
        goto LABEL_21;
      case 1:
        if ( *(_BYTE *)(a1 + 356) )
          return 1;
        break;
      case 3:
LABEL_13:
        v3 = 0;
        v4 = (_DWORD *)(a1 + 400);
        while ( *(_WORD *)(a1 + 1472) && (((unsigned __int64)*(unsigned __int16 *)(a1 + 1472) >> v3) & 1) == 0 || !*v4 )
        {
          if ( *(_WORD *)(a1 + 1472) )
          {
            v5 = v3++ >= 0xE;
            v4 += 18;
            if ( !v5 )
              continue;
          }
          return 0;
        }
        return 1;
    }
  }
  else
  {
    if ( v1 <= 8 )
    {
      if ( v1 != 5 )
        return v1 == 7 && *(_BYTE *)(a1 + 384);
LABEL_21:
      __break(0x800u);
      return 0;
    }
    if ( v1 == 13 )
      goto LABEL_21;
    if ( v1 == 9 )
      goto LABEL_13;
  }
  return 0;
}
