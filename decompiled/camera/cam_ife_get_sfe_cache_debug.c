__int64 __fastcall cam_ife_get_sfe_cache_debug(__int64 a1, unsigned __int64 *a2)
{
  unsigned int v2; // w9
  unsigned __int64 v3; // x6

  v2 = dword_3A8524;
  *a2 = (unsigned __int64)(unsigned int)dword_3A8524 << 32;
  v3 = (unsigned int)dword_3A8520 | ((unsigned __int64)v2 << 32);
  *a2 = v3;
  if ( (debug_mdl & 8) == 0 || debug_priority )
    return 0;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    debug_mdl & 8,
    4,
    "cam_ife_get_sfe_cache_debug",
    18552,
    "Get SFE cace debug value: 0x%llx",
    v3);
  return 0;
}
