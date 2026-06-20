__int64 __fastcall pwrkey_timer(__int64 a1)
{
  return queue_work_on(32, system_wq, a1 + 40);
}
