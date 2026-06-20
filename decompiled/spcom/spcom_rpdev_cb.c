__int64 __fastcall spcom_rpdev_cb(__int64 a1, __int64 a2, __int64 a3)
{
  const char *v4; // x20
  unsigned int v5; // w19
  __int64 v6; // x21
  __int64 v7; // x0
  __int64 v8; // x8
  __int64 v9; // x0
  __int64 v10; // x8
  __int64 *v11; // x1
  __int64 v12; // x2
  __int64 v13; // x9

  if ( a1 && a2 )
  {
    v4 = *(const char **)(a1 + 152);
    if ( v4 )
    {
      v5 = a3;
      if ( (unsigned int)(a3 - 301) <= 0xFFFFFED3 )
      {
        printk(&unk_1158A, "spcom_rpdev_cb", (unsigned int)a3);
        ipc_log_string(
          spcom_ipc_log_context,
          "%sspcom:%s: got msg size %d, max allowed %d\n",
          "spcom_rpdev_cb",
          (const char *)&unk_F80E,
          v5,
          300);
        return 4294967274LL;
      }
      else
      {
        v6 = _kmalloc_cache_noprof(complete_all, 2336, 40);
        if ( v6 && (v7 = kmemdup_noprof(a2, v5, 2080), (*(_QWORD *)(v6 + 16) = v7) != 0) )
        {
          *(_DWORD *)(v6 + 24) = v5;
          v8 = spcom_dev;
          *(_QWORD *)(v6 + 32) = v4;
          pm_wakeup_ws_event(*(_QWORD *)(v8 + 1192), 2000, 1);
          ipc_log_string(
            spcom_ipc_log_context,
            "%sspcom:%s: %s:got new packet, wakeup requested\n",
            "spcom_rpdev_cb",
            (const char *)&unk_F80E,
            v4);
          v9 = raw_spin_lock_irqsave(spcom_dev + 58448);
          v10 = spcom_dev;
          v11 = (__int64 *)(spcom_dev + 58432);
          v12 = *(_QWORD *)(spcom_dev + 58432);
          v13 = v9;
          if ( *(_QWORD *)(v12 + 8) != spcom_dev + 58432 || (__int64 *)v6 == v11 || v12 == v6 )
          {
            _list_add_valid_or_report(v6);
            v10 = spcom_dev;
          }
          else
          {
            *(_QWORD *)(v12 + 8) = v6;
            *(_QWORD *)v6 = v12;
            *(_QWORD *)(v6 + 8) = v11;
            *v11 = v6;
          }
          raw_spin_unlock_irqrestore(v10 + 58448, v13);
          queue_work_on(32, system_wq, &spcom_rpdev_cb_rpmsg_rx_consumer);
          return 0;
        }
        else
        {
          return 4294967284LL;
        }
      }
    }
    else
    {
      printk(&unk_10426, "spcom_rpdev_cb", 0);
      ipc_log_string(
        spcom_ipc_log_context,
        "%sspcom:%s: %s: invalid ch\n",
        "spcom_rpdev_cb",
        (const char *)&unk_F80E,
        nullptr);
      return 4294967274LL;
    }
  }
  else
  {
    printk(&unk_FE2C, "spcom_rpdev_cb", a3);
    ipc_log_string(
      spcom_ipc_log_context,
      "%sspcom:%s: rpdev or data is NULL\n",
      "spcom_rpdev_cb",
      (const char *)&unk_F80E);
    return 4294967274LL;
  }
}
