__int64 __fastcall tgt_vdev_mgr_csa_received_handler(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        __int64 a10,
        __int64 a11)
{
  const char *v12; // x2

  if ( a1 )
  {
    if ( a11 )
    {
      if ( *(_BYTE *)(a11 + 8) )
        return policy_mgr_sta_sap_dfs_scc_conc_check();
      v12 = "%s: CSA IE Received without no-Tx mode, ignoring 1st SAP / GO movement";
    }
    else
    {
      v12 = "%s: CSA IE Received Event is NULL";
    }
  }
  else
  {
    v12 = "%s: PSOC is NULL";
  }
  qdf_trace_msg(0x68u, 2u, v12, a2, a3, a4, a5, a6, a7, a8, a9, "tgt_vdev_mgr_csa_received_handler");
  return 4;
}
