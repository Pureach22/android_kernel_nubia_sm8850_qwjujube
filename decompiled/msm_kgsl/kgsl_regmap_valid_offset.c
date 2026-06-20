bool __fastcall kgsl_regmap_valid_offset(_DWORD *a1, __int64 a2)
{
  return kgsl_regmap_get_region(a1, a2) != 0;
}
