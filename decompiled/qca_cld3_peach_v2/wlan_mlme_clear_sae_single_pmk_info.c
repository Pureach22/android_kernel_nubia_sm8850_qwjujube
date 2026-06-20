void *__fastcall wlan_mlme_clear_sae_single_pmk_info(
        __int64 a1,
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
  __int64 ext_hdl; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  size_t v20; // x2
  __int64 v21; // x20
  void *result; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  void *v31; // x0
  const char *v32; // x2
  unsigned int v33; // w1
  __int64 v34; // x19

  ext_hdl = wlan_vdev_mlme_get_ext_hdl(a1, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( ext_hdl )
  {
    if ( !a2 )
    {
      v34 = ext_hdl;
      qdf_trace_msg(
        0x1Fu,
        8u,
        "%s: Flush sae_single_pmk info",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "wlan_mlme_clear_sae_single_pmk_info");
      v31 = (void *)(v34 + 184);
      return qdf_mem_set(v31, 0x50u, 0);
    }
    v20 = a2[64];
    if ( (_DWORD)v20 == *(unsigned __int8 *)(ext_hdl + 248) )
    {
      v21 = ext_hdl;
      result = (void *)qdf_mem_cmp((const void *)(ext_hdl + 184), a2, v20);
      if ( (_DWORD)result )
        return result;
      qdf_trace_msg(
        0x1Fu,
        8u,
        "%s: Clear sae_single_pmk info",
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        "wlan_mlme_clear_sae_single_pmk_info");
      v31 = (void *)(v21 + 184);
      return qdf_mem_set(v31, 0x50u, 0);
    }
    v32 = "%s: Invalid pmk len";
    v33 = 8;
  }
  else
  {
    v32 = "%s: vdev legacy private object is NULL";
    v33 = 2;
  }
  return (void *)qdf_trace_msg(
                   0x1Fu,
                   v33,
                   v32,
                   v12,
                   v13,
                   v14,
                   v15,
                   v16,
                   v17,
                   v18,
                   v19,
                   "wlan_mlme_clear_sae_single_pmk_info");
}
