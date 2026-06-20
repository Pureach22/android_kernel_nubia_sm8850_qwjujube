__int64 __fastcall os_if_dp_print_tuple(__int64 a1)
{
  __int64 v2; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x19
  unsigned __int16 v12; // w0
  unsigned __int16 v13; // w21
  __int16 v14; // w0
  unsigned __int16 v15; // w21
  __int16 v16; // w0
  __int16 v17; // w22
  __int16 v18; // w0
  unsigned __int16 v19; // w22
  __int16 v20; // w0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7

  v2 = _qdf_mem_malloc(0x100u, "os_if_dp_print_tuple", 187);
  if ( !v2 )
    return qdf_trace_msg(
             0x48u,
             8u,
             "%s: log buffer allocation failed",
             v3,
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             "os_if_dp_print_tuple");
  v11 = v2;
  scnprintf(v2, 256, "Flow tuple: ");
  v13 = v12;
  scnprintf(v11 + v12, 256 - v12, " 0x%x", *(_DWORD *)a1);
  v15 = v14 + v13;
  scnprintf(v11 + v15, 256 - v15, " 0x%x", *(_DWORD *)(a1 + 16));
  v17 = v16 + v15;
  scnprintf(
    v11 + (unsigned __int16)(v16 + v15),
    256 - (unsigned __int16)(v16 + v15),
    " %u",
    *(unsigned __int16 *)(a1 + 32));
  v19 = v18 + v17;
  scnprintf(v11 + v19, 256 - v19, " %u", *(unsigned __int16 *)(a1 + 34));
  v21 = scnprintf(
          v11 + (unsigned __int16)(v20 + v19),
          256 - (unsigned __int16)(v20 + v19),
          " %u",
          *(unsigned __int8 *)(a1 + 36));
  qdf_trace_msg(0x48u, 8u, "STC: %s", v21, v22, v23, v24, v25, v26, v27, v28, v11);
  return _qdf_mem_free(v11);
}
