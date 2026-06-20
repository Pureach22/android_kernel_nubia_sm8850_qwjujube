__int64 __fastcall reg_dmn_get_chanwidth_from_opclass(__int64 a1, unsigned __int8 a2, unsigned __int8 a3)
{
  unsigned __int8 *class_from_country; // x0
  int v6; // w10
  int v7; // t1
  __int64 v8; // x10

  class_from_country = (unsigned __int8 *)reg_get_class_from_country();
  v6 = *class_from_country;
  if ( *class_from_country )
  {
    do
    {
      if ( v6 == a3 )
      {
        v8 = 16;
        while ( class_from_country[v8] )
        {
          if ( class_from_country[v8] == a2 )
            return *((unsigned __int16 *)class_from_country + 1);
          if ( ++v8 == 86 )
            break;
        }
      }
      v7 = class_from_country[96];
      class_from_country += 96;
      v6 = v7;
    }
    while ( v7 );
  }
  return 0;
}
