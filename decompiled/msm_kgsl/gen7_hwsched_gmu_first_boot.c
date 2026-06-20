__int64 __fastcall gen7_hwsched_gmu_first_boot(__int64 a1)
{
  __int64 v2; // x21
  __int64 v3; // x20
  __int64 result; // x0
  unsigned int v5; // w22
  unsigned int fw; // w0
  unsigned int v7; // w8
  __int64 v8; // x22
  unsigned int v9; // w0
  unsigned int v10; // w0
  unsigned int v11; // w22
  unsigned int v12; // w21
  int v13; // w8
  unsigned __int64 v16; // x9
  unsigned __int64 v19; // x9
  unsigned __int64 v26; // x9
  unsigned __int64 v29; // x9

  v2 = a1 + 20433;
  v3 = to_gen7_gmu(a1);
  kgsl_pwrctrl_request_state(a1, 32);
  gen7_gmu_aop_send_acd_state(v3, *(_BYTE *)v2);
  result = ((__int64 (__fastcall *)(__int64))kgsl_pwrctrl_enable_cx_gdsc)(a1);
  if ( !(_DWORD)result )
  {
    v5 = gmu_core_enable_clks(a1, (unsigned int)(*(_DWORD *)(a1 + 8388) - 1));
    if ( !v5 )
    {
      gen7_enable_ahb_timeout_detection(a1);
      gen7_cx_timer_init(a1);
      fw = gen7_gmu_load_fw(a1);
      if ( !fw )
      {
        fw = gen7_gmu_itcm_shadow(a1);
        if ( !fw )
        {
          if ( (*(_QWORD *)(v3 + 1096) & 0x20) != 0 )
            goto LABEL_8;
          fw = gen7_load_pdc_ucode(a1);
          if ( !fw )
          {
            gen7_load_rsc_ucode(a1);
            while ( 1 )
            {
              _X8 = (unsigned __int64 *)(v3 + 1096);
              __asm { PRFM            #0x11, [X8] }
              do
                v16 = __ldxr(_X8);
              while ( __stxr(v16 | 0x20, _X8) );
LABEL_8:
              fw = gen7_scm_gpu_init_cx_regs(a1);
              if ( fw )
                break;
              gen7_gmu_register_config(a1);
              fw = gen7_gmu_version_info(a1);
              if ( fw )
                break;
              if ( (*(_WORD *)(a1 + 8282) & 0xFFE) == 0 )
              {
                _X8 = (unsigned __int64 *)(a1 + 22496);
                __asm { PRFM            #0x11, [X8] }
                do
                  v26 = __ldxr(_X8);
                while ( __stxr(v26 | 4, _X8) );
              }
              gen7_gmu_irq_enable(a1);
              v7 = *(_DWORD *)(a1 + 10052);
              if ( v7 < 0x20 )
              {
                v8 = *(int *)(a1 + 28LL * v7 + 9152);
                if ( *(_DWORD *)(a1 + 8264) >= 0x50010006u )
                  adreno_irq_free(a1);
                if ( (gmu_core_capabilities_enabled(a1 + 8232, 5) & 1) != 0 )
                {
                  _X8 = (unsigned __int64 *)(a1 + 22496);
                  __asm { PRFM            #0x11, [X8] }
                  do
                    v19 = __ldxr(_X8);
                  while ( __stxr(v19 | 0x20, _X8) );
                }
                icc_set_bw(*(_QWORD *)(a1 + 10456), 0, *(unsigned int *)(*(_QWORD *)(a1 + 10392) + 4 * v8));
                *(_DWORD *)(v2 + 4015) = 0;
                __dmb(0xAu);
                v9 = gen7_gmu_device_start(a1);
                if ( !v9 )
                {
                  gen7_get_gpu_feature_info(a1);
                  v9 = gen7_hwsched_hfi_start(a1);
                  if ( !v9 )
                  {
                    v10 = gmu_core_clock_set_rate(a1, 0);
                    if ( !v10 )
                    {
                      if ( (unsigned int)gen7_hwsched_hfi_get_value(a1, 122) == 1 )
                      {
                        v13 = *(_DWORD *)(*(_QWORD *)(a1 + 14264) + 80LL);
                        if ( v13 || (gen7_hwsched_gmu_first_boot___already_done & 1) != 0 )
                        {
                          if ( v13 )
                          {
                            *(_BYTE *)(v2 + 3599) = 1;
                            _X8 = (unsigned __int64 *)(a1 + 14240);
                            __asm { PRFM            #0x11, [X8] }
                            do
                              v29 = __ldxr(_X8);
                            while ( __stxr(v29 | 0x8000, _X8) );
                          }
                        }
                        else
                        {
                          gen7_hwsched_gmu_first_boot___already_done = 1;
                          _warn_printk("Number of DDR channel is not specified in gpu core");
                          __break(0x800u);
                        }
                      }
                      icc_set_bw(*(_QWORD *)(a1 + 10456), 0, 0);
                      *(_BYTE *)(a1 + 13192) = 0;
                      kgsl_pwrctrl_set_state(a1, 32);
                      return 0;
                    }
                    v11 = v10;
                    gen7_hwsched_hfi_stop(a1);
                    v9 = v11;
                  }
                }
                v12 = v9;
                gen7_gmu_irq_disable(a1);
                if ( *(_BYTE *)(a1 + 13192) == 1 )
                {
                  gen7_gmu_suspend(a1, 0);
                  adreno_hwsched_reset_hfi_mem(a1);
                  return v12;
                }
                adreno_hwsched_reset_hfi_mem(a1);
                fw = v12;
                break;
              }
              __break(0x5512u);
            }
          }
        }
      }
      v5 = fw;
      gmu_core_disable_clks(a1);
    }
    kgsl_pwrctrl_disable_cx_gdsc(a1);
    gmu_core_rdpm_cx_freq_update(a1, 0);
    return v5;
  }
  return result;
}
