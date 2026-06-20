__int64 __fastcall qdf_mutex_destroy(__int64 a1)
{
  if ( !a1 )
  {
    qdf_trace_msg(56, 2, "%s: NULL pointer passed in", "qdf_mutex_destroy");
    return 5;
  }
  if ( *(_DWORD *)(a1 + 48) == 305419896 )
  {
    if ( (*(_DWORD *)(_ReadStatusReg(SP_EL0) + 16) & 0xFFFF00) != 0 )
    {
      qdf_trace_msg(56, 2, "%s cannot be called from interrupt context!!!", "qdf_mutex_destroy");
      return 5;
    }
    if ( (unsigned int)mutex_trylock() )
    {
      *(_QWORD *)(a1 + 48) = 0;
      *(_BYTE *)(a1 + 60) = 0;
      *(_DWORD *)(a1 + 56) = 287454022;
      mutex_unlock(a1);
      return 0;
    }
    else
    {
      qdf_trace_msg(56, 2, "%s: lock is not released", "qdf_mutex_destroy");
      return 8;
    }
  }
  else
  {
    qdf_trace_msg(56, 2, "%s: uninitialized lock", "qdf_mutex_destroy");
    return 4;
  }
}
