__int64 __fastcall a6xx_rgmu_boot(__int64 a1)
{
  __int64 result; // x0
  __int64 v3; // x0
  unsigned int v4; // w8
  unsigned int v5; // w0
  unsigned int v6; // w20
  __int64 v7; // x21
  unsigned int v8; // w0
  unsigned int v9; // w0
  unsigned int v10; // w23
  int v11; // w0
  unsigned int v12; // w20
  unsigned int v13; // w22
  int v14; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v15; // [xsp+8h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  kgsl_pwrctrl_request_state(a1, 32);
  result = ((__int64 (__fastcall *)(__int64))kgsl_pwrctrl_enable_cx_gdsc)(a1);
  if ( (_DWORD)result )
    goto LABEL_22;
  v3 = clk_set_rate(*(_QWORD *)(a1 - 32), 200000000);
  if ( (_DWORD)v3 )
  {
    v13 = v3;
    dev_err(*(_QWORD *)(a1 - 88) + 16LL, "Couldn't set the RGMU clock\n");
    goto LABEL_21;
  }
  v4 = *(_DWORD *)(a1 + 10052);
  if ( v4 < 0x20 )
  {
    v5 = clk_set_rate(*(_QWORD *)(a1 - 40), *(unsigned int *)(a1 + 28LL * v4 + 9144));
    if ( v5 )
    {
      v13 = v5;
      dev_err(*(_QWORD *)(a1 - 88) + 16LL, "Couldn't set the GPU clock\n");
    }
    else
    {
      v6 = *(_DWORD *)(a1 - 48);
      v7 = *(_QWORD *)(a1 - 56);
      v8 = clk_bulk_prepare(v6, v7);
      if ( v8 )
      {
        v13 = v8;
      }
      else
      {
        v9 = clk_bulk_enable(v6, v7);
        if ( !v9 )
        {
          *(_DWORD *)(a1 + 11120) = 32;
          gmu_core_regwrite(a1, 129425, 0xFFFFFFFFLL);
          gmu_core_regwrite(a1, 146180, 0xFFFFFFFFLL);
          gmu_core_regwrite(a1, 129427, 0xFFFFFF);
          gmu_core_regwrite(a1, 146182, 4294967287LL);
          enable_irq(*(unsigned int *)(a1 - 76));
          enable_irq(*(unsigned int *)(a1 - 80));
          *(_DWORD *)(a1 + 24448) = 0;
          __dmb(0xAu);
          v14 = 0;
          gmu_core_regwrite(a1, 129484, 1);
          if ( *(_DWORD *)(a1 - 64) )
          {
            v10 = 0;
            do
            {
              gmu_core_regwrite(a1, v10 + 111616, *(unsigned int *)(*(_QWORD *)(a1 - 72) + 4LL * (int)v10));
              ++v10;
            }
            while ( v10 < *(_DWORD *)(a1 - 64) );
          }
          if ( *(_DWORD *)(a1 - 24) == 3 )
          {
            gmu_core_regwrite(a1, 129217, *(_DWORD *)(a1 + 24036) | 0xA0000u);
            gmu_core_regwrite(a1, 129216, 1);
          }
          gmu_core_regwrite(a1, 129039, 131168);
          gmu_core_regwrite(a1, 146179, 8);
          gmu_core_regwrite(a1, 129433, 16711680);
          gmu_core_regwrite(a1, 129434, 4278190080LL);
          gmu_core_regwrite(a1, 146193, 2157971616LL);
          gmu_core_regwrite(a1, 146192, 0);
          gmu_core_regwrite(a1, 146306, 0);
          gmu_core_regwrite(a1, 129080, 0);
          __dsb(0xEu);
          gmu_core_regwrite(a1, 129080, 1);
          if ( (unsigned int)gmu_core_timed_poll_check(a1, 129081, 1, 100, 1) )
          {
            gmu_core_regread(a1, 129085, &v14);
            dev_err(*(_QWORD *)(a1 - 88) + 16LL, "rgmu boot Failed. status:%08x\n", v14);
            gmu_core_fault_snapshot(a1, 0);
            v11 = -110;
          }
          else
          {
            gmu_core_regread(a1, 129477, a1 - 96);
            v11 = kgsl_pwrctrl_setup_default_votes(a1);
            if ( !v11 )
            {
              *(_BYTE *)(a1 + 13192) = 0;
              kgsl_pwrctrl_set_state(a1, 32);
              result = 0;
              goto LABEL_22;
            }
          }
          v12 = v11;
          a6xx_rgmu_power_off(a1);
          result = v12;
LABEL_22:
          _ReadStatusReg(SP_EL0);
          return result;
        }
        v13 = v9;
        clk_bulk_unprepare(v6, v7);
      }
      dev_err(*(_QWORD *)(a1 - 88) + 16LL, "Failed to enable RGMU clocks\n");
    }
LABEL_21:
    kgsl_pwrctrl_disable_cx_gdsc(a1);
    result = v13;
    goto LABEL_22;
  }
  __break(0x5512u);
  return a6xx_gpu_boot_0(v3);
}
