__int64 __fastcall send_set_arp_stats_req_cmd_tlv(__int64 a1, unsigned int *a2)
{
  unsigned int v4; // w22
  __int64 v5; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  _DWORD *v14; // x23
  __int64 v15; // x20
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  unsigned int v32; // w21
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7

  if ( a2[3] )
    v4 = 44;
  else
    v4 = 20;
  v5 = wmi_buf_alloc_fl(a1, v4, "send_set_arp_stats_req_cmd_tlv", 0x956u);
  if ( v5 )
  {
    v14 = *(_DWORD **)(v5 + 224);
    v15 = v5;
    *v14 = 41418768;
    v14[1] = *a2;
    v14[2] = *((unsigned __int8 *)a2 + 4);
    v14[3] = *((unsigned __int8 *)a2 + 5);
    v14[4] = a2[2];
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: NUD Stats: vdev_id %u set_clr %u pkt_type:%u ipv4 %u",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "send_set_arp_stats_req_cmd_tlv");
    if ( a2[3] )
    {
      v14[5] = 1179668;
      v14[6] = 46792720;
      v14[7] = a2[3];
      v14[8] = a2[4];
      v14[9] = a2[5];
      v14[10] = a2[6];
      qdf_trace_msg(
        0x31u,
        8u,
        "%s: Connectivity Stats: pkt_type_bitmap %u tcp_src_port:%u tcp_dst_port %u icmp_ipv4 %u",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "send_set_arp_stats_req_cmd_tlv");
    }
    wmi_mtrace(0x501Cu, 0xFFu, 0);
    v32 = wmi_unified_cmd_send_fl(
            a1,
            v15,
            v4,
            0x501Cu,
            "send_set_arp_stats_req_cmd_tlv",
            0x990u,
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            v31);
    if ( v32 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: WMI_SET_ARP_STATS_CMDID failed, Error %d",
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        "send_set_arp_stats_req_cmd_tlv",
        v32);
      wmi_buf_free();
    }
    else
    {
      qdf_trace_msg(
        0x31u,
        8u,
        "%s: set arp stats flag=%d, vdev=%d",
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        "send_set_arp_stats_req_cmd_tlv",
        *((unsigned __int8 *)a2 + 4),
        *a2);
    }
  }
  else
  {
    return 2;
  }
  return v32;
}
