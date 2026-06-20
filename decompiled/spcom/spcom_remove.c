__int64 __fastcall spcom_remove(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x27
  __int64 v5; // x28
  __int64 v6; // x22
  int v7; // w0
  int v8; // w24
  __int64 v9; // x0
  __int64 v10; // x2
  __int64 v11; // x8
  __int64 i; // x23
  __int64 v13; // x2
  _QWORD *v15; // x0
  _QWORD *v16; // x8
  __int64 v17; // x9
  _QWORD *v18; // x9
  __int64 v19; // x0
  unsigned int v25; // w9

  _X8 = (unsigned int *)(spcom_dev + 58428);
  __asm { PRFM            #0x11, [X8] }
  do
    v25 = __ldxr(_X8);
  while ( __stxr(v25 + 1, _X8) );
  if ( *(_QWORD *)(spcom_dev + 58464) )
  {
    printk(&unk_107CB, "spcom_remove", a3);
    ipc_log_string(spcom_ipc_log_context, "%sspcom:%s: shutdown spss\n", "spcom_remove", (const char *)&unk_F80E);
    rproc_shutdown(*(_QWORD *)(spcom_dev + 58464));
    *(_QWORD *)(spcom_dev + 58464) = 0;
  }
  v4 = 1200;
  v5 = 32;
  while ( 1 )
  {
    v6 = spcom_dev;
    if ( !*(_BYTE *)(spcom_dev + v4) )
      break;
    v7 = spcom_destroy_channel_chardev(spcom_dev + v4);
    if ( v7 )
    {
      v8 = v7;
      printk(&unk_102A4, "spcom_remove", v6 + v4);
      ipc_log_string(
        spcom_ipc_log_context,
        "%sspcom:%s: failed to destroy chardev [%s], ret [%d]\n",
        "spcom_remove",
        (const char *)&unk_F80E,
        (const char *)(v6 + v4),
        v8);
    }
    ipc_log_string(
      spcom_ipc_log_context,
      "%sspcom:%s: destroyed channel %s",
      "spcom_remove",
      (const char *)&unk_F80E,
      (const char *)(v6 + v4));
    --v5;
    v4 += 1784;
    if ( !v5 )
    {
      v6 = spcom_dev;
      break;
    }
  }
  cdev_del(v6 + 1024);
  device_destroy(*(_QWORD *)(spcom_dev + 1168), *(unsigned int *)(spcom_dev + 1160));
  class_destroy(*(_QWORD *)(spcom_dev + 1168));
  mutex_lock(spcom_dev + 58296);
  unregister_chrdev_region(*(unsigned int *)(spcom_dev + 1160), *(unsigned int *)(spcom_dev + 58288));
  mutex_unlock(spcom_dev + 58296);
  ipc_log_string(
    spcom_ipc_log_context,
    "%sspcom:%s: control spcom device removed\n",
    "spcom_unregister_chrdev",
    (const char *)&unk_F80E);
  v9 = raw_spin_lock_irqsave(spcom_dev + 58448);
  v11 = spcom_dev;
  for ( i = v9; *(_QWORD *)(spcom_dev + 58432) != spcom_dev + 58432; i = v19 )
  {
    while ( 1 )
    {
      v15 = *(_QWORD **)(v11 + 58440);
      v16 = (_QWORD *)v15[1];
      if ( (_QWORD *)*v16 == v15 && (v17 = *v15, *(_QWORD **)(*v15 + 8LL) == v15) )
      {
        *(_QWORD *)(v17 + 8) = v16;
        *v16 = v17;
      }
      else
      {
        _list_del_entry_valid_or_report();
        v15 = v18;
      }
      *v15 = 0xDEAD000000000100LL;
      v15[1] = 0xDEAD000000000122LL;
      if ( !v15 )
        break;
      kfree(v15);
      v11 = spcom_dev;
      if ( *(_QWORD *)(spcom_dev + 58432) == spcom_dev + 58432 )
        goto LABEL_11;
    }
    printk(&unk_10606, "spcom_remove", v10);
    ipc_log_string(
      spcom_ipc_log_context,
      "%sspcom:%s: empty entry in pending rx list\n",
      "spcom_remove",
      (const char *)&unk_F80E);
    v19 = raw_spin_lock_irqsave(spcom_dev + 58448);
    v11 = spcom_dev;
  }
LABEL_11:
  raw_spin_unlock_irqrestore(v11 + 58448, i);
  wakeup_source_unregister(*(_QWORD *)(spcom_dev + 1192));
  if ( spcom_ipc_log_context )
    ipc_log_context_destroy();
  kfree(spcom_dev);
  spcom_dev = 0;
  return printk(&unk_107E6, "spcom_remove", v13);
}
