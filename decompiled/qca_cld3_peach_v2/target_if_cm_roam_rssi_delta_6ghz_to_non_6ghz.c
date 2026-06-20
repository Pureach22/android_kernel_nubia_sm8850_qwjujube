__int64 __fastcall target_if_cm_roam_rssi_delta_6ghz_to_non_6ghz(
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
  const char *v13; // x2
  const char *v14; // x3

  _ReadStatusReg(SP_EL0);
  v9 = *(_QWORD *)(a1 + 216);
  if ( !v9 )
  {
    v13 = "%s: PDEV is NULL";
    goto LABEL_8;
  }
  v10 = *(__int64 **)(v9 + 1240);
  if ( !v10 || (v11 = *v10) == 0 )
  {
    v13 = "%s: wmi_handle is null";
LABEL_8:
    v14 = "target_if_cm_roam_get_wmi_handle_from_vdev";
    goto LABEL_9;
  }
  result = wmi_unified_roam_set_param_send(v11);
  if ( (_DWORD)result )
  {
    v13 = "%s: Failed to set WMI_ROAM_PARAM_ROAM_RSSI_PENALTY_FOR_NON_6GHZ_CAND_AP";
    v14 = "target_if_cm_roam_rssi_delta_6ghz_to_non_6ghz";
LABEL_9:
    result = qdf_trace_msg(0x49u, 2u, v13, a2, a3, a4, a5, a6, a7, a8, a9, v14);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
