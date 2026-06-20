bool __fastcall _qdf_nbuf_data_is_dns_response(__int64 a1)
{
  return *(_WORD *)(a1 + 34) == 13568 && (*(_WORD *)(a1 + 44) & 0xF8) == 0x80;
}
