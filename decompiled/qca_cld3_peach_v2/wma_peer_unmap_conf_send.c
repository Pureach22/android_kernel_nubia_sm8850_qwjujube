__int64 __fastcall wma_peer_unmap_conf_send(
        _QWORD *a1,
        unsigned __int8 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v11; // w20
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7

  if ( a2 )
  {
    v11 = wmi_unified_peer_unmap_conf_send(*a1, *a2, *((unsigned int *)a2 + 1), *((_QWORD *)a2 + 1));
    if ( v11 )
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: peer_unmap_conf_send failed %d",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "wma_peer_unmap_conf_send",
        v11);
    _qdf_mem_free(*((_QWORD *)a2 + 1));
    *((_QWORD *)a2 + 1) = 0;
  }
  else
  {
    qdf_trace_msg(0x36u, 2u, "%s: null input params", a3, a4, a5, a6, a7, a8, a9, a10, "wma_peer_unmap_conf_send");
    return 4;
  }
  return v11;
}
