__int64 __fastcall send_p2p_lo_start_cmd_tlv(
        __int64 a1,
        const void **a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  int v12; // w22
  int v13; // w26
  unsigned __int64 v14; // x25
  int v15; // w23
  __int64 v16; // x0
  _DWORD *v17; // x24
  __int64 v18; // x20
  unsigned int v19; // w8
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  unsigned int v36; // w0
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  unsigned int v45; // w19

  if ( a2 )
  {
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: vdev_id: %d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "send_p2p_lo_start_cmd_tlv",
      *(unsigned int *)a2);
    v12 = *((_DWORD *)a2 + 6) + 3;
    v13 = *((_DWORD *)a2 + 7) + 3;
    v14 = v12 & 0xFFFFFFFFFFFFFFFCLL;
    v15 = v14 + (v13 & 0xFFFFFFFC);
    v16 = wmi_buf_alloc_fl(a1, v15 + 52, "send_p2p_lo_start_cmd_tlv", 0x173u);
    if ( v16 )
    {
      v17 = *(_DWORD **)(v16 + 224);
      v18 = v16;
      *v17 = 35782696;
      v17[1] = *(_DWORD *)a2;
      v17[2] = *((_DWORD *)a2 + 1);
      v17[3] = *((_DWORD *)a2 + 2);
      v17[4] = *((_DWORD *)a2 + 3);
      v17[5] = *((_DWORD *)a2 + 4);
      v17[6] = *((_DWORD *)a2 + 5);
      v17[7] = *((_DWORD *)a2 + 6);
      v19 = *((_DWORD *)a2 + 7);
      v17[11] = v12 & 0xFFFC | 0x110000;
      v17[8] = v19;
      qdf_mem_copy(v17 + 12, a2[4], *((unsigned int *)a2 + 6));
      *(_DWORD *)((char *)v17 + v14 + 48) = v13 & 0xFFFC | 0x110000;
      qdf_mem_copy((char *)v17 + v14 + 52, a2[5], *((unsigned int *)a2 + 7));
      qdf_trace_msg(
        0x31u,
        8u,
        "%s: Sending WMI_P2P_LO_START command, channel=%d, period=%d, interval=%d, count=%d",
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        "send_p2p_lo_start_cmd_tlv",
        (unsigned int)v17[3],
        (unsigned int)v17[4],
        (unsigned int)v17[5],
        (unsigned int)v17[6]);
      v28 = wmi_mtrace(53258, (unsigned int)v17[1], 0);
      v36 = wmi_unified_cmd_send_fl(
              a1,
              v18,
              v15 + 52,
              0xD00Au,
              "send_p2p_lo_start_cmd_tlv",
              0x19Cu,
              v28,
              v29,
              v30,
              v31,
              v32,
              v33,
              v34,
              v35);
      if ( v36 )
      {
        v45 = v36;
        qdf_trace_msg(
          0x31u,
          2u,
          "%s: Failed to send p2p lo start: %d",
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          "send_p2p_lo_start_cmd_tlv",
          v36);
        wmi_buf_free();
        return v45;
      }
      else
      {
        qdf_trace_msg(
          0x31u,
          8u,
          "%s: Successfully sent WMI_P2P_LO_START",
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          "send_p2p_lo_start_cmd_tlv");
        return 0;
      }
    }
    else
    {
      return 2;
    }
  }
  else
  {
    qdf_trace_msg(0x31u, 2u, "%s: lo start param is null", a3, a4, a5, a6, a7, a8, a9, a10, "send_p2p_lo_start_cmd_tlv");
    return 4;
  }
}
