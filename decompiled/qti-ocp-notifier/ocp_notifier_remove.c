__int64 __fastcall ocp_notifier_remove(__int64 a1)
{
  __int64 v1; // x19

  v1 = *(_QWORD *)(a1 + 168);
  ipc_log_context_destroy(*(_QWORD *)(v1 + 48));
  ipc_log_context_destroy(*(_QWORD *)(v1 + 72));
  return idr_destroy(v1 + 8);
}
