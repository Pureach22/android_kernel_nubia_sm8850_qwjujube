__int64 __fastcall arm_smmu_pm_suspend(__int64 a1)
{
  __int64 v1; // x19

  v1 = *(_QWORD *)(a1 + 152);
  if ( *(_DWORD *)(a1 + 500) != 2 || (*(_WORD *)(a1 + 488) & 7) != 0 )
    arm_smmu_power_off(*(_QWORD *)(a1 + 152), *(_QWORD *)(v1 + 304));
  clk_bulk_unprepare(*(unsigned int *)(v1 + 204), *(_QWORD *)(v1 + 216));
  return 0;
}
