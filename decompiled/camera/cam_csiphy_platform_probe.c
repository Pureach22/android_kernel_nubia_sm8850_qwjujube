__int64 __fastcall cam_csiphy_platform_probe(__int64 a1)
{
  unsigned int v2; // w19

  if ( (debug_mdl & 0x8000) != 0 && !debug_priority )
    ((void (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      (unsigned __int16)debug_mdl & 0x8000,
      4,
      "cam_csiphy_platform_probe",
      707,
      "Adding CSIPHY component");
  cam_soc_util_initialize_power_domain(a1 + 16);
  v2 = component_add(a1 + 16, cam_csiphy_component_ops);
  if ( v2 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x8000,
      1,
      "cam_csiphy_platform_probe",
      713,
      "failed to add component rc: %d",
      v2);
  return v2;
}
