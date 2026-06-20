__int64 ipa3_setup_dflt_rt_tables()
{
  __int64 v0; // x0
  __int64 v1; // x19
  __int64 v2; // x10
  int v3; // w9
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x8
  __int64 v8; // x0
  __int64 v9; // x0
  unsigned int v10; // w20
  __int64 v11; // x8
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x8
  __int64 v15; // x0
  __int64 v16; // x0

  v0 = _kmalloc_cache_noprof(raw_spin_lock_irqsave, 3520, 224);
  v1 = v0;
  if ( !v0 )
    return (unsigned int)-12;
  strcpy((char *)(v0 + 8), "ipa_dflt_rt");
  v2 = ipa3_ctx;
  *(_BYTE *)(v0 + 40) = 1;
  *(_BYTE *)v0 = 1;
  *(_DWORD *)(v0 + 4) = 0;
  *(_BYTE *)(v0 + 212) = 1;
  *(_DWORD *)(v0 + 44) = 33;
  v3 = *(_DWORD *)(v2 + 30384);
  *(_BYTE *)(v0 + 210) = 1;
  *(_DWORD *)(v0 + 48) = v3;
  if ( (unsigned int)ipa_add_rt_rule(v0) )
  {
    printk(&unk_3F6F1D, "ipa3_setup_dflt_rt_tables");
    v11 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v12 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v12 )
      {
        ipc_log_string(v12, "ipa %s:%d fail to add dflt v4 rule\n", "ipa3_setup_dflt_rt_tables", 4501);
        v11 = ipa3_ctx;
      }
      v13 = *(_QWORD *)(v11 + 34160);
      if ( v13 )
        ipc_log_string(v13, "ipa %s:%d fail to add dflt v4 rule\n", "ipa3_setup_dflt_rt_tables", 4501);
    }
  }
  else
  {
    v4 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v5 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v5 )
      {
        ipc_log_string(
          v5,
          "ipa %s:%d dflt v4 rt rule hdl=%x\n",
          "ipa3_setup_dflt_rt_tables",
          4505,
          *(_DWORD *)(v1 + 216));
        v4 = ipa3_ctx;
      }
      v6 = *(_QWORD *)(v4 + 34160);
      if ( v6 )
      {
        ipc_log_string(
          v6,
          "ipa %s:%d dflt v4 rt rule hdl=%x\n",
          "ipa3_setup_dflt_rt_tables",
          4505,
          *(_DWORD *)(v1 + 216));
        v4 = ipa3_ctx;
      }
    }
    *(_DWORD *)(v4 + 30388) = *(_DWORD *)(v1 + 216);
    *(_DWORD *)(v1 + 4) = 1;
    if ( !(unsigned int)ipa_add_rt_rule(v1) )
    {
      v7 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v8 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v8 )
        {
          ipc_log_string(
            v8,
            "ipa %s:%d dflt v6 rt rule hdl=%x\n",
            "ipa3_setup_dflt_rt_tables",
            4515,
            *(_DWORD *)(v1 + 216));
          v7 = ipa3_ctx;
        }
        v9 = *(_QWORD *)(v7 + 34160);
        if ( v9 )
        {
          ipc_log_string(
            v9,
            "ipa %s:%d dflt v6 rt rule hdl=%x\n",
            "ipa3_setup_dflt_rt_tables",
            4515,
            *(_DWORD *)(v1 + 216));
          v7 = ipa3_ctx;
        }
      }
      v10 = 0;
      *(_DWORD *)(v7 + 30392) = *(_DWORD *)(v1 + 216);
      goto LABEL_15;
    }
    printk(&unk_3D1D9A, "ipa3_setup_dflt_rt_tables");
    v14 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v15 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v15 )
      {
        ipc_log_string(v15, "ipa %s:%d fail to add dflt v6 rule\n", "ipa3_setup_dflt_rt_tables", 4511);
        v14 = ipa3_ctx;
      }
      v16 = *(_QWORD *)(v14 + 34160);
      if ( v16 )
        ipc_log_string(v16, "ipa %s:%d fail to add dflt v6 rule\n", "ipa3_setup_dflt_rt_tables", 4511);
    }
  }
  v10 = -1;
LABEL_15:
  kfree(v1);
  return v10;
}
