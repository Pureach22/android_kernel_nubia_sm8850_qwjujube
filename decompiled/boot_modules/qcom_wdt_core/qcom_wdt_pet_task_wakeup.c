__int64 __fastcall qcom_wdt_pet_task_wakeup(__int64 a1)
{
  *(_BYTE *)(a1 + 64) = 1;
  *(_QWORD *)(a1 + 72) = sched_clock(a1);
  return _wake_up(a1 + 40, 3, 1, 0);
}
