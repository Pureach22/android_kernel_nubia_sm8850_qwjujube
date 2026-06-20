__int64 __fastcall wlfw_wlan_hw_init_cfg_msg(__int64 a1, int a2)
{
  __int64 v4; // x19
  unsigned __int16 *v5; // x20
  unsigned int v6; // w0
  unsigned int v7; // w22
  unsigned int v8; // w0
  __int64 v9; // x0
  const char *v10; // x21
  _QWORD v12[10]; // [xsp+0h] [xbp-50h] BYREF

  v12[9] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    memset(v12, 0, 72);
    ipc_log_string(icnss_ipc_log_context, "icnss2_qmi: Sending hw init cfg, rf_subtype: 0x%x\n", a2);
    v4 = _kmalloc_cache_noprof(pm_stay_awake, 3520, 8);
    if ( v4 )
    {
      v5 = (unsigned __int16 *)_kmalloc_cache_noprof(pm_stay_awake, 3520, 4);
      if ( !v5 )
      {
        v7 = -12;
        goto LABEL_19;
      }
      *(_BYTE *)v4 = 1;
      *(_DWORD *)(v4 + 4) = a2;
      v6 = qmi_txn_init(a1 + 624, v12, &wlfw_wlan_hw_init_cfg_resp_msg_v01_ei, v5);
      if ( (v6 & 0x80000000) != 0 )
      {
        v7 = v6;
        v10 = "%sicnss2_qmi: Fail to init txn for hw init cfg, resp %d\n";
        printk("%sicnss2_qmi: Fail to init txn for hw init cfg, resp %d\n", byte_130B32, v6);
      }
      else
      {
        v7 = qmi_send_request(a1 + 624, 0, v12, 88, 7, &wlfw_wlan_hw_init_cfg_req_msg_v01_ei, v4);
        if ( (v7 & 0x80000000) != 0 )
        {
          qmi_txn_cancel(v12);
          v10 = "%sicnss2_qmi: Fail to send hw init cfg %d\n";
          printk("%sicnss2_qmi: Fail to send hw init cfg %d\n", byte_130B32, v7);
        }
        else
        {
          v8 = qmi_txn_wait(v12, *(unsigned int *)(a1 + 336));
          if ( (v8 & 0x80000000) == 0 )
          {
            if ( !*v5 )
            {
              v7 = 0;
              v9 = (__int64)v5;
              v5 = (unsigned __int16 *)v4;
LABEL_16:
              kfree(v9);
              v4 = (__int64)v5;
LABEL_19:
              kfree(v4);
              goto LABEL_20;
            }
            printk("%sicnss2_qmi: HW init cfg request rejected,result:%d error:%d\n", byte_130B32, *v5, v5[1]);
            ipc_log_string(
              icnss_ipc_log_context,
              "%sicnss2_qmi: HW init cfg request rejected,result:%d error:%d\n",
              (const char *)&unk_12DBF3,
              *v5,
              v5[1]);
            v7 = -*v5;
LABEL_15:
            v9 = v4;
            goto LABEL_16;
          }
          v7 = v8;
          v10 = "%sicnss2_qmi: HW init cfg timed out with ret %d\n";
          printk("%sicnss2_qmi: HW init cfg timed out with ret %d\n", byte_130B32, v8);
        }
      }
      ipc_log_string(icnss_ipc_log_context, v10, &unk_12DBF3, v7);
      goto LABEL_15;
    }
    v7 = -12;
  }
  else
  {
    v7 = -19;
  }
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return v7;
}
