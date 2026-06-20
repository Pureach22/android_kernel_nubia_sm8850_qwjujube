__int64 __fastcall target_if_fwol_get_elna_bypass(
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
  __int64 result; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  unsigned int v19; // w19

  if ( a1 && (v9 = *(_QWORD *)(a1 + 2800)) != 0 && *(_QWORD *)(v9 + 16) )
  {
    result = wmi_unified_send_get_elna_bypass_cmd();
    if ( (_DWORD)result )
    {
      v19 = result;
      qdf_trace_msg(
        0x49u,
        2u,
        "%s: Failed to set eLNA bypass %d",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "target_if_fwol_get_elna_bypass",
        (unsigned int)result);
      return v19;
    }
  }
  else
  {
    qdf_trace_msg(0x49u, 2u, "%s: Invalid wmi_handle", a2, a3, a4, a5, a6, a7, a8, a9, "target_if_fwol_get_elna_bypass");
    return 4;
  }
  return result;
}
