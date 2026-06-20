__int64 __fastcall cam_cci_platform_probe(__int64 a1)
{
  unsigned int v2; // w19

  if ( (debug_mdl & 0x4000) != 0 && !debug_priority )
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 0x4000,
      4,
      "cam_cci_platform_probe",
      835,
      "Adding CCI component");
  cam_soc_util_initialize_power_domain(a1 + 16);
  *(_WORD *)(a1 + 504) |= 0x100u;
  v2 = component_add(a1 + 16, cam_cci_component_ops);
  if ( v2 )
    ((void (*)(__int64, const char *, ...))cam_print_log)(
      3,
      print_fmt_cam_context_state,
      (_BYTE *)&_ksymtab_cam_cci_dump_registers + 1,
      "cam_cci_platform_probe",
      842);
  return v2;
}
