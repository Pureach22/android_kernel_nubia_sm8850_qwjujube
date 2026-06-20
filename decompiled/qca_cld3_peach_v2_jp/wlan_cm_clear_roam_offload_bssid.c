__int64 __fastcall wlan_cm_clear_roam_offload_bssid(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 ext_hdl; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  unsigned __int16 *v18; // x0
  const char *v19; // x2
  unsigned int v20; // w1
  __int64 result; // x0
  int v22; // [xsp+8h] [xbp-18h] BYREF
  __int16 v23; // [xsp+Ch] [xbp-14h]
  __int64 v24; // [xsp+18h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v23 = 0;
  v22 = 0;
  ext_hdl = wlan_vdev_mlme_get_ext_hdl(a1, a2, a3, a4, a5, a6, a7, a8, a9);
  if ( ext_hdl )
  {
    v18 = (unsigned __int16 *)(ext_hdl + 329);
    if ( *(_DWORD *)v18 | v18[2] )
    {
      qdf_mem_copy(v18, &v22, 6u);
      v19 = "%s: Set offload bssid to zero";
    }
    else
    {
      v19 = "%s: offolad BSSID already zero";
    }
    v20 = 8;
  }
  else
  {
    v19 = "%s: vdev legacy private object is NULL";
    v20 = 2;
  }
  result = qdf_trace_msg(0x68u, v20, v19, v10, v11, v12, v13, v14, v15, v16, v17, "wlan_cm_clear_roam_offload_bssid");
  _ReadStatusReg(SP_EL0);
  return result;
}
