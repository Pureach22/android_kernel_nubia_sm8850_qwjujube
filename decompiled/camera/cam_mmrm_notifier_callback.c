__int64 __fastcall cam_mmrm_notifier_callback(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x9
  const char *v3; // x7

  if ( !a1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_mmrm_notifier_callback",
      879,
      "Invalid notifier data");
    return 4294967243LL;
  }
  if ( *(_DWORD *)a1 == 1 )
  {
    v1 = *(_QWORD *)(a1 + 24);
    v2 = *(unsigned int *)(v1 + 2796);
    if ( (_DWORD)v2 == -1 )
    {
      v3 = "No src clk";
    }
    else
    {
      if ( (unsigned int)v2 >= 0x20 )
      {
        __break(0x5512u);
        return cam_soc_util_register_mmrm_client();
      }
      v3 = *(const char **)(v1 + 8 * v2 + 872);
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x20000,
      2,
      "cam_mmrm_notifier_callback",
      891,
      "Dev %s Clk %s value change from %ld to %ld",
      *(const char **)(v1 + 24),
      v3,
      *(_QWORD *)(a1 + 8),
      *(_QWORD *)(a1 + 16));
  }
  return 0;
}
