__int64 __fastcall arm_smmu_pm_prepare(__int64 a1)
{
  __int64 result; // x0

  result = of_device_is_compatible(*(_QWORD *)(a1 + 744), "qcom,adreno-smmu");
  if ( (_DWORD)result )
  {
    if ( *(_DWORD *)(a1 + 500) == 2 && (*(_WORD *)(a1 + 488) & 7) == 0 )
    {
      return 0;
    }
    else if ( *(_DWORD *)(a1 + 480) == 1 )
    {
      return 4294967181LL;
    }
    else
    {
      return 0;
    }
  }
  return result;
}
