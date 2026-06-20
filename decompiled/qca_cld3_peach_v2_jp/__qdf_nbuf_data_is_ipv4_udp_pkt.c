bool __fastcall _qdf_nbuf_data_is_ipv4_udp_pkt(__int64 a1)
{
  return *(_WORD *)(a1 + 12) == 8 && *(_BYTE *)(a1 + 23) == 17;
}
