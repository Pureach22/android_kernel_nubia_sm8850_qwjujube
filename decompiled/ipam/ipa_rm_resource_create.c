__int64 __fastcall ipa_rm_resource_create(__int64 a1, __int64 *a2)
{
  int v4; // w8
  __int64 v5; // x0
  __int64 v6; // x21
  unsigned int v7; // w0
  __int64 result; // x0
  __int64 v9; // x0
  __int64 v10; // x8
  __int64 v11; // x9
  unsigned int v12; // w20
  __int64 ipc_logbuf; // x0
  long double v14; // q0
  __int64 ipc_logbuf_low; // x0
  __int64 v16; // x0
  __int64 v17; // x0
  unsigned int v18; // w19
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x0

  if ( !a1 )
    return 4294967274LL;
  v4 = *(_DWORD *)a1 & 1;
  if ( *(_DWORD *)a1 > 0x15u || v4 )
  {
    if ( *(_DWORD *)a1 <= 0x15u && v4 )
    {
      v9 = _kmalloc_cache_noprof(_kmalloc_cache_noprof, 2336, 88);
      if ( v9 )
      {
        v10 = *(_QWORD *)(a1 + 24);
        v11 = *(_QWORD *)(a1 + 32);
        *a2 = v9;
        *(_DWORD *)(v9 + 40) = 0;
        *(_QWORD *)(v9 + 72) = v10;
        *(_QWORD *)(v9 + 80) = v11;
        *(_DWORD *)(v9 + 4) = 1;
        _init_swait_queue_head(v9 + 48, "&x->wait", &init_completion___key_9);
        v6 = *a2;
LABEL_12:
        result = ipa_rm_peers_list_create(22, (__int64 *)(v6 + 24));
        if ( (_DWORD)result )
        {
          v12 = result;
          printk(&unk_3FD327, "ipa_rm_resource_create");
          if ( ipa3_get_ipc_logbuf() )
          {
            ipc_logbuf = ipa3_get_ipc_logbuf();
            ipc_log_string(ipc_logbuf, "ipa_rm %s:%d ipa_rm_peers_list_create failed\n", "ipa_rm_resource_create", 419);
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
            v14 = ipc_log_string(
                    ipc_logbuf_low,
                    "ipa_rm %s:%d ipa_rm_peers_list_create failed\n",
                    "ipa_rm_resource_create",
                    419);
          }
          ipa_rm_resource_delete(*a2, v14);
          return v12;
        }
        else
        {
          *(_DWORD *)*a2 = *(_DWORD *)a1;
          *(_DWORD *)(*a2 + 8) = *(_DWORD *)(a1 + 4);
          *(_DWORD *)(*a2 + 20) = 0;
        }
        return result;
      }
      printk(&unk_3D4BA7, "ipa_rm_resource_create");
      if ( ipa3_get_ipc_logbuf() )
      {
        v23 = ipa3_get_ipc_logbuf();
        ipc_log_string(v23, "ipa_rm %s:%d ipa_rm_resource_producer_create failed\n", "ipa_rm_resource_create", 407);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v24 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v24, "ipa_rm %s:%d ipa_rm_resource_producer_create failed\n", "ipa_rm_resource_create", 407);
      }
      return 4294967284LL;
    }
    else
    {
      printk(&unk_3FA40D, "ipa_rm_resource_create");
      if ( ipa3_get_ipc_logbuf() )
      {
        v16 = ipa3_get_ipc_logbuf();
        ipc_log_string(v16, "ipa_rm %s:%d invalid resource\n", "ipa_rm_resource_create", 411);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v17 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v17, "ipa_rm %s:%d invalid resource\n", "ipa_rm_resource_create", 411);
      }
      return 0xFFFFFFFFLL;
    }
  }
  else
  {
    v5 = _kmalloc_cache_noprof(ipc_log_string, 2336, 56);
    v6 = v5;
    if ( v5 )
    {
      *(_QWORD *)(v5 + 32) = v5 + 32;
      *(_QWORD *)(v5 + 40) = v5 + 32;
      v7 = ipa_rm_resource_producer_register(v5, a1 + 8, 0);
      if ( !v7 )
      {
        *a2 = v6;
        *(_DWORD *)(v6 + 4) = 0;
        goto LABEL_12;
      }
      v18 = v7;
      printk(&unk_3C625E, "ipa_rm_resource_producer_create");
      if ( ipa3_get_ipc_logbuf() )
      {
        v19 = ipa3_get_ipc_logbuf();
        ipc_log_string(
          v19,
          "ipa_rm %s:%d ipa_rm_resource_producer_register() failed\n",
          "ipa_rm_resource_producer_create",
          317);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v20 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          v20,
          "ipa_rm %s:%d ipa_rm_resource_producer_register() failed\n",
          "ipa_rm_resource_producer_create",
          317);
      }
      kfree(v6);
    }
    else
    {
      v18 = -12;
    }
    printk(&unk_3D4BA7, "ipa_rm_resource_create");
    if ( ipa3_get_ipc_logbuf() )
    {
      v21 = ipa3_get_ipc_logbuf();
      ipc_log_string(v21, "ipa_rm %s:%d ipa_rm_resource_producer_create failed\n", "ipa_rm_resource_create", 398);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v22 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v22, "ipa_rm %s:%d ipa_rm_resource_producer_create failed\n", "ipa_rm_resource_create", 398);
    }
    return v18;
  }
}
