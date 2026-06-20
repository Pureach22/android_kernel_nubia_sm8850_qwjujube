__int64 __fastcall target_if_cfr_periodic_peer_cfr_enable(
        __int64 a1,
        int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 pdev_wmi_handle; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x21
  __int64 result; // x0
  __int64 v22; // [xsp+8h] [xbp-18h] BYREF
  int v23; // [xsp+10h] [xbp-10h]
  __int64 v24; // [xsp+18h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v23 = 0;
  v22 = 0;
  pdev_wmi_handle = lmac_get_pdev_wmi_handle(a1, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( pdev_wmi_handle )
  {
    v20 = pdev_wmi_handle;
    qdf_mem_set(&v22, 0xCu, 0);
    LODWORD(v22) = 168;
    HIDWORD(v22) = a2;
    result = wmi_unified_pdev_param_send(v20);
  }
  else
  {
    qdf_trace_msg(
      0x6Au,
      2u,
      "%s: pdev wmi handle NULL",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "target_if_cfr_periodic_peer_cfr_enable");
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
