void sub_945FC()
{
  unsigned __int64 StatusReg; // x21

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    _traceiter_kgsl_gmu_oob_clear(0, 0x1000000);
    JUMPOUT(0x94638);
  }
  JUMPOUT(0x944E4);
}
