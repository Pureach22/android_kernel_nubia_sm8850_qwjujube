__int64 __fastcall cam_sfe_probe(__int64 a1)
{
  unsigned int v2; // w19

  if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 0x40000000,
      4,
      "cam_sfe_probe",
      242,
      "Adding SFE component");
  ++g_num_sfe_hws;
  cam_soc_util_initialize_power_domain(a1 + 16);
  v2 = component_add(a1 + 16, cam_sfe_component_ops);
  if ( v2 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x40000000,
      1,
      "cam_sfe_probe",
      249,
      "failed to add component rc: %d",
      v2);
  return v2;
}
