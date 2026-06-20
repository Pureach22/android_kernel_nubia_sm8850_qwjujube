unsigned __int8 *__fastcall wlan_get_ie_ptr_from_eid(unsigned __int8 a1, unsigned __int8 *a2, unsigned __int16 a3)
{
  int v3; // w9
  __int64 v4; // x10
  unsigned int v5; // w9
  bool v6; // cf

  if ( (a3 & 0xFFFE) != 0 )
  {
    v3 = a3;
    do
    {
      v4 = a2[1];
      v5 = v3 - 2;
      v6 = v5 >= (unsigned int)v4;
      v3 = v5 - v4;
      if ( !v6 )
        break;
      if ( *a2 == a1 )
        return a2;
      a2 += v4 + 2;
    }
    while ( v3 > 1 );
  }
  return nullptr;
}
