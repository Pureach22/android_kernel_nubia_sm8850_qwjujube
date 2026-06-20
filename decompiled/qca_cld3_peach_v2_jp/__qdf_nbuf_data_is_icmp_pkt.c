bool __fastcall _qdf_nbuf_data_is_icmp_pkt(__int64 a1)
{
  return *(_WORD *)(a1 + 12) == 8 && *(_BYTE *)(a1 + 23) == 1;
}
