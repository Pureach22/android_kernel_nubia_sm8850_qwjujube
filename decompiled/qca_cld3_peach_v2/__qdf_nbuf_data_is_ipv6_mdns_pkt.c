bool __fastcall _qdf_nbuf_data_is_ipv6_mdns_pkt(__int64 a1)
{
  return *(unsigned __int16 *)(a1 + 54) == 59668 && *(unsigned __int16 *)(a1 + 56) == 59668;
}
