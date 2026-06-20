__int64 __fastcall rmnet_wlan_tuple_present(unsigned __int16 *a1)
{
  int v1; // w8
  __int64 *v2; // x9
  int v3; // w10

  v1 = *a1;
  v2 = (__int64 *)rmnet_wlan_tuple_hash[(unsigned int)(1640531527 * v1) >> 28];
  if ( v2 )
  {
    v3 = *((unsigned __int8 *)a1 + 4);
    do
    {
      if ( *((unsigned __int8 *)v2 + 36) == v3 && *((unsigned __int8 *)v2 + 37) == *((unsigned __int8 *)a1 + 5) )
      {
        if ( v3 == 50 )
        {
          if ( *((_DWORD *)v2 + 8) == *(_DWORD *)a1 )
            return 1;
        }
        else if ( *((unsigned __int16 *)v2 + 16) == v1 )
        {
          return 1;
        }
      }
      v2 = (__int64 *)*v2;
    }
    while ( v2 );
  }
  return 0;
}
