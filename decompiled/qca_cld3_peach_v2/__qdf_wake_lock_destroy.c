__int64 __fastcall _qdf_wake_lock_destroy(__int64 a1)
{
  qdf_trace_msg(56, 8, "%s enter", "__qdf_wake_lock_destroy");
  wakeup_source_unregister(*(_QWORD *)(a1 + 192));
  return qdf_trace_msg(56, 8, "%s exit", "__qdf_wake_lock_destroy");
}
