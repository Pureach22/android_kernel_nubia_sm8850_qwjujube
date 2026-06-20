__int64 __fastcall lim_send_probe_rsp_template_to_hal(__int64 a1, __int64 a2, const void *a3)
{
  size_t v6; // x25
  _BYTE *v7; // x22
  char *v8; // x0
  unsigned int v9; // w26
  unsigned __int8 *v10; // x23
  char *v11; // x24
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  int v20; // w21
  unsigned int v21; // w28
  __int64 v22; // x19
  unsigned int v23; // w8
  __int64 v24; // x19
  unsigned __int8 *v25; // x0
  unsigned __int8 *v26; // x27
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 result; // x0
  __int64 v36; // x0
  unsigned int packed_probe_response_size; // w0
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  __int64 v46; // x0
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  __int64 v55; // x8
  unsigned int v56; // w26
  unsigned __int16 v57; // w9
  unsigned __int16 v58; // w21
  unsigned __int8 *ie_ptr_from_eid; // x0
  __int16 v60; // w27
  unsigned int v61; // w28
  _BOOL4 v62; // w19
  unsigned int frame_mlo_ie_len; // w0
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  int v72; // w27
  int v73; // w8
  _BOOL4 v74; // w10
  bool v75; // w23
  unsigned int v76; // w28
  const char *v77; // x2
  __int64 v78; // x4
  unsigned int v79; // w25
  unsigned int v80; // w0
  unsigned __int8 *ext_ie_ptr_from_ext_id; // x0
  unsigned int v82; // w28
  unsigned __int8 *v83; // x0
  unsigned int v84; // w28
  double v85; // d0
  double v86; // d1
  double v87; // d2
  double v88; // d3
  double v89; // d4
  double v90; // d5
  double v91; // d6
  double v92; // d7
  unsigned int v93; // w23
  _BYTE *v94; // x0
  double v95; // d0
  double v96; // d1
  double v97; // d2
  double v98; // d3
  double v99; // d4
  double v100; // d5
  double v101; // d6
  double v102; // d7
  __int64 v103; // x24
  double v104; // d0
  double v105; // d1
  double v106; // d2
  double v107; // d3
  double v108; // d4
  double v109; // d5
  double v110; // d6
  double v111; // d7
  double v112; // d0
  double v113; // d1
  double v114; // d2
  double v115; // d3
  double v116; // d4
  double v117; // d5
  double v118; // d6
  double v119; // d7
  unsigned int v120; // w19
  __int64 v121; // [xsp+8h] [xbp-88h]
  unsigned __int16 v122; // [xsp+14h] [xbp-7Ch]
  unsigned __int8 *v123; // [xsp+18h] [xbp-78h]
  const void *v124; // [xsp+20h] [xbp-70h]
  const void *v125; // [xsp+20h] [xbp-70h]
  __int64 v126; // [xsp+28h] [xbp-68h]
  __int64 v127; // [xsp+28h] [xbp-68h]
  unsigned __int16 v128[2]; // [xsp+34h] [xbp-5Ch] BYREF
  unsigned __int16 n; // [xsp+38h] [xbp-58h] BYREF
  unsigned int n_4; // [xsp+3Ch] [xbp-54h] BYREF
  __int64 v131; // [xsp+40h] [xbp-50h] BYREF
  __int64 v132; // [xsp+48h] [xbp-48h]
  __int64 v133; // [xsp+50h] [xbp-40h]
  __int64 v134; // [xsp+58h] [xbp-38h]
  __int64 v135; // [xsp+60h] [xbp-30h]
  __int64 v136; // [xsp+68h] [xbp-28h]
  _QWORD v137[2]; // [xsp+70h] [xbp-20h] BYREF
  char v138; // [xsp+80h] [xbp-10h]
  __int64 v139; // [xsp+88h] [xbp-8h]

  v139 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(unsigned __int16 *)(a2 + 7288);
  v7 = *(_BYTE **)(a2 + 7336);
  v135 = 0;
  v136 = 0;
  v133 = 0;
  v134 = 0;
  v131 = 0;
  v132 = 0;
  n_4 = 0;
  v138 = 0;
  v137[0] = 0;
  v137[1] = 0;
  n = 0;
  v128[0] = 0;
  if ( v6 )
  {
    v8 = (char *)_qdf_mem_malloc(v6, "lim_send_probe_rsp_template_to_hal", 830);
    if ( !v8 )
    {
      result = 2;
      goto LABEL_68;
    }
    v9 = *(unsigned __int16 *)(a2 + 7288);
    v10 = *(unsigned __int8 **)(a2 + 7296);
    v11 = v8;
    v124 = a3;
    v126 = a1;
    qdf_mem_copy(v8, v10, *(unsigned __int16 *)(a2 + 7288));
    if ( v9 >= 2 )
    {
      v20 = 0;
      v21 = v9;
      while ( 1 )
      {
        v22 = v10[1];
        v23 = v21 - 2;
        v21 = v21 - 2 - v22;
        if ( v23 < (unsigned int)v22 )
          break;
        if ( *v10 != 221 || (unsigned int)qdf_mem_cmp(v10 + 2, &unk_969516, 4u) )
        {
          v10 += v22 + 2;
          v20 += v22 + 2;
          if ( v21 <= 1 )
            goto LABEL_10;
        }
        else
        {
          v24 = v22 + 2;
          v10 += v24;
          qdf_mem_copy(&v11[v20], v10, v21);
          v9 -= v24;
          if ( v21 <= 1 )
            goto LABEL_10;
        }
      }
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Invalid IEs",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "lim_remove_p2p_ie_from_add_ie");
      goto LABEL_66;
    }
LABEL_10:
    v25 = (unsigned __int8 *)_qdf_mem_malloc(v9, "lim_send_probe_rsp_template_to_hal", 843);
    if ( !v25 )
    {
      v36 = (__int64)v11;
LABEL_36:
      _qdf_mem_free(v36);
      result = 2;
      goto LABEL_68;
    }
    v26 = v25;
    n = v9;
    if ( (unsigned int)(unsigned __int16)v9 - 1 <= 0xFE )
      qdf_mem_copy(v25, v11, v9);
    _qdf_mem_free((__int64)v11);
    qdf_mem_set(v137, 0x11u, 0);
    a1 = v126;
    if ( (unsigned int)lim_strip_extcap_update_struct(v126, v26, &n, (__int64)v137) )
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: extcap not extracted",
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        "lim_send_probe_rsp_template_to_hal");
    }
    else
    {
      lim_merge_extcap_struct(a2 + 3130, v137, 1, v27, v28, v29, v30, v31, v32, v33, v34);
      populate_dot11f_bcn_prot_extcaps(v126, a2, a2 + 3130);
      populate_dot11f_twt_extended_caps(v126, a2, a2 + 3130);
    }
    a3 = v124;
  }
  else
  {
    v26 = nullptr;
  }
  packed_probe_response_size = dot11f_get_packed_probe_response_size(a1, a2 + 1988, &n_4);
  if ( (packed_probe_response_size & 0x10000000) != 0 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Failed to calculate the packed size for a Probe Response (0x%08x)",
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      "lim_send_probe_rsp_template_to_hal",
      packed_probe_response_size);
    n_4 = 5032;
  }
  else if ( packed_probe_response_size )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: There were warnings while calculating the packed size for a Probe Response (0x%08x)",
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      "lim_send_probe_rsp_template_to_hal");
  }
  v46 = _qdf_mem_malloc(0xD8u, "lim_send_probe_rsp_template_to_hal", 904);
  if ( !v46 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Malloc failed for TPE IE",
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      "lim_send_probe_rsp_template_to_hal");
    v36 = (__int64)v26;
    goto LABEL_36;
  }
  v55 = *(_QWORD *)(a2 + 7352);
  v11 = (char *)v46;
  v123 = v26;
  v125 = a3;
  v56 = 0;
  v57 = 0;
  v58 = 0;
  v127 = a1;
  do
  {
    ie_ptr_from_eid = wlan_get_ie_ptr_from_eid(0xC3u, (unsigned __int8 *)(v55 + v57), *(_WORD *)(a2 + 7362) - v57);
    if ( !ie_ptr_from_eid )
      break;
    v60 = (__int16)ie_ptr_from_eid;
    v61 = ie_ptr_from_eid[1] + 2;
    if ( 216 - v56 < v61 )
      break;
    qdf_mem_copy(&v11[v58], ie_ptr_from_eid, v61);
    v58 += v61;
    v55 = *(_QWORD *)(a2 + 7352);
    v56 = v58;
    v57 = v61 + v60 - v55;
  }
  while ( v58 < 0xD8u );
  v62 = v6 != 0;
  frame_mlo_ie_len = lim_get_frame_mlo_ie_len(a2);
  v72 = (unsigned __int16)frame_mlo_ie_len;
  v73 = v56 + n_4 + (unsigned __int16)frame_mlo_ie_len + 24;
  v74 = v73 + (unsigned int)n < 0x201;
  v75 = v62 && v74;
  if ( v62 && v74 )
    v76 = v73 + n;
  else
    v76 = v56 + n_4 + (unsigned __int16)frame_mlo_ie_len + 24;
  if ( v76 >= 0x201 )
  {
    v77 = "%s: nBytes %d greater than max size";
    v78 = v76;
LABEL_65:
    qdf_trace_msg(0x35u, 2u, v77, v64, v65, v66, v67, v68, v69, v70, v71, "lim_send_probe_rsp_template_to_hal", v78);
    _qdf_mem_free((__int64)v123);
LABEL_66:
    _qdf_mem_free((__int64)v11);
LABEL_67:
    result = 16;
    goto LABEL_68;
  }
  v79 = frame_mlo_ie_len;
  qdf_mem_set(v7, v76, 0);
  lim_populate_mac_header(v127, (__int64)v7, 0, 5, (const void *)(a2 + 30), (_BYTE *)(a2 + 30));
  v7[16] = *(_BYTE *)(a2 + 24);
  v7[17] = *(_BYTE *)(a2 + 25);
  v7[18] = *(_BYTE *)(a2 + 26);
  v7[19] = *(_BYTE *)(a2 + 27);
  v7[20] = *(_BYTE *)(a2 + 28);
  v7[21] = *(_BYTE *)(a2 + 29);
  v80 = dot11f_pack_probe_response(v127, a2 + 1988, v7 + 24, n_4, &n_4);
  v78 = v80;
  if ( (v80 & 0x10000000) != 0 )
  {
    v77 = "%s: Failed to pack a Probe Response (0x%08x)";
    goto LABEL_65;
  }
  if ( v80 )
    qdf_trace_msg(
      0x35u,
      3u,
      "%s: There were warnings while packing a Probe Response (0x%08x)",
      v64,
      v65,
      v66,
      v67,
      v68,
      v69,
      v70,
      v71,
      "lim_send_probe_rsp_template_to_hal");
  v121 = (__int64)(v7 + 36);
  v128[0] = n_4 - 12;
  v122 = v76 - 36;
  if ( a2 )
  {
    if ( *(_BYTE *)(a2 + 10071) == 1 )
    {
      lim_strip_eht_op_ie(v127, v121, (__int64)v128, 0);
      ext_ie_ptr_from_ext_id = wlan_get_ext_ie_ptr_from_ext_id(
                                 "j",
                                 1u,
                                 *(unsigned __int8 **)(a2 + 7352),
                                 *(_WORD *)(a2 + 7362));
      if ( ext_ie_ptr_from_ext_id )
      {
        v82 = ext_ie_ptr_from_ext_id[1] + 2;
        if ( v82 + v128[0] <= v122 )
        {
          qdf_mem_copy((void *)(v121 + v128[0]), ext_ie_ptr_from_ext_id, v82);
          v128[0] += v82;
          lim_strip_eht_cap_ie(v127, v121, (__int64)v128, 0);
          v83 = wlan_get_ext_ie_ptr_from_ext_id("l", 1u, *(unsigned __int8 **)(a2 + 7352), *(_WORD *)(a2 + 7362));
          if ( v83 )
          {
            v84 = v83[1] + 2;
            if ( v84 + v128[0] <= v122 )
            {
              qdf_mem_copy((void *)(v121 + v128[0]), v83, v84);
              v128[0] += v84;
            }
          }
        }
      }
    }
  }
  if ( (_WORD)v79 && (unsigned int)v128[0] + v72 <= v122 )
  {
    if ( (unsigned int)lim_fill_complete_mlo_ie(a2, v79, v121 + v128[0]) )
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: assemble ml ie error",
        v85,
        v86,
        v87,
        v88,
        v89,
        v90,
        v91,
        v92,
        "lim_send_probe_rsp_template_to_hal");
      LOWORD(v79) = 0;
    }
    v128[0] += v79;
  }
  if ( (unsigned __int16)(v58 - 1) <= 0xD7u && v56 + v128[0] <= v122 )
  {
    qdf_mem_copy((void *)(v121 + v128[0]), v11, v56);
    v128[0] += v58;
  }
  _qdf_mem_free((__int64)v11);
  if ( v75 && n + (unsigned int)v128[0] <= v122 )
  {
    qdf_mem_copy((void *)(v121 + v128[0]), v123, n);
    v128[0] += n;
  }
  _qdf_mem_free((__int64)v123);
  lim_reorder_vendor_ies(v127, v121, v128[0]);
  v93 = v128[0] + 36;
  v94 = (_BYTE *)_qdf_mem_malloc(0x230u, "lim_send_probe_rsp_template_to_hal", 1037);
  if ( !v94 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: malloc failed for bytes %d",
      v95,
      v96,
      v97,
      v98,
      v99,
      v100,
      v101,
      v102,
      "lim_send_probe_rsp_template_to_hal",
      v93);
    goto LABEL_67;
  }
  v103 = (__int64)v94;
  *v94 = *(_BYTE *)(a2 + 24);
  v94[1] = *(_BYTE *)(a2 + 25);
  v94[2] = *(_BYTE *)(a2 + 26);
  v94[3] = *(_BYTE *)(a2 + 27);
  v94[4] = *(_BYTE *)(a2 + 28);
  v94[5] = *(_BYTE *)(a2 + 29);
  qdf_mem_copy(v94 + 6, v7, v93);
  *(_DWORD *)(v103 + 520) = v93;
  qdf_mem_copy((void *)(v103 + 524), v125, 0x20u);
  if ( *(_DWORD *)(a2 + 7036) == 3 && (cfg_p2p_is_go_ignore_non_p2p_probe_req(*(_QWORD *)(v127 + 21624)) & 1) != 0 )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: GO ignore non-P2P probe req",
      v104,
      v105,
      v106,
      v107,
      v108,
      v109,
      v110,
      v111,
      "lim_send_probe_rsp_template_to_hal");
    *(_BYTE *)(v103 + 556) = 1;
  }
  v131 = 4222;
  v132 = v103;
  result = wma_post_ctrl_msg(v127, &v131);
  if ( (_DWORD)result )
  {
    v120 = result;
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: FAIL bytes %d retcode[%X]",
      v112,
      v113,
      v114,
      v115,
      v116,
      v117,
      v118,
      v119,
      "lim_send_probe_rsp_template_to_hal",
      v93,
      (unsigned int)result);
    _qdf_mem_free(v103);
    result = v120;
  }
LABEL_68:
  _ReadStatusReg(SP_EL0);
  return result;
}
