char *__fastcall wlan_cm_get_roam_offload_bssid(
        __int64 a1,
        void *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  char *result; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7

  result = (char *)wlan_vdev_mlme_get_ext_hdl(a1, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !result )
    return (char *)qdf_trace_msg(
                     0x68u,
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
                     "wlan_cm_get_roam_offload_bssid");
  if ( a2 )
    return (char *)qdf_mem_copy(a2, result + 329, 6u);
  return result;
}
