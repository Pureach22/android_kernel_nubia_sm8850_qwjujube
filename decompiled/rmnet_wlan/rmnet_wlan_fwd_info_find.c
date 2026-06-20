__int64 *__fastcall rmnet_wlan_fwd_info_find(__int64 a1)
{
  int v1; // w9
  __int64 *result; // x0
  int v4; // w10

  v1 = *(_DWORD *)(a1 + 8);
  result = (__int64 *)rmnet_wlan_fwd_hash[(unsigned int)(1640531527 * v1) >> 28];
  if ( result )
  {
    v4 = *(unsigned __int8 *)(a1 + 24);
    do
    {
      if ( *((unsigned __int8 *)result + 96) == v4 )
      {
        if ( v4 == 4 )
        {
          if ( *((_DWORD *)result + 20) == v1 )
            return result;
        }
        else if ( *(_QWORD *)(a1 + 8) == result[10] )
        {
          return result;
        }
      }
      result = (__int64 *)*result;
    }
    while ( result );
  }
  return result;
}
