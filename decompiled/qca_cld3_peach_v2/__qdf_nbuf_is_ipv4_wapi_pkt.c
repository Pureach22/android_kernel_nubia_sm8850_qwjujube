bool __fastcall _qdf_nbuf_is_ipv4_wapi_pkt(__int64 a1)
{
  return *(unsigned __int16 *)(*(_QWORD *)(a1 + 224) + 12LL) == 46216;
}
