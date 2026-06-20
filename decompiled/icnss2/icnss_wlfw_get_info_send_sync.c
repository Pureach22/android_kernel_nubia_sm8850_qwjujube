__int64 __fastcall icnss_wlfw_get_info_send_sync(__int64 a1, char a2, const void *a3, unsigned int a4)
{
  __int64 v8; // x19
  unsigned __int16 *v9; // x20
  unsigned int v10; // w0
  unsigned int v11; // w21
  unsigned int v12; // w0
  const char *v14; // x22
  unsigned __int64 StatusReg; // x20
  __int64 v16; // x25
  _QWORD v17[10]; // [xsp+0h] [xbp-50h] BYREF

  v17[9] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (int)a4 > 6144 || (*(_QWORD *)(a1 + 1832) & 0x2000) != 0 )
  {
    v11 = -22;
  }
  else
  {
    memset(v17, 0, 72);
    v8 = _kmalloc_cache_noprof(icc_set_bw, 3520, 6152);
    if ( v8 )
    {
      while ( 1 )
      {
        v9 = (unsigned __int16 *)_kmalloc_cache_noprof(pm_stay_awake, 3520, 4);
        if ( !v9 )
          break;
        *(_BYTE *)v8 = a2;
        *(_DWORD *)(v8 + 4) = a4;
        if ( a4 < 0x1801 )
        {
          memcpy((void *)(v8 + 8), a3, a4);
          v10 = qmi_txn_init(a1 + 624, v17, &wlfw_get_info_resp_msg_v01_ei, v9);
          if ( (v10 & 0x80000000) != 0 )
          {
            v11 = v10;
            v14 = "%sicnss2_qmi: Failed to initialize txn for get info request, err: %d\n";
            printk("%sicnss2_qmi: Failed to initialize txn for get info request, err: %d\n", byte_130B32, v10);
          }
          else
          {
            v11 = qmi_send_request(a1 + 624, 0, v17, 74, 6153, &wlfw_get_info_req_msg_v01_ei, v8);
            if ( (v11 & 0x80000000) != 0 )
            {
              qmi_txn_cancel(v17);
              v14 = "%sicnss2_qmi: Failed to send get info request, err: %d\n";
              printk("%sicnss2_qmi: Failed to send get info request, err: %d\n", byte_130B32, v11);
            }
            else
            {
              v12 = qmi_txn_wait(v17, *(unsigned int *)(a1 + 336));
              if ( (v12 & 0x80000000) == 0 )
              {
                if ( *v9 )
                {
                  printk("%sicnss2_qmi: Get info request failed, result: %d, err: %d\n", byte_130B32, *v9, v9[1]);
                  ipc_log_string(
                    icnss_ipc_log_context,
                    "%sicnss2_qmi: Get info request failed, result: %d, err: %d\n",
                    (const char *)&unk_12DBF3,
                    *v9,
                    v9[1]);
                  v11 = -*v9;
                }
                else
                {
                  v11 = 0;
                }
                goto LABEL_11;
              }
              v11 = v12;
              v14 = "%sicnss2_qmi: Failed to wait for response of get info request, err: %d\n";
              printk("%sicnss2_qmi: Failed to wait for response of get info request, err: %d\n", byte_130B32, v12);
            }
          }
          ipc_log_string(icnss_ipc_log_context, v14, &unk_12DBF3, v11);
LABEL_11:
          kfree(v8);
          goto LABEL_22;
        }
        _fortify_panic(17, 6144, a4);
        StatusReg = _ReadStatusReg(SP_EL0);
        v16 = *(_QWORD *)(StatusReg + 80);
        *(_QWORD *)(StatusReg + 80) = &icnss_wlfw_get_info_send_sync__alloc_tag;
        v8 = _kmalloc_cache_noprof(icc_set_bw, 3520, 6152);
        *(_QWORD *)(StatusReg + 80) = v16;
        if ( !v8 )
          goto LABEL_20;
      }
      v11 = -12;
      v9 = (unsigned __int16 *)v8;
LABEL_22:
      kfree(v9);
    }
    else
    {
LABEL_20:
      v11 = -12;
    }
  }
  _ReadStatusReg(SP_EL0);
  return v11;
}
