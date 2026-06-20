__int64 __fastcall a6xx_rgmu_power_off(__int64 a1)
{
  int v2; // w8
  unsigned __int64 alwayson; // x20
  __int64 v4; // x24
  unsigned __int64 v5; // x21
  __int64 result; // x0
  unsigned __int64 v7; // x22
  __int64 v8; // [xsp+0h] [xbp-30h] BYREF
  __int64 v9; // [xsp+8h] [xbp-28h] BYREF
  __int64 v10; // [xsp+10h] [xbp-20h] BYREF
  __int64 v11; // [xsp+18h] [xbp-18h] BYREF
  _QWORD v12[2]; // [xsp+20h] [xbp-10h] BYREF

  v12[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  kgsl_pwrctrl_axi(a1, 0);
  if ( *(_BYTE *)(a1 + 13192) == 1 )
  {
    disable_irq(*(unsigned int *)(a1 - 80));
    disable_irq(*(unsigned int *)(a1 - 76));
    gmu_core_regwrite(a1, 129427, 0xFFFFFFFFLL);
LABEL_3:
    gmu_core_regwrite(a1, 146182, 0xFFFFFFFFLL);
    gmu_core_regwrite(a1, 129425, 0xFFFFFFFFLL);
    gmu_core_regwrite(a1, 146180, 0xFFFFFFFFLL);
    a6xx_rgmu_disable_clks(a1);
    kgsl_pwrctrl_disable_cx_gdsc(a1);
  }
  else
  {
    v2 = *(_DWORD *)(a1 - 24);
    v11 = 0;
    v12[0] = 0;
    v9 = 0;
    v10 = 0;
    v8 = 0;
    if ( v2 == 3 )
    {
      alwayson = a6xx_read_alwayson(a1);
      v4 = jiffies + 25LL;
      while ( 1 )
      {
        gmu_core_regread(a1, 129232, &v8);
        if ( (v8 & 0x40) != 0 )
          break;
        usleep_range_state(10, 100, 2);
        if ( v4 - jiffies < 0 )
        {
          v5 = a6xx_read_alwayson(a1);
          gmu_core_regread(a1, 129232, &v8);
          if ( (v8 & 0x40) != 0 )
            break;
          v7 = a6xx_read_alwayson(a1);
          gmu_core_regread(a1, 129085, (char *)&v8 + 4);
          gmu_core_regread(a1, 129084, &v9);
          gmu_core_regread(a1, 146188, (char *)&v9 + 4);
          LODWORD(v10) = kgsl_regmap_read(a1 + 13200);
          gmu_core_regread(a1, 146197, (char *)&v10 + 4);
          gmu_core_regread(a1, 129219, &v11);
          HIDWORD(v11) = kgsl_regmap_read(a1 + 13200);
          LODWORD(v12[0]) = kgsl_regmap_read(a1 + 13200);
          gmu_core_regread(a1, 146198, (char *)v12 + 4);
          dev_err(*(_QWORD *)(a1 - 88) + 16LL, "----------------------[ RGMU error ]----------------------\n");
          dev_err(*(_QWORD *)(a1 - 88) + 16LL, "Timeout waiting for lowest idle level\n");
          dev_err(*(_QWORD *)(a1 - 88) + 16LL, "Timestamps: %llx %llx %llx\n", alwayson, v5, v7);
          dev_err(
            *(_QWORD *)(a1 - 88) + 16LL,
            "SPTPRAC_PWR_CLK_STATUS=%x PCC_DEBUG=%x PCC_STATUS=%x\n",
            v8,
            HIDWORD(v8),
            v9);
          dev_err(*(_QWORD *)(a1 - 88) + 16LL, "CX_BUSY_STATUS=%x CP_STATUS_1=%x\n", HIDWORD(v9), v10);
          dev_err(*(_QWORD *)(a1 - 88) + 16LL, "RBBM_INT_UNMASKED_STATUS=%x PWR_COL_KEEPALIVE=%x\n", HIDWORD(v10), v11);
          dev_err(
            *(_QWORD *)(a1 - 88) + 16LL,
            "CP2GMU_STATUS=%x CONTEXT_SWITCH_CNTL=%x AO_SPARE_CNTL=%x\n",
            HIDWORD(v11),
            LODWORD(v12[0]),
            HIDWORD(v12[0]));
          __break(0x800u);
          gmu_core_fault_snapshot(a1, 0);
          disable_irq(*(unsigned int *)(a1 - 80));
          disable_irq(*(unsigned int *)(a1 - 76));
          gmu_core_regwrite(a1, 129427, 0xFFFFFFFFLL);
          goto LABEL_3;
        }
      }
    }
    gmu_core_regwrite(a1, 129088, 0);
    gmu_core_regwrite(a1, 146306, 1);
    if ( (unsigned int)gmu_core_timed_poll_check(a1, 146305, 2, 10, 2)
      && (unsigned int)__ratelimit(&a6xx_rgmu_bcl_config__rs, "a6xx_rgmu_bcl_config") )
    {
      dev_err(*(_QWORD *)(a1 - 88) + 16LL, "Timed out waiting for HW CRC disable acknowledgment\n");
    }
    gmu_core_regrmw(a1, 146304, 128, 0);
    kgsl_regmap_write(a1 + 13200, 2);
    adreno_wait_for_halt_ack_1(a1, 2);
    kgsl_regmap_write(a1 + 13200, 0);
    disable_irq(*(unsigned int *)(a1 - 80));
    disable_irq(*(unsigned int *)(a1 - 76));
    gmu_core_regwrite(a1, 129427, 0xFFFFFFFFLL);
    gmu_core_regwrite(a1, 146182, 0xFFFFFFFFLL);
    gmu_core_regwrite(a1, 129425, 0xFFFFFFFFLL);
    gmu_core_regwrite(a1, 146180, 0xFFFFFFFFLL);
    a6xx_rgmu_disable_clks(a1);
    kgsl_pwrctrl_disable_cx_gdsc(a1);
    kgsl_pwrctrl_clear_l3_vote(a1);
  }
  result = kgsl_pwrctrl_set_state(a1, 0);
  _ReadStatusReg(SP_EL0);
  return result;
}
