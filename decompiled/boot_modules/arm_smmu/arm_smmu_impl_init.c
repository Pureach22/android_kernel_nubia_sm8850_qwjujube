__int64 __fastcall arm_smmu_impl_init(__int64 *a1)
{
  int v1; // w8
  __int64 v3; // x0
  __int64 v4; // x20
  __int64 result; // x0
  __int64 v6; // x19

  v1 = *((_DWORD *)a1 + 11);
  v3 = *a1;
  if ( v1 == 2 )
  {
    result = devm_krealloc(v3, a1, 336, 3264);
    if ( result )
      *(_QWORD *)(result + 48) = &cavium_impl;
    else
      return -12;
  }
  else
  {
    v4 = *(_QWORD *)(v3 + 744);
    if ( v1 == 1 )
      a1[6] = (__int64)&arm_mmu500_impl;
    if ( of_find_property(v4, "calxeda,smmu-secure-config-access", 0) )
      a1[6] = (__int64)calxeda_impl;
    if ( (unsigned int)of_device_is_compatible(v4, "nvidia,tegra234-smmu")
      || (unsigned int)of_device_is_compatible(v4, "nvidia,tegra194-smmu")
      || (unsigned int)of_device_is_compatible(v4, "nvidia,tegra186-smmu") )
    {
      return nvidia_smmu_impl_init(a1);
    }
    else if ( (unsigned int)of_device_is_compatible(*(_QWORD *)(*a1 + 744), "qcom,qsmmu-v500") )
    {
      return qsmmuv500_impl_init(a1);
    }
    else if ( (unsigned int)of_device_is_compatible(*(_QWORD *)(*a1 + 744), "qcom,smmu-v2") )
    {
      return qsmmuv2_impl_init(a1);
    }
    else
    {
      v6 = qcom_smmu_impl_init(a1);
      if ( (unsigned int)of_device_is_compatible(v4, "marvell,ap806-smmu-500") )
      {
        *(_QWORD *)(v6 + 48) = &mrvl_mmu500_impl;
        return v6;
      }
      else
      {
        return v6;
      }
    }
  }
  return result;
}
