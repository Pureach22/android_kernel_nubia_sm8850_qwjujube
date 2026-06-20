__int64 gh_dbgfs_trace_class_clear()
{
  _ReadStatusReg(SP_EL0);
  __asm { HVC             #0x603F }
  _ReadStatusReg(SP_EL0);
  return 0;
}
