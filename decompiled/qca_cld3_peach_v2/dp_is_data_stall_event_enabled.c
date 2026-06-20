bool __fastcall dp_is_data_stall_event_enabled(int a1)
{
  __int64 **context; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x8
  __int64 (*v12)(void); // x8
  int v13; // w0

  context = (__int64 **)_cds_get_context(71, "dp_is_data_stall_event_enabled");
  if ( !context || !*context )
  {
    qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance", v3, v4, v5, v6, v7, v8, v9, v10, "cdp_cfg_get");
LABEL_9:
    v13 = 0;
    return (v13 & (a1 | 1)) != 0;
  }
  v11 = **context;
  if ( !v11 )
    goto LABEL_9;
  v12 = *(__int64 (**)(void))(v11 + 264);
  if ( !v12 )
    goto LABEL_9;
  if ( *((_DWORD *)v12 - 1) != -1095293032 )
    __break(0x8228u);
  v13 = v12();
  return (v13 & (a1 | 1)) != 0;
}
