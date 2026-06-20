__int64 __fastcall sap_init_dfs_channel_nol_list(
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
  _QWORD *context; // x0
  const char *v11; // x2

  if ( a1 )
  {
    context = _cds_get_context(53, (__int64)"sap_get_mac_context", a2, a3, a4, a5, a6, a7, a8, a9);
    if ( context )
    {
      utils_dfs_init_nol(context[2695]);
      return 0;
    }
    v11 = "%s: Invalid MAC context";
  }
  else
  {
    v11 = "%s: Invalid SAP context";
  }
  qdf_trace_msg(0x39u, 2u, v11, a2, a3, a4, a5, a6, a7, a8, a9, "sap_init_dfs_channel_nol_list");
  return 5;
}
