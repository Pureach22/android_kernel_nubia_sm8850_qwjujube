__int64 __fastcall qdf_wake_lock_timeout_acquire(__int64 a1, __int64 a2)
{
  pm_wakeup_ws_event(*(_QWORD *)(a1 + 192), a2, 1);
  return 0;
}
