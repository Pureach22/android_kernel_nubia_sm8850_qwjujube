__int64 __fastcall wlansap_get_dfs_cac_state(
        __int64 a1,
        __int64 a2,
        _BYTE *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  const char *v12; // x2

  if ( a1 )
  {
    if ( a2 )
    {
      *a3 = (unsigned __int8)sap_is_dfs_cac_wait_state(a2, a4, a5, a6, a7, a8, a9, a10, a11) & 1;
      return 0;
    }
    v12 = "%s: Invalid sapcontext pointer";
  }
  else
  {
    v12 = "%s: Invalid mac_handle pointer";
  }
  qdf_trace_msg(0x39u, 2u, v12, a4, a5, a6, a7, a8, a9, a10, a11, "wlansap_get_dfs_cac_state");
  return 5;
}
