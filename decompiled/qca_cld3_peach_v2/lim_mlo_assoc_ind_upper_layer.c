__int64 __fastcall lim_mlo_assoc_ind_upper_layer(
        __int64 result,
        __int64 a2,
        _BYTE *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v13; // x22
  unsigned __int64 v14; // x28
  unsigned __int8 *v15; // x23
  __int64 partner_session_by_link_id; // x0
  __int64 v17; // x19
  __int64 v18; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x24
  __int64 v28; // x0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  unsigned __int8 *v37; // x26
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  _WORD *v46; // x0
  _WORD *v47; // x27
  char v48; // w8
  unsigned __int8 v49; // w1
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  unsigned int *v58; // x8
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  const char *v67; // x2
  unsigned int *v68; // x8
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  const char *v77; // x2
  __int64 v78; // [xsp+0h] [xbp-40h] BYREF
  _WORD *v79; // [xsp+8h] [xbp-38h]
  __int64 v80; // [xsp+10h] [xbp-30h]
  __int64 v81; // [xsp+18h] [xbp-28h]
  __int64 v82; // [xsp+20h] [xbp-20h]
  __int64 v83; // [xsp+28h] [xbp-18h]
  __int16 v84; // [xsp+34h] [xbp-Ch] BYREF
  __int64 v85; // [xsp+38h] [xbp-8h]

  v85 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v84 = 0;
  v82 = 0;
  v83 = 0;
  v80 = 0;
  v81 = 0;
  v78 = 0;
  v79 = nullptr;
  if ( !result )
  {
    v67 = "%s: mac is NULL";
    goto LABEL_17;
  }
  if ( !a2 )
  {
    v67 = "%s: pe_session is NULL";
    goto LABEL_17;
  }
  if ( !a3 )
  {
    v67 = "%s: mlo_info is NULL";
LABEL_17:
    qdf_trace_msg(
      0x35u,
      2u,
      v67,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "lim_mlo_assoc_ind_upper_layer",
      v78,
      v79,
      v80,
      v81,
      v82,
      v83);
LABEL_18:
    result = 16;
    goto LABEL_19;
  }
  if ( !*a3 )
  {
    result = 0;
LABEL_19:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v13 = result;
  v14 = 0;
  v15 = a3 + 8;
  while ( v14 != 3 )
  {
    partner_session_by_link_id = pe_find_partner_session_by_link_id(a2, v15[6], a4, a5, a6, a7, a8, a9, a10, a11);
    if ( !partner_session_by_link_id )
    {
      v67 = "%s: link_session is NULL";
      goto LABEL_17;
    }
    v17 = partner_session_by_link_id;
    v18 = dph_lookup_hash_entry(a4, a5, a6, a7, a8, a9, a10, a11, v13, v15, &v84, partner_session_by_link_id + 360);
    if ( !v18 )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: sta_ds is NULL",
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        "lim_mlo_assoc_ind_upper_layer");
LABEL_28:
      wlan_objmgr_vdev_release_ref(*(_QWORD *)(v17 + 16), 0x5Au, v68, v69, v70, v71, v72, v73, v74, v75, v76);
      goto LABEL_18;
    }
    v27 = v18;
    v28 = _qdf_mem_malloc(0xB58u, "lim_mlo_assoc_ind_upper_layer", 1066);
    if ( !v28 )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: lim assoc ind allocate error",
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        "lim_mlo_assoc_ind_upper_layer");
LABEL_27:
      _qdf_mem_free(*(_QWORD *)(*(_QWORD *)(v17 + 384) + 8LL * *(unsigned __int16 *)(v27 + 348)));
      v68 = *(unsigned int **)(v17 + 384);
      *(_QWORD *)&v68[2 * *(unsigned __int16 *)(v27 + 348)] = 0;
      goto LABEL_28;
    }
    v37 = (unsigned __int8 *)v28;
    if ( (lim_fill_lim_assoc_ind_params(v28, v13, v27, v17, v29, v30, v31, v32, v33, v34, v35, v36) & 1) == 0 )
    {
      v77 = "%s: lim assoc ind fill error";
LABEL_26:
      qdf_trace_msg(
        0x35u,
        2u,
        v77,
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        "lim_mlo_assoc_ind_upper_layer",
        v78,
        v79,
        v80,
        v81,
        v82,
        v83);
      _qdf_mem_free((__int64)v37);
      goto LABEL_27;
    }
    v46 = (_WORD *)_qdf_mem_malloc(0xB90u, "lim_mlo_assoc_ind_upper_layer", 1086);
    if ( !v46 )
    {
      v77 = "%s: sme assoc ind allocate error";
      goto LABEL_26;
    }
    v47 = v46;
    *v46 = 5156;
    lim_fill_sme_assoc_ind_params(v13, v37, (__int64)v46, v17, 1);
    qdf_mem_set(&v78, 0x30u, 0);
    v48 = *(_BYTE *)(v27 + 32);
    v79 = v47;
    HIDWORD(v78) = 0;
    *((_BYTE *)v47 + 2739) = v48 & 1;
    *((_BYTE *)v47 + 2752) = *(_BYTE *)(v27 + 656);
    v49 = *(_BYTE *)(v17 + 8);
    LOWORD(v78) = 5156;
    mac_trace_msg_tx(v13, v49, 5156);
    sys_process_mmh_msg(v50, v51, v52, v53, v54, v55, v56, v57, v13, (unsigned __int16 *)&v78);
    _qdf_mem_free((__int64)v37);
    lim_free_assoc_req_frm_buf(*(_QWORD *)(*(_QWORD *)(v17 + 384) + 8LL * *(unsigned __int16 *)(v27 + 348)));
    _qdf_mem_free(*(_QWORD *)(*(_QWORD *)(v17 + 384) + 8LL * *(unsigned __int16 *)(v27 + 348)));
    v58 = *(unsigned int **)(v17 + 384);
    *(_QWORD *)&v58[2 * *(unsigned __int16 *)(v27 + 348)] = 0;
    wlan_objmgr_vdev_release_ref(*(_QWORD *)(v17 + 16), 0x5Au, v58, v59, v60, v61, v62, v63, v64, v65, v66);
    ++v14;
    result = 0;
    v15 += 48;
    if ( v14 >= (unsigned __int8)*a3 )
      goto LABEL_19;
  }
  __break(0x5512u);
  return lim_mlo_save_mlo_info(result, a2);
}
