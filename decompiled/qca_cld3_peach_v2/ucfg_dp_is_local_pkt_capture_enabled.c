bool ucfg_dp_is_local_pkt_capture_enabled()
{
  __int64 **context; // x0
  double v1; // d0
  double v2; // d1
  double v3; // d2
  double v4; // d3
  double v5; // d4
  double v6; // d5
  double v7; // d6
  double v8; // d7
  __int64 v9; // x8
  unsigned int (*v10)(void); // x8

  context = (__int64 **)_cds_get_context(71, "ucfg_dp_is_local_pkt_capture_enabled");
  if ( !context || !*context )
  {
    qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance", v1, v2, v3, v4, v5, v6, v7, v8, "cdp_cfg_get");
    return 0;
  }
  v9 = **context;
  if ( !v9 )
    return 0;
  v10 = *(unsigned int (**)(void))(v9 + 264);
  if ( !v10 )
    return 0;
  if ( *((_DWORD *)v10 - 1) != -1095293032 )
    __break(0x8228u);
  return v10() != 0;
}
