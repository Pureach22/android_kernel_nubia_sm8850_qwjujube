__int64 __fastcall cnss_get_timeout(__int64 a1, int a2)
{
  __int64 result; // x0
  int v4; // w8

  result = cnss_get_qmi_timeout();
  if ( a2 > 4 )
  {
    if ( a2 > 6 )
    {
      if ( a2 == 7 )
      {
        v4 = 30000;
      }
      else
      {
        if ( a2 != 8 )
          return result;
        v4 = 65000;
      }
      return (unsigned int)(result + v4);
    }
    else if ( a2 == 5 )
    {
      return 20000;
    }
    else
    {
      return 60000;
    }
  }
  else if ( a2 > 2 )
  {
    if ( a2 == 3 )
      return (unsigned int)(result + 120000);
    else
      return (unsigned int)(2 * result + 60000);
  }
  else if ( a2 == 1 )
  {
    return (unsigned int)(4 * result);
  }
  else if ( a2 == 2 )
  {
    return (unsigned int)(result + 90000);
  }
  return result;
}
