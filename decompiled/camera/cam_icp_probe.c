__int64 __fastcall cam_icp_probe(const char **a1)
{
  unsigned int v2; // w20

  if ( (debug_mdl & 0x100) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x100,
      4,
      "cam_icp_probe",
      468,
      "%s Adding ICP component",
      *a1);
  cam_soc_util_initialize_power_domain((__int64)(a1 + 2));
  v2 = component_add(a1 + 2, &cam_icp_component_ops);
  if ( v2 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_probe",
      474,
      "%s failed to add component rc: %d",
      *a1,
      v2);
  return v2;
}
