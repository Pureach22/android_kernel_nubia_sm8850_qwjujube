__int64 ipa_retrieve_and_dump()
{
  __int64 v0; // x19
  __int64 v1; // x8
  __int64 v2; // x0
  __int64 v3; // x0
  int regions; // w0
  __int64 v5; // x8
  __int64 v6; // x0
  __int64 v7; // x0
  unsigned int v8; // w20
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v12; // x8
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15[2]; // [xsp+0h] [xbp-10h] BYREF

  v15[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15[0] = 0;
  get_ipc_and_dmesg_logs();
  v0 = _kmalloc_noprof((num_of_regions_registered << 7) + 128, 3264);
  if ( !v0 )
  {
    printk(&unk_3B1F13, "ipa_retrieve_and_dump");
    v12 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v13 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v13 )
      {
        ipc_log_string(v13, "ipa %s:%d Memory not allocated\n", "ipa_retrieve_and_dump", 489);
        v12 = ipa3_ctx;
      }
      v14 = *(_QWORD *)(v12 + 34160);
      if ( v14 )
        ipc_log_string(v14, "ipa %s:%d Memory not allocated\n", "ipa_retrieve_and_dump", 489);
    }
    goto LABEL_13;
  }
  v1 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v2 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v2 )
    {
      ipc_log_string(v2, "ipa %s:%d ELF DUMP\n", "ipa_retrieve_and_dump", 493);
      v1 = ipa3_ctx;
    }
    v3 = *(_QWORD *)(v1 + 34160);
    if ( v3 )
      ipc_log_string(v3, "ipa %s:%d ELF DUMP\n", "ipa_retrieve_and_dump", 493);
  }
  regions = ipa_ssr_driver_dump_retrieve_regions(v0, v15);
  v5 = ipa3_ctx;
  if ( regions )
  {
    if ( ipa3_ctx )
    {
      v6 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v6 )
      {
        ipc_log_string(v6, "ipa %s:%d Error retrieving the regions\n", "ipa_retrieve_and_dump", 495);
        v5 = ipa3_ctx;
      }
      v7 = *(_QWORD *)(v5 + 34160);
      if ( v7 )
        ipc_log_string(v7, "ipa %s:%d Error retrieving the regions\n", "ipa_retrieve_and_dump", 495);
    }
LABEL_13:
    v8 = -1;
    goto LABEL_20;
  }
  if ( ipa3_ctx )
  {
    v9 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v9 )
    {
      ipc_log_string(v9, "ipa %s:%d ELF regions retrieved %zu\n", "ipa_retrieve_and_dump", 499, v15[0]);
      v5 = ipa3_ctx;
    }
    v10 = *(_QWORD *)(v5 + 34160);
    if ( v10 )
      ipc_log_string(v10, "ipa %s:%d ELF regions retrieved %zu\n", "ipa_retrieve_and_dump", 499, v15[0]);
  }
  ipa_do_host_ramdump(v0, v15[0]);
  v8 = 0;
LABEL_20:
  kfree(v0);
  _ReadStatusReg(SP_EL0);
  return v8;
}
