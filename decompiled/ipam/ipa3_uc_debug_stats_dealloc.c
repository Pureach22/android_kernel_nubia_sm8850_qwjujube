__int64 __fastcall ipa3_uc_debug_stats_dealloc(int a1)
{
  __int64 v2; // x8
  __int64 v3; // x0
  __int64 v4; // x0
  unsigned int v5; // w19
  __int64 v6; // x8
  __int64 v7; // x20
  __int64 v8; // x8
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v12; // x8
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x8
  __int64 v16; // x0
  __int64 v17; // x0

  _ReadStatusReg(SP_EL0);
  v2 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v3 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v3 )
    {
      ipc_log_string(v3, "ipa %s:%d protocol %d\n", "ipa3_uc_debug_stats_dealloc", 1624, a1);
      v2 = ipa3_ctx;
    }
    v4 = *(_QWORD *)(v2 + 34160);
    if ( v4 )
      ipc_log_string(v4, "ipa %s:%d protocol %d\n", "ipa3_uc_debug_stats_dealloc", 1624, a1);
  }
  ipa3_inc_client_enable_clks();
  v5 = ipa3_uc_send_cmd_64b_param(a1, 0, 198, 192, 0, 2500);
  if ( v5 )
  {
    printk(&unk_3B02E4, "ipa3_uc_debug_stats_dealloc");
    v12 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v13 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v13 )
      {
        ipc_log_string(v13, "ipa %s:%d fail to dealloc offload stats\n", "ipa3_uc_debug_stats_dealloc", 1635);
        v12 = ipa3_ctx;
      }
      v14 = *(_QWORD *)(v12 + 34160);
      if ( v14 )
        ipc_log_string(v14, "ipa %s:%d fail to dealloc offload stats\n", "ipa3_uc_debug_stats_dealloc", 1635);
    }
  }
  else
  {
    if ( a1 <= 3 )
    {
      if ( a1 == 1 )
      {
        v6 = ipa3_ctx;
        v7 = 45080;
        goto LABEL_18;
      }
      if ( a1 == 3 )
      {
        v6 = ipa3_ctx;
        v7 = 44952;
        goto LABEL_18;
      }
    }
    else
    {
      switch ( a1 )
      {
        case 4:
          v6 = ipa3_ctx;
          v7 = 45032;
          goto LABEL_18;
        case 9:
          v6 = ipa3_ctx;
          v7 = 45096;
          goto LABEL_18;
        case 10:
          v6 = ipa3_ctx;
          v7 = 45112;
LABEL_18:
          iounmap(*(_QWORD *)(v6 + v7));
          *(_QWORD *)(ipa3_ctx + v7) = 0;
          goto LABEL_19;
      }
    }
    printk(&unk_3E6E2A, "ipa3_uc_debug_stats_dealloc");
    v15 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v16 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v16 )
      {
        ipc_log_string(v16, "ipa %s:%d unknown protocols %d\n", "ipa3_uc_debug_stats_dealloc", 1660, a1);
        v15 = ipa3_ctx;
      }
      v17 = *(_QWORD *)(v15 + 34160);
      if ( v17 )
        ipc_log_string(v17, "ipa %s:%d unknown protocols %d\n", "ipa3_uc_debug_stats_dealloc", 1660, a1);
    }
  }
LABEL_19:
  ipa3_dec_client_disable_clks();
  v8 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v9 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v9 )
    {
      ipc_log_string(v9, "ipa %s:%d exit\n", "ipa3_uc_debug_stats_dealloc", 1665);
      v8 = ipa3_ctx;
    }
    v10 = *(_QWORD *)(v8 + 34160);
    if ( v10 )
      ipc_log_string(v10, "ipa %s:%d exit\n", "ipa3_uc_debug_stats_dealloc", 1665);
  }
  _ReadStatusReg(SP_EL0);
  return v5;
}
