__int64 __fastcall a6xx_deassert_gbif_halt(__int64 a1)
{
  kgsl_regmap_write(a1 + 13200, 0);
  of_device_is_compatible(*(_QWORD *)(*(_QWORD *)(a1 + 11168) + 760LL));
  return kgsl_regmap_write(a1 + 13200, 0);
}
