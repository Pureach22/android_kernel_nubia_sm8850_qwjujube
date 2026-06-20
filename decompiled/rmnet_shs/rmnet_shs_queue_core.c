__int64 __fastcall rmnet_shs_queue_core(__int64 a1)
{
  rmnet_shs_reset_cpus();
  queue_work_on(32, system_wq, a1 + 64);
  return 0;
}
