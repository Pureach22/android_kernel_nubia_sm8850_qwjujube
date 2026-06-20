bool __fastcall _qdf_nbuf_data_is_icmpv6_pkt(__int64 a1)
{
  return *(unsigned __int16 *)(a1 + 12) == 56710 && *(_BYTE *)(a1 + 20) == 58;
}
