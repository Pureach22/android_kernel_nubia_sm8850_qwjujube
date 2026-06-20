__int64 __fastcall sme_oem_data_cmd(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        char a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  _QWORD *context; // x0
  _QWORD *v25; // x23
  unsigned int started; // w19
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7

  qdf_trace_msg(0x34u, 8u, "%s: enter", a5, a6, a7, a8, a9, a10, a11, a12, "sme_oem_data_cmd");
  context = _cds_get_context(54, (__int64)"sme_oem_data_cmd", v16, v17, v18, v19, v20, v21, v22, v23);
  if ( context )
  {
    v25 = context;
    if ( !(unsigned int)qdf_mutex_acquire(a1 + 12776) )
    {
      *(_QWORD *)(a1 + 14552) = a2;
      *(_BYTE *)(a1 + 14560) = a4;
      qdf_mutex_release(a1 + 12776);
    }
    started = wma_start_oem_data_cmd(v25, a3);
    if ( started )
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: fail to call wma_start_oem_data_cmd.",
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        "sme_oem_data_cmd");
    qdf_trace_msg(0x34u, 8u, "%s: exit", v27, v28, v29, v30, v31, v32, v33, v34, "sme_oem_data_cmd");
  }
  else
  {
    return 16;
  }
  return started;
}
