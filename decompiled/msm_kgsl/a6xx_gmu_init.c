unsigned __int64 __fastcall a6xx_gmu_init(__int64 a1)
{
  unsigned __int64 result; // x0
  __int64 v3; // x8
  unsigned int v4; // w20
  unsigned int v5; // w21
  int *v6; // x8
  int v7; // w20
  unsigned int v8; // w9
  unsigned int v9; // w8
  unsigned __int64 v10; // x0
  unsigned __int64 v11; // x0
  const char *v12; // x0
  __int64 v13; // x8
  unsigned int v14; // w20
  unsigned int v15; // w21

  result = a6xx_gmu_parse_fw(a1);
  if ( (_DWORD)result )
    return result;
  if ( (*(_BYTE *)(a1 - 376) & 1) == 0 )
  {
    v3 = *(_QWORD *)(a1 + 8224);
    v4 = *(_DWORD *)(v3 + 24);
    v5 = *(_DWORD *)(v3 + 28);
    if ( !gmu_core_find_memdesc(a1, v4, v5) )
    {
      result = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD, __int64, _QWORD))gmu_core_reserve_kernel_block)(
                 a1,
                 v4,
                 v5,
                 1,
                 0);
      if ( result >= 0xFFFFFFFFFFFFF001LL )
        return result;
    }
    v6 = *(int **)(a1 + 14264);
    v7 = *v6;
    v8 = *v6 - 620;
    if ( v8 > 0x28 || ((1LL << v8) & 0x10040000001LL) == 0 )
    {
      v12 = *((const char **)v6 + 3);
      if ( (!v12 || strcmp(v12, "qcom,adreno-gpu-a642l"))
        && ((unsigned int)(v7 - 621) > 0x2A || ((1LL << ((unsigned __int8)v7 - 109)) & 0x60000400003LL) == 0) )
      {
        v13 = *(_QWORD *)(a1 + 8224);
        v14 = *(_DWORD *)(v13 + 72);
        v15 = *(_DWORD *)(v13 + 76);
        if ( !gmu_core_find_memdesc(a1, v14, v15) )
        {
          result = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD, __int64, _QWORD))gmu_core_reserve_kernel_block)(
                     a1,
                     v14,
                     v15,
                     3,
                     0);
          if ( result >= 0xFFFFFFFFFFFFF001LL )
            return result;
        }
      }
    }
    result = ((__int64 (__fastcall *)(__int64, _QWORD, __int64, __int64, _QWORD))gmu_core_reserve_kernel_block)(
               a1,
               0,
               4096,
               4,
               0);
    if ( result > 0xFFFFFFFFFFFFF000LL )
      return result;
    *(_BYTE *)(a1 - 376) = 1;
  }
  v9 = **(_DWORD **)(a1 + 14264) - 615;
  if ( v9 > 0xF
    || ((1 << v9) & 0x801B) == 0
    || (v10 = *(_QWORD *)(a1 - 1632)) != 0 && v10 < 0xFFFFFFFFFFFFF001LL
    || (result = ((__int64 (__fastcall *)(__int64, _QWORD, __int64, __int64, _QWORD))gmu_core_reserve_kernel_block)(
                   a1,
                   0,
                   0x4000,
                   4,
                   0),
        *(_QWORD *)(a1 - 1632) = result,
        result <= 0xFFFFFFFFFFFFF000LL) )
  {
    v11 = *(_QWORD *)(a1 - 1624);
    if ( v11 && v11 < 0xFFFFFFFFFFFFF001LL )
      return a6xx_hfi_init(a1);
    result = ((__int64 (__fastcall *)(__int64, _QWORD, __int64, __int64, _QWORD))gmu_core_reserve_kernel_block)(
               a1,
               0,
               0x10000,
               4,
               0);
    *(_QWORD *)(a1 - 1624) = result;
    if ( result < 0xFFFFFFFFFFFFF001LL )
      return a6xx_hfi_init(a1);
  }
  return result;
}
