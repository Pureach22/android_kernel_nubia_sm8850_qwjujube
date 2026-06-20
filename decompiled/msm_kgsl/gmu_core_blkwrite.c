__int64 __fastcall gmu_core_blkwrite(__int64 a1, __int64 a2, __int64 a3, unsigned __int64 a4)
{
  return kgsl_regmap_bulk_write(a1 + 13200, a2, a3, a4 >> 2);
}
