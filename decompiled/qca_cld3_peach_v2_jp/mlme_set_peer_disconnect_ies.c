void *__fastcall mlme_set_peer_disconnect_ies(
        __int64 a1,
        unsigned int *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 ext_hdl; // x0
  __int64 v12; // x19
  __int64 v13; // x0
  void *result; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  const char *v23; // x2
  unsigned int v24; // w1

  if ( !a2 || !*a2 || !*((_QWORD *)a2 + 1) )
  {
    v23 = "%s: disocnnect IEs are NULL";
    v24 = 8;
    return (void *)qdf_trace_msg(0x1Fu, v24, v23, a3, a4, a5, a6, a7, a8, a9, a10, "mlme_set_peer_disconnect_ies");
  }
  ext_hdl = wlan_vdev_mlme_get_ext_hdl(a1, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !ext_hdl )
  {
    v23 = "%s: vdev legacy private object is NULL";
    v24 = 2;
    return (void *)qdf_trace_msg(0x1Fu, v24, v23, a3, a4, a5, a6, a7, a8, a9, a10, "mlme_set_peer_disconnect_ies");
  }
  v12 = ext_hdl;
  v13 = *(_QWORD *)(ext_hdl + 136);
  if ( v13 )
  {
    _qdf_mem_free(v13);
    *(_DWORD *)(v12 + 128) = 0;
  }
  result = (void *)_qdf_mem_malloc(*a2, "mlme_set_peer_disconnect_ies", 4443);
  *(_QWORD *)(v12 + 136) = result;
  if ( result )
  {
    qdf_mem_copy(result, *((const void **)a2 + 1), *a2);
    *(_DWORD *)(v12 + 128) = *a2;
    qdf_trace_msg(
      0x1Fu,
      8u,
      "%s: peer disconnect IEs",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "mlme_set_peer_disconnect_ies");
    return (void *)((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD))qdf_trace_hex_dump)(
                     31,
                     8,
                     *(_QWORD *)(v12 + 136),
                     *(unsigned int *)(v12 + 128));
  }
  return result;
}
