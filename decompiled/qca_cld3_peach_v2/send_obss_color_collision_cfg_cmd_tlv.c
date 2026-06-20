__int64 __fastcall send_obss_color_collision_cfg_cmd_tlv(__int64 a1, unsigned int *a2)
{
  __int64 v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  _DWORD *v13; // x23
  __int64 v14; // x19
  unsigned int v15; // w8
  unsigned int v16; // w9
  __int64 v17; // x4
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 result; // x0
  const char *v27; // x2
  unsigned int v28; // [xsp+0h] [xbp-10h]
  unsigned int v29; // [xsp+8h] [xbp-8h]

  v4 = wmi_buf_alloc_fl(a1, 0x20u, "send_obss_color_collision_cfg_cmd_tlv", 0x4DECu);
  if ( !v4 )
    return 2;
  v13 = *(_DWORD **)(v4 + 224);
  v14 = v4;
  *v13 = 47317020;
  v13[1] = *a2;
  v13[2] = a2[1];
  v13[4] = a2[3];
  v13[5] = a2[4];
  v15 = a2[5];
  v13[6] = v15;
  v16 = a2[6];
  v13[7] = v16;
  v17 = a2[2];
  if ( (unsigned int)v17 >= 4 )
  {
    v27 = "%s: Invalid event type: %d";
  }
  else
  {
    v13[3] = v17;
    v29 = v16;
    v28 = v15;
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: evt_type: %d vdev id: %d current_bss_color: %d detection_period_ms: %d scan_period_ms: %d free_slot_expiry_timer_ms: %d",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "send_obss_color_collision_cfg_cmd_tlv",
      v28,
      v29);
    qdf_mtrace(49, 100, 0x1503u, v13[1], 0);
    result = wmi_unified_cmd_send_fl(
               a1,
               v14,
               0x20u,
               0x2A003u,
               "send_obss_color_collision_cfg_cmd_tlv",
               0x4E19u,
               v18,
               v19,
               v20,
               v21,
               v22,
               v23,
               v24,
               v25);
    if ( !(_DWORD)result )
      return result;
    v17 = *a2;
    v27 = "%s: Sending OBSS color det cmd failed, vdev_id: %d";
  }
  qdf_trace_msg(0x31u, 2u, v27, v5, v6, v7, v8, v9, v10, v11, v12, "send_obss_color_collision_cfg_cmd_tlv", v17);
  wmi_buf_free();
  return 16;
}
