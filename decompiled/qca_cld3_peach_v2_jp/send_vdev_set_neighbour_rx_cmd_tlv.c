__int64 __fastcall send_vdev_set_neighbour_rx_cmd_tlv(__int64 a1, __int64 a2, _DWORD *a3)
{
  __int64 v6; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  _DWORD *v15; // x8
  __int64 v16; // x19
  int v17; // w1
  int v18; // w9
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 result; // x0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7

  v6 = wmi_buf_alloc_fl(a1, 0x20u, "send_vdev_set_neighbour_rx_cmd_tlv", 0xB5u);
  if ( v6 )
  {
    v15 = *(_DWORD **)(v6 + 224);
    v16 = v6;
    *v15 = 31653916;
    v17 = *(unsigned __int8 *)a3;
    v15[1] = v17;
    v15[7] = a3[1];
    v15[4] = a3[2];
    v15[5] = a3[3];
    v15[2] = *(_DWORD *)a2;
    v18 = *(unsigned __int16 *)(a2 + 4);
    v15[6] = 0;
    v15[3] = v18;
    wmi_mtrace(0x5017u, v17, 0);
    result = wmi_unified_cmd_send_fl(
               a1,
               v16,
               0x20u,
               0x5017u,
               "send_vdev_set_neighbour_rx_cmd_tlv",
               0xC8u,
               v19,
               v20,
               v21,
               v22,
               v23,
               v24,
               v25,
               v26);
    if ( !(_DWORD)result )
      return result;
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to set neighbour rx param",
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      "send_vdev_set_neighbour_rx_cmd_tlv");
    wmi_buf_free();
  }
  else
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: wmi_buf_alloc failed",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "send_vdev_set_neighbour_rx_cmd_tlv");
  }
  return 16;
}
