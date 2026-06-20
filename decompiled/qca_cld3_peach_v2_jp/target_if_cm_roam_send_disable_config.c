__int64 __fastcall target_if_cm_roam_send_disable_config(
        __int64 a1,
        unsigned __int8 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 cmpt_obj; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  const char *v21; // x2
  const char *v22; // x3
  __int64 result; // x0
  __int64 v24; // x8
  __int64 *v25; // x8
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  unsigned int v34; // w19

  _ReadStatusReg(SP_EL0);
  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(a1, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !cmpt_obj )
  {
    v21 = "%s: Failed to get vdev mlme obj!";
    v22 = "target_if_cm_roam_send_disable_config";
LABEL_6:
    qdf_trace_msg(0x49u, 2u, v21, v13, v14, v15, v16, v17, v18, v19, v20, v22);
    goto LABEL_7;
  }
  if ( *(_BYTE *)(cmpt_obj + 163) != 2 || *(_BYTE *)(cmpt_obj + 164) )
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: This isn't a STA: %d",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "target_if_cm_roam_send_disable_config",
      *a2);
LABEL_7:
    result = 16;
    goto LABEL_8;
  }
  v24 = *(_QWORD *)(a1 + 152);
  if ( !v24 )
  {
    v21 = "%s: PDEV is NULL";
    goto LABEL_17;
  }
  v25 = *(__int64 **)(v24 + 1232);
  if ( !v25 || !*v25 )
  {
    v21 = "%s: wmi_handle is null";
LABEL_17:
    v22 = "target_if_cm_roam_get_wmi_handle_from_vdev";
    goto LABEL_6;
  }
  if ( *a2 >= 6u )
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: vdev_id: %d is invalid, reject the req: param id %d val %d",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "target_if_vdev_set_param");
    LODWORD(result) = 4;
  }
  else
  {
    result = wmi_unified_vdev_set_param_send(*v25);
    if ( !(_DWORD)result )
      goto LABEL_8;
  }
  v34 = result;
  qdf_trace_msg(
    0x49u,
    2u,
    "%s: Failed to set wmi_vdev_param_roam_11kv_ctrl",
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    "target_if_cm_roam_send_disable_config");
  result = v34;
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
