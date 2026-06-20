__int64 __fastcall target_if_cm_roam_full_scan_6ghz_on_disc(
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
  __int64 v9; // x8
  __int64 *v10; // x8
  __int64 v11; // x8
  __int64 result; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int v21; // w19
  const char *v22; // x2

  _ReadStatusReg(SP_EL0);
  v9 = *(_QWORD *)(a1 + 216);
  if ( !v9 )
  {
    v22 = "%s: PDEV is NULL";
    goto LABEL_8;
  }
  v10 = *(__int64 **)(v9 + 1240);
  if ( !v10 || (v11 = *v10) == 0 )
  {
    v22 = "%s: wmi_handle is null";
LABEL_8:
    qdf_trace_msg(0x49u, 2u, v22, a2, a3, a4, a5, a6, a7, a8, a9, "target_if_cm_roam_get_wmi_handle_from_vdev");
    result = 16;
    goto LABEL_9;
  }
  result = wmi_unified_roam_set_param_send(v11);
  if ( (_DWORD)result )
  {
    v21 = result;
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: Failed to set WMI_ROAM_PARAM_ROAM_CONTROL_FULL_SCAN_6GHZ_PSC_ONLY_WITH_RNR",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "target_if_cm_roam_full_scan_6ghz_on_disc");
    result = v21;
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
