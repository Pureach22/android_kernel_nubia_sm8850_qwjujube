__int64 __fastcall send_vdev_set_custom_aggr_size_cmd_tlv(__int64 a1, unsigned int *a2)
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
  _DWORD *v13; // x22
  __int64 v14; // x19
  int v15; // w8
  unsigned int v16; // w8
  unsigned int v17; // w8
  unsigned int v18; // w8
  unsigned int v19; // w8
  unsigned int v20; // w8
  unsigned int v21; // w8
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 result; // x0
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7

  v4 = wmi_buf_alloc_fl(a1, 0x14u, "send_vdev_set_custom_aggr_size_cmd_tlv", 0x2234u);
  if ( v4 )
  {
    v13 = *(_DWORD **)(v4 + 224);
    v14 = v4;
    *v13 = 34471952;
    v13[1] = *a2;
    v13[2] = a2[1];
    v15 = v13[4];
    v13[3] = a2[2];
    v13[4] = v15 & 0xFFFFFFFC;
    v16 = v15 & 0xFFFFFFF8 | a2[3] & 3;
    v13[4] = v16;
    v17 = v16 & 0xFFFFFFF3 | a2[3] & 4;
    v13[4] = v17;
    v18 = v17 & 0xFFFFFFE7 | a2[3] & 8;
    v13[4] = v18;
    v19 = v18 & 0xFFFFFFCF | a2[3] & 0x10;
    v13[4] = v19;
    v20 = v19 & 0xFFFFFF9F | a2[3] & 0x20;
    v13[4] = v20;
    v13[4] = a2[3] & 0x40 | v20;
    v21 = a2[3];
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: Set custom aggr: vdev id=0x%X, tx aggr size=0x%X rx_aggr_size=0x%X access category=0x%X, agg_type=0x%X tx_aggr"
      "_size_disable=0x%X, rx_aggr_size_disable=0x%X tx_ac_enable=0x%X",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "send_vdev_set_custom_aggr_size_cmd_tlv",
      *a2,
      a2[1],
      a2[2],
      v21 & 3,
      (v21 >> 2) & 1,
      (v21 >> 3) & 1,
      (v21 >> 4) & 1,
      (v21 >> 5) & 1);
    qdf_mtrace(49, 100, 0x299u, v13[1], 0);
    result = wmi_unified_cmd_send_fl(
               a1,
               v14,
               0x14u,
               0x5019u,
               "send_vdev_set_custom_aggr_size_cmd_tlv",
               0x224Du,
               v22,
               v23,
               v24,
               v25,
               v26,
               v27,
               v28,
               v29);
    if ( !(_DWORD)result )
      return result;
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Setting custom aggregation size failed",
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      "send_vdev_set_custom_aggr_size_cmd_tlv");
    wmi_buf_free();
  }
  return 16;
}
