__int64 __fastcall get_index(int a1)
{
  if ( a1 > 143 )
  {
    if ( a1 != 144 )
    {
      if ( a1 == 165 )
        return 4;
      return 0;
    }
    return 3;
  }
  else
  {
    if ( a1 != 90 )
    {
      if ( a1 == 120 )
        return 2;
      return 0;
    }
    return 1;
  }
}
