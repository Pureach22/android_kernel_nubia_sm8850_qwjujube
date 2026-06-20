__int64 __fastcall target_if_roam_offload_register_events(
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
  _QWORD *v10; // x19
  unsigned int v11; // w0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 result; // x0
  unsigned int v21; // w0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x5
  __int64 v31; // x4
  unsigned int v32; // w0
  unsigned int v33; // w0
  unsigned int v34; // w0
  unsigned int v35; // w0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7

  if ( !a1 || (v9 = *(_QWORD *)(a1 + 2800)) == 0 || (v10 = *(_QWORD **)(v9 + 16)) == nullptr )
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: handle is NULL",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "target_if_roam_offload_register_events");
    return 16;
  }
  v11 = wmi_unified_register_event_handler(
          *(_QWORD **)(v9 + 16),
          0x4Du,
          (__int64)target_if_cm_roam_sync_event,
          2u,
          a2,
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          a9);
  if ( v11
    || (v11 = wmi_unified_register_event_handler(
                v10,
                0x4Eu,
                (__int64)target_if_cm_roam_sync_frame_event,
                2u,
                v12,
                v13,
                v14,
                v15,
                v16,
                v17,
                v18,
                v19)) != 0 )
  {
LABEL_6:
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: wmi event registration failed, ret: %d",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "target_if_roam_offload_register_events",
      v11);
    return 16;
  }
  v21 = wmi_unified_register_event_handler(
          v10,
          0xCFu,
          (__int64)target_if_cm_btm_denylist_event,
          2u,
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19);
  if ( v21 )
  {
    v30 = v21;
    v31 = 207;
LABEL_16:
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: wmi event(%u) registration failed, ret: %d",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "target_if_roam_offload_register_events",
      v31,
      v30);
    return 16;
  }
  v32 = wmi_unified_register_event_handler(
          v10,
          0xECu,
          (__int64)target_if_cm_roam_vdev_disconnect_event_handler,
          2u,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29);
  if ( v32 )
  {
    v30 = v32;
    v31 = 236;
    goto LABEL_16;
  }
  v33 = wmi_unified_register_event_handler(
          v10,
          0xE7u,
          (__int64)target_if_cm_roam_scan_chan_list_event_handler,
          2u,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29);
  if ( v33 )
  {
    v30 = v33;
    v31 = 231;
    goto LABEL_16;
  }
  v11 = wmi_unified_register_event_handler(
          v10,
          0xE2u,
          (__int64)target_if_cm_roam_stats_event,
          2u,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29);
  if ( v11 )
    goto LABEL_6;
  v34 = wmi_unified_register_event_handler(
          v10,
          0xDBu,
          (__int64)target_if_cm_roam_auth_offload_event,
          2u,
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19);
  if ( v34 )
  {
    v30 = v34;
    v31 = 219;
    goto LABEL_16;
  }
  v35 = wmi_unified_register_event_handler(
          v10,
          0xE6u,
          (__int64)target_if_pmkid_request_event_handler,
          2u,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29);
  if ( v35 )
  {
    v30 = v35;
    v31 = 226;
    goto LABEL_16;
  }
  v36 = target_if_register_roam_vendor_control_param_event(v10);
  result = wmi_unified_register_event_handler(
             v10,
             0xF6u,
             (__int64)target_if_roam_frame_event_handler,
             2u,
             v36,
             v37,
             v38,
             v39,
             v40,
             v41,
             v42,
             v43);
  if ( (_DWORD)result )
  {
    v30 = (unsigned int)result;
    v31 = 246;
    goto LABEL_16;
  }
  return result;
}
