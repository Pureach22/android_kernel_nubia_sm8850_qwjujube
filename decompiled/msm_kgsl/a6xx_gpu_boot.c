__int64 __fastcall a6xx_gpu_boot(__int64 a1)
{
  unsigned int v2; // w20
  __int64 v4; // x8
  void (__fastcall *v5)(_QWORD); // x8
  unsigned int v6; // w0
  unsigned __int64 v7; // x0
  unsigned __int64 v8; // x0
  unsigned __int64 v9; // x0
  __int64 v10; // x8
  int v11; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v12; // [xsp+8h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  adreno_set_active_ctxs_null(a1);
  v2 = kgsl_mmu_start(a1);
  if ( v2 )
  {
LABEL_5:
    a6xx_gmu_power_off(a1);
    goto LABEL_6;
  }
  v2 = a6xx_gmu_oob_set(a1, 0);
  if ( v2 || (*(_BYTE *)(a1 + 20656) & 0x20) == 0 && (v11 = 10, (v2 = a6xx_hfi_send_generic_req(a1, &v11, 4)) != 0) )
  {
LABEL_3:
    a6xx_gmu_oob_clear(a1, 0);
    if ( (*(_BYTE *)(a1 + 20656) & 0x20) != 0 )
      gmu_core_dev_oob_clear(a1, 6);
    goto LABEL_5;
  }
  *(_QWORD *)(a1 + 20376) = 0;
  *(_QWORD *)(a1 + 20368) = 0;
  *(_QWORD *)(a1 + 20360) = 0;
  *(_QWORD *)(a1 + 20352) = 0;
  *(_QWORD *)(a1 + 20344) = 0;
  *(_QWORD *)(a1 + 20336) = 0;
  *(_DWORD *)(a1 + 20384) = 0;
  adreno_perfcounter_restore(a1);
  a6xx_start(a1);
  adreno_coresight_start(a1);
  adreno_perfcounter_start(a1);
  v4 = *(_QWORD *)(a1 + 88);
  if ( v4 )
  {
    v5 = *(void (__fastcall **)(_QWORD))(v4 + 40);
    if ( v5 )
    {
      if ( *((_DWORD *)v5 - 1) != -919125270 )
        __break(0x8228u);
      v5(a1 + 56);
    }
  }
  kgsl_pwrctrl_irq(a1, 1);
  adreno_irqctrl(a1, 1);
  v6 = a6xx_rb_start(a1);
  if ( v6 )
  {
    v2 = v6;
    kgsl_pwrctrl_irq(a1, 0);
    v11 = 0;
    gmu_core_regread(a1, 129232, &v11);
    if ( (v11 & 0xC0) == 0 )
      adreno_irqctrl(a1, 0);
    if ( *(_BYTE *)(a1 + 20832) == 1 )
    {
      v7 = *(_QWORD *)(a1 + 20824);
      if ( v7 )
      {
        if ( v7 <= 0xFFFFFFFFFFFFF000LL )
          llcc_slice_deactivate();
      }
    }
    if ( *(_BYTE *)(a1 + 20848) == 1 )
    {
      v8 = *(_QWORD *)(a1 + 20840);
      if ( v8 )
      {
        if ( v8 <= 0xFFFFFFFFFFFFF000LL )
          llcc_slice_deactivate();
      }
    }
    if ( *(_BYTE *)(a1 + 20864) == 1 )
    {
      v9 = *(_QWORD *)(a1 + 20856);
      if ( v9 )
      {
        if ( v9 <= 0xFFFFFFFFFFFFF000LL )
          llcc_slice_deactivate();
      }
    }
    goto LABEL_3;
  }
  v10 = *(_QWORD *)(a1 + 11240);
  if ( v10 )
    *(_BYTE *)(v10 + 245) = 1;
  adreno_dispatcher_start(a1);
  ++*(_DWORD *)(a1 + 12968);
  a6xx_gmu_oob_clear(a1, 0);
  v2 = 0;
  if ( (*(_BYTE *)(a1 + 20656) & 0x20) != 0 )
  {
    gmu_core_dev_oob_clear(a1, 6);
    v2 = 0;
  }
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return v2;
}
