__int64 __fastcall chg_ulog_remove(__int64 a1)
{
  _QWORD *v1; // x19
  unsigned int v2; // w0

  v1 = *(_QWORD **)(a1 + 168);
  debugfs_remove(v1[2]);
  cancel_delayed_work_sync(v1 + 15);
  v2 = pmic_glink_unregister_client(v1[1]);
  if ( (v2 & 0x80000000) != 0 )
    printk(&unk_702F, "chg_ulog_remove", v2);
  ipc_log_context_destroy(v1[3]);
  return ipc_log_context_destroy(v1[4]);
}
