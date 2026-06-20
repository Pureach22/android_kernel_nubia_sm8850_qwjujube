__int64 __fastcall spatial_reuse_send_pd_threshold(
        __int64 a1,
        unsigned __int8 a2,
        int a3,
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
  __int64 v22; // x21
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 result; // x0
  __int64 v32; // [xsp+8h] [xbp-18h] BYREF
  int v33; // [xsp+10h] [xbp-10h]
  __int64 v34; // [xsp+18h] [xbp-8h]

  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v33 = 0;
  v32 = 0;
  pdev_wmi_handle = lmac_get_pdev_wmi_handle(a1, a4, a5, a6, a7, a8, a9, a10, a11);
  if ( pdev_wmi_handle )
  {
    v22 = pdev_wmi_handle;
    if ( (wmi_service_enabled(pdev_wmi_handle, 0xCEu, v14, v15, v16, v17, v18, v19, v20, v21) & 1) != 0 )
    {
      qdf_mem_set(&v32, 0xCu, 0);
      v32 = a2 | 0x9E00000000LL;
      v33 = a3;
      result = wmi_unified_vdev_set_param_send(v22);
    }
    else
    {
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: Target doesn't support SR operations",
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        "spatial_reuse_send_pd_threshold");
      result = 0;
    }
  }
  else
  {
    result = 4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
