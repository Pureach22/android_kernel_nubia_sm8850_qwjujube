__int64 __fastcall cam_cdm_intf_mgr_soc_get_dt_properties(__int64 a1, __int64 a2)
{
  int variable_u32_array; // w0
  int v5; // w6
  int v6; // w19

  variable_u32_array = of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "num-hw-cdm", a2 + 8, 1, 0);
  if ( (debug_mdl & 1) != 0 && !debug_priority )
  {
    v5 = *(_DWORD *)(a2 + 8);
    v6 = variable_u32_array;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      1,
      4,
      "cam_cdm_intf_mgr_soc_get_dt_properties",
      241,
      "Number of HW cdm supported =%d",
      v5);
    variable_u32_array = v6;
  }
  return variable_u32_array & (unsigned int)(variable_u32_array >> 31);
}
