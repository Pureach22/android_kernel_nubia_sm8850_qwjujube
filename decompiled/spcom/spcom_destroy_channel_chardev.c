__int64 __fastcall spcom_destroy_channel_chardev(const char *a1)
{
  __int64 v2; // x21
  __int64 v3; // x19
  __int64 v4; // x1
  __int64 v5; // x2
  unsigned int v6; // w0
  __int64 v7; // x0
  int v9; // w21

  printk(&unk_1114A, "spcom_destroy_channel_chardev", a1);
  ipc_log_string(
    spcom_ipc_log_context,
    "%sspcom:%s: destroy channel [%s]\n",
    "spcom_destroy_channel_chardev",
    (const char *)&unk_F80E,
    a1);
  v2 = 32;
  v3 = spcom_dev + 1200;
  while ( strcmp((const char *)v3, a1) )
  {
    --v2;
    v3 += 1784;
    if ( !v2 )
      goto LABEL_9;
  }
  if ( !v3 )
  {
LABEL_9:
    printk(&unk_FC94, "spcom_destroy_channel_chardev", a1);
    ipc_log_string(
      spcom_ipc_log_context,
      "%sspcom:%s: channel [%s] not exist\n",
      "spcom_destroy_channel_chardev",
      (const char *)&unk_F80E,
      a1);
    return 4294967274LL;
  }
  v6 = spcom_unregister_rpmsg_drv(v3, v4, v5);
  if ( (v6 & 0x80000000) != 0 )
  {
    v9 = v6;
    printk(&unk_12172, "spcom_destroy_channel_chardev", v6);
    ipc_log_string(
      spcom_ipc_log_context,
      "%sspcom:%s: unregister rpmsg driver failed %d\n",
      "spcom_destroy_channel_chardev",
      (const char *)&unk_F80E,
      v9);
  }
  mutex_lock(v3 + 32);
  device_destroy(*(_QWORD *)(spcom_dev + 1168), *(unsigned int *)(v3 + 144));
  kfree(*(_QWORD *)(v3 + 96));
  mutex_unlock(v3 + 32);
  mutex_lock(spcom_dev + 58296);
  v7 = spcom_dev + 58296;
  --*(_DWORD *)(spcom_dev + 58288);
  mutex_unlock(v7);
  return 0;
}
