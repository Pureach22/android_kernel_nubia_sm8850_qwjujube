__int64 __fastcall hdd_hif_close(
        __int64 result,
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
  _QWORD *v11; // x19
  double v12; // d0
  __int64 v13; // x2
  __int64 v14; // x3
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

  if ( !result )
    return qdf_trace_msg(0x33u, 2u, "%s: hdd_ctx error", a3, a4, a5, a6, a7, a8, a9, a10, "hdd_hif_close");
  if ( a2 )
  {
    v11 = (_QWORD *)result;
    cds_clear_driver_state(32, a3, a4, a5, a6, a7, a8, a9, a10);
    hif_disable(a2);
    v12 = hdd_napi_destroy(1);
    if ( (unsigned int)cds_set_context(0x3Du, 0, v13, v14, v12, v15, v16, v17, v18, v19, v20, v21) )
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Failed to reset CDS HIF Context",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "hdd_deinit_cds_hif_context");
    hif_close(a2);
    return ucfg_pmo_psoc_set_hif_handle(*v11, 0);
  }
  return result;
}
