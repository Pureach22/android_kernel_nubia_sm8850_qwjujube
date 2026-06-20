__int64 __fastcall wlan_cm_set_roam_offload_ssid(
        __int64 a1,
        const void *a2,
        char a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned int v11; // w20
  __int64 ext_hdl; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x21
  void *v23; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7

  LOBYTE(v11) = a3;
  ext_hdl = wlan_vdev_mlme_get_ext_hdl(a1, a4, a5, a6, a7, a8, a9, a10, a11);
  if ( !ext_hdl )
    return qdf_trace_msg(
             0x68u,
             2u,
             "%s: vdev legacy private object is NULL",
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             v21,
             "wlan_cm_set_roam_offload_ssid");
  v22 = ext_hdl;
  v23 = (void *)(ext_hdl + 296);
  if ( (v11 & 0xE0) != 0 )
    v11 = 32;
  else
    v11 = (unsigned __int8)v11;
  qdf_mem_set(v23, 0x21u, 0);
  qdf_mem_copy((void *)(v22 + 297), a2, v11);
  *(_BYTE *)(v22 + 296) = v11;
  return qdf_trace_msg(
           0x68u,
           8u,
           "%s: Set roam offload ssid: %.*s",
           v24,
           v25,
           v26,
           v27,
           v28,
           v29,
           v30,
           v31,
           "wlan_cm_set_roam_offload_ssid",
           v11,
           v22 + 297);
}
