// positive sp value has been detected, the output may be wrong!
__int64 sub_D03F4()
{
  __int64 v0; // x19
  _QWORD *v1; // x20
  __int64 v2; // x21
  __int64 v3; // x8
  __int64 result; // x0
  unsigned __int64 StatusReg; // x9
  unsigned __int64 v11; // x11

  v3 = _arch_copy_to_user(v2 & 0xFF7FFFFFFFFFFFFFLL);
  result = v0;
  StatusReg = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v11 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
  _WriteStatusReg(TTBR0_EL1, v11 - 4096);
  _WriteStatusReg(TTBR1_EL1, v11);
  __isb(0xFu);
  _WriteStatusReg(DAIF, StatusReg);
  if ( v3 )
    result = -14;
  else
    *v1 += v0;
  _ReadStatusReg(SP_EL0);
  return result;
}
