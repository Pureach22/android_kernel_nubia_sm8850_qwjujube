__int64 __fastcall wlan_nan_get_sap_conc_support(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 comp_private_obj; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  char is_nan_conc_control_supported; // w0

  if ( !a1 )
  {
    qdf_trace_msg(0x53u, 2u, "%s: psoc is null", a2, a3, a4, a5, a6, a7, a8, a9, "nan_get_psoc_priv_obj");
    goto LABEL_6;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0xFu);
  if ( !comp_private_obj )
  {
LABEL_6:
    qdf_trace_msg(
      0x53u,
      2u,
      "%s: psoc_nan_obj is null",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "wlan_nan_get_sap_conc_support");
    is_nan_conc_control_supported = 0;
    return is_nan_conc_control_supported & 1;
  }
  if ( (*(_WORD *)(comp_private_obj + 232) & 8) != 0 )
    is_nan_conc_control_supported = ucfg_is_nan_conc_control_supported(a1);
  else
    is_nan_conc_control_supported = 0;
  return is_nan_conc_control_supported & 1;
}
