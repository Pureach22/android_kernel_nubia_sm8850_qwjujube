__int64 __fastcall ipa_rm_resource_add_dependency(__int64 a1, __int64 a2, char a3)
{
  __int64 v6; // x21
  const char *v7; // x0
  __int64 v8; // x21
  const char *v9; // x0
  int v10; // w21
  unsigned int v11; // w20
  __int64 v12; // x0
  __int64 v13; // x0
  int v14; // w1
  int v15; // w8
  int v16; // w8
  unsigned int v17; // w0
  __int64 v18; // x21
  const char *v19; // x0
  __int64 v20; // x21
  const char *v21; // x0
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 ipc_logbuf; // x0
  const char *v28; // x4
  __int64 ipc_logbuf_low; // x0
  const char *v30; // x4
  _BYTE v31[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v32; // [xsp+8h] [xbp-8h]

  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v31[0] = 0;
  if ( a1 && a2 )
  {
    if ( (ipa_rm_peers_list_check_dependency(
            *(_QWORD **)(a1 + 24),
            *(_DWORD *)a1,
            *(_QWORD **)(a2 + 24),
            *(_DWORD *)a2,
            v31)
        & 1) != 0 )
    {
      printk(&unk_3FD357, "ipa_rm_resource_add_dependency");
      if ( ipa3_get_ipc_logbuf() )
      {
        ipc_logbuf = ipa3_get_ipc_logbuf();
        if ( v31[0] )
          v28 = "userspace";
        else
          v28 = "kernel";
        ipc_log_string(
          ipc_logbuf,
          "ipa_rm %s:%d dependency already exists, added by %s\n",
          "ipa_rm_resource_add_dependency",
          628,
          v28);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
        if ( v31[0] )
          v30 = "userspace";
        else
          v30 = "kernel";
        ipc_log_string(
          ipc_logbuf_low,
          "ipa_rm %s:%d dependency already exists, added by %s\n",
          "ipa_rm_resource_add_dependency",
          628,
          v30);
        v11 = -17;
      }
      else
      {
        v11 = -17;
      }
    }
    else
    {
      ipa_rm_peers_list_add_peer(*(_QWORD *)(a1 + 24), (unsigned int *)a2, a3 & 1);
      ipa_rm_peers_list_add_peer(*(_QWORD *)(a2 + 24), (unsigned int *)a1, a3 & 1);
      if ( ipa3_get_ipc_logbuf() )
      {
        v6 = ipa3_get_ipc_logbuf();
        v7 = ipa_rm_resource_str(*(_DWORD *)a1);
        ipc_log_string(
          v6,
          "ipa_rm %s:%d %s state: %d\n",
          "ipa_rm_resource_add_dependency",
          637,
          v7,
          *(_DWORD *)(a1 + 20));
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v8 = ipa3_get_ipc_logbuf_low();
        v9 = ipa_rm_resource_str(*(_DWORD *)a1);
        ipc_log_string(
          v8,
          "ipa_rm %s:%d %s state: %d\n",
          "ipa_rm_resource_add_dependency",
          637,
          v9,
          *(_DWORD *)(a1 + 20));
      }
      v10 = *(_DWORD *)(a1 + 20);
      *(_DWORD *)(a1 + 16) += *(_DWORD *)(a2 + 12);
      if ( (unsigned int)(v10 - 1) < 2 )
      {
        v14 = *(_DWORD *)(a1 + 12);
        v15 = *(_DWORD *)(a1 + 48) + 1;
        *(_DWORD *)(a1 + 20) = 1;
        *(_DWORD *)(a1 + 48) = v15;
        v11 = ipa_rm_resource_consumer_request((unsigned int *)a2, v14, 1, 0);
        if ( v11 != -115 )
        {
          v16 = *(_DWORD *)(a1 + 48);
          v17 = *(_DWORD *)a1;
          *(_DWORD *)(a1 + 20) = v10;
          *(_DWORD *)(a1 + 48) = v16 - 1;
          ipa_rm_perf_profile_change(v17);
        }
      }
      else
      {
        v11 = 0;
        if ( v10 && v10 != 3 )
        {
          printk(&unk_3BFE5A, "ipa_rm_resource_add_dependency");
          if ( ipa3_get_ipc_logbuf() )
          {
            v12 = ipa3_get_ipc_logbuf();
            ipc_log_string(v12, "ipa_rm %s:%d invalid state\n", "ipa_rm_resource_add_dependency", 666);
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v13 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(v13, "ipa_rm %s:%d invalid state\n", "ipa_rm_resource_add_dependency", 666);
          }
          v11 = -1;
        }
      }
      if ( ipa3_get_ipc_logbuf() )
      {
        v18 = ipa3_get_ipc_logbuf();
        v19 = ipa_rm_resource_str(*(_DWORD *)a1);
        ipc_log_string(
          v18,
          "ipa_rm %s:%d %s new state: %d\n",
          "ipa_rm_resource_add_dependency",
          672,
          v19,
          *(_DWORD *)(a1 + 20));
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v20 = ipa3_get_ipc_logbuf_low();
        v21 = ipa_rm_resource_str(*(_DWORD *)a1);
        ipc_log_string(
          v20,
          "ipa_rm %s:%d %s new state: %d\n",
          "ipa_rm_resource_add_dependency",
          672,
          v21,
          *(_DWORD *)(a1 + 20));
      }
      if ( ipa3_get_ipc_logbuf() )
      {
        v22 = ipa3_get_ipc_logbuf();
        ipc_log_string(v22, "ipa_rm %s:%d EXIT with %d\n", "ipa_rm_resource_add_dependency", 673, v11);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v23 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v23, "ipa_rm %s:%d EXIT with %d\n", "ipa_rm_resource_add_dependency", 673, v11);
      }
    }
  }
  else
  {
    printk(&unk_3DA65E, "ipa_rm_resource_add_dependency");
    if ( ipa3_get_ipc_logbuf() )
    {
      v25 = ipa3_get_ipc_logbuf();
      ipc_log_string(v25, "ipa_rm %s:%d invalid params\n", "ipa_rm_resource_add_dependency", 618);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v26 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v26, "ipa_rm %s:%d invalid params\n", "ipa_rm_resource_add_dependency", 618);
    }
    v11 = -22;
  }
  _ReadStatusReg(SP_EL0);
  return v11;
}
