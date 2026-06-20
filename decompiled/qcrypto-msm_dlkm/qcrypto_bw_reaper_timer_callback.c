__int64 __fastcall qcrypto_bw_reaper_timer_callback(__int64 a1)
{
  return queue_work_on(32, system_wq, a1 + 40);
}
