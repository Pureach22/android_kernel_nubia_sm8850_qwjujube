void sub_6F42C()
{
  __int64 v0; // x19
  unsigned __int64 StatusReg; // x20

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    _traceiter_rdev_return_int_tx_rx(0, v0 + 992, 0);
    JUMPOUT(0x6F470);
  }
  JUMPOUT(0x6F3BC);
}
