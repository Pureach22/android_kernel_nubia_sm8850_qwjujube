__int64 __fastcall a6xx_gmu_gfx_rail_on(__int64 a1)
{
  unsigned int v1; // w8
  int *v3; // x20
  int v4; // w21

  v1 = *(_DWORD *)(a1 - 680) + ~*(_DWORD *)(a1 + 10052);
  if ( v1 >= 0x10 )
  {
    __break(0x5512u);
    return a6xx_gmu_power_off(a1);
  }
  else
  {
    v3 = (int *)(a1 + 12LL * v1 - 672);
    v4 = *v3;
    gmu_core_regwrite(a1, 117752, 0);
    gmu_core_regwrite(a1, 117753, (unsigned __int8)v4);
    gmu_core_regwrite(a1, 117754, BYTE1(v4));
    gmu_core_rdpm_mx_freq_update(a1, (unsigned int)v3[2]);
    return a6xx_gmu_oob_set(a1, 6u);
  }
}
