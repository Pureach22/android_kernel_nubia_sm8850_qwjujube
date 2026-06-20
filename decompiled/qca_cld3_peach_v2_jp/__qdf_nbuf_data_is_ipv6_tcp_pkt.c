bool __fastcall _qdf_nbuf_data_is_ipv6_tcp_pkt(__int64 a1)
{
  return *(unsigned __int16 *)(a1 + 12) == 56710 && *(_BYTE *)(a1 + 20) == 6;
}
