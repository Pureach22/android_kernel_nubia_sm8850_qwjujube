__int64 __fastcall vibrator_timer_func(__int64 a1)
{
  __int64 v1; // x1

  v1 = *(_QWORD *)(a1 + 280);
  *(_DWORD *)(a1 - 752) = 0;
  queue_work_on(32, v1, a1 + 248);
  return 0;
}
