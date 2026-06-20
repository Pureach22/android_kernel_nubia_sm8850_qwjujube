__int64 __fastcall ipa_rm_add_dependency_sync_from_ioctl(unsigned int a1, unsigned int a2)
{
  __int64 ipc_logbuf; // x0
  const char *v5; // x4
  const char *v6; // x5
  __int64 ipc_logbuf_low; // x0
  const char *v8; // x4
  const char *v9; // x5
  __int64 v10; // x22
  unsigned int v11; // w21
  __int64 v12; // x0
  const char *v13; // x4
  const char *v14; // x5
  __int64 v15; // x0
  const char *v16; // x4
  const char *v17; // x5
  __int64 v18; // x0
  __int64 v19; // x21
  __int64 v20; // x0
  const char *v21; // x4
  const char *v22; // x5
  __int64 v23; // x0
  const char *v24; // x4
  const char *v25; // x5
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v29; // x0
  const char *v30; // x4
  __int64 v31; // x0
  const char *v32; // x4
  __int64 v33; // x0
  __int64 v34; // x0
  _QWORD v35[2]; // [xsp+0h] [xbp-10h] BYREF

  v35[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v35[0] = 0;
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
        ipc_log_string(ipc_logbuf, "ipa_rm %s:%d %s -> %s\n", "_ipa_rm_add_dependency_sync", 119, v5, v6);
LABEL_9:
        if ( !ipa3_get_ipc_logbuf_low() )
          goto LABEL_16;
        ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
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
            ipc_log_string(ipc_logbuf_low, "ipa_rm %s:%d %s -> %s\n", "_ipa_rm_add_dependency_sync", 119, v8, v9);
LABEL_16:
            v10 = raw_spin_lock_irqsave(ipa_rm_ctx + 16);
            v11 = ipa_rm_dep_graph_add_dependency(*(_QWORD *)ipa_rm_ctx, a1, a2, 1);
            raw_spin_unlock_irqrestore(ipa_rm_ctx + 16, v10);
            if ( v11 != -115 )
            {
LABEL_47:
              if ( ipa3_get_ipc_logbuf() )
              {
                v26 = ipa3_get_ipc_logbuf();
                ipc_log_string(v26, "ipa_rm %s:%d EXIT with %d\n", "_ipa_rm_add_dependency_sync", 150, v11);
              }
              if ( ipa3_get_ipc_logbuf_low() )
              {
                v27 = ipa3_get_ipc_logbuf_low();
                ipc_log_string(v27, "ipa_rm %s:%d EXIT with %d\n", "_ipa_rm_add_dependency_sync", 150, v11);
              }
              goto LABEL_51;
            }
            ipa_rm_dep_graph_get_resource(*(_QWORD *)ipa_rm_ctx, a2, v35);
            if ( !ipa3_get_ipc_logbuf() )
            {
LABEL_24:
              if ( !ipa3_get_ipc_logbuf_low() )
                goto LABEL_31;
              v15 = ipa3_get_ipc_logbuf_low();
              if ( a1 <= 0x15 )
              {
                v16 = resource_name_to_str[a1];
                if ( a2 <= 0x15 )
                  goto LABEL_27;
              }
              else
              {
                v16 = "INVALID RESOURCE";
                if ( a2 <= 0x15 )
                {
LABEL_27:
                  v17 = resource_name_to_str[a2];
LABEL_30:
                  ipc_log_string(
                    v15,
                    "ipa_rm %s:%d %s waits for GRANT of %s.\n",
                    "_ipa_rm_add_dependency_sync",
                    133,
                    v16,
                    v17);
LABEL_31:
                  v18 = wait_for_completion_timeout(v35[0] + 40LL, 1250);
                  if ( !v18 )
                  {
                    printk(&unk_3B15AF, "_ipa_rm_add_dependency_sync");
                    if ( ipa3_get_ipc_logbuf() )
                    {
                      v29 = ipa3_get_ipc_logbuf();
                      if ( a2 <= 0x15 )
                        v30 = resource_name_to_str[a2];
                      else
                        v30 = "INVALID RESOURCE";
                      ipc_log_string(
                        v29,
                        "ipa_rm %s:%d TIMEOUT waiting for %s GRANT event.",
                        "_ipa_rm_add_dependency_sync",
                        141,
                        v30);
                    }
                    if ( ipa3_get_ipc_logbuf_low() )
                    {
                      v31 = ipa3_get_ipc_logbuf_low();
                      if ( a2 <= 0x15 )
                        v32 = resource_name_to_str[a2];
                      else
                        v32 = "INVALID RESOURCE";
                      ipc_log_string(
                        v31,
                        "ipa_rm %s:%d TIMEOUT waiting for %s GRANT event.",
                        "_ipa_rm_add_dependency_sync",
                        141,
                        v32);
                      v11 = -62;
                    }
                    else
                    {
                      v11 = -62;
                    }
                    goto LABEL_47;
                  }
                  v19 = v18;
                  if ( !ipa3_get_ipc_logbuf() )
                  {
LABEL_39:
                    if ( !ipa3_get_ipc_logbuf_low() )
                    {
LABEL_46:
                      v11 = 0;
                      goto LABEL_47;
                    }
                    v23 = ipa3_get_ipc_logbuf_low();
                    if ( a1 <= 0x15 )
                    {
                      v24 = resource_name_to_str[a1];
                      if ( a2 <= 0x15 )
                        goto LABEL_42;
                    }
                    else
                    {
                      v24 = "INVALID RESOURCE";
                      if ( a2 <= 0x15 )
                      {
LABEL_42:
                        v25 = resource_name_to_str[a2];
LABEL_45:
                        ipc_log_string(
                          v23,
                          "ipa_rm %s:%d %s waited for %s GRANT %lu time.\n",
                          "_ipa_rm_add_dependency_sync",
                          147,
                          v24,
                          v25,
                          v19);
                        goto LABEL_46;
                      }
                    }
                    v25 = "INVALID RESOURCE";
                    goto LABEL_45;
                  }
                  v20 = ipa3_get_ipc_logbuf();
                  if ( a1 <= 0x15 )
                  {
                    v21 = resource_name_to_str[a1];
                    if ( a2 <= 0x15 )
                      goto LABEL_35;
                  }
                  else
                  {
                    v21 = "INVALID RESOURCE";
                    if ( a2 <= 0x15 )
                    {
LABEL_35:
                      v22 = resource_name_to_str[a2];
LABEL_38:
                      ipc_log_string(
                        v20,
                        "ipa_rm %s:%d %s waited for %s GRANT %lu time.\n",
                        "_ipa_rm_add_dependency_sync",
                        147,
                        v21,
                        v22,
                        v19);
                      goto LABEL_39;
                    }
                  }
                  v22 = "INVALID RESOURCE";
                  goto LABEL_38;
                }
              }
              v17 = "INVALID RESOURCE";
              goto LABEL_30;
            }
            v12 = ipa3_get_ipc_logbuf();
            if ( a1 <= 0x15 )
            {
              v13 = resource_name_to_str[a1];
              if ( a2 <= 0x15 )
                goto LABEL_20;
            }
            else
            {
              v13 = "INVALID RESOURCE";
              if ( a2 <= 0x15 )
              {
LABEL_20:
                v14 = resource_name_to_str[a2];
LABEL_23:
                ipc_log_string(
                  v12,
                  "ipa_rm %s:%d %s waits for GRANT of %s.\n",
                  "_ipa_rm_add_dependency_sync",
                  133,
                  v13,
                  v14);
                goto LABEL_24;
              }
            }
            v14 = "INVALID RESOURCE";
            goto LABEL_23;
          }
        }
        v9 = "INVALID RESOURCE";
        goto LABEL_15;
      }
    }
    v6 = "INVALID RESOURCE";
    goto LABEL_8;
  }
  printk(&unk_3F6CB5, "_ipa_rm_add_dependency_sync");
  if ( ipa3_get_ipc_logbuf() )
  {
    v33 = ipa3_get_ipc_logbuf();
    ipc_log_string(v33, "ipa_rm %s:%d IPA RM was not initialized\n", "_ipa_rm_add_dependency_sync", 114);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v34 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v34, "ipa_rm %s:%d IPA RM was not initialized\n", "_ipa_rm_add_dependency_sync", 114);
  }
  v11 = -22;
LABEL_51:
  _ReadStatusReg(SP_EL0);
  return v11;
}
