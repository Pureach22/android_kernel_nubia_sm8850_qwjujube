__int64 __fastcall qdf_sleep_uninterruptible(__int64 a1)
{
  if ( (*(_DWORD *)(_ReadStatusReg(SP_EL0) + 16) & 0xFFFF00) != 0 )
    return qdf_trace_msg(56, 2, "%s cannot be called from interrupt context!!!", "qdf_sleep_uninterruptible");
  else
    return msleep(a1);
}
