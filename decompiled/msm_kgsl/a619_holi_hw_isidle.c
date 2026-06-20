bool __fastcall a619_holi_hw_isidle(__int64 a1)
{
  return (unsigned int)kgsl_regmap_read(a1 + 13200) <= 1
      && (*(_DWORD *)(a1 + 20888) & (unsigned int)kgsl_regmap_read(a1 + 13200)) == 0
      && *(_DWORD *)(a1 + 20416) == 0;
}
