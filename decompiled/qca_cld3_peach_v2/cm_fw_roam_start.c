__int64 __fastcall cm_fw_roam_start(
        __int64 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 first_roam_command; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  unsigned int v19; // w21
  __int64 v20; // x22
  __int64 v21; // x23
  __int64 v22; // x4
  __int64 v23; // x24
  unsigned int v24; // w20
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  unsigned int v33; // w3
  const char *v34; // x2
  __int64 v35; // x0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  unsigned int v53; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v54; // [xsp+8h] [xbp-8h]

  v54 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  first_roam_command = cm_get_first_roam_command(*a1, a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !first_roam_command )
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: Failed to find roam req from list",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "cm_fw_roam_start");
    v19 = -1;
LABEL_13:
    v24 = 16;
    goto LABEL_14;
  }
  v19 = *(_DWORD *)first_roam_command;
  v20 = *(_QWORD *)(*a1 + 216);
  if ( !v20 )
  {
    v22 = *(unsigned __int8 *)(first_roam_command + 9);
    v34 = "%s: vdev %d cm_id 0x%x: Failed to find pdev";
LABEL_12:
    qdf_trace_msg(0x68u, 2u, v34, v11, v12, v13, v14, v15, v16, v17, v18, "cm_fw_roam_start", v22, v19);
    goto LABEL_13;
  }
  v21 = *(_QWORD *)(v20 + 80);
  v22 = *(unsigned __int8 *)(first_roam_command + 9);
  if ( !v21 )
  {
    v34 = "%s: vdev %d cm_id 0x%x: Failed to find psoc";
    goto LABEL_12;
  }
  v23 = first_roam_command;
  v24 = wlan_cm_roam_state_change(*(_QWORD *)(*a1 + 216), v22, 4u, 0x33u);
  if ( !v24 )
  {
    mlme_cm_osif_roam_start_ind();
    if ( (wlan_mlme_get_host_scan_abort_support(v21) & 1) != 0 )
      v33 = -2;
    else
      v33 = -1;
    wlan_abort_scan(v20, -1, *(unsigned __int8 *)(v23 + 9), v33, 0);
    goto LABEL_16;
  }
LABEL_14:
  v35 = *a1;
  v53 = v19;
  cm_get_first_roam_command(v35, v25, v26, v27, v28, v29, v30, v31, v32);
  mlme_cm_osif_roam_abort_ind();
  if ( (unsigned int)cm_sm_deliver_event(*a1, 0x1Fu, 4u, (__int64)&v53, v36, v37, v38, v39, v40, v41, v42, v43) )
    cm_remove_cmd(a1, &v53, v44, v45, v46, v47, v48, v49, v50, v51);
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return v24;
}
