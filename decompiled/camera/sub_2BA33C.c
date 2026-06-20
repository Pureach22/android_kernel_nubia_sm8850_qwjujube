// positive sp value has been detected, the output may be wrong!
__int64 sub_2BA33C()
{
  __int64 v0; // x19
  __int64 v1; // x20
  __int64 v2; // x0
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v9; // x9
  __int64 v11; // x22

  v2 = _arch_copy_to_user(v1 & 0xFF7FFFFFFFFFFFFFLL);
  StatusReg = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v9 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
  _WriteStatusReg(TTBR0_EL1, v9 - 4096);
  _WriteStatusReg(TTBR1_EL1, v9);
  __isb(0xFu);
  _WriteStatusReg(DAIF, StatusReg);
  if ( v2 )
  {
    printk(&unk_432DD2);
    v11 = -14;
  }
  else
  {
    v11 = 0;
  }
  mutex_unlock(v0);
  _ReadStatusReg(SP_EL0);
  return v11;
}
