__int64 __fastcall swrm_notify_work_fn(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x20
  __int64 result; // x0

  if ( a1 == 15440 || (v1 = *(_QWORD *)(a1 - 96)) == 0 )
  {
    result = __ratelimit(&swrm_notify_work_fn__rs, "swrm_notify_work_fn");
    if ( (_DWORD)result )
      return printk(&unk_107F0, "swrm_notify_work_fn");
  }
  else
  {
    v2 = *(_QWORD *)(v1 + 168);
    if ( v2 )
    {
      mutex_lock(v2 + 8784);
      if ( *(_DWORD *)(v2 + 15336) != 3 )
        swrm_device_down(v1 + 16);
      return mutex_unlock(v2 + 8784);
    }
    else
    {
      result = __ratelimit(&swrm_wcd_notify__rs_8, "swrm_wcd_notify");
      if ( (_DWORD)result )
        return dev_err(v1 + 16, "%s: swrm is NULL\n", "swrm_wcd_notify");
    }
  }
  return result;
}
