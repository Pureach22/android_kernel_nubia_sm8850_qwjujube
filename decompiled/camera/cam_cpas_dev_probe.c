__int64 __fastcall cam_cpas_dev_probe(__int64 a1)
{
  unsigned int v2; // w19

  if ( (debug_mdl & 4) != 0 && !debug_priority )
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 4,
      4,
      "cam_cpas_dev_probe",
      2171,
      "Adding CPAS INTF component");
  cam_soc_util_initialize_power_domain(a1 + 16);
  v2 = component_add(a1 + 16, cam_cpas_dev_component_ops);
  if ( v2 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_dev_probe",
      2177,
      "failed to add component rc: %d",
      v2);
  return v2;
}
