unsigned __int64 __fastcall kgsl_iommu_disable_clk(__int64 a1)
{
  unsigned int v2; // w20
  __int64 v3; // x21
  unsigned __int64 result; // x0
  __int64 v5; // x8
  unsigned int v12; // w10

  _X8 = (unsigned int *)(a1 + 920);
  __asm { PRFM            #0x11, [X8] }
  do
    v12 = __ldxr(_X8);
  while ( __stxr(v12 - 1, _X8) );
  if ( (*(_DWORD *)(a1 + 920) & 0x80000000) != 0 )
    __break(0x800u);
  v2 = *(_DWORD *)(a1 + 936);
  v3 = *(_QWORD *)(a1 + 928);
  clk_bulk_disable(v2, v3);
  clk_bulk_unprepare(v2, v3);
  result = *(_QWORD *)(a1 + 976);
  if ( result && result <= 0xFFFFFFFFFFFFF000LL )
    result = regulator_disable(result);
  v5 = *(_QWORD *)(a1 + 952);
  if ( (*(_WORD *)(v5 + 504) & 7) == 0 )
    return _pm_runtime_idle(v5 + 16, 4);
  return result;
}
