__int64 __fastcall wlan_hdd_is_tdls_allowed(
        __int64 *a1,
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
  __int64 v12; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x4
  const char *v30; // x2
  const char *v31; // x2
  __int64 result; // x0
  __int64 link_info_by_vdev; // x0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  bool v42; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v43; // [xsp+8h] [xbp-8h]

  v43 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *a1;
  v42 = 0;
  if ( !(unsigned int)cfg_tdls_get_support_enable(v12, &v42, a3, a4, a5, a6, a7, a8, a9, a10) && !v42 )
  {
    v31 = "%s: TDLS feature not Enabled or Not supported in FW";
    goto LABEL_13;
  }
  if ( !(unsigned int)wlan_vdev_is_up() )
  {
    if ( wlan_cm_roaming_in_progress(a1[1], *(_BYTE *)(a2 + 168)) )
    {
      v31 = "%s: Failed due to Roaming is in progress";
    }
    else if ( (ucfg_tdls_check_is_tdls_allowed(a2, v13, v14, v15, v16, v17, v18, v19, v20) & 1) != 0 )
    {
      if ( (mlme_get_tdls_prohibited(a2, v13, v14, v15, v16, v17, v18, v19, v20) & 1) == 0 )
      {
        link_info_by_vdev = hdd_get_link_info_by_vdev((__int64)a1, *(unsigned __int8 *)(a2 + 168));
        if ( (wlan_hdd_is_link_switch_in_progress(link_info_by_vdev, v34, v35, v36, v37, v38, v39, v40, v41) & 1) == 0 )
        {
          result = 1;
          goto LABEL_15;
        }
        v29 = *(unsigned __int8 *)(a2 + 168);
        v30 = "%s: vdev:%d Link switch in progress";
        goto LABEL_5;
      }
      v31 = "%s: TDLS is prohobited by AP";
    }
    else
    {
      v31 = "%s: TDLS is not allowed";
    }
LABEL_13:
    qdf_trace_msg(0x33u, 8u, v31, v13, v14, v15, v16, v17, v18, v19, v20, "wlan_hdd_is_tdls_allowed");
    goto LABEL_14;
  }
  v29 = *(unsigned __int8 *)(a2 + 168);
  v30 = "%s: vdev %d Failed due to Not associated";
LABEL_5:
  qdf_trace_msg(0x33u, 8u, v30, v21, v22, v23, v24, v25, v26, v27, v28, "wlan_hdd_is_tdls_allowed", v29);
LABEL_14:
  result = 0;
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
