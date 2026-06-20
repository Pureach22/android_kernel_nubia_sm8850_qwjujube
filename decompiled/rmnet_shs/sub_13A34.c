void __fastcall sub_13A34(unsigned int a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  unsigned __int64 StatusReg; // x20

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    _traceiter_rmnet_shs_wq_high(0, 9, 53, a1, a5, a6, 7, 0);
    JUMPOUT(0x13A84);
  }
  JUMPOUT(0x139A8);
}
