__int64 __fastcall wlan_crypto_rsn_suite_to_keymgmt(int *a1)
{
  int v1; // w8

  v1 = *a1;
  if ( *a1 <= 195825407 )
  {
    if ( v1 <= 61607679 )
    {
      if ( v1 <= 28053247 )
      {
        if ( v1 == 9846784 )
          return 14;
        if ( v1 == 26898256 )
          return 15;
      }
      else
      {
        switch ( v1 )
        {
          case 28053248:
            return 0;
          case 43675472:
            return 23;
          case 44830464:
            return 1;
        }
      }
    }
    else if ( v1 > 111939327 )
    {
      switch ( v1 )
      {
        case 111939328:
          return 8;
        case 145493760:
          return 10;
        case 162270976:
          return 11;
      }
    }
    else
    {
      switch ( v1 )
      {
        case 61607680:
          return 5;
        case 78384896:
          return 6;
        case 95162112:
          return 7;
      }
    }
  }
  else if ( v1 > 296488703 )
  {
    if ( v1 > 346820351 )
    {
      switch ( v1 )
      {
        case 346820352:
          return 26;
        case 413929216:
          return 27;
        case 430706432:
          return 28;
      }
    }
    else
    {
      switch ( v1 )
      {
        case 296488704:
          return 21;
        case 313265920:
          return 22;
        case 330043136:
          return 25;
      }
    }
  }
  else if ( v1 > 246157055 )
  {
    switch ( v1 )
    {
      case 246157056:
        return 18;
      case 262934272:
        return 19;
      case 279711488:
        return 20;
    }
  }
  else
  {
    switch ( v1 )
    {
      case 195825408:
        return 16;
      case 212602624:
        return 17;
      case 229379840:
        return 24;
    }
  }
  return 0xFFFFFFFFLL;
}
