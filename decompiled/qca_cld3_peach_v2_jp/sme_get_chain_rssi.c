__int64 __fastcall sme_get_chain_rssi(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
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
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7

  qdf_trace_msg(0x34u, 8u, "%s: enter", a5, a6, a7, a8, a9, a10, a11, a12, "sme_get_chain_rssi");
  if ( a2 )
  {
    *(_QWORD *)(a1 + 14384) = a4;
    *(_QWORD *)(a1 + 14376) = a3;
    context = _cds_get_context(54, (__int64)"sme_get_chain_rssi", v16, v17, v18, v19, v20, v21, v22, v23);
    wma_get_chain_rssi(context, a2);
    qdf_trace_msg(0x34u, 8u, "%s: exit", v25, v26, v27, v28, v29, v30, v31, v32, "sme_get_chain_rssi");
    return 0;
  }
  else
  {
    qdf_trace_msg(0x34u, 2u, "%s: Invalid req params", v16, v17, v18, v19, v20, v21, v22, v23, "sme_get_chain_rssi");
    return 4;
  }
}
