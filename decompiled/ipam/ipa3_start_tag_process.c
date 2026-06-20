void ipa3_start_tag_process()
{
  __int64 v0; // x8
  __int64 v1; // x0
  __int64 v2; // x0
  int v3; // w0
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 v6; // x0
  int v7; // w19
  __int64 v8; // x8
  int v9; // w4
  __int64 v10; // x0
  __int64 v11; // x0

  v0 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v1 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v1 )
    {
      ipc_log_string(v1, "ipa %s:%d starting TAG process\n", "ipa3_start_tag_process", 6845);
      v0 = ipa3_ctx;
    }
    v2 = *(_QWORD *)(v0 + 34160);
    if ( v2 )
      ipc_log_string(v2, "ipa %s:%d starting TAG process\n", "ipa3_start_tag_process", 6845);
  }
  v3 = ipa3_tag_aggr_force_close(0xFFFFFFFFLL);
  if ( v3 )
  {
    v7 = v3;
    printk(&unk_3E3054, "ipa3_start_tag_process");
    v8 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v9 = v7;
      v10 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v10 )
      {
        ipc_log_string(v10, "ipa %s:%d ipa3_tag_aggr_force_close failed %d\n", "ipa3_start_tag_process", 6849, v7);
        v8 = ipa3_ctx;
        v9 = v7;
      }
      v11 = *(_QWORD *)(v8 + 34160);
      if ( v11 )
        ipc_log_string(v11, "ipa %s:%d ipa3_tag_aggr_force_close failed %d\n", "ipa3_start_tag_process", 6849, v9);
    }
  }
  _ipa3_dec_client_disable_clks();
  v4 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v5 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v5 )
    {
      ipc_log_string(v5, "ipa %s:%d TAG process done\n", "ipa3_start_tag_process", 6852);
      v4 = ipa3_ctx;
    }
    v6 = *(_QWORD *)(v4 + 34160);
    if ( v6 )
      ipc_log_string(v6, "ipa %s:%d TAG process done\n", "ipa3_start_tag_process", 6852);
  }
}
