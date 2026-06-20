__int64 __fastcall wma_disable_uapsd_mode(
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
  unsigned int v10; // w19
  __int64 *v11; // x21
  __int64 v13; // x0
  __int64 v14; // x0
  unsigned int v15; // w0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x21
  const char *v25; // x2
  __int64 result; // x0
  __int64 v27; // [xsp+0h] [xbp-20h] BYREF
  _QWORD v28[3]; // [xsp+8h] [xbp-18h] BYREF

  v28[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_DWORD *)(a2 + 8);
  v11 = (__int64 *)(a1[65] + 488LL * v10);
  if ( !*v11 )
  {
    v25 = "%s: vdev is null for vdev_%d";
    goto LABEL_13;
  }
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: Disable Uapsd vdevId %d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "wma_disable_uapsd_mode",
    v10);
  v13 = *v11;
  v28[0] = 0;
  if ( (unsigned int)wlan_pmo_get_ps_params(v13, v28) )
  {
LABEL_12:
    v25 = "%s: ps_param is invalid for vdev_%d";
    goto LABEL_13;
  }
  if ( LODWORD(v28[0]) >= 3 )
  {
    qdf_trace_msg(0x36u, 2u, "%s: Invalid opm_mode:%d", a3, a4, a5, a6, a7, a8, a9, a10, "wma_wlan_pmo_get_ps_params");
    goto LABEL_12;
  }
  v14 = *a1;
  v27 = v28[0];
  v15 = wmi_unified_set_sta_ps_mode(v14);
  if ( v15 )
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Failed to send set Mimo PS ret = %d",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "wmi_unified_set_sta_ps",
      v15,
      v27);
  v24 = *a1;
  if ( _cds_get_context(54, (__int64)"wma_unified_set_sta_ps_param", v16, v17, v18, v19, v20, v21, v22, v23)
    && (wma_is_vdev_valid(v10, a3, a4, a5, a6, a7, a8, a9, a10) & 1) != 0
    && (qdf_trace_msg(
          0x36u,
          8u,
          "%s: Set Sta Ps param vdevId %d Param %d val %d",
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          "wma_unified_set_sta_ps_param",
          v10,
          4,
          0),
        LODWORD(v28[0]) = v10,
        *(_QWORD *)((char *)v28 + 4) = 4,
        !(unsigned int)wmi_unified_sta_ps_cmd_send(v24)) )
  {
    result = wma_set_force_sleep(a1, v10, 0, (unsigned int *)&v27, 1, a3, a4, a5, a6, a7, a8, a9, a10);
    if ( !(_DWORD)result )
      goto LABEL_14;
    v25 = "%s: Disable Forced Sleep Failed vdevId %d";
  }
  else
  {
    v25 = "%s: Disable Uapsd Failed vdevId %d";
  }
LABEL_13:
  result = qdf_trace_msg(0x36u, 2u, v25, a3, a4, a5, a6, a7, a8, a9, a10, "wma_disable_uapsd_mode", v10, v27);
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
