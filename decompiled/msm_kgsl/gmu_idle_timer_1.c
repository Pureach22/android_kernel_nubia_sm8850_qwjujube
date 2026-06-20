__int64 __fastcall gmu_idle_timer_1(__int64 a1)
{
  return queue_work_on(32, qword_3A900, a1 - 32);
}
