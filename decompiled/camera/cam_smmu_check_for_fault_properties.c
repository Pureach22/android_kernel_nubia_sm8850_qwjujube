__int64 __fastcall cam_smmu_check_for_fault_properties(const char *a1, __int64 a2)
{
  __int64 result; // x0

  result = strcmp(a1, "non-fatal");
  if ( (_DWORD)result )
  {
    result = strcmp(a1, "stall-disable");
    if ( !(_DWORD)result )
      *(_BYTE *)(a2 + 107) = 1;
  }
  else
  {
    *(_BYTE *)(a2 + 106) = 1;
  }
  if ( (debug_mdl & 0x40) != 0 && !debug_priority )
    return ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             3,
             debug_mdl & 0x40,
             4,
             "cam_smmu_check_for_fault_properties",
             5218,
             "iommu fault property: %s found for cb: %s",
             a1,
             *(const char **)(a2 + 32));
  return result;
}
