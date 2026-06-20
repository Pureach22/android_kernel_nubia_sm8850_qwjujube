__int64 __fastcall cds_enable(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  unsigned int v10; // w0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  const char *v19; // x2
  unsigned int v20; // w0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x0
  unsigned int v30; // w0
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 (****context)(void); // x0
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  unsigned int v48; // w0
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  __int64 v57; // x4
  const char *v58; // x2
  unsigned int v59; // w0
  __int64 v60; // x0
  __int64 result; // x0
  int v62; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v63; // [xsp+8h] [xbp-8h]

  v63 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v62 = 0;
  if ( !gp_cds_context )
  {
    v19 = "%s: Invalid CDS context";
LABEL_21:
    qdf_trace_msg(0x38u, 2u, v19, a2, a3, a4, a5, a6, a7, a8, a9, "cds_enable");
    goto LABEL_22;
  }
  if ( !*(_QWORD *)(gp_cds_context + 24) )
  {
    v19 = "%s: WMA NULL context";
    goto LABEL_21;
  }
  if ( !*(_QWORD *)(gp_cds_context + 8) )
  {
    v19 = "%s: MAC NULL context";
    goto LABEL_21;
  }
  v10 = wma_start();
  if ( v10 )
  {
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: Failed to start wma; status:%d",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "cds_enable",
      v10);
    goto LABEL_22;
  }
  qdf_mem_set(&v62, 4u, 0);
  v62 = 0;
  v20 = mac_start(*(_QWORD *)(gp_cds_context + 8), &v62);
  if ( v20 )
  {
    v29 = qdf_trace_msg(
            0x38u,
            2u,
            "%s: Failed to start MAC; status:%d",
            v21,
            v22,
            v23,
            v24,
            v25,
            v26,
            v27,
            v28,
            "cds_enable",
            v20);
    if ( !(unsigned int)wma_stop(v29) )
      goto LABEL_22;
    goto LABEL_20;
  }
  v30 = sme_start(*(_QWORD *)(gp_cds_context + 8));
  if ( v30 )
  {
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: Failed to start SME; status:%d",
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      "cds_enable",
      v30);
  }
  else
  {
    context = (__int64 (****)(void))_cds_get_context(71, (__int64)"cds_enable", v31, v32, v33, v34, v35, v36, v37, v38);
    v48 = ucfg_dp_txrx_attach_target(context, 0, v40, v41, v42, v43, v44, v45, v46, v47);
    if ( v48 )
    {
      v57 = v48;
      v58 = "%s: Failed to attach DP target; status:%d";
    }
    else
    {
      v59 = dispatcher_psoc_enable(a1);
      if ( !v59 )
      {
        hdd_component_psoc_enable(a1);
        result = 0;
        goto LABEL_23;
      }
      v57 = v59;
      v58 = "%s: dispatcher_psoc_enable failed; status:%d";
    }
    qdf_trace_msg(0x38u, 2u, v58, v49, v50, v51, v52, v53, v54, v55, v56, "cds_enable", v57);
    sme_stop(*(_QWORD *)(gp_cds_context + 8));
  }
  v60 = mac_stop(*(_QWORD *)(gp_cds_context + 8));
  if ( (unsigned int)wma_stop(v60) )
  {
LABEL_20:
    v19 = "%s: Failed to stop wma";
    goto LABEL_21;
  }
LABEL_22:
  result = 16;
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return result;
}
