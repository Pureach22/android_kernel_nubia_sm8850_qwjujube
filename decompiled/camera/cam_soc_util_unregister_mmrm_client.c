__int64 __fastcall cam_soc_util_unregister_mmrm_client(const void *a1)
{
  unsigned int v2; // w20

  if ( (debug_mdl & 0x20000) == 0 || debug_priority )
  {
    if ( a1 )
      goto LABEL_4;
    return 0;
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    debug_mdl & 0x20000,
    4,
    "cam_soc_util_unregister_mmrm_client",
    965,
    "MMRM UnRegister handle=%pK",
    a1);
  if ( !a1 )
    return 0;
LABEL_4:
  v2 = mmrm_client_deregister(a1);
  if ( v2 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_soc_util_unregister_mmrm_client",
      972,
      "Failed in deregister handle=%pK, rc %d",
      a1,
      v2);
  return v2;
}
