__int64 __fastcall cam_sync_probe(__int64 a1)
{
  unsigned int v2; // w19

  if ( (debug_mdl & 0x80) != 0 && !debug_priority )
    ((void (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      (unsigned __int8)debug_mdl & 0x80,
      4,
      "cam_sync_probe",
      2937,
      "Adding Sync component");
  cam_soc_util_initialize_power_domain(a1 + 16);
  v2 = component_add(a1 + 16, cam_sync_component_ops);
  if ( v2 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      128,
      1,
      "cam_sync_probe",
      2943,
      "failed to add component rc: %d",
      v2);
  return v2;
}
