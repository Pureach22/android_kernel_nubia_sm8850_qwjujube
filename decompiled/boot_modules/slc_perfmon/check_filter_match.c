__int64 __fastcall check_filter_match(unsigned __int16 *a1, int a2, unsigned __int64 a3, unsigned __int64 a4)
{
  __int64 result; // x0
  unsigned __int64 v6; // x8
  unsigned __int64 v7; // x8

  result = 0;
  if ( a2 > 2 )
  {
    if ( a2 > 4 )
    {
      if ( a2 == 5 )
      {
        v6 = a1[5];
      }
      else
      {
        if ( a2 != 7 )
          return result;
        v6 = ~(-1LL << *a1);
      }
    }
    else if ( a2 == 3 )
    {
      v6 = a1[3];
    }
    else
    {
      v6 = a1[4];
    }
    goto LABEL_21;
  }
  if ( a2 )
  {
    if ( a2 == 1 )
    {
      v6 = a1[1];
    }
    else
    {
      if ( a2 != 2 )
        return result;
      v6 = a1[2];
    }
LABEL_21:
    if ( v6 >= a4 && v6 >= a3 )
      return 0;
    else
      return 4294967274LL;
  }
  v7 = *a1;
  if ( v7 > a4 && v7 > a3 )
    return 0;
  else
    return 4294967274LL;
}
