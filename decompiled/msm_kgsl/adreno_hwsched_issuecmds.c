__int64 __fastcall adreno_hwsched_issuecmds(__int64 a1)
{
  __int64 v2; // x20
  __int64 v10; // x3
  __int64 v12; // x21
  __int64 v13; // x21
  __int64 result; // x0
  _QWORD v15[14]; // [xsp+0h] [xbp-70h] BYREF

  v15[13] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  raw_spin_lock(a1 + 11080);
  if ( (*(_BYTE *)(a1 + 11084) & 1) != 0 )
    goto LABEL_14;
  ++*(_DWORD *)(a1 + 11076);
  raw_spin_unlock(a1 + 11080);
  if ( !(unsigned int)mutex_trylock(a1 + 22448) )
  {
    raw_spin_lock(a1 + 11080);
    --*(_DWORD *)(a1 + 11076);
LABEL_14:
    raw_spin_unlock(a1 + 11080);
    result = kthread_queue_work(*(_QWORD *)(a1 + 24400), a1 + 24408);
    goto LABEL_15;
  }
  __dmb(9u);
  if ( !*(_DWORD *)(a1 + 24448) )
  {
    v2 = 0;
    _X25 = (unsigned __int64 *)(a1 + 22512);
    do
    {
      _X9 = _X25 + 16;
      memset(v15, 0, 104);
      __asm { PRFM            #0x11, [X9] }
      do
        v10 = __ldxr(_X9);
      while ( __stlxr(0, _X9) );
      __dmb(0xBu);
      __asm { PRFM            #0x11, [X25] }
      do
        v12 = __ldxr(_X25);
      while ( __stlxr(0, _X25) );
      __dmb(0xBu);
      hwsched_handle_jobs_list(a1, v2, (__int64)v15, v10);
      hwsched_handle_jobs_list(a1, v2++, (__int64)v15, v12);
      ++_X25;
    }
    while ( v2 != 16 );
  }
  if ( *(_DWORD *)(a1 + 22504) )
  {
    rt_mutex_lock(a1 + 11088);
    kgsl_pwrscale_update(a1);
    v13 = jiffies;
    *(_QWORD *)(a1 + 14144) = _msecs_to_jiffies(*(_QWORD *)(a1 + 10080)) + v13;
    mod_timer(a1 + 8792);
    rt_mutex_unlock(a1 + 11088);
  }
  mutex_unlock(a1 + 22448);
  raw_spin_lock(a1 + 11080);
  --*(_DWORD *)(a1 + 11076);
  result = raw_spin_unlock(a1 + 11080);
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
