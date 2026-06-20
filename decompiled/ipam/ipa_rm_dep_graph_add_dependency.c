__int64 __fastcall ipa_rm_dep_graph_add_dependency(__int64 a1, unsigned int a2, unsigned int a3, char a4)
{
  unsigned int v8; // w0
  __int64 v9; // x23
  unsigned int v10; // w0
  __int64 v11; // x1
  unsigned int v12; // w19
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x19
  const char *v16; // x0
  __int64 v17; // x19
  const char *v18; // x4
  __int64 ipc_logbuf; // x20
  const char *v20; // x0
  __int64 ipc_logbuf_low; // x20
  const char *v22; // x4
  __int64 v23; // x0
  __int64 v24; // x0

  if ( a1 && a2 <= 0x15 && (a2 & 1) == 0 && a3 <= 0x15 && (a3 & 1) != 0 )
  {
    v8 = ipa_rm_prod_index(a2);
    if ( v8 != -1 )
    {
      if ( v8 >= 0x16 )
        goto LABEL_31;
      v9 = *(_QWORD *)(a1 + 8LL * v8);
      if ( v9 )
      {
        v10 = ipa_rm_cons_index(a3);
        if ( v10 == -1 )
        {
LABEL_21:
          ipa_rm_resource_str(a3);
          printk(&unk_3BFE17, "ipa_rm_dep_graph_add_dependency");
          if ( ipa3_get_ipc_logbuf() )
          {
            ipc_logbuf = ipa3_get_ipc_logbuf();
            v20 = ipa_rm_resource_str(a3);
            ipc_log_string(ipc_logbuf, "ipa_rm %s:%d %s does not exist\n", "ipa_rm_dep_graph_add_dependency", 176, v20);
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
            v22 = ipa_rm_resource_str(a3);
            ipc_log_string(
              ipc_logbuf_low,
              "ipa_rm %s:%d %s does not exist\n",
              "ipa_rm_dep_graph_add_dependency",
              176,
              v22);
          }
          goto LABEL_25;
        }
        if ( v10 < 0x16 )
        {
          v11 = *(_QWORD *)(a1 + 8LL * v10);
          if ( v11 )
          {
            v12 = ipa_rm_resource_add_dependency(v9, v11, a4 & 1);
            goto LABEL_26;
          }
          goto LABEL_21;
        }
LABEL_31:
        __break(0x5512u);
        JUMPOUT(0xFFFFFFFFFA5C6378LL);
      }
    }
    ipa_rm_resource_str(a2);
    printk(&unk_3BFE17, "ipa_rm_dep_graph_add_dependency");
    if ( ipa3_get_ipc_logbuf() )
    {
      v15 = ipa3_get_ipc_logbuf();
      v16 = ipa_rm_resource_str(a2);
      ipc_log_string(v15, "ipa_rm %s:%d %s does not exist\n", "ipa_rm_dep_graph_add_dependency", 168, v16);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v17 = ipa3_get_ipc_logbuf_low();
      v18 = ipa_rm_resource_str(a2);
      ipc_log_string(v17, "ipa_rm %s:%d %s does not exist\n", "ipa_rm_dep_graph_add_dependency", 168, v18);
    }
    goto LABEL_25;
  }
  printk(&unk_3DA65E, "ipa_rm_dep_graph_add_dependency");
  if ( ipa3_get_ipc_logbuf() )
  {
    v13 = ipa3_get_ipc_logbuf();
    ipc_log_string(v13, "ipa_rm %s:%d invalid params\n", "ipa_rm_dep_graph_add_dependency", 160);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v14 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v14, "ipa_rm %s:%d invalid params\n", "ipa_rm_dep_graph_add_dependency", 160);
    v12 = -22;
    goto LABEL_26;
  }
LABEL_25:
  v12 = -22;
LABEL_26:
  if ( ipa3_get_ipc_logbuf() )
  {
    v23 = ipa3_get_ipc_logbuf();
    ipc_log_string(v23, "ipa_rm %s:%d EXIT with %d\n", "ipa_rm_dep_graph_add_dependency", 183, v12);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v24 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v24, "ipa_rm %s:%d EXIT with %d\n", "ipa_rm_dep_graph_add_dependency", 183, v12);
  }
  return v12;
}
