__int64 __fastcall send_set_sta_keep_alive_cmd_tlv(
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
  __int64 v12; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  _DWORD *v21; // x22
  __int64 v22; // x19
  int v23; // w8
  int v24; // w8
  __int64 v25; // x9
  unsigned int v26; // w20
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7

  qdf_trace_msg(0x31u, 8u, "%s: Enter", a3, a4, a5, a6, a7, a8, a9, a10, "send_set_sta_keep_alive_cmd_tlv");
  v12 = wmi_buf_alloc_fl(a1, 0x28u, "send_set_sta_keep_alive_cmd_tlv", 0x67u);
  if ( !v12 )
    return 16;
  v21 = *(_DWORD **)(v12 + 224);
  v22 = v12;
  *v21 = 8323088;
  v23 = *((_DWORD *)a2 + 2);
  v21[4] = v23;
  v21[2] = v23 != 0;
  v21[1] = *a2;
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: Keep Alive: vdev_id:%d interval:%u method:%d",
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    "send_set_sta_keep_alive_cmd_tlv",
    *a2,
    *((unsigned int *)a2 + 2),
    *((unsigned int *)a2 + 1));
  v21[5] = 8388624;
  v24 = *((_DWORD *)a2 + 1);
  if ( v24 == 2 )
    goto LABEL_5;
  if ( v24 == 5 )
  {
LABEL_8:
    v25 = 3;
    goto LABEL_9;
  }
  if ( v24 != 4 )
  {
    v24 = 1;
    goto LABEL_8;
  }
LABEL_5:
  v21[3] = v24;
  qdf_mem_copy(v21 + 6, a2 + 12, 4u);
  qdf_mem_copy(v21 + 7, a2 + 16, 4u);
  v25 = 9;
  v21[8] = *((_DWORD *)a2 + 5);
  v24 = *((unsigned __int16 *)a2 + 12);
LABEL_9:
  v21[v25] = v24;
  wmi_mtrace(0x1C005u, v21[1], 0);
  v26 = wmi_unified_cmd_send_fl(
          a1,
          v22,
          0x28u,
          0x1C005u,
          "send_set_sta_keep_alive_cmd_tlv",
          0x8Eu,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34);
  if ( v26 )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to set KeepAlive",
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      "send_set_sta_keep_alive_cmd_tlv");
    wmi_buf_free();
  }
  qdf_trace_msg(0x31u, 8u, "%s: Exit", v35, v36, v37, v38, v39, v40, v41, v42, "send_set_sta_keep_alive_cmd_tlv");
  return v26;
}
