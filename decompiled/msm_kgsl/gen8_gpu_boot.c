__int64 __fastcall gen8_gpu_boot(__int64 a1)
{
  __int64 v2; // x22
  unsigned int v3; // w20
  __int64 v5; // x8
  __int64 v6; // x8
  void (__fastcall *v7)(_QWORD); // x8
  unsigned int v8; // w0
  unsigned __int64 v9; // x0
  unsigned __int64 v10; // x0
  unsigned __int64 v11; // x0
  __int64 v12; // x8
  int v13; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v14; // [xsp+8h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 14264);
  adreno_set_active_ctxs_null(a1);
  v3 = kgsl_mmu_start(a1);
  if ( v3 )
    goto LABEL_5;
  v3 = gen8_gmu_oob_set(a1, 0);
  if ( v3 || (v13 = 10, (v3 = gen8_hfi_send_generic_req(a1, &v13, 4)) != 0) )
  {
LABEL_4:
    gmu_core_regwrite(a1, 129428, 0x80000000LL);
LABEL_5:
    gen8_gmu_power_off(a1);
    goto LABEL_6;
  }
  *(_QWORD *)(a1 + 20376) = 0;
  *(_QWORD *)(a1 + 20368) = 0;
  *(_QWORD *)(a1 + 20360) = 0;
  *(_QWORD *)(a1 + 20352) = 0;
  *(_QWORD *)(a1 + 20344) = 0;
  *(_QWORD *)(a1 + 20336) = 0;
  *(_DWORD *)(a1 + 20384) = 0;
  gen8_start(a1);
  v5 = *(_QWORD *)(v2 + 216);
  if ( v5 && (*(_QWORD *)(a1 + 14240) & 0x200) != 0 )
    kgsl_regmap_write(a1 + 13200, *(unsigned int *)(v5 + 4LL * *(int *)(*(_QWORD *)(a1 + 19640) + 28LL)));
  adreno_coresight_start(a1);
  adreno_perfcounter_start(a1);
  v6 = *(_QWORD *)(a1 + 88);
  if ( v6 )
  {
    v7 = *(void (__fastcall **)(_QWORD))(v6 + 40);
    if ( v7 )
    {
      if ( *((_DWORD *)v7 - 1) != -919125270 )
        __break(0x8228u);
      v7(a1 + 56);
    }
  }
  kgsl_pwrctrl_irq(a1, 1);
  adreno_irqctrl(a1, 1);
  v8 = gen8_rb_start(a1);
  if ( v8 )
  {
    v3 = v8;
    kgsl_pwrctrl_irq(a1, 0);
    v13 = 0;
    gmu_core_regread(a1, 129000, &v13);
    if ( (v13 & 3) == 0 )
      adreno_irqctrl(a1, 0);
    if ( *(_BYTE *)(a1 + 20832) == 1 )
    {
      v9 = *(_QWORD *)(a1 + 20824);
      if ( v9 )
      {
        if ( v9 <= 0xFFFFFFFFFFFFF000LL )
          llcc_slice_deactivate();
      }
    }
    if ( *(_BYTE *)(a1 + 20848) == 1 )
    {
      v10 = *(_QWORD *)(a1 + 20840);
      if ( v10 )
      {
        if ( v10 <= 0xFFFFFFFFFFFFF000LL )
          llcc_slice_deactivate();
      }
    }
    if ( *(_BYTE *)(a1 + 20864) == 1 )
    {
      v11 = *(_QWORD *)(a1 + 20856);
      if ( v11 )
      {
        if ( v11 <= 0xFFFFFFFFFFFFF000LL )
          llcc_slice_deactivate();
      }
    }
    goto LABEL_4;
  }
  v12 = *(_QWORD *)(a1 + 11240);
  if ( v12 )
    *(_BYTE *)(v12 + 245) = 1;
  adreno_dispatcher_start(a1);
  ++*(_DWORD *)(a1 + 12968);
  gen8_gmu_oob_clear(a1, 0);
  v3 = 0;
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return v3;
}
