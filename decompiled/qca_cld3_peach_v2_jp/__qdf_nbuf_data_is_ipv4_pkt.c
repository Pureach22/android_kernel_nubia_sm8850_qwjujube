bool __fastcall _qdf_nbuf_data_is_ipv4_pkt(__int64 a1)
{
  return *(unsigned __int16 *)(a1 + 12) == 8;
}
