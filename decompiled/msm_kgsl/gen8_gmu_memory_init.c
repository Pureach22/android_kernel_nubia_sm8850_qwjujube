unsigned __int64 __fastcall gen8_gmu_memory_init(__int64 a1)
{
  unsigned __int64 *v1; // x19
  unsigned __int64 result; // x0

  v1 = (unsigned __int64 *)(a1 - 1808);
  result = *(_QWORD *)(a1 - 1808);
  if ( !result || result >= 0xFFFFFFFFFFFFF001LL )
  {
    result = ((__int64 (__fastcall *)(__int64, _QWORD, __int64, __int64, _QWORD))gmu_core_reserve_kernel_block)(
               a1,
               0,
               0x10000,
               4,
               0);
    *v1 = result;
  }
  if ( result <= 0xFFFFFFFFFFFFF000LL )
    return 0;
  else
    return (unsigned int)result;
}
