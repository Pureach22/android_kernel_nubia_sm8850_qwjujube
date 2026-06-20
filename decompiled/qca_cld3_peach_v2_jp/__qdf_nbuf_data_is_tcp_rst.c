bool __fastcall _qdf_nbuf_data_is_tcp_rst(__int64 a1)
{
  return *(_BYTE *)(a1 + 47) == 4;
}
