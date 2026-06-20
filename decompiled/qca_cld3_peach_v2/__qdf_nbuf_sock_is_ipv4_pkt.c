bool __fastcall _qdf_nbuf_sock_is_ipv4_pkt(__int64 a1)
{
  __int64 v1; // x8

  v1 = *(_QWORD *)(a1 + 24);
  return v1 && *(_WORD *)(v1 + 16) == 2;
}
