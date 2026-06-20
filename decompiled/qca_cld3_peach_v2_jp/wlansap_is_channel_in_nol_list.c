bool __fastcall wlansap_is_channel_in_nol_list(
        __int64 a1,
        unsigned int a2,
        int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  if ( a1 )
  {
    return sap_dfs_is_channel_in_nol_list(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);
  }
  else
  {
    qdf_trace_msg(
      0x39u,
      2u,
      "%s: Invalid SAP pointer from pCtx",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "wlansap_is_channel_in_nol_list");
    return 1;
  }
}
