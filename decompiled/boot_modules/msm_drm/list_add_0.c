_UNKNOWN **__fastcall list_add_0(_UNKNOWN **result)
{
  void *v1; // x2

  v1 = sde_smmu_list;
  if ( sde_smmu_list == (_UNKNOWN *)result
    || result == &sde_smmu_list
    || *((_QWORD *)sde_smmu_list + 1) != (_QWORD)&sde_smmu_list )
  {
    return (_UNKNOWN **)_list_add_valid_or_report(result, &sde_smmu_list);
  }
  *((_QWORD *)sde_smmu_list + 1) = result;
  *result = v1;
  result[1] = &sde_smmu_list;
  sde_smmu_list = result;
  return result;
}
