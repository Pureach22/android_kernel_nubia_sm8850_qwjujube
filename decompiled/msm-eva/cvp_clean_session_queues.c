__int64 __fastcall cvp_clean_session_queues(__int64 a1)
{
  int v2; // w22
  _QWORD *v3; // x21
  _QWORD *v4; // x23
  unsigned __int64 StatusReg; // x8

  mutex_lock(a1 + 15272);
  if ( (unsigned int)(*(_DWORD *)(a1 + 15320) - 1) > 1 )
  {
    if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      printk(&unk_95AB2, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), "warn");
    }
    mutex_unlock(a1 + 15272);
  }
  else
  {
    mutex_unlock(a1 + 15272);
    cvp_clean_fence_queue(a1);
  }
  cvp_fence_thread_stop(a1);
  v2 = 101;
  v3 = (_QWORD *)(a1 + 15368);
  while ( 1 )
  {
    mutex_lock(a1 + 15272);
    v4 = (_QWORD *)*v3;
    mutex_unlock(a1 + 15272);
    if ( v4 == v3 )
      break;
    usleep_range_state(500, 1000, 2);
    if ( !--v2 )
      return 4294967280LL;
  }
  return 0;
}
