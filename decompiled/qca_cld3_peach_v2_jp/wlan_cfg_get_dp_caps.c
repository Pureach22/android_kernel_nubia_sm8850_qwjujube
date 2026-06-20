bool __fastcall wlan_cfg_get_dp_caps(_BYTE *a1, int a2)
{
  char v2; // w8

  v2 = 0;
  if ( a2 <= 3 )
  {
    if ( a2 <= 1 )
    {
      if ( !a2 )
        return a1[529] & 1;
      if ( a2 == 1 )
        return a1[530] & 1;
      return v2 & 1;
    }
    if ( a2 == 2 )
      return a1[531] & 1;
    else
      return a1[532] & 1;
  }
  else
  {
    if ( a2 > 5 )
    {
      switch ( a2 )
      {
        case 6:
          return a1[543] & 1;
        case 7:
          v2 = a1[544];
          break;
        case 8:
          return a1[812] != 0;
      }
      return v2 & 1;
    }
    if ( a2 == 4 )
      return a1[541] & 1;
    else
      return a1[542] & 1;
  }
}
