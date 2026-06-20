__int64 __fastcall ipa_rm_add_dependency_from_ioctl(unsigned int a1, unsigned int a2)
{
  __int64 ipc_logbuf; // x0
  const char *v5; // x4
  const char *v6; // x5
  __int64 v7; // x0
  const char *v8; // x4
  const char *v9; // x5
  __int64 v10; // x21
  unsigned int v11; // w19
  __int64 v12; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v15; // x0
  __int64 v16; // x0

  if ( ipa_rm_ctx )
  {
    if ( !ipa3_get_ipc_logbuf() )
      goto LABEL_9;
    ipc_logbuf = ipa3_get_ipc_logbuf();
    if ( a1 <= 0x15 )
    {
      v5 = resource_name_to_str[a1];
      if ( a2 <= 0x15 )
        goto LABEL_5;
    }
    else
    {
      v5 = "INVALID RESOURCE";
      if ( a2 <= 0x15 )
      {
LABEL_5:
        v6 = resource_name_to_str[a2];
LABEL_8:
        ipc_log_string(ipc_logbuf, "ipa_rm %s:%d %s -> %s\n", "_ipa_rm_add_dependency", 72, v5, v6);
LABEL_9:
        if ( !ipa3_get_ipc_logbuf_low() )
        {
LABEL_16:
          v10 = raw_spin_lock_irqsave(ipa_rm_ctx + 16);
          v11 = ipa_rm_dep_graph_add_dependency(*(_QWORD *)ipa_rm_ctx, a1, a2, 1);
          raw_spin_unlock_irqrestore(ipa_rm_ctx + 16, v10);
          if ( ipa3_get_ipc_logbuf() )
          {
            v12 = ipa3_get_ipc_logbuf();
            ipc_log_string(v12, "ipa_rm %s:%d EXIT with %d\n", "_ipa_rm_add_dependency", 80, v11);
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
            ipc_log_string(ipc_logbuf_low, "ipa_rm %s:%d EXIT with %d\n", "_ipa_rm_add_dependency", 80, v11);
          }
          return v11;
        }
        v7 = ipa3_get_ipc_logbuf_low();
        if ( a1 <= 0x15 )
        {
          v8 = resource_name_to_str[a1];
          if ( a2 <= 0x15 )
            goto LABEL_12;
        }
        else
        {
          v8 = "INVALID RESOURCE";
          if ( a2 <= 0x15 )
          {
LABEL_12:
            v9 = resource_name_to_str[a2];
LABEL_15:
            ipc_log_string(v7, "ipa_rm %s:%d %s -> %s\n", "_ipa_rm_add_dependency", 72, v8, v9);
            goto LABEL_16;
          }
        }
        v9 = "INVALID RESOURCE";
        goto LABEL_15;
      }
    }
    v6 = "INVALID RESOURCE";
    goto LABEL_8;
  }
  printk(&unk_3F6CB5, "_ipa_rm_add_dependency");
  if ( ipa3_get_ipc_logbuf() )
  {
    v15 = ipa3_get_ipc_logbuf();
    ipc_log_string(v15, "ipa_rm %s:%d IPA RM was not initialized\n", "_ipa_rm_add_dependency", 67);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v16 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v16, "ipa_rm %s:%d IPA RM was not initialized\n", "_ipa_rm_add_dependency", 67);
  }
  return (unsigned int)-22;
}
