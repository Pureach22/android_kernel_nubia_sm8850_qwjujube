__int64 __fastcall gen8_gmu_add_to_minidump(_QWORD *a1)
{
  __int64 v2; // x19
  __int64 result; // x0
  int v4; // w9
  int v5; // w10

  v2 = a1[3069];
  result = kgsl_add_va_to_minidump(*a1, "kgsl_gen8_device", a1 - 228, 26440);
  if ( !(_DWORD)result )
  {
    result = kgsl_add_va_to_minidump(
               *a1,
               "kgsl_gmu_log",
               *(_QWORD *)(*(a1 - 226) + 8LL),
               *(_QWORD *)(*(a1 - 226) + 40LL));
    if ( !(_DWORD)result )
    {
      result = kgsl_add_va_to_minidump(
                 *a1,
                 "kgsl_hfi_mem",
                 *(_QWORD *)(*(a1 - 222) + 8LL),
                 *(_QWORD *)(*(a1 - 222) + 40LL));
      if ( !(_DWORD)result )
      {
        if ( v2 )
        {
          v4 = 0;
          do
            v5 = v4;
          while ( *(_DWORD *)(v2 + 20LL * v4++) );
          return kgsl_add_va_to_minidump(*a1, "kgsl_nc_overrides", v2, 20LL * v5);
        }
        else
        {
          return 0;
        }
      }
    }
  }
  return result;
}
