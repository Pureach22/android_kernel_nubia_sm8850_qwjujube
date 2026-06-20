__int64 __fastcall hwsched_idle_timer_0(__int64 a1)
{
  return queue_work_on(32, qword_3A900, a1 - 32);
}
