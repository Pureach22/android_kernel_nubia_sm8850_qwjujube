__int64 __fastcall wma_get_bcn_rate_code(unsigned __int16 a1)
{
  int v1; // w8
  __int64 result; // x0

  v1 = a1;
  result = 131;
  if ( v1 <= 119 )
  {
    if ( v1 <= 59 )
    {
      if ( v1 == 20 )
      {
        return 130;
      }
      else if ( v1 == 55 )
      {
        return 129;
      }
    }
    else
    {
      switch ( v1 )
      {
        case '<':
          return 3;
        case 'Z':
          return 7;
        case 'n':
          return 128;
      }
    }
  }
  else if ( v1 > 359 )
  {
    switch ( v1 )
    {
      case 360:
        return 5;
      case 480:
        return 0;
      case 540:
        return 4;
    }
  }
  else
  {
    switch ( v1 )
    {
      case 120:
        return 2;
      case 180:
        return 6;
      case 240:
        return 1;
    }
  }
  return result;
}
