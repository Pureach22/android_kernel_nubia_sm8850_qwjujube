__int64 __fastcall ipa3_app_clk_vote(int a1)
{
  __int64 v2; // x8
  __int64 v3; // x0
  __int64 v4; // x0
  int v5; // w9
  unsigned int v6; // w10
  unsigned int v7; // w19
  int v8; // w10
  __int64 v9; // x8
  __int64 v10; // x0
  __int64 v11; // x0
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
      ipc_log_string(v3, "ipa %s:%d In\n", "ipa3_app_clk_vote", 13951);
      v2 = ipa3_ctx;
    }
    v4 = *(_QWORD *)(v2 + 34160);
    if ( v4 )
    {
      ipc_log_string(v4, "ipa %s:%d In\n", "ipa3_app_clk_vote", 13951);
      v2 = ipa3_ctx;
    }
  }
  mutex_lock(v2 + 48800);
  switch ( a1 )
  {
    case 0:
      v8 = *(_DWORD *)(ipa3_ctx + 48848);
      if ( v8 )
      {
        *(_DWORD *)(ipa3_ctx + 48848) = v8 - 1;
        ipa3_dec_client_disable_clks();
        v7 = 0;
        goto LABEL_30;
      }
      goto LABEL_16;
    case 1:
      v6 = *(_DWORD *)(ipa3_ctx + 48848) + 1;
      if ( v6 <= 0x1F4 )
      {
        *(_DWORD *)(ipa3_ctx + 48848) = v6;
        ipa3_inc_client_enable_clks();
        v7 = 0;
        goto LABEL_30;
      }
      if ( (unsigned int)__ratelimit(&ipa3_app_clk_vote__rs, "ipa3_app_clk_vote") )
      {
        printk(&unk_3B8EA1, "ipa3_app_clk_vote");
        v12 = ipa3_ctx;
        if ( !ipa3_ctx )
          goto LABEL_29;
      }
      else
      {
        v12 = ipa3_ctx;
        if ( !ipa3_ctx )
          goto LABEL_29;
      }
      v13 = *(_QWORD *)(v12 + 34152);
      if ( v13 )
      {
        ipc_log_string(v13, "ipa %s:%d App vote count max hit\n", "ipa3_app_clk_vote", 13961);
        v12 = ipa3_ctx;
      }
      v14 = *(_QWORD *)(v12 + 34160);
      if ( v14 )
        ipc_log_string(v14, "ipa %s:%d App vote count max hit\n", "ipa3_app_clk_vote", 13961);
      goto LABEL_29;
    case 2:
      if ( *(_DWORD *)(ipa3_ctx + 48848) )
      {
        do
        {
          ipa3_dec_client_disable_clks();
          v5 = *(_DWORD *)(ipa3_ctx + 48848) - 1;
          *(_DWORD *)(ipa3_ctx + 48848) = v5;
        }
        while ( v5 );
      }
LABEL_16:
      v7 = 0;
      goto LABEL_30;
  }
  if ( (unsigned int)__ratelimit(&ipa3_app_clk_vote__rs_543, "ipa3_app_clk_vote") )
  {
    printk(&unk_3CA73A, "ipa3_app_clk_vote");
    v9 = ipa3_ctx;
    if ( ipa3_ctx )
      goto LABEL_19;
  }
  else
  {
    v9 = ipa3_ctx;
    if ( ipa3_ctx )
    {
LABEL_19:
      v10 = *(_QWORD *)(v9 + 34152);
      if ( v10 )
      {
        ipc_log_string(v10, "ipa %s:%d Unknown vote_type(%u)\n", "ipa3_app_clk_vote", 13979, a1);
        v9 = ipa3_ctx;
      }
      v11 = *(_QWORD *)(v9 + 34160);
      if ( v11 )
        ipc_log_string(v11, "ipa %s:%d Unknown vote_type(%u)\n", "ipa3_app_clk_vote", 13979, a1);
    }
  }
LABEL_29:
  v7 = -1;
LABEL_30:
  mutex_unlock(ipa3_ctx + 48800);
  v15 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v16 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v16 )
    {
      ipc_log_string(v16, "ipa %s:%d Out\n", "ipa3_app_clk_vote", 13986);
      v15 = ipa3_ctx;
    }
    v17 = *(_QWORD *)(v15 + 34160);
    if ( v17 )
      ipc_log_string(v17, "ipa %s:%d Out\n", "ipa3_app_clk_vote", 13986);
  }
  _ReadStatusReg(SP_EL0);
  return v7;
}
