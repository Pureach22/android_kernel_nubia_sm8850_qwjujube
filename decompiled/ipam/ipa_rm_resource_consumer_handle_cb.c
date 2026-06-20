long double __fastcall ipa_rm_resource_consumer_handle_cb(__int64 a1, int a2)
{
  __int64 v4; // x21
  const char *v5; // x0
  int v6; // w8
  unsigned int v7; // w0
  long double result; // q0
  signed int i; // w21
  __int64 v10; // x20
  const char *v11; // x0
  unsigned int v12; // w0
  unsigned int *v13; // x0
  __int64 v14; // x1
  __int64 resource; // x0
  unsigned int *v16; // x25
  __int64 v17; // x26
  const char *v18; // x0
  unsigned int v19; // w8
  unsigned int v20; // w8
  bool v21; // vf
  int v22; // w8
  unsigned int v23; // w0
  unsigned int v24; // w8
  int v25; // w8
  __int64 v26; // x26
  const char *v27; // x0
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0

  if ( !a1 )
  {
    printk(&unk_3DA65E, "ipa_rm_resource_consumer_handle_cb");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(ipc_logbuf, "ipa_rm %s:%d invalid params\n", "ipa_rm_resource_consumer_handle_cb", 1004);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      return ipc_log_string(ipc_logbuf_low, "ipa_rm %s:%d invalid params\n", "ipa_rm_resource_consumer_handle_cb", 1004);
    }
    return result;
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v4 = ipa3_get_ipc_logbuf_low();
    v5 = ipa_rm_resource_str(*(_DWORD *)a1);
    ipc_log_string(
      v4,
      "ipa_rm %s:%d %s state: %d event: %d\n",
      "ipa_rm_resource_consumer_handle_cb",
      1010,
      v5,
      *(_DWORD *)(a1 + 20),
      a2);
  }
  v6 = *(_DWORD *)(a1 + 20);
  if ( v6 != 3 )
  {
    if ( v6 == 1 && a2 != 1 )
    {
      v7 = *(_DWORD *)a1;
      *(_DWORD *)(a1 + 20) = 2;
      ipa_rm_perf_profile_change(v7);
      ipa3_resume_resource(*(_DWORD *)a1);
      complete_all(a1 + 40);
      goto LABEL_10;
    }
LABEL_12:
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v10 = ipa3_get_ipc_logbuf_low();
      v11 = ipa_rm_resource_str(*(_DWORD *)a1);
      return ipc_log_string(
               v10,
               "ipa_rm %s:%d %s new state: %d\n",
               "ipa_rm_resource_consumer_handle_cb",
               1049,
               v11,
               *(_DWORD *)(a1 + 20));
    }
    return result;
  }
  if ( !a2 )
    goto LABEL_12;
  *(_DWORD *)(a1 + 20) = 0;
LABEL_10:
  if ( (int)ipa_rm_peers_list_get_size(*(_QWORD *)(a1 + 24)) >= 1 )
  {
    for ( i = 0; i < (int)ipa_rm_peers_list_get_size(*(_QWORD *)(a1 + 24)); ++i )
    {
      resource = ipa_rm_peers_list_get_resource(i, *(_QWORD *)(a1 + 24));
      if ( resource )
      {
        v16 = (unsigned int *)resource;
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v17 = ipa3_get_ipc_logbuf_low();
          v18 = ipa_rm_resource_str(*v16);
          ipc_log_string(
            v17,
            "ipa_rm %s:%d %s state: %d event: %d pending_request: %d\n",
            "ipa_rm_resource_producer_handle_cb",
            939,
            v18,
            v16[5],
            a2,
            v16[12]);
        }
        v19 = v16[5];
        if ( v19 == 3 )
        {
          if ( a2 != 1
            || (v24 = v16[13], v21 = __OFSUB__(v24, 1), v25 = v24 - 1, (v25 < 0) ^ v21)
            || (v16[13] = v25) != 0 )
          {
LABEL_30:
            if ( ipa3_get_ipc_logbuf_low() )
            {
              v26 = ipa3_get_ipc_logbuf_low();
              v27 = ipa_rm_resource_str(*v16);
              ipc_log_string(
                v26,
                "ipa_rm %s:%d %s new state: %d\n",
                "ipa_rm_resource_producer_handle_cb",
                986,
                v27,
                v16[5]);
            }
            continue;
          }
          v12 = *v16;
          v16[5] = 0;
          ipa_rm_perf_profile_change(v12);
          v13 = v16;
          v14 = 1;
        }
        else
        {
          if ( v19 != 1 )
            goto LABEL_30;
          if ( a2 )
            goto LABEL_30;
          v20 = v16[12];
          v21 = __OFSUB__(v20, 1);
          v22 = v20 - 1;
          if ( v22 < 0 != v21 )
            goto LABEL_30;
          v16[12] = v22;
          if ( v22 )
            goto LABEL_30;
          v23 = *v16;
          v16[5] = 2;
          ipa_rm_perf_profile_change(v23);
          v13 = v16;
          v14 = 0;
        }
        ipa_rm_resource_producer_notify_clients(v13, v14, 0);
      }
    }
  }
  return result;
}
