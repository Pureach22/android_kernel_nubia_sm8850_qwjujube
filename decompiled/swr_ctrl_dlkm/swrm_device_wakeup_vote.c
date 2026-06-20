__int64 __fastcall swrm_device_wakeup_vote(__int64 a1)
{
  __int64 v1; // x19
  __int64 result; // x0

  if ( a1 && (v1 = *(_QWORD *)(a1 + 152)) != 0 )
  {
    if ( (swrm_lock_sleep(*(_QWORD *)(a1 + 152)) & 1) != 0 )
    {
      if ( (unsigned int)swrm_request_hw_vote(v1, 0, 1)
        && (unsigned int)__ratelimit(&swrm_device_wakeup_vote__rs_166, "swrm_device_wakeup_vote") )
      {
        dev_err(*(_QWORD *)(v1 + 8512), "%s:lpass core hw enable failed\n", "swrm_device_wakeup_vote");
      }
      if ( (unsigned int)swrm_request_hw_vote(v1, 1, 1) )
      {
        if ( (unsigned int)__ratelimit(&swrm_device_wakeup_vote__rs_167, "swrm_device_wakeup_vote") )
          dev_err(*(_QWORD *)(v1 + 8512), "%s:lpass audio hw enable failed\n", "swrm_device_wakeup_vote");
      }
      return _pm_runtime_resume(*(_QWORD *)(v1 + 8512), 4);
    }
    else
    {
      result = __ratelimit(&swrm_device_wakeup_vote__rs_165, "swrm_device_wakeup_vote");
      if ( (_DWORD)result )
        return dev_err(*(_QWORD *)(v1 + 8512), "%s Failed to hold suspend\n", "swrm_device_wakeup_vote");
    }
  }
  else
  {
    result = __ratelimit(&swrm_device_wakeup_vote__rs, "swrm_device_wakeup_vote");
    if ( (_DWORD)result )
      return printk(&unk_1079B, "swrm_device_wakeup_vote");
  }
  return result;
}
