bool __fastcall _qdf_nbuf_data_is_ipv4_igmp_pkt(__int64 a1)
{
  int v1; // w8
  __int64 v2; // x8

  v1 = *(unsigned __int16 *)(a1 + 12);
  if ( v1 == 8 )
  {
    v2 = 23;
    return *(_BYTE *)(a1 + v2) == 2;
  }
  if ( v1 == 129 && *(_WORD *)(a1 + 16) == 8 )
  {
    v2 = 27;
    return *(_BYTE *)(a1 + v2) == 2;
  }
  return 0;
}
