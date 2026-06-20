bool __fastcall _qdf_nbuf_data_is_icmpv4_rsp(__int64 a1)
{
  return *(_BYTE *)(a1 + 34) == 0;
}
