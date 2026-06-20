__int64 __fastcall dp_tx_process_htt_completion_be(
        __int64 result,
        __int64 a2,
        unsigned int *a3,
        unsigned int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v13; // x19
  unsigned int v14; // w8
  unsigned int v15; // w22
  __int64 v16; // x1
  __int64 v17; // x0
  int v18; // w8
  _BYTE *v20; // x27
  __int64 ref_by_id; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  unsigned int v31; // w8
  __int64 v32; // x21
  unsigned int v33; // w24
  __int64 v34; // x0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  __int64 v43; // x26
  unsigned __int64 v44; // x9
  __int64 v45; // x8
  unsigned __int64 v46; // x9
  __int64 v47; // x8
  char v48; // w10
  unsigned int v49; // w10
  unsigned int v50; // w2
  unsigned int v51; // w25
  __int64 v52; // x8
  __int64 v53; // x0
  __int64 v54; // x24
  __int64 v55; // x8
  int v56; // w9
  __int64 v57; // x0
  __int64 v58; // x21
  __int64 v59; // x22
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  __int64 v68; // x22
  __int64 v69; // x22
  int eapol_subtype; // w8
  __int64 v71; // x7
  __int64 v72; // [xsp+0h] [xbp-30h] BYREF
  __int64 v73; // [xsp+8h] [xbp-28h] BYREF
  __int64 v74; // [xsp+10h] [xbp-20h]
  __int64 v75; // [xsp+18h] [xbp-18h]
  __int64 v76; // [xsp+20h] [xbp-10h]
  __int64 v77; // [xsp+28h] [xbp-8h]

  v13 = result;
  v77 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = *a3;
  v75 = 0;
  v76 = 0;
  v73 = 0;
  v74 = 0;
  v15 = (v14 >> 13) & 0xF;
  v72 = 0;
  if ( v15 == 5 )
  {
    if ( (*(_BYTE *)(result + 20120) & 4) == 0 )
    {
      v57 = printk(
              &unk_AAA255,
              "expr",
              "__dp_assert_always_internal",
              "/proc/self/cwd/vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_internal.h");
      result = dump_stack(v57);
    }
    if ( (a3[4] & 0xFE) > 5 )
      goto LABEL_56;
    result = dp_vdev_get_ref_by_id(v13);
    if ( !result )
      goto LABEL_56;
    v16 = result;
    v17 = v13;
    goto LABEL_55;
  }
  v18 = *(_DWORD *)(a2 + 32);
  if ( !v18 )
  {
    v58 = jiffies;
    if ( dp_tx_process_htt_completion_be___last_ticks - jiffies + 125 < 0 )
    {
      result = qdf_trace_msg(
                 0x87u,
                 5u,
                 "%s: Descriptor freed in vdev_detach %d",
                 a5,
                 a6,
                 a7,
                 a8,
                 a9,
                 a10,
                 a11,
                 a12,
                 "dp_tx_process_htt_completion_be",
                 *(unsigned int *)(a2 + 36),
                 v72,
                 v73,
                 v74,
                 v75,
                 v76,
                 v77);
      dp_tx_process_htt_completion_be___last_ticks = v58;
    }
    goto LABEL_56;
  }
  if ( *(unsigned __int8 *)(a2 + 48) == 255 )
  {
    v59 = jiffies;
    if ( dp_tx_process_htt_completion_be___last_ticks_1 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x87u,
        5u,
        "%s: Invalid vdev_id %d",
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        "dp_tx_process_htt_completion_be",
        *(unsigned int *)(a2 + 36),
        v72,
        v73,
        v74,
        v75,
        v76,
        v77);
      v18 = *(_DWORD *)(a2 + 32);
      dp_tx_process_htt_completion_be___last_ticks_1 = v59;
    }
    goto LABEL_67;
  }
  v20 = *(_BYTE **)(a2 + 56);
  if ( !v20 )
  {
    qdf_trace_msg(
      0x87u,
      3u,
      "%s: The pdev in TX desc is NULL, dropped.",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "dp_tx_process_htt_completion_be",
      v72,
      v73,
      v74,
      v75,
      v76,
      v77);
    qdf_trace_msg(
      0x87u,
      3u,
      "%s: tx_status: %u",
      v60,
      v61,
      v62,
      v63,
      v64,
      v65,
      v66,
      v67,
      "dp_tx_process_htt_completion_be",
      v15);
LABEL_66:
    v18 = *(_DWORD *)(a2 + 32);
LABEL_67:
    v32 = 0;
    *(_DWORD *)(a2 + 32) = v18 | 0x1000;
    goto LABEL_28;
  }
  if ( v20[16] == 1 )
  {
    v68 = jiffies;
    if ( dp_tx_process_htt_completion_be___last_ticks_5 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x87u,
        5u,
        "%s: pdev in down state %d",
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        "dp_tx_process_htt_completion_be",
        *(unsigned int *)(a2 + 36),
        v72,
        v73,
        v74,
        v75,
        v76,
        v77);
      v18 = *(_DWORD *)(a2 + 32);
      dp_tx_process_htt_completion_be___last_ticks_5 = v68;
    }
    goto LABEL_67;
  }
  ref_by_id = dp_vdev_get_ref_by_id(result);
  if ( !ref_by_id )
  {
    v69 = jiffies;
    if ( dp_tx_process_htt_completion_be___last_ticks_7 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x87u,
        5u,
        "%s: Unable to get vdev ref  %d",
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        "dp_tx_process_htt_completion_be",
        *(unsigned int *)(a2 + 36),
        v72,
        v73,
        v74,
        v75,
        v76,
        v77);
      dp_tx_process_htt_completion_be___last_ticks_7 = v69;
    }
    goto LABEL_66;
  }
  v31 = a3[3];
  v32 = ref_by_id;
  if ( (v31 & 0x200000) != 0 )
    v33 = v31 & 0x1FFFFF;
  else
    v33 = 0x1FFFFF;
  HIDWORD(v76) = v33;
  v34 = dp_txrx_peer_get_ref_by_id(v13, v33, &v72);
  if ( v34 )
  {
    v43 = v34;
    if ( _qdf_nbuf_data_is_ipv4_eapol_pkt(*(_QWORD *)(*(_QWORD *)(a2 + 8) + 224LL)) )
    {
      eapol_subtype = (unsigned __int8)_qdf_nbuf_data_get_eapol_subtype(*(_QWORD *)(*(_QWORD *)(a2 + 8) + 224LL));
      dp_tx_update_eapol_comp_status_stats(
        v13,
        v32,
        *(_QWORD *)(a2 + 8),
        v43,
        0,
        v15,
        (unsigned int)(eapol_subtype - 63) < 0xFFFFFFFE,
        v71,
        v72,
        v73,
        v74,
        v75,
        v76,
        v77);
    }
    v34 = dp_txrx_peer_unref_delete(v72, 3);
  }
  if ( (int)v15 > 2 )
  {
    if ( v15 == 3 )
    {
      dp_tx_reinject_handler(v13, v32, a2, a3, a3[1] & 0xF);
    }
    else
    {
      if ( v15 != 4 )
      {
        if ( v15 == 6 )
          ++*(_DWORD *)(v32 + 772);
        else
          qdf_trace_msg(
            0x87u,
            2u,
            "%s: Invalid HTT tx_status %d\n",
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            "dp_tx_process_htt_completion_be",
            v15,
            v72);
LABEL_28:
        dp_tx_comp_free_buf(v13, a2, 0);
        result = dp_tx_desc_release(v13, a2, *(unsigned __int8 *)(a2 + 67));
        if ( !v32 )
          goto LABEL_56;
        goto LABEL_54;
      }
      dp_tx_inspect_handler(v13, v32, a2, a3);
    }
LABEL_54:
    v17 = v13;
    v16 = v32;
LABEL_55:
    result = dp_vdev_unref_delete(v17, v16, 3);
LABEL_56:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  if ( v15 == 1 && (*(_BYTE *)(a2 + 34) & 0x20) != 0 )
  {
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: opt_dp_ctrl: pkt dropped in fw, unvote clk",
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      "dp_tx_process_htt_completion_be");
    v34 = ipa_opt_dpath_disable_clk_req(*(_QWORD *)(v13 + 16));
  }
  v44 = a3[2];
  v45 = v44 & 0xFFFFFF;
  v46 = v44 >> 24;
  v47 = (v45 << 32) | 3;
  v48 = *((_BYTE *)a3 + 15);
  v74 = v47;
  if ( (v48 & 0x10) != 0 )
  {
    v47 |= (unsigned __int64)((a3[1] >> 5) & 0x7F) << 56;
    v74 = v47;
  }
  v49 = a3[4];
  v75 = v46 | 0x300;
  LODWORD(v76) = v49;
  if ( v15 )
  {
    if ( v15 == 2 )
      v47 |= 0x4000uLL;
    else
      v47 |= 0x2000uLL;
  }
  v74 = v47;
  if ( (v33 & 0x1F0000) > 0x80000 )
    v50 = 8;
  else
    v50 = HIWORD(v33);
  if ( (unsigned __int8)a4 <= 4u && v50 < 0xA )
  {
    v51 = v50;
    if ( (v20[95938] & 1) != 0 || *(_BYTE *)(v32 + 46141) )
      dp_tx_compute_delay(v32, a2);
    v52 = (__int64)&v20[6768 * (unsigned __int8)a4 + 8840 + 752 * v51 + 8 * v15];
    ++*(_QWORD *)(v52 + 696);
    v53 = dp_txrx_peer_get_ref_by_id(v13, v33 & 0x1FFF | (((v33 >> 13) & 1) << *(_DWORD *)(v13 + 13328)), &v72);
    v54 = v53;
    if ( v53 )
    {
      v55 = *(_QWORD *)(a2 + 8);
      if ( (*(_BYTE *)(v55 + 68) & 4) != 0 )
        v56 = *(unsigned __int16 *)(v55 + 66);
      else
        v56 = 0;
      dp_tx_update_peer_basic_stats(v53, (unsigned int)(*(_DWORD *)(v55 + 112) + v56), v15, v20[17] & 1);
    }
    dp_tx_comp_process_tx_status(v13, a2, &v73, v54, a4);
    dp_tx_comp_process_desc(v13, a2, &v73, v54);
    if ( (*(_BYTE *)(a2 + 32) & 0x40) != 0 )
      dp_tx_comp_free_buf(v13, a2, 0);
    dp_tx_desc_release(v13, a2, *(unsigned __int8 *)(a2 + 67));
    if ( v54 )
      dp_txrx_peer_unref_delete(v72, 3);
    goto LABEL_54;
  }
  __break(0x5512u);
  return dp_vdev_get_ref_by_id(v34);
}
