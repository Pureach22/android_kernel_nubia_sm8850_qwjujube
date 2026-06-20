__int64 __fastcall write_voltage_table(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x1
  unsigned __int64 v4; // x24
  unsigned __int64 v5; // x21
  unsigned int *v6; // x25
  int v7; // w20
  unsigned int v8; // t1
  unsigned __int64 v9; // x8
  unsigned __int64 freq_exact; // x0
  unsigned __int64 v11; // x22

  kgsl_regmap_write(a1 + 13200, *(unsigned int *)(*(_QWORD *)(a1 + 14264) + 92LL));
  v2 = kgsl_regmap_write(a1 + 13200, *(unsigned int *)(a1 + 10068));
  if ( !*(_DWORD *)(a1 + 10068) )
    return 2;
  v4 = 0;
  LODWORD(v5) = 0;
  v6 = (unsigned int *)(a1 + 9144);
  v7 = 38926;
  while ( v4 != 32 )
  {
    freq_exact = dev_pm_opp_find_freq_exact(*(_QWORD *)(a1 + 11168) + 16LL, *v6, 1);
    if ( freq_exact <= 0xFFFFFFFFFFFFF000LL )
    {
      v11 = freq_exact;
      v5 = dev_pm_opp_get_voltage() / 0x3E8uLL;
      dev_pm_opp_put(v11);
    }
    kgsl_regmap_write(a1 + 13200, (unsigned int)v5);
    v8 = *v6;
    v6 += 7;
    v2 = kgsl_regmap_write(a1 + 13200, v8 / 0xF4240uLL);
    v9 = *(unsigned int *)(a1 + 10068);
    ++v4;
    v7 += 2;
    if ( v4 >= v9 )
      return (unsigned int)(2 * v9 + 2);
  }
  __break(0x5512u);
  return a5xx_spin_idle_debug(v2, v3);
}
