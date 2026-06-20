__int64 __fastcall cam_icp_v2_driver_probe(__int64 a1)
{
  unsigned int v2; // w19

  cam_soc_util_initialize_power_domain(a1 + 16);
  v2 = component_add(a1 + 16, cam_icp_v2_component_ops);
  if ( v2 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_v2_driver_probe",
      264,
      "cam-icp_v2 component add failed rc=%d",
      v2);
  return v2;
}
