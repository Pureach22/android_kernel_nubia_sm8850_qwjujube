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
  __int64 v40; // x25
  __int64 *v41; // x8
  __int64 v42; // x8
  __int64 v43; // x0
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  __int64 v52; // x24
  __int64 v53; // x8
  __int64 v54; // x0
  char is_opt_wifi_dp_enabled; // w0
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  char *v64; // x8
  __int64 v65; // x8
  char v66; // w8
  int v67; // w9
  int v68; // w8
  int v69; // w10
  __int64 *v70; // x0
  double v71; // d0
  double v72; // d1
  double v73; // d2
  double v74; // d3
  double v75; // d4
  double v76; // d5
  double v77; // d6
  double v78; // d7
  __int64 v79; // x24
  __int64 (__fastcall *v80)(__int64, __int64, __int64); // x8
  __int64 v81; // x1
  int v82; // w2
  int v83; // w3
  int v84; // w4
  int v85; // w5
  int v86; // w6
  int v87; // w7
  __int64 v88; // x0
  __int64 v89; // x8
  __int64 v90; // x24
  __int64 v91; // x21
  __int64 v92; // x22
  __int64 v93; // x23
  __int64 result; // x0
  char v95; // [xsp+0h] [xbp-80h]
  _QWORD v96[11]; // [xsp+8h] [xbp-78h] BYREF
  __int64 v97; // [xsp+60h] [xbp-20h]
  __int64 v98; // [xsp+68h] [xbp-18h]
  __int64 v99; // [xsp+70h] [xbp-10h]
  __int64 v100; // [xsp+78h] [xbp-8h]

  v100 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17 = *(_QWORD *)(a3 + 8);
  v98 = 0;
  v99 = 0;
  v97 = 0;
  memset(v96, 0, sizeof(v96));
  qdf_trace_msg(0x7Du, 8u, "%s: Tx reinject path", a4, a5, a6, a7, a8, a9, a10, a11, "dp_tx_reinject_handler");
  if ( a2 )
  {
    ++*(_QWORD *)(a2 + 472);
    v26 = *(_QWORD *)(a3 + 8);
    if ( (*(_BYTE *)(v26 + 68) & 4) != 0 )
      v27 = *(unsigned __int16 *)(v26 + 66);
    else
      v27 = 0;
    *(_QWORD *)(a2 + 480) += (unsigned int)(*(_DWORD *)(v26 + 112) + v27);
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
      v82,
      v83,
      v84,
      v85,
      v86,
      v87,
      v95);
    v88 = printk(
            &unk_AAA255,
            "0",
            "dp_ipa_tx_opt_dp_ctrl_reinject",
            "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_tx.c");
    dump_stack(v88);
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
      v95);
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
    v80 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(a1 + 1712);
    if ( v80 )
    {
      v81 = *(unsigned __int8 *)(a3 + 48);
      if ( *((_DWORD *)v80 - 1) != -722450304 )
        __break(0x8228u);
      is_pp_nbuf = v80(a1, v81, v17);
    }
    goto LABEL_57;
  }
  if ( *(_DWORD *)(a2 + 64) )
  {
    is_pp_nbuf = _qdf_nbuf_unmap(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a2 + 24) + 8LL) + 24LL), *(_QWORD *)(a3 + 8), 1);
    v17 = *(_QWORD *)(a3 + 8);
    if ( !v17 )
      goto LABEL_57;
    goto LABEL_56;
  }
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a2 + 144);
    v40 = *(_QWORD *)(a2 + 128);
    if ( !v40 )
      goto LABEL_46;
    while ( 1 )
    {
LABEL_21:
      if ( *(_DWORD *)(v40 + 408) != 1 || (v41 = *(__int64 **)(v40 + 416)) == nullptr )
        v41 = (__int64 *)v40;
      v42 = *v41;
      if ( !v42 || *(__int16 *)(v42 + 8) == -1 || (*(_BYTE *)(v42 + 88) & 2) == 0 )
        goto LABEL_20;
      v43 = skb_copy(v17, 2080);
      if ( !v43 )
      {
        qdf_trace_msg(
          0x7Du,
          8u,
          "%s: nbuf copy failed",
          v44,
          v45,
          v46,
          v47,
          v48,
          v49,
          v50,
          v51,
          "dp_tx_reinject_handler");
        goto LABEL_46;
      }
      v52 = v43;
      qdf_mem_set(v96, 0x70u, 0);
      v53 = *(_QWORD *)(*(_QWORD *)(a2 + 24) + 8LL);
      BYTE4(v96[0]) = *(_BYTE *)(a2 + 59);
      v54 = *(_QWORD *)(v53 + 40);
      if ( *(_BYTE *)(v54 + 540) == 1 )
      {
        is_opt_wifi_dp_enabled = ipa_config_is_opt_wifi_dp_enabled();
        v64 = *(char **)(a2 + 24);
        if ( (is_opt_wifi_dp_enabled & 1) == 0 )
        {
          v66 = *v64;
          goto LABEL_38;
        }
        v54 = *(_QWORD *)(*((_QWORD *)v64 + 1) + 40LL);
      }
      if ( (wlan_cfg_is_lapb_enabled(v54) & 1) != 0 )
      {
        v65 = *(_QWORD *)(a2 + 24);
        if ( (*(_DWORD *)(v17 + 168) & 0xF000000) == 0xB000000 )
        {
          v66 = *(_BYTE *)(*(_QWORD *)(v65 + 8) + 7201LL) - 1;
          goto LABEL_38;
        }
        v67 = *(unsigned __int16 *)(v17 + 124);
        v68 = *(unsigned __int8 *)(*(_QWORD *)(v65 + 8) + 7201LL) - 1;
        v69 = v67 / v68;
      }
      else
      {
        v67 = *(unsigned __int16 *)(v17 + 124);
        v68 = *(unsigned __int8 *)(*(_QWORD *)(*(_QWORD *)(a2 + 24) + 8LL) + 7201LL);
        v69 = v67 / (unsigned int)v68;
      }
      v66 = v67 - v69 * v68;
LABEL_38:
      BYTE5(v96[0]) = v66;
      BYTE6(v97) = 0;
      v70 = dp_tx_send_msdu_single(a2, v52, (__int64)v96, 65534, 0, v56, v57, v58, v59, v60, v61, v62, v63);
      if ( v70 )
      {
        v79 = (__int64)v70;
        qdf_trace_msg(
          0x7Du,
          8u,
          "%s: pkt send failed",
          v71,
          v72,
          v73,
          v74,
          v75,
          v76,
          v77,
          v78,
          "dp_tx_reinject_handler");
        _qdf_nbuf_free(v79);
      }
LABEL_20:
      v40 = *(_QWORD *)(v40 + 56);
      if ( !v40 )
        goto LABEL_46;
    }
  }
  raw_spin_lock_bh(a2 + 144);
  *(_QWORD *)(a2 + 152) |= 1uLL;
  v40 = *(_QWORD *)(a2 + 128);
  if ( v40 )
    goto LABEL_21;
LABEL_46:
  v89 = *(_QWORD *)(a2 + 152);
  if ( (v89 & 1) != 0 )
  {
    *(_QWORD *)(a2 + 152) = v89 & 0xFFFFFFFFFFFFFFFELL;
    is_pp_nbuf = raw_spin_unlock_bh(a2 + 144);
  }
  else
  {
    is_pp_nbuf = raw_spin_unlock(a2 + 144);
  }
  v90 = *(_QWORD *)(a2 + 16);
  v91 = *(int *)(v17 + 112);
  v92 = *(_QWORD *)(v17 + 40);
  if ( *(_BYTE *)(v90 + 624) == 1 && (is_pp_nbuf = _qdf_is_pp_nbuf(v17), (is_pp_nbuf & 1) != 0) && *(_QWORD *)(v17 + 40) )
  {
    is_pp_nbuf = *(_QWORD *)(v90 + 40);
    if ( (*(_BYTE *)(is_pp_nbuf + 844) & 0x40) == 0 )
      is_pp_nbuf = _dma_sync_single_for_cpu(is_pp_nbuf, v92);
  }
  else if ( v92 )
  {
    v93 = *(int *)(v17 + 212);
    qdf_mem_dp_tx_skb_cnt_dec();
    qdf_mem_dp_tx_skb_dec(v93);
    qdf_mem_skb_total_dec(v93);
    is_pp_nbuf = dma_unmap_page_attrs(*(_QWORD *)(v90 + 40), v92, v91, 1, 0);
  }
  if ( v17 )
LABEL_56:
    is_pp_nbuf = _qdf_nbuf_free(v17);
LABEL_57:
  result = dp_tx_desc_release(is_pp_nbuf, a3, *(unsigned __int8 *)(a3 + 67));
  _ReadStatusReg(SP_EL0);
  return result;
}
