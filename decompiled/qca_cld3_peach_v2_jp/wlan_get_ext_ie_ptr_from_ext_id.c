unsigned __int8 *__fastcall wlan_get_ext_ie_ptr_from_ext_id(
        const void *a1,
        unsigned __int8 a2,
        unsigned __int8 *a3,
        unsigned __int16 a4)
{
  int v4; // w22
  unsigned int v8; // w23
  __int64 v9; // x24
  unsigned int v10; // w8

  v4 = a4;
  if ( a4 >= 2u )
  {
    v8 = a2;
    do
    {
      v9 = a3[1];
      v10 = v4 - 2;
      v4 = v4 - 2 - v9;
      if ( v10 < (unsigned int)v9 )
        break;
      if ( *a3 == 255 )
      {
        if ( !a1 )
          return a3;
        if ( v10 < v8 )
          return nullptr;
        if ( !(unsigned int)qdf_mem_cmp(a3 + 2, a1, a2) )
          return a3;
      }
      a3 += v9 + 2;
    }
    while ( v4 > 1 );
  }
  return nullptr;
}
