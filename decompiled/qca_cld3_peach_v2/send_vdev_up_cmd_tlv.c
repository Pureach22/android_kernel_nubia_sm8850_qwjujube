__int64 __fastcall send_vdev_up_cmd_tlv(
        __int64 a1,
        unsigned __int8 *a2,
        unsigned __int8 *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  int v22; // w8
  int v23; // w9
  int v24; // w10
  int v25; // w11
  __int64 v26; // x0
  _DWORD *v27; // x8
  __int64 v28; // x22
  int v29; // w3
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 result; // x0
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7

  qdf_trace_msg(0x31u, 8u, "%s: VDEV_UP", a4, a5, a6, a7, a8, a9, a10, a11, "send_vdev_up_cmd_tlv");
  if ( a2 )
  {
    v22 = *a2;
    v23 = a2[1];
    v24 = a2[2];
    v25 = a2[5];
  }
  else
  {
    v24 = 0;
    v22 = 0;
    v23 = 0;
    v25 = 0;
  }
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: vdev_id %d aid %d profile idx %d count %d bssid %02x:%02x:%02x:**:**:%02x trans bssid %02x:%02x:%02x:**:**:%02x",
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    "send_vdev_up_cmd_tlv",
    *a3,
    *((unsigned __int16 *)a3 + 1),
    *((unsigned int *)a3 + 1),
    *((unsigned int *)a3 + 2),
    v22,
    v23,
    v24,
    v25,
    a3[12],
    a3[13],
    a3[14],
    a3[17]);
  v26 = wmi_buf_alloc_fl(a1, 0x28u, "send_vdev_up_cmd_tlv", 0x8BDu);
  if ( !v26 )
    return 2;
  v27 = *(_DWORD **)(v26 + 224);
  v28 = v26;
  *v27 = 6029348;
  v29 = *a3;
  v27[1] = v29;
  v27[2] = *((unsigned __int16 *)a3 + 1);
  v27[7] = *((_DWORD *)a3 + 1);
  v27[8] = *((_DWORD *)a3 + 2);
  v27[5] = *((_DWORD *)a3 + 3);
  v27[6] = *((unsigned __int16 *)a3 + 8);
  v27[3] = *(_DWORD *)a2;
  v27[4] = *((unsigned __int16 *)a2 + 2);
  qdf_mtrace(49, 100, 0x285u, v29, 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v28,
             0x28u,
             0x5005u,
             "send_vdev_up_cmd_tlv",
             0x8CCu,
             v30,
             v31,
             v32,
             v33,
             v34,
             v35,
             v36,
             v37);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to send vdev up command",
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      "send_vdev_up_cmd_tlv");
    wmi_buf_free();
    return 16;
  }
  return result;
}
