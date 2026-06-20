__int64 __fastcall qcom_slim_ngd_runtime_idle(__int64 a1)
{
  __int64 v1; // x20
  int v3; // w8

  v1 = *(_QWORD *)(a1 + 152);
  if ( !*(_DWORD *)(v1 + 5384) )
    *(_DWORD *)(v1 + 5384) = 1;
  _slimbus_dbg();
  v3 = *(_DWORD *)(v1 + 5476);
  if ( v3 >= 4 )
  {
    ipc_log_string(*(_QWORD *)(v1 + 5488), "pm_runtime: idle...\n");
    v3 = *(_DWORD *)(v1 + 5476);
  }
  if ( !v3 )
    ipc_log_string(*(_QWORD *)(v1 + 5496), "pm_runtime: idle...\n");
  _pm_runtime_suspend(a1, 9);
  return 4294967285LL;
}
