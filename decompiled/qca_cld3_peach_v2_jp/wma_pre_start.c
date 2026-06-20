__int64 __fastcall wma_pre_start(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 *context; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 *v25; // x19
  __int64 htc_hdl; // x0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 *v35; // x20
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  const char *v44; // x2
  unsigned int v45; // w19
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7

  qdf_trace_msg(0x36u, 8u, "%s: Enter", a1, a2, a3, a4, a5, a6, a7, a8, "wma_pre_start");
  context = _cds_get_context(54, (__int64)"wma_pre_start", v8, v9, v10, v11, v12, v13, v14, v15);
  if ( context )
  {
    v25 = context;
    htc_hdl = lmac_get_htc_hdl(context[3], v17, v18, v19, v20, v21, v22, v23, v24);
    if ( htc_hdl )
    {
      v35 = (__int64 *)htc_hdl;
      if ( (unsigned int)wmi_unified_connect_htc_service(*v25, htc_hdl) )
      {
        v44 = "%s: wmi_unified_connect_htc_service";
      }
      else
      {
        if ( !(unsigned int)wmi_diag_connect_pdev_htc_service(*v25, v35) )
        {
          qdf_trace_msg(
            0x36u,
            8u,
            "%s: WMA --> wmi_unified_connect_htc_service - success",
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            v43,
            "wma_pre_start");
          v45 = 0;
          goto LABEL_10;
        }
        v44 = "%s: wmi_diag_connect_pdev_htc_service";
      }
      qdf_trace_msg(0x36u, 2u, v44, v36, v37, v38, v39, v40, v41, v42, v43, "wma_pre_start");
      cds_is_fw_down(v46, v47, v48, v49, v50, v51, v52, v53);
      v45 = 5;
    }
    else
    {
      qdf_trace_msg(0x36u, 2u, "%s: invalid htc handle", v27, v28, v29, v30, v31, v32, v33, v34, "wma_pre_start");
      v45 = 4;
    }
  }
  else
  {
    v45 = 4;
  }
LABEL_10:
  qdf_trace_msg(0x36u, 8u, "%s: Exit", v17, v18, v19, v20, v21, v22, v23, v24, "wma_pre_start");
  return v45;
}
