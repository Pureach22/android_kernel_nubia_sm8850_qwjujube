void __fastcall ipa_wigig_init_debugfs(__int64 a1)
{
  unsigned __int64 file; // x0
  unsigned __int64 v3; // x0
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0

  file = debugfs_create_file("conn_clients", 292, a1, 0, &ipa_wigig_conn_clients_ops);
  *(_QWORD *)(ipa_wigig_ctx + 920) = file;
  if ( file && file < 0xFFFFFFFFFFFFF001LL )
  {
    v3 = debugfs_create_file("smmu", 292, a1, 0, &ipa_wigig_smmu_ops);
    *(_QWORD *)(ipa_wigig_ctx + 928) = v3;
    if ( !v3 || v3 >= 0xFFFFFFFFFFFFF001LL )
    {
      printk(&unk_3CE7B2, "ipa_wigig_init_debugfs");
      if ( ipa3_get_ipc_logbuf() )
      {
        ipc_logbuf = ipa3_get_ipc_logbuf();
        ipc_log_string(ipc_logbuf, "ipa_wigig %s:%d fail to create file %s\n", "ipa_wigig_init_debugfs", 2056, "smmu");
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          ipc_logbuf_low,
          "ipa_wigig %s:%d fail to create file %s\n",
          "ipa_wigig_init_debugfs",
          2056,
          "smmu");
      }
      debugfs_remove(*(_QWORD *)(ipa_wigig_ctx + 920));
    }
  }
  else
  {
    printk(&unk_3CE7B2, "ipa_wigig_init_debugfs");
    if ( ipa3_get_ipc_logbuf() )
    {
      v4 = ipa3_get_ipc_logbuf();
      ipc_log_string(v4, "ipa_wigig %s:%d fail to create file %s\n", "ipa_wigig_init_debugfs", 2048, "conn_clients");
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v5 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v5, "ipa_wigig %s:%d fail to create file %s\n", "ipa_wigig_init_debugfs", 2048, "conn_clients");
    }
  }
}
