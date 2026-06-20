__int64 __fastcall dp_tx_reinject_handler(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        __int64 a12,
        char a13)
{
  __int64 v17; // x20
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x8
  int v27; // w9
  int v28; // w3
  int v29; // w4
  int v30; // w5
  int v31; // w6
  int v32; // w7
  __int64 v33; // x24
  __int64 v34; // x26
  __int64 v35; // x21
  __int64 v36; // x23
  __int64 v37; // x25
  __int64 is_pp_nbuf; // x0
  unsigned __int64 StatusReg; // x8
  __int64 *v40; // x25
  __int64 v41; // x8
  __int64 v42; // x0
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  unsigned __int16 *v51; // x24
  __int64 v52; // x8
  __int64 v53; // x0
  char is_opt_wifi_dp_enabled; // w0
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  char *v63; // x8
  __int64 v64; // x8
  char v65; // w8
  int v66; // w9
  int v67; // w8
  int v68; // w10
  char *v69; // x0
  double v70; // d0
  double v71; // d1
  double v72; // d2
  double v73; // d3
  double v74; // d4
  double v75; // d5
  double v76; // d6
  double v77; // d7
  __int64 v78; // x24
  __int64 (__fastcall *v79)(__int64, __int64, __int64); // x8
  __int64 v80; // x1
  int v81; // w2
  int v82; // w3
  int v83; // w4
  int v84; // w5
  int v85; // w6
  int v86; // w7
  __int64 v87; // x0
  __int64 v88; // x8
  __int64 v89; // x24
  __int64 v90; // x21
  __int64 v91; // x22
  __int64 v92; // x23
  __int64 result; // x0
  char v94; // [xsp+0h] [xbp-80h]
  _QWORD v95[11]; // [xsp+8h] [xbp-78h] BYREF
  __int64 v96; // [xsp+60h] [xbp-20h]
  __int64 v97; // [xsp+68h] [xbp-18h]
  __int64 v98; // [xsp+70h] [xbp-10h]
  __int64 v99; // [xsp+78h] [xbp-8h]

  v99 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17 = *(_QWORD *)(a3 + 8);
  v97 = 0;
  v98 = 0;
  v96 = 0;
  memset(v95, 0, sizeof(v95));
  qdf_trace_msg(0x7Du, 8u, "%s: Tx reinject path", a4, a5, a6, a7, a8, a9, a10, a11, "dp_tx_reinject_handler");
  if ( a2 )
  {
    ++*(_QWORD *)(a2 + 464);
    v26 = *(_QWORD *)(a3 + 8);
    if ( (*(_BYTE *)(v26 + 68) & 4) != 0 )
      v27 = *(unsigned __int16 *)(v26 + 66);
    else
      v27 = 0;
    *(_QWORD *)(a2 + 472) += (unsigned int)(*(_DWORD *)(v26 + 112) + v27);
  }
  if ( *(_QWORD *)(a3 + 72) )
  {
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: extension descriptor should not be required for opt_dp_ctrl",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "dp_ipa_tx_opt_dp_ctrl_reinject");
    wlan_ipa_log_message(
      (int)"dp_ipa_tx_opt_dp_ctrl_reinject",
      (int)"extension descriptor should not be required for opt_dp_ctrl",
      v81,
      v82,
      v83,
      v84,
      v85,
      v86,
      v94);
    v87 = printk(
            &unk_9BB309,
            "0",
            "dp_ipa_tx_opt_dp_ctrl_reinject",
            "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_tx.c");
    dump_stack(v87);
  }
  if ( a13 == 8 )
  {
    ++dp_ipa_tx_opt_dp_ctrl_reinject_ctrl_pkt_reinject;
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: opt_dp_ctrl: tx pkt reinjected from fw, cnt: %d",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "dp_ipa_tx_opt_dp_ctrl_reinject");
    wlan_ipa_log_message(
      (int)"dp_ipa_tx_opt_dp_ctrl_reinject",
      (int)"opt_dp_ctrl: tx pkt reinjected from fw, cnt: %d",
      dp_ipa_tx_opt_dp_ctrl_reinject_ctrl_pkt_reinject,
      v28,
      v29,
      v30,
      v31,
      v32,
      v94);
    v33 = *(_QWORD *)(a3 + 8);
    v34 = *(_QWORD *)(a1 + 24);
    v35 = *(_QWORD *)(a3 + 40);
    v36 = *(unsigned __int16 *)(a3 + 16);
    v37 = *(int *)(v33 + 212);
    qdf_mem_dp_tx_skb_cnt_dec();
    qdf_mem_dp_tx_skb_dec(v37);
    qdf_mem_skb_total_dec(v37);
    if ( *(_BYTE *)(v34 + 624) == 1 && (_qdf_is_pp_nbuf(v33) & 1) != 0 && *(_QWORD *)(v33 + 40) )
    {
      is_pp_nbuf = *(_QWORD *)(v34 + 40);
      if ( (*(_BYTE *)(is_pp_nbuf + 844) & 0x40) == 0 )
        is_pp_nbuf = _dma_sync_single_for_cpu(is_pp_nbuf, v35);
    }
    else
    {
      is_pp_nbuf = dma_unmap_page_attrs(*(_QWORD *)(v34 + 40), v35, v36, 1, 0);
    }
    v79 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(a1 + 1664);
    if ( v79 )
    {
      v80 = *(unsigned __int8 *)(a3 + 48);
      if ( *((_DWORD *)v79 - 1) != -722450304 )
        __break(0x8228u);
      is_pp_nbuf = v79(a1, v80, v17);
    }
    goto LABEL_54;
  }
  if ( *(_DWORD *)(a2 + 64) )
  {
    is_pp_nbuf = _qdf_nbuf_unmap(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a2 + 24) + 8LL) + 24LL), *(_QWORD *)(a3 + 8), 1);
    v17 = *(_QWORD *)(a3 + 8);
    if ( !v17 )
      goto LABEL_54;
    goto LABEL_53;
  }
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a2 + 136);
    v40 = *(__int64 **)(a2 + 120);
    if ( !v40 )
      goto LABEL_43;
LABEL_21:
    while ( 1 )
    {
      v41 = *v40;
      if ( *v40 )
      {
        if ( *(__int16 *)(v41 + 8) != -1 && (*(_BYTE *)(v41 + 88) & 2) != 0 )
          break;
      }
LABEL_20:
      v40 = (__int64 *)v40[7];
      if ( !v40 )
        goto LABEL_43;
    }
    v42 = skb_copy(v17, 2080);
    if ( !v42 )
    {
      qdf_trace_msg(0x7Du, 8u, "%s: nbuf copy failed", v43, v44, v45, v46, v47, v48, v49, v50, "dp_tx_reinject_handler");
      goto LABEL_43;
    }
    v51 = (unsigned __int16 *)v42;
    qdf_mem_set(v95, 0x70u, 0);
    v52 = *(_QWORD *)(*(_QWORD *)(a2 + 24) + 8LL);
    BYTE4(v95[0]) = *(_BYTE *)(a2 + 59);
    v53 = *(_QWORD *)(v52 + 40);
    if ( *(_BYTE *)(v53 + 540) == 1 )
    {
      is_opt_wifi_dp_enabled = ipa_config_is_opt_wifi_dp_enabled();
      v63 = *(char **)(a2 + 24);
      if ( (is_opt_wifi_dp_enabled & 1) == 0 )
      {
        v65 = *v63;
        goto LABEL_35;
      }
      v53 = *(_QWORD *)(*((_QWORD *)v63 + 1) + 40LL);
    }
    if ( (wlan_cfg_is_lapb_enabled(v53) & 1) != 0 )
    {
      v64 = *(_QWORD *)(a2 + 24);
      if ( (*(_DWORD *)(v17 + 168) & 0xF000000) == 0xB000000 )
      {
        v65 = *(_BYTE *)(*(_QWORD *)(v64 + 8) + 7153LL) - 1;
        goto LABEL_35;
      }
      v66 = *(unsigned __int16 *)(v17 + 124);
      v67 = *(unsigned __int8 *)(*(_QWORD *)(v64 + 8) + 7153LL) - 1;
      v68 = v66 / v67;
    }
    else
    {
      v66 = *(unsigned __int16 *)(v17 + 124);
      v67 = *(unsigned __int8 *)(*(_QWORD *)(*(_QWORD *)(a2 + 24) + 8LL) + 7153LL);
      v68 = v66 / (unsigned int)v67;
    }
    v65 = v66 - v68 * v67;
LABEL_35:
    BYTE5(v95[0]) = v65;
    BYTE6(v96) = 0;
    v69 = dp_tx_send_msdu_single(a2, v51, (__int64)v95, 65534, 0, v55, v56, v57, v58, v59, v60, v61, v62);
    if ( v69 )
    {
      v78 = (__int64)v69;
      qdf_trace_msg(0x7Du, 8u, "%s: pkt send failed", v70, v71, v72, v73, v74, v75, v76, v77, "dp_tx_reinject_handler");
      _qdf_nbuf_free(v78);
    }
    goto LABEL_20;
  }
  raw_spin_lock_bh(a2 + 136);
  *(_QWORD *)(a2 + 144) |= 1uLL;
  v40 = *(__int64 **)(a2 + 120);
  if ( v40 )
    goto LABEL_21;
LABEL_43:
  v88 = *(_QWORD *)(a2 + 144);
  if ( (v88 & 1) != 0 )
  {
    *(_QWORD *)(a2 + 144) = v88 & 0xFFFFFFFFFFFFFFFELL;
    is_pp_nbuf = raw_spin_unlock_bh(a2 + 136);
  }
  else
  {
    is_pp_nbuf = raw_spin_unlock(a2 + 136);
  }
  v89 = *(_QWORD *)(a2 + 16);
  v90 = *(int *)(v17 + 112);
  v91 = *(_QWORD *)(v17 + 40);
  if ( *(_BYTE *)(v89 + 624) == 1 && (is_pp_nbuf = _qdf_is_pp_nbuf(v17), (is_pp_nbuf & 1) != 0) && *(_QWORD *)(v17 + 40) )
  {
    is_pp_nbuf = *(_QWORD *)(v89 + 40);
    if ( (*(_BYTE *)(is_pp_nbuf + 844) & 0x40) == 0 )
      is_pp_nbuf = _dma_sync_single_for_cpu(is_pp_nbuf, v91);
  }
  else if ( v91 )
  {
    v92 = *(int *)(v17 + 212);
    qdf_mem_dp_tx_skb_cnt_dec();
    qdf_mem_dp_tx_skb_dec(v92);
    qdf_mem_skb_total_dec(v92);
    is_pp_nbuf = dma_unmap_page_attrs(*(_QWORD *)(v89 + 40), v91, v90, 1, 0);
  }
  if ( v17 )
LABEL_53:
    is_pp_nbuf = _qdf_nbuf_free(v17);
LABEL_54:
  result = dp_tx_desc_release(is_pp_nbuf, a3, *(unsigned __int8 *)(a3 + 67));
  _ReadStatusReg(SP_EL0);
  return result;
}
