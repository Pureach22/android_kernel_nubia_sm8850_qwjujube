unsigned __int64 __fastcall irq_domain_add_tree(__int64 a1, __int64 a2)
{
  __int64 v2; // x9
  __int64 v3; // x8
  unsigned __int64 result; // x0
  _QWORD v5[13]; // [xsp+8h] [xbp-68h] BYREF

  v2 = a1 + 24;
  v3 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
    v2 = 0;
  v5[12] = v3;
  v5[2] = 0xFFFFFFFFLL;
  memset(&v5[3], 0, 24);
  v5[0] = v2;
  v5[1] = 0;
  v5[6] = &pmic_arb_irq_domain_ops;
  v5[7] = a2;
  memset(&v5[8], 0, 32);
  result = irq_domain_instantiate(v5);
  _ReadStatusReg(SP_EL0);
  if ( result > 0xFFFFFFFFFFFFF000LL )
    return 0;
  return result;
}
