__int64 __fastcall wma_pasn_peer_delete_handler(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        __int64 a10,
        unsigned __int8 a11,
        unsigned __int8 *a12)
{
  if ( !a12 )
    return qdf_trace_msg(
             0x36u,
             2u,
             "%s: peer del rsp is null",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "wma_pasn_peer_delete_handler");
  if ( *((_DWORD *)a12 + 1) )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: peer delete fail status %d",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "wma_pasn_peer_delete_handler");
  }
  else if ( a1 )
  {
    if ( *a12 == a11 )
      wlan_nan_pasn_peer_handle_del_rsp();
    else
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: peer del vdev id %d, expected vdev id %d",
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        "wma_pasn_peer_delete_handler",
        a11);
  }
  else
  {
    qdf_trace_msg(0x36u, 2u, "%s: psoc is null", a2, a3, a4, a5, a6, a7, a8, a9, "wma_pasn_peer_delete_handler");
  }
  return _qdf_mem_free((__int64)a12);
}
