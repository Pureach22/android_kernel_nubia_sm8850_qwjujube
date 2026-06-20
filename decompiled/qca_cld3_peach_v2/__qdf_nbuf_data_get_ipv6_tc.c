__int64 __fastcall _qdf_nbuf_data_get_ipv6_tc(__int64 a1)
{
  return bswap32(*(_DWORD *)(a1 + 14) & 0xF00F) >> 20;
}
