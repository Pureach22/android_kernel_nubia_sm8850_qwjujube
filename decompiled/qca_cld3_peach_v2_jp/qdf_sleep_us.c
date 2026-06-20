__int64 qdf_sleep_us()
{
  __int64 v0; // x0
  unsigned __int64 StatusReg; // x19
  __int64 result; // x0
  bool v3; // cf

  v0 = _usecs_to_jiffies();
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(StatusReg + 16) & 0xFFFF00) != 0 )
    return qdf_trace_msg(56, 2, "%s cannot be called from interrupt context!!!", "qdf_sleep_us");
  v3 = __CFADD__(v0, 1);
  result = v0 + 1;
  if ( !v3 )
  {
    do
    {
      if ( (*(_QWORD *)StatusReg & 0x40) != 0 )
        break;
      if ( (*(_QWORD *)StatusReg & 1) != 0 )
        break;
      result = schedule_timeout_interruptible();
    }
    while ( result );
  }
  return result;
}
