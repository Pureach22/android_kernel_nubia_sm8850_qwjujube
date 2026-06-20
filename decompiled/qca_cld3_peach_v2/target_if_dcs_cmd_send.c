__int64 __fastcall target_if_dcs_cmd_send(
        __int64 a1,
        __int64 a2,
        char a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x8
  __int64 v12; // x0
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
  const char *v23; // x2

  if ( !a1 )
  {
    v23 = "%s: null psoc";
    goto LABEL_8;
  }
  v11 = *(_QWORD *)(a1 + 2800);
  if ( !v11 || (v12 = *(_QWORD *)(v11 + 16)) == 0 )
  {
    v23 = "%s: null handle";
LABEL_8:
    qdf_trace_msg(0x49u, 2u, v23, a4, a5, a6, a7, a8, a9, a10, a11, "target_if_dcs_cmd_send");
    return 16;
  }
  result = wmi_send_dcs_pdev_param(v12, a2, a3 & 1);
  if ( (_DWORD)result )
  {
    v22 = result;
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: wmi dcs cmd send failed, ret: %d",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "target_if_dcs_cmd_send",
      (unsigned int)result);
    return v22;
  }
  return result;
}
