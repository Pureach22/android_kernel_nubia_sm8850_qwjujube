unsigned __int8 *__fastcall wlan_get_rsn_sel_ie_from_ie_ptr(unsigned __int8 *a1, unsigned __int16 a2)
{
  int v3; // w21
  __int64 v4; // x22
  unsigned int v5; // w8

  if ( (a2 & 0xFFFE) != 0 )
  {
    v3 = a2;
    do
    {
      v4 = a1[1];
      v5 = v3 - 2;
      v3 = v3 - 2 - v4;
      if ( v5 < (unsigned int)v4 )
        break;
      if ( *a1 == 221 )
      {
        if ( v5 < 4 )
          return nullptr;
        if ( !(unsigned int)qdf_mem_cmp(a1 + 2, &unk_940622, 4u) )
          return a1;
      }
      a1 += v4 + 2;
    }
    while ( v3 > 1 );
  }
  return nullptr;
}
