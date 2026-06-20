__int64 __fastcall tgt_fwol_register_ev_handler(
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
  __int64 psoc_obj; // x0
  _DWORD *v11; // x8
  unsigned int v12; // w19
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  const char *v22; // x2

  if ( !a1 )
  {
    v22 = "%s: NULL psoc handle";
LABEL_9:
    qdf_trace_msg(0x66u, 2u, v22, a2, a3, a4, a5, a6, a7, a8, a9, "tgt_fwol_register_ev_handler");
    return 4;
  }
  psoc_obj = fwol_get_psoc_obj(a1);
  if ( !psoc_obj )
  {
    v22 = "%s: Failed to get FWOL Obj";
    goto LABEL_9;
  }
  v11 = *(_DWORD **)(psoc_obj + 1368);
  if ( v11 )
  {
    if ( *(v11 - 1) != -1796695762 )
      __break(0x8228u);
    v12 = ((__int64 (__fastcall *)(__int64, _QWORD))v11)(a1, 0);
    qdf_trace_msg(
      0x66u,
      8u,
      "%s: reg_evt_handler, status:%d",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "tgt_fwol_register_ev_handler",
      v12);
    return v12;
  }
  else
  {
    qdf_trace_msg(0x66u, 1u, "%s: No reg_evt_handler", a2, a3, a4, a5, a6, a7, a8, a9, "tgt_fwol_register_ev_handler");
    return 16;
  }
}
