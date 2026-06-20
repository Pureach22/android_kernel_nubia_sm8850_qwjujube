__int64 __fastcall gen8_hwsched_gmu_boot(__int64 a1)
{
  __int64 result; // x0
  unsigned int v3; // w20
  unsigned int fw; // w0
  unsigned int v5; // w0
  unsigned int v6; // w21

  kgsl_pwrctrl_request_state(a1, 32);
  result = ((__int64 (__fastcall *)(__int64))kgsl_pwrctrl_enable_cx_gdsc)(a1);
  if ( !(_DWORD)result )
  {
    v3 = gmu_core_enable_clks(a1, 0);
    if ( !v3 )
    {
      gen8_enable_ahb_timeout_detection(a1);
      gen8_cx_timer_init(a1);
      fw = gen8_rscc_wakeup_sequence(a1);
      if ( !fw )
      {
        fw = gen8_gmu_load_fw(a1);
        if ( !fw )
        {
          gen8_gmu_register_config(a1);
          gen8_gmu_irq_enable(a1);
          gen8_hwsched_soccp_vote(a1);
          *(_DWORD *)(a1 + 24448) = 0;
          __dmb(0xAu);
          v5 = gen8_gmu_device_start(a1);
          if ( !v5 )
          {
            v5 = gen8_hwsched_hfi_start(a1);
            if ( !v5 )
            {
              *(_BYTE *)(a1 + 13192) = 0;
              kgsl_pwrctrl_set_state(a1, 32);
              return 0;
            }
          }
          v6 = v5;
          gen8_gmu_irq_disable(a1);
          gen8_hwsched_soccp_vote(a1);
          if ( *(_BYTE *)(a1 + 13192) == 1 )
          {
            gen8_gmu_suspend(a1, 0);
            adreno_hwsched_reset_hfi_mem(a1);
            return v6;
          }
          adreno_hwsched_reset_hfi_mem(a1);
          fw = v6;
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
