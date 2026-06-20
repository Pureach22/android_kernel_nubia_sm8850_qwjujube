__int64 __fastcall gh_rm_vm_irq_lend_notify(__int16 a1, unsigned int a2)
{
  __int64 result; // x0
  __int16 v3; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v4; // [xsp+8h] [xbp-8h]

  v4 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = a1;
  result = gh_rm_vm_irq_notify(&v3, 1, 1, a2);
  _ReadStatusReg(SP_EL0);
  return result;
}
