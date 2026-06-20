__int64 __fastcall qdf_mutex_acquire(__int64 a1)
{
  unsigned __int64 StatusReg; // x20
  char v5; // w9

  if ( !a1 )
  {
    qdf_trace_msg(56, 2, "%s: NULL pointer passed in", "qdf_mutex_acquire");
    return 5;
  }
  if ( *(_DWORD *)(a1 + 48) == 305419896 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xFFFF00) != 0 )
    {
      qdf_trace_msg(56, 2, "%s cannot be called from interrupt context!!!", "qdf_mutex_acquire");
      return 5;
    }
    if ( *(_DWORD *)(a1 + 52) == *(_DWORD *)(StatusReg + 1800) && *(_DWORD *)(a1 + 56) == 287454021 )
    {
      ++*(_BYTE *)(a1 + 60);
      return 0;
    }
    mutex_lock();
    if ( (mutex_is_locked(a1) & 1) == 0 )
    {
      qdf_trace_msg(56, 2, "%s: unable to lock mutex (rc = %d)", "qdf_mutex_acquire", 0);
      return 16;
    }
    if ( *(_DWORD *)(a1 + 56) == 287454022 )
    {
      qdf_trace_msg(56, 2, "%s: Lock is already destroyed", "qdf_mutex_acquire");
      mutex_unlock(a1);
      return 16;
    }
    v5 = *(_BYTE *)(a1 + 60) + 1;
    *(_DWORD *)(a1 + 52) = *(_DWORD *)(StatusReg + 1800);
    *(_DWORD *)(a1 + 56) = 287454021;
    *(_BYTE *)(a1 + 60) = v5;
    return 0;
  }
  else
  {
    qdf_trace_msg(56, 2, "%s: uninitialized lock", "qdf_mutex_acquire");
    return 4;
  }
}
