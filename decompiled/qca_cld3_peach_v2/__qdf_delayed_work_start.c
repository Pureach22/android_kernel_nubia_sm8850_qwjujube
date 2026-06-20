__int64 __fastcall _qdf_delayed_work_start(__int64 a1, unsigned int a2)
{
  __int64 v3; // x0

  v3 = _msecs_to_jiffies(a2);
  return queue_delayed_work_on(32, system_wq, a1, v3) & 1;
}
