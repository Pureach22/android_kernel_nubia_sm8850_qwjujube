__int64 __fastcall gen7_gmu_first_boot(__int64 a1)
{
  unsigned __int8 *v3; // x20
  unsigned __int64 v4; // x8
  int v5; // w3
  int v6; // w0
  __int64 v7; // x8
  int v8; // w0
  __int64 result; // x0
  unsigned int v10; // w0
  __int64 v11; // x21
  int fw; // w0
  unsigned int v13; // w8
  unsigned int pdc_ucode; // w0
  unsigned int v15; // w20
  int v16; // w8
  int v17; // w8
  unsigned __int64 v19; // x8
  unsigned __int64 v26; // x9
  _QWORD v27[2]; // [xsp+0h] [xbp-40h] BYREF
  _QWORD v28[4]; // [xsp+10h] [xbp-30h] BYREF
  int v29; // [xsp+30h] [xbp-10h]
  __int64 v30; // [xsp+38h] [xbp-8h]

  v3 = (unsigned __int8 *)(a1 + 20433);
  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  kgsl_pwrctrl_request_state(a1, 32);
  v4 = *(_QWORD *)(a1 - 704);
  if ( v4 )
  {
    if ( v4 <= 0xFFFFFFFFFFFFF000LL )
    {
      v5 = *v3;
      v27[0] = 0;
      memset(v28, 0, sizeof(v28));
      _X22 = v28;
      v29 = 0;
      v6 = scnprintf(v28, 36, "{class: gpu, res: acd, val: %d}", v5);
      v7 = *(_QWORD *)(a1 - 704);
      v27[1] = v28;
      v27[0] = (v6 & 0xFFFFFFFC) + 4;
      v8 = mbox_send_message(v7, v27);
      if ( v8 < 0 )
        dev_err(*(_QWORD *)(a1 + 1544) + 16LL, "AOP mbox send message failed: %d\n", v8);
    }
  }
  result = ((__int64 (__fastcall *)(__int64))kgsl_pwrctrl_enable_cx_gdsc)(a1);
  if ( (_DWORD)result )
    goto LABEL_23;
  v10 = gmu_core_enable_clks(a1, 0);
  v11 = v10;
  if ( v10 )
  {
LABEL_22:
    kgsl_pwrctrl_disable_cx_gdsc(a1);
    gmu_core_rdpm_cx_freq_update(a1, 0);
    result = (unsigned int)v11;
    goto LABEL_23;
  }
  gen7_enable_ahb_timeout_detection(a1);
  gen7_cx_timer_init(a1);
  fw = gen7_gmu_load_fw(a1);
  if ( fw
    || (fw = gen7_gmu_version_info(a1)) != 0
    || (fw = gen7_gmu_itcm_shadow(a1)) != 0
    || (fw = gen7_scm_gpu_init_cx_regs(a1)) != 0 )
  {
LABEL_21:
    LODWORD(v11) = fw;
    gmu_core_disable_clks(a1);
    goto LABEL_22;
  }
  gen7_gmu_register_config(a1);
  gen7_gmu_irq_enable(a1);
  v13 = *(_DWORD *)(a1 + 10052);
  if ( v13 >= 0x20 )
  {
    __break(0x5512u);
LABEL_34:
    __asm { PRFM            #0x11, [X22] }
    do
      v19 = __ldxr(_X22);
    while ( __stxr(v19 | 0x20, _X22) );
    goto LABEL_16;
  }
  v11 = 13192;
  icc_set_bw(
    *(_QWORD *)(a1 + 10456),
    0,
    *(unsigned int *)(*(_QWORD *)(a1 + 10392) + 4LL * *(int *)(a1 + 28LL * v13 + 9152)));
  *(_DWORD *)(v3 + 4015) = 0;
  __dmb(0xAu);
  pdc_ucode = gen7_gmu_device_start(a1);
  if ( pdc_ucode )
  {
LABEL_18:
    v15 = pdc_ucode;
    gen7_gmu_irq_disable(a1);
    if ( *(_BYTE *)(a1 + v11) == 1 )
    {
      gen7_gmu_suspend(a1, 0);
      result = v15;
      goto LABEL_23;
    }
    fw = v15;
    goto LABEL_21;
  }
  _X22 = (unsigned __int64 *)(a1 - 680);
  if ( (*(_QWORD *)(a1 - 680) & 0x20) == 0 )
  {
    pdc_ucode = gen7_load_pdc_ucode(a1);
    if ( !pdc_ucode )
    {
      gen7_load_rsc_ucode(a1);
      goto LABEL_34;
    }
    goto LABEL_18;
  }
LABEL_16:
  pdc_ucode = gen7_gmu_hfi_start(a1);
  if ( pdc_ucode )
    goto LABEL_18;
  gen7_get_gpu_feature_info(a1);
  pdc_ucode = gen7_hfi_start(a1);
  if ( pdc_ucode )
    goto LABEL_18;
  v16 = **(_DWORD **)(a1 + 14264);
  if ( ((unsigned int)(v16 - 461056) < 2 || v16 == 461568) && (unsigned int)gen7_hfi_send_get_value(a1, 122, 0) == 1 )
  {
    v17 = *(_DWORD *)(*(_QWORD *)(a1 + 14264) + 80LL);
    if ( v17 || (gen7_gmu_first_boot___already_done & 1) != 0 )
    {
      if ( v17 )
      {
        v3[3599] = 1;
        _X8 = (unsigned __int64 *)(a1 + 14240);
        __asm { PRFM            #0x11, [X8] }
        do
          v26 = __ldxr(_X8);
        while ( __stxr(v26 | 0x8000, _X8) );
      }
    }
    else
    {
      gen7_gmu_first_boot___already_done = 1;
      _warn_printk("Number of DDR channel is not specified in gpu core");
      __break(0x800u);
    }
  }
  icc_set_bw(*(_QWORD *)(a1 + 10456), 0, 0);
  *(_BYTE *)(a1 + v11) = 0;
  kgsl_pwrctrl_set_state(a1, 32);
  result = 0;
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return result;
}
