__int64 __fastcall a6xx_gmu_irq_handler(__int64 a1, __int64 a2)
{
  __int64 v3; // x8
  __int64 v4; // x21
  char v5; // w8
  void (__fastcall *v6)(_QWORD); // x8
  unsigned int v7; // w8
  int v9; // [xsp+0h] [xbp-10h] BYREF
  unsigned int v10; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a2 + 14264);
  v10 = 0;
  v4 = *(_QWORD *)(v3 + 40);
  gmu_core_regread(a2, 146181, &v10);
  gmu_core_regwrite(a2, 146180, v10);
  v5 = v10;
  if ( (v10 & 1) != 0 )
  {
    v6 = *(void (__fastcall **)(_QWORD))(v4 + 344);
    if ( *((_DWORD *)v6 - 1) != 994519391 )
      __break(0x8228u);
    v6(a2);
    v5 = v10;
  }
  if ( (v5 & 0x20) != 0 && (unsigned int)__ratelimit(&a6xx_gmu_irq_handler__rs, "a6xx_gmu_irq_handler") )
  {
    dev_err(*(_QWORD *)(a2 + 1544) + 16LL, "AHB bus error interrupt received\n");
    v7 = v10;
    if ( (v10 & 8) == 0 )
      goto LABEL_11;
  }
  else
  {
    v7 = v10;
    if ( (v10 & 8) == 0 )
      goto LABEL_11;
  }
  v9 = 0;
  gmu_core_regread(a2, 146195, &v9);
  if ( (unsigned int)__ratelimit(&a6xx_gmu_irq_handler__rs_96, "a6xx_gmu_irq_handler") )
    dev_err(*(_QWORD *)(a2 + 1544) + 16LL, "FENCE error interrupt received %x\n", v9);
  v7 = v10;
LABEL_11:
  if ( (v7 & 0xFFFFFFD6) != 0 && (unsigned int)__ratelimit(&a6xx_gmu_irq_handler__rs_98, "a6xx_gmu_irq_handler") )
    dev_err(*(_QWORD *)(a2 + 1544) + 16LL, "Unhandled GMU interrupts 0x%lx\n", v10 & 0xFFFFFFD6);
  _ReadStatusReg(SP_EL0);
  return 1;
}
