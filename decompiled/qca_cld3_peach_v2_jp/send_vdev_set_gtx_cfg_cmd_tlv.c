__int64 __fastcall send_vdev_set_gtx_cfg_cmd_tlv(__int64 a1, unsigned int a2, _DWORD *a3)
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
  _DWORD *v15; // x23
  __int64 v16; // x19
  int v17; // w8
  int v18; // w9
  int v19; // w10
  int v20; // w11
  int v21; // w12
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
  unsigned int v39; // w20
  int v40; // [xsp+0h] [xbp-30h]
  int v41; // [xsp+8h] [xbp-28h]
  int v42; // [xsp+10h] [xbp-20h]
  int v43; // [xsp+18h] [xbp-18h]
  int v44; // [xsp+20h] [xbp-10h]

  v6 = wmi_buf_alloc_fl(a1, 0x28u, "send_vdev_set_gtx_cfg_cmd_tlv", 0xAAu);
  if ( !v6 )
    return 2;
  v15 = *(_DWORD **)(v6 + 224);
  v16 = v6;
  *v15 = 14352420;
  v15[1] = a2;
  v15[2] = *a3;
  v15[3] = a3[1];
  v15[4] = a3[2];
  v17 = a3[3];
  v15[5] = v17;
  v18 = a3[4];
  v15[6] = v18;
  v19 = a3[5];
  v15[7] = v19;
  v20 = a3[6];
  v15[8] = v20;
  v21 = a3[7];
  v15[9] = v21;
  v44 = v21;
  v43 = v20;
  v42 = v19;
  v41 = v18;
  v40 = v17;
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: Setting vdev%d GTX values:htmcs 0x%x, vhtmcs 0x%x, usermask 0x%x, \t\t gtxPERThreshold %d, gtxPERMargin %d, gtxT"
    "PCstep %d, gtxTPCMin %d, \t\t gtxBWMask 0x%x.",
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    "send_vdev_set_gtx_cfg_cmd_tlv",
    a2,
    v40,
    v41,
    v42,
    v43,
    v44);
  wmi_mtrace(0x500Eu, v15[1], 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v16,
             0x28u,
             0x500Eu,
             "send_vdev_set_gtx_cfg_cmd_tlv",
             0xC6u,
             v22,
             v23,
             v24,
             v25,
             v26,
             v27,
             v28,
             v29);
  if ( (_DWORD)result )
  {
    v39 = result;
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to set GTX PARAMS",
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      "send_vdev_set_gtx_cfg_cmd_tlv");
    wmi_buf_free();
    return v39;
  }
  return result;
}
