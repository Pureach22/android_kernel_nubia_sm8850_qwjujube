__int64 ipa3_debugfs_remove()
{
  __int64 v0; // x0
  __int64 result; // x0
  __int64 v2; // x8
  __int64 v3; // x0

  v0 = dent;
  if ( (unsigned __int64)dent >= 0xFFFFFFFFFFFFF001LL )
  {
    result = printk(&unk_3A307E, "ipa3_debugfs_remove");
    v2 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v3 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v3 )
      {
        ipc_log_string(v3, "ipa %s:%d Debugfs:folder was not created.\n", "ipa3_debugfs_remove", 3869);
        v2 = ipa3_ctx;
      }
      result = *(_QWORD *)(v2 + 34160);
      if ( result )
        return ipc_log_string(result, "ipa %s:%d Debugfs:folder was not created.\n", "ipa3_debugfs_remove", 3869);
    }
  }
  else
  {
    if ( active_clients_buf )
    {
      kfree(active_clients_buf);
      v0 = dent;
      active_clients_buf = 0;
    }
    return debugfs_remove(v0);
  }
  return result;
}
