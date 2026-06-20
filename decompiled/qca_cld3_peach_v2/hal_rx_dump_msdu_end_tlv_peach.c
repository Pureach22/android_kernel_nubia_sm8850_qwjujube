__int64 __fastcall hal_rx_dump_msdu_end_tlv_peach(
        __int64 result,
        unsigned __int8 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v11; // x23
  __int64 v12; // x20
  unsigned int v13; // w10
  __int64 v14; // x23
  unsigned __int64 v15; // x8
  __int64 v16; // x23
  unsigned int v17; // w10
  unsigned __int64 v18; // x8
  unsigned __int64 v19; // x9
  __int64 v20; // x23
  unsigned int v21; // w9
  unsigned __int64 v22; // x8
  __int64 v23; // x23
  unsigned __int64 v24; // x9
  unsigned __int64 v25; // x8
  __int64 v26; // x23
  unsigned __int64 v27; // x8
  __int64 v28; // x21
  unsigned __int64 v29; // x8
  unsigned int v30; // w9
  __int64 v31; // [xsp+0h] [xbp-90h]
  __int64 v32; // [xsp+8h] [xbp-88h]
  __int64 v33; // [xsp+10h] [xbp-80h]
  __int64 v34; // [xsp+18h] [xbp-78h]
  __int64 v35; // [xsp+20h] [xbp-70h]
  __int64 v36; // [xsp+28h] [xbp-68h]
  __int64 v37; // [xsp+30h] [xbp-60h]
  __int64 v38; // [xsp+38h] [xbp-58h]
  __int64 v39; // [xsp+40h] [xbp-50h]
  __int64 v40; // [xsp+48h] [xbp-48h]
  __int64 v41; // [xsp+50h] [xbp-40h]
  __int64 v42; // [xsp+58h] [xbp-38h]
  __int64 v43; // [xsp+60h] [xbp-30h]
  __int64 v44; // [xsp+68h] [xbp-28h]
  __int64 v45; // [xsp+70h] [xbp-20h]
  __int64 v46; // [xsp+78h] [xbp-18h]

  v11 = jiffies;
  v12 = result;
  if ( hal_rx_dump_msdu_end_tlv_peach___last_ticks - jiffies + 125 < 0 )
  {
    v13 = *(_DWORD *)(result + 12);
    result = qdf_trace_msg(
               0x46u,
               a2,
               "%s: rx_msdu_end tlv (1/7)- rxpcu_mpdu_filter_in_category :%x sw_frame_group_id :%x reserved_0 :%x phy_ppd"
               "u_id :%x ip_hdr_chksum :%x reported_mpdu_length :%x reserved_1a :%x ipv6_options_crc :%x da_offset :%x sa"
               "_offset :%x da_offset_valid :%x sa_offset_valid :%x reserved_5a :%x l3_type :%x",
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               "hal_rx_dump_msdu_end_tlv_peach",
               *(_QWORD *)result & 3LL,
               ((unsigned int)*(_QWORD *)result >> 2) & 0x7F,
               (unsigned __int16)*(_QWORD *)result >> 9,
               WORD1(*(_QWORD *)result),
               (unsigned __int16)WORD2(*(_QWORD *)result),
               HIWORD(*(_QWORD *)result) & 0x3FFF,
               *(_QWORD *)result >> 62,
               *(_DWORD *)(result + 8),
               v13 & 0x3F,
               (v13 >> 6) & 0x3F,
               (v13 >> 12) & 1,
               (v13 >> 13) & 1,
               (unsigned __int16)v13 >> 14,
               HIWORD(v13));
    hal_rx_dump_msdu_end_tlv_peach___last_ticks = v11;
  }
  v14 = jiffies;
  if ( hal_rx_dump_msdu_end_tlv_peach___last_ticks_15 - jiffies + 125 < 0 )
  {
    v15 = *(_QWORD *)(v12 + 12);
    LODWORD(v40) = (unsigned __int16)*(_DWORD *)(v12 + 20);
    LODWORD(v39) = v15 >> 63;
    LODWORD(v38) = (v15 & 0x4000000000000000LL) != 0;
    LODWORD(v37) = (v15 & 0x2000000000000000LL) != 0;
    LODWORD(v36) = (v15 & 0x1000000000000000LL) != 0;
    LODWORD(v35) = (v15 >> 58) & 3;
    LODWORD(v34) = (v15 & 0x200000000000000LL) != 0;
    LODWORD(v33) = HIBYTE(v15) & 1;
    LODWORD(v32) = (v15 >> 55) & 1;
    LODWORD(v31) = (v15 >> 51) & 0xF;
    result = qdf_trace_msg(
               0x46u,
               a2,
               "%s: rx_msdu_end tlv (2/7)- sa_sw_peer_id :%x sa_idx_timeout :%x da_idx_timeout :%x to_ds :%x tid :%x sa_i"
               "s_valid :%x da_is_valid :%x da_is_mcbc :%x l3_header_padding :%x first_msdu :%x last_msdu :%x fr_ds :%x i"
               "p_chksum_fail_copy :%x sa_idx :%x da_idx_or_sw_peer_id :%x",
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               "hal_rx_dump_msdu_end_tlv_peach",
               WORD2(v15),
               HIWORD(v15) & 1,
               (v15 >> 49) & 1,
               (v15 >> 50) & 1,
               v31,
               v32,
               v33,
               v34,
               v35,
               v36,
               v37,
               v38,
               v39,
               v40,
               HIWORD(*(_DWORD *)(v12 + 20)));
    hal_rx_dump_msdu_end_tlv_peach___last_ticks_15 = v14;
  }
  v16 = jiffies;
  if ( hal_rx_dump_msdu_end_tlv_peach___last_ticks_17 - jiffies + 125 < 0 )
  {
    v17 = *(_DWORD *)(v12 + 36);
    v18 = *(_QWORD *)(v12 + 20);
    v19 = *(_QWORD *)(v12 + 28);
    LODWORD(v41) = (v17 >> 11) & 1;
    LODWORD(v40) = (v17 >> 10) & 1;
    LODWORD(v39) = (v17 >> 9) & 1;
    LODWORD(v38) = (v17 >> 8) & 1;
    LODWORD(v37) = (unsigned __int8)v17;
    LODWORD(v36) = HIWORD(v19);
    LODWORD(v35) = WORD2(v19);
    LODWORD(v34) = v19;
    LODWORD(v33) = v18 >> 63;
    LODWORD(v32) = (v18 & 0x4000000000000000LL) != 0;
    LODWORD(v31) = (v18 & 0x2000000000000000LL) != 0;
    result = qdf_trace_msg(
               0x46u,
               a2,
               "%s: rx_msdu_end tlv (3/7)- msdu_drop :%x reo_destination_indication :%x flow_idx :%x use_ppe :%x vlan_cta"
               "g_stripped :%x vlan_stag_stripped :%x fragment_flag :%x fse_metadata :%x cce_metadata :%x tcp_udp_chksum "
               ":%x aggregation_count :%x flow_aggregation_continuation :%x fisa_timeout :%x tcp_udp_chksum_fail_copy :%x"
               " msdu_limit_error :%x flow_idx_timeout :%x flow_idx_invalid :%x cce_match :%x amsdu_parser_error :%x cumu"
               "lative_ip_length :%x ",
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               "hal_rx_dump_msdu_end_tlv_peach",
               HIDWORD(v18) & 1,
               (v18 >> 33) & 0x1F,
               (v18 >> 38) & 0xFFFFF,
               (v18 >> 58) & 1,
               v31,
               v32,
               v33,
               v34,
               v35,
               v36,
               v37,
               v38,
               v39,
               v40,
               v41,
               (v17 >> 12) & 1,
               (v17 >> 13) & 1,
               (v17 >> 14) & 1,
               (v17 >> 15) & 1,
               HIWORD(v17));
    hal_rx_dump_msdu_end_tlv_peach___last_ticks_17 = v16;
  }
  v20 = jiffies;
  if ( hal_rx_dump_msdu_end_tlv_peach___last_ticks_19 - jiffies + 125 < 0 )
  {
    v21 = *(_DWORD *)(v12 + 44);
    v22 = *(_QWORD *)(v12 + 36);
    LODWORD(v44) = (v21 >> 20) & 1;
    LODWORD(v43) = (v21 >> 19) & 1;
    LODWORD(v42) = (v21 >> 17) & 3;
    LODWORD(v41) = HIWORD(v21) & 1;
    LODWORD(v46) = (v21 >> 22) & 1;
    LODWORD(v45) = (v21 >> 21) & 1;
    LODWORD(v40) = (v21 >> 15) & 1;
    LODWORD(v39) = (v21 >> 14) & 1;
    LODWORD(v38) = (v21 >> 13) & 1;
    LODWORD(v37) = (v21 >> 12) & 1;
    LODWORD(v36) = (v21 >> 11) & 1;
    LODWORD(v35) = (v21 >> 10) & 1;
    LODWORD(v34) = (v21 >> 8) & 3;
    LODWORD(v33) = (unsigned __int8)v21;
    LODWORD(v32) = HIBYTE(v22);
    LODWORD(v31) = (v22 >> 55) & 1;
    result = qdf_trace_msg(
               0x46u,
               a2,
               "%s: rx_msdu_end tlv (4/7)- msdu_length :%x stbc :%x ipsec_esp :%x l3_offset :%x ipsec_ah :%x l4_offset :%"
               "x msdu_number :%x decap_format :%x ipv4_proto :%x ipv6_proto :%x tcp_proto :%x udp_proto :%x ip_frag :%x "
               "tcp_only_ack :%x da_is_bcast_mcast :%x toeplitz_hash_sel :%x ip_fixed_header_valid :%x ip_extn_header_val"
               "id :%x tcp_udp_header_valid :%x mesh_control_present :%x ldpc :%x ip4_protocol_ip6_next_header :%x ",
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               "hal_rx_dump_msdu_end_tlv_peach",
               HIDWORD(v22) & 0x3FFF,
               (v22 >> 46) & 1,
               (v22 >> 47) & 1,
               HIWORD(v22) & 0x7F,
               v31,
               v32,
               v33,
               v34,
               v35,
               v36,
               v37,
               v38,
               v39,
               v40,
               v41,
               v42,
               v43,
               v44,
               v45,
               v46,
               (v21 >> 23) & 1,
               HIBYTE(v21));
    hal_rx_dump_msdu_end_tlv_peach___last_ticks_19 = v20;
  }
  v23 = jiffies;
  if ( hal_rx_dump_msdu_end_tlv_peach___last_ticks_21 - jiffies + 125 < 0 )
  {
    v24 = *(_QWORD *)(v12 + 52);
    v25 = *(_QWORD *)(v12 + 44);
    LODWORD(v41) = (v24 >> 37) & 1;
    LODWORD(v38) = (v24 >> 34) & 1;
    LODWORD(v40) = (v24 >> 36) & 1;
    LODWORD(v39) = (v24 >> 35) & 1;
    LODWORD(v37) = (v24 >> 33) & 1;
    LODWORD(v36) = BYTE4(v24) & 1;
    LODWORD(v35) = v24;
    LODWORD(v34) = v25 >> 63;
    LODWORD(v33) = HIBYTE(v25) & 0x7F;
    LODWORD(v32) = (v25 >> 53) & 7;
    LODWORD(v31) = (v25 >> 50) & 7;
    result = qdf_trace_msg(
               0x46u,
               a2,
               "%s: rx_msdu_end tlv (5/7)- user_rssi :%x pkt_type :%x sgi :%x rate_mcs :%x receive_bandwidth :%x receptio"
               "n_type :%x mimo_ss_bitmap :%x msdu_done_copy :%x flow_id_toeplitz :%xfirst_mpdu :%x reserved_30a :%x mcas"
               "t_bcast :%x ast_index_not_found :%x ast_index_timeout :%x power_mgmt :%x ",
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               "hal_rx_dump_msdu_end_tlv_peach",
               BYTE4(v25),
               (v25 >> 40) & 0xF,
               (v25 >> 44) & 3,
               (v25 >> 46) & 0xF,
               v31,
               v32,
               v33,
               v34,
               v35,
               v36,
               v37,
               v38,
               v39,
               v40,
               v41);
    hal_rx_dump_msdu_end_tlv_peach___last_ticks_21 = v23;
  }
  v26 = jiffies;
  if ( hal_rx_dump_msdu_end_tlv_peach___last_ticks_23 - jiffies + 125 < 0 )
  {
    v27 = *(_QWORD *)(v12 + 52);
    LODWORD(v42) = (v27 >> 53) & 1;
    LODWORD(v41) = (v27 >> 52) & 1;
    LODWORD(v40) = (v27 >> 51) & 1;
    LODWORD(v43) = (v27 >> 54) & 1;
    LODWORD(v39) = (v27 >> 50) & 1;
    LODWORD(v38) = (v27 >> 49) & 1;
    LODWORD(v37) = HIWORD(v27) & 1;
    LODWORD(v36) = (v27 >> 47) & 1;
    LODWORD(v35) = (v27 >> 46) & 1;
    LODWORD(v34) = (v27 >> 45) & 1;
    LODWORD(v33) = (v27 >> 44) & 1;
    LODWORD(v32) = (v27 >> 43) & 1;
    LODWORD(v31) = (v27 >> 42) & 1;
    result = qdf_trace_msg(
               0x46u,
               a2,
               "%s: rx_msdu_end tlv (6/7)- non_qos :%x null_data :%x mgmt_type :%x ctrl_type :%x more_data :%x eosp :%x a"
               "_msdu_error :%x reserved_30b :%x order :%x wifi_parser_error :%x overflow_err :%x msdu_length_err :%x tcp"
               "_udp_chksum_fail :%x ip_chksum_fail :%x sa_idx_invalid :%x da_idx_invalid :%x amsdu_addr_mismatch :%x ",
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               "hal_rx_dump_msdu_end_tlv_peach",
               (v27 >> 38) & 1,
               (v27 >> 39) & 1,
               (v27 >> 40) & 1,
               (v27 >> 41) & 1,
               v31,
               v32,
               v33,
               v34,
               v35,
               v36,
               v37,
               v38,
               v39,
               v40,
               v41,
               v42,
               v43);
    hal_rx_dump_msdu_end_tlv_peach___last_ticks_23 = v26;
  }
  v28 = jiffies;
  if ( hal_rx_dump_msdu_end_tlv_peach___last_ticks_25 - jiffies + 125 < 0 )
  {
    v29 = *(_QWORD *)(v12 + 52);
    v30 = *(_DWORD *)(v12 + 60);
    LODWORD(v39) = (v30 >> 14) & 0x1FFFF;
    LODWORD(v40) = v30 >> 31;
    LODWORD(v38) = (v30 >> 13) & 1;
    LODWORD(v37) = (v30 >> 10) & 7;
    LODWORD(v36) = v30 & 0x3FF;
    LODWORD(v35) = v29 >> 63;
    LODWORD(v34) = (v29 & 0x4000000000000000LL) != 0;
    LODWORD(v33) = (v29 & 0x2000000000000000LL) != 0;
    LODWORD(v32) = (v29 & 0x1000000000000000LL) != 0;
    LODWORD(v31) = (v29 & 0x800000000000000LL) != 0;
    result = qdf_trace_msg(
               0x46u,
               a2,
               "%s: rx_msdu_end tlv (7/7)- rx_in_tx_decrypt_byp :%x encrypt_required :%x directed :%x buffer_fragment :%x"
               " mpdu_length_err :%x tkip_mic_err :%x decrypt_err :%x unencrypted_frame_err :%x fcs_err :%x reserved_31a "
               ":%x decrypt_status_code :%x rx_bitmap_not_updated :%x reserved_31b :%x msdu_done :%x",
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               "hal_rx_dump_msdu_end_tlv_peach",
               (v29 >> 55) & 1,
               HIBYTE(v29) & 1,
               (v29 >> 57) & 1,
               (v29 >> 58) & 1,
               v31,
               v32,
               v33,
               v34,
               v35,
               v36,
               v37,
               v38,
               v39,
               v40);
    hal_rx_dump_msdu_end_tlv_peach___last_ticks_25 = v28;
  }
  return result;
}
