__int64 __fastcall vib_overdrive_timer(__int64 a1)
{
  queue_work_on(32, system_wq, a1 + 64);
  return 0;
}
