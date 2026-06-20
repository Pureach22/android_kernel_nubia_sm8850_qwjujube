__int64 __fastcall send_process_set_ie_info_cmd_tlv(__int64 a1, const void **a2)
{
  int v4; // w25
  unsigned int v5; // w24
  __int64 v6; // x0
  _DWORD *v7; // x22
  __int64 v8; // x19
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  size_t v17; // x2
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  unsigned int v26; // w20
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7

  v4 = *((_DWORD *)a2 + 2) + 3;
  v5 = v4 & 0xFFFFFFFC;
  v6 = wmi_buf_alloc_fl(a1, (v4 & 0xFFFFFFFC) + 28, "send_process_set_ie_info_cmd_tlv", 0x440u);
  if ( v6 )
  {
    v7 = *(_DWORD **)(v6 + 224);
    v8 = v6;
    qdf_mem_set(v7, v5 + 28, 0);
    *v7 = 26411028;
    v7[1] = *(_DWORD *)a2;
    v7[2] = *((_DWORD *)a2 + 1);
    v7[3] = *((_DWORD *)a2 + 2);
    v7[5] = *((_DWORD *)a2 + 4);
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: IE:%d of size:%d sent for vdev:%d",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "send_process_set_ie_info_cmd_tlv",
      *((unsigned int *)a2 + 1),
      *((unsigned int *)a2 + 2),
      *(unsigned int *)a2);
    v17 = (unsigned int)v7[3];
    v7[6] = v4 & 0xFFFC | 0x110000;
    qdf_mem_copy(v7 + 7, a2[3], v17);
    wmi_mtrace(0x5013u, v7[1], 0);
    v26 = wmi_unified_cmd_send_fl(
            a1,
            v8,
            v5 + 28,
            0x5013u,
            "send_process_set_ie_info_cmd_tlv",
            0x45Fu,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            v24,
            v25);
    if ( v26 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Failed to send set IE command ret = %d",
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        "send_process_set_ie_info_cmd_tlv",
        v26);
      wmi_buf_free();
    }
  }
  else
  {
    return 2;
  }
  return v26;
}
