bool __fastcall _qdf_nbuf_data_is_ipv6_mcast_pkt(__int64 a1)
{
  return *(unsigned __int16 *)(a1 + 12) == 56710 && *(unsigned __int8 *)(a1 + 38) == 0xFF;
}
