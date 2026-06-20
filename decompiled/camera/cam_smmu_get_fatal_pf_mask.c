__int64 __fastcall cam_smmu_get_fatal_pf_mask(__int64 a1, _QWORD *a2)
{
  __int64 v2; // x6

  v2 = (unsigned int)dword_3940D0;
  *a2 = (unsigned int)dword_3940D0;
  if ( (debug_mdl & 0x40) == 0 || debug_priority )
    return 0;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    debug_mdl & 0x40,
    4,
    "cam_smmu_get_fatal_pf_mask",
    5538,
    "Get fatal page fault value: 0x%llx",
    v2);
  return 0;
}
