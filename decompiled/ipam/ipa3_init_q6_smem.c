__int64 ipa3_init_q6_smem()
{
  unsigned int inited; // w0
  unsigned int v1; // w0
  unsigned int v2; // w0
  unsigned int v3; // w0
  unsigned int v4; // w19
  __int64 v6; // x8
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x8
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x8
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x8
  __int64 v16; // x0
  __int64 v17; // x0

  ipa3_inc_client_enable_clks_no_log();
  inited = ipa3_init_smem_region(
             *(unsigned int *)(**(_QWORD **)(ipa3_ctx + 34176) + 200LL),
             *(unsigned int *)(**(_QWORD **)(ipa3_ctx + 34176) + 196LL));
  if ( inited )
  {
    v4 = inited;
    printk(&unk_3AED8F, "ipa3_init_q6_smem");
    v6 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v7 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v7 )
      {
        ipc_log_string(v7, "ipa %s:%d failed to initialize Modem RAM memory\n", "ipa3_init_q6_smem", 4663);
        v6 = ipa3_ctx;
      }
      v8 = *(_QWORD *)(v6 + 34160);
      if ( v8 )
        ipc_log_string(v8, "ipa %s:%d failed to initialize Modem RAM memory\n", "ipa3_init_q6_smem", 4663);
    }
  }
  else
  {
    v1 = ipa3_init_smem_region(
           *(unsigned int *)(**(_QWORD **)(ipa3_ctx + 34176) + 144LL),
           *(unsigned int *)(**(_QWORD **)(ipa3_ctx + 34176) + 140LL));
    if ( v1 )
    {
      v4 = v1;
      printk(&unk_3C8F4B, "ipa3_init_q6_smem");
      v9 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v10 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v10 )
        {
          ipc_log_string(v10, "ipa %s:%d failed to initialize Modem HDRs RAM memory\n", "ipa3_init_q6_smem", 4671);
          v9 = ipa3_ctx;
        }
        v11 = *(_QWORD *)(v9 + 34160);
        if ( v11 )
          ipc_log_string(v11, "ipa %s:%d failed to initialize Modem HDRs RAM memory\n", "ipa3_init_q6_smem", 4671);
      }
    }
    else
    {
      v2 = ipa3_init_smem_region(
             *(unsigned int *)(**(_QWORD **)(ipa3_ctx + 34176) + 164LL),
             *(unsigned int *)(**(_QWORD **)(ipa3_ctx + 34176) + 160LL));
      if ( v2 )
      {
        v4 = v2;
        printk(&unk_3FA521, "ipa3_init_q6_smem");
        v12 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v13 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v13 )
          {
            ipc_log_string(v13, "ipa %s:%d failed to initialize Modem proc ctx RAM memory\n", "ipa3_init_q6_smem", 4679);
            v12 = ipa3_ctx;
          }
          v14 = *(_QWORD *)(v12 + 34160);
          if ( v14 )
            ipc_log_string(v14, "ipa %s:%d failed to initialize Modem proc ctx RAM memory\n", "ipa3_init_q6_smem", 4679);
        }
      }
      else
      {
        v3 = ipa3_init_smem_region(
               *(unsigned int *)(**(_QWORD **)(ipa3_ctx + 34176) + 192LL),
               *(unsigned int *)(**(_QWORD **)(ipa3_ctx + 34176) + 188LL));
        if ( v3 )
        {
          v4 = v3;
          printk(&unk_3A5E45, "ipa3_init_q6_smem");
          v15 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v16 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v16 )
            {
              ipc_log_string(
                v16,
                "ipa %s:%d failed to initialize Modem Comp/Decomp RAM memory\n",
                "ipa3_init_q6_smem",
                4687);
              v15 = ipa3_ctx;
            }
            v17 = *(_QWORD *)(v15 + 34160);
            if ( v17 )
              ipc_log_string(
                v17,
                "ipa %s:%d failed to initialize Modem Comp/Decomp RAM memory\n",
                "ipa3_init_q6_smem",
                4687);
          }
        }
        else
        {
          v4 = 0;
        }
      }
    }
  }
  _ipa3_dec_client_disable_clks();
  return v4;
}
