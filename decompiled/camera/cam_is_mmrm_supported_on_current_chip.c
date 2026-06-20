__int64 cam_is_mmrm_supported_on_current_chip()
{
  char v0; // w0
  const char *v2; // x6
  char v3; // w19

  v0 = mmrm_client_check_scaling_supported(0, 1);
  if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
  {
    if ( (v0 & 1) != 0 )
      v2 = "Y";
    else
      v2 = "N";
    v3 = v0;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x20000,
      4,
      "cam_is_mmrm_supported_on_current_chip",
      870,
      "is mmrm supported: %s",
      v2);
    v0 = v3;
  }
  return v0 & 1;
}
