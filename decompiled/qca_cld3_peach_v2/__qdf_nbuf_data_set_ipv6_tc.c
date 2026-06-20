__int64 __fastcall _qdf_nbuf_data_set_ipv6_tc(__int64 result, unsigned __int8 a2)
{
  *(_DWORD *)(result + 14) = bswap32((a2 << 20) | 0x60000000) | *(_DWORD *)(result + 14) & 0xFFFF0F00;
  return result;
}
