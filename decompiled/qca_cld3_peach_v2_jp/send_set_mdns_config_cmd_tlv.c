__int64 __fastcall send_set_mdns_config_cmd_tlv(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v10; // w8
  unsigned int v11; // w23
  __int64 v12; // x20
  unsigned int v13; // w19
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x21
  __int64 v23; // x20
  __int64 v24; // x21
  __int64 v28; // x0
  _DWORD *v29; // x8
  __int64 v30; // x22
  size_t v31; // x2
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  unsigned int v40; // w0
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  __int64 v49; // x21
  unsigned int v50; // w8
  unsigned int v51; // w25
  __int64 v52; // x20
  __int64 v53; // x20
  __int64 v54; // x21
  __int64 v55; // x0
  _DWORD *v56; // x8
  __int64 v57; // x22
  size_t v58; // x2
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  unsigned int v67; // w0
  __int64 v68; // x21
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  __int64 v77; // x21

  if ( (*(_BYTE *)(a2 + 4) & 1) != 0 )
  {
    v10 = *(_DWORD *)(a2 + 12);
    v11 = (v10 + 3) & 0xFFFC;
    if ( v10 > v11 )
    {
      v12 = jiffies;
      if ( send_set_mdns_fqdn_cmd_tlv___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x31u,
          2u,
          "%s: integer overflow while rounding up data_len",
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          "send_set_mdns_fqdn_cmd_tlv");
        send_set_mdns_fqdn_cmd_tlv___last_ticks = v12;
        v13 = 16;
        goto LABEL_11;
      }
      goto LABEL_10;
    }
    if ( v11 >= 0x5FD )
    {
      v23 = jiffies;
      if ( send_set_mdns_fqdn_cmd_tlv___last_ticks_12 - jiffies + 125 >= 0 )
      {
LABEL_10:
        v13 = 16;
        goto LABEL_11;
      }
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: wmi_max_msg_size overflow for given data_len",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "send_set_mdns_fqdn_cmd_tlv");
      send_set_mdns_fqdn_cmd_tlv___last_ticks_12 = v23;
      v13 = 16;
LABEL_11:
      v24 = jiffies;
      if ( send_set_mdns_config_cmd_tlv___last_ticks_5 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x31u,
          2u,
          "%s: Failed to send set fqdn command. ret = %d",
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          "send_set_mdns_config_cmd_tlv",
          v13);
        send_set_mdns_config_cmd_tlv___last_ticks_5 = v24;
      }
      return v13;
    }
    v28 = wmi_buf_alloc_fl(a1, (unsigned __int16)(v11 + 20), "send_set_mdns_fqdn_cmd_tlv", 0xF5u);
    if ( !v28 )
    {
      v49 = jiffies;
      v13 = 2;
      if ( send_set_mdns_fqdn_cmd_tlv___last_ticks_14 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x31u,
          2u,
          "%s: Failed to allocate wmi buffer",
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          "send_set_mdns_fqdn_cmd_tlv");
        send_set_mdns_fqdn_cmd_tlv___last_ticks_14 = v49;
      }
      goto LABEL_11;
    }
    v29 = *(_DWORD **)(v28 + 224);
    v30 = v28;
    *v29 = 23199756;
    v29[1] = *(_DWORD *)a2;
    v29[2] = *(_DWORD *)(a2 + 8);
    v31 = *(unsigned int *)(a2 + 12);
    v29[3] = v31;
    v29[4] = v11 | 0x110000;
    qdf_mem_copy(v29 + 5, (const void *)(a2 + 16), v31);
    wmi_mtrace(0x2F002u, *(_DWORD *)a2, *(_DWORD *)(a2 + 8));
    v40 = wmi_unified_cmd_send_fl(
            a1,
            v30,
            (unsigned __int16)(v11 + 20),
            0x2F002u,
            "send_set_mdns_fqdn_cmd_tlv",
            0x10Du,
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            v38,
            v39);
    if ( v40 )
    {
      v13 = v40;
      wmi_buf_free();
      goto LABEL_11;
    }
    v50 = *(_DWORD *)(a2 + 84);
    v51 = (v50 + 3) & 0xFFFC;
    if ( v50 > v51 )
    {
      v52 = jiffies;
      if ( send_set_mdns_response_cmd_tlv___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x31u,
          2u,
          "%s: integer overflow while rounding up data_len",
          v41,
          v42,
          v43,
          v44,
          v45,
          v46,
          v47,
          v48,
          "send_set_mdns_response_cmd_tlv");
        send_set_mdns_response_cmd_tlv___last_ticks = v52;
        v13 = 16;
        goto LABEL_27;
      }
      goto LABEL_26;
    }
    if ( v51 >= 0x5FD )
    {
      v53 = jiffies;
      if ( send_set_mdns_response_cmd_tlv___last_ticks_15 - jiffies + 125 >= 0 )
      {
LABEL_26:
        v13 = 16;
        goto LABEL_27;
      }
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: wmi_max_msg_size overflow for given data_len",
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        "send_set_mdns_response_cmd_tlv");
      send_set_mdns_response_cmd_tlv___last_ticks_15 = v53;
      v13 = 16;
LABEL_27:
      v54 = jiffies;
      if ( send_set_mdns_config_cmd_tlv___last_ticks_7 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x31u,
          2u,
          "%s: Failed to send set mDNS response command. ret = %d",
          v41,
          v42,
          v43,
          v44,
          v45,
          v46,
          v47,
          v48,
          "send_set_mdns_config_cmd_tlv",
          v13);
        send_set_mdns_config_cmd_tlv___last_ticks_7 = v54;
      }
      return v13;
    }
    v55 = wmi_buf_alloc_fl(a1, (unsigned __int16)(v51 + 20), "send_set_mdns_response_cmd_tlv", 0x134u);
    if ( !v55 )
    {
      v68 = jiffies;
      v13 = 2;
      if ( send_set_mdns_response_cmd_tlv___last_ticks_16 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x31u,
          2u,
          "%s: Failed to allocate wmi buffer",
          v41,
          v42,
          v43,
          v44,
          v45,
          v46,
          v47,
          v48,
          "send_set_mdns_response_cmd_tlv");
        send_set_mdns_response_cmd_tlv___last_ticks_16 = v68;
      }
      goto LABEL_27;
    }
    v56 = *(_DWORD **)(v55 + 224);
    v57 = v55;
    *v56 = 23265292;
    v56[1] = *(_DWORD *)a2;
    v56[2] = *(_DWORD *)(a2 + 80);
    v58 = *(unsigned int *)(a2 + 84);
    v56[3] = v58;
    v56[4] = v51 | 0x110000;
    qdf_mem_copy(v56 + 5, (const void *)(a2 + 88), v58);
    wmi_mtrace(0x2F003u, *(_DWORD *)a2, 0);
    v67 = wmi_unified_cmd_send_fl(
            a1,
            v57,
            (unsigned __int16)(v51 + 20),
            0x2F003u,
            "send_set_mdns_response_cmd_tlv",
            0x14Bu,
            v59,
            v60,
            v61,
            v62,
            v63,
            v64,
            v65,
            v66);
    if ( v67 )
    {
      v13 = v67;
      wmi_buf_free();
      goto LABEL_27;
    }
    v13 = send_set_mdns_offload_cmd_tlv(a1, a2);
    if ( v13 )
    {
      v77 = jiffies;
      if ( send_set_mdns_config_cmd_tlv___last_ticks_9 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x31u,
          2u,
          "%s: Failed to send set mDNS offload  command. ret = %d",
          v69,
          v70,
          v71,
          v72,
          v73,
          v74,
          v75,
          v76,
          "send_set_mdns_config_cmd_tlv",
          v13);
        send_set_mdns_config_cmd_tlv___last_ticks_9 = v77;
      }
    }
  }
  else
  {
    v13 = ((__int64 (*)(void))send_set_mdns_offload_cmd_tlv)();
    if ( v13 )
    {
      v22 = jiffies;
      if ( send_set_mdns_config_cmd_tlv___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x31u,
          2u,
          "%s: Failed to send mDNS offload command. ret = %d",
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          "send_set_mdns_config_cmd_tlv",
          v13);
        send_set_mdns_config_cmd_tlv___last_ticks = v22;
      }
    }
  }
  return v13;
}
