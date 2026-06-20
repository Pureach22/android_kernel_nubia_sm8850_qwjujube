__int64 __fastcall wma_disable_sta_ps_mode(
        _DWORD *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  unsigned int v10; // w19
  __int64 result; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 *v20; // x20
  __int64 v21; // x22
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x20
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7

  _ReadStatusReg(SP_EL0);
  v10 = a1[1];
  result = (__int64)_cds_get_context(54, (__int64)"wma_disable_sta_ps_mode", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( result )
  {
    v20 = (__int64 *)result;
    v21 = *(_QWORD *)(result + 520);
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: Disable Sta Mode Ps vdevId %d",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "wma_disable_sta_ps_mode",
      v10);
    result = wmi_unified_set_sta_ps_mode(*v20);
    if ( (_DWORD)result )
      result = qdf_trace_msg(
                 0x36u,
                 2u,
                 "%s: Failed to send set Mimo PS ret = %d",
                 v22,
                 v23,
                 v24,
                 v25,
                 v26,
                 v27,
                 v28,
                 v29,
                 "wmi_unified_set_sta_ps",
                 (unsigned int)result);
    *(_BYTE *)(v21 + 488LL * v10 + 280) = 0;
    if ( *a1 == 2 )
    {
      qdf_trace_msg(
        0x36u,
        8u,
        "%s: Disable Uapsd vdevId %d",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "wma_disable_sta_ps_mode",
        v10);
      v30 = *v20;
      if ( !_cds_get_context(54, (__int64)"wma_unified_set_sta_ps_param", v31, v32, v33, v34, v35, v36, v37, v38)
        || (wma_is_vdev_valid(v10, v39, v40, v41, v42, v43, v44, v45, v46) & 1) == 0
        || (qdf_trace_msg(
              0x36u,
              8u,
              "%s: Set Sta Ps param vdevId %d Param %d val %d",
              v39,
              v40,
              v41,
              v42,
              v43,
              v44,
              v45,
              v46,
              "wma_unified_set_sta_ps_param",
              v10,
              4,
              0),
            result = wmi_unified_sta_ps_cmd_send(v30),
            (_DWORD)result) )
      {
        result = qdf_trace_msg(
                   0x36u,
                   2u,
                   "%s: Disable Uapsd Failed vdevId %d",
                   v39,
                   v40,
                   v41,
                   v42,
                   v43,
                   v44,
                   v45,
                   v46,
                   "wma_disable_sta_ps_mode",
                   v10);
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
