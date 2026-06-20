__int64 __fastcall adreno_pwrctrl_active_count_get(__int64 a1)
{
  __int64 v1; // x19
  unsigned int v2; // w8
  unsigned int v10; // w9

  if ( *(_QWORD *)(a1 + 11112) )
  {
    if ( *(_DWORD *)(a1 + 11128)
      || *(_DWORD *)(a1 + 11120) == 2
      || (v1 = a1,
          rt_mutex_unlock(a1 + 11088),
          wait_for_completion(v1 + 8688),
          rt_mutex_lock(v1 + 11088),
          *(_BYTE *)(v1 + 10440) = 1,
          v2 = kgsl_pwrctrl_change_state(v1, 2),
          a1 = v1,
          !v2) )
    {
      _X8 = (unsigned int *)(a1 + 11128);
      __asm { PRFM            #0x11, [X8] }
      do
        v10 = __ldxr(_X8);
      while ( __stxr(v10 + 1, _X8) );
      return 0;
    }
  }
  else
  {
    __break(0x800u);
    return (unsigned int)-22;
  }
  return v2;
}
