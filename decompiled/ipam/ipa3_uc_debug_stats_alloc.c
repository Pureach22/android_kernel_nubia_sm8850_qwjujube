__int64 __fastcall ipa3_uc_debug_stats_alloc(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  __int64 v5; // x0
  unsigned int v6; // w19
  __int64 v7; // x8
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v11; // x8
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // [xsp+20h] [xbp-20h]
  __int64 v15; // [xsp+28h] [xbp-18h] BYREF
  __int64 v16; // [xsp+30h] [xbp-10h]
  __int64 v17; // [xsp+38h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15 = 0;
  v16 = 0;
  v4 = *(_QWORD *)(ipa3_ctx + 34224);
  LODWORD(v16) = 14;
  v5 = dma_alloc_attrs(v4, 14, &v15, 3264, 0);
  v14 = v5;
  if ( v5 )
  {
    *(_QWORD *)v5 = a1;
    *(_DWORD *)(v5 + 8) = a2;
    *(_WORD *)(v5 + 12) = WORD2(a2);
    ipa3_inc_client_enable_clks();
    v6 = ipa3_uc_send_cmd_64b_param(v15, 0, 197, 192, 0, 5000);
    if ( v6 )
    {
      printk(&unk_3D6483, "ipa3_uc_debug_stats_alloc");
      v11 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v12 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v12 )
        {
          ipc_log_string(v12, "ipa %s:%d fail to alloc offload stats\n", "ipa3_uc_debug_stats_alloc", 1606);
          v11 = ipa3_ctx;
        }
        v13 = *(_QWORD *)(v11 + 34160);
        if ( v13 )
          ipc_log_string(v13, "ipa %s:%d fail to alloc offload stats\n", "ipa3_uc_debug_stats_alloc", 1606);
      }
    }
    dma_free_attrs(*(_QWORD *)(ipa3_ctx + 34224), (unsigned int)v16, v14, v15, 0);
    ipa3_dec_client_disable_clks();
    v7 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v8 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v8 )
      {
        ipc_log_string(v8, "ipa %s:%d exit\n", "ipa3_uc_debug_stats_alloc", 1615);
        v7 = ipa3_ctx;
      }
      v9 = *(_QWORD *)(v7 + 34160);
      if ( v9 )
        ipc_log_string(v9, "ipa %s:%d exit\n", "ipa3_uc_debug_stats_alloc", 1615);
    }
  }
  else
  {
    v6 = -12;
  }
  _ReadStatusReg(SP_EL0);
  return v6;
}
