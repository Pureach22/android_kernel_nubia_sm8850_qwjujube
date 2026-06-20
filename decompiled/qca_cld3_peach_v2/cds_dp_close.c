__int64 __fastcall cds_dp_close(
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
  __int64 **v10; // x8
  __int64 v11; // x9
  void (__fastcall *v12)(_QWORD); // x9
  __int64 v13; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 **v30; // x0
  __int64 v31; // x8
  void (*v32)(void); // x8
  __int64 v33; // x8
  __int64 **v34; // x0

  v10 = *(__int64 ***)(gp_cds_context + 64);
  if ( v10 && *v10 )
  {
    v11 = **v10;
    if ( v11 )
    {
      v12 = *(void (__fastcall **)(_QWORD))(v11 + 552);
      if ( v12 )
      {
        v13 = *(_QWORD *)(gp_cds_context + 64);
        if ( *((_DWORD *)v12 - 1) != -1106481425 )
          __break(0x8229u);
        v12(v13);
      }
    }
  }
  else
  {
    qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance:", a2, a3, a4, a5, a6, a7, a8, a9, "cdp_txrx_intr_detach");
  }
  qdf_nbuf_stop_replenish_timer();
  if ( gp_cds_context )
  {
    if ( !*(_QWORD *)(gp_cds_context + 64) )
      qdf_trace_msg(
        0x38u,
        2u,
        "%s: Module ID %d context is Null (via %s)",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "__cds_get_context",
        71,
        "cds_dp_close");
  }
  else
  {
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: cds context pointer is null (via %s)",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "__cds_get_context",
      "cds_dp_close");
  }
  ucfg_dp_txrx_deinit();
  if ( !gp_cds_context )
  {
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: cds context pointer is null (via %s)",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "__cds_get_context",
      "cds_dp_close");
    goto LABEL_26;
  }
  v30 = *(__int64 ***)(gp_cds_context + 64);
  if ( !v30 )
  {
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: Module ID %d context is Null (via %s)",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "__cds_get_context",
      71,
      "cds_dp_close");
LABEL_26:
    qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance:", v22, v23, v24, v25, v26, v27, v28, v29, "cdp_pdev_deinit");
    v33 = gp_cds_context;
    if ( gp_cds_context )
      goto LABEL_22;
LABEL_27:
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: cds context pointer is null (via %s)",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "__cds_get_context",
      "cds_dp_close");
    goto LABEL_28;
  }
  if ( !*v30 )
    goto LABEL_26;
  v31 = **v30;
  if ( v31 )
  {
    v32 = *(void (**)(void))(v31 + 64);
    if ( v32 )
    {
      if ( *((_DWORD *)v32 - 1) != 226555140 )
        __break(0x8228u);
      v32();
    }
  }
  v33 = gp_cds_context;
  if ( !gp_cds_context )
    goto LABEL_27;
LABEL_22:
  v34 = *(__int64 ***)(v33 + 64);
  if ( !v34 )
  {
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: Module ID %d context is Null (via %s)",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "__cds_get_context",
      71,
      "cds_dp_close");
LABEL_28:
    v34 = nullptr;
  }
  ucfg_dp_txrx_pdev_detach(v34, 0, 1u);
  ucfg_pmo_psoc_set_txrx_pdev_id(a1, 255);
  return 0;
}
