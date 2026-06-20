__int64 __fastcall spatial_reuse_send_cfg(
        __int64 a1,
        char a2,
        unsigned __int8 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v13; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x20
  __int64 result; // x0
  __int64 v24; // [xsp+8h] [xbp-18h] BYREF
  int v25; // [xsp+10h] [xbp-10h]
  __int64 v26; // [xsp+18h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v25 = 0;
  v24 = 0;
  v13 = target_if_vdev_mgr_wmi_handle_get(a1, a4, a5, a6, a7, a8, a9, a10, a11);
  if ( v13 )
  {
    v22 = v13;
    qdf_mem_set(&v24, 0xCu, 0);
    LODWORD(v24) = 188;
    if ( (a2 & 6) == 4 )
      HIDWORD(v24) = HIDWORD(v24) & 0x7FFFFF00 | a3 | 0x20000000;
    result = wmi_unified_pdev_param_send(v22);
  }
  else
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: Failed to get WMI handle!",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "spatial_reuse_send_cfg");
    result = 4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
