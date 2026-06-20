__int64 __fastcall send_vdev_set_ltf_key_seed_cmd_tlv(__int64 a1, unsigned __int8 *a2)
{
  int v2; // w22
  __int64 v5; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  _DWORD *v14; // x8
  __int64 v15; // x19
  size_t v16; // x2
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned int v25; // w20
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7

  v2 = *((unsigned __int16 *)a2 + 31);
  v5 = wmi_buf_alloc_fl(a1, v2 + 28, "send_vdev_set_ltf_key_seed_cmd_tlv", 0x508Eu);
  if ( v5 )
  {
    v14 = *(_DWORD **)(v5 + 224);
    v15 = v5;
    *v14 = 68878356;
    v14[1] = *a2;
    v14[2] = *(_DWORD *)(a2 + 1);
    v14[3] = *(unsigned __int16 *)(a2 + 5);
    v16 = *((unsigned __int16 *)a2 + 31);
    v14[5] = v16;
    v14[4] = a2[13];
    v14[6] = v16 | 0x110000;
    qdf_mem_copy(v14 + 7, a2 + 14, v16);
    qdf_mtrace(49, 100, 0x2B2u, 0, 0);
    v25 = wmi_unified_cmd_send_fl(
            a1,
            v15,
            v2 + 28,
            0x5032u,
            "send_vdev_set_ltf_key_seed_cmd_tlv",
            0x50ABu,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            v24);
    if ( v25 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Failed to send ltf keyseed command ret = %d",
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        "send_vdev_set_ltf_key_seed_cmd_tlv",
        v25);
      wmi_buf_free();
    }
  }
  else
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: wmi_buf_alloc failed",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "send_vdev_set_ltf_key_seed_cmd_tlv");
    return 16;
  }
  return v25;
}
