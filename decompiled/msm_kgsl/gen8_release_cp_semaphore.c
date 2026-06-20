__int64 __fastcall gen8_release_cp_semaphore(__int64 a1)
{
  return kgsl_regmap_write(a1 + 13200, 0);
}
