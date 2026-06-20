__int64 __fastcall send_peer_unmap_conf_cmd_tlv(__int64 a1, unsigned __int8 a2, unsigned int a3, __int64 a4)
{
  unsigned int v4; // w22
  int v6; // w24
  __int64 v10; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  _DWORD *v19; // x9
  __int64 v20; // x19
  int v21; // w8
  _DWORD *v22; // x9
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7

  v4 = 16;
  if ( a3 && a4 )
  {
    v6 = 4 * a3;
    v10 = wmi_buf_alloc_fl(a1, 4 * a3 + 8, "send_peer_unmap_conf_cmd_tlv", 0x9F1u);
    if ( v10 )
    {
      v19 = *(_DWORD **)(v10 + 224);
      v20 = v10;
      v21 = 0;
      *v19 = 50921472;
      v19[1] = v6 & 0xFFFC | 0x100000;
      v22 = v19 + 2;
      do
      {
        v22[v21] = *(unsigned __int16 *)(a4 + 2LL * v21);
        ++v21;
      }
      while ( a3 != v21 );
      qdf_trace_msg(
        0x31u,
        8u,
        "%s: vdev_id %d peer_id_cnt %d",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "send_peer_unmap_conf_cmd_tlv",
        a2,
        a3);
      wmi_mtrace(0x601Du, a2, 0);
      v4 = wmi_unified_cmd_send_fl(
             a1,
             v20,
             v6 + 8,
             0x601Du,
             "send_peer_unmap_conf_cmd_tlv",
             0xA0Du,
             v23,
             v24,
             v25,
             v26,
             v27,
             v28,
             v29,
             v30);
      if ( v4 )
      {
        qdf_trace_msg(
          0x31u,
          2u,
          "%s: Failed to send peer unmap conf command: Err[%d]",
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          "send_peer_unmap_conf_cmd_tlv",
          v4);
        wmi_buf_free();
      }
    }
    else
    {
      v4 = 2;
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: wmi_buf_alloc failed",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "send_peer_unmap_conf_cmd_tlv");
    }
  }
  return v4;
}
