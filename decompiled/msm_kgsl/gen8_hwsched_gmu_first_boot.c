__int64 __fastcall gen8_hwsched_gmu_first_boot(__int64 a1)
{
  __int64 v2; // x21
  __int64 v3; // x20
  __int64 result; // x0
  unsigned int v5; // w20
  unsigned int inited; // w0
  __int64 v7; // x20
  __int64 v8; // x9
  unsigned __int64 v9; // x8
  unsigned __int64 v10; // x0
  unsigned int v11; // w8
  unsigned int v12; // w0
  unsigned int v13; // w21
  int v14; // w8
  unsigned __int64 v21; // x9

  v2 = a1 + 20433;
  v3 = to_gen8_gmu(a1);
  kgsl_pwrctrl_request_state(a1, 32);
  gen8_gmu_aop_send_acd_state(v3, *(_BYTE *)v2);
  result = ((__int64 (__fastcall *)(__int64))kgsl_pwrctrl_enable_cx_gdsc)(a1);
  if ( !(_DWORD)result )
  {
    v5 = gmu_core_enable_clks(a1, 0);
    if ( v5 )
    {
LABEL_26:
      kgsl_pwrctrl_disable_cx_gdsc(a1);
      gmu_core_rdpm_cx_freq_update(a1, 0);
      return v5;
    }
    inited = gen8_scm_gpu_init_cx_regs(a1);
    if ( inited )
      goto LABEL_25;
    gen8_get_gpu_slice_info(a1);
    v7 = *(_QWORD *)(a1 + 14264);
    if ( (unsigned int)adreno_populate_ctxt_record_size((_QWORD *)a1) )
    {
      v8 = 13860864;
      if ( *(_QWORD *)(v7 + 176) )
        v8 = *(_QWORD *)(v7 + 176);
      v9 = 0x4000;
    }
    else
    {
      v8 = *(_QWORD *)(a1 + 24520);
      v9 = (*(_QWORD *)(a1 + 24536) + 4095LL) & 0xFFFFFFFFFFFFF000LL;
    }
    v10 = *(_QWORD *)(a1 + 8664);
    *(_QWORD *)(a1 + 24536) = v9;
    *(_QWORD *)(a1 + 24520) = (v8 + 4095) & 0xFFFFFFFFFFFFF000LL;
    if ( v10 && v10 <= 0xFFFFFFFFFFFFF000LL )
    {
      gmu_core_set_vrb_register(v10, 10);
      gmu_core_set_vrb_register(*(_QWORD *)(a1 + 8664), 12);
      gmu_core_set_vrb_register(*(_QWORD *)(a1 + 8664), 11);
    }
    gen8_enable_ahb_timeout_detection(a1);
    gen8_cx_timer_init(a1);
    inited = gen8_gmu_load_fw(a1);
    if ( inited
      || (inited = gen8_gmu_itcm_shadow(a1)) != 0
      || (get_hw_fence_entries(a1), gen8_gmu_register_config(a1), (inited = gen8_gmu_version_info(a1)) != 0) )
    {
LABEL_25:
      v5 = inited;
      gmu_core_disable_clks(a1);
      goto LABEL_26;
    }
    gen8_gmu_irq_enable(a1);
    v11 = *(_DWORD *)(a1 + 10052);
    if ( v11 < 0x20 )
    {
      icc_set_bw(
        *(_QWORD *)(a1 + 10456),
        0,
        *(unsigned int *)(*(_QWORD *)(a1 + 10392) + 4LL * *(int *)(a1 + 28LL * v11 + 9152)));
      if ( (*(_DWORD *)(a1 + 8280) & 0xFFF0000u) > 0x60000 )
        adreno_hwsched_register_hw_fence(a1);
      v7 = 13192;
      if ( *(_DWORD *)(a1 + 8264) >= 0x50010006u )
        adreno_irq_free_0(a1);
      gen8_hwsched_soccp_vote(a1);
      *(_DWORD *)(v2 + 4015) = 0;
      __dmb(0xAu);
      v12 = gen8_gmu_device_start(a1);
      if ( v12 || (gen8_get_gpu_feature_info(a1), (v12 = gen8_hwsched_hfi_start(a1)) != 0) )
      {
        v13 = v12;
        gen8_gmu_irq_disable(a1);
        gen8_hwsched_soccp_vote(a1);
        if ( *(_BYTE *)(a1 + 13192) == 1 )
        {
          gen8_gmu_suspend(a1, 0);
          adreno_hwsched_reset_hfi_mem(a1);
          return v13;
        }
        adreno_hwsched_reset_hfi_mem(a1);
        inited = v13;
        goto LABEL_25;
      }
      if ( (unsigned int)gen8_hwsched_hfi_get_value(a1, 122, 0) == 1 )
      {
        v14 = *(_DWORD *)(*(_QWORD *)(a1 + 14264) + 80LL);
        if ( v14 || (gen8_hwsched_gmu_first_boot___already_done & 1) != 0 )
        {
          if ( v14 )
          {
            *(_BYTE *)(v2 + 3599) = 1;
            goto LABEL_36;
          }
        }
        else
        {
          gen8_hwsched_gmu_first_boot___already_done = 1;
          _warn_printk("Number of DDR channel is not specified in gpu core");
          __break(0x800u);
        }
      }
LABEL_33:
      icc_set_bw(*(_QWORD *)(a1 + 10456), 0, 0);
      *(_BYTE *)(a1 + v7) = 0;
      *(_QWORD *)(a1 + 23896) = -1;
      *(_QWORD *)(a1 + 23904) = -1;
      *(_QWORD *)(a1 + 23912) = -1;
      *(_QWORD *)(a1 + 23920) = -1;
      *(_QWORD *)(a1 + 23928) = -1;
      *(_QWORD *)(a1 + 23936) = -1;
      *(_QWORD *)(a1 + 23944) = -1;
      *(_QWORD *)(a1 + 23952) = -1;
      *(_DWORD *)(a1 + 23960) = -1;
      gen8_hwsched_hfi_get_dcvs_tuning_attrs(a1, 0);
      kgsl_pwrctrl_set_state(a1, 32);
      return 0;
    }
    __break(0x5512u);
LABEL_36:
    _X8 = (unsigned __int64 *)(a1 + 14240);
    __asm { PRFM            #0x11, [X8] }
    do
      v21 = __ldxr(_X8);
    while ( __stxr(v21 | 0x8000, _X8) );
    goto LABEL_33;
  }
  return result;
}
