__int64 __fastcall dp_soc_reset_intr_mask(__int64 a1)
{
  __int64 v1; // x20
  unsigned int ring_in_mask; // w0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  unsigned int v12; // w21
  unsigned int v13; // w22
  unsigned int v14; // w0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned int v23; // w21
  unsigned int v24; // w22
  unsigned int v25; // w0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  unsigned int v34; // w20
  unsigned int v35; // w21
  __int64 v36; // x26
  unsigned int v37; // w20
  int v38; // w25
  unsigned int v39; // w0
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  unsigned int v48; // w23
  int v49; // w24
  __int64 v50; // x21
  unsigned int v51; // w20
  __int64 result; // x0
  unsigned int v53; // w0
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  unsigned int v62; // w21
  int v63; // w0
  __int64 v64; // x23
  unsigned int i; // w20
  unsigned int v66; // w0
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7

  v1 = *(_QWORD *)(a1 + 40);
  ring_in_mask = dp_srng_find_ring_in_mask(0, v1 + 152);
  if ( (ring_in_mask & 0x80000000) != 0 )
  {
    qdf_trace_msg(
      0x7Cu,
      8u,
      "%s: %pK: ring not part of any group; ring_type: %d,ring_num %d",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "dp_soc_reset_intr_mask",
      a1,
      13,
      0);
  }
  else
  {
    v12 = ring_in_mask;
    v13 = ((__int64 (__fastcall *)(__int64, _QWORD))wlan_cfg_get_tx_ring_mask)(v1, ring_in_mask);
    if ( wlan_cfg_get_dp_soc_nss_cfg(*(_QWORD *)(a1 + 40)) & 1 | v13 )
      wlan_cfg_set_tx_ring_mask(*(_QWORD *)(a1 + 40), v12, v13 & 0xFFFFFFFE);
  }
  v14 = dp_srng_find_ring_in_mask(1, v1 + 152);
  if ( (v14 & 0x80000000) != 0 )
  {
    qdf_trace_msg(
      0x7Cu,
      8u,
      "%s: %pK: ring not part of any group; ring_type: %d,ring_num %d",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "dp_soc_reset_intr_mask",
      a1,
      13,
      1);
  }
  else
  {
    v23 = v14;
    v24 = ((__int64 (__fastcall *)(_QWORD, _QWORD))wlan_cfg_get_tx_ring_mask)(*(_QWORD *)(a1 + 40), v14);
    if ( wlan_cfg_get_dp_soc_nss_cfg(*(_QWORD *)(a1 + 40)) & 2 | v24 )
      wlan_cfg_set_tx_ring_mask(*(_QWORD *)(a1 + 40), v23, v24 & 0xFFFFFFFD);
  }
  v25 = dp_srng_find_ring_in_mask(2, v1 + 152);
  if ( (v25 & 0x80000000) != 0 )
  {
    qdf_trace_msg(
      0x7Cu,
      8u,
      "%s: %pK: ring not part of any group; ring_type: %d,ring_num %d",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "dp_soc_reset_intr_mask",
      a1,
      13,
      2);
  }
  else
  {
    v34 = v25;
    v35 = ((__int64 (__fastcall *)(_QWORD, _QWORD))wlan_cfg_get_tx_ring_mask)(*(_QWORD *)(a1 + 40), v25);
    if ( wlan_cfg_get_dp_soc_nss_cfg(*(_QWORD *)(a1 + 40)) & 4 | v35 )
      wlan_cfg_set_tx_ring_mask(*(_QWORD *)(a1 + 40), v34, v35 & 0xFFFFFFFB);
  }
  v36 = *(_QWORD *)(a1 + 40);
  v37 = 0;
  v38 = *(unsigned __int8 *)(a1 + 12896);
  do
  {
    v39 = dp_srng_find_ring_in_mask(v37, v36 + 170);
    if ( (v39 & 0x80000000) != 0 )
    {
      qdf_trace_msg(
        0x7Cu,
        8u,
        "%s: %pK: ring not part of any group; ring_type: %d,ring_num %d",
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        "dp_soc_reset_intr_mask",
        a1,
        0,
        v37);
    }
    else
    {
      v48 = v39;
      v49 = ((__int64 (__fastcall *)(_QWORD, _QWORD))wlan_cfg_get_rx_ring_mask)(*(_QWORD *)(a1 + 40), v39);
      if ( (unsigned int)wlan_cfg_get_dp_soc_nss_cfg(*(_QWORD *)(a1 + 40)) & (1 << v37) | v49 )
        wlan_cfg_set_rx_ring_mask(*(_QWORD *)(a1 + 40), v48, v49 & (unsigned int)~(1 << v37));
    }
    ++v37;
  }
  while ( v37 != 8 );
  v50 = *(_QWORD *)(a1 + 40);
  v51 = ((__int64 (__fastcall *)(__int64, _QWORD))wlan_cfg_get_hw_mac_idx)(v50, 0);
  result = wlan_cfg_get_dp_soc_nss_cfg(*(_QWORD *)(a1 + 40));
  if ( (result & 1) != 0 )
  {
    v53 = dp_srng_find_ring_in_mask(v51, v50 + 350);
    if ( (v53 & 0x80000000) != 0 )
    {
      result = qdf_trace_msg(
                 0x7Cu,
                 8u,
                 "%s: %pK: ring not part of any group; ring_type: %d,ring_num %d",
                 v54,
                 v55,
                 v56,
                 v57,
                 v58,
                 v59,
                 v60,
                 v61,
                 "dp_soc_reset_intr_mask",
                 a1,
                 0,
                 v51);
      if ( !v38 )
        return result;
      goto LABEL_23;
    }
    v62 = v53;
    v63 = ((__int64 (__fastcall *)(_QWORD, _QWORD))wlan_cfg_get_host2rxdma_ring_mask)(*(_QWORD *)(a1 + 40), v53);
    result = ((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD))wlan_cfg_set_host2rxdma_ring_mask)(
               *(_QWORD *)(a1 + 40),
               v62,
               v63 & (unsigned int)~(1 << v51));
  }
  if ( !v38 )
    return result;
LABEL_23:
  v64 = *(_QWORD *)(a1 + 40);
  for ( i = 0; i != v38; ++i )
  {
    result = wlan_cfg_get_dp_soc_nss_cfg(*(_QWORD *)(a1 + 40));
    if ( ((unsigned __int8)(1 << i) & (unsigned __int8)result) != 0 )
    {
      v66 = dp_srng_find_ring_in_mask(i, v64 + 278);
      if ( (v66 & 0x80000000) != 0 )
        result = qdf_trace_msg(
                   0x7Cu,
                   8u,
                   "%s: %pK: ring not part of any group; ring_type: %d,ring_num %d",
                   v67,
                   v68,
                   v69,
                   v70,
                   v71,
                   v72,
                   v73,
                   v74,
                   "dp_soc_reset_intr_mask",
                   a1,
                   1,
                   i);
      else
        result = wlan_cfg_set_rx_err_ring_mask(*(_QWORD *)(a1 + 40), v66, 0);
    }
  }
  return result;
}
