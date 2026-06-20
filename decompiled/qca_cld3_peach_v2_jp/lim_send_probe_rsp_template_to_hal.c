__int64 __fastcall lim_send_probe_rsp_template_to_hal(__int64 a1, __int64 a2, const void *a3)
{
  size_t v6; // x24
  _BYTE *v7; // x22
  char *v8; // x0
  unsigned int v9; // w26
  unsigned __int8 *v10; // x23
  char *v11; // x25
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
  unsigned __int8 *v26; // x23
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  unsigned int packed_probe_response_size; // w0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  __int64 v44; // x0
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  __int64 v53; // x8
  unsigned int v54; // w26
  unsigned __int16 v55; // w9
  unsigned __int16 v56; // w21
  unsigned __int8 *ie_ptr_from_eid; // x0
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  __int16 v66; // w27
  unsigned int v67; // w28
  _BOOL4 v68; // w10
  int v69; // w8
  _BOOL4 v70; // w11
  bool v71; // w28
  unsigned int v72; // w24
  const char *v73; // x2
  __int64 v74; // x4
  __int64 result; // x0
  __int64 v76; // x0
  unsigned int v77; // w0
  unsigned __int16 v78; // w19
  unsigned __int16 v79; // w27
  __int64 v80; // x24
  bool v81; // cc
  __int64 v82; // x19
  unsigned int v83; // w23
  _BYTE *v84; // x0
  double v85; // d0
  double v86; // d1
  double v87; // d2
  double v88; // d3
  double v89; // d4
  double v90; // d5
  double v91; // d6
  double v92; // d7
  __int64 v93; // x24
  double v94; // d0
  double v95; // d1
  double v96; // d2
  double v97; // d3
  double v98; // d4
  double v99; // d5
  double v100; // d6
  double v101; // d7
  double v102; // d0
  double v103; // d1
  double v104; // d2
  double v105; // d3
  double v106; // d4
  double v107; // d5
  double v108; // d6
  double v109; // d7
  unsigned int v110; // w19
  const void *v111; // [xsp+8h] [xbp-68h]
  __int64 v112; // [xsp+10h] [xbp-60h]
  __int64 v113; // [xsp+10h] [xbp-60h]
  unsigned __int16 n; // [xsp+18h] [xbp-58h] BYREF
  unsigned int n_4; // [xsp+1Ch] [xbp-54h] BYREF
  __int64 v116; // [xsp+20h] [xbp-50h] BYREF
  __int64 v117; // [xsp+28h] [xbp-48h]
  __int64 v118; // [xsp+30h] [xbp-40h]
  __int64 v119; // [xsp+38h] [xbp-38h]
  __int64 v120; // [xsp+40h] [xbp-30h]
  __int64 v121; // [xsp+48h] [xbp-28h]
  _QWORD v122[2]; // [xsp+50h] [xbp-20h] BYREF
  char v123; // [xsp+60h] [xbp-10h]
  __int64 v124; // [xsp+68h] [xbp-8h]

  v124 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(unsigned __int16 *)(a2 + 7288);
  v7 = *(_BYTE **)(a2 + 7336);
  v120 = 0;
  v121 = 0;
  v118 = 0;
  v119 = 0;
  v116 = 0;
  v117 = 0;
  n_4 = 0;
  v123 = 0;
  v122[0] = 0;
  v122[1] = 0;
  n = 0;
  if ( v6 )
  {
    v8 = (char *)_qdf_mem_malloc(v6, "lim_send_probe_rsp_template_to_hal", 830);
    if ( !v8 )
    {
      result = 2;
      goto LABEL_45;
    }
    v9 = *(unsigned __int16 *)(a2 + 7288);
    v10 = *(unsigned __int8 **)(a2 + 7296);
    v11 = v8;
    v111 = a3;
    v112 = a1;
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
        if ( *v10 != 221 || (unsigned int)qdf_mem_cmp(v10 + 2, &unk_89A401, 4u) )
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
      goto LABEL_43;
    }
LABEL_10:
    v25 = (unsigned __int8 *)_qdf_mem_malloc(v9, "lim_send_probe_rsp_template_to_hal", 843);
    if ( !v25 )
    {
      v76 = (__int64)v11;
      goto LABEL_39;
    }
    v26 = v25;
    n = v9;
    if ( (unsigned int)(unsigned __int16)v9 - 1 <= 0xFE )
      qdf_mem_copy(v25, v11, v9);
    _qdf_mem_free((__int64)v11);
    qdf_mem_set(v122, 0x11u, 0);
    a1 = v112;
    if ( (unsigned int)lim_strip_extcap_update_struct(v112, v26, &n, (__int64)v122) )
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
      lim_merge_extcap_struct(a2 + 3130, v122, 1, v27, v28, v29, v30, v31, v32, v33, v34);
      populate_dot11f_bcn_prot_extcaps(v112, a2, a2 + 3130);
      populate_dot11f_twt_extended_caps(v112, a2, a2 + 3130);
    }
  }
  else
  {
    v111 = a3;
    v26 = nullptr;
  }
  packed_probe_response_size = dot11f_get_packed_probe_response_size(a1, a2 + 1988, &n_4);
  if ( (packed_probe_response_size & 0x10000000) != 0 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Failed to calculate the packed size for a Probe Response (0x%08x)",
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
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
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      "lim_send_probe_rsp_template_to_hal");
  }
  v44 = _qdf_mem_malloc(0xD8u, "lim_send_probe_rsp_template_to_hal", 904);
  if ( !v44 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Malloc failed for TPE IE",
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      "lim_send_probe_rsp_template_to_hal");
    v76 = (__int64)v26;
LABEL_39:
    _qdf_mem_free(v76);
    result = 2;
    goto LABEL_45;
  }
  v53 = *(_QWORD *)(a2 + 7352);
  v11 = (char *)v44;
  v113 = a1;
  v54 = 0;
  v55 = 0;
  v56 = 0;
  do
  {
    ie_ptr_from_eid = wlan_get_ie_ptr_from_eid(0xC3u, (unsigned __int8 *)(v53 + v55), *(_WORD *)(a2 + 7362) - v55);
    if ( !ie_ptr_from_eid )
      break;
    v66 = (__int16)ie_ptr_from_eid;
    v67 = ie_ptr_from_eid[1] + 2;
    if ( 216 - v54 < v67 )
      break;
    qdf_mem_copy(&v11[v56], ie_ptr_from_eid, v67);
    v56 += v67;
    v53 = *(_QWORD *)(a2 + 7352);
    v54 = v56;
    v55 = v67 + v66 - v53;
  }
  while ( v56 < 0xD8u );
  v68 = v6 != 0;
  v69 = v54 + n_4 + 24;
  v70 = v69 + (unsigned int)n < 0x201;
  v71 = v68 && v70;
  if ( v68 && v70 )
    v72 = v69 + n;
  else
    v72 = v54 + n_4 + 24;
  if ( v72 >= 0x201 )
  {
    v73 = "%s: nBytes %d greater than max size";
    v74 = v72;
LABEL_42:
    qdf_trace_msg(0x35u, 2u, v73, v58, v59, v60, v61, v62, v63, v64, v65, "lim_send_probe_rsp_template_to_hal", v74);
    _qdf_mem_free((__int64)v26);
LABEL_43:
    _qdf_mem_free((__int64)v11);
LABEL_44:
    result = 16;
    goto LABEL_45;
  }
  qdf_mem_set(v7, v72, 0);
  lim_populate_mac_header(v113, (__int64)v7, 0, 5, (const void *)(a2 + 30), (_BYTE *)(a2 + 30));
  v7[16] = *(_BYTE *)(a2 + 24);
  v7[17] = *(_BYTE *)(a2 + 25);
  v7[18] = *(_BYTE *)(a2 + 26);
  v7[19] = *(_BYTE *)(a2 + 27);
  v7[20] = *(_BYTE *)(a2 + 28);
  v7[21] = *(_BYTE *)(a2 + 29);
  v77 = dot11f_pack_probe_response(v113, a2 + 1988, v7 + 24, n_4, &n_4);
  v74 = v77;
  if ( (v77 & 0x10000000) != 0 )
  {
    v73 = "%s: Failed to pack a Probe Response (0x%08x)";
    goto LABEL_42;
  }
  if ( v77 )
    qdf_trace_msg(
      0x35u,
      3u,
      "%s: There were warnings while packing a Probe Response (0x%08x)",
      v58,
      v59,
      v60,
      v61,
      v62,
      v63,
      v64,
      v65,
      "lim_send_probe_rsp_template_to_hal");
  v78 = v72 - 36;
  v79 = n_4 - 12;
  if ( (unsigned __int16)(v56 - 1) > 0xD7u )
  {
    v80 = (__int64)(v7 + 36);
  }
  else
  {
    v80 = (__int64)(v7 + 36);
    if ( v54 + v79 <= v78 )
    {
      qdf_mem_copy(&v7[v79 + 36], v11, v54);
      v79 += v56;
    }
  }
  _qdf_mem_free((__int64)v11);
  if ( v71 )
  {
    v81 = n + (unsigned int)v79 > v78;
    v82 = v113;
    if ( !v81 )
    {
      qdf_mem_copy((void *)(v80 + v79), v26, n);
      v79 += n;
    }
  }
  else
  {
    v82 = v113;
  }
  _qdf_mem_free((__int64)v26);
  lim_reorder_vendor_ies(v82, v80, v79);
  v83 = v79 + 36;
  v84 = (_BYTE *)_qdf_mem_malloc(0x230u, "lim_send_probe_rsp_template_to_hal", 1037);
  if ( !v84 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: malloc failed for bytes %d",
      v85,
      v86,
      v87,
      v88,
      v89,
      v90,
      v91,
      v92,
      "lim_send_probe_rsp_template_to_hal",
      v83);
    goto LABEL_44;
  }
  v93 = (__int64)v84;
  *v84 = *(_BYTE *)(a2 + 24);
  v84[1] = *(_BYTE *)(a2 + 25);
  v84[2] = *(_BYTE *)(a2 + 26);
  v84[3] = *(_BYTE *)(a2 + 27);
  v84[4] = *(_BYTE *)(a2 + 28);
  v84[5] = *(_BYTE *)(a2 + 29);
  qdf_mem_copy(v84 + 6, v7, v83);
  *(_DWORD *)(v93 + 520) = v83;
  qdf_mem_copy((void *)(v93 + 524), v111, 0x20u);
  if ( *(_DWORD *)(a2 + 7036) == 3 && (cfg_p2p_is_go_ignore_non_p2p_probe_req(*(_QWORD *)(v82 + 21552)) & 1) != 0 )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: GO ignore non-P2P probe req",
      v94,
      v95,
      v96,
      v97,
      v98,
      v99,
      v100,
      v101,
      "lim_send_probe_rsp_template_to_hal");
    *(_BYTE *)(v93 + 556) = 1;
  }
  v116 = 4222;
  v117 = v93;
  result = wma_post_ctrl_msg(v82, &v116);
  if ( (_DWORD)result )
  {
    v110 = result;
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: FAIL bytes %d retcode[%X]",
      v102,
      v103,
      v104,
      v105,
      v106,
      v107,
      v108,
      v109,
      "lim_send_probe_rsp_template_to_hal",
      v83,
      (unsigned int)result);
    _qdf_mem_free(v93);
    result = v110;
  }
LABEL_45:
  _ReadStatusReg(SP_EL0);
  return result;
}
