bool __fastcall _qdf_nbuf_data_is_ipv4_mcast_pkt(__int64 a1)
{
  return *(_WORD *)(a1 + 12) == 8 && (*(_DWORD *)(a1 + 30) & 0xF0) == 224;
}
