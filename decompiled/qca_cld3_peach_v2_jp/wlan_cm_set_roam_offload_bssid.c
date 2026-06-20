__int64 __fastcall wlan_cm_set_roam_offload_bssid(
        __int64 a1,
        unsigned __int16 *a2,
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
  __int64 result; // x0
  const char *v21; // x2

  _ReadStatusReg(SP_EL0);
  ext_hdl = wlan_vdev_mlme_get_ext_hdl(a1, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !ext_hdl )
  {
    v21 = "%s: vdev legacy private object is NULL";
    goto LABEL_7;
  }
  if ( !a2 || !(*(_DWORD *)a2 | a2[2]) )
  {
    v21 = "%s: NULL BSSID";
LABEL_7:
    result = qdf_trace_msg(0x68u, 2u, v21, v12, v13, v14, v15, v16, v17, v18, v19, "wlan_cm_set_roam_offload_bssid");
    goto LABEL_8;
  }
  result = (__int64)qdf_mem_copy((void *)(ext_hdl + 329), a2, 6u);
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
