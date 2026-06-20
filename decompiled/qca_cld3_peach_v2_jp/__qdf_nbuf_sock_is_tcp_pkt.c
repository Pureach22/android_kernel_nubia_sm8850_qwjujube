bool __fastcall _qdf_nbuf_sock_is_tcp_pkt(__int64 a1)
{
  return *(unsigned __int16 *)(*(_QWORD *)(a1 + 24) + 566LL) == 6;
}
