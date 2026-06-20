__int64 __fastcall kgsl_work_period_timer(__int64 a1)
{
  return queue_work_on(32, qword_3A908, a1 + 48);
}
