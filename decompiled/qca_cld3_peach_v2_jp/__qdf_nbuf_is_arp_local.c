bool __fastcall _qdf_nbuf_is_arp_local(__int64 a1, unsigned __int8 *a2)
{
  _BOOL8 result; // x0
  __int64 v4; // x19
  unsigned __int8 *v5; // x19
  int v6; // t1

  result = 0;
  if ( a2 )
  {
    v4 = *(_QWORD *)(a1 + 224);
    if ( *(_WORD *)(v4 + 6) == 256 )
    {
      v6 = *(unsigned __int8 *)(v4 + 24);
      v5 = (unsigned __int8 *)(v4 + 24);
      qdf_trace_msg(
        56,
        8,
        "%s: ARP packet: local IP: %d.%d.%d.%d dest IP:%d.%d.%d.%d",
        "__qdf_nbuf_is_arp_local",
        *a2,
        a2[1],
        a2[2],
        a2[3],
        v6,
        v5[1],
        v5[2],
        v5[3]);
      return (unsigned int)qdf_mem_cmp(v5, a2, 4u) == 0;
    }
  }
  return result;
}
