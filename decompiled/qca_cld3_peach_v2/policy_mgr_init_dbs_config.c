__int64 __fastcall policy_mgr_init_dbs_config(__int64 a1, int a2, int a3)
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
  int v14; // w8
  __int64 v15; // x19
  unsigned int v16; // w4
  unsigned int v17; // w5

  context = policy_mgr_get_context(a1);
  if ( !context )
    return qdf_trace_msg(
             0x4Fu,
             2u,
             "%s: Invalid Context",
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             v12,
             v13,
             "policy_mgr_init_dbs_config");
  v14 = *(unsigned __int8 *)(context + 2207);
  *(_QWORD *)(context + 1512) = 0;
  if ( v14 == 1 )
  {
    v15 = context;
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Disabling dual mac capabilities",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "policy_mgr_init_dbs_config");
    v16 = *(_DWORD *)(v15 + 1512);
    v17 = *(_DWORD *)(v15 + 1516);
    context = v15;
  }
  else
  {
    v16 = a2 & 0xF8000000;
    v17 = a3 & 0xE0000000;
    *(_DWORD *)(context + 1512) = a2 & 0xF8000000;
    *(_DWORD *)(context + 1516) = a3 & 0xE0000000;
  }
  *(_DWORD *)(context + 1504) = v16;
  *(_DWORD *)(context + 1508) = v17;
  return qdf_trace_msg(
           0x4Fu,
           8u,
           "%s: cur_scan_config:%x cur_fw_mode_config:%x",
           v6,
           v7,
           v8,
           v9,
           v10,
           v11,
           v12,
           v13,
           "policy_mgr_init_dbs_config");
}
