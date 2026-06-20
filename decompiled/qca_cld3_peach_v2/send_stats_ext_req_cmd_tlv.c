__int64 __fastcall send_stats_ext_req_cmd_tlv(__int64 a1, _DWORD *a2)
{
  unsigned __int16 max_msg_len; // w0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  unsigned __int64 v13; // x19
  __int64 result; // x0
  __int64 v15; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  _DWORD *v24; // x25
  __int64 v25; // x21
  size_t v26; // x2
  _DWORD *v27; // x8
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  unsigned int v52; // w19

  max_msg_len = wmi_get_max_msg_len(a1);
  v13 = (unsigned int)a2[1];
  if ( (unsigned __int64)max_msg_len - 16 >= v13 )
  {
    v15 = wmi_buf_alloc_fl(a1, (int)v13 + 24, "send_stats_ext_req_cmd_tlv", 0x2151u);
    if ( v15 )
    {
      v24 = *(_DWORD **)(v15 + 224);
      v25 = v15;
      *v24 = 17498120;
      v24[1] = *a2;
      v24[2] = a2[1];
      qdf_trace_msg(
        0x31u,
        8u,
        "%s: The data len value is %u and vdev id set is %u",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "send_stats_ext_req_cmd_tlv");
      v26 = (unsigned int)v24[2];
      v24[3] = (unsigned __int16)v24[2] | 0x110000;
      qdf_mem_copy(v24 + 4, a2 + 3, v26);
      v27 = (_DWORD *)((char *)v24 + (unsigned int)v24[2] + 16);
      *v27 = 1048580;
      v27[1] = a2[2];
      qdf_trace_msg(
        0x31u,
        8u,
        "%s: Sending MLO vdev_id_bitmap:%x",
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        "send_stats_ext_req_cmd_tlv");
      qdf_mtrace(49, 100, 0xB03u, v24[1], 0);
      result = wmi_unified_cmd_send_fl(
                 a1,
                 v25,
                 (int)v13 + 24,
                 0x16003u,
                 "send_stats_ext_req_cmd_tlv",
                 0x2177u,
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
        v52 = result;
        qdf_trace_msg(
          0x31u,
          2u,
          "%s: Failed to send notify cmd ret = %d",
          v44,
          v45,
          v46,
          v47,
          v48,
          v49,
          v50,
          v51,
          "send_stats_ext_req_cmd_tlv",
          (unsigned int)result);
        wmi_buf_free();
        return v52;
      }
    }
    else
    {
      return 2;
    }
  }
  else
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Data length=%d is greater than max wmi msg size",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "send_stats_ext_req_cmd_tlv",
      (unsigned int)v13);
    return 16;
  }
  return result;
}
