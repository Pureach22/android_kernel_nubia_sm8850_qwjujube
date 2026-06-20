__int64 __fastcall sme_rrm_send_chan_load_report_xmit_ind(__int64 a1, __int64 a2, unsigned int a3, char a4)
{
  unsigned __int64 v4; // x24
  __int64 result; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x8
  __int64 v18; // x19
  __int64 v19; // x23
  unsigned int v20; // w22
  unsigned int v21; // w24
  const char *v22; // x2
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  unsigned __int16 *bonded_chan_entry; // x0
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  unsigned int v40; // w23
  __int64 v41; // x4
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  unsigned __int16 *v50; // x0
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  unsigned __int8 v59; // w24
  unsigned __int8 rx_clear_count; // w0
  const char *v61; // x2
  __int64 v62; // x4
  __int64 v63; // x5

  v4 = *(unsigned __int8 *)(a2 + 9);
  if ( v4 >= 6 )
  {
    __break(0x5512u);
    return wma_post_ctrl_msg(a1, a2);
  }
  result = _qdf_mem_malloc(0x30u, "sme_rrm_send_chan_load_report_xmit_ind", 746);
  if ( result )
  {
    v17 = a1 + 544LL * (unsigned int)v4;
    *(_BYTE *)(result + 32) = a4 & 1;
    *(_DWORD *)result = 3150896;
    v18 = result;
    *(_BYTE *)(result + 4) = v4;
    v19 = v17 + 17416;
    *(_WORD *)(result + 12) = *(_WORD *)(v17 + 17416);
    *(_WORD *)(result + 16) = *(_WORD *)(v17 + 17530);
    *(_BYTE *)(result + 14) = *(_BYTE *)(v17 + 17424);
    *(_BYTE *)(result + 15) = *(_BYTE *)(v17 + 17432);
    *(_QWORD *)(result + 24) = *(_QWORD *)(v17 + 17448);
    v20 = *(_DWORD *)(v17 + 17436);
    v21 = *(_DWORD *)(v17 + 17440);
    switch ( v21 )
    {
      case 0u:
        qdf_trace_msg(
          0x34u,
          8u,
          "%s: cw %d: start_freq %d, end_freq %d",
          v9,
          v10,
          v11,
          v12,
          v13,
          v14,
          v15,
          v16,
          "sme_rrm_send_chan_load_report_xmit_ind",
          0,
          v20,
          v20);
        v40 = v20;
        goto LABEL_17;
      case 7u:
        if ( (*(_BYTE *)(v17 + 17456) & 1) == 0 )
        {
          v22 = "%s: is_bw_ind_element is false";
          goto LABEL_23;
        }
        qdf_mem_copy((void *)(result + 36), (const void *)(v17 + 17456), 8u);
        bonded_chan_entry = wlan_reg_get_bonded_chan_entry(
                              v20,
                              *(unsigned __int8 *)(v19 + 41),
                              *(_DWORD *)(v19 + 44),
                              v23,
                              v24,
                              v25,
                              v26,
                              v27,
                              v28,
                              v29,
                              v30);
        if ( bonded_chan_entry )
        {
          v40 = *bonded_chan_entry;
          v20 = bonded_chan_entry[1];
          v41 = 7;
          goto LABEL_15;
        }
        v61 = "%s: vdev %d : range is null for freq %d";
        v62 = (unsigned __int8)a3;
        v63 = v20;
        break;
      case 8u:
        v22 = "%s: Invalid scanned_ch_width";
LABEL_23:
        qdf_trace_msg(0x34u, 8u, v22, v9, v10, v11, v12, v13, v14, v15, v16, "sme_rrm_send_chan_load_report_xmit_ind");
        return _qdf_mem_free(v18);
      default:
        if ( *(_BYTE *)(v17 + 17464) )
        {
          qdf_mem_copy((void *)(result + 44), (const void *)(v17 + 17464), 4u);
          v21 = *(unsigned __int8 *)(v19 + 49);
          qdf_trace_msg(
            0x34u,
            8u,
            "%s: Fill wide_bw_chan_switch IE for cw:%d",
            v42,
            v43,
            v44,
            v45,
            v46,
            v47,
            v48,
            v49,
            "sme_rrm_send_chan_load_report_xmit_ind",
            *(unsigned __int8 *)(v19 + 49));
        }
        v50 = wlan_reg_get_bonded_chan_entry(v20, v21, 0, v9, v10, v11, v12, v13, v14, v15, v16);
        if ( v50 )
        {
          v40 = *v50;
          v20 = v50[1];
          v41 = v21;
LABEL_15:
          qdf_trace_msg(
            0x34u,
            8u,
            "%s: cw %d: start_freq %d, end_freq %d",
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            "sme_rrm_send_chan_load_report_xmit_ind",
            v41,
            v40,
            v20);
          if ( v40 > v20 )
          {
            v59 = 0;
LABEL_21:
            *(_BYTE *)(v18 + 18) = v59;
            qdf_trace_msg(
              0x34u,
              8u,
              "%s: SME Sending CHAN_LOAD_REPORT_RESP_XMIT_IND to PE",
              v51,
              v52,
              v53,
              v54,
              v55,
              v56,
              v57,
              v58,
              "sme_rrm_send_chan_load_report_xmit_ind");
            return umac_send_mb_message_to_mac(v18);
          }
LABEL_17:
          v59 = 0;
          do
          {
            rx_clear_count = wlan_cp_stats_get_rx_clear_count(*(_QWORD *)(a1 + 21552), a3, v40);
            v40 += 20;
            if ( v59 <= (unsigned int)rx_clear_count )
              v59 = rx_clear_count;
          }
          while ( v40 <= v20 );
          goto LABEL_21;
        }
        v61 = "%s: range is NULL for freq %d, ch_width %d";
        v62 = v20;
        v63 = v21;
        break;
    }
    qdf_trace_msg(
      0x34u,
      8u,
      v61,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      "sme_rrm_send_chan_load_report_xmit_ind",
      v62,
      v63);
    return _qdf_mem_free(v18);
  }
  return result;
}
