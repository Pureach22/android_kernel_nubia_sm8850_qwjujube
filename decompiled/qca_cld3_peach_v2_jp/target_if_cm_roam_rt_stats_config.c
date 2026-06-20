__int64 __fastcall target_if_cm_roam_rt_stats_config(
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
  __int64 result; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  unsigned int v20; // w19
  const char *v21; // x2

  _ReadStatusReg(SP_EL0);
  v9 = *(_QWORD *)(a1 + 152);
  if ( !v9 )
  {
    v21 = "%s: PDEV is NULL";
    goto LABEL_8;
  }
  v10 = *(__int64 **)(v9 + 1232);
  if ( !v10 || !*v10 )
  {
    v21 = "%s: wmi_handle is null";
LABEL_8:
    qdf_trace_msg(0x49u, 2u, v21, a2, a3, a4, a5, a6, a7, a8, a9, "target_if_cm_roam_get_wmi_handle_from_vdev");
    result = 16;
    goto LABEL_9;
  }
  result = wmi_unified_roam_set_param_send(*v10);
  if ( (_DWORD)result )
  {
    v20 = result;
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: Failed to set WMI_ROAM_PARAM_ROAM_EVENTS_CONFIG",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "target_if_cm_roam_rt_stats_config");
    result = v20;
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
