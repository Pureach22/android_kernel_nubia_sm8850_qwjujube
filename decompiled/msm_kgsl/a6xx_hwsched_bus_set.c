__int64 __fastcall a6xx_hwsched_bus_set(__int64 a1, unsigned int a2, int a3)
{
  __int64 result; // x0

  kgsl_icc_set_tag(a1 + 8832);
  if ( *(_DWORD *)(a1 + 10404) != a2 )
  {
    result = a6xx_hwsched_dcvs_set(a1, 255, a2);
    if ( (_DWORD)result )
      return result;
    gmu_core_scale_gmu_frequency(a1, a2);
    *(_DWORD *)(a1 + 10404) = a2;
  }
  if ( *(_DWORD *)(a1 + 10464) != a3 )
  {
    icc_set_bw(*(_QWORD *)(a1 + 10456), (unsigned int)(1000 * a3), 0);
    *(_DWORD *)(a1 + 10464) = a3;
  }
  return 0;
}
