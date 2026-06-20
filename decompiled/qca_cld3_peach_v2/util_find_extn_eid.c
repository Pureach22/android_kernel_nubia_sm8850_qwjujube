unsigned __int8 *__fastcall util_find_extn_eid(
        unsigned __int8 a1,
        unsigned __int8 a2,
        unsigned __int8 *a3,
        unsigned __int64 a4)
{
  unsigned __int8 *result; // x0
  __int64 v6; // x11
  bool v7; // cf

  result = nullptr;
  if ( a3 && a4 >= 3 )
  {
    do
    {
      v6 = a3[1];
      v7 = a4 >= v6 + 2;
      a4 -= v6 + 2;
      if ( !v7 )
        break;
      if ( a3[1] && *a3 == a1 && a3[2] == a2 )
        return a3;
      a3 += v6 + 2;
    }
    while ( a4 > 2 );
    return nullptr;
  }
  return result;
}
