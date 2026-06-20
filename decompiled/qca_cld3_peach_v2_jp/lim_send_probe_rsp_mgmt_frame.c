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
  char v19; // w28
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
  __int64 v40; // x8
  __int64 v41; // x8
  unsigned __int8 *v42; // x0
  unsigned __int8 *v43; // x24
  size_t v44; // x27
  int v45; // w28
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  int v54; // w26
  unsigned __int8 *vendor_ie_ptr_from_oui; // x25
  unsigned int noa_attr_stream; // w0
  int v57; // w8
  unsigned __int8 v58; // w27
  int updated; // w0
  __int64 v60; // x0
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  char *v69; // x26
  unsigned __int8 *v70; // x28
  unsigned __int16 v71; // w24
  unsigned int v72; // w25
  unsigned int v73; // w5
  unsigned int v74; // w6
  __int64 v75; // x4
  double v76; // d0
  double v77; // d1
  double v78; // d2
  double v79; // d3
  double v80; // d4
  double v81; // d5
  double v82; // d6
  double v83; // d7
  unsigned int packed_probe_response_size; // w0
  double v85; // d0
  double v86; // d1
  double v87; // d2
  double v88; // d3
  double v89; // d4
  double v90; // d5
  double v91; // d6
  double v92; // d7
  unsigned int v93; // w26
  const char *v94; // x2
  __int64 v95; // x0
  _BYTE *v96; // x8
  unsigned int v97; // w0
  double v98; // d0
  double v99; // d1
  double v100; // d2
  double v101; // d3
  double v102; // d4
  double v103; // d5
  double v104; // d6
  double v105; // d7
  int v106; // w0
  unsigned __int16 v107; // w9
  __int64 v108; // x4
  __int64 v109; // x5
  __int64 v110; // x6
  __int64 v111; // x7
  char v112; // w21
  double v113; // d0
  double v114; // d1
  double v115; // d2
  double v116; // d3
  double v117; // d4
  double v118; // d5
  double v119; // d6
  double v120; // d7
  _QWORD *context; // x0
  double v122; // d0
  double v123; // d1
  double v124; // d2
  double v125; // d3
  double v126; // d4
  double v127; // d5
  double v128; // d6
  double v129; // d7
  unsigned __int8 *v130; // [xsp+40h] [xbp-B0h]
  char v131; // [xsp+4Ch] [xbp-A4h]
  unsigned __int8 v132; // [xsp+50h] [xbp-A0h]
  unsigned int tpe_ie_length; // [xsp+54h] [xbp-9Ch]
  unsigned __int16 v134[2]; // [xsp+58h] [xbp-98h] BYREF
  unsigned __int16 v135[2]; // [xsp+5Ch] [xbp-94h] BYREF
  _BYTE *v136; // [xsp+60h] [xbp-90h] BYREF
  int v137[2]; // [xsp+68h] [xbp-88h] BYREF
  unsigned int v138; // [xsp+74h] [xbp-7Ch] BYREF
  _QWORD v139[2]; // [xsp+78h] [xbp-78h] BYREF
  char v140; // [xsp+88h] [xbp-68h]
  _QWORD v141[5]; // [xsp+90h] [xbp-60h] BYREF
  _QWORD v142[7]; // [xsp+B8h] [xbp-38h] BYREF

  v142[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v136 = nullptr;
  v135[0] = 0;
  v140 = 0;
  v139[0] = 0;
  v139[1] = 0;
  v134[0] = 0;
  if ( !a4 )
    goto LABEL_7;
  v13 = (__int64)result;
  if ( *(_DWORD *)result == 1 )
    goto LABEL_7;
  v18 = *(_DWORD *)(a4 + 7036) | 2;
  v138 = 0;
  *(_QWORD *)v137 = 0;
  memset(v142, 0, 37);
  memset(v141, 0, 37);
  if ( v18 == 3 && result[14809] == 1 )
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
    v21 = (_WORD *)(*(_QWORD *)(v13 + 8) + 3200LL);
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
    if ( (*(_BYTE *)(*(_QWORD *)(v13 + 8) + 5584LL) & 1) != 0 )
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
      goto LABEL_75;
    populate_dot11f_tx_power_env(v13, a4, v39, *(unsigned int *)(a4 + 7176), *(unsigned int *)(a4 + 284), v134, 0);
    tpe_ie_length = lim_get_tpe_ie_length(*(unsigned int *)(a4 + 7176), v39, v134[0]);
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
  populate_dot11f_ext_cap(v13, v30 != 0, v20 + 1142, a4);
  v40 = *(_QWORD *)(a4 + 104);
  if ( v40 )
  {
    populate_dot11f_wpa(v13, v40 + 56, v20 + 3118);
    populate_dot11f_rsn_opaque(v13, *(_QWORD *)(a4 + 104) + 56LL, v20 + 619);
  }
  populate_dot11f_wmm(v13, v20 + 3166, v20 + 3170, v20 + 3190, a4);
  v41 = *(_QWORD *)(a4 + 104);
  if ( v41 )
    populate_dot11f_wapi(v13, v41 + 56, v20 + 2122);
  if ( !*(_WORD *)(a4 + 7288) )
  {
    v132 = 0;
    v58 = 0;
    vendor_ie_ptr_from_oui = nullptr;
    v43 = nullptr;
    v54 = 0;
    goto LABEL_67;
  }
  v42 = (unsigned __int8 *)_qdf_mem_malloc(*(unsigned __int16 *)(a4 + 7288), "lim_send_probe_rsp_mgmt_frame", 846);
  if ( !v42 )
    goto LABEL_75;
  v43 = v42;
  qdf_mem_copy(v42, *(const void **)(a4 + 7296), *(unsigned __int16 *)(a4 + 7288));
  v44 = *(unsigned __int16 *)(a4 + 7288);
  v135[0] = *(_WORD *)(a4 + 7288);
  if ( !a5 )
  {
    v60 = _qdf_mem_malloc(v44, "lim_get_addn_ie_for_probe_resp", 518);
    if ( v60 )
    {
      v69 = (char *)v60;
      v130 = v43;
      v131 = v19;
      if ( (unsigned int)v44 < 2 )
      {
        v71 = 0;
LABEL_62:
        qdf_mem_copy(v130, v69, v71);
        v135[0] = v71;
        v43 = v130;
        _qdf_mem_free((__int64)v69);
        updated = lim_strip_extcap_update_struct(v13, v130, v135, v139);
        if ( updated )
        {
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: Unable to strip off ExtCap IE",
            v76,
            v77,
            v78,
            v79,
            v80,
            v81,
            v82,
            v83,
            "lim_send_probe_rsp_mgmt_frame");
          v54 = v135[0];
          v132 = 0;
          v58 = 0;
          vendor_ie_ptr_from_oui = nullptr;
          goto LABEL_66;
        }
        v54 = v135[0];
        v58 = 0;
        vendor_ie_ptr_from_oui = nullptr;
        goto LABEL_65;
      }
      v70 = v43;
      v71 = 0;
      while ( 1 )
      {
        v73 = v70[1];
        v74 = v44 - 2;
        v75 = *v70;
        LODWORD(v44) = v44 - 2 - v73;
        if ( v74 < v73 )
          break;
        if ( (_DWORD)v75 == 221 && *(_DWORD *)(v70 + 2) == 161115984 )
        {
          v72 = v73 + 2;
        }
        else
        {
          v72 = v73 + 2;
          qdf_mem_copy(&v69[v71], v70, v73 + 2);
          v71 += v72;
        }
        v70 += v72;
        if ( (int)v44 <= 1 )
          goto LABEL_62;
      }
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Invalid IEs eid: %d elem_len: %d left: %d",
        v61,
        v62,
        v63,
        v64,
        v65,
        v66,
        v67,
        v68,
        "lim_get_addn_ie_for_probe_resp",
        v75);
      _qdf_mem_free((__int64)v69);
      v43 = v130;
    }
    v94 = "%s: Unable to get addn_ie";
LABEL_73:
    qdf_trace_msg(0x35u, 2u, v94, v61, v62, v63, v64, v65, v66, v67, v68, "lim_send_probe_rsp_mgmt_frame");
    if ( !v43 )
      goto LABEL_75;
    goto LABEL_74;
  }
  v131 = v19;
  v45 = lim_strip_extcap_update_struct(v13, v43, v135, v139);
  if ( v45 )
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Unable to strip off ExtCap IE",
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      "lim_send_probe_rsp_mgmt_frame");
  v54 = v135[0];
  vendor_ie_ptr_from_oui = wlan_get_vendor_ie_ptr_from_oui(&unk_89A401, 4u, v43, v135[0]);
  if ( vendor_ie_ptr_from_oui )
  {
    noa_attr_stream = lim_get_noa_attr_stream(v13, v142, a4);
    if ( (_BYTE)noa_attr_stream )
    {
      v57 = (unsigned __int8)noa_attr_stream;
      v58 = noa_attr_stream;
      if ( vendor_ie_ptr_from_oui[1] + (unsigned int)(unsigned __int8)noa_attr_stream >= 0x100 )
      {
        LOBYTE(updated) = lim_build_p2p_ie(v13, v141, v142, noa_attr_stream);
        v54 += (unsigned __int8)updated;
        if ( !v45 )
          goto LABEL_65;
        goto LABEL_60;
      }
      LOBYTE(updated) = 0;
      v54 += v57;
      if ( v45 )
      {
LABEL_60:
        v132 = updated;
        goto LABEL_66;
      }
LABEL_65:
      v132 = updated;
      lim_merge_extcap_struct(v20 + 1142, v139, 1);
      populate_dot11f_twt_extended_caps(v13, a4, v20 + 1142);
      goto LABEL_66;
    }
  }
  LOBYTE(updated) = 0;
  v58 = 0;
  if ( !v45 )
    goto LABEL_65;
  v58 = 0;
  v132 = 0;
LABEL_66:
  v19 = v131;
LABEL_67:
  populate_dot11f_bcn_prot_extcaps(v13, a4, v20 + 1142);
  packed_probe_response_size = dot11f_get_packed_probe_response_size(v13, v20, &v138);
  if ( (packed_probe_response_size & 0x10000000) != 0 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Probe Response size error (0x%08x)",
      v85,
      v86,
      v87,
      v88,
      v89,
      v90,
      v91,
      v92,
      "lim_send_probe_rsp_mgmt_frame",
      packed_probe_response_size);
    v138 = 5032;
  }
  else if ( packed_probe_response_size )
  {
    qdf_trace_msg(
      0x35u,
      3u,
      "%s: Probe Response size warning (0x%08x)",
      v85,
      v86,
      v87,
      v88,
      v89,
      v90,
      v91,
      v92,
      "lim_send_probe_rsp_mgmt_frame");
  }
  v93 = v54 + (unsigned __int16)tpe_ie_length + v138 + 24;
  if ( (unsigned int)cds_packet_alloc(v93, v137, &v136) )
  {
    v94 = "%s: Probe Response allocation failed";
    goto LABEL_73;
  }
  qdf_mem_set(*(void **)v137, v93, 0);
  lim_populate_mac_header(v13, *(__int64 *)v137, 0, 5, a2, (_BYTE *)(a4 + 30));
  v96 = *(_BYTE **)v137;
  *(_BYTE *)(*(_QWORD *)v137 + 16LL) = *(_BYTE *)(a4 + 24);
  v96[17] = *(_BYTE *)(a4 + 25);
  v96[18] = *(_BYTE *)(a4 + 26);
  v96[19] = *(_BYTE *)(a4 + 27);
  v96[20] = *(_BYTE *)(a4 + 28);
  v96[21] = *(_BYTE *)(a4 + 29);
  v97 = dot11f_pack_probe_response(v13, v20, *(_QWORD *)v137 + 24LL, v138, &v138);
  if ( (v97 & 0x10000000) == 0 )
  {
    if ( v97 )
      qdf_trace_msg(
        0x35u,
        3u,
        "%s: Probe Response pack warning (0x%08x)",
        v98,
        v99,
        v100,
        v101,
        v102,
        v103,
        v104,
        v105,
        "lim_send_probe_rsp_mgmt_frame");
    if ( (_WORD)tpe_ie_length )
    {
      v106 = lim_fill_complete_tpe_ie(
               *(unsigned int *)(a4 + 7176),
               tpe_ie_length,
               v39,
               v134[0],
               *(_QWORD *)v137 + v138 + 24LL);
      v107 = tpe_ie_length;
      if ( v106 )
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: assemble tpe ie error",
          v98,
          v99,
          v100,
          v101,
          v102,
          v103,
          v104,
          v105,
          "lim_send_probe_rsp_mgmt_frame");
        v107 = 0;
      }
      v138 += v107;
    }
    if ( a2 )
    {
      v108 = *a2;
      v109 = a2[1];
      v110 = a2[2];
      v111 = a2[5];
    }
    else
    {
      v110 = 0;
      v108 = 0;
      v109 = 0;
      v111 = 0;
    }
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Sending Probe Response frame to: %02x:%02x:%02x:**:**:%02x",
      v98,
      v99,
      v100,
      v101,
      v102,
      v103,
      v104,
      v105,
      "lim_send_probe_rsp_mgmt_frame",
      v108,
      v109,
      v110,
      v111);
    lim_add_additional_ie(*(_QWORD *)v137, v138 + 24, v43, v135[0], vendor_ie_ptr_from_oui, v141, v132, v142, v58);
    if ( wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a4 + 284)) && (*(_DWORD *)(a4 + 7036) & 0xFFFFFFFE) != 2 )
      v112 = 0;
    else
      v112 = 64;
    v113 = lim_reorder_vendor_ies(v13, *(_QWORD *)v137 + 36LL, v93 - 36);
    context = _cds_get_context(
                54,
                (__int64)"lim_send_probe_rsp_mgmt_frame",
                v113,
                v114,
                v115,
                v116,
                v117,
                v118,
                v119,
                v120);
    if ( (unsigned int)wma_tx_packet(
                         context,
                         v136,
                         v93,
                         3,
                         1,
                         7,
                         lim_tx_complete,
                         *(_QWORD *)v137,
                         0,
                         v112,
                         v19,
                         0,
                         0,
                         12,
                         0,
                         0) )
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Could not send Probe Response",
        v122,
        v123,
        v124,
        v125,
        v126,
        v127,
        v128,
        v129,
        "lim_send_probe_rsp_mgmt_frame");
    if ( v43 )
      _qdf_mem_free((__int64)v43);
    _qdf_mem_free(v39);
    v95 = v20;
    goto LABEL_79;
  }
  qdf_trace_msg(
    0x35u,
    2u,
    "%s: Probe Response pack failure (0x%08x)",
    v98,
    v99,
    v100,
    v101,
    v102,
    v103,
    v104,
    v105,
    "lim_send_probe_rsp_mgmt_frame",
    v97);
  if ( !v43 )
    goto LABEL_75;
LABEL_74:
  _qdf_mem_free((__int64)v43);
LABEL_75:
  _qdf_mem_free(v20);
  result = v136;
  if ( v136 )
    result = (_BYTE *)cds_packet_free((__int64)v136);
  if ( v39 )
  {
    v95 = v39;
LABEL_79:
    result = (_BYTE *)_qdf_mem_free(v95);
  }
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
