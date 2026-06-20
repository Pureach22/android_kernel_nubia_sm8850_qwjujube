__int64 __fastcall gen8_gmu_first_boot(__int64 a1)
{
  unsigned __int8 *v2; // x20
  unsigned __int64 v3; // x8
  int v4; // w3
  int v5; // w0
  int v6; // w0
  __int64 result; // x0
  unsigned int v8; // w0
  __int64 v9; // x21
  int inited; // w0
  unsigned int v11; // w8
  unsigned int v12; // w0
  unsigned int v13; // w20
  int v14; // w8
  unsigned __int64 v21; // x9
  _QWORD v22[4]; // [xsp+0h] [xbp-30h] BYREF
  int v23; // [xsp+20h] [xbp-10h]
  __int64 v24; // [xsp+28h] [xbp-8h]

  v2 = (unsigned __int8 *)(a1 + 20433);
  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  kgsl_pwrctrl_request_state(a1, 32);
  v3 = *(_QWORD *)(a1 - 808);
  if ( v3 )
  {
    if ( v3 <= 0xFFFFFFFFFFFFF000LL )
    {
      v4 = *v2;
      v23 = 0;
      memset(v22, 0, sizeof(v22));
      v5 = scnprintf(v22, 36, "{class: gpu, res: acd, val: %d}", v4);
      v6 = qmp_send(*(_QWORD *)(a1 - 808), v22, (v5 & 0xFFFFFFFC) + 4);
      if ( v6 < 0 )
        dev_err(*(_QWORD *)(a1 + 1544) + 16LL, "AOP qmp send message failed: %d\n", v6);
    }
  }
  result = ((__int64 (__fastcall *)(__int64))kgsl_pwrctrl_enable_cx_gdsc)(a1);
  if ( !(_DWORD)result )
  {
    v8 = gmu_core_enable_clks(a1, 0);
    v9 = v8;
    if ( v8 )
    {
LABEL_19:
      kgsl_pwrctrl_disable_cx_gdsc(a1);
      gmu_core_rdpm_cx_freq_update(a1, 0);
      result = (unsigned int)v9;
      goto LABEL_20;
    }
    inited = gen8_scm_gpu_init_cx_regs(a1);
    if ( inited
      || (gen8_get_gpu_slice_info(a1),
          gen8_enable_ahb_timeout_detection(a1),
          gen8_cx_timer_init(a1),
          (inited = gen8_gmu_load_fw(a1)) != 0)
      || (inited = gen8_gmu_version_info(a1)) != 0
      || (inited = gen8_gmu_itcm_shadow(a1)) != 0 )
    {
LABEL_18:
      LODWORD(v9) = inited;
      gmu_core_disable_clks(a1);
      goto LABEL_19;
    }
    gen8_gmu_register_config(a1);
    gen8_gmu_irq_enable(a1);
    v11 = *(_DWORD *)(a1 + 10052);
    if ( v11 < 0x20 )
    {
      v9 = 13192;
      icc_set_bw(
        *(_QWORD *)(a1 + 10456),
        0,
        *(unsigned int *)(*(_QWORD *)(a1 + 10392) + 4LL * *(int *)(a1 + 28LL * v11 + 9152)));
      *(_DWORD *)(v2 + 4015) = 0;
      __dmb(0xAu);
      v12 = gen8_gmu_device_start(a1);
      if ( v12
        || (v12 = gen8_gmu_hfi_start(a1)) != 0
        || (gen8_get_gpu_feature_info(a1), (v12 = gen8_hfi_start(a1)) != 0) )
      {
        v13 = v12;
        gen8_gmu_irq_disable(a1);
        if ( *(_BYTE *)(a1 + 13192) == 1 )
        {
          gen8_gmu_suspend(a1, 0);
          result = v13;
          goto LABEL_20;
        }
        inited = v13;
        goto LABEL_18;
      }
      if ( (unsigned int)gen8_hfi_send_get_value(a1, 122, 0) == 1 )
      {
        v14 = *(_DWORD *)(*(_QWORD *)(a1 + 14264) + 80LL);
        if ( v14 || (gen8_gmu_first_boot___already_done & 1) != 0 )
        {
          if ( v14 )
          {
            v2[3599] = 1;
            goto LABEL_29;
          }
        }
        else
        {
          gen8_gmu_first_boot___already_done = 1;
          _warn_printk("Number of DDR channel is not specified in gpu core");
          __break(0x800u);
        }
      }
LABEL_26:
      icc_set_bw(*(_QWORD *)(a1 + 10456), 0, 0);
      *(_BYTE *)(a1 + v9) = 0;
      kgsl_pwrctrl_set_state(a1, 32);
      result = 0;
      goto LABEL_20;
    }
    __break(0x5512u);
LABEL_29:
    _X8 = (unsigned __int64 *)(a1 + 14240);
    __asm { PRFM            #0x11, [X8] }
    do
      v21 = __ldxr(_X8);
    while ( __stxr(v21 | 0x8000, _X8) );
    goto LABEL_26;
  }
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
