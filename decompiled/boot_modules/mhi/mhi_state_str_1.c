const char *__fastcall mhi_state_str_1(int a1)
{
  if ( a1 <= 3 )
  {
    if ( a1 <= 1 )
    {
      if ( !a1 )
        return "RESET";
      if ( a1 == 1 )
        return "READY";
      return "Unknown state";
    }
    if ( a1 == 2 )
      return "M0";
    else
      return "M1";
  }
  else
  {
    if ( a1 > 5 )
    {
      switch ( a1 )
      {
        case 6:
          return "M3_FAST";
        case 7:
          return "BHI";
        case 255:
          return "SYS ERROR";
      }
      return "Unknown state";
    }
    if ( a1 == 4 )
      return "M2";
    else
      return "M3";
  }
}
