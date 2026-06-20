__int64 __fastcall gen8_gmu_irq_handler(__int64 a1, __int64 a2)
{
  __int64 v3; // x8
  __int64 v4; // x21
  unsigned int v5; // w8
  void (__fastcall *v6)(_QWORD); // x8
  int v8; // [xsp+0h] [xbp-10h] BYREF
  unsigned int v9; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a2 + 14264);
  v9 = 0;
  v4 = *(_QWORD *)(v3 + 40);
  gmu_core_regread(a2, 146181, &v9);
  gmu_core_regwrite(a2, 146180, v9);
  if ( (v9 & 0x20) != 0 && (unsigned int)__ratelimit(&gen8_gmu_irq_handler__rs, "gen8_gmu_irq_handler") )
  {
    dev_err(*(_QWORD *)(a2 + 1544) + 16LL, "AHB bus error interrupt received\n");
    v5 = v9;
    if ( (v9 & 1) == 0 )
      goto LABEL_7;
  }
  else
  {
    v5 = v9;
    if ( (v9 & 1) == 0 )
      goto LABEL_7;
  }
  v6 = *(void (__fastcall **)(_QWORD))(v4 + 344);
  if ( *((_DWORD *)v6 - 1) != 994519391 )
    __break(0x8228u);
  v6(a2);
  v5 = v9;
LABEL_7:
  if ( (v5 & 8) != 0 )
  {
    v8 = 0;
    gmu_core_regread(a2, 146195, &v8);
    if ( (unsigned int)__ratelimit(&gen8_gmu_irq_handler__rs_83, "gen8_gmu_irq_handler") )
      dev_err(*(_QWORD *)(a2 + 1544) + 16LL, "FENCE error interrupt received %x\n", v8);
    v5 = v9;
  }
  if ( (v5 & 0xFFFFFFD6) != 0 && (unsigned int)__ratelimit(&gen8_gmu_irq_handler__rs_85, "gen8_gmu_irq_handler") )
    dev_err(*(_QWORD *)(a2 + 1544) + 16LL, "Unhandled GMU interrupts 0x%lx\n", v9 & 0xFFFFFFD6);
  _ReadStatusReg(SP_EL0);
  return 1;
}
