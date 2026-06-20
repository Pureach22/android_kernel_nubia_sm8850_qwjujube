__int64 spcom_signal_rx_done()
{
  __int64 v0; // x0
  __int64 v1; // x8
  __int64 v2; // x9
  __int64 *v3; // x19
  __int64 **v4; // x8
  __int64 *v5; // x10
  __int64 v6; // x2
  __int64 v7; // x28
  __int64 v8; // x27
  __int64 v9; // x0
  int v10; // w5
  __int64 v11; // x8
  int v12; // w5
  int v13; // w6
  int v14; // w9
  __int64 v15; // x8
  __int64 v16; // x0

  v0 = raw_spin_lock_irqsave(spcom_dev + 58448);
  v1 = spcom_dev;
  v2 = v0;
  if ( *(_QWORD *)(spcom_dev + 58432) == spcom_dev + 58432 )
    return raw_spin_unlock_irqrestore(v1 + 58448, v2);
  while ( 1 )
  {
    v3 = *(__int64 **)(v1 + 58440);
    v4 = (__int64 **)v3[1];
    if ( *v4 == v3 && (v5 = (__int64 *)*v3, *(__int64 **)(*v3 + 8) == v3) )
    {
      v5[1] = (__int64)v4;
      *v4 = v5;
    }
    else
    {
      _list_del_entry_valid_or_report(v3);
    }
    *v3 = 0xDEAD000000000100LL;
    v3[1] = 0xDEAD000000000122LL;
    raw_spin_unlock_irqrestore(spcom_dev + 58448, v2);
    if ( !v3 )
    {
      printk(&unk_10606, "spcom_signal_rx_done", v6);
      ipc_log_string(
        spcom_ipc_log_context,
        "%sspcom:%s: empty entry in pending rx list\n",
        "spcom_signal_rx_done",
        (const char *)&unk_F80E);
      goto LABEL_15;
    }
    v7 = v3[4];
    v8 = v3[2];
    mutex_lock(v7 + 32);
    if ( *(_BYTE *)(v7 + 85) == 1 )
    {
      *(_WORD *)(v7 + 84) = 1;
      v9 = spcom_ipc_log_context;
      v10 = *(_DWORD *)(v8 + 4);
      *(_DWORD *)(v7 + 80) = v10;
      ipc_log_string(
        v9,
        "%sspcom:%s: ch [%s] first packet txn_id=%d, it is server\n",
        "spcom_signal_rx_done",
        (const char *)&unk_F80E,
        (const char *)v7,
        v10);
    }
    v11 = *(_QWORD *)(v7 + 328);
    if ( *(_BYTE *)(v7 + 316) == 1 )
      break;
    if ( v11 )
    {
      printk(&unk_10FE2, "spcom_signal_rx_done", v7);
      ipc_log_string(
        spcom_ipc_log_context,
        "%sspcom:%s: ch [%s] previous buffer not consumed %zd bytes\n",
        "spcom_signal_rx_done",
        (const char *)&unk_F80E,
        (const char *)v7,
        *(_QWORD *)(v7 + 320));
      kfree(*(_QWORD *)(v7 + 328));
      *(_QWORD *)(v7 + 320) = 0;
      *(_QWORD *)(v7 + 328) = 0;
    }
    v12 = *(_DWORD *)(v8 + 4);
    if ( (*(_BYTE *)(v7 + 84) & 1) != 0 )
    {
      v13 = *(_DWORD *)(v7 + 80);
    }
    else
    {
      v13 = *(_DWORD *)(v8 + 4);
      if ( v12 != *(_DWORD *)(v7 + 80) )
      {
        printk(&unk_12E7F, "spcom_signal_rx_done", v7);
        ipc_log_string(
          spcom_ipc_log_context,
          "%sspcom:%s: ch [%s] client: rx dropped txn_id %d, ch->txn_id %d\n",
          "spcom_signal_rx_done",
          (const char *)&unk_F80E,
          (const char *)v7,
          *(_DWORD *)(v8 + 4),
          *(_DWORD *)(v7 + 80));
        goto LABEL_22;
      }
    }
    ipc_log_string(
      spcom_ipc_log_context,
      "%sspcom:%s: ch[%s] rx txn_id %d, ch->txn_id %d, size=%d\n",
      "spcom_signal_rx_done",
      (const char *)&unk_F80E,
      (const char *)v7,
      v12,
      v13,
      *((_DWORD *)v3 + 6));
    v14 = *(_DWORD *)(v7 + 80);
    *(_QWORD *)(v7 + 328) = v3[2];
    v15 = *((int *)v3 + 6);
    *(_DWORD *)(v7 + 336) = v14;
    *(_QWORD *)(v7 + 320) = v15;
    complete_all(v7 + 168);
    mutex_unlock(v7 + 32);
    kfree(v3);
LABEL_15:
    v16 = raw_spin_lock_irqsave(spcom_dev + 58448);
    v1 = spcom_dev;
    v2 = v16;
    if ( *(_QWORD *)(spcom_dev + 58432) == spcom_dev + 58432 )
      return raw_spin_unlock_irqrestore(v1 + 58448, v2);
  }
  if ( v11 )
  {
    ipc_log_string(
      spcom_ipc_log_context,
      "%sspcom:%s: ch [%s] rx aborted free %zd bytes\n",
      "spcom_signal_rx_done",
      (const char *)&unk_F80E,
      (const char *)v7,
      *(_QWORD *)(v7 + 320));
    kfree(*(_QWORD *)(v7 + 328));
    *(_QWORD *)(v7 + 320) = 0;
  }
LABEL_22:
  mutex_unlock(v7 + 32);
  kfree(v3[2]);
  return kfree(v3);
}
