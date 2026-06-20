__int64 __fastcall gmu_core_iommu_fault_handler(__int64 a1, __int64 a2, __int64 a3, char a4)
{
  const char *v4; // x10
  const char *v5; // x9
  const char *v6; // x8
  const char *v7; // x4
  const char *v8; // x3

  v4 = "transaction stalled";
  v5 = "external";
  if ( (a4 & 0x20) == 0 )
    v4 = "unknown";
  v6 = "permission";
  if ( (a4 & 0x10) == 0 )
    v5 = v4;
  if ( (a4 & 8) == 0 )
    v6 = v5;
  if ( (a4 & 4) != 0 )
    v7 = "translation";
  else
    v7 = v6;
  if ( (a4 & 1) != 0 )
    v8 = "write";
  else
    v8 = "read";
  dev_err(a2, "GMU fault addr = %lX, context=kernel (%s %s fault)\n", a3, v8, v7);
  return 0;
}
