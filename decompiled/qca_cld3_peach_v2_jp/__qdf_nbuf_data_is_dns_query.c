bool __fastcall _qdf_nbuf_data_is_dns_query(__int64 a1)
{
  return *(_WORD *)(a1 + 36) == 13568 && (*(_WORD *)(a1 + 44) & 0xF8) == 0;
}
