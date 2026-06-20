__int64 __fastcall policy_mgr_change_mcc_go_beacon_interval(__int64 a1, unsigned int a2, int a3)
{
  __int64 context; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x21
  unsigned int (__fastcall *v15)(_QWORD); // x8
  const char *v16; // x2

  context = policy_mgr_get_context(a1);
  if ( context )
  {
    v14 = context;
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: UPDATE Beacon Params",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "policy_mgr_change_mcc_go_beacon_interval");
    if ( a3 != 1 )
      return 0;
    v15 = *(unsigned int (__fastcall **)(_QWORD))(v14 + 424);
    if ( !v15 )
    {
      v16 = "%s: sme_change_mcc_beacon_interval callback is NULL";
      goto LABEL_11;
    }
    if ( *((_DWORD *)v15 - 1) != 2029277559 )
      __break(0x8228u);
    if ( v15(a2) != 16 )
      return 0;
    v16 = "%s: Failed to update Beacon Params";
  }
  else
  {
    v16 = "%s: Invalid context";
  }
LABEL_11:
  qdf_trace_msg(0x4Fu, 2u, v16, v6, v7, v8, v9, v10, v11, v12, v13, "policy_mgr_change_mcc_go_beacon_interval");
  return 16;
}
