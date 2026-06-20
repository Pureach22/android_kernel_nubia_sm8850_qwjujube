__int64 __fastcall gen7_hwsched_gmu_boot(__int64 a1)
{
  __int64 result; // x0
  unsigned int v3; // w20
  unsigned int fw; // w0
  unsigned int v5; // w0
  unsigned int v6; // w0
  unsigned int v7; // w21
  unsigned int v8; // w21

  kgsl_pwrctrl_request_state(a1, 32);
  result = ((__int64 (__fastcall *)(__int64))kgsl_pwrctrl_enable_cx_gdsc)(a1);
  if ( !(_DWORD)result )
  {
    v3 = gmu_core_enable_clks(a1, (unsigned int)(*(_DWORD *)(a1 + 8388) - 1));
    if ( !v3 )
    {
      gen7_enable_ahb_timeout_detection(a1);
      gen7_cx_timer_init(a1);
      fw = gen7_rscc_wakeup_sequence(a1);
      if ( !fw )
      {
        fw = gen7_gmu_load_fw(a1);
        if ( !fw )
        {
          gen7_gmu_register_config(a1);
          gen7_gmu_irq_enable(a1);
          *(_DWORD *)(a1 + 24448) = 0;
          __dmb(0xAu);
          v5 = gen7_gmu_device_start(a1);
          if ( !v5 )
          {
            v5 = gen7_hwsched_hfi_start(a1);
            if ( !v5 )
            {
              v6 = gmu_core_clock_set_rate(a1, 0);
              if ( !v6 )
              {
                *(_BYTE *)(a1 + 13192) = 0;
                kgsl_pwrctrl_set_state(a1, 32);
                return 0;
              }
              v7 = v6;
              gen7_hwsched_hfi_stop(a1);
              v5 = v7;
            }
          }
          v8 = v5;
          gen7_gmu_irq_disable(a1);
          if ( *(_BYTE *)(a1 + 13192) == 1 )
          {
            gen7_gmu_suspend(a1, 0);
            adreno_hwsched_reset_hfi_mem(a1);
            return v8;
          }
          adreno_hwsched_reset_hfi_mem(a1);
          fw = v8;
        }
      }
      v3 = fw;
      gmu_core_disable_clks(a1);
    }
    kgsl_pwrctrl_disable_cx_gdsc(a1);
    gmu_core_rdpm_cx_freq_update(a1, 0);
    return v3;
  }
  return result;
}
