__int64 init_module()
{
  __int64 v0; // x8
  __int64 v1; // x0
  __int64 v2; // x0
  unsigned int v3; // w0
  unsigned int inited; // w19
  int v6; // w19
  __int64 v7; // x0
  __int64 v8; // x8
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x8
  __int64 v12; // x0

  v0 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v1 = *(_QWORD *)(ipa3_ctx + 34152LL);
    if ( v1 )
    {
      ipc_log_string(v1, "ipa %s:%d IPA late init\n", "ipa_late_init", 30);
      v0 = ipa3_ctx;
    }
    v2 = *(_QWORD *)(v0 + 34160);
    if ( v2 )
      ipc_log_string(v2, "ipa %s:%d IPA late init\n", "ipa_late_init", 30);
  }
  v3 = ipa3_wwan_platform_driver_register();
  if ( v3 )
  {
    v6 = v3;
    v7 = printk(&unk_639C, "ipa_late_init", 35, v3);
    v8 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v9 = *(_QWORD *)(ipa3_ctx + 34152LL);
      if ( v9 )
      {
        ipc_log_string(v9, "ipa %s:%d ipa3_wwan_platform_driver_register failed: %d\n", "ipa_late_init", 35, v6);
        v8 = ipa3_ctx;
      }
      v7 = *(_QWORD *)(v8 + 34160);
      if ( v7 )
        v7 = ipc_log_string(v7, "ipa %s:%d ipa3_wwan_platform_driver_register failed: %d\n", "ipa_late_init", 35, v6);
    }
    ipa3_wwan_cleanup(v7);
  }
  inited = rndis_ipa_init_module();
  if ( inited )
  {
    v10 = printk(&unk_6329, "ipa_late_init", 42, inited);
    v11 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v12 = *(_QWORD *)(ipa3_ctx + 34152LL);
      if ( v12 )
      {
        ipc_log_string(v12, "ipa %s:%d rndis_ipa_init_module failed: %d\n", "ipa_late_init", 42, inited);
        v11 = ipa3_ctx;
      }
      v10 = *(_QWORD *)(v11 + 34160);
      if ( v10 )
        v10 = ipc_log_string(v10, "ipa %s:%d rndis_ipa_init_module failed: %d\n", "ipa_late_init", 42, inited);
    }
    rndis_ipa_cleanup_module(v10);
  }
  return inited;
}
