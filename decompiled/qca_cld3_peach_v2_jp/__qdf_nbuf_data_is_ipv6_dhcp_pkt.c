bool __fastcall _qdf_nbuf_data_is_ipv6_dhcp_pkt(unsigned __int16 *a1)
{
  int v1; // w8
  int v2; // w10

  if ( a1[6] != 56710 )
    return 0;
  v1 = a1[27];
  v2 = a1[28];
  if ( v1 == 8962 && v2 == 8706 )
    return 1;
  return v1 == 8706 && v2 == 8962;
}
