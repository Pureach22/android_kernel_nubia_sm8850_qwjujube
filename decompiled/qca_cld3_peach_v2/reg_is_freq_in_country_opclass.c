char *__fastcall reg_is_freq_in_country_opclass(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        unsigned __int8 *a10,
        unsigned __int8 a11,
        int a12)
{
  int v13; // w20
  char *result; // x0
  __int64 v15; // x8

  v13 = a11;
  result = reg_get_class_from_country(a10, a1, a2, a3, a4, a5, a6, a7, a8);
  while ( *result )
  {
    if ( (unsigned __int8)*result == v13 )
    {
      v15 = 16;
      while ( result[v15] )
      {
        if ( *((_DWORD *)result + 3) + 5 * (unsigned __int8)result[v15] == a12 )
          return (_BYTE *)(&off_0 + 1);
        if ( ++v15 == 86 )
          break;
      }
    }
    result += 96;
    if ( !result )
      return result;
  }
  return nullptr;
}
