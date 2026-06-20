__int64 __fastcall qdf_mutex_create(__int64 a1)
{
  if ( a1 )
  {
    if ( *(_DWORD *)(a1 + 48) == 305419896 )
    {
      qdf_trace_msg(56, 2, "%s: already initialized lock", "qdf_mutex_create");
      return 8;
    }
    if ( (*(_DWORD *)(_ReadStatusReg(SP_EL0) + 16) & 0xFFFF00) == 0 )
    {
      _mutex_init();
      *(_DWORD *)(a1 + 48) = 305419896;
      *(_BYTE *)(a1 + 60) = 0;
      *(_QWORD *)(a1 + 52) = 0x1122334400000000LL;
      return 0;
    }
    qdf_trace_msg(56, 2, "%s cannot be called from interrupt context!!!", "qdf_mutex_create");
  }
  else
  {
    qdf_trace_msg(56, 2, "%s: NULL pointer passed in", "qdf_mutex_create");
  }
  return 5;
}
