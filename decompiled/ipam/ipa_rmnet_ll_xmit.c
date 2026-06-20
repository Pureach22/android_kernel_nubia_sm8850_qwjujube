__int64 __fastcall ipa_rmnet_ll_xmit(__int64 a1)
{
  __int64 v2; // x0
  _DWORD *v3; // x8
  __int64 v4; // x20
  int v5; // w5
  __int64 v6; // x9
  __int64 v7; // x0
  __int64 v8; // x0
  int v10; // w0
  __int64 v11; // x8
  int v12; // w19
  __int64 v13; // x21
  int v14; // w0
  int v15; // w9
  __int64 v16; // x0
  __int64 v18; // x11
  __int64 v19; // x8
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x8
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x8
  __int64 v26; // x10
  __int64 v27; // x0
  unsigned __int64 StatusReg; // x21
  __int64 v29; // x8
  __int64 v30; // x0
  __int64 v31; // x0
  int v32; // w21
  __int64 v33; // x8
  __int64 v34; // x0
  __int64 v35; // x0
  __int64 v36; // x8
  __int64 v37; // x10
  __int64 v38; // x0
  __int64 v39; // x8
  __int64 v40; // x0
  __int64 v41; // x0
  __int64 v42; // x0
  __int64 v43; // x8
  __int64 v44; // x1
  __int64 v45; // x10
  __int64 v46; // x0
  unsigned int v52; // w9

  if ( (*(_BYTE *)(ipa3_ctx + 48859) & 1) != 0 )
  {
    v2 = raw_spin_lock_irqsave(rmnet_ll_ipa3_ctx + 584);
    v3 = (_DWORD *)rmnet_ll_ipa3_ctx;
    v4 = v2;
    if ( *(_DWORD *)(rmnet_ll_ipa3_ctx + 56) == 3 )
    {
      if ( !*(_DWORD *)(rmnet_ll_ipa3_ctx + 640) && (*(_DWORD *)rmnet_ll_ipa3_ctx & 0x80000000) == 0 )
      {
        v5 = *(_DWORD *)(rmnet_ll_ipa3_ctx + 664);
        if ( (unsigned int)(v5 + *(_DWORD *)rmnet_ll_ipa3_ctx) >= 0x1FE )
        {
          v6 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v7 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v7 )
            {
              ipc_log_string(
                v7,
                "ipa %s:%d IPA LL TX queue full, %d + %d\n",
                "ipa_rmnet_ll_xmit",
                672,
                *(_DWORD *)rmnet_ll_ipa3_ctx,
                v5);
              v6 = ipa3_ctx;
              v3 = (_DWORD *)rmnet_ll_ipa3_ctx;
            }
            v8 = *(_QWORD *)(v6 + 34160);
            if ( v8 )
            {
              ipc_log_string(v8, "ipa %s:%d IPA LL TX queue full, %d + %d\n", "ipa_rmnet_ll_xmit", 672, *v3, v3[166]);
              v3 = (_DWORD *)rmnet_ll_ipa3_ctx;
            }
          }
          v3[160] = 1;
          raw_spin_unlock_irqrestore(v3 + 146, v4);
          return 4294967285LL;
        }
      }
      if ( *(_DWORD *)(rmnet_ll_ipa3_ctx + 664) )
      {
        skb_queue_tail(rmnet_ll_ipa3_ctx + 648, a1);
LABEL_18:
        v11 = rmnet_ll_ipa3_ctx;
        v12 = 510 - (*(_DWORD *)v11 + *(_DWORD *)(v11 + 664));
LABEL_19:
        raw_spin_unlock_irqrestore(v11 + 584, v4);
        return v12 & (unsigned int)~(v12 >> 31);
      }
      if ( *(_DWORD *)(ipa3_ctx + 52488) )
      {
        StatusReg = _ReadStatusReg(SP_EL0);
        printk(&unk_3F9131, "ipa_rmnet_ll_xmit");
        v29 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v30 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v30 )
          {
            ipc_log_string(
              v30,
              "ipa %s:%d User %s sent data in suspend mode.\n",
              "ipa_rmnet_ll_xmit",
              691,
              (const char *)(StatusReg + 2320));
            v29 = ipa3_ctx;
          }
          v31 = *(_QWORD *)(v29 + 34160);
          if ( v31 )
            ipc_log_string(
              v31,
              "ipa %s:%d User %s sent data in suspend mode.\n",
              "ipa_rmnet_ll_xmit",
              691,
              (const char *)(StatusReg + 2320));
        }
      }
      v10 = ipa_pm_activate(*(_DWORD *)(rmnet_ll_ipa3_ctx + 672));
      if ( !v10 )
      {
        raw_spin_unlock_irqrestore(rmnet_ll_ipa3_ctx + 584, v4);
        v13 = *(int *)(a1 + 112);
        v14 = ipa_tx_dp(0x78u, a1, nullptr);
        if ( v14 )
        {
          if ( v14 == -32 )
          {
            printk(&unk_3B0D33, "ipa_rmnet_ll_xmit");
            v39 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v40 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v40 )
              {
                ipc_log_string(v40, "ipa %s:%d Low lat data fatal: pipe is not valid\n", "ipa_rmnet_ll_xmit", 730);
                v39 = ipa3_ctx;
              }
              v41 = *(_QWORD *)(v39 + 34160);
              if ( v41 )
                ipc_log_string(v41, "ipa %s:%d Low lat data fatal: pipe is not valid\n", "ipa_rmnet_ll_xmit", 730);
            }
            v42 = raw_spin_lock_irqsave(rmnet_ll_ipa3_ctx + 584);
            v43 = rmnet_ll_ipa3_ctx;
            v44 = v42;
            v45 = *(_QWORD *)(rmnet_ll_ipa3_ctx + 40);
            v46 = rmnet_ll_ipa3_ctx + 584;
            ++*(_DWORD *)(rmnet_ll_ipa3_ctx + 32);
            *(_QWORD *)(v43 + 40) = v45 + *(unsigned int *)(a1 + 112);
            raw_spin_unlock_irqrestore(v46, v44);
            sk_skb_reason_drop(0, a1, 2);
            return 4294967264LL;
          }
          v4 = raw_spin_lock_irqsave(rmnet_ll_ipa3_ctx + 584);
          skb_queue_head(rmnet_ll_ipa3_ctx + 648, a1);
          queue_delayed_work_on(32, *(_QWORD *)(rmnet_ll_ipa3_ctx + 736), &rmnet_ll_wakeup_work, 0);
          v11 = rmnet_ll_ipa3_ctx;
          v15 = *(_DWORD *)(rmnet_ll_ipa3_ctx + 664) + *(_DWORD *)rmnet_ll_ipa3_ctx;
        }
        else
        {
          v16 = raw_spin_lock_irqsave(rmnet_ll_ipa3_ctx + 584);
          _X8 = (unsigned int *)rmnet_ll_ipa3_ctx;
          v4 = v16;
          __asm { PRFM            #0x11, [X8] }
          do
            v52 = __ldxr(_X8);
          while ( __stxr(v52 + 1, _X8) );
          v11 = rmnet_ll_ipa3_ctx;
          v18 = *(_QWORD *)(rmnet_ll_ipa3_ctx + 16) + v13;
          v15 = *(_DWORD *)(rmnet_ll_ipa3_ctx + 664) + *(_DWORD *)rmnet_ll_ipa3_ctx;
          ++*(_DWORD *)(rmnet_ll_ipa3_ctx + 4);
          *(_QWORD *)(v11 + 16) = v18;
        }
        v12 = 510 - v15;
        if ( !*(_DWORD *)v11 )
        {
          ((void (__fastcall *)(_QWORD))ipa_pm_deferred_deactivate)(*(unsigned int *)(v11 + 672));
          v11 = rmnet_ll_ipa3_ctx;
        }
        goto LABEL_19;
      }
      if ( v10 == -115 )
      {
        skb_queue_tail(rmnet_ll_ipa3_ctx + 648, a1);
        queue_delayed_work_on(32, *(_QWORD *)(rmnet_ll_ipa3_ctx + 736), &rmnet_ll_wakeup_work, 0);
        goto LABEL_18;
      }
      v32 = v10;
      printk(&unk_3E1D87, "ipa_rmnet_ll_xmit");
      v33 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v34 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v34 )
        {
          ipc_log_string(
            v34,
            "ipa %s:%d [%s] fatal: ipa pm activate failed %d\n",
            "ipa_rmnet_ll_xmit",
            711,
            "ipa_rmnet_ll_xmit",
            v32);
          v33 = ipa3_ctx;
        }
        v35 = *(_QWORD *)(v33 + 34160);
        if ( v35 )
          ipc_log_string(
            v35,
            "ipa %s:%d [%s] fatal: ipa pm activate failed %d\n",
            "ipa_rmnet_ll_xmit",
            711,
            "ipa_rmnet_ll_xmit",
            v32);
      }
      v36 = rmnet_ll_ipa3_ctx;
      v37 = *(_QWORD *)(rmnet_ll_ipa3_ctx + 40);
      v38 = rmnet_ll_ipa3_ctx + 584;
      ++*(_DWORD *)(rmnet_ll_ipa3_ctx + 32);
      *(_QWORD *)(v36 + 40) = v37 + *(unsigned int *)(a1 + 112);
      raw_spin_unlock_irqrestore(v38, v4);
      sk_skb_reason_drop(0, a1, 2);
      return 0xFFFFFFFFLL;
    }
    else
    {
      printk(&unk_3B353F, "ipa_rmnet_ll_xmit");
      v22 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v23 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v23 )
        {
          ipc_log_string(
            v23,
            "ipa %s:%d bad rmnet_ll state %d\n",
            "ipa_rmnet_ll_xmit",
            650,
            *(_DWORD *)(rmnet_ll_ipa3_ctx + 56));
          v22 = ipa3_ctx;
        }
        v24 = *(_QWORD *)(v22 + 34160);
        if ( v24 )
          ipc_log_string(
            v24,
            "ipa %s:%d bad rmnet_ll state %d\n",
            "ipa_rmnet_ll_xmit",
            650,
            *(_DWORD *)(rmnet_ll_ipa3_ctx + 56));
      }
      v25 = rmnet_ll_ipa3_ctx;
      v26 = *(_QWORD *)(rmnet_ll_ipa3_ctx + 40);
      v27 = rmnet_ll_ipa3_ctx + 584;
      ++*(_DWORD *)(rmnet_ll_ipa3_ctx + 32);
      *(_QWORD *)(v25 + 40) = v26 + *(unsigned int *)(a1 + 112);
      raw_spin_unlock_irqrestore(v27, v4);
      sk_skb_reason_drop(0, a1, 2);
      return 4294967274LL;
    }
  }
  else
  {
    printk(&unk_3F9685, "ipa_rmnet_ll_xmit");
    v19 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v20 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v20 )
      {
        ipc_log_string(v20, "ipa %s:%d low lat data pipe not supported\n", "ipa_rmnet_ll_xmit", 641);
        v19 = ipa3_ctx;
      }
      v21 = *(_QWORD *)(v19 + 34160);
      if ( v21 )
        ipc_log_string(v21, "ipa %s:%d low lat data pipe not supported\n", "ipa_rmnet_ll_xmit", 641);
    }
    sk_skb_reason_drop(0, a1, 2);
    return 4294967277LL;
  }
}
