__int64 __fastcall dfs_print_nolhistory(
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
  __int64 result; // x0
  __int64 v11; // x19
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x20
  unsigned __int16 *v21; // x23
  unsigned int v22; // t1
  int num_chans; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v24; // [xsp+8h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    num_chans = dfs_get_num_chans();
    result = _qdf_mem_malloc(32LL * num_chans, "dfs_print_nolhistory", 292);
    if ( result )
    {
      v11 = result;
      utils_dfs_get_nol_history_chan_list(*(_QWORD *)(a1 + 14936), result, &num_chans);
      if ( num_chans )
      {
        if ( num_chans >= 1 )
        {
          v20 = 0;
          v21 = (unsigned __int16 *)v11;
          do
          {
            v22 = *v21;
            v21 += 16;
            qdf_trace_msg(
              0x27u,
              4u,
              "WLAN_DEBUG_DFS_ALWAYS : %s: nolhistory = %d channel = %d MHz",
              v12,
              v13,
              v14,
              v15,
              v16,
              v17,
              v18,
              v19,
              "dfs_print_nolhistory",
              (unsigned int)v20++,
              v22);
          }
          while ( v20 < num_chans );
        }
      }
      else
      {
        qdf_trace_msg(
          0x27u,
          2u,
          "WLAN_DEBUG_DFS_ALWAYS : %s: zero chans",
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          "dfs_print_nolhistory");
      }
      result = _qdf_mem_free(v11);
    }
  }
  else
  {
    result = qdf_trace_msg(
               0x27u,
               2u,
               "WLAN_DEBUG_DFS_ALWAYS : %s: dfs is NULL",
               a2,
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               "dfs_print_nolhistory");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
