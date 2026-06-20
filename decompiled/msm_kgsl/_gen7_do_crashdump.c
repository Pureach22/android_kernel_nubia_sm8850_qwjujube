__int64 __fastcall gen7_do_crashdump(__int64 a1)
{
  __int64 result; // x0
  __int64 v3; // x0
  __int64 v4; // x0
  __int64 v5; // x25
  char v6; // w0
  char v7; // w20

  if ( (adreno_smmu_is_stalled(a1) & 1) != 0 || *(_BYTE *)(a1 + 11305) != 1 )
    return 0;
  result = 0;
  if ( gen7_capturescript )
  {
    if ( (unsigned __int64)gen7_capturescript <= 0xFFFFFFFFFFFFF000LL )
    {
      result = 0;
      if ( gen7_crashdump_registers )
      {
        if ( (unsigned __int64)gen7_crashdump_registers <= 0xFFFFFFFFFFFFF000LL && (gen7_crashdump_timedout & 1) == 0 )
        {
          kgsl_regmap_write(a1 + 13200, *(unsigned int *)(gen7_capturescript + 24));
          kgsl_regmap_write(a1 + 13200, *(unsigned int *)(gen7_capturescript + 28));
          v3 = kgsl_regmap_write(a1 + 13200, 1);
          v4 = ktime_get(v3);
          __dsb(0xDu);
          if ( *(_DWORD *)gen7_cd_reg_end == -1431655766 )
          {
            v5 = v4 + 500000000;
            do
            {
              v4 = ktime_get(v4);
              if ( v4 > v5 )
                break;
              if ( (*(_BYTE *)(a1 + 11304) & 1) == 0 )
                v4 = usleep_range_state(5, 50, 2);
              __dsb(0xDu);
            }
            while ( *(_DWORD *)gen7_cd_reg_end == -1431655766 );
          }
          v6 = kgsl_regmap_read(a1 + 13200);
          __dsb(0xDu);
          v7 = v6;
          kgsl_regmap_write(a1 + 13200, 0);
          result = 1;
          if ( (v7 & 2) == 0 )
          {
            _warn_printk("Crashdumper timed out\n");
            __break(0x800u);
            gen7_crashdump_timedout = 1;
            return 0;
          }
        }
      }
    }
  }
  return result;
}
