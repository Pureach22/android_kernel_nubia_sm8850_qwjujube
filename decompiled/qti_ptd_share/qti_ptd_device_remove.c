__int64 __fastcall qti_ptd_device_remove(__int64 a1)
{
  __int64 v1; // x19

  v1 = *(_QWORD *)(a1 + 168);
  ipc_log_context_destroy(*(_QWORD *)(v1 + 8));
  ipc_log_context_destroy(*(_QWORD *)(v1 + 16));
  return qptm_data_update_notifier_unregister(v1 + 24);
}
