__int64 __fastcall cam_flash_platform_probe(__int64 a1)
{
  unsigned int v2; // w19

  if ( (debug_mdl & 0x1000) != 0 && !debug_priority )
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 0x1000,
      4,
      "cam_flash_platform_probe",
      696,
      "Adding Flash Sensor component");
  cam_soc_util_initialize_power_domain(a1 + 16);
  v2 = component_add(a1 + 16, cam_flash_component_ops);
  if ( v2 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4096,
      1,
      "cam_flash_platform_probe",
      702,
      "failed to add component rc: %d",
      v2);
  return v2;
}
