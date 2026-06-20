__int64 __fastcall rgmu_idle_timer(__int64 a1)
{
  return queue_work_on(32, qword_3A900, a1 - 32);
}
