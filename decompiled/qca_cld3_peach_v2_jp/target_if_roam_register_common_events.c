__int64 __fastcall target_if_roam_register_common_events(
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
  __int64 v9; // x8
  _QWORD *v10; // x0
  __int64 result; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7

  if ( a1 && (v9 = *(_QWORD *)(a1 + 2800)) != 0 && (v10 = *(_QWORD **)(v9 + 16)) != nullptr )
  {
    result = wmi_unified_register_event_handler(
               v10,
               0x11u,
               (__int64)target_if_cm_roam_event,
               2u,
               a2,
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9);
    if ( !(_DWORD)result )
      return result;
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: wmi event registration failed, ret: %d",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "target_if_roam_register_common_events",
      (unsigned int)result);
  }
  else
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: handle is NULL",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "target_if_roam_register_common_events");
  }
  return 16;
}
