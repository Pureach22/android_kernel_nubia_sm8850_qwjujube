__int64 __fastcall aw86320_timecheck_work_init(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x0

  if ( *(int *)(result + 12) >= 1024 )
  {
    v1 = result;
    cancel_delayed_work_sync(result + 712);
    *(_QWORD *)(v1 + 712) = 0xFFFFFFFE00000LL;
    *(_QWORD *)(v1 + 720) = v1 + 720;
    *(_QWORD *)(v1 + 728) = v1 + 720;
    *(_QWORD *)(v1 + 736) = aw86320_timecheck_work_handle;
    init_timer_key(v1 + 744, &delayed_work_timer_fn, 0x200000, 0, 0);
    v2 = _msecs_to_jiffies(*(unsigned int *)(v1 + 12));
    return queue_delayed_work_on(32, system_wq, v1 + 712, v2);
  }
  return result;
}
