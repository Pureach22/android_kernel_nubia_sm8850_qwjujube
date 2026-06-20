void __fastcall qcom_slim_ngd_enable(__int64 a1, __int64 a2)
{
  __int64 v3; // x8
  int v4; // w8
  int v5; // w8
  __int64 v6; // x0
  _QWORD *v7; // x20
  unsigned int v8; // w0
  unsigned int v9; // w0
  __int64 v10; // x8
  unsigned int v11; // w0
  unsigned int v12; // w21
  int v13; // w8
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x20
  int v17; // w8
  int v18; // w8
  int v19; // w8
  int v20; // w8
  int v21; // w8
  int v22; // w8
  int v23; // w8
  int v24; // w8
  __int64 v25; // [xsp+8h] [xbp-68h] BYREF
  int v26; // [xsp+10h] [xbp-60h]
  _QWORD v27[9]; // [xsp+18h] [xbp-58h] BYREF
  int v28; // [xsp+64h] [xbp-Ch] BYREF
  __int64 v29; // [xsp+68h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (a2 & 1) != 0 )
  {
    v3 = *(_QWORD *)(a1 + 1920);
    v26 = 0;
    v25 = 0;
    if ( v3 )
    {
      _slimbus_dbg();
      v4 = *(_DWORD *)(a1 + 5476);
      if ( v4 >= 3 )
      {
        ipc_log_string(*(_QWORD *)(a1 + 5488), "qmi handle already allocated\n");
        v4 = *(_DWORD *)(a1 + 5476);
      }
      if ( !v4 )
        ipc_log_string(*(_QWORD *)(a1 + 5496), "qmi handle already allocated\n");
LABEL_24:
      complete(a1 + 1928);
      v14 = *(_QWORD *)(a1 + 928);
      if ( (*(_WORD *)(v14 + 488) & 7) != 0 || *(_DWORD *)(v14 + 500) != 2 )
        v15 = qcom_slim_ngd_runtime_resume();
      else
        v15 = _pm_runtime_resume();
      v16 = *(_QWORD *)(a1 + 928);
      *(_QWORD *)(v16 + 520) = ktime_get_mono_fast_ns(v15);
      _pm_runtime_idle(*(_QWORD *)(a1 + 928), 5);
      _slimbus_dbg();
      v17 = *(_DWORD *)(a1 + 5476);
      if ( v17 >= 3 )
      {
        ipc_log_string(
          *(_QWORD *)(a1 + 5488),
          "SLIM %s: PM put count:%d\n",
          "qcom_slim_ngd_enable",
          *(_DWORD *)(*(_QWORD *)(a1 + 928) + 480LL));
        v17 = *(_DWORD *)(a1 + 5476);
      }
      if ( !v17 )
        ipc_log_string(
          *(_QWORD *)(a1 + 5496),
          "SLIM %s: PM put count:%d\n",
          "qcom_slim_ngd_enable",
          *(_DWORD *)(*(_QWORD *)(a1 + 928) + 480LL));
      _slimbus_dbg();
      v18 = *(_DWORD *)(a1 + 5476);
      if ( v18 >= 3 )
      {
        ipc_log_string(*(_QWORD *)(a1 + 5488), "SLIM NGD Enable\n");
        v18 = *(_DWORD *)(a1 + 5476);
      }
      if ( !v18 )
        ipc_log_string(*(_QWORD *)(a1 + 5496), "SLIM NGD Enable\n");
      goto LABEL_36;
    }
    v6 = devm_kmalloc(*(_QWORD *)(a1 + 1968), 304, 3520);
    if ( !v6 )
    {
      v12 = -12;
      goto LABEL_65;
    }
    v7 = (_QWORD *)v6;
    v8 = qmi_handle_init(v6, 14, 0, &qcom_slim_qmi_msg_handlers);
    if ( (v8 & 0x80000000) != 0 )
    {
      v12 = v8;
      dev_err(*(_QWORD *)(a1 + 1968), "QMI client init failed: %d\n", v8);
LABEL_64:
      devm_kfree(*(_QWORD *)(a1 + 1968), v7);
LABEL_65:
      _slimbus_dbg();
      v24 = *(_DWORD *)(a1 + 5476);
      if ( v24 >= 1 )
      {
        printk(&unk_C86C, v12);
        ipc_log_string(*(_QWORD *)(a1 + 5488), "qmi init fail, ret:%d, state:%d\n", v12, *(_DWORD *)(a1 + 5384));
        *(_QWORD *)(a1 + 5472) = *(unsigned int *)(a1 + 5476);
      }
      else if ( v24 )
      {
        goto LABEL_36;
      }
      ipc_log_string(*(_QWORD *)(a1 + 5496), "qmi init fail, ret:%d, state:%d\n", v12, *(_DWORD *)(a1 + 5384));
      goto LABEL_36;
    }
    v9 = kernel_connect(*v7, a1 + 1592, 12, 0);
    if ( (v9 & 0x80000000) == 0 )
    {
      v10 = *(_QWORD *)(a1 + 1960);
      BYTE4(v25) = 1;
      LODWORD(v10) = *(_DWORD *)(v10 + 16);
      v26 = 2;
      v28 = 0;
      *(_QWORD *)(a1 + 1920) = v7;
      LODWORD(v25) = (int)v10 >> 1;
      memset(v27, 0, sizeof(v27));
      v11 = qmi_txn_init(v7, v27, &slimbus_select_inst_resp_msg_v01_ei, &v28);
      if ( (v11 & 0x80000000) != 0 )
      {
        v12 = v11;
        _slimbus_dbg();
        v20 = *(_DWORD *)(a1 + 5476);
        if ( v20 < 1 )
        {
          if ( v20 )
            goto LABEL_62;
        }
        else
        {
          printk(&unk_C25F, v12);
          ipc_log_string(*(_QWORD *)(a1 + 5488), "QMI TXN init fail: %d\n", v12);
          *(_QWORD *)(a1 + 5472) = *(unsigned int *)(a1 + 5476);
        }
        ipc_log_string(*(_QWORD *)(a1 + 5496), "QMI TXN init fail: %d\n", v12);
        goto LABEL_62;
      }
      v12 = qmi_send_request(*(_QWORD *)(a1 + 1920), 0, v27, 32, 14, &slimbus_select_inst_req_msg_v01_ei, &v25);
      if ( (v12 & 0x80000000) == 0 )
      {
        v12 = qmi_txn_wait(v27, 1000);
        if ( (v12 & 0x80000000) == 0 )
        {
          if ( !(_WORD)v28 )
          {
            _slimbus_dbg();
            v13 = *(_DWORD *)(a1 + 5476);
            if ( v13 >= 3 )
            {
              ipc_log_string(*(_QWORD *)(a1 + 5488), "%s end RC=%d\n", "qcom_slim_qmi_send_select_inst_req", v12);
              v13 = *(_DWORD *)(a1 + 5476);
            }
            if ( !v13 )
              ipc_log_string(*(_QWORD *)(a1 + 5496), "%s end RC=%d\n", "qcom_slim_qmi_send_select_inst_req", v12);
            goto LABEL_24;
          }
          _slimbus_dbg();
          v23 = *(_DWORD *)(a1 + 5476);
          if ( v23 < 1 )
          {
            if ( v23 )
            {
LABEL_61:
              v12 = -121;
              goto LABEL_62;
            }
          }
          else
          {
            printk(&unk_C900, (unsigned __int16)v28);
            ipc_log_string(*(_QWORD *)(a1 + 5488), "QMI request failed 0x%x\n", (unsigned __int16)v28);
            *(_QWORD *)(a1 + 5472) = *(unsigned int *)(a1 + 5476);
          }
          ipc_log_string(*(_QWORD *)(a1 + 5496), "QMI request failed 0x%x\n", (unsigned __int16)v28);
          goto LABEL_61;
        }
        _slimbus_dbg();
        v22 = *(_DWORD *)(a1 + 5476);
        if ( v22 >= 1 )
        {
          printk(&unk_CA0D, v12);
          ipc_log_string(*(_QWORD *)(a1 + 5488), "QMI TXN wait fail: %d\n", v12);
          *(_QWORD *)(a1 + 5472) = *(unsigned int *)(a1 + 5476);
LABEL_57:
          ipc_log_string(*(_QWORD *)(a1 + 5496), "QMI TXN wait fail: %d\n", v12);
          goto LABEL_62;
        }
        if ( !v22 )
          goto LABEL_57;
LABEL_62:
        dev_err(*(_QWORD *)(a1 + 1968), "failed to select h/w instance\n");
        *(_QWORD *)(a1 + 1920) = 0;
        goto LABEL_63;
      }
      _slimbus_dbg();
      v21 = *(_DWORD *)(a1 + 5476);
      if ( v21 < 1 )
      {
        if ( v21 )
        {
LABEL_55:
          qmi_txn_cancel(v27);
          goto LABEL_62;
        }
      }
      else
      {
        printk(&unk_CC90, v12);
        ipc_log_string(*(_QWORD *)(a1 + 5488), "QMI send req fail %d\n", v12);
        *(_QWORD *)(a1 + 5472) = *(unsigned int *)(a1 + 5476);
      }
      ipc_log_string(*(_QWORD *)(a1 + 5496), "QMI send req fail %d\n", v12);
      goto LABEL_55;
    }
    v12 = v9;
    _slimbus_dbg();
    v19 = *(_DWORD *)(a1 + 5476);
    if ( v19 >= 1 )
    {
      printk(&unk_D157, v12);
      ipc_log_string(*(_QWORD *)(a1 + 5488), "Remote Service connect failed: %d\n", v12);
      *(_QWORD *)(a1 + 5472) = *(unsigned int *)(a1 + 5476);
    }
    else if ( v19 )
    {
LABEL_63:
      qmi_handle_release(v7);
      goto LABEL_64;
    }
    ipc_log_string(*(_QWORD *)(a1 + 5496), "Remote Service connect failed: %d\n", v12);
    goto LABEL_63;
  }
  mutex_lock(a1 + 5296, a2);
  if ( *(_QWORD *)(a1 + 1920) )
  {
    ((void (*)(void))qmi_handle_release)();
    devm_kfree(*(_QWORD *)(a1 + 1968), *(_QWORD *)(a1 + 1920));
    *(_QWORD *)(a1 + 1920) = 0;
  }
  mutex_unlock(a1 + 5296);
  _slimbus_dbg();
  v5 = *(_DWORD *)(a1 + 5476);
  if ( v5 >= 3 )
  {
    ipc_log_string(*(_QWORD *)(a1 + 5488), "SLIM NGD Disable\n");
    v5 = *(_DWORD *)(a1 + 5476);
  }
  if ( !v5 )
    ipc_log_string(*(_QWORD *)(a1 + 5496), "SLIM NGD Disable\n");
LABEL_36:
  _ReadStatusReg(SP_EL0);
}
