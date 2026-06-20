__int64 __fastcall dp_soc_disable_unused_mac_intr_mask(__int64 a1, unsigned int a2)
{
  __int64 v2; // x21
  unsigned int ring_in_mask; // w0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x21
  unsigned int v15; // w0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x21
  unsigned int v25; // w0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x21
  unsigned int v35; // w0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7

  v2 = *(_QWORD *)(a1 + 40);
  ring_in_mask = dp_srng_find_ring_in_mask(a2, (unsigned __int8 *)(v2 + 350));
  if ( (ring_in_mask & 0x80000000) != 0 )
    qdf_trace_msg(
      0x7Cu,
      8u,
      "%s: %pK: ring not part of any group; ring_type: RXDMA_BUF, mac_num %d",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "dp_soc_disable_unused_mac_intr_mask",
      a1,
      a2);
  else
    ((void (__fastcall *)(__int64, _QWORD, _QWORD))wlan_cfg_set_host2rxdma_ring_mask)(v2, ring_in_mask, 0);
  v14 = *(_QWORD *)(a1 + 40);
  v15 = dp_srng_find_ring_in_mask(a2, (unsigned __int8 *)(v14 + 188));
  if ( (v15 & 0x80000000) != 0 )
    qdf_trace_msg(
      0x7Cu,
      8u,
      "%s: %pK: ring not part of any group; ring_type: RXDMA_MONITOR_DST, mac_num %d",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "dp_soc_disable_unused_mac_intr_mask",
      a1,
      a2);
  else
    wlan_cfg_set_rx_mon_ring_mask(v14, v15, 0);
  v24 = *(_QWORD *)(a1 + 40);
  v25 = dp_srng_find_ring_in_mask(a2, (unsigned __int8 *)(v24 + 332));
  if ( (v25 & 0x80000000) != 0 )
    qdf_trace_msg(
      0x7Cu,
      8u,
      "%s: %pK: ring not part of any group; ring_type: RXDMA_DST, mac_num %d",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "dp_soc_disable_unused_mac_intr_mask",
      a1,
      a2);
  else
    ((void (__fastcall *)(__int64, _QWORD, _QWORD))wlan_cfg_set_rxdma2host_ring_mask)(v24, v25, 0);
  v34 = *(_QWORD *)(a1 + 40);
  v35 = dp_srng_find_ring_in_mask(a2, (unsigned __int8 *)(v34 + 224));
  if ( (v35 & 0x80000000) != 0 )
    return qdf_trace_msg(
             0x7Cu,
             8u,
             "%s: %pK: ring not part of any group; ring_type: RXDMA_MONITOR_BUF, mac_num %d",
             v36,
             v37,
             v38,
             v39,
             v40,
             v41,
             v42,
             v43,
             "dp_soc_disable_unused_mac_intr_mask",
             a1,
             a2);
  else
    return ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))wlan_cfg_set_host2rxdma_mon_ring_mask)(v34, v35, 0);
}
