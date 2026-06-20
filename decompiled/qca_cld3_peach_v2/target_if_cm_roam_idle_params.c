__int64 __fastcall target_if_cm_roam_idle_params(
        __int64 a1,
        char a2,
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
  __int64 result; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned int v22; // w19

  if ( a2 == 2 )
    *(_BYTE *)(a3 + 4) = 0;
  if ( (wmi_service_enabled(a1, 0xACu, a4, a5, a6, a7, a8, a9, a10, a11) & 1) == 0 )
    *(_DWORD *)(a3 + 16) = (unsigned __int8)(*(_DWORD *)(a3 + 16) + 96);
  result = wmi_unified_send_idle_roam_params(a1, a3);
  if ( (_DWORD)result )
  {
    v22 = result;
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: failed to send idle roam parameters",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "target_if_cm_roam_idle_params");
    return v22;
  }
  return result;
}
