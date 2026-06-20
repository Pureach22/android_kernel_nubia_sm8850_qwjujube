__int64 __fastcall frame_time(int a1)
{
  if ( a1 < 28 )
    return 33333;
  if ( a1 <= 89 )
  {
    if ( a1 == 30 )
      return 33333;
    if ( a1 == 60 )
      return 16666;
  }
  else
  {
    switch ( a1 )
    {
      case 90:
        return 11111;
      case 120:
        return 8333;
      case 144:
        return 6944;
    }
  }
  return 0xF4240u / a1;
}
