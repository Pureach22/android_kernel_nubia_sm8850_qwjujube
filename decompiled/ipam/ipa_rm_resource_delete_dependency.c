__int64 __fastcall ipa_rm_resource_delete_dependency(__int64 a1, __int64 a2, char a3)
{
  int v6; // w22
  __int64 v7; // x0
  __int64 v8; // x21
  const char *v9; // x0
  __int64 v10; // x21
  const char *v11; // x0
  int v12; // w8
  unsigned int v13; // w21
  int v14; // w8
  int v15; // w9
  int v16; // w22
  int v17; // w21
  int v18; // w8
  __int64 v19; // x0
  const char *v20; // x4
  __int64 v21; // x0
  const char *v22; // x4
  __int64 v23; // x0
  const char *v24; // x4
  __int64 v25; // x0
  const char *v26; // x4
  int v27; // w9
  unsigned int v28; // w0
  __int64 v29; // x21
  const char *v30; // x0
  __int64 v31; // x21
  const char *v32; // x0
  __int64 v33; // x0
  __int64 v34; // x0
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v37; // x0
  __int64 v38; // x0
  _BYTE v40[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v41; // [xsp+8h] [xbp-8h]

  v41 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v40[0] = 0;
  if ( !a1 || !a2 )
  {
    printk(&unk_3DA65E, "ipa_rm_resource_delete_dependency");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(ipc_logbuf, "ipa_rm %s:%d invalid params\n", "ipa_rm_resource_delete_dependency", 699);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      ipc_log_string(ipc_logbuf_low, "ipa_rm %s:%d invalid params\n", "ipa_rm_resource_delete_dependency", 699);
    }
    goto LABEL_69;
  }
  if ( (ipa_rm_peers_list_check_dependency(
          *(_QWORD **)(a1 + 24),
          *(_DWORD *)a1,
          *(_QWORD **)(a2 + 24),
          *(_DWORD *)a2,
          v40)
      & 1) == 0 )
  {
    printk(&unk_3B7138, "ipa_rm_resource_delete_dependency");
    if ( ipa3_get_ipc_logbuf() )
    {
      v37 = ipa3_get_ipc_logbuf();
      ipc_log_string(v37, "ipa_rm %s:%d dependency does not exist\n", "ipa_rm_resource_delete_dependency", 708);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v38 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v38, "ipa_rm %s:%d dependency does not exist\n", "ipa_rm_resource_delete_dependency", 708);
    }
LABEL_69:
    v13 = -22;
    goto LABEL_70;
  }
  v6 = v40[0];
  v7 = ipa3_get_ipc_logbuf();
  if ( v6 == (a3 & 1) )
  {
    if ( v7 )
    {
      v8 = ipa3_get_ipc_logbuf();
      v9 = ipa_rm_resource_str(*(_DWORD *)a1);
      ipc_log_string(
        v8,
        "ipa_rm %s:%d %s state: %d\n",
        "ipa_rm_resource_delete_dependency",
        725,
        v9,
        *(_DWORD *)(a1 + 20));
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v10 = ipa3_get_ipc_logbuf_low();
      v11 = ipa_rm_resource_str(*(_DWORD *)a1);
      ipc_log_string(
        v10,
        "ipa_rm %s:%d %s state: %d\n",
        "ipa_rm_resource_delete_dependency",
        725,
        v11,
        *(_DWORD *)(a1 + 20));
    }
    v12 = *(_DWORD *)(a1 + 20);
    v13 = -22;
    *(_DWORD *)(a1 + 16) -= *(_DWORD *)(a2 + 12);
    if ( v12 > 1 )
    {
      if ( v12 != 3 )
      {
        if ( v12 == 2 )
        {
          ipa_rm_perf_profile_change(*(_DWORD *)a1);
          v16 = 1;
          if ( !ipa3_get_ipc_logbuf() )
            goto LABEL_50;
          goto LABEL_49;
        }
        goto LABEL_55;
      }
      v18 = *(_DWORD *)(a1 + 52);
      v27 = v18 - 1;
      if ( v18 >= 1 )
      {
        --v18;
        *(_DWORD *)(a1 + 52) = v27;
      }
      if ( *(_DWORD *)(a2 + 20) == 3 )
      {
        v16 = 0;
        if ( v18 )
          goto LABEL_48;
        v17 = 1;
        goto LABEL_47;
      }
    }
    else if ( v12 )
    {
      if ( v12 == 1 )
      {
        v14 = *(_DWORD *)(a1 + 48);
        v15 = v14 - 1;
        if ( v14 >= 1 )
        {
          --v14;
          *(_DWORD *)(a1 + 48) = v15;
        }
        v16 = 1;
        if ( *(_DWORD *)(a2 + 20) != 1 || v14 )
        {
LABEL_48:
          if ( !ipa3_get_ipc_logbuf() )
          {
LABEL_50:
            if ( ipa3_get_ipc_logbuf_low() )
            {
              v31 = ipa3_get_ipc_logbuf_low();
              v32 = ipa_rm_resource_str(*(_DWORD *)a1);
              ipc_log_string(
                v31,
                "ipa_rm %s:%d %s new state: %d\n",
                "ipa_rm_resource_delete_dependency",
                775,
                v32,
                *(_DWORD *)(a1 + 20));
            }
            ipa_rm_peers_list_remove_peer(*(_QWORD *)(a1 + 24), *(_DWORD *)a2);
            ipa_rm_peers_list_remove_peer(*(_QWORD *)(a2 + 24), *(_DWORD *)a1);
            if ( v16 )
              ipa_rm_resource_consumer_release((unsigned int *)a2, *(_DWORD *)(a1 + 12), 1);
            v13 = 0;
            goto LABEL_55;
          }
LABEL_49:
          v29 = ipa3_get_ipc_logbuf();
          v30 = ipa_rm_resource_str(*(_DWORD *)a1);
          ipc_log_string(
            v29,
            "ipa_rm %s:%d %s new state: %d\n",
            "ipa_rm_resource_delete_dependency",
            775,
            v30,
            *(_DWORD *)(a1 + 20));
          goto LABEL_50;
        }
        v17 = 0;
        v18 = 2;
LABEL_47:
        v28 = *(_DWORD *)a1;
        *(_DWORD *)(a1 + 20) = v18;
        ipa_rm_perf_profile_change(v28);
        ipa_rm_wq_send_cmd(0, *(_DWORD *)a1, v17, 0);
        goto LABEL_48;
      }
LABEL_55:
      if ( ipa3_get_ipc_logbuf() )
      {
        v33 = ipa3_get_ipc_logbuf();
        ipc_log_string(v33, "ipa_rm %s:%d EXIT with %d\n", "ipa_rm_resource_delete_dependency", 786, v13);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v34 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v34, "ipa_rm %s:%d EXIT with %d\n", "ipa_rm_resource_delete_dependency", 786, v13);
      }
      goto LABEL_70;
    }
    v16 = 0;
    if ( !ipa3_get_ipc_logbuf() )
      goto LABEL_50;
    goto LABEL_49;
  }
  if ( v7 )
  {
    v19 = ipa3_get_ipc_logbuf();
    if ( v40[0] )
      v20 = "userspace";
    else
      v20 = "kernel";
    ipc_log_string(v19, "ipa_rm %s:%d dependency was added by %s\n", "ipa_rm_resource_delete_dependency", 718, v20);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v21 = ipa3_get_ipc_logbuf_low();
    if ( v40[0] )
      v22 = "userspace";
    else
      v22 = "kernel";
    ipc_log_string(v21, "ipa_rm %s:%d dependency was added by %s\n", "ipa_rm_resource_delete_dependency", 718, v22);
  }
  if ( ipa3_get_ipc_logbuf() )
  {
    v23 = ipa3_get_ipc_logbuf();
    if ( (a3 & 1) != 0 )
      v24 = "userspace";
    else
      v24 = "kernel";
    ipc_log_string(
      v23,
      "ipa_rm %s:%d ignore request to delete dependency by %s\n",
      "ipa_rm_resource_delete_dependency",
      720,
      v24);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v25 = ipa3_get_ipc_logbuf_low();
    if ( (a3 & 1) != 0 )
      v26 = "userspace";
    else
      v26 = "kernel";
    ipc_log_string(
      v25,
      "ipa_rm %s:%d ignore request to delete dependency by %s\n",
      "ipa_rm_resource_delete_dependency",
      720,
      v26);
  }
  v13 = 0;
LABEL_70:
  _ReadStatusReg(SP_EL0);
  return v13;
}
