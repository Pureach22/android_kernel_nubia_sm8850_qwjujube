unsigned int *__fastcall hal_rx_dump_mpdu_start_tlv_peach(
        unsigned int *result,
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
  unsigned int *v12; // x20
  __int64 v13; // x8
  __int64 v14; // x23
  unsigned int v15; // w9
  unsigned int v16; // w8
  __int64 v17; // x23
  unsigned __int64 v18; // x10
  __int64 v19; // x21
  unsigned __int64 v20; // x9
  __int64 v21; // [xsp+0h] [xbp-90h]
  __int64 v22; // [xsp+8h] [xbp-88h]
  __int64 v23; // [xsp+10h] [xbp-80h]
  __int64 v24; // [xsp+18h] [xbp-78h]
  __int64 v25; // [xsp+20h] [xbp-70h]
  __int64 v26; // [xsp+28h] [xbp-68h]
  __int64 v27; // [xsp+30h] [xbp-60h]
  __int64 v28; // [xsp+38h] [xbp-58h]
  __int64 v29; // [xsp+40h] [xbp-50h]
  __int64 v30; // [xsp+48h] [xbp-48h]
  __int64 v31; // [xsp+50h] [xbp-40h]
  __int64 v32; // [xsp+58h] [xbp-38h]
  __int64 v33; // [xsp+60h] [xbp-30h]
  __int64 v34; // [xsp+68h] [xbp-28h]
  __int64 v35; // [xsp+70h] [xbp-20h]
  __int64 v36; // [xsp+78h] [xbp-18h]
  __int64 v37; // [xsp+80h] [xbp-10h]

  v11 = jiffies;
  v12 = result;
  if ( hal_rx_dump_mpdu_start_tlv_peach___last_ticks - jiffies + 125 < 0 )
  {
    v13 = *((_QWORD *)result + 2);
    result = (unsigned int *)qdf_trace_msg(
                               0x46u,
                               a2,
                               "%s: rx_mpdu_start tlv (1/4) - pn_31_0:%x pn_63_32:%x pn_95_64:%x pn_127_96:%x peer_meta_d"
                               "ata:%x mpdu_frame_control_valid:%x mpdu_duration_valid:%x mac_addr_ad1_valid:%x mac_addr_"
                               "ad2_valid:%x mac_addr_ad3_valid:%x mac_addr_ad4_valid:%x mpdu_sequence_control_valid :%xm"
                               "pdu_qos_control_valid:%x mpdu_ht_control_valid:%x frame_encryption_info_valid :%x",
                               a3,
                               a4,
                               a5,
                               a6,
                               a7,
                               a8,
                               a9,
                               a10,
                               "hal_rx_dump_mpdu_start_tlv_peach",
                               *result,
                               result[1],
                               result[2],
                               result[3],
                               HIDWORD(v13),
                               result[4] & 1,
                               ((unsigned int)v13 >> 1) & 1,
                               ((unsigned int)v13 >> 2) & 1,
                               ((unsigned int)v13 >> 3) & 1,
                               ((unsigned int)v13 >> 4) & 1,
                               ((unsigned int)v13 >> 5) & 1,
                               ((unsigned int)v13 >> 6) & 1,
                               ((unsigned int)v13 >> 7) & 1,
                               ((unsigned int)v13 >> 8) & 1,
                               ((unsigned int)v13 >> 9) & 1);
    hal_rx_dump_mpdu_start_tlv_peach___last_ticks = v11;
  }
  v14 = jiffies;
  if ( hal_rx_dump_mpdu_start_tlv_peach___last_ticks_28 - jiffies + 125 < 0 )
  {
    v15 = v12[6];
    v16 = v12[4];
    LODWORD(v31) = (v15 >> 14) & 1;
    LODWORD(v30) = (v15 >> 13) & 1;
    LODWORD(v29) = (v15 >> 12) & 1;
    LODWORD(v28) = (v15 >> 10) & 3;
    LODWORD(v27) = (v15 >> 9) & 1;
    LODWORD(v26) = (v15 >> 8) & 1;
    LODWORD(v25) = (unsigned __int8)v15;
    LODWORD(v24) = v16 >> 20;
    LODWORD(v23) = (v16 >> 19) & 1;
    LODWORD(v22) = (v16 >> 18) & 1;
    LODWORD(v21) = (v16 >> 17) & 1;
    result = (unsigned int *)qdf_trace_msg(
                               0x46u,
                               a2,
                               "%s: rx_mpdu_start tlv (2/4) - mpdu_fragment_number:%x more_fragment_flag:%x reserved_11a:"
                               "%x fr_ds:%x to_ds:%x encrypted:%x mpdu_retry:%x mpdu_sequence_number:%x key_id_octet:%x n"
                               "ew_peer_entry:%x decrypt_needed:%x decap_type:%x rx_insert_vlan_c_tag_padding :%xrx_inser"
                               "t_vlan_s_tag_padding :%xstrip_vlan_c_tag_decap:%x strip_vlan_s_tag_decap:%x pre_delim_cou"
                               "nt:%x ampdu_flag:%x bar_frame:%x raw_mpdu:%x reserved_12:%x ",
                               a3,
                               a4,
                               a5,
                               a6,
                               a7,
                               a8,
                               a9,
                               a10,
                               "hal_rx_dump_mpdu_start_tlv_peach",
                               (v16 >> 10) & 0xF,
                               (v16 >> 14) & 1,
                               (v16 >> 15) & 1,
                               HIWORD(v16) & 1,
                               v21,
                               v22,
                               v23,
                               v24,
                               v25,
                               v26,
                               v27,
                               v28,
                               v29,
                               v30,
                               v31,
                               (v15 >> 15) & 1,
                               HIWORD(v15) & 0xFFF,
                               (v15 >> 28) & 1,
                               (v15 >> 29) & 1,
                               (v15 >> 30) & 1,
                               v15 >> 31);
    hal_rx_dump_mpdu_start_tlv_peach___last_ticks_28 = v14;
  }
  v17 = jiffies;
  if ( hal_rx_dump_mpdu_start_tlv_peach___last_ticks_30 - jiffies + 125 < 0 )
  {
    v18 = *((_QWORD *)v12 + 3);
    LODWORD(v36) = (unsigned __int16)v12[8];
    LODWORD(v32) = (v18 & 0x1000000000000000LL) != 0;
    LODWORD(v31) = (v18 & 0x800000000000000LL) != 0;
    LODWORD(v30) = (v18 & 0x400000000000000LL) != 0;
    LODWORD(v37) = HIWORD(v12[8]);
    LODWORD(v35) = v18 >> 63;
    LODWORD(v34) = (v18 & 0x4000000000000000LL) != 0;
    LODWORD(v33) = (v18 & 0x2000000000000000LL) != 0;
    LODWORD(v29) = (v18 & 0x200000000000000LL) != 0;
    LODWORD(v28) = HIBYTE(v18) & 1;
    LODWORD(v27) = (v18 >> 55) & 1;
    LODWORD(v26) = (v18 >> 54) & 1;
    LODWORD(v25) = (v18 >> 53) & 1;
    LODWORD(v24) = (v18 >> 52) & 1;
    LODWORD(v23) = (v18 >> 51) & 1;
    LODWORD(v22) = (v18 >> 50) & 1;
    LODWORD(v21) = (v18 >> 49) & 1;
    result = (unsigned int *)qdf_trace_msg(
                               0x46u,
                               a2,
                               "%s: rx_mpdu_start tlv (3/4) - mpdu_length:%x first_mpdu:%x mcast_bcast:%x ast_index_not_f"
                               "ound:%x ast_index_timeout:%x power_mgmt:%x non_qos:%x null_data:%x mgmt_type:%x ctrl_type"
                               ":%x more_data:%x eosp:%x fragment_flag:%x order:%x u_apsd_trigger:%x encrypt_required:%x "
                               "directed:%x amsdu_present:%x reserved_13:%x mpdu_frame_control_field:%x mpdu_duration_field:%x ",
                               a3,
                               a4,
                               a5,
                               a6,
                               a7,
                               a8,
                               a9,
                               a10,
                               "hal_rx_dump_mpdu_start_tlv_peach",
                               HIDWORD(v18) & 0x3FFF,
                               (v18 >> 46) & 1,
                               (v18 >> 47) & 1,
                               HIWORD(v18) & 1,
                               v21,
                               v22,
                               v23,
                               v24,
                               v25,
                               v26,
                               v27,
                               v28,
                               v29,
                               v30,
                               v31,
                               v32,
                               v33,
                               v34,
                               v35,
                               v36,
                               v37);
    hal_rx_dump_mpdu_start_tlv_peach___last_ticks_30 = v17;
  }
  v19 = jiffies;
  if ( hal_rx_dump_mpdu_start_tlv_peach___last_ticks_32 - jiffies + 125 < 0 )
  {
    v20 = *((_QWORD *)v12 + 6);
    LODWORD(v23) = HIWORD(v20);
    LODWORD(v22) = WORD2(v20);
    LODWORD(v21) = v20;
    result = (unsigned int *)qdf_trace_msg(
                               0x46u,
                               a2,
                               "%s: rx_mpdu_start tlv (4/4) - mac_addr_ad1_31_0:%x mac_addr_ad1_47_32:%x mac_addr_ad2_15_"
                               "0:%x mac_addr_ad2_47_16:%x mac_addr_ad3_31_0:%x mac_addr_ad3_47_32:%x mpdu_sequence_control_field :%x",
                               a3,
                               a4,
                               a5,
                               a6,
                               a7,
                               a8,
                               a9,
                               a10,
                               "hal_rx_dump_mpdu_start_tlv_peach",
                               v12[9],
                               (unsigned __int16)v12[10],
                               HIWORD(v12[10]),
                               v12[11],
                               v21,
                               v22,
                               v23);
    hal_rx_dump_mpdu_start_tlv_peach___last_ticks_32 = v19;
  }
  return result;
}
