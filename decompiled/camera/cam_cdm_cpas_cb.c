__int64 __fastcall cam_cdm_cpas_cb(__int64 a1, __int64 a2, _DWORD *a3)
{
  if ( !a3 || (debug_mdl & 1) == 0 || debug_priority )
    return 0;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    1,
    4,
    "cam_cdm_cpas_cb",
    107,
    "CPAS error callback type=%d",
    *a3);
  return 0;
}
