__int64 __fastcall target_if_vdev_mgr_set_param_send(
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
  __int64 v10; // x8
  __int64 *v11; // x8
  __int64 v12; // x19
  int v13; // w8
  __int64 v14; // x21
  __int64 v15; // x20
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 result; // x0
  const char *v25; // x2
  const char *v26; // x2
  int v27; // [xsp+1Ch] [xbp-24h] BYREF
  int v28; // [xsp+20h] [xbp-20h] BYREF
  int v29; // [xsp+24h] [xbp-1Ch] BYREF
  __int64 v30; // [xsp+28h] [xbp-18h] BYREF
  _QWORD v31[2]; // [xsp+30h] [xbp-10h] BYREF

  v31[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || !a2 )
  {
    v25 = "%s: Invalid input";
LABEL_15:
    qdf_trace_msg(0x68u, 2u, v25, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_vdev_mgr_set_param_send");
    result = 4;
    goto LABEL_16;
  }
  v10 = *(_QWORD *)(a1 + 152);
  if ( !v10 )
  {
    v26 = "%s: PDEV is NULL";
    goto LABEL_14;
  }
  v11 = *(__int64 **)(v10 + 1232);
  if ( !v11 || (v12 = *v11) == 0 )
  {
    v26 = "%s: wmi_handle is null";
LABEL_14:
    qdf_trace_msg(0x68u, 2u, v26, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_vdev_mgr_wmi_handle_get");
    v25 = "%s: Failed to get WMI handle!";
    goto LABEL_15;
  }
  v13 = *(_DWORD *)(a2 + 4);
  if ( v13 > 7 )
  {
    if ( v13 <= 11 )
    {
      switch ( v13 )
      {
        case 8:
          *(_DWORD *)(a2 + 4) = 40;
          break;
        case 9:
          *(_DWORD *)(a2 + 4) = 41;
          break;
        case 10:
          *(_DWORD *)(a2 + 4) = 42;
          break;
      }
      goto LABEL_10;
    }
    if ( v13 <= 13 )
    {
      if ( v13 == 12 )
        *(_DWORD *)(a2 + 4) = 4;
      else
        *(_DWORD *)(a2 + 4) = 48;
      goto LABEL_10;
    }
    if ( v13 == 14 )
    {
      *(_DWORD *)(a2 + 4) = 91;
      goto LABEL_10;
    }
    if ( v13 != 45 )
      goto LABEL_10;
  }
  else
  {
    if ( (unsigned int)(v13 - 1) >= 6 )
    {
      if ( !v13 )
        *(_DWORD *)(a2 + 4) = 3;
      goto LABEL_10;
    }
    *(_DWORD *)(a2 + 4) = 45;
  }
  v14 = a2;
  v30 = 0;
  v31[0] = 0;
  v15 = a1;
  v29 = 0;
  v27 = 0;
  v28 = 0;
  ((void (*)(void))wlan_util_vdev_get_param)();
  wlan_util_vdev_get_param(v15, 4, &v30);
  wlan_util_vdev_get_param(v15, 1, (char *)v31 + 4);
  wlan_util_vdev_get_param(v15, 2, v31);
  wlan_util_vdev_get_param(v15, 7, &v27);
  wlan_util_vdev_get_param(v15, 5, &v29);
  wlan_util_vdev_get_param(v15, 6, &v28);
  LODWORD(v15) = BYTE4(v30) & 1
               | (16 * (v27 & 7)) & 0x7F
               | (2 * (v30 & 1)) & 0x73
               | (4 * (BYTE4(v31[0]) & 1)) & 0x77
               | (8 * (v31[0] & 1)) & 0x7F
               | ((v29 & 1) << 7)
               | ((v28 & 7) << 8);
  qdf_trace_msg(
    0x68u,
    8u,
    "%s: VHT su bfee:%d mu bfee:%d su bfer:%d mu bfer:%d impl bf:%d sounding dim:%d",
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    "target_if_vdev_mlme_build_txbf_caps",
    v29 & 1,
    v28 & 7);
  a2 = v14;
  *(_DWORD *)(v14 + 8) = v15;
LABEL_10:
  result = wmi_unified_vdev_set_param_send(v12, a2);
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
