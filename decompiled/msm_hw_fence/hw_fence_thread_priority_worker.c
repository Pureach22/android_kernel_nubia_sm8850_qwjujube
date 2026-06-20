__int64 __fastcall hw_fence_thread_priority_worker(__int64 a1)
{
  __int64 v1; // x30
  __int64 v2; // x19
  unsigned __int64 v3; // x4
  __int64 result; // x0
  __int64 v5; // x4
  struct sched_param param; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v7; // [xsp+8h] [xbp-8h]

  v2 = v1;
  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 - 8);
  param.__sched_priority = 83;
  if ( v3 && v3 < 0xFFFFFFFFFFFFF001LL )
  {
    result = sched_setscheduler(v3, 1, &param);
    if ( (_DWORD)result )
    {
      result = printk(&unk_25611, "hw_fence_thread_priority_worker", 687, v2, (unsigned int)result);
    }
    else if ( (~msm_hw_fence_debug_level & 0x10008) == 0 )
    {
      result = printk(&unk_21486, "hw_fence_thread_priority_worker", 690, (unsigned int)param.__sched_priority, v5);
    }
  }
  else
  {
    result = printk(&unk_220A0, "hw_fence_thread_priority_worker", 680, v1, v3);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
