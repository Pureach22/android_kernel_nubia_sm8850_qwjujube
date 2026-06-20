__int64 __fastcall cam_vfe_probe(__int64 a1)
{
  int string_helper; // w0
  size_t v3; // x0
  size_t v4; // x0
  size_t v5; // x0
  unsigned int v6; // w19
  char *s[2]; // [xsp+0h] [xbp-10h] BYREF

  s[1] = *(char **)(_ReadStatusReg(SP_EL0) + 1808);
  s[0] = nullptr;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_vfe_probe",
      271,
      "Adding VFE component");
  string_helper = of_property_read_string_helper(*(_QWORD *)(a1 + 760), "compatible", s, 1, 0);
  if ( string_helper < 0 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_probe",
      278,
      "No compatible string present for: %s, rc: %d",
      *(const char **)a1,
      string_helper);
  v3 = strlen(s[0]);
  if ( strnstr(s[0], "lite", v3) )
  {
    ++g_num_ife_lite_hws;
  }
  else
  {
    v4 = strlen(s[0]);
    if ( strnstr(s[0], "vfe", v4) || (v5 = strlen(s[0]), strnstr(s[0], "mc_tfe", v5)) )
      ++g_num_ife_hws;
    else
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        8,
        1,
        "cam_vfe_probe",
        287,
        "Failed to increment number of IFEs/IFE-LITEs");
  }
  cam_soc_util_initialize_power_domain(a1 + 16);
  v6 = component_add(a1 + 16, cam_vfe_component_ops);
  if ( v6 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_probe",
      293,
      "failed to add component rc: %d",
      v6);
  _ReadStatusReg(SP_EL0);
  return v6;
}
