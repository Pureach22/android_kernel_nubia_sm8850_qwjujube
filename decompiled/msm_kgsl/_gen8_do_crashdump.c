__int64 __fastcall gen8_do_crashdump(__int64 a1)
{
  __int64 v2; // x8
  __int64 (__fastcall *v3)(_QWORD); // x8
  __int64 result; // x0
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x25
  char v8; // w0
  char v9; // w20

  if ( (adreno_smmu_is_stalled(a1) & 1) != 0 )
    return 0;
  v2 = *(_QWORD *)(a1 + 88);
  if ( v2 )
  {
    v3 = *(__int64 (__fastcall **)(_QWORD))(v2 + 16);
    if ( v3 )
    {
      if ( *((_DWORD *)v3 - 1) != -55574103 )
        __break(0x8228u);
      if ( (v3(a1 + 56) & 1) != 0 )
        return 0;
    }
  }
  if ( *(_BYTE *)(a1 + 11305) != 1 )
    return 0;
  result = 0;
  if ( gen8_capturescript )
  {
    if ( (unsigned __int64)gen8_capturescript <= 0xFFFFFFFFFFFFF000LL )
    {
      result = 0;
      if ( gen8_crashdump_registers )
      {
        if ( (unsigned __int64)gen8_crashdump_registers <= 0xFFFFFFFFFFFFF000LL && (gen8_crashdump_timedout & 1) == 0 )
        {
          kgsl_regmap_write(a1 + 13200, *(unsigned int *)(gen8_capturescript + 24));
          kgsl_regmap_write(a1 + 13200, *(unsigned int *)(gen8_capturescript + 28));
          v5 = kgsl_regmap_write(a1 + 13200, 1);
          v6 = ktime_get(v5);
          __dsb(0xDu);
          if ( *(_DWORD *)gen8_cd_reg_end == -1431655766 )
          {
            v7 = v6 + 500000000;
            do
            {
              v6 = ktime_get(v6);
              if ( v6 > v7 )
                break;
              if ( (*(_BYTE *)(a1 + 11304) & 1) == 0 )
                v6 = usleep_range_state(5, 50, 2);
              __dsb(0xDu);
            }
            while ( *(_DWORD *)gen8_cd_reg_end == -1431655766 );
          }
          v8 = kgsl_regmap_read(a1 + 13200);
          __dsb(0xDu);
          v9 = v8;
          kgsl_regmap_write(a1 + 13200, 0);
          result = 1;
          if ( (v9 & 2) == 0 )
          {
            _warn_printk("Crashdumper timed out\n");
            __break(0x800u);
            gen8_crashdump_timedout = 1;
            return 0;
          }
        }
      }
    }
  }
  return result;
}
