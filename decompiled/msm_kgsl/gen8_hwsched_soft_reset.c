__int64 __fastcall gen8_hwsched_soft_reset(__int64 a1, __int64 a2, char a3)
{
  __int64 v6; // x0
  int *v7; // x22
  __int64 result; // x0
  __int64 v9; // x26
  __int64 v10; // x8
  void (__fastcall *v11)(_QWORD); // x8
  int v12; // w22
  int v13; // w0
  __int64 v14; // x8
  int v15; // w8
  __int64 v16; // x0
  unsigned int v17; // w19
  unsigned int v24; // w8
  unsigned int v25; // w8
  int v26[3]; // [xsp+Ch] [xbp-14h] BYREF
  __int64 v27; // [xsp+18h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = to_gen8_gmu(a1);
  v7 = *(int **)(a1 + 22792);
  if ( (*(_QWORD *)(a1 + 22496) & 0x40) == 0 )
  {
    result = 4294967201LL;
    goto LABEL_29;
  }
  if ( *(_DWORD *)(a1 + 23440) != 1 )
  {
    result = 4294967274LL;
    goto LABEL_29;
  }
  if ( (*(_QWORD *)(v6 + 1040) & 2) == 0 )
  {
    result = 0;
    goto LABEL_29;
  }
  gen8_disable_gpu_irq(a1);
  kgsl_regmap_write(a1 + 13200, 1);
  v9 = jiffies + 25LL;
  while ( (kgsl_regmap_read(a1 + 13200) & 1) == 0 )
  {
    usleep_range_state(10, 100, 2);
    if ( v9 - jiffies < 0 )
    {
      if ( (kgsl_regmap_read(a1 + 13200) & 1) == 0 )
        dev_err(*(_QWORD *)a1, "%s GBIF halt timed out\n", "GX");
      break;
    }
  }
  kgsl_regmap_write(a1 + 13200, 1);
  __dsb(0xEu);
  _const_udelay(429500);
  *(_DWORD *)(a1 + 24448) = 0;
  __dmb(0xAu);
  *(_QWORD *)(a1 + 20376) = 0;
  *(_DWORD *)(a1 + 20384) = 0;
  *(_QWORD *)(a1 + 20368) = 0;
  *(_QWORD *)(a1 + 20360) = 0;
  *(_QWORD *)(a1 + 20352) = 0;
  *(_QWORD *)(a1 + 20344) = 0;
  *(_QWORD *)(a1 + 20336) = 0;
  gen8_start(a1);
  adreno_coresight_start(a1);
  adreno_perfcounter_start(a1);
  v10 = *(_QWORD *)(a1 + 88);
  if ( v10 )
  {
    v11 = *(void (__fastcall **)(_QWORD))(v10 + 40);
    if ( v11 )
    {
      if ( *((_DWORD *)v11 - 1) != -919125270 )
        __break(0x8228u);
      v11(a1 + 56);
    }
  }
  v12 = *v7;
  _X9 = (unsigned int *)(to_gen8_gmu(a1) + 44);
  __asm { PRFM            #0x11, [X9] }
  do
  {
    v24 = __ldxr(_X9);
    v25 = v24 + 1;
  }
  while ( __stlxr(v25, _X9) );
  __dmb(0xBu);
  v26[1] = v12;
  v26[2] = 0;
  v26[0] = (v25 << 20) | 0x10396;
  v13 = gen8_hfi_cmdq_write(a1, v26, 0xCu);
  if ( v13 )
    goto LABEL_28;
  v13 = gmu_core_timed_poll_check(a1, 129052, 3072, 1000, 3584);
  if ( v13 )
    goto LABEL_28;
  gen8_hwsched_init_ucode_regs(a1);
  gen8_enable_gpu_irq(a1);
  v13 = gen8_hwsched_boot_gpu(a1);
  if ( v13 )
    goto LABEL_28;
  gen8_hwsched_raise_dispatch_interrupt(a1);
  if ( (a3 & 1) != 0 )
  {
    v13 = handle_hw_fences_after_soft_reset(a1, a2);
    if ( !v13 )
    {
      v13 = send_context_unregister_hfi((_QWORD *)a1, a2, *(_DWORD *)(a2 + 396));
      if ( !v13 )
      {
        kgsl_sharedmem_writel(*(_QWORD *)(a1 + 40), 40LL * *(unsigned int *)(a2 + 4), *(unsigned int *)(a2 + 392));
        kgsl_sharedmem_writel(*(_QWORD *)(a1 + 40), 40LL * *(unsigned int *)(a2 + 4) + 8, *(unsigned int *)(a2 + 392));
        adreno_profile_process_results(a1);
        *(_BYTE *)(a2 + 288) = 0;
        goto LABEL_25;
      }
    }
LABEL_28:
    v15 = v13;
    v16 = *(_QWORD *)a1;
    v17 = v15;
    dev_err(v16, "GPU soft reset failed: %d\n", v15);
    result = v17;
    goto LABEL_29;
  }
LABEL_25:
  v14 = *(_QWORD *)(a1 + 11240);
  if ( v14 )
    *(_BYTE *)(v14 + 245) = 1;
  result = 0;
  ++*(_DWORD *)(a1 + 12968);
LABEL_29:
  _ReadStatusReg(SP_EL0);
  return result;
}
