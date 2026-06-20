__int64 msm_drm_display_thread_priority_worker()
{
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v1; // x20
  __int64 v2; // x19
  __int64 result; // x0
  struct sched_param param; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v5; // [xsp+8h] [xbp-8h]

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = _ReadStatusReg(SP_EL0);
  v5 = *(_QWORD *)(StatusReg + 1808);
  v2 = *(_QWORD *)(v1 + 1864);
  param.__sched_priority = 16;
  result = sched_setscheduler(v2, 1, &param);
  if ( (_DWORD)result )
    result = printk(&unk_24153F, *(unsigned int *)(v1 + 1804));
  _ReadStatusReg(SP_EL0);
  return result;
}
