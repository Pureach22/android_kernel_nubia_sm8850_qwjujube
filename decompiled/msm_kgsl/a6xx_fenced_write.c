__int64 __fastcall a6xx_fenced_write(_QWORD *a1, int a2, unsigned int a3, int a4)
{
  __int64 alwayson; // x23
  int v9; // w24
  unsigned int v10; // w26
  __int64 v11; // x0

  kgsl_regmap_write(a1 + 1650, a3);
  if ( (gmu_core_isenabled(a1) & 1) != 0 )
  {
    alwayson = a6xx_read_alwayson(a1);
    v9 = 0;
    v10 = 0;
    while ( 1 )
    {
      __dsb(0xFu);
      if ( ((unsigned int)kgsl_regmap_read(a1 + 1650) & a4) == 0 )
        break;
      _const_udelay(42950);
      kgsl_regmap_write(a1 + 1650, a3);
      ++v10;
      v9 += 10;
      if ( v10 == 200 )
      {
        v11 = a6xx_read_alwayson(a1);
        dev_err(
          *a1,
          "Timed out waiting %d usecs to write fenced register 0x%x, timestamps: %llx %llx\n",
          2000,
          a2,
          alwayson,
          v11);
        return 4294967186LL;
      }
    }
    if ( v10 >= 0x64 )
      dev_err(*a1, "Waited %d usecs to write fenced register 0x%x\n", v9, a2);
  }
  return 0;
}
