__int64 __fastcall wma_enable_uapsd_mode(
        __int64 *a1,
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
  unsigned int v11; // w19
  __int64 v12; // x25
  __int64 v13; // x0
  int v15; // w22
  __int64 v16; // x0
  unsigned int v17; // w0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  unsigned int v26; // w8
  unsigned int v27; // w23
  __int64 v28; // x24
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  const char *v37; // x2
  __int64 result; // x0
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  __int64 v47; // [xsp+0h] [xbp-20h] BYREF
  __int64 v48; // [xsp+8h] [xbp-18h] BYREF
  unsigned int v49; // [xsp+10h] [xbp-10h]
  __int64 v50; // [xsp+18h] [xbp-8h]

  v50 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *((_DWORD *)a2 + 2);
  v12 = a1[65] + 488LL * v11;
  v13 = *(_QWORD *)v12;
  if ( !*(_QWORD *)v12 )
  {
    v37 = "%s: vdev is NULL for vdev_%d";
    goto LABEL_13;
  }
  v48 = 0;
  if ( (unsigned int)wlan_pmo_get_ps_params(v13, &v48) )
  {
LABEL_12:
    v37 = "%s: ps_param is invalid for vdev_%d";
    goto LABEL_13;
  }
  v15 = v48;
  if ( (unsigned int)v48 >= 3 )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Invalid opm_mode:%d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wma_wlan_pmo_get_ps_params",
      (unsigned int)v48);
    goto LABEL_12;
  }
  v16 = *a1;
  v47 = v48;
  v17 = wmi_unified_set_sta_ps_mode(v16);
  if ( v17 )
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Failed to send set Mimo PS ret = %d",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "wmi_unified_set_sta_ps",
      v17,
      v47);
  v26 = *a2;
  v27 = v26 & 0x80
      | (v26 >> 4) & 2
      | ((v26 & 2) != 0)
      | (4 * (v26 & 1)) & 0xEF
      | (v26 >> 1) & 8
      | (unsigned __int8)(16 * ((v26 & 4) != 0))
      | (v26 >> 1) & 0x20
      | (8 * (_BYTE)v26) & 0x40;
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: Enable Uapsd vdevId %d Mask %d",
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    "wma_enable_uapsd_mode",
    v11,
    v26 & 0x80
  | (v26 >> 4) & 2
  | ((v26 & 2) != 0)
  | (4 * (v26 & 1)) & 0xEF
  | (v26 >> 1) & 8
  | (unsigned __int8)(16 * ((v26 & 4) != 0))
  | (v26 >> 1) & 0x20
  | (8 * (_BYTE)v26) & 0x40,
    v47);
  v28 = *a1;
  if ( !_cds_get_context(54, (__int64)"wma_unified_set_sta_ps_param", v29, v30, v31, v32, v33, v34, v35, v36)
    || (wma_is_vdev_valid(v11, a3, a4, a5, a6, a7, a8, a9, a10) & 1) == 0
    || (qdf_trace_msg(
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
          v11,
          4,
          v27),
        v48 = v11 | 0x400000000LL,
        v49 = v27,
        (unsigned int)wmi_unified_sta_ps_cmd_send(v28)) )
  {
    v37 = "%s: Enable Uapsd Failed vdevId %d";
LABEL_13:
    result = qdf_trace_msg(0x36u, 2u, v37, a3, a4, a5, a6, a7, a8, a9, a10, "wma_enable_uapsd_mode", v11);
    goto LABEL_14;
  }
  if ( v27 && v15 )
  {
    LODWORD(v47) = 0;
    qdf_trace_msg(0x36u, 8u, "%s: Disable power %d", a3, a4, a5, a6, a7, a8, a9, a10, "wma_enable_uapsd_mode", v11, v47);
  }
  *(_DWORD *)(v12 + 212) = v27;
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: Enable Forced Sleep vdevId %d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "wma_enable_uapsd_mode",
    v11);
  result = wma_set_force_sleep(a1, v11, 1u, (unsigned int *)&v47, a2[1], v39, v40, v41, v42, v43, v44, v45, v46);
  if ( (_DWORD)result )
  {
    v37 = "%s: Enable Forced Sleep Failed vdevId %d";
    goto LABEL_13;
  }
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
