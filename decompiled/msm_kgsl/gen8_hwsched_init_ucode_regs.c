__int64 __fastcall gen8_hwsched_init_ucode_regs(__int64 a1)
{
  __int64 result; // x0

  kgsl_regmap_write(a1 + 13200, *(unsigned int *)(*(_QWORD *)(a1 + 14296) + 24LL));
  result = kgsl_regmap_write(a1 + 13200, *(unsigned int *)(*(_QWORD *)(a1 + 14296) + 28LL));
  if ( (*(_BYTE *)(*(_QWORD *)(a1 + 14264) + 34LL) & 4) != 0 )
  {
    kgsl_regmap_write(a1 + 13200, *(unsigned int *)(*(_QWORD *)(a1 + 14328) + 24LL));
    result = kgsl_regmap_write(a1 + 13200, *(unsigned int *)(*(_QWORD *)(a1 + 14328) + 28LL));
    if ( *(_BYTE *)(a1 + 20440) == 1 )
    {
      kgsl_regmap_write(a1 + 13200, *(unsigned int *)(*(_QWORD *)(a1 + 14328) + 24LL));
      return kgsl_regmap_write(a1 + 13200, *(unsigned int *)(*(_QWORD *)(a1 + 14328) + 28LL));
    }
  }
  return result;
}
