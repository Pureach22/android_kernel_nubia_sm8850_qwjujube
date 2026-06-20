__int64 __fastcall target_if_cfr_start_capture(
        __int64 a1,
        __int64 a2,
        unsigned __int8 *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 pdev_wmi_handle; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x20
  __int64 v23; // x22
  unsigned int v24; // w10
  unsigned int v25; // w8
  unsigned int v26; // w9
  __int64 result; // x0
  __int64 v28; // [xsp+8h] [xbp-28h] BYREF
  __int64 v29; // [xsp+10h] [xbp-20h]
  unsigned __int64 v30; // [xsp+18h] [xbp-18h]
  unsigned __int64 v31; // [xsp+20h] [xbp-10h]
  __int64 v32; // [xsp+28h] [xbp-8h]

  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v30 = 0;
  v31 = 0;
  v28 = 0;
  v29 = 0;
  pdev_wmi_handle = lmac_get_pdev_wmi_handle(a1, a4, a5, a6, a7, a8, a9, a10, a11);
  if ( pdev_wmi_handle )
  {
    v22 = pdev_wmi_handle;
    v23 = *(_QWORD *)(a2 + 96);
    qdf_mem_set(&v28, 0x20u, 0);
    v24 = *(unsigned __int8 *)(v23 + 168);
    LODWORD(v28) = 1;
    v25 = *((_DWORD *)a3 + 1);
    v29 = a2 + 48;
    v26 = *a3;
    v30 = __PAIR64__(v25, v24);
    v31 = __PAIR64__(a3[8], v26);
    result = wmi_unified_send_peer_cfr_capture_cmd(v22, &v28);
  }
  else
  {
    qdf_trace_msg(
      0x6Au,
      2u,
      "%s: pdev wmi handle NULL",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "target_if_cfr_start_capture");
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
