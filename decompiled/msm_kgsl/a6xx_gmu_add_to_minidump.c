__int64 __fastcall a6xx_gmu_add_to_minidump(_QWORD *a1)
{
  __int64 result; // x0
  unsigned int v3; // w8

  result = kgsl_add_va_to_minidump(*a1, "kgsl_a6xx_device", a1 - 206, 26192);
  if ( !(_DWORD)result )
  {
    result = kgsl_add_va_to_minidump(
               *a1,
               "kgsl_gmu_log",
               *(_QWORD *)(*(a1 - 203) + 8LL),
               *(_QWORD *)(*(a1 - 203) + 40LL));
    if ( !(_DWORD)result )
    {
      result = kgsl_add_va_to_minidump(
                 *a1,
                 "kgsl_hfi_mem",
                 *(_QWORD *)(*(a1 - 201) + 8LL),
                 *(_QWORD *)(*(a1 - 201) + 40LL));
      if ( !(_DWORD)result )
      {
        v3 = *(_DWORD *)a1[1783] - 615;
        if ( v3 <= 0xF && ((1 << v3) & 0x801B) != 0 )
          return kgsl_add_va_to_minidump(
                   *a1,
                   "kgsl_gmu_dump_mem",
                   *(_QWORD *)(*(a1 - 204) + 8LL),
                   *(_QWORD *)(*(a1 - 204) + 40LL));
      }
    }
  }
  return result;
}
