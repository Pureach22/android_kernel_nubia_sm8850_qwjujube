__int64 __fastcall reg_dmn_get_opclass_from_freq_width(
        unsigned __int8 *a1,
        int a2,
        unsigned __int16 a3,
        unsigned __int16 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  int v14; // w21
  char *class_from_country; // x0
  unsigned int v16; // w8
  __int64 v17; // x9

  v14 = a3;
  class_from_country = reg_get_class_from_country(a1, a5, a6, a7, a8, a9, a10, a11, a12);
  while ( 1 )
  {
    v16 = (unsigned __int8)*class_from_country;
    if ( !*class_from_country )
      return v16;
    if ( *((unsigned __int16 *)class_from_country + 1) == v14 )
    {
      v17 = 16;
      while ( class_from_country[v17] )
      {
        if ( *((_DWORD *)class_from_country + 3) + 5 * (unsigned __int8)class_from_country[v17] == a2
          && (*((_WORD *)class_from_country + 4) & a4) != 0 )
        {
          return v16;
        }
        if ( ++v17 == 86 )
          break;
      }
    }
    class_from_country += 96;
    if ( !class_from_country )
      return 0;
  }
}
