__int64 __fastcall wlansap_set_dfs_nol(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *context; // x0
  _QWORD *v12; // x19
  const char *v13; // x2

  if ( !a1 )
  {
    v13 = "%s: Invalid SAP pointer";
LABEL_9:
    qdf_trace_msg(0x39u, 2u, v13, a3, a4, a5, a6, a7, a8, a9, a10, "wlansap_set_dfs_nol");
    return 5;
  }
  context = _cds_get_context(53, (__int64)"sap_get_mac_context", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !context )
  {
    v13 = "%s: Invalid MAC context";
    goto LABEL_9;
  }
  if ( a2 == 1 )
  {
    qdf_trace_msg(0x39u, 2u, "%s: Randomize the DFS NOL", a3, a4, a5, a6, a7, a8, a9, a10, "wlansap_set_dfs_nol");
    return 0;
  }
  if ( a2 )
  {
    qdf_trace_msg(0x39u, 2u, "%s: unsupported type %d", a3, a4, a5, a6, a7, a8, a9, a10, "wlansap_set_dfs_nol", a2);
    return 0;
  }
  v12 = context;
  qdf_trace_msg(0x39u, 2u, "%s: clear the DFS NOL", a3, a4, a5, a6, a7, a8, a9, a10, "wlansap_set_dfs_nol");
  if ( !v12[2704] )
  {
    v13 = "%s: null pdev";
    goto LABEL_9;
  }
  utils_dfs_clear_nol_channels();
  return 0;
}
