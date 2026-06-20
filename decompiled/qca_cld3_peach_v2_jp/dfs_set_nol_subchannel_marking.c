__int64 __fastcall dfs_set_nol_subchannel_marking(
        __int64 a1,
        char a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  const char *v10; // x4

  if ( !a1 )
    return 4294967291LL;
  *(_BYTE *)(a1 + 14986) = a2 & 1;
  if ( (a2 & 1) != 0 )
    v10 = "set";
  else
    v10 = "disabled";
  qdf_trace_msg(
    0x27u,
    4u,
    "WLAN_DEBUG_DFS_ALWAYS : %s: NOL subchannel marking is %s ",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "dfs_set_nol_subchannel_marking",
    v10);
  return qdf_status_to_os_return(0);
}
