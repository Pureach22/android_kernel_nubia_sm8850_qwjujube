__int64 __fastcall target_if_register_roam_vendor_control_param_event(
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
  __int64 result; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7

  result = wmi_unified_register_event_handler(
             a1,
             0xFEu,
             (__int64)target_if_get_roam_vendor_control_param_event_handler,
             2u,
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9);
  if ( (_DWORD)result )
    return qdf_trace_msg(
             0x49u,
             2u,
             "%s: wmi event(%u) registration failed, ret: %d",
             v10,
             v11,
             v12,
             v13,
             v14,
             v15,
             v16,
             v17,
             "target_if_register_roam_vendor_control_param_event",
             254,
             (unsigned int)result);
  return result;
}
