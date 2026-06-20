__int64 __fastcall target_if_wifi_pos_send_rtt_pasn_auth_status(
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
  const char *v21; // x4

  if ( !a1 )
  {
    v21 = "psoc";
    goto LABEL_8;
  }
  v9 = *(_QWORD *)(a1 + 2800);
  if ( !v9 || (v10 = *(_QWORD *)(v9 + 16)) == 0 )
  {
    v21 = "wmi_handle";
LABEL_8:
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: %s is null",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "target_if_wifi_pos_send_rtt_pasn_auth_status",
      v21);
    return 4;
  }
  result = wmi_send_rtt_pasn_auth_status_cmd(v10);
  if ( (_DWORD)result )
  {
    v20 = result;
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: send pasn auth status cmd failed",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "target_if_wifi_pos_send_rtt_pasn_auth_status");
    return v20;
  }
  return result;
}
