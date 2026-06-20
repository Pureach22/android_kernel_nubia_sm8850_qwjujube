__int64 __fastcall lim_send_probe_req_mgmt_frame(
        __int64 a1,
        __int64 a2,
        unsigned __int16 *a3,
        unsigned __int8 *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  int v15; // w26
  unsigned int v16; // w20
  unsigned int v17; // w22
  __int16 v18; // w8
  int v19; // w9
  __int64 v20; // x0
  int v21; // w28
  unsigned int v22; // w25
  unsigned int v23; // w21
  __int64 v24; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x19
  bool v34; // zf
  char v35; // w21
  unsigned __int8 *vendor_ie_ptr_from_oui; // x0
  unsigned int mgmt_tx_power; // w0
  __int16 v38; // w10
  __int16 v39; // w11
  __int16 v40; // w10
  __int16 v41; // w8
  __int64 v42; // x1
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  unsigned __int16 v51; // w3
  _BOOL4 v52; // w21
  char v53; // w0
  unsigned __int8 *v54; // x0
  __int64 v55; // x2
  unsigned int packed_probe_request_size; // w0
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  unsigned int v65; // w25
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  char *v74; // x25
  char *v75; // x0
  double v76; // d0
  double v77; // d1
  double v78; // d2
  double v79; // d3
  double v80; // d4
  double v81; // d5
  double v82; // d6
  double v83; // d7
  unsigned int v84; // w8
  __int16 v85; // w8
  __int64 v86; // x5
  unsigned int v87; // w0
  double v88; // d0
  double v89; // d1
  double v90; // d2
  double v91; // d3
  double v92; // d4
  double v93; // d5
  double v94; // d6
  double v95; // d7
  unsigned int v96; // w8
  __int64 v97; // x3
  double v98; // d0
  double v99; // d1
  double v100; // d2
  double v101; // d3
  double v102; // d4
  double v103; // d5
  double v104; // d6
  double v105; // d7
  double v106; // d0
  double v107; // d1
  double v108; // d2
  double v109; // d3
  double v110; // d4
  double v111; // d5
  double v112; // d6
  double v113; // d7
  char v114; // w20
  _QWORD *context; // x0
  double v116; // d0
  double v117; // d1
  double v118; // d2
  double v119; // d3
  double v120; // d4
  double v121; // d5
  double v122; // d6
  double v123; // d7
  int v125; // [xsp+8h] [xbp-98h]
  unsigned int v126; // [xsp+4Ch] [xbp-54h]
  unsigned __int16 v128; // [xsp+5Ch] [xbp-44h] BYREF
  __int64 v129; // [xsp+60h] [xbp-40h] BYREF
  char *v130; // [xsp+68h] [xbp-38h] BYREF
  unsigned int v131; // [xsp+74h] [xbp-2Ch] BYREF
  _DWORD v132[2]; // [xsp+78h] [xbp-28h] BYREF
  __int128 v133; // [xsp+80h] [xbp-20h] BYREF
  char v134; // [xsp+90h] [xbp-10h]
  __int64 v135; // [xsp+98h] [xbp-8h]

  v135 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v128 = 0;
  if ( a2 )
  {
    if ( a3 )
    {
      v15 = *a3;
      v128 = *a3;
    }
    else
    {
      v15 = 0;
    }
    v17 = *(_DWORD *)(a2 + 284);
    v18 = *(_WORD *)(a2 + 24);
    v19 = *(_DWORD *)(a2 + 26);
    v20 = *(_QWORD *)(a1 + 21560);
    v21 = *(unsigned __int8 *)(a2 + 154);
    v131 = 0;
    v129 = 0;
    v130 = nullptr;
    v133 = 0u;
    v134 = 0;
    LOWORD(v132[0]) = v18;
    *(_DWORD *)((char *)v132 + 2) = v19;
    v22 = wlan_reg_freq_to_chan(v20, v17, a5, a6, a7, a8, a9, a10, a11, a12);
    if ( wlan_reg_is_24ghz_ch_freq(v17) && (*(_BYTE *)(*(_QWORD *)(a1 + 8) + 2671LL) & 1) == 0 && (v21 & 0xFE) == 8 )
      v21 = 5;
    v23 = *(unsigned __int8 *)(a2 + 10);
    v24 = _qdf_mem_malloc(0x488u, "lim_send_probe_req_mgmt_frame", 222);
    if ( v24 )
    {
      v33 = v24;
      v126 = v23;
      if ( !wlan_reg_is_6ghz_chan_freq(v17) && *(unsigned __int8 *)(a2 + 10074) >= 3u )
        memset(v132, 255, 6);
      populate_dot11f_ssid(a1, a2 + 36, v33);
      if ( a4 )
        v34 = v15 == 0;
      else
        v34 = 1;
      v35 = !v34;
      if ( v34
        || (vendor_ie_ptr_from_oui = wlan_get_vendor_ie_ptr_from_oui(&unk_89A401, 4u, a4, v15), v21 == 3)
        || !vendor_ie_ptr_from_oui
        || *(_DWORD *)(a2 + 7036) != 2 )
      {
        populate_dot11f_supp_rates(a1, v22, v33 + 34, a2);
        if ( v21 != 3 )
          populate_dot11f_ext_supp_rates1(a1, v22, v33 + 305);
      }
      else
      {
        populate_dot11f_supp_rates(a1, 15, v33 + 34, a2);
      }
      populate_dot11f_ds_params(a1, v33 + 319, v17);
      mgmt_tx_power = rrm_get_mgmt_tx_power(a1, a2);
      populate_dot11f_wfatpc(a1, v33 + 1082, mgmt_tx_power, 0);
      if ( *(_BYTE *)(a2 + 155) && !wlan_reg_is_6ghz_chan_freq(v17) )
        populate_dot11f_ht_caps(a1, a2, v33 + 324);
      if ( wlan_reg_is_24ghz_ch_freq(v17) )
      {
        v38 = *(_WORD *)(v33 + 325);
        v39 = v38 & 0xFFBD;
        v40 = v38 | 2;
        if ( *(_DWORD *)(a1 + 17120) )
          v41 = v40;
        else
          v41 = v39;
        *(_WORD *)(v33 + 325) = v41;
      }
      if ( *(_BYTE *)(a2 + 7170) && !wlan_reg_is_6ghz_chan_freq(v17) )
      {
        populate_dot11f_vht_caps(a1, a2, v33 + 404);
        v42 = 1;
      }
      else
      {
        v42 = 0;
      }
      populate_dot11f_ext_cap(a1, v42, v33 + 384, a2);
      if ( (unsigned int)(v21 - 10) < 4 || !v21 )
      {
        lim_update_session_he_capable(a1, a2);
        populate_dot11f_he_caps(a1, a2, *(_DWORD *)(a2 + 7036), v17, *(_DWORD *)(a2 + 7176), v33 + 420);
        populate_dot11f_he_6ghz_cap(a1, a2, v33 + 480);
        populate_dot11f_reg_connectivity(a1, v33 + 833);
      }
      if ( (v35 & 1) == 0 )
      {
        populate_dot11f_qcn_ie(a1, a2, v33 + 1116, 255);
        goto LABEL_54;
      }
      qdf_mem_set(&v133, 0x11u, 0);
      if ( (unsigned int)lim_strip_extcap_update_struct(a1, a4, &v128, &v133) )
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: Unable to Stripoff ExtCap IE from Probe Req",
          v43,
          v44,
          v45,
          v46,
          v47,
          v48,
          v49,
          v50,
          "lim_send_probe_req_mgmt_frame");
        v51 = v128;
        v52 = 0;
      }
      else
      {
        if ( (*(_DWORD *)((_BYTE *)&v133 + 2) & 0x80000000) != 0 )
          *(_QWORD *)((char *)&v133 + 2) |= 0x100000000uLL;
        v53 = lim_compute_ext_cap_ie_length(&v133);
        v51 = v128;
        v52 = v53 != 0;
        BYTE1(v133) = v53;
        if ( a3 )
          *a3 = v128;
      }
      v54 = wlan_get_vendor_ie_ptr_from_oui(&unk_8A74CD, 4u, a4, v51);
      v55 = v33 + 1116;
      if ( v54 )
      {
        populate_dot11f_qcn_ie(a1, a2, v55, 2);
        if ( !v52 )
          goto LABEL_54;
      }
      else
      {
        populate_dot11f_qcn_ie(a1, a2, v55, 255);
        if ( !v52 )
        {
LABEL_54:
          populate_dot11f_btm_extended_caps(a1, a2, v33 + 384);
          packed_probe_request_size = dot11f_get_packed_probe_request_size(a1, v33, &v131);
          if ( (packed_probe_request_size & 0x10000000) != 0 )
          {
            qdf_trace_msg(
              0x35u,
              2u,
              "%s: Failed to calculate the packed size for a Probe Request (0x%08x)",
              v57,
              v58,
              v59,
              v60,
              v61,
              v62,
              v63,
              v64,
              "lim_send_probe_req_mgmt_frame",
              packed_probe_request_size);
            v131 = 1160;
          }
          else if ( packed_probe_request_size )
          {
            qdf_trace_msg(
              0x35u,
              3u,
              "%s: There were warnings while calculating the packed size for a Probe Request (0x%08x)",
              v57,
              v58,
              v59,
              v60,
              v61,
              v62,
              v63,
              v64,
              "lim_send_probe_req_mgmt_frame");
          }
          v65 = v131 + v128;
          if ( (unsigned int)cds_packet_alloc((unsigned __int16)v131 + v128 + 24, &v130, &v129) )
          {
            v16 = 2;
            qdf_trace_msg(
              0x35u,
              2u,
              "%s: Failed to allocate %d bytes for a Probe Request",
              v66,
              v67,
              v68,
              v69,
              v70,
              v71,
              v72,
              v73,
              "lim_send_probe_req_mgmt_frame",
              v65 + 24);
LABEL_80:
            _qdf_mem_free(0);
            _qdf_mem_free(v33);
            goto LABEL_81;
          }
          qdf_mem_set(v130, v65 + 24, 0);
          v74 = v130;
          v75 = v130 + 4;
          *v130 = 64;
          qdf_mem_copy(v75, v132, 6u);
          v74[10] = *(_BYTE *)(a2 + 30);
          v74[11] = *(_BYTE *)(a2 + 31);
          v74[12] = *(_BYTE *)(a2 + 32);
          v74[13] = *(_BYTE *)(a2 + 33);
          v74[14] = *(_BYTE *)(a2 + 34);
          v74[15] = *(_BYTE *)(a2 + 35);
          qdf_mem_copy(v74 + 16, v132, 6u);
          v84 = *(unsigned __int16 *)(a1 + 21532);
          if ( v84 <= 0xFFE )
            v85 = v84 + 1;
          else
            v85 = 2048;
          *(_WORD *)(a1 + 21532) = v85;
          *((_WORD *)v74 + 11) = (16 * (v85 & 0xF)) | *((_WORD *)v74 + 11) & 0xFF0F;
          v86 = (unsigned __int8)(*(_WORD *)(a1 + 21532) >> 4);
          *((_WORD *)v74 + 11) = (16 * *(_WORD *)(a1 + 21532)) & 0xFF00 | (16 * (v85 & 0xF));
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: seqNumLo=%d, seqNumHi=%d, mgmtSeqNum=%d, fragNum=%d",
            v76,
            v77,
            v78,
            v79,
            v80,
            v81,
            v82,
            v83,
            "lim_populate_mac_header",
            v85 & 0xF,
            v86,
            *(unsigned __int16 *)(a1 + 21532),
            0);
          v87 = dot11f_pack_probe_request(a1, v33, v130 + 24, v131, &v131);
          if ( (v87 & 0x10000000) != 0 )
          {
            qdf_trace_msg(
              0x35u,
              2u,
              "%s: Failed to pack a Probe Request (0x%08x)",
              v88,
              v89,
              v90,
              v91,
              v92,
              v93,
              v94,
              v95,
              "lim_send_probe_req_mgmt_frame",
              v87);
            cds_packet_free(v129);
LABEL_79:
            v16 = 16;
            goto LABEL_80;
          }
          if ( v87 )
            qdf_trace_msg(
              0x35u,
              3u,
              "%s: There were warnings while packing a Probe Request (0x%08x)",
              v88,
              v89,
              v90,
              v91,
              v92,
              v93,
              v94,
              v95,
              "lim_send_probe_req_mgmt_frame");
          v96 = v131;
          if ( v128 )
          {
            qdf_mem_copy(&v130[v131 + 24], a4, v128);
            v96 = v131 + v128;
            v131 = v96;
          }
          qdf_trace_msg(
            0x35u,
            8u,
            "Probe req TX: vdev %d seq num %d to %02x:%02x:%02x:**:**:%02x len %d",
            v88,
            v89,
            v90,
            v91,
            v92,
            v93,
            v94,
            v95,
            v126,
            *(unsigned __int16 *)(a1 + 21532),
            LOBYTE(v132[0]),
            BYTE1(v132[0]),
            BYTE2(v132[0]),
            BYTE1(v132[1]),
            v96 + 24);
          mgmt_txrx_frame_hex_dump((__int64)v130, v131 + 24, 1, v97, v98, v99, v100, v101, v102, v103, v104, v105);
          if ( !wlan_reg_is_6ghz_chan_freq(v17) )
          {
            if ( wlan_reg_is_5ghz_ch_freq(v17) )
              goto LABEL_72;
            wlan_reg_is_24ghz_ch_freq(v17);
          }
          if ( *(_DWORD *)(a2 + 7036) != 2 )
          {
            v114 = 0;
            goto LABEL_77;
          }
LABEL_72:
          v114 = 64;
LABEL_77:
          context = _cds_get_context(
                      54,
                      (__int64)"lim_send_probe_req_mgmt_frame",
                      v106,
                      v107,
                      v108,
                      v109,
                      v110,
                      v111,
                      v112,
                      v113);
          LOBYTE(v125) = v114;
          if ( !(unsigned int)wma_tx_packet(
                                context,
                                v129,
                                (unsigned int)(unsigned __int16)v131 + 24,
                                3,
                                1,
                                7,
                                lim_tx_complete,
                                v130,
                                0,
                                v125,
                                (_BYTE)v126,
                                0,
                                0,
                                12,
                                0,
                                0) )
          {
            v16 = 0;
            goto LABEL_80;
          }
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: could not send Probe Request frame!",
            v116,
            v117,
            v118,
            v119,
            v120,
            v121,
            v122,
            v123,
            "lim_send_probe_req_mgmt_frame");
          goto LABEL_79;
        }
      }
      lim_merge_extcap_struct(v33 + 384, &v133, 1);
      goto LABEL_54;
    }
    v16 = 2;
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: memory alloc failed for probe request",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      "lim_send_probe_req_mgmt_frame");
  }
  else
  {
    v16 = 29;
  }
LABEL_81:
  _ReadStatusReg(SP_EL0);
  return v16;
}
