__int64 __fastcall send_mlo_vdev_pause_cmd_tlv(
        __int64 a1,
        unsigned __int16 *a2,
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
  _DWORD *v21; // x23
  __int64 v22; // x20
  int v23; // w6
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 result; // x0
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 v41; // x5
  unsigned int v42; // w19
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7

  if ( a2 )
  {
    v12 = wmi_buf_alloc_fl(a1, 0x10u, "send_mlo_vdev_pause_cmd_tlv", 0x4F8u);
    if ( v12 )
    {
      v21 = *(_DWORD **)(v12 + 224);
      v22 = v12;
      *v21 = 77201420;
      v21[1] = *a2;
      v21[3] = *((_DWORD *)a2 + 1);
      v23 = *((_DWORD *)a2 + 2);
      if ( (unsigned int)(v23 - 1) >= 3 )
      {
        wmi_buf_free();
        qdf_trace_msg(
          0x31u,
          2u,
          "%s: invalid type %d",
          v43,
          v44,
          v45,
          v46,
          v47,
          v48,
          v49,
          v50,
          "send_mlo_vdev_pause_cmd_tlv",
          *((unsigned int *)a2 + 2));
        return 4;
      }
      else
      {
        v21[2] = v23;
        qdf_trace_msg(
          0x31u,
          8u,
          "%s: vdev id: %d pause duration: %d pause type %d",
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          "send_mlo_vdev_pause_cmd_tlv");
        wmi_mtrace(0x5035u, v21[1], 0);
        result = wmi_unified_cmd_send_fl(
                   a1,
                   v22,
                   0x10u,
                   0x5035u,
                   "send_mlo_vdev_pause_cmd_tlv",
                   0x51Bu,
                   v24,
                   v25,
                   v26,
                   v27,
                   v28,
                   v29,
                   v30,
                   v31);
        if ( (_DWORD)result )
        {
          v41 = *a2;
          v42 = result;
          qdf_trace_msg(
            0x31u,
            2u,
            "%s: Failed to send vdev pause cmd: psoc (%pK) vdev(%u)",
            v33,
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            "send_mlo_vdev_pause_cmd_tlv",
            **(_QWORD **)(a1 + 760),
            v41);
          wmi_buf_free();
          return v42;
        }
      }
    }
    else
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: wmi buf alloc failed for vdev pause cmd: psoc (%pK) vdev(%u)",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "send_mlo_vdev_pause_cmd_tlv",
        **(_QWORD **)(a1 + 760),
        *a2);
      return 2;
    }
  }
  else
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: ML vdev pause info is NULL",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "send_mlo_vdev_pause_cmd_tlv");
    return 29;
  }
  return result;
}
