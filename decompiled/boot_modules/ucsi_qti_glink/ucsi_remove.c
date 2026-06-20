__int64 __fastcall ucsi_remove(__int64 a1)
{
  _QWORD *v1; // x20
  int v3; // w0
  __int64 result; // x0

  v1 = *(_QWORD **)(a1 + 168);
  debugfs_remove(v1[3]);
  cancel_work_sync(v1 + 173);
  if ( (cancel_work_sync(v1 + 177) & 1) == 0 )
  {
    ucsi_unregister(v1[1]);
    ucsi_destroy(v1[1]);
  }
  v3 = pmic_glink_unregister_client(v1[2]);
  if ( v3 < 0 )
    dev_err(a1 + 16, "pmic_glink_unregister_client failed rc=%d\n", v3);
  result = ipc_log_context_destroy(ucsi_ipc_log);
  ucsi_ipc_log = 0;
  return result;
}
