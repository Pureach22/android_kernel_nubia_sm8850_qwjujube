__int64 __fastcall spcom_rx(__int64 a1, void *a2, int a3, unsigned int a4)
{
  size_t StatusReg; // x21
  __int64 v8; // x23
  int v9; // w5
  __int64 v10; // x0
  __int64 v11; // x23
  __int64 v12; // x2
  unsigned int v13; // w22
  int v14; // w8

  LODWORD(StatusReg) = a3;
  v8 = _msecs_to_jiffies(a4);
  mutex_lock(a1 + 32);
  v9 = *(_DWORD *)(a1 + 336);
  if ( v9 != *(_DWORD *)(a1 + 80) )
  {
    ipc_log_string(
      spcom_ipc_log_context,
      "%sspcom:%s: ch[%s]:ch->rx_buf_txn_id=%d is updated in a different session\n",
      "spcom_rx",
      (const char *)&unk_F80E,
      (const char *)a1,
      v9);
    if ( *(_QWORD *)(a1 + 328) )
    {
      memset(*(void **)(a1 + 328), 0, *(_QWORD *)(a1 + 320));
      kfree(*(_QWORD *)(a1 + 328));
      *(_QWORD *)(a1 + 320) = 0;
      *(_QWORD *)(a1 + 328) = 0;
    }
  }
  if ( *(_QWORD *)(a1 + 320) )
  {
    ipc_log_string(
      spcom_ipc_log_context,
      "%sspcom:%s: ch[%s]:rx data size [%zu], txn_id:%d\n",
      "spcom_rx",
      &unk_F80E,
      a1);
  }
  else
  {
    *(_DWORD *)(a1 + 168) = 0;
    mutex_unlock(a1 + 32);
    v10 = a1 + 168;
    if ( a4 )
    {
      v11 = wait_for_completion_killable_timeout(v10, v8);
      mutex_lock(a1 + 32);
      if ( !v11 )
      {
        printk(&unk_129D0, "spcom_rx", a1);
        ipc_log_string(
          spcom_ipc_log_context,
          "%sspcom:%s: ch[%s]: timeout expired %d ms, set txn_id=%d\n",
          "spcom_rx",
          (const char *)&unk_F80E,
          (const char *)a1,
          a4,
          *(_DWORD *)(a1 + 80));
        LODWORD(StatusReg) = -110;
        ++*(_DWORD *)(a1 + 80);
        goto LABEL_22;
      }
      v13 = 0;
    }
    else
    {
      v13 = (unsigned int)wait_for_completion_killable(v10) >> 31;
      mutex_lock(a1 + 32);
      v11 = 1;
    }
    if ( *(_BYTE *)(a1 + 316) == 1 )
    {
      printk(&unk_E756, "spcom_rx", v12);
      ipc_log_string(
        spcom_ipc_log_context,
        "%sspcom:%s: rpmsg channel is closing\n",
        "spcom_rx",
        (const char *)&unk_F80E);
      LODWORD(StatusReg) = -85;
      goto LABEL_22;
    }
    if ( v11 < 0 )
      v14 = 1;
    else
      v14 = v13;
    if ( v14 == 1 )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      printk(&unk_123DC, "spcom_rx", *(unsigned int *)(StatusReg + 1804));
      ipc_log_string(
        spcom_ipc_log_context,
        "%sspcom:%s: rx wait was interrupted! PID: %d",
        "spcom_rx",
        (const char *)&unk_F80E,
        *(_DWORD *)(StatusReg + 1804));
      LODWORD(StatusReg) = -4;
      goto LABEL_22;
    }
    if ( !*(_QWORD *)(a1 + 320) )
    {
      printk(&unk_F199, "spcom_rx", a1);
      ipc_log_string(
        spcom_ipc_log_context,
        "%sspcom:%s: ch[%s]:actual_rx_size==0\n",
        "spcom_rx",
        (const char *)&unk_F80E,
        (const char *)a1);
      LODWORD(StatusReg) = -14;
      goto LABEL_22;
    }
    ipc_log_string(
      spcom_ipc_log_context,
      "%sspcom:%s: ch[%s]:actual_rx_size is [%zu], txn_id %d\n",
      "spcom_rx",
      &unk_F80E,
      a1);
  }
  if ( *(_QWORD *)(a1 + 328) )
  {
    if ( *(_QWORD *)(a1 + 320) >= (unsigned __int64)(unsigned int)StatusReg )
      StatusReg = (unsigned int)StatusReg;
    else
      StatusReg = *(_QWORD *)(a1 + 320);
    memcpy(a2, *(const void **)(a1 + 328), StatusReg);
    memset(*(void **)(a1 + 328), 0, *(_QWORD *)(a1 + 320));
    kfree(*(_QWORD *)(a1 + 328));
    *(_QWORD *)(a1 + 320) = 0;
    *(_QWORD *)(a1 + 328) = 0;
  }
  else
  {
    printk(&unk_12A41, "spcom_rx", a1);
    ipc_log_string(
      spcom_ipc_log_context,
      "%sspcom:%s: ch[%s]:invalid rpmsg_rx_buf\n",
      "spcom_rx",
      (const char *)&unk_F80E,
      (const char *)a1);
    LODWORD(StatusReg) = -12;
  }
LABEL_22:
  mutex_unlock(a1 + 32);
  return (unsigned int)StatusReg;
}
