__int64 __fastcall arm_smmu_pm_resume(__int64 a1)
{
  __int64 v1; // x19
  __int64 result; // x0
  unsigned int v4; // w0
  unsigned int v5; // w8
  __int64 v6; // x1
  unsigned int v7; // w19

  v1 = *(_QWORD *)(a1 + 152);
  result = clk_bulk_prepare(*(unsigned int *)(v1 + 204), *(_QWORD *)(v1 + 216));
  if ( !(_DWORD)result )
  {
    if ( *(_DWORD *)(a1 + 500) != 2 || (*(_WORD *)(a1 + 488) & 7) != 0 )
    {
      v4 = arm_smmu_power_on(*(_QWORD *)(*(_QWORD *)(a1 + 152) + 304LL));
      if ( v4 )
      {
        v5 = *(_DWORD *)(v1 + 204);
        v6 = *(_QWORD *)(v1 + 216);
        v7 = v4;
        clk_bulk_unprepare(v5, v6);
        return v7;
      }
      arm_smmu_device_reset(v1);
    }
    return 0;
  }
  return result;
}
