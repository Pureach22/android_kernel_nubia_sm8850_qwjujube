__int64 __fastcall sde_core_irq_domain_add(_QWORD *a1)
{
  __int64 v1; // x8
  __int64 v2; // x8
  __int64 v3; // x8
  bool v5; // zf
  __int64 v6; // x8
  unsigned __int64 v7; // x0
  unsigned __int64 v8; // x8
  __int64 result; // x0
  void *v10; // x0
  _QWORD v11[13]; // [xsp+8h] [xbp-68h] BYREF

  v11[12] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = a1[17];
  if ( !v1 || (v2 = *(_QWORD *)(v1 + 8)) == 0 )
  {
    v10 = &unk_216038;
LABEL_11:
    printk(v10, "sde_core_irq_domain_add");
    result = 4294967274LL;
    goto LABEL_8;
  }
  v3 = *(_QWORD *)(v2 + 744);
  v11[2] = 32;
  memset(&v11[3], 0, 24);
  v5 = v3 == 0;
  v6 = v3 + 24;
  if ( v5 )
    v6 = 0;
  memset(&v11[8], 0, 32);
  v11[0] = v6;
  v11[1] = 0x2000000000LL;
  v11[6] = &sde_core_irqdomain_ops;
  v11[7] = a1;
  v7 = irq_domain_instantiate(v11);
  if ( v7 > 0xFFFFFFFFFFFFF000LL || (v8 = v7) == 0 )
  {
    v10 = &unk_23BCD1;
    goto LABEL_11;
  }
  result = 0;
  a1[235] = 0;
  a1[236] = v8;
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
