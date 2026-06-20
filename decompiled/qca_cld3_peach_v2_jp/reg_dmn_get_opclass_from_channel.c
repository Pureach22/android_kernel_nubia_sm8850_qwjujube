__int64 __fastcall reg_dmn_get_opclass_from_channel(
        unsigned __int8 *a1,
        unsigned __int8 a2,
        unsigned __int8 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  int v12; // w20
  char *class_from_country; // x0
  unsigned int v14; // w8
  __int64 i; // x10

  v12 = a2;
  class_from_country = reg_get_class_from_country(a1, a4, a5, a6, a7, a8, a9, a10, a11);
  while ( 1 )
  {
    v14 = (unsigned __int8)*class_from_country;
    if ( !*class_from_country )
      break;
    if ( a3 == 5 || *((_DWORD *)class_from_country + 1) == a3 )
    {
      for ( i = 16; i != 86; ++i )
      {
        if ( !class_from_country[i] )
          break;
        if ( (unsigned __int8)class_from_country[i] == v12 )
          return v14;
      }
    }
    class_from_country += 96;
    if ( !class_from_country )
      return 0;
  }
  return v14;
}
