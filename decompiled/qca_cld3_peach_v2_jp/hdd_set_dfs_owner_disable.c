__int64 __fastcall hdd_set_dfs_owner_disable(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 *v10; // x19
  __int64 v11; // x8
  char v12; // w20

  v10 = *(__int64 **)(*(_QWORD *)a1 + 24LL);
  v11 = v10[3];
  if ( !v11 || *(_BYTE *)(v11 + 1304) != 1 )
    return 4294967274LL;
  v12 = *(_BYTE *)(a2 + 4) != 0;
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: configure DFS owner disable %d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "hdd_set_dfs_owner_disable");
  ucfg_mlme_vendor_set_disable_dfs_master_capability(*v10, v12);
  hdd_send_wiphy_regd_sync_event(v10, 0);
  return 0;
}
