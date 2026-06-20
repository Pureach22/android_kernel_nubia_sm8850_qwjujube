__int64 __fastcall reg_is_phymode_unallowed(int a1, unsigned int a2)
{
  bool v3; // cc
  __int64 result; // x0

  if ( !a2 )
    return 0;
  v3 = a1 <= 3;
  result = 1;
  if ( v3 )
  {
    switch ( a1 )
    {
      case 1:
        return (a2 >> 1) & 1;
      case 2:
        return (a2 >> 2) & 1;
      case 3:
        return a2 & 1;
    }
  }
  else
  {
    switch ( a1 )
    {
      case 4:
        return (a2 >> 3) & 1;
      case 5:
        return (a2 >> 4) & 1;
      case 6:
        return (a2 >> 5) & 1;
    }
  }
  return result;
}
