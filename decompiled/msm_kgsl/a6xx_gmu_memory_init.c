__int64 __fastcall a6xx_gmu_memory_init(__int64 a1)
{
  unsigned __int64 *v2; // x20
  unsigned __int64 v3; // x8
  __int64 v4; // x19
  unsigned __int64 *v5; // x19

  if ( (unsigned int)(**(_DWORD **)(a1 + 14264) - 615) > 0xF || ((1 << (**(_BYTE **)(a1 + 14264) - 103)) & 0x801B) == 0 )
    goto LABEL_9;
  v2 = (unsigned __int64 *)(a1 - 1632);
  v3 = *(_QWORD *)(a1 - 1632);
  if ( !v3 || v3 >= 0xFFFFFFFFFFFFF001LL )
  {
    v4 = a1;
    v3 = ((__int64 (*)(void))gmu_core_reserve_kernel_block)();
    a1 = v4;
    *v2 = v3;
  }
  if ( v3 < 0xFFFFFFFFFFFFF001LL )
  {
LABEL_9:
    v5 = (unsigned __int64 *)(a1 - 1624);
    v3 = *(_QWORD *)(a1 - 1624);
    if ( !v3 || v3 >= 0xFFFFFFFFFFFFF001LL )
    {
      v3 = ((__int64 (*)(void))gmu_core_reserve_kernel_block)();
      *v5 = v3;
    }
    if ( v3 <= 0xFFFFFFFFFFFFF000LL )
      LODWORD(v3) = 0;
  }
  return (unsigned int)v3;
}
