__int64 __fastcall icnss_wlfw_aux_dnld_send_sync(__int64 a1)
{
  __int64 v2; // x19
  unsigned __int16 *v3; // x20
  __int64 v4; // x4
  __int64 v5; // x9
  unsigned int v6; // w0
  unsigned int v7; // w22
  unsigned int v8; // w0
  const char *v9; // x21
  _QWORD v11[10]; // [xsp+0h] [xbp-50h] BYREF

  v11[9] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v11, 0, 72);
  ipc_log_string(icnss_ipc_log_context, "icnss2_qmi: Sending Aux file download message");
  v2 = _kmalloc_cache_noprof(_init_swait_queue_head, 3520, 16);
  if ( v2 )
  {
    v3 = (unsigned __int16 *)_kmalloc_cache_noprof(pm_stay_awake, 3520, 4);
    if ( !v3 )
    {
      v7 = -12;
      v3 = (unsigned __int16 *)v2;
      goto LABEL_19;
    }
    if ( *(_QWORD *)(a1 + 5424) && (v4 = *(_QWORD *)(a1 + 5408)) != 0 )
    {
      ipc_log_string(
        icnss_ipc_log_context,
        "icnss2_qmi: AUX memory, va: 0x%pK, pa: %pa, size: 0x%zx\n",
        *(const void **)(a1 + 5416),
        (const void *)(a1 + 5424),
        v4);
      v5 = *(_QWORD *)(a1 + 5408);
      *(_QWORD *)v2 = *(_QWORD *)(a1 + 5424);
      *(_DWORD *)(v2 + 8) = v5;
      v6 = qmi_txn_init(a1 + 624, v11, &wlfw_aux_uc_info_resp_msg_v01_ei, v3);
      if ( (v6 & 0x80000000) != 0 )
      {
        v7 = v6;
        v9 = "%sicnss2_qmi: Failed to initialize txn for QMI_WLFW_AUX_UC_INFO_REQ_V01 request, err: %d\n";
        printk(
          "%sicnss2_qmi: Failed to initialize txn for QMI_WLFW_AUX_UC_INFO_REQ_V01 request, err: %d\n",
          byte_130B32,
          v6);
      }
      else
      {
        v7 = qmi_send_request(a1 + 624, 0, v11, 90, 18, &wlfw_aux_uc_info_req_msg_v01_ei, v2);
        if ( (v7 & 0x80000000) != 0 )
        {
          qmi_txn_cancel(v11);
          v9 = "%sicnss2_qmi: Failed to send QMI_WLFW_AUX_UC_INFO_REQ_V01 request, err: %d\n";
          printk("%sicnss2_qmi: Failed to send QMI_WLFW_AUX_UC_INFO_REQ_V01 request, err: %d\n", byte_130B32, v7);
        }
        else
        {
          v8 = qmi_txn_wait(v11, *(unsigned int *)(a1 + 336));
          if ( (v8 & 0x80000000) == 0 )
          {
            if ( *v3 )
            {
              printk(
                "%sicnss2_qmi: QMI_WLFW_AUX_UC_INFO_REQ_V01 request failed, result: %d, err: %d\n",
                byte_130B32,
                *v3,
                v3[1]);
              ipc_log_string(
                icnss_ipc_log_context,
                "%sicnss2_qmi: QMI_WLFW_AUX_UC_INFO_REQ_V01 request failed, result: %d, err: %d\n",
                (const char *)&unk_12DBF3,
                *v3,
                v3[1]);
              v7 = -*v3;
            }
            else
            {
              v7 = 0;
            }
            goto LABEL_10;
          }
          v7 = v8;
          v9 = "%sicnss2_qmi: Failed to wait for response of QMI_WLFW_AUX_UC_INFO_REQ_V01 request, err: %d\n";
          printk(
            "%sicnss2_qmi: Failed to wait for response of QMI_WLFW_AUX_UC_INFO_REQ_V01 request, err: %d\n",
            byte_130B32,
            v8);
        }
      }
      ipc_log_string(icnss_ipc_log_context, v9, &unk_12DBF3, v7);
    }
    else
    {
      printk("%sicnss2_qmi: Memory for AUX is not available\n", byte_130B32);
      ipc_log_string(
        icnss_ipc_log_context,
        "%sicnss2_qmi: Memory for AUX is not available\n",
        (const char *)&unk_12DBF3);
      v7 = -12;
    }
LABEL_10:
    kfree(v2);
LABEL_19:
    kfree(v3);
    goto LABEL_20;
  }
  v7 = -12;
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return v7;
}
