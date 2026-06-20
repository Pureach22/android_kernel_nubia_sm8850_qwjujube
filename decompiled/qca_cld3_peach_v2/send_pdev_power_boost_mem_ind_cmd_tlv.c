__int64 __fastcall send_pdev_power_boost_mem_ind_cmd_tlv(__int64 a1, _DWORD *a2, unsigned __int8 a3)
{
  __int64 v6; // x0
  _DWORD *v7; // x23
  __int64 v8; // x19
  _DWORD *v9; // x8
  double v10; // d0
  int v11; // w0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  unsigned int v19; // w20
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

  v6 = wmi_buf_alloc_fl(a1, 0x14u, "send_pdev_power_boost_mem_ind_cmd_tlv", 0x5BA3u);
  if ( v6 )
  {
    v7 = *(_DWORD **)(v6 + 224);
    v8 = v6;
    *v7 = 82444304;
    v9 = *(_DWORD **)(*(_QWORD *)(a1 + 728) + 3680LL);
    if ( *(v9 - 1) != -2112860426 )
      __break(0x8228u);
    v10 = ((double (__fastcall *)(__int64, _QWORD))v9)(a1, a3);
    v7[1] = v11;
    v7[2] = *a2;
    v7[3] = a2[1];
    v7[4] = a2[2];
    v19 = wmi_unified_cmd_send_fl(
            a1,
            v8,
            0x14u,
            0x4057u,
            "send_pdev_power_boost_mem_ind_cmd_tlv",
            0x5BB6u,
            v10,
            v12,
            v13,
            v14,
            v15,
            v16,
            v17,
            v18);
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: TPB: Sending WMI_PDEV_POWER_BOOST_MEM_ADDR_CMDID with pdev_id: %u, paddr_aligned_lo: 0x%x, paddr_aligned_hi: 0x%x, size: %u",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "send_pdev_power_boost_mem_ind_cmd_tlv",
      (unsigned int)v7[1],
      (unsigned int)v7[2],
      (unsigned int)v7[3],
      (unsigned int)v7[4]);
    if ( v19 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: TPB: Failed to send WMI_PDEV_POWER_BOOST_MEM_ADDR_CMDID",
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        "send_pdev_power_boost_mem_ind_cmd_tlv");
      wmi_buf_free();
    }
  }
  else
  {
    return 2;
  }
  return v19;
}
