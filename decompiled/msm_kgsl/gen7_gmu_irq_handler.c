__int64 __fastcall gen7_gmu_irq_handler(__int64 a1, __int64 a2)
{
  __int64 v3; // x8
  __int64 v4; // x20
  __int64 v5; // x22
  unsigned int v6; // w8
  void (__fastcall *v7)(_QWORD); // x8
  int v9; // [xsp+0h] [xbp-10h] BYREF
  unsigned int v10; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a2 + 14264);
  v4 = *(_QWORD *)(a2 + 1544);
  v10 = 0;
  v5 = *(_QWORD *)(v3 + 40);
  gmu_core_regread(a2, 146181, &v10);
  gmu_core_regwrite(a2, 146180, v10);
  if ( (v10 & 0x20) != 0 && (unsigned int)__ratelimit(&gen7_gmu_irq_handler__rs, "gen7_gmu_irq_handler") )
  {
    dev_err(v4 + 16, "AHB bus error interrupt received\n");
    v6 = v10;
    if ( (v10 & 1) == 0 )
      goto LABEL_7;
  }
  else
  {
    v6 = v10;
    if ( (v10 & 1) == 0 )
      goto LABEL_7;
  }
  v7 = *(void (__fastcall **)(_QWORD))(v5 + 344);
  if ( *((_DWORD *)v7 - 1) != 994519391 )
    __break(0x8228u);
  v7(a2);
  v6 = v10;
LABEL_7:
  if ( (v6 & 8) != 0 )
  {
    v9 = 0;
    gmu_core_regread(a2, 146195, &v9);
    if ( (unsigned int)__ratelimit(&gen7_gmu_irq_handler__rs_80, "gen7_gmu_irq_handler") )
      dev_err(v4 + 16, "FENCE error interrupt received %x\n", v9);
    v6 = v10;
  }
  if ( (v6 & 0xFFFFFFD6) != 0 && (unsigned int)__ratelimit(&gen7_gmu_irq_handler__rs_82, "gen7_gmu_irq_handler") )
    dev_err(v4 + 16, "Unhandled GMU interrupts 0x%lx\n", v10 & 0xFFFFFFD6);
  _ReadStatusReg(SP_EL0);
  return 1;
}
