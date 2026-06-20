__int64 __fastcall cam_smmu_set_fatal_pf_mask(__int64 a1, __int64 a2)
{
  dword_3940D0 = a2;
  if ( (debug_mdl & 0x40) == 0 || debug_priority )
    return 0;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    debug_mdl & 0x40,
    4,
    "cam_smmu_set_fatal_pf_mask",
    5530,
    "Set fatal page fault value: 0x%llx",
    a2);
  return 0;
}
