void __fastcall sub_13404(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  unsigned __int64 StatusReg; // x19

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    _traceiter_rmnet_shs_wq_high(0, 9, 59, a4, a5, 3567, 3567, 0);
    JUMPOUT(0x13454);
  }
  JUMPOUT(0x133D4);
}
