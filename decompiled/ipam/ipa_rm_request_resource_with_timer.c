__int64 __fastcall ipa_rm_request_resource_with_timer(unsigned int a1)
{
  __int64 v2; // x19
  int v3; // w0
  __int64 v4; // x0
  __int64 v5; // x20
  int v6; // w8
  unsigned int v7; // w20
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  int v12; // w20
  __int64 v13; // x0
  __int64 v14; // x0
  _QWORD v16[2]; // [xsp+0h] [xbp-10h] BYREF

  v16[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16[0] = 0;
  if ( a1 <= 0x15 && (a1 & 1) != 0 )
  {
    v2 = raw_spin_lock_irqsave(ipa_rm_ctx + 16);
    if ( (unsigned int)ipa_rm_dep_graph_get_resource(*(_QWORD *)ipa_rm_ctx, a1, v16) )
    {
      printk(&unk_3E015F, "ipa_rm_request_resource_with_timer");
      if ( ipa3_get_ipc_logbuf() )
      {
        ipc_logbuf = ipa3_get_ipc_logbuf();
        ipc_log_string(ipc_logbuf, "ipa_rm %s:%d resource does not exists\n", "ipa_rm_request_resource_with_timer", 276);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          ipc_logbuf_low,
          "ipa_rm %s:%d resource does not exists\n",
          "ipa_rm_request_resource_with_timer",
          276);
        v7 = -1;
LABEL_24:
        raw_spin_unlock_irqrestore(ipa_rm_ctx + 16, v2);
        goto LABEL_25;
      }
    }
    else
    {
      v3 = ipa_rm_resource_consumer_request(v16[0], 0, 0, 1);
      if ( v3 == -115 || !v3 )
      {
        v4 = _kmalloc_cache_noprof(of_find_property, 2336, 120);
        if ( v4 )
        {
          v5 = v4;
          v6 = *(_DWORD *)v16[0];
          *(_BYTE *)(v4 + 112) = 0;
          *(_QWORD *)v4 = 0xFFFFFFFE00000LL;
          *(_DWORD *)(v4 + 104) = v6;
          *(_DWORD *)(v4 + 108) = 0;
          *(_QWORD *)(v4 + 8) = v4 + 8;
          *(_QWORD *)(v4 + 16) = v4 + 8;
          *(_QWORD *)(v4 + 24) = delayed_release_work_func;
          init_timer_key(v4 + 32, &delayed_work_timer_fn, 0x200000, 0, 0);
          queue_delayed_work_on(32, system_wq, v5, 250);
          v7 = 0;
        }
        else
        {
          v7 = -12;
        }
        goto LABEL_24;
      }
      v12 = v3;
      printk(&unk_3D1ACB, "ipa_rm_request_resource_with_timer");
      if ( ipa3_get_ipc_logbuf() )
      {
        v13 = ipa3_get_ipc_logbuf();
        ipc_log_string(
          v13,
          "ipa_rm %s:%d consumer request returned error %d\n",
          "ipa_rm_request_resource_with_timer",
          283,
          v12);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v14 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          v14,
          "ipa_rm %s:%d consumer request returned error %d\n",
          "ipa_rm_request_resource_with_timer",
          283,
          v12);
        v7 = -1;
        goto LABEL_24;
      }
    }
    v7 = -1;
    goto LABEL_24;
  }
  printk(&unk_3DD74A, "ipa_rm_request_resource_with_timer");
  if ( ipa3_get_ipc_logbuf() )
  {
    v8 = ipa3_get_ipc_logbuf();
    ipc_log_string(v8, "ipa_rm %s:%d can be called on CONS only\n", "ipa_rm_request_resource_with_timer", 268);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v9 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v9, "ipa_rm %s:%d can be called on CONS only\n", "ipa_rm_request_resource_with_timer", 268);
  }
  v7 = -22;
LABEL_25:
  _ReadStatusReg(SP_EL0);
  return v7;
}
