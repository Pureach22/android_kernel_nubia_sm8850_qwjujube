__int64 __fastcall gen7_crashdump_init(__int64 result)
{
  __int64 v1; // x19
  unsigned __int64 global; // x8

  if ( gen7_capturescript && (unsigned __int64)gen7_capturescript < 0xFFFFFFFFFFFFF001LL
    || (v1 = result,
        global = kgsl_allocate_global(result, 12288, 0, 0x1000000, 64, "capturescript"),
        result = v1,
        gen7_capturescript = global,
        global <= 0xFFFFFFFFFFFFF000LL) )
  {
    if ( !gen7_crashdump_registers || (unsigned __int64)gen7_crashdump_registers >= 0xFFFFFFFFFFFFF001LL )
    {
      result = kgsl_allocate_global(result, 102400, 0, 0, 64, "capturescript_regs");
      gen7_crashdump_registers = result;
    }
  }
  return result;
}
