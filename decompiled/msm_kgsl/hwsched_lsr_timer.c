__int64 __fastcall hwsched_lsr_timer(__int64 a1)
{
  return queue_work_on(32, qword_3A900, a1 + 40);
}
