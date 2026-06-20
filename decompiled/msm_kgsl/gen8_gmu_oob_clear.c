__int64 __fastcall gen8_gmu_oob_clear(__int64 result, unsigned int a2)
{
  int v2; // w9
  const char *v3; // x8
  const char *v4; // x2

  if ( a2 == 1 )
  {
    v2 = *(_DWORD *)(result - 664) - 1;
    *(_DWORD *)(result - 664) = v2;
    if ( v2 )
      return result;
    return gmu_core_regwrite(result, 129428, (unsigned int)(1LL << (31 - 2 * (unsigned __int8)a2)));
  }
  if ( a2 < 6 )
    return gmu_core_regwrite(result, 129428, (unsigned int)(1LL << (31 - 2 * (unsigned __int8)a2)));
  v3 = "unknown";
  if ( a2 == 6 )
    v3 = "oob_boot_slumber";
  if ( a2 == 7 )
    v4 = "oob_dcvs";
  else
    v4 = v3;
  return dev_err(*(_QWORD *)(result + 1544) + 16LL, "Unsupported OOB clear %s\n", v4);
}
