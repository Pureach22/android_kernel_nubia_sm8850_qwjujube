__int64 __fastcall htc_runtime_resume(__int64 a1)
{
  if ( a1 )
    queue_work_on(32, system_wq, a1 + 3504);
  return 0;
}
