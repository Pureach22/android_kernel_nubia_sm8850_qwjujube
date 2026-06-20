__int64 __fastcall cam_sensor_driver_platform_probe(const char **a1)
{
  unsigned int v2; // w19

  if ( (debug_mdl & 0x20) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x20,
      4,
      "cam_sensor_driver_platform_probe",
      754,
      "Adding Sensor component for %s",
      *a1);
  cam_soc_util_initialize_power_domain((__int64)(a1 + 2));
  v2 = component_add(a1 + 2, cam_sensor_component_ops);
  if ( v2 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      32,
      1,
      "cam_sensor_driver_platform_probe",
      760,
      "failed to add component rc: %d",
      v2);
  return v2;
}
