__int64 __fastcall a6xx_gmu_boot(__int64 a1)
{
  __int64 result; // x0
  unsigned int v3; // w0
  unsigned int fw; // w0
  unsigned int v5; // w0
  unsigned int v6; // w22
  unsigned int v7; // w21
  unsigned int v8; // w21
  unsigned int v9; // w0
  unsigned int v10; // w22

  kgsl_pwrctrl_request_state(a1, 32);
  result = ((__int64 (__fastcall *)(__int64))kgsl_pwrctrl_enable_cx_gdsc)(a1);
  if ( (_DWORD)result )
    return result;
  v3 = gmu_core_enable_clks(a1, 0);
  if ( !v3 )
  {
    fw = a6xx_rscc_wakeup_sequence(a1);
    if ( !fw )
    {
      fw = a6xx_gmu_load_fw(a1);
      if ( !fw )
      {
        a6xx_gmu_register_config(a1);
        a6xx_gmu_irq_enable(a1);
        *(_DWORD *)(a1 + 24448) = 0;
        __dmb(0xAu);
        v5 = a6xx_gmu_device_start(a1);
        if ( !v5 )
        {
          if ( (*(_BYTE *)(a1 + 20656) & 0x20) != 0 && (v9 = a6xx_gmu_gfx_rail_on(a1)) != 0 )
          {
            v10 = v9;
            a6xx_gmu_oob_clear(a1, 6u);
            v5 = v10;
          }
          else if ( *(_DWORD *)(a1 - 448) || (v5 = a6xx_gmu_sptprac_enable(a1)) == 0 )
          {
            v5 = a6xx_gmu_hfi_start(a1);
            if ( !v5 )
            {
              v5 = ((__int64 (__fastcall *)(__int64))a6xx_hfi_start)(a1);
              if ( !v5 )
              {
                *(_BYTE *)(a1 + 13192) = 0;
                kgsl_pwrctrl_set_state(a1, 32);
                return 0;
              }
            }
          }
        }
        v6 = v5;
        a6xx_gmu_irq_disable(a1);
        if ( *(_BYTE *)(a1 + 13192) == 1 )
        {
          a6xx_gmu_suspend(a1, 0);
          return v6;
        }
        fw = v6;
      }
    }
    v7 = fw;
    gmu_core_disable_clks(a1);
    v3 = v7;
  }
  v8 = v3;
  if ( *(_QWORD *)(a1 + 9024) && (*(_BYTE *)(a1 + 20657) & 2) != 0 )
  {
    __break(0x800u);
    if ( *(_QWORD *)(a1 + 9000) )
    {
LABEL_13:
      if ( (*(_BYTE *)(a1 + 20657) & 2) != 0 )
        regulator_set_mode();
    }
  }
  else if ( *(_QWORD *)(a1 + 9000) )
  {
    goto LABEL_13;
  }
  kgsl_pwrctrl_disable_cx_gdsc(a1);
  if ( *(_QWORD *)(a1 + 9000) )
  {
    if ( (*(_BYTE *)(a1 + 20657) & 2) != 0 )
      regulator_set_mode();
  }
  gmu_core_rdpm_cx_freq_update(a1, 0);
  return v8;
}
