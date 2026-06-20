__int64 __fastcall a6xx_gmu_oob_clear(__int64 result, unsigned int a2)
{
  int v2; // w8
  unsigned int v3; // w8
  bool v4; // cc
  int v5; // w8
  char v7; // w8
  const char *v8; // x8
  const char *v9; // x2

  if ( a2 != 1 || (v2 = *(_DWORD *)(result - 232) - 1, (*(_DWORD *)(result - 232) = v2) == 0) )
  {
    v3 = **(_DWORD **)(result + 14264) - 615;
    v4 = v3 > 0xF;
    v5 = (1 << v3) & 0x801B;
    if ( !v4 && v5 != 0 )
    {
      v7 = a2 + 24;
      return gmu_core_regwrite(result, 129428, (unsigned int)(1LL << v7));
    }
    if ( a2 < 6 )
    {
      v7 = 31 - 2 * a2;
      return gmu_core_regwrite(result, 129428, (unsigned int)(1LL << v7));
    }
    v8 = "unknown";
    if ( a2 == 6 )
      v8 = "oob_boot_slumber";
    if ( a2 == 7 )
      v9 = "oob_dcvs";
    else
      v9 = v8;
    return dev_err(*(_QWORD *)(result + 1544) + 16LL, "Unsupported OOB clear %s\n", v9);
  }
  return result;
}
