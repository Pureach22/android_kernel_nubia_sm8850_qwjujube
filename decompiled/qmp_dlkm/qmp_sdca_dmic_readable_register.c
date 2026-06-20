__int64 __fastcall qmp_sdca_dmic_readable_register(__int64 a1, int a2)
{
  __int64 result; // x0
  unsigned __int16 v3; // w8

  result = 1;
  if ( a2 <= 1078460423 )
  {
    if ( a2 > 1077936287 )
    {
      if ( a2 > 1077936527 )
      {
        if ( a2 != 1077936528 && a2 != 1078460416 )
          return 0;
      }
      else if ( a2 != 1077936288 && a2 != 1077936392 )
      {
        return 0;
      }
    }
    else if ( (unsigned int)(a2 - 1075316144) > 8 || ((1 << (a2 + 80)) & 0x10F) == 0 )
    {
      return 0;
    }
  }
  else if ( a2 > 1082654719 )
  {
    if ( a2 <= 1082654975 )
    {
      if ( a2 == 1082654720 )
        return result;
      v3 = 8;
    }
    else
    {
      if ( a2 == 1082654976 || a2 == 1082655744 )
        return result;
      v3 = 1032;
    }
    if ( a2 != (v3 | 0x40880000) )
      return 0;
  }
  else if ( a2 <= 1082130591 )
  {
    if ( a2 != 1078460424 && a2 != 1078460672 )
      return 0;
  }
  else if ( a2 != 1082130592 && a2 != 1082130696 && a2 != 1082130832 )
  {
    return 0;
  }
  return result;
}
