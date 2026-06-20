__int64 __fastcall sme_get_fw_state(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  _QWORD *context; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7

  qdf_trace_msg(0x34u, 8u, "%s: enter", a4, a5, a6, a7, a8, a9, a10, a11, "sme_get_fw_state");
  *(_QWORD *)(a1 + 14464) = a2;
  *(_QWORD *)(a1 + 14472) = a3;
  context = _cds_get_context(54, (__int64)"sme_get_fw_state", v14, v15, v16, v17, v18, v19, v20, v21);
  LODWORD(a3) = wma_get_fw_state(context);
  qdf_trace_msg(0x34u, 8u, "%s: exit", v23, v24, v25, v26, v27, v28, v29, v30, "sme_get_fw_state");
  return (unsigned int)a3;
}
