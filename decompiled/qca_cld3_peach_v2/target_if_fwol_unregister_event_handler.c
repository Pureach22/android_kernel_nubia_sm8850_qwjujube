__int64 __fastcall target_if_fwol_unregister_event_handler(
        _QWORD *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  _QWORD *v9; // x19
  __int64 v10; // x8
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x8
  _QWORD *v20; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7

  v9 = a1;
  if ( a1 )
  {
    v10 = a1[350];
    if ( v10 )
      a1 = *(_QWORD **)(v10 + 16);
    else
      a1 = nullptr;
  }
  if ( (unsigned int)wmi_unified_unregister_event_handler(a1, 0x2Du, a2, a3, a4, a5, a6, a7, a8, a9) )
    qdf_trace_msg(
      0x49u,
      8u,
      "%s: Failed to unregister thermal stats event cb",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "target_if_fwol_unregister_thermal_throttle_handler");
  if ( v9 && (v19 = v9[350]) != 0 )
    v20 = *(_QWORD **)(v19 + 16);
  else
    v20 = nullptr;
  if ( (unsigned int)wmi_unified_unregister_event_handler(v20, 0xDDu, v11, v12, v13, v14, v15, v16, v17, v18) )
    qdf_trace_msg(
      0x49u,
      8u,
      "%s: Failed to unregister get eLNA bypass event cb",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "target_if_fwol_unregister_elna_event_handler");
  return 0;
}
