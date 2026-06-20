__int64 __fastcall wlfw_ind_register_send_sync_msg(__int64 a1)
{
  __int64 v2; // x2
  __int64 v3; // x20
  unsigned __int16 *v4; // x21
  __int64 v5; // x8
  unsigned int v6; // w22
  int v7; // w8
  unsigned int v8; // w0
  unsigned int v9; // w0
  int v10; // w9
  const char *v11; // x23
  _QWORD v13[10]; // [xsp+0h] [xbp-50h] BYREF

  v13[9] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    v2 = *(_QWORD *)(a1 + 1832);
    memset(v13, 0, 72);
    ipc_log_string(icnss_ipc_log_context, "icnss2_qmi: Sending indication register message, state: 0x%lx\n", v2);
    v3 = _kmalloc_cache_noprof(raw_spin_unlock_irqrestore, 3520, 56);
    if ( v3 )
    {
      v4 = (unsigned __int16 *)_kmalloc_cache_noprof(_init_swait_queue_head, 3520, 16);
      if ( !v4 )
      {
        v6 = -12;
        goto LABEL_31;
      }
      v5 = *(_QWORD *)(a1 + 304);
      *(_BYTE *)(v3 + 10) = 1;
      *(_DWORD *)(v3 + 12) = 1263420748;
      *(_WORD *)v3 = 257;
      *(_WORD *)(v3 + 8) = 257;
      if ( v5 > 30543 )
      {
        if ( v5 != 30544 )
        {
          if ( v5 == 43981 )
          {
            *(_WORD *)(v3 + 6) = 257;
            if ( (*(_QWORD *)(a1 + 328) & 0x40) != 0 )
            {
              *(_BYTE *)(v3 + 22) = 1;
              *(_DWORD *)(v3 + 24) = 1;
            }
          }
LABEL_14:
          v7 = *(_DWORD *)(a1 + 2564) + 1;
          *(_WORD *)(v3 + 50) = 257;
          *(_DWORD *)(a1 + 2564) = v7;
          v8 = qmi_txn_init(a1 + 624, v13, &wlfw_ind_register_resp_msg_v01_ei, v4);
          if ( (v8 & 0x80000000) != 0 )
          {
            v6 = v8;
            v11 = "%sicnss2_qmi: fatal: Fail to init txn for Ind Register resp %d\n";
            printk("%sicnss2_qmi: fatal: Fail to init txn for Ind Register resp %d\n", byte_130B32, v8);
          }
          else
          {
            v6 = qmi_send_request(a1 + 624, 0, v13, 32, 102, &wlfw_ind_register_req_msg_v01_ei, v3);
            if ( (v6 & 0x80000000) != 0 )
            {
              qmi_txn_cancel(v13);
              v11 = "%sicnss2_qmi: fatal: Fail to send Ind Register req %d\n";
              printk("%sicnss2_qmi: fatal: Fail to send Ind Register req %d\n", byte_130B32, v6);
            }
            else
            {
              v9 = qmi_txn_wait(v13, *(unsigned int *)(a1 + 336));
              if ( (v9 & 0x80000000) == 0 )
              {
                if ( !*v4 )
                {
                  v10 = *((unsigned __int8 *)v4 + 4);
                  ++*(_DWORD *)(a1 + 2568);
                  if ( v10 && (v4[4] & 1) != 0 )
                  {
                    ipc_log_string(icnss_ipc_log_context, "icnss2_qmi: WLFW already registered\n");
                    v6 = -114;
                  }
                  else
                  {
                    v6 = 0;
                  }
                  goto LABEL_28;
                }
                printk(
                  "%sicnss2_qmi: fatal: QMI Ind Register request rejected, result:%d error:%d\n",
                  byte_130B32,
                  *v4,
                  v4[1]);
                ipc_log_string(
                  icnss_ipc_log_context,
                  "%sicnss2_qmi: fatal: QMI Ind Register request rejected, result:%d error:%d\n",
                  (const char *)&unk_12DBF3,
                  *v4,
                  v4[1]);
                v6 = -*v4;
LABEL_27:
                ++*(_DWORD *)(a1 + 2572);
LABEL_28:
                kfree(v4);
LABEL_31:
                kfree(v3);
                goto LABEL_32;
              }
              v6 = v9;
              v11 = "%sicnss2_qmi: fatal: Ind Register resp wait failed with ret %d\n";
              printk("%sicnss2_qmi: fatal: Ind Register resp wait failed with ret %d\n", byte_130B32, v9);
            }
          }
          ipc_log_string(icnss_ipc_log_context, v11, &unk_12DBF3, v6);
          goto LABEL_27;
        }
      }
      else if ( v5 != 25680 && v5 != 26448 )
      {
        goto LABEL_14;
      }
      *(_WORD *)(v3 + 20) = 257;
      *(_WORD *)(v3 + 46) = 257;
      *(_QWORD *)(v3 + 30) = 0x101010101010101LL;
      *(_WORD *)(v3 + 38) = 257;
      goto LABEL_14;
    }
    v6 = -12;
  }
  else
  {
    v6 = -19;
  }
LABEL_32:
  _ReadStatusReg(SP_EL0);
  return v6;
}
