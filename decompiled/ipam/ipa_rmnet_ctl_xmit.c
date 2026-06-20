__int64 __fastcall ipa_rmnet_ctl_xmit(__int64 a1)
{
  __int64 v2; // x20
  unsigned int v3; // w9
  int v4; // w0
  __int64 v5; // x21
  int v6; // w0
  __int64 v7; // x8
  __int64 v8; // x0
  __int64 v10; // x10
  __int64 v12; // x8
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x8
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x8
  __int64 v19; // x10
  __int64 v20; // x0
  __int64 v21; // x8
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x8
  __int64 v25; // x1
  __int64 v26; // x10
  unsigned __int64 StatusReg; // x21
  __int64 v28; // x8
  __int64 v29; // x0
  __int64 v30; // x0
  int v31; // w21
  __int64 v32; // x8
  __int64 v33; // x0
  __int64 v34; // x0
  __int64 v35; // x8
  __int64 v36; // x0
  __int64 v37; // x0
  __int64 v38; // x0
  unsigned int v44; // w9

  if ( (*(_BYTE *)(ipa3_ctx + 48858) & 1) == 0 )
  {
    printk(&unk_3B604E, "ipa_rmnet_ctl_xmit");
    v12 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v13 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v13 )
      {
        ipc_log_string(v13, "ipa %s:%d low lat pipe not supported\n", "ipa_rmnet_ctl_xmit", 469);
        v12 = ipa3_ctx;
      }
      v14 = *(_QWORD *)(v12 + 34160);
      if ( v14 )
        ipc_log_string(v14, "ipa %s:%d low lat pipe not supported\n", "ipa_rmnet_ctl_xmit", 469);
    }
    goto LABEL_39;
  }
  v2 = raw_spin_lock_irqsave(rmnet_ctl_ipa3_ctx + 584);
  v3 = *(_DWORD *)(rmnet_ctl_ipa3_ctx + 656);
  if ( v3 < 0x200 )
  {
    if ( *(_DWORD *)(rmnet_ctl_ipa3_ctx + 56) == 3 )
    {
      if ( v3 )
      {
        skb_queue_tail(rmnet_ctl_ipa3_ctx + 640, a1);
LABEL_17:
        v7 = rmnet_ctl_ipa3_ctx;
        goto LABEL_18;
      }
      if ( *(_DWORD *)(ipa3_ctx + 52488) )
      {
        StatusReg = _ReadStatusReg(SP_EL0);
        printk(&unk_3F9131, "ipa_rmnet_ctl_xmit");
        v28 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v29 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v29 )
          {
            ipc_log_string(
              v29,
              "ipa %s:%d User %s sent data in suspend mode.\n",
              "ipa_rmnet_ctl_xmit",
              509,
              (const char *)(StatusReg + 2320));
            v28 = ipa3_ctx;
          }
          v30 = *(_QWORD *)(v28 + 34160);
          if ( v30 )
            ipc_log_string(
              v30,
              "ipa %s:%d User %s sent data in suspend mode.\n",
              "ipa_rmnet_ctl_xmit",
              509,
              (const char *)(StatusReg + 2320));
        }
      }
      v4 = ipa_pm_activate(*(_DWORD *)(rmnet_ctl_ipa3_ctx + 664));
      if ( !v4 )
      {
        raw_spin_unlock_irqrestore(rmnet_ctl_ipa3_ctx + 584, v2);
        v5 = *(int *)(a1 + 112);
        v6 = ipa_tx_dp(0x68u, a1, nullptr);
        if ( v6 )
        {
          if ( v6 == -32 )
          {
            printk(&unk_3ADC82, "ipa_rmnet_ctl_xmit");
            v35 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v36 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v36 )
              {
                ipc_log_string(v36, "ipa %s:%d Low lat fatal: pipe is not valid\n", "ipa_rmnet_ctl_xmit", 545);
                v35 = ipa3_ctx;
              }
              v37 = *(_QWORD *)(v35 + 34160);
              if ( v37 )
                ipc_log_string(v37, "ipa %s:%d Low lat fatal: pipe is not valid\n", "ipa_rmnet_ctl_xmit", 545);
            }
            v38 = raw_spin_lock_irqsave(rmnet_ctl_ipa3_ctx + 584);
            v24 = rmnet_ctl_ipa3_ctx;
            v25 = v38;
            goto LABEL_38;
          }
          v2 = raw_spin_lock_irqsave(rmnet_ctl_ipa3_ctx + 584);
          skb_queue_head(rmnet_ctl_ipa3_ctx + 640, a1);
          v7 = rmnet_ctl_ipa3_ctx;
          if ( *(_DWORD *)rmnet_ctl_ipa3_ctx )
          {
LABEL_18:
            raw_spin_unlock_irqrestore(v7 + 584, v2);
            return 0;
          }
        }
        else
        {
          v8 = raw_spin_lock_irqsave(rmnet_ctl_ipa3_ctx + 584);
          _X8 = (unsigned int *)rmnet_ctl_ipa3_ctx;
          v2 = v8;
          __asm { PRFM            #0x11, [X8] }
          do
            v44 = __ldxr(_X8);
          while ( __stxr(v44 + 1, _X8) );
          v7 = rmnet_ctl_ipa3_ctx;
          v10 = *(_QWORD *)(rmnet_ctl_ipa3_ctx + 16) + v5;
          ++*(_DWORD *)(rmnet_ctl_ipa3_ctx + 4);
          *(_QWORD *)(v7 + 16) = v10;
          if ( *(_DWORD *)v7 )
            goto LABEL_18;
        }
        ((void (__fastcall *)(_QWORD))ipa_pm_deferred_deactivate)(*(unsigned int *)(v7 + 664));
        goto LABEL_17;
      }
      if ( v4 == -115 )
      {
        skb_queue_tail(rmnet_ctl_ipa3_ctx + 640, a1);
        queue_delayed_work_on(32, *(_QWORD *)(rmnet_ctl_ipa3_ctx + 720), &rmnet_ctl_wakeup_work, 0);
        goto LABEL_17;
      }
      v31 = v4;
      printk(&unk_3E1D87, "ipa_rmnet_ctl_xmit");
      v32 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v33 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v33 )
        {
          ipc_log_string(
            v33,
            "ipa %s:%d [%s] fatal: ipa pm activate failed %d\n",
            "ipa_rmnet_ctl_xmit",
            526,
            "ipa_rmnet_ctl_xmit",
            v31);
          v32 = ipa3_ctx;
        }
        v34 = *(_QWORD *)(v32 + 34160);
        if ( v34 )
          ipc_log_string(
            v34,
            "ipa %s:%d [%s] fatal: ipa pm activate failed %d\n",
            "ipa_rmnet_ctl_xmit",
            526,
            "ipa_rmnet_ctl_xmit",
            v31);
      }
    }
    else
    {
      printk(&unk_3A4A13, "ipa_rmnet_ctl_xmit");
      v21 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v22 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v22 )
        {
          ipc_log_string(
            v22,
            "ipa %s:%d bad rmnet_ctl state %d\n",
            "ipa_rmnet_ctl_xmit",
            490,
            *(_DWORD *)(rmnet_ctl_ipa3_ctx + 56));
          v21 = ipa3_ctx;
        }
        v23 = *(_QWORD *)(v21 + 34160);
        if ( v23 )
          ipc_log_string(
            v23,
            "ipa %s:%d bad rmnet_ctl state %d\n",
            "ipa_rmnet_ctl_xmit",
            490,
            *(_DWORD *)(rmnet_ctl_ipa3_ctx + 56));
      }
    }
    v24 = rmnet_ctl_ipa3_ctx;
    v25 = v2;
LABEL_38:
    v26 = *(_QWORD *)(v24 + 40);
    ++*(_DWORD *)(v24 + 32);
    *(_QWORD *)(v24 + 40) = v26 + *(unsigned int *)(a1 + 112);
    raw_spin_unlock_irqrestore(v24 + 584, v25);
LABEL_39:
    sk_skb_reason_drop(0, a1, 2);
    return 0;
  }
  printk(&unk_3F360B, "ipa_rmnet_ctl_xmit");
  v15 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v16 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v16 )
    {
      ipc_log_string(v16, "ipa %s:%d rmnet_ctl tx queue full\n", "ipa_rmnet_ctl_xmit", 478);
      v15 = ipa3_ctx;
    }
    v17 = *(_QWORD *)(v15 + 34160);
    if ( v17 )
      ipc_log_string(v17, "ipa %s:%d rmnet_ctl tx queue full\n", "ipa_rmnet_ctl_xmit", 478);
  }
  v18 = rmnet_ctl_ipa3_ctx;
  v19 = *(_QWORD *)(rmnet_ctl_ipa3_ctx + 40);
  v20 = rmnet_ctl_ipa3_ctx + 584;
  ++*(_DWORD *)(rmnet_ctl_ipa3_ctx + 32);
  *(_QWORD *)(v18 + 40) = v19 + *(unsigned int *)(a1 + 112);
  raw_spin_unlock_irqrestore(v20, v2);
  sk_skb_reason_drop(0, a1, 2);
  return 4294967285LL;
}
