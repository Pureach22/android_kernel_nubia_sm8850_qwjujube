bool __fastcall _qdf_nbuf_data_is_icmpv6_redirect(__int64 a1)
{
  return *(unsigned __int8 *)(a1 + 54) == 137;
}
