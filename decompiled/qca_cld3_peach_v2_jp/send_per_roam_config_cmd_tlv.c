__int64 __fastcall send_per_roam_config_cmd_tlv(__int64 a1, unsigned __int8 *a2)
{
  __int64 v4; // x0
  _DWORD *v5; // x8
  __int64 v6; // x19
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  unsigned int v15; // w21
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7

  v4 = wmi_buf_alloc_fl(a1, 0x24u, "send_per_roam_config_cmd_tlv", 0x1770u);
  if ( v4 )
  {
    v5 = *(_DWORD **)(v4 + 224);
    v6 = v4;
    *v5 = 40370208;
    v5[1] = *a2;
    v5[2] = *((_DWORD *)a2 + 1);
    v5[3] = *((unsigned __int16 *)a2 + 6) | (*((_DWORD *)a2 + 2) << 16);
    v5[4] = *((unsigned __int16 *)a2 + 10) | (*((_DWORD *)a2 + 4) << 16);
    v5[5] = *((unsigned __int16 *)a2 + 14) | (*((_DWORD *)a2 + 6) << 16);
    v5[6] = *((_DWORD *)a2 + 8);
    v5[7] = *((unsigned __int16 *)a2 + 20) | (*((_DWORD *)a2 + 9) << 16);
    v5[8] = *((_DWORD *)a2 + 11);
    wmi_mtrace(0xB00Fu, 0xFFu, 0);
    v15 = wmi_unified_cmd_send_fl(
            a1,
            v6,
            0x24u,
            0xB00Fu,
            "send_per_roam_config_cmd_tlv",
            0x1793u,
            v7,
            v8,
            v9,
            v10,
            v11,
            v12,
            v13,
            v14);
    if ( v15 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: WMI_ROAM_PER_CONFIG_CMDID failed, Error %d",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "send_per_roam_config_cmd_tlv",
        v15);
      wmi_buf_free();
    }
    else
    {
      qdf_trace_msg(
        0x31u,
        8u,
        "%s: per roam enable=%d, vdev=%d",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "send_per_roam_config_cmd_tlv",
        *((unsigned int *)a2 + 1),
        *a2);
    }
  }
  else
  {
    return 2;
  }
  return v15;
}
