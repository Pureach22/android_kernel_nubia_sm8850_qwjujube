bool __fastcall _qdf_nbuf_data_is_ipv6_igmp_pkt(__int64 a1)
{
  int v1; // w8
  __int64 v2; // x8
  __int64 v3; // x9
  int v4; // w9
  int v6; // w8

  v1 = *(unsigned __int16 *)(a1 + 12);
  if ( v1 == 56710 )
  {
    v2 = 54;
    v3 = 20;
  }
  else
  {
    if ( v1 != 129 || *(unsigned __int16 *)(a1 + 16) != 56710 )
      return 0;
    v2 = 58;
    v3 = 24;
  }
  v4 = *(unsigned __int8 *)(a1 + v3);
  if ( v4 == 58 )
    return 1;
  v6 = *(unsigned __int8 *)(a1 + v2);
  return !v4 && v6 == 58;
}
