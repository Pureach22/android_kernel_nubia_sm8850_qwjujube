_BYTE *__fastcall lim_send_probe_rsp_mgmt_frame(
        _BYTE *result,
        unsigned __int8 *a2,
        __int64 a3,
        __int64 a4,
        char a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  __int64 v13; // x20
  int v18; // w8
  char v19; // w26
  __int64 v20; // x19
  _WORD *v21; // x8
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  int v30; // w25
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 v39; // x23
  unsigned int tpe_ie_length; // w28
  __int64 v41; // x0
  __int64 v42; // x8
  __int64 v43; // x8
  unsigned __int8 *v44; // x0
  unsigned __int8 *v45; // x24
  size_t v46; // x25
  int v47; // w25
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  int v56; // w27
  unsigned __int8 *vendor_ie_ptr_from_oui; // x26
  unsigned int noa_attr_stream; // w0
  int v59; // w8
  unsigned __int8 v60; // w28
  int updated; // w0
  __int64 v62; // x0
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  char *v71; // x27
  unsigned __int8 *v72; // x28
  unsigned __int16 v73; // w24
  unsigned int v74; // w26
  unsigned int v75; // w5
  unsigned int v76; // w6
  __int64 v77; // x4
  double v78; // d0
  double v79; // d1
  double v80; // d2
  double v81; // d3
  double v82; // d4
  double v83; // d5
  double v84; // d6
  double v85; // d7
  unsigned int packed_probe_response_size; // w0
  double v87; // d0
  double v88; // d1
  double v89; // d2
  double v90; // d3
  double v91; // d4
  double v92; // d5
  double v93; // d6
  double v94; // d7
  unsigned __int16 v95; // w25
  unsigned int v96; // w27
  const char *v97; // x2
  __int64 v98; // x0
  _BYTE *v99; // x8
  unsigned int v100; // w0
  double v101; // d0
  double v102; // d1
  double v103; // d2
  double v104; // d3
  double v105; // d4
  double v106; // d5
  double v107; // d6
  double v108; // d7
  unsigned __int16 v109; // w25
  __int64 v110; // x4
  __int64 v111; // x5
  __int64 v112; // x6
  __int64 v113; // x7
  char v114; // w21
  double v115; // d0
  double v116; // d1
  double v117; // d2
  double v118; // d3
  double v119; // d4
  double v120; // d5
  double v121; // d6
  double v122; // d7
  _QWORD *context; // x0
  double v124; // d0
  double v125; // d1
  double v126; // d2
  double v127; // d3
  double v128; // d4
  double v129; // d5
  double v130; // d6
  double v131; // d7
  unsigned __int8 *v132; // [xsp+40h] [xbp-B0h]
  unsigned __int8 v133; // [xsp+48h] [xbp-A8h]
  char v134; // [xsp+4Ch] [xbp-A4h]
  unsigned int v135; // [xsp+50h] [xbp-A0h]
  unsigned int v136; // [xsp+54h] [xbp-9Ch]
  unsigned __int16 v137[2]; // [xsp+58h] [xbp-98h] BYREF
  unsigned __int16 v138[2]; // [xsp+5Ch] [xbp-94h] BYREF
  _BYTE *v139; // [xsp+60h] [xbp-90h] BYREF
  int v140[2]; // [xsp+68h] [xbp-88h] BYREF
  unsigned int v141; // [xsp+74h] [xbp-7Ch] BYREF
  _QWORD v142[2]; // [xsp+78h] [xbp-78h] BYREF
  char v143; // [xsp+88h] [xbp-68h]
  _QWORD v144[5]; // [xsp+90h] [xbp-60h] BYREF
  _QWORD v145[7]; // [xsp+B8h] [xbp-38h] BYREF

  v145[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v139 = nullptr;
  v138[0] = 0;
  v143 = 0;
  v142[0] = 0;
  v142[1] = 0;
  v137[0] = 0;
  if ( !a4 )
    goto LABEL_7;
  v13 = (__int64)result;
  if ( *(_DWORD *)result == 1 )
    goto LABEL_7;
  v18 = *(_DWORD *)(a4 + 7036) | 2;
  v141 = 0;
  *(_QWORD *)v140 = 0;
  memset(v145, 0, 37);
  memset(v144, 0, 37);
  if ( v18 == 3 && result[14881] == 1 )
  {
    result = (_BYTE *)qdf_trace_msg(
                        0x35u,
                        4u,
                        "%s: CAC timer is running, probe response dropped",
                        a6,
                        a7,
                        a8,
                        a9,
                        a10,
                        a11,
                        a12,
                        a13,
                        "lim_send_probe_rsp_mgmt_frame");
    goto LABEL_7;
  }
  result = (_BYTE *)wlan_vdev_is_up();
  if ( (_DWORD)result )
    goto LABEL_7;
  v19 = *(_BYTE *)(a4 + 10);
  result = (_BYTE *)_qdf_mem_malloc(0x13A8u, "lim_send_probe_rsp_mgmt_frame", 672);
  if ( !result )
    goto LABEL_7;
  v20 = (__int64)result;
  qdf_mem_set(result, 0x13A8u, 0);
  if ( *(_DWORD *)(a4 + 88) == 1 )
    v21 = (_WORD *)(v13 + 12448);
  else
    v21 = (_WORD *)(*(_QWORD *)(v13 + 8) + 3400LL);
  *(_WORD *)(v20 + 8) = *v21;
  populate_dot11f_capabilities(v13, v20 + 10, a4, 1);
  populate_dot11f_ssid(v13, a3, v20 + 12);
  populate_dot11f_supp_rates(v13, 255, v20 + 46, a4);
  populate_dot11f_tpc_report(v13, v20 + 600, a4);
  populate_dot11f_ds_params(v13, v20 + 68, *(unsigned int *)(a4 + 284));
  if ( *(_DWORD *)(a4 + 88) == 1 )
  {
    if ( *(_BYTE *)(a4 + 7022) )
      populate_dot11f_probe_res_wpsi_es(v13, v20 + 3204, a4);
  }
  else
  {
    if ( (*(_BYTE *)(*(_QWORD *)(v13 + 8) + 5800LL) & 1) != 0 )
      populate_dot11f_wsc_in_probe_res(v13, v20 + 3204);
    if ( *(_DWORD *)(v13 + 12252) == 1 )
    {
      populate_dot11f_wsc_registrar_info_in_probe_res(v13, v20 + 3204);
      *(_DWORD *)(v13 + 12252) = 2;
    }
    if ( *(_DWORD *)(v13 + 12248) == 3 )
    {
      de_populate_dot11f_wsc_registrar_info_in_probe_res(v13, v20 + 3204);
      *(_DWORD *)(v13 + 12252) = 0;
    }
  }
  populate_dot11f_country(v13, v20 + 78, a4);
  populate_dot11f_edca_param_set(v13, v20 + 882, a4);
  if ( *(_BYTE *)(a4 + 154) != 3 )
    populate_dot11f_erp_info(v13, v20 + 603, a4);
  populate_dot11f_ext_supp_rates(v13, 255, v20 + 605, a4);
  if ( *(_BYTE *)(a4 + 155) )
  {
    populate_dot11f_ht_caps(v13, a4, v20 + 1008);
    populate_dot11f_ht_info(v13, v20 + 1068, a4);
  }
  v30 = *(unsigned __int8 *)(a4 + 7170);
  if ( *(_BYTE *)(a4 + 7170)
    && (qdf_trace_msg(
          0x35u,
          8u,
          "%s: Populate VHT IE in Probe Response",
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          "lim_send_probe_rsp_mgmt_frame"),
        populate_dot11f_vht_caps(v13, a4, v20 + 1160),
        populate_dot11f_vht_operation(v13, a4, v20 + 1176),
        *(_BYTE *)(a4 + 7170))
    || wlan_reg_is_6ghz_chan_freq(*(_DWORD *)(a4 + 284)) )
  {
    v39 = _qdf_mem_malloc(0xD8u, "lim_send_probe_rsp_mgmt_frame", 772);
    if ( !v39 )
      goto LABEL_80;
    populate_dot11f_tx_power_env(v13, a4, v39, *(unsigned int *)(a4 + 7176), *(unsigned int *)(a4 + 284), v137, 0);
    tpe_ie_length = lim_get_tpe_ie_length(*(unsigned int *)(a4 + 7176), v39, v137[0]);
  }
  else
  {
    tpe_ie_length = 0;
    v39 = 0;
  }
  if ( *(_BYTE *)(a4 + 8676) == 1 )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Populate HE IEs",
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      "lim_send_probe_rsp_mgmt_frame");
    populate_dot11f_he_caps(v13, a4, *(_DWORD *)(a4 + 7036), *(_DWORD *)(a4 + 284), *(_DWORD *)(a4 + 7176), v20 + 2000);
    populate_dot11f_he_operation(v13, a4, v20 + 2060);
    populate_dot11f_sr_info(v13, a4, v20 + 2078);
    populate_dot11f_he_6ghz_cap(v13, a4, v20 + 2116);
  }
  v41 = *(_QWORD *)(a4 + 16);
  if ( *(_DWORD *)(v41 + 16) == 1 && (wlan_vdev_mlme_is_mlo_vdev(v41, v31, v32, v33, v34, v35, v36, v37, v38) & 1) != 0 )
  {
    v136 = lim_send_bcn_frame_mlo(v13, a4);
    populate_dot11f_mlo_rnr(v13, a4, v20 + 4976, v20 + 4972);
  }
  else
  {
    v136 = 0;
  }
  if ( *(_BYTE *)(a4 + 10071) == 1 )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Populate EHT IEs",
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      "lim_send_probe_rsp_mgmt_frame");
    populate_dot11f_eht_caps(v13, a4, v20 + 2240);
    populate_dot11f_eht_operation(v13, a4, v20 + 2332);
  }
  populate_dot11f_ext_cap(v13, v30 != 0, v20 + 1142, a4);
  v42 = *(_QWORD *)(a4 + 104);
  if ( v42 )
  {
    populate_dot11f_wpa(v13, v42 + 56, v20 + 3118);
    populate_dot11f_rsn_opaque(v13, *(_QWORD *)(a4 + 104) + 56LL, v20 + 619);
  }
  populate_dot11f_wmm(v13, v20 + 3166, v20 + 3170, v20 + 3190, a4);
  v43 = *(_QWORD *)(a4 + 104);
  if ( v43 )
    populate_dot11f_wapi(v13, v43 + 56, v20 + 2122);
  if ( !*(_WORD *)(a4 + 7288) )
  {
    v134 = v19;
    v135 = tpe_ie_length;
    v60 = 0;
    vendor_ie_ptr_from_oui = nullptr;
    v133 = 0;
    v45 = nullptr;
    v56 = 0;
    goto LABEL_72;
  }
  v44 = (unsigned __int8 *)_qdf_mem_malloc(*(unsigned __int16 *)(a4 + 7288), "lim_send_probe_rsp_mgmt_frame", 846);
  if ( !v44 )
    goto LABEL_80;
  v45 = v44;
  qdf_mem_copy(v44, *(const void **)(a4 + 7296), *(unsigned __int16 *)(a4 + 7288));
  v46 = *(unsigned __int16 *)(a4 + 7288);
  v138[0] = *(_WORD *)(a4 + 7288);
  if ( !a5 )
  {
    v62 = _qdf_mem_malloc(v46, "lim_get_addn_ie_for_probe_resp", 518);
    if ( v62 )
    {
      v71 = (char *)v62;
      v134 = v19;
      v135 = tpe_ie_length;
      v132 = v45;
      if ( (unsigned int)v46 < 2 )
      {
        v73 = 0;
LABEL_68:
        qdf_mem_copy(v132, v71, v73);
        v138[0] = v73;
        v45 = v132;
        _qdf_mem_free((__int64)v71);
        updated = lim_strip_extcap_update_struct(v13, v132, v138, v142);
        if ( updated )
        {
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: Unable to strip off ExtCap IE",
            v78,
            v79,
            v80,
            v81,
            v82,
            v83,
            v84,
            v85,
            "lim_send_probe_rsp_mgmt_frame");
          v56 = v138[0];
          v133 = 0;
          v60 = 0;
          vendor_ie_ptr_from_oui = nullptr;
          goto LABEL_72;
        }
        v56 = v138[0];
        v60 = 0;
        vendor_ie_ptr_from_oui = nullptr;
        goto LABEL_71;
      }
      v72 = v45;
      v73 = 0;
      while ( 1 )
      {
        v75 = v72[1];
        v76 = v46 - 2;
        v77 = *v72;
        LODWORD(v46) = v46 - 2 - v75;
        if ( v76 < v75 )
          break;
        if ( (_DWORD)v77 == 221 && *(_DWORD *)(v72 + 2) == 161115984 )
        {
          v74 = v75 + 2;
        }
        else
        {
          v74 = v75 + 2;
          qdf_mem_copy(&v71[v73], v72, v75 + 2);
          v73 += v74;
        }
        v72 += v74;
        if ( (int)v46 <= 1 )
          goto LABEL_68;
      }
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Invalid IEs eid: %d elem_len: %d left: %d",
        v63,
        v64,
        v65,
        v66,
        v67,
        v68,
        v69,
        v70,
        "lim_get_addn_ie_for_probe_resp",
        v77);
      _qdf_mem_free((__int64)v71);
      v45 = v132;
    }
    v97 = "%s: Unable to get addn_ie";
LABEL_78:
    qdf_trace_msg(0x35u, 2u, v97, v63, v64, v65, v66, v67, v68, v69, v70, "lim_send_probe_rsp_mgmt_frame");
    if ( !v45 )
      goto LABEL_80;
    goto LABEL_79;
  }
  v134 = v19;
  v135 = tpe_ie_length;
  v47 = lim_strip_extcap_update_struct(v13, v45, v138, v142);
  if ( v47 )
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Unable to strip off ExtCap IE",
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      "lim_send_probe_rsp_mgmt_frame");
  v56 = v138[0];
  vendor_ie_ptr_from_oui = wlan_get_vendor_ie_ptr_from_oui(&unk_969516, 4u, v45, v138[0]);
  if ( !vendor_ie_ptr_from_oui || (noa_attr_stream = lim_get_noa_attr_stream(v13, v145, a4), !(_BYTE)noa_attr_stream) )
  {
    LOBYTE(updated) = 0;
    v60 = 0;
    if ( v47 )
    {
      v60 = 0;
      v133 = 0;
      goto LABEL_72;
    }
    goto LABEL_71;
  }
  v59 = (unsigned __int8)noa_attr_stream;
  v60 = noa_attr_stream;
  if ( vendor_ie_ptr_from_oui[1] + (unsigned int)(unsigned __int8)noa_attr_stream >= 0x100 )
  {
    LOBYTE(updated) = lim_build_p2p_ie(v13, v144, v145, noa_attr_stream);
    v56 += (unsigned __int8)updated;
    if ( !v47 )
      goto LABEL_71;
LABEL_66:
    v133 = updated;
    goto LABEL_72;
  }
  LOBYTE(updated) = 0;
  v56 += v59;
  if ( v47 )
    goto LABEL_66;
LABEL_71:
  v133 = updated;
  lim_merge_extcap_struct(v20 + 1142, v142, 1);
  populate_dot11f_twt_extended_caps(v13, a4, v20 + 1142);
LABEL_72:
  populate_dot11f_bcn_prot_extcaps(v13, a4, v20 + 1142);
  packed_probe_response_size = dot11f_get_packed_probe_response_size(v13, v20, &v141);
  if ( (packed_probe_response_size & 0x10000000) != 0 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Probe Response size error (0x%08x)",
      v87,
      v88,
      v89,
      v90,
      v91,
      v92,
      v93,
      v94,
      "lim_send_probe_rsp_mgmt_frame",
      packed_probe_response_size);
    v141 = 5032;
  }
  else if ( packed_probe_response_size )
  {
    qdf_trace_msg(
      0x35u,
      3u,
      "%s: Probe Response size warning (0x%08x)",
      v87,
      v88,
      v89,
      v90,
      v91,
      v92,
      v93,
      v94,
      "lim_send_probe_rsp_mgmt_frame");
  }
  v95 = v135;
  v96 = (unsigned __int16)v135 + (unsigned __int16)v136 + v56 + v141 + 24;
  if ( (unsigned int)cds_packet_alloc(v96, v140, &v139) )
  {
    v97 = "%s: Probe Response allocation failed";
    goto LABEL_78;
  }
  qdf_mem_set(*(void **)v140, v96, 0);
  lim_populate_mac_header(v13, *(__int64 *)v140, 0, 5, a2, (_BYTE *)(a4 + 30));
  v99 = *(_BYTE **)v140;
  *(_BYTE *)(*(_QWORD *)v140 + 16LL) = *(_BYTE *)(a4 + 24);
  v99[17] = *(_BYTE *)(a4 + 25);
  v99[18] = *(_BYTE *)(a4 + 26);
  v99[19] = *(_BYTE *)(a4 + 27);
  v99[20] = *(_BYTE *)(a4 + 28);
  v99[21] = *(_BYTE *)(a4 + 29);
  v100 = dot11f_pack_probe_response(v13, v20, *(_QWORD *)v140 + 24LL, v141, &v141);
  if ( (v100 & 0x10000000) == 0 )
  {
    if ( v100 )
      qdf_trace_msg(
        0x35u,
        3u,
        "%s: Probe Response pack warning (0x%08x)",
        v101,
        v102,
        v103,
        v104,
        v105,
        v106,
        v107,
        v108,
        "lim_send_probe_rsp_mgmt_frame");
    if ( (_WORD)v135 )
    {
      if ( (unsigned int)lim_fill_complete_tpe_ie(
                           *(unsigned int *)(a4 + 7176),
                           v135,
                           v39,
                           v137[0],
                           *(_QWORD *)v140 + v141 + 24LL) )
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: assemble tpe ie error",
          v101,
          v102,
          v103,
          v104,
          v105,
          v106,
          v107,
          v108,
          "lim_send_probe_rsp_mgmt_frame");
        v95 = 0;
      }
      v141 += v95;
    }
    v109 = v136;
    if ( (_WORD)v136 )
    {
      if ( (unsigned int)lim_fill_complete_mlo_ie(a4, v136, *(_QWORD *)v140 + v141 + 24LL) )
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: assemble ml ie error",
          v101,
          v102,
          v103,
          v104,
          v105,
          v106,
          v107,
          v108,
          "lim_send_probe_rsp_mgmt_frame");
        v109 = 0;
      }
      v141 += v109;
    }
    if ( a2 )
    {
      v110 = *a2;
      v111 = a2[1];
      v112 = a2[2];
      v113 = a2[5];
    }
    else
    {
      v112 = 0;
      v110 = 0;
      v111 = 0;
      v113 = 0;
    }
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Sending Probe Response frame to: %02x:%02x:%02x:**:**:%02x",
      v101,
      v102,
      v103,
      v104,
      v105,
      v106,
      v107,
      v108,
      "lim_send_probe_rsp_mgmt_frame",
      v110,
      v111,
      v112,
      v113);
    lim_add_additional_ie(*(_QWORD *)v140, v141 + 24, v45, v138[0], vendor_ie_ptr_from_oui, v144, v133, v145, v60);
    if ( wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a4 + 284)) && (*(_DWORD *)(a4 + 7036) & 0xFFFFFFFE) != 2 )
      v114 = 0;
    else
      v114 = 64;
    v115 = lim_reorder_vendor_ies(v13, *(_QWORD *)v140 + 36LL, v96 - 36);
    context = _cds_get_context(
                54,
                (__int64)"lim_send_probe_rsp_mgmt_frame",
                v115,
                v116,
                v117,
                v118,
                v119,
                v120,
                v121,
                v122);
    if ( (unsigned int)wma_tx_packet(
                         context,
                         v139,
                         v96,
                         3,
                         1,
                         7,
                         lim_tx_complete,
                         *(_QWORD *)v140,
                         0,
                         v114,
                         v134,
                         0,
                         0,
                         12,
                         0,
                         0) )
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Could not send Probe Response",
        v124,
        v125,
        v126,
        v127,
        v128,
        v129,
        v130,
        v131,
        "lim_send_probe_rsp_mgmt_frame");
    if ( v45 )
      _qdf_mem_free((__int64)v45);
    _qdf_mem_free(v39);
    v98 = v20;
    goto LABEL_84;
  }
  qdf_trace_msg(
    0x35u,
    2u,
    "%s: Probe Response pack failure (0x%08x)",
    v101,
    v102,
    v103,
    v104,
    v105,
    v106,
    v107,
    v108,
    "lim_send_probe_rsp_mgmt_frame",
    v100);
  if ( !v45 )
    goto LABEL_80;
LABEL_79:
  _qdf_mem_free((__int64)v45);
LABEL_80:
  _qdf_mem_free(v20);
  result = v139;
  if ( v139 )
    result = (_BYTE *)cds_packet_free((__int64)v139);
  if ( v39 )
  {
    v98 = v39;
LABEL_84:
    result = (_BYTE *)_qdf_mem_free(v98);
  }
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
