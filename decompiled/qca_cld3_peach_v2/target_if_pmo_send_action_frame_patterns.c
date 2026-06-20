__int64 __fastcall target_if_pmo_send_action_frame_patterns(
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
  __int64 v10; // x8
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
    v23 = "%s: vdev ptr passed is NULL";
    goto LABEL_11;
  }
  v9 = *(_QWORD *)(a1 + 216);
  if ( !v9 || (v10 = *(_QWORD *)(v9 + 80)) == 0 )
  {
    v23 = "%s: psoc handle is NULL";
LABEL_11:
    qdf_trace_msg(0x49u, 2u, v23, a2, a3, a4, a5, a6, a7, a8, a9, "target_if_pmo_send_action_frame_patterns");
    return 4;
  }
  v11 = *(_QWORD *)(v10 + 2800);
  if ( !v11 || (v12 = *(_QWORD *)(v11 + 16)) == 0 )
  {
    v23 = "%s: Invalid wmi handle";
    goto LABEL_11;
  }
  result = wmi_unified_action_frame_patterns_cmd(v12);
  if ( (_DWORD)result )
  {
    v22 = result;
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: Failed to config wow action frame map, ret %d",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "target_if_pmo_send_action_frame_patterns",
      (unsigned int)result);
    return v22;
  }
  return result;
}
