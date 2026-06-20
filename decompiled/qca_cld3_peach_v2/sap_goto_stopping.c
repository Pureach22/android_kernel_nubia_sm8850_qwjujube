__int64 __fastcall sap_goto_stopping(
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
  _QWORD *context; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  _QWORD *v19; // x20
  __int64 result; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7

  context = _cds_get_context(53, (__int64)"sap_get_mac_context", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( context )
  {
    v19 = context;
    sap_update_mcs_rate(a1, 0, v11, v12, v13, v14, v15, v16, v17, v18);
    qdf_mem_set((void *)(a1 + 32), 0x2B0u, 0);
    result = sme_roam_stop_bss(v19, *(unsigned __int8 *)(a1 + 12));
    if ( (_DWORD)result )
    {
      qdf_trace_msg(
        0x39u,
        2u,
        "%s: Calling sme_roam_stop_bss status = %d",
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        "sap_goto_stopping",
        (unsigned int)result);
      return 16;
    }
  }
  else
  {
    qdf_trace_msg(0x39u, 2u, "%s: Invalid MAC context", v11, v12, v13, v14, v15, v16, v17, v18, "sap_goto_stopping");
    return 5;
  }
  return result;
}
