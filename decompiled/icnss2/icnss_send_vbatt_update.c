__int64 __fastcall icnss_send_vbatt_update(__int64 a1, __int64 a2)
{
  __int64 v2; // x2
  _QWORD *v5; // x19
  unsigned __int16 *v6; // x20
  unsigned int v7; // w0
  unsigned int v8; // w22
  unsigned int v9; // w0
  const char *v10; // x21
  _QWORD v12[10]; // [xsp+0h] [xbp-50h] BYREF

  v12[9] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    v2 = *(_QWORD *)(a1 + 1832);
    if ( (v2 & 0x2000) != 0 )
    {
      v8 = -22;
    }
    else
    {
      memset(v12, 0, 72);
      ipc_log_string(icnss_ipc_log_context, "icnss2_qmi: Sending Vbatt message, state: 0x%lx\n", v2);
      v5 = (_QWORD *)_kmalloc_cache_noprof(pm_stay_awake, 3520, 8);
      if ( v5 )
      {
        v6 = (unsigned __int16 *)_kmalloc_cache_noprof(pm_stay_awake, 3520, 4);
        if ( !v6 )
        {
          v8 = -12;
          goto LABEL_20;
        }
        *v5 = a2;
        v7 = qmi_txn_init(a1 + 624, v12, &wlfw_vbatt_resp_msg_v01_ei, v6);
        if ( (v7 & 0x80000000) != 0 )
        {
          v8 = v7;
          v10 = "%sicnss2_qmi: Fail to init txn for Vbatt message resp %d\n";
          printk("%sicnss2_qmi: Fail to init txn for Vbatt message resp %d\n", byte_130B32, v7);
        }
        else
        {
          v8 = qmi_send_request(a1 + 624, 0, v12, 50, 11, &wlfw_vbatt_req_msg_v01_ei, v5);
          if ( (v8 & 0x80000000) != 0 )
          {
            qmi_txn_cancel(v12);
            v10 = "%sicnss2_qmi: Fail to send Vbatt message req %d\n";
            printk("%sicnss2_qmi: Fail to send Vbatt message req %d\n", byte_130B32, v8);
          }
          else
          {
            v9 = qmi_txn_wait(v12, *(unsigned int *)(a1 + 336));
            if ( (v9 & 0x80000000) == 0 )
            {
              if ( *v6 )
              {
                printk(
                  "%sicnss2_qmi: QMI Vbatt message request rejected, result:%d error:%d\n",
                  byte_130B32,
                  *v6,
                  v6[1]);
                ipc_log_string(
                  icnss_ipc_log_context,
                  "%sicnss2_qmi: QMI Vbatt message request rejected, result:%d error:%d\n",
                  (const char *)&unk_12DBF3,
                  *v6,
                  v6[1]);
                v8 = -*v6;
              }
              else
              {
                v8 = 0;
              }
              goto LABEL_10;
            }
            v8 = v9;
            v10 = "%sicnss2_qmi: VBATT message resp wait failed with ret %d\n";
            printk("%sicnss2_qmi: VBATT message resp wait failed with ret %d\n", byte_130B32, v9);
          }
        }
        ipc_log_string(icnss_ipc_log_context, v10, &unk_12DBF3, v8);
LABEL_10:
        kfree(v6);
LABEL_20:
        kfree(v5);
        goto LABEL_21;
      }
      v8 = -12;
    }
  }
  else
  {
    v8 = -19;
  }
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return v8;
}
