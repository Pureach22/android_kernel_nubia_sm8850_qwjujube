void *__fastcall wlan_mlme_get_sae_single_pmk_info(
        __int64 a1,
        __int64 a2,
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
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x20
  size_t v21; // x2
  void *result; // x0

  ext_hdl = wlan_vdev_mlme_get_ext_hdl(a1, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !ext_hdl )
    return (void *)qdf_trace_msg(
                     0x1Fu,
                     2u,
                     "%s: vdev legacy private object is NULL",
                     v12,
                     v13,
                     v14,
                     v15,
                     v16,
                     v17,
                     v18,
                     v19,
                     "wlan_mlme_get_sae_single_pmk_info");
  v20 = ext_hdl;
  *(_BYTE *)a2 = *(_BYTE *)(ext_hdl + 176);
  *(_WORD *)(a2 + 74) = *(_WORD *)(ext_hdl + 250);
  *(_QWORD *)(a2 + 80) = *(_QWORD *)(ext_hdl + 256);
  v21 = *(unsigned __int8 *)(ext_hdl + 248);
  if ( *(_BYTE *)(ext_hdl + 248) )
  {
    result = qdf_mem_copy((void *)(a2 + 8), (const void *)(ext_hdl + 184), v21);
    *(_BYTE *)(a2 + 72) = *(_BYTE *)(v20 + 248);
  }
  else
  {
    result = qdf_mem_set((void *)(a2 + 8), 1u, v21);
    *(_BYTE *)(a2 + 72) = 0;
  }
  return result;
}
