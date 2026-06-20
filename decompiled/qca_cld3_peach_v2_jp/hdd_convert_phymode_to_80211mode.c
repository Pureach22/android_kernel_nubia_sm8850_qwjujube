__int64 __fastcall hdd_convert_phymode_to_80211mode(int a1)
{
  if ( a1 > 255 )
  {
    if ( a1 > 4095 )
    {
      if ( a1 != 4096 )
      {
        if ( a1 == 0x2000 || a1 == 0x4000 )
          return 6;
        return 7;
      }
    }
    else
    {
      if ( a1 == 256 || a1 == 512 )
        return 4;
      if ( a1 != 2048 )
        return 7;
    }
    return 5;
  }
  if ( a1 > 15 )
  {
    if ( a1 != 16 )
    {
      if ( a1 == 32 )
        return 1;
      if ( a1 != 64 )
        return 7;
    }
    return 2;
  }
  switch ( a1 )
  {
    case 2:
      return 3;
    case 4:
      return 0;
    case 8:
      return 1;
  }
  return 7;
}
