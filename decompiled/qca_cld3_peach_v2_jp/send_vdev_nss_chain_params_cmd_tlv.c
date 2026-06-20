__int64 __fastcall send_vdev_nss_chain_params_cmd_tlv(__int64 a1, unsigned __int8 a2, __int64 a3)
{
  __int64 v6; // x0
  _DWORD *v7; // x8
  __int64 v8; // x20
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  unsigned int v17; // w21
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7

  v6 = wmi_buf_alloc_fl(a1, 0x4Cu, "send_vdev_nss_chain_params_cmd_tlv", 0x4D7u);
  if ( v6 )
  {
    v7 = *(_DWORD **)(v6 + 224);
    v8 = v6;
    *v7 = 50004040;
    v7[1] = a2;
    v7[14] = *(unsigned __int8 *)(a3 + 44);
    v7[13] = *(unsigned __int8 *)(a3 + 46);
    v7[16] = *(unsigned __int8 *)(a3 + 45);
    v7[15] = *(unsigned __int8 *)(a3 + 47);
    v7[3] = *(_DWORD *)(a3 + 8);
    v7[2] = *(_DWORD *)a3;
    v7[9] = *(_DWORD *)(a3 + 12);
    v7[8] = *(_DWORD *)(a3 + 4);
    v7[5] = *(_DWORD *)(a3 + 24);
    v7[4] = *(_DWORD *)(a3 + 16);
    v7[11] = *(_DWORD *)(a3 + 28);
    v7[10] = *(_DWORD *)(a3 + 20);
    v7[12] = *(_DWORD *)(a3 + 40);
    v7[6] = *(_DWORD *)(a3 + 32);
    v7[7] = *(_DWORD *)(a3 + 36);
    v7[17] = *(_DWORD *)(a3 + 48);
    v7[18] = *(_DWORD *)(a3 + 52);
    qdf_mtrace(49, 100, 0x2A1u, a2, 0);
    v17 = wmi_unified_cmd_send_fl(
            a1,
            v8,
            0x4Cu,
            0x5021u,
            "send_vdev_nss_chain_params_cmd_tlv",
            0x4F7u,
            v9,
            v10,
            v11,
            v12,
            v13,
            v14,
            v15,
            v16);
    if ( v17 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Failed to send WMI_VDEV_CHAINMASK_CONFIG_CMDID",
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        "send_vdev_nss_chain_params_cmd_tlv");
      wmi_buf_free();
    }
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: vdev_id %d",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "send_vdev_nss_chain_params_cmd_tlv",
      a2);
  }
  else
  {
    return 2;
  }
  return v17;
}
