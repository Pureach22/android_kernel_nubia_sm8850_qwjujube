__int64 qdf_sleep()
{
  if ( (*(_DWORD *)(_ReadStatusReg(SP_EL0) + 16) & 0xFFFF00) != 0 )
    return qdf_trace_msg(56, 2, "%s cannot be called from interrupt context!!!", "qdf_sleep");
  else
    return msleep_interruptible();
}
