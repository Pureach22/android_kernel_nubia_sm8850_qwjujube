__int64 __fastcall wlfw_wlan_mode_send_sync_msg(__int64 a1, int a2)
{
  __int64 v2; // x2
  unsigned int v3; // w21
  __int64 v7; // x23
  int v8; // w22
  __int64 v9; // x19
  unsigned __int16 *v10; // x20
  __int64 v11; // x8
  unsigned int v12; // w2
  int v13; // w9
  unsigned int v14; // w0
  __int64 v15; // x21
  __int64 v16; // x0
  unsigned int v17; // w0
  __int64 v18; // x0
  __int64 v19; // x2
  const char *v20; // x22
  unsigned __int64 v27; // x10
  unsigned __int64 v30; // x9
  _QWORD v31[10]; // [xsp+0h] [xbp-50h] BYREF

  v31[9] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    v3 = -19;
    goto LABEL_8;
  }
  if ( a2 != 4 || (*(_QWORD *)(a1 + 1832) & 0x200) == 0 )
  {
    v2 = *(_QWORD *)(a1 + 1832);
    if ( a2 != 4 || (v2 & 0x10000) != 0 )
    {
      memset(v31, 0, 72);
      printk("%sicnss2_qmi: Sending Mode request, state: 0x%lx, mode: %d\n", byte_13289B, v2, a2);
      v7 = a1;
      v8 = a2;
      ipc_log_string(
        icnss_ipc_log_context,
        "%sicnss2_qmi: Sending Mode request, state: 0x%lx, mode: %d\n",
        (const char *)&unk_12DBF3,
        *(_QWORD *)(a1 + 1832),
        a2);
      v9 = _kmalloc_cache_noprof(raw_spin_lock_irqsave, 3520, 20);
      if ( !v9 )
      {
        v3 = -12;
        goto LABEL_8;
      }
      v10 = (unsigned __int16 *)_kmalloc_cache_noprof(pm_stay_awake, 3520, 4);
      if ( !v10 )
      {
        kfree(v9);
        v3 = -12;
        goto LABEL_8;
      }
      *(_DWORD *)v9 = v8;
      v11 = a1;
      *(_BYTE *)(v9 + 4) = 1;
      v12 = *(_DWORD *)(a1 + 5780);
      *(_BYTE *)(v9 + 5) = (*(_QWORD *)(a1 + 328) & 2) != 0;
      if ( v12 >= 0x64 )
      {
        ipc_log_string(icnss_ipc_log_context, "icnss2_qmi: Setting WLAN_EN delay: %d ms\n", v12);
        v13 = *(_DWORD *)(a1 + 5780);
        v11 = a1;
        *(_BYTE *)(v9 + 8) = 1;
        *(_DWORD *)(v9 + 12) = v13;
      }
      ++*(_DWORD *)(v11 + 2632);
      v14 = qmi_txn_init(v11 + 624, v31, &wlfw_wlan_mode_resp_msg_v01_ei, v10);
      if ( (v14 & 0x80000000) != 0 )
      {
        v3 = v14;
        v20 = "%sicnss2_qmi: fatal: Fail to init txn for Mode resp %d\n";
        printk("%sicnss2_qmi: fatal: Fail to init txn for Mode resp %d\n", byte_130B32, v14);
      }
      else
      {
        v3 = qmi_send_request(a1 + 624, 0, v31, 34, 26, &wlfw_wlan_mode_req_msg_v01_ei, v9);
        if ( (v3 & 0x80000000) != 0 )
        {
          qmi_txn_cancel(v31);
          v20 = "%sicnss2_qmi: fatal: Fail to send Mode req %d\n";
          printk("%sicnss2_qmi: fatal: Fail to send Mode req %d\n", byte_130B32, v3);
        }
        else
        {
          v15 = *(unsigned int *)(v7 + 336);
          v16 = _msecs_to_jiffies(*(unsigned int *)(v7 + 5780));
          v17 = qmi_txn_wait(v31, v16 + v15);
          if ( (v17 & 0x80000000) == 0 )
          {
            if ( !*v10 )
            {
              v18 = icnss_ipc_log_context;
              v19 = *(_QWORD *)(v7 + 1832);
              ++*(_DWORD *)(v7 + 2636);
              if ( v8 == 4 )
              {
                ipc_log_string(v18, "icnss2_qmi: Clear mode on 0x%lx, mode: %d\n", v19, 4);
                _X8 = (unsigned __int64 *)(v7 + 1832);
                __asm { PRFM            #0x11, [X8] }
                do
                  v27 = __ldxr(_X8);
                while ( __stxr(v27 & 0xFFFFFFFFFFFEFFFFLL, _X8) );
              }
              else
              {
                ipc_log_string(v18, "icnss2_qmi: Set mode on 0x%lx, mode: %d\n", v19, v8);
                _X8 = (unsigned __int64 *)(v7 + 1832);
                __asm { PRFM            #0x11, [X8] }
                do
                  v30 = __ldxr(_X8);
                while ( __stxr(v30 | 0x10000, _X8) );
              }
              kfree(v10);
              kfree(v9);
              goto LABEL_6;
            }
            printk("%sicnss2_qmi: fatal: QMI Mode request rejected, result:%d error:%d\n", byte_130B32, *v10, v10[1]);
            ipc_log_string(
              icnss_ipc_log_context,
              "%sicnss2_qmi: fatal: QMI Mode request rejected, result:%d error:%d\n",
              (const char *)&unk_12DBF3,
              *v10,
              v10[1]);
            v3 = -*v10;
LABEL_26:
            kfree(v10);
            kfree(v9);
            ++*(_DWORD *)(v7 + 2640);
            goto LABEL_8;
          }
          v3 = v17;
          v20 = "%sicnss2_qmi: fatal: Mode resp wait failed with ret %d\n";
          printk("%sicnss2_qmi: fatal: Mode resp wait failed with ret %d\n", byte_130B32, v17);
        }
      }
      ipc_log_string(icnss_ipc_log_context, v20, &unk_12DBF3, v3);
      goto LABEL_26;
    }
  }
LABEL_6:
  v3 = 0;
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return v3;
}
