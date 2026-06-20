__int64 __fastcall qdf_dp_trace_log_pkt(unsigned int a1, __int64 a2, unsigned int a3, unsigned int a4, unsigned int a5)
{
  char v5; // w9
  char v6; // w8
  char v7; // w24
  int v8; // w10
  unsigned int v14; // w24
  int arp_subtype; // w0
  char v16; // w8
  int v17; // w23
  int v18; // w25
  unsigned int v19; // w26
  bool is_ipv4_dhcp_pkt; // w0
  unsigned int v21; // w26
  __int64 dhcp_subtype; // x0
  __int64 v23; // x1
  __int64 v24; // x2
  __int64 v25; // x3
  __int64 v26; // x4
  int v27; // w23
  unsigned __int8 *v28; // x24
  unsigned int v29; // w9
  const char *pkt_type_string; // x3
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 v39; // x5
  __int64 v40; // x6
  __int64 v41; // x7
  int v42; // w8
  int v43; // w25
  unsigned int v44; // w26
  bool is_ipv4_eapol_pkt; // w0
  unsigned int v46; // w26
  int v47; // w23
  unsigned __int8 *v48; // x24
  unsigned int v49; // w9
  const char *v50; // x3
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  __int64 v59; // x5
  __int64 v60; // x6
  __int64 v61; // x7
  int v62; // w8
  __int64 v63; // x0
  _BYTE *v64; // x23
  __int64 v65; // x0
  unsigned __int8 icmp_subtype; // w0
  __int64 v67; // x2
  __int16 v68; // w10
  unsigned int v69; // w9
  int v70; // w21
  __int64 result; // x0
  int icmpv6_subtype; // w23
  _BYTE *v73; // x8
  char v74; // w9
  char v75; // w9
  __int16 v76; // w9
  __int64 v77; // x2
  __int64 v78; // x2
  __int16 v79; // w8
  int v80; // w9
  int v81; // w10
  int v82; // w11
  int v83; // w12
  unsigned int v84; // w24
  char v85; // w8
  __int64 v86; // x2
  __int16 v87; // w8
  int v88; // w9
  int v89; // w10
  int v90; // w11
  int v91; // w12
  unsigned int v92; // w24
  char v93; // w8
  __int16 v94; // w9
  __int64 v95; // x2
  __int64 v96; // [xsp+28h] [xbp-18h] BYREF
  __int64 v97; // [xsp+30h] [xbp-10h]
  __int64 v98; // [xsp+38h] [xbp-8h]

  v98 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = byte_7F7658;
  v6 = dword_7F764C;
  v7 = dword_7F76A0;
  v8 = (unsigned __int8)byte_7F7658 ^ 1;
  if ( !dword_7F764C )
    v8 = 1;
  if ( v8 == 1 && dword_7F76A0 == 0 )
    goto LABEL_59;
  if ( byte_7F7658 && (dword_7F764C & 0x10) != 0 )
  {
    LODWORD(v97) = 0;
    v96 = 0;
    if ( !a3 )
    {
      if ( (*(_BYTE *)(a2 + 71) & 0x78) != 0x10 )
        goto LABEL_16;
      goto LABEL_14;
    }
    if ( a3 == 1 )
    {
      v14 = a5;
      if ( !_qdf_nbuf_data_is_ipv4_arp_pkt(*(_QWORD *)(a2 + 224)) )
      {
        a5 = v14;
        v6 = dword_7F764C;
        v7 = dword_7F76A0;
        v5 = byte_7F7658;
        goto LABEL_16;
      }
LABEL_14:
      arp_subtype = _qdf_nbuf_data_get_arp_subtype(*(_QWORD *)(a2 + 224));
      v16 = *(_BYTE *)(a2 + 71);
      v17 = arp_subtype;
      *(_BYTE *)(a2 + 71) = v16 | 0x80;
      if ( a3 )
        *(_BYTE *)(a2 + 85) |= 1u;
      else
        *(_BYTE *)(a2 + 71) = v16 | 0x81;
      v76 = *(_WORD *)(a2 + 52);
      v77 = *(_QWORD *)(a2 + 224);
      BYTE1(v96) = 2;
      LOBYTE(v96) = a1;
      BYTE2(v96) = arp_subtype;
      HIDWORD(v96) = 0;
      LOWORD(v97) = v76 & 0xFFF;
      qdf_dp_trace_proto_pkt(4, v77 + 6, v77, a3, a4, 1, &v96);
      result = 1;
      if ( v17 == 13 )
        ++word_7F7674;
      else
        ++word_7F7676;
      goto LABEL_60;
    }
  }
LABEL_16:
  v18 = *(_DWORD *)&v5 & ((unsigned __int8)(v6 & 4) >> 2);
  if ( (v18 & 1) == 0 && (v7 & 4) == 0 )
    goto LABEL_30;
  LODWORD(v97) = 0;
  v96 = 0;
  if ( a3 )
  {
    if ( a3 != 1 )
      goto LABEL_30;
    v19 = a5;
    is_ipv4_dhcp_pkt = _qdf_nbuf_data_is_ipv4_dhcp_pkt(*(_QWORD *)(a2 + 224));
    a5 = v19;
    if ( !is_ipv4_dhcp_pkt )
    {
      v6 = dword_7F764C;
      v7 = dword_7F76A0;
      v5 = byte_7F7658;
      goto LABEL_30;
    }
LABEL_23:
    v21 = a5;
    dhcp_subtype = _qdf_nbuf_data_get_dhcp_subtype(*(_BYTE **)(a2 + 224));
    v27 = dhcp_subtype;
    if ( a3 == 1 && (v7 & 4) != 0 )
    {
      v28 = *(unsigned __int8 **)(a2 + 224);
      if ( (unsigned __int8)dhcp_subtype >= 0x3Fu )
      {
LABEL_127:
        __break(0x5512u);
        goto LABEL_128;
      }
      if ( (dhcp_subtype & 0x3F) == 0x3F )
        goto LABEL_128;
      v29 = v21;
      if ( qdf_dp_log_proto_pkt_info_last_ticks_rx[dhcp_subtype & 0x3F] - jiffies + 12LL < 0 )
      {
        qdf_dp_log_proto_pkt_info_last_ticks_rx[dhcp_subtype & 0x3F] = jiffies;
        pkt_type_string = qdf_get_pkt_type_string(0, dhcp_subtype);
        if ( v28 == (unsigned __int8 *)-6LL )
        {
          v41 = 0;
          v39 = 0;
          v40 = 0;
          v42 = 0;
        }
        else
        {
          v39 = v28[6];
          v40 = v28[7];
          v41 = v28[8];
          v42 = v28[11];
        }
        if ( v28 )
        {
          v80 = *v28;
          v81 = v28[1];
          v82 = v28[2];
          v83 = v28[5];
        }
        else
        {
          v82 = 0;
          v80 = 0;
          v81 = 0;
          v83 = 0;
        }
        qdf_trace_msg(
          0x38u,
          4u,
          "%s %s: SA:%02x:%02x:%02x:**:**:%02x DA:%02x:%02x:%02x:**:**:%02x",
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          pkt_type_string,
          &unk_A39F4F,
          v39,
          v40,
          v41,
          v42,
          v80,
          v81,
          v82,
          v83,
          v96,
          v97,
          v98);
        v29 = v21;
      }
      v84 = v29;
      qdf_fill_wlan_connectivity_log(0, (unsigned int)v27, 1, 0, v29, a1, a2, (*(_DWORD *)(a2 + 48) >> 22) & 7);
      wlan_cp_stats_cstats_pkt_log(
        *(_QWORD *)(a2 + 224) + 6LL,
        *(_QWORD *)(a2 + 224),
        0,
        (unsigned int)v27,
        1,
        0,
        a1,
        v84);
    }
    if ( v18 )
    {
      v85 = *(_BYTE *)(a2 + 71);
      *(_BYTE *)(a2 + 71) = v85 | 0x80;
      if ( a3 )
        *(_BYTE *)(a2 + 85) |= 1u;
      else
        *(_BYTE *)(a2 + 71) = v85 | 0x81;
      v86 = *(_QWORD *)(a2 + 224);
      v87 = *(_WORD *)(a2 + 52) & 0xFFF;
      LOWORD(v96) = (unsigned __int8)a1;
      BYTE2(v96) = v27;
      HIDWORD(v96) = 0;
      LOWORD(v97) = v87;
      qdf_dp_trace_proto_pkt(3, v86 + 6, v86, a3, a4, 1, &v96);
      if ( v27 <= 6 )
      {
        if ( v27 == 5 )
        {
          ++word_7F7678;
          goto LABEL_125;
        }
        if ( v27 == 6 )
        {
          result = 1;
          ++word_7F767A;
          goto LABEL_60;
        }
      }
      else
      {
        switch ( v27 )
        {
          case 7:
            result = 1;
            ++word_7F767C;
            goto LABEL_60;
          case 8:
            result = 1;
            ++word_7F767E;
            goto LABEL_60;
          case 9:
            result = 1;
            ++word_7F7680;
            goto LABEL_60;
        }
      }
LABEL_123:
      result = 1;
      ++word_7F768C;
      goto LABEL_60;
    }
LABEL_125:
    result = 1;
    goto LABEL_60;
  }
  if ( (*(_BYTE *)(a2 + 71) & 0x78) == 0x20 )
    goto LABEL_23;
LABEL_30:
  v43 = *(_DWORD *)&v5 & ((unsigned __int8)(v6 & 2) >> 1);
  if ( (v43 & 1) == 0 && (v7 & 2) == 0 )
    goto LABEL_44;
  LODWORD(v97) = 0;
  v96 = 0;
  if ( !a3 )
  {
    if ( (*(_BYTE *)(a2 + 71) & 0x78) != 8 )
      goto LABEL_44;
    goto LABEL_37;
  }
  if ( a3 != 1 )
  {
LABEL_44:
    if ( (v5 & 1) != 0 && (v6 & 0x20) != 0 )
    {
      v63 = *(_QWORD *)(a2 + 224);
      LODWORD(v97) = 0;
      v96 = 0;
      if ( _qdf_nbuf_data_is_icmp_pkt(v63) )
      {
        v64 = (_BYTE *)(a2 + 71);
        v65 = *(_QWORD *)(a2 + 224);
        *(_BYTE *)(a2 + 71) &= ~0x80u;
        icmp_subtype = _qdf_nbuf_data_get_icmp_subtype(v65);
        v67 = *(_QWORD *)(a2 + 224);
        BYTE2(v96) = icmp_subtype;
        v68 = *(_WORD *)(a2 + 52);
        v69 = *(_DWORD *)(v67 + 38);
        BYTE1(v96) = 4;
        LOBYTE(v96) = a1;
        HIDWORD(v96) = bswap32(v69);
        LOWORD(v97) = v68 & 0xFFF;
        if ( a3 )
        {
          if ( a3 != 1 )
            goto LABEL_51;
          v64 = (_BYTE *)(a2 + 85);
        }
        *v64 |= 1u;
LABEL_51:
        v70 = icmp_subtype;
        qdf_dp_trace_proto_pkt(8, v67 + 6, v67, a3, a4, 0, &v96);
        result = 1;
        if ( v70 == 15 )
          ++word_7F768E;
        else
          ++word_7F7690;
        goto LABEL_60;
      }
      v6 = dword_7F764C;
      v5 = byte_7F7658;
    }
    result = 0;
    if ( (v5 & 1) == 0 || (v6 & 0x40) == 0 )
      goto LABEL_60;
    LODWORD(v97) = 0;
    v96 = 0;
    if ( a3 )
    {
      if ( a3 != 1 || !_qdf_nbuf_data_is_icmpv6_pkt(*(_QWORD *)(a2 + 224)) )
        goto LABEL_59;
    }
    else if ( (*(_BYTE *)(a2 + 71) & 0x78) != 0x30 )
    {
LABEL_59:
      result = 0;
LABEL_60:
      _ReadStatusReg(SP_EL0);
      return result;
    }
    icmpv6_subtype = _qdf_nbuf_data_get_icmpv6_subtype(*(_BYTE **)(a2 + 224));
    v73 = (_BYTE *)(a2 + 71);
    v74 = *(_BYTE *)(a2 + 71);
    *(_BYTE *)(a2 + 71) = v74 & 0x7F;
    if ( a3 )
    {
      v73 = (_BYTE *)(a2 + 85);
      v75 = *(_BYTE *)(a2 + 85);
    }
    else
    {
      v75 = v74 & 0x7E;
    }
    v78 = *(_QWORD *)(a2 + 224);
    *v73 = v75 | 1;
    v79 = *(_WORD *)(a2 + 52) & 0xFFF;
    LOBYTE(v96) = a1;
    BYTE1(v96) = 5;
    BYTE2(v96) = icmpv6_subtype;
    HIDWORD(v96) = 0;
    LOWORD(v97) = v79;
    qdf_dp_trace_proto_pkt(9, v78 + 6, v78, a3, a4, 0, &v96);
    result = 1;
    if ( icmpv6_subtype <= 19 )
    {
      switch ( icmpv6_subtype )
      {
        case 17:
          ++word_7F7692;
          break;
        case 18:
          ++word_7F7694;
          break;
        case 19:
          ++word_7F769C;
          break;
      }
    }
    else if ( icmpv6_subtype > 21 )
    {
      if ( icmpv6_subtype == 22 )
      {
        ++word_7F7698;
      }
      else if ( icmpv6_subtype == 23 )
      {
        ++word_7F769A;
      }
    }
    else if ( icmpv6_subtype == 20 )
    {
      ++word_7F769E;
    }
    else
    {
      ++word_7F7696;
    }
    goto LABEL_60;
  }
  v44 = a5;
  is_ipv4_eapol_pkt = _qdf_nbuf_data_is_ipv4_eapol_pkt(*(_QWORD *)(a2 + 224));
  a5 = v44;
  if ( !is_ipv4_eapol_pkt )
  {
    v6 = dword_7F764C;
    v5 = byte_7F7658;
    goto LABEL_44;
  }
LABEL_37:
  v46 = a5;
  dhcp_subtype = _qdf_nbuf_data_get_eapol_subtype(*(_QWORD *)(a2 + 224));
  v47 = dhcp_subtype;
  if ( a3 != 1 || (v7 & 2) == 0 )
    goto LABEL_112;
  v48 = *(unsigned __int8 **)(a2 + 224);
  if ( (unsigned __int8)dhcp_subtype >= 0x3Fu )
    goto LABEL_127;
  if ( (dhcp_subtype & 0x3F) != 0x3F )
  {
    v49 = v46;
    if ( qdf_dp_log_proto_pkt_info_last_ticks_rx[dhcp_subtype & 0x3F] - jiffies + 5LL < 0 )
    {
      qdf_dp_log_proto_pkt_info_last_ticks_rx[dhcp_subtype & 0x3F] = jiffies;
      v50 = qdf_get_pkt_type_string(1u, dhcp_subtype);
      if ( v48 == (unsigned __int8 *)-6LL )
      {
        v61 = 0;
        v59 = 0;
        v60 = 0;
        v62 = 0;
      }
      else
      {
        v59 = v48[6];
        v60 = v48[7];
        v61 = v48[8];
        v62 = v48[11];
      }
      if ( v48 )
      {
        v88 = *v48;
        v89 = v48[1];
        v90 = v48[2];
        v91 = v48[5];
      }
      else
      {
        v90 = 0;
        v88 = 0;
        v89 = 0;
        v91 = 0;
      }
      qdf_trace_msg(
        0x38u,
        4u,
        "%s %s: SA:%02x:%02x:%02x:**:**:%02x DA:%02x:%02x:%02x:**:**:%02x",
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        v57,
        v58,
        v50,
        &unk_A39F4F,
        v59,
        v60,
        v61,
        v62,
        v88,
        v89,
        v90,
        v91,
        v96,
        v97,
        v98);
      v49 = v46;
    }
    v92 = v49;
    qdf_fill_wlan_connectivity_log(1, (unsigned int)v47, 1, 0, v49, a1, a2, (*(_DWORD *)(a2 + 48) >> 22) & 7);
    wlan_cp_stats_cstats_pkt_log(
      *(_QWORD *)(a2 + 224) + 6LL,
      *(_QWORD *)(a2 + 224),
      1,
      (unsigned int)v47,
      1,
      0,
      a1,
      v92);
LABEL_112:
    if ( v43 )
    {
      v93 = *(_BYTE *)(a2 + 71);
      *(_BYTE *)(a2 + 71) = v93 | 0x80;
      if ( a3 )
        *(_BYTE *)(a2 + 85) |= 1u;
      else
        *(_BYTE *)(a2 + 71) = v93 | 0x81;
      v94 = *(_WORD *)(a2 + 52);
      v95 = *(_QWORD *)(a2 + 224);
      BYTE1(v96) = 1;
      LOBYTE(v96) = a1;
      BYTE2(v96) = v47;
      HIDWORD(v96) = 0;
      LOWORD(v97) = v94 & 0xFFF;
      qdf_dp_trace_proto_pkt(2, v95 + 6, v95, a3, a4, 1, &v96);
      if ( v47 > 2 )
      {
        if ( v47 == 3 )
        {
          result = 1;
          ++word_7F7688;
          goto LABEL_60;
        }
        if ( v47 == 4 )
        {
          result = 1;
          ++word_7F768A;
          goto LABEL_60;
        }
        goto LABEL_123;
      }
      if ( v47 != 1 )
      {
        if ( v47 == 2 )
        {
          result = 1;
          ++word_7F7686;
          goto LABEL_60;
        }
        goto LABEL_123;
      }
      ++word_7F7684;
    }
    goto LABEL_125;
  }
LABEL_128:
  __break(1u);
  return qdf_dp_trace_fill_meta_str(dhcp_subtype, v23, v24, v25, v26);
}
