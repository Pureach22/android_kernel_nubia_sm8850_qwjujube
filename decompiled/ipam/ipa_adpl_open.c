__int64 ipa_adpl_open()
{
  __int64 v0; // x8
  __int64 v1; // x0
  __int64 v2; // x0
  unsigned int v3; // w19
  __int64 v5; // x0
  __int64 v6; // x8
  __int64 v7; // x0
  __int64 v8; // x8
  __int64 v9; // x0
  __int64 v10; // x0

  v0 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v1 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v1 )
    {
      ipc_log_string(v1, "ipa %s:%d Called the function :\n", "ipa_adpl_open", 431);
      v0 = ipa3_ctx;
    }
    v2 = *(_QWORD *)(v0 + 34160);
    if ( v2 )
      ipc_log_string(v2, "ipa %s:%d Called the function :\n", "ipa_adpl_open", 431);
  }
  mutex_lock(ipa3_odl_ctx + 384);
  if ( (*(_WORD *)(ipa3_odl_ctx + 692) & 5) == 1 )
  {
    if ( (unsigned int)ipa_pm_activate_sync(*(unsigned int *)(ipa3_odl_ctx + 716)) )
    {
      printk(&unk_3D5D44, "ipa_adpl_open");
      v8 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v9 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v9 )
        {
          ipc_log_string(v9, "ipa %s:%d failed to activate pm\n", "ipa_adpl_open", 438);
          v8 = ipa3_ctx;
        }
        v10 = *(_QWORD *)(v8 + 34160);
        if ( v10 )
          ipc_log_string(v10, "ipa %s:%d failed to activate pm\n", "ipa_adpl_open", 438);
      }
    }
    *(_WORD *)(ipa3_odl_ctx + 692) |= 4u;
    v3 = ipa3_odl_pipe_open();
  }
  else
  {
    v5 = printk(&unk_3CFFB1, "ipa_adpl_open");
    v6 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v7 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v7 )
      {
        ipc_log_string(v7, "ipa %s:%d Before odl init trying to open adpl pipe\n", "ipa_adpl_open", 442);
        v6 = ipa3_ctx;
      }
      v5 = *(_QWORD *)(v6 + 34160);
      if ( v5 )
        v5 = ipc_log_string(v5, "ipa %s:%d Before odl init trying to open adpl pipe\n", "ipa_adpl_open", 442);
    }
    print_ipa_odl_state_bit_mask(v5);
    v3 = -19;
  }
  mutex_unlock(ipa3_odl_ctx + 384);
  return v3;
}
