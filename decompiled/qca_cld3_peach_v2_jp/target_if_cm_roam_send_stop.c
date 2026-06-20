__int64 __fastcall target_if_cm_roam_send_stop(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  __int64 *v11; // x9
  __int64 v12; // x19
  unsigned int v15; // w0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned int v24; // w19
  const char *v26; // x2
  unsigned int v27; // w0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  const char *v36; // x2
  unsigned int v37; // w19
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  __int64 v46; // x8
  int v47; // w8

  v10 = *(_QWORD *)(a1 + 152);
  if ( !v10 )
  {
    v26 = "%s: PDEV is NULL";
    goto LABEL_9;
  }
  v11 = *(__int64 **)(v10 + 1232);
  if ( !v11 || (v12 = *v11) == 0 )
  {
    v26 = "%s: wmi_handle is null";
LABEL_9:
    qdf_trace_msg(0x49u, 2u, v26, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_cm_roam_get_wmi_handle_from_vdev");
    return 16;
  }
  if ( !*(_QWORD *)(v10 + 80) )
  {
    qdf_trace_msg(0x49u, 2u, "%s: psoc handle is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "target_if_cm_roam_send_stop");
    return 4;
  }
  v15 = target_if_cm_roam_offload_11k_params(*v11, a2 + 1960);
  if ( v15 )
  {
    v24 = v15;
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: 11k offload disable not sent, status %d",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "target_if_cm_roam_send_stop",
      v15);
    return v24;
  }
  v27 = wmi_unified_send_btm_config(v12, a2 + 2028);
  if ( v27 )
  {
    v36 = "%s: Sending BTM config to fw failed";
LABEL_14:
    v37 = v27;
    qdf_trace_msg(0x49u, 2u, v36, v28, v29, v30, v31, v32, v33, v34, v35, "target_if_cm_roam_send_stop");
    return v37;
  }
  if ( (unsigned int)wmi_unified_roam_scan_offload_mode_cmd(v12, a2 + 4) )
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: vdev:%d Send RSO mode cmd failed",
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      "target_if_cm_roam_send_stop",
      *(unsigned int *)(a2 + 4));
  }
  else
  {
    target_if_cm_roam_scan_offload_rssi_thresh(v12, (char *)(a2 + 3336), v38, v39, v40, v41, v42, v43, v44, v45);
    v46 = a2;
    if ( !*(_BYTE *)(a2 + 1) )
    {
      v27 = target_if_cm_roam_scan_filter(v12, 2, a2 + 2064);
      v46 = a2;
      if ( v27 )
      {
        v36 = "%s: clear for roam scan filter failed";
        goto LABEL_14;
      }
    }
    target_if_cm_roam_disconnect_params(v12, 2, v46 + 3072);
    target_if_cm_roam_idle_params(v12, 2, a2 + 3084);
    if ( !*(_DWORD *)(a2 + 12) )
    {
      v47 = *(unsigned __int8 *)(a1 + 104);
      *(_DWORD *)(a2 + 3116) = 0;
      *(_DWORD *)(a2 + 3112) = v47;
      *(_DWORD *)(a2 + 3124) = 0;
      *(_DWORD *)(a2 + 3176) = -1;
      *(_DWORD *)(a2 + 3184) = -1;
      *(_DWORD *)(a2 + 3192) = -1;
      *(_DWORD *)(a2 + 3200) = -1;
      *(_DWORD *)(a2 + 3208) = -1;
      *(_DWORD *)(a2 + 3216) = -1;
      *(_DWORD *)(a2 + 3224) = -1;
      *(_DWORD *)(a2 + 3232) = -1;
      *(_DWORD *)(a2 + 3240) = -1;
      *(_DWORD *)(a2 + 3248) = -1;
      *(_DWORD *)(a2 + 3256) = -1;
      *(_DWORD *)(a2 + 3264) = -1;
      *(_DWORD *)(a2 + 3272) = -1;
      *(_DWORD *)(a2 + 3280) = -1;
      *(_DWORD *)(a2 + 3288) = -1;
      *(_DWORD *)(a2 + 3296) = -1;
      *(_DWORD *)(a2 + 3304) = -1;
      *(_DWORD *)(a2 + 3312) = -1;
      *(_DWORD *)(a2 + 3320) = -1;
      *(_DWORD *)(a2 + 3328) = -1;
      target_if_cm_roam_triggers(a1, a2 + 3112);
    }
  }
  return 0;
}
