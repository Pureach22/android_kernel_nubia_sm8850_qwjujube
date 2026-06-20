__int64 __fastcall qdf_mutex_release(__int64 a1)
{
  unsigned __int64 StatusReg; // x8
  char v3; // w9

  if ( !a1 )
  {
    qdf_trace_msg(56, 2, "%s: NULL pointer passed in", "qdf_mutex_release");
    return 5;
  }
  if ( *(_DWORD *)(a1 + 48) == 305419896 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xFFFF00) != 0 )
    {
      qdf_trace_msg(56, 2, "%s cannot be called from interrupt context!!!", "qdf_mutex_release");
      return 5;
    }
    if ( *(_DWORD *)(a1 + 52) == *(_DWORD *)(StatusReg + 1800) )
    {
      v3 = *(_BYTE *)(a1 + 60);
      if ( *(_DWORD *)(a1 + 56) == 287454021 )
      {
        if ( !*(_BYTE *)(a1 + 60) )
          goto LABEL_14;
        *(_BYTE *)(a1 + 60) = --v3;
      }
      if ( v3 )
        return 0;
LABEL_14:
      *(_BYTE *)(a1 + 60) = 0;
      *(_DWORD *)(a1 + 52) = 0;
      *(_DWORD *)(a1 + 56) = 287454020;
      mutex_unlock(a1);
      return 0;
    }
    qdf_trace_msg(56, 2, "%s: current task pid does not match original task pid!!", "qdf_mutex_release");
    return 12;
  }
  else
  {
    qdf_trace_msg(56, 2, "%s: uninitialized lock", "qdf_mutex_release");
    return 4;
  }
}
