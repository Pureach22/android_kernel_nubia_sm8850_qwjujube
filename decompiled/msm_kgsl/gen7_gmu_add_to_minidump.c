__int64 __fastcall gen7_gmu_add_to_minidump(_QWORD *a1)
{
  __int64 result; // x0

  result = kgsl_add_va_to_minidump(*a1, "kgsl_gen7_device", a1 - 222, 26328);
  if ( !(_DWORD)result )
  {
    result = kgsl_add_va_to_minidump(
               *a1,
               "kgsl_gmu_log",
               *(_QWORD *)(*(a1 - 220) + 8LL),
               *(_QWORD *)(*(a1 - 220) + 40LL));
    if ( !(_DWORD)result )
      return kgsl_add_va_to_minidump(
               *a1,
               "kgsl_hfi_mem",
               *(_QWORD *)(*(a1 - 216) + 8LL),
               *(_QWORD *)(*(a1 - 216) + 40LL));
  }
  return result;
}
