unsigned __int64 __fastcall gen8_crashdump_init(unsigned __int64 result)
{
  _QWORD *v1; // x19
  unsigned int v2; // w9
  _BOOL4 v4; // w20
  int v5; // w2
  __int64 v6; // x1

  v1 = (_QWORD *)result;
  v2 = **(_DWORD **)(result + 14264);
  v4 = v2 != 526592 && v2 >> 1 != 262400;
  if ( !gen8_capturescript || (unsigned __int64)gen8_capturescript >= 0xFFFFFFFFFFFFF001LL )
  {
    result = kgsl_allocate_global(result, 204800, 0, 0x1000000, 64, "capturescript");
    gen8_capturescript = result;
    if ( result >= 0xFFFFFFFFFFFFF001LL )
    {
      v5 = result;
      return dev_err(*v1, "Failed to init crashdumper err = %d\n", v5);
    }
  }
  if ( !gen8_crashdump_registers || (unsigned __int64)gen8_crashdump_registers >= 0xFFFFFFFFFFFFF001LL )
  {
    v6 = v4 ? 819200LL : 1638400LL;
    result = kgsl_allocate_global(v1, v6, 0, 0, 64, "capturescript_regs");
    v5 = result;
    gen8_crashdump_registers = result;
    if ( result >= 0xFFFFFFFFFFFFF001LL && (_DWORD)result != 0 )
      return dev_err(*v1, "Failed to init crashdumper err = %d\n", v5);
  }
  return result;
}
