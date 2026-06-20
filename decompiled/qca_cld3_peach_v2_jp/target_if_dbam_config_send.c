__int64 __fastcall target_if_dbam_config_send(
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
  __int64 v10; // x0
  __int64 result; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  unsigned int v20; // w19

  if ( a1 && (v9 = *(_QWORD *)(a1 + 2800)) != 0 && (v10 = *(_QWORD *)(v9 + 16)) != 0 )
  {
    result = wmi_unified_send_dbam_config_cmd(v10);
    if ( (_DWORD)result )
    {
      v20 = result;
      qdf_trace_msg(
        0x49u,
        2u,
        "%s: Failed to send DBAM config %d",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "target_if_dbam_config_send",
        (unsigned int)result);
      return v20;
    }
  }
  else
  {
    qdf_trace_msg(0x49u, 2u, "%s: Invalid WMI handle", a2, a3, a4, a5, a6, a7, a8, a9, "target_if_dbam_config_send");
    return 16;
  }
  return result;
}
