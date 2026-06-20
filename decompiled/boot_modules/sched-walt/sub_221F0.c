void __usercall sub_221F0(unsigned int a1@<W8>, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x22
  __int64 v5; // x23
  unsigned __int64 StatusReg; // x20

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    _traceiter_sched_load_sync_settings(0, HIDWORD(a4), v4, v5, a1);
    JUMPOUT(0x22238);
  }
  JUMPOUT(0x22250);
}
