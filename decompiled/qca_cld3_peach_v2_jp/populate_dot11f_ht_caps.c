__int64 __fastcall populate_dot11f_ht_caps(
        _QWORD *a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v14; // x24
  int v15; // w9
  unsigned int v16; // w9
  unsigned int v17; // w9
  unsigned int v18; // w9
  unsigned int v19; // w9
  unsigned int v20; // w9
  unsigned int v21; // w9
  int v22; // w8
  char cb_mode_for_freq; // w22
  bool is_24ghz_ch_freq; // w0
  int v25; // w8
  __int64 v26; // x0
  unsigned int v27; // w1
  int v28; // w8
  unsigned __int16 *v29; // x9
  unsigned int v30; // w8
  unsigned int v31; // w8
  unsigned int v32; // w8
  unsigned int v33; // w8
  unsigned int v34; // w10
  unsigned int v35; // w8
  unsigned int v36; // w8
  unsigned int v37; // w8
  bool v38; // zf
  unsigned int v39; // w8
  unsigned int v40; // w8
  char v41; // w9
  char v42; // w8
  char v43; // w9
  char v44; // w10
  __int64 v45; // x9
  unsigned int cfg_str; // w0
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  unsigned int v55; // w22
  __int64 v56; // x8
  unsigned int v57; // w22
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  unsigned int v66; // w8
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  __int64 v75; // x8
  unsigned int v76; // w8
  unsigned int v77; // w8
  unsigned int v78; // w8
  unsigned int v79; // w8
  unsigned int v80; // w8
  unsigned int v81; // w8
  unsigned int v82; // w8
  unsigned int v83; // w8
  unsigned int v84; // w8
  unsigned int v85; // w8
  unsigned int v86; // w8
  unsigned int v87; // w8
  unsigned int v88; // w8
  unsigned int v89; // w10
  int v90; // w8
  unsigned int v91; // w8
  unsigned int v92; // w8
  int v93; // w8
  unsigned int v94; // w8
  unsigned int v95; // w8
  unsigned int v96; // w8
  unsigned int v97; // w8
  unsigned int v98; // w8
  _QWORD v100[2]; // [xsp+0h] [xbp-20h] BYREF
  size_t v101[2]; // [xsp+10h] [xbp-10h] BYREF

  v101[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = a1[1];
  v15 = *(unsigned __int16 *)(a3 + 1);
  v100[0] = 0;
  v100[1] = 0;
  v16 = v15 & 0xFFFFFFEF | (16 * ((*(unsigned __int16 *)(v14 + 1268) >> 4) & 1));
  *(_WORD *)(a3 + 1) = v16;
  v17 = v16 & 0xFFFFFBFF | (((*(unsigned __int16 *)(v14 + 1268) >> 10) & 1) << 10);
  *(_WORD *)(a3 + 1) = v17;
  v18 = v17 & 0xFFFFF7FF | (((*(unsigned __int16 *)(v14 + 1268) >> 11) & 1) << 11);
  *(_WORD *)(a3 + 1) = v18;
  v19 = v18 & 0xFFFFEFFF | (((*(unsigned __int16 *)(v14 + 1268) >> 12) & 1) << 12);
  *(_WORD *)(a3 + 1) = v19;
  v20 = v19 & 0xFFFFDFFF | (((*(unsigned __int16 *)(v14 + 1268) >> 13) & 1) << 13);
  *(_WORD *)(a3 + 1) = v20;
  v21 = v20 & 0xFFFFBFFF | (((*(unsigned __int16 *)(v14 + 1268) >> 14) & 1) << 14);
  *(_WORD *)(a3 + 1) = v21;
  v22 = *(_WORD *)(v14 + 1268) & 0x8000 | v21 & 0x7FFF;
  *(_WORD *)(a3 + 1) = *(_WORD *)(v14 + 1268) & 0x8000 | v21 & 0x7FFF;
  if ( !a2 )
  {
    v29 = (unsigned __int16 *)(v14 + 1268);
    v30 = v22 & 0xFFFFFFFD | (2 * ((*(unsigned __int16 *)(v14 + 1268) >> 1) & 1));
    *(_WORD *)(a3 + 1) = v30;
    v31 = v30 & 0xFFFFFFFE | *(_WORD *)(v14 + 1268) & 1;
    *(_WORD *)(a3 + 1) = v31;
    v32 = v31 & 0xFFFFFF7F | (((*(unsigned __int16 *)(v14 + 1268) >> 7) & 1) << 7);
    *(_WORD *)(a3 + 1) = v32;
    v33 = v32 & 0xFFFFFCFF | ((HIBYTE(*(unsigned __int16 *)(v14 + 1268)) & 3) << 8);
    *(_WORD *)(a3 + 1) = v33;
    v34 = *(unsigned __int16 *)(v14 + 1268);
    goto LABEL_15;
  }
  cb_mode_for_freq = lim_get_cb_mode_for_freq((__int64)a1, a2, *(_DWORD *)(a2 + 284));
  is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a2 + 284));
  v25 = *(_DWORD *)(a2 + 88);
  if ( !is_24ghz_ch_freq || v25 != 2 || !cb_mode_for_freq )
  {
    if ( v25 == 2 )
    {
      v28 = *(unsigned __int16 *)(a3 + 1);
      if ( !*(_DWORD *)(a2 + 7176) )
      {
LABEL_12:
        v28 &= ~2u;
        goto LABEL_13;
      }
      v28 |= 2u;
    }
    else
    {
      v28 = *(_WORD *)(a3 + 1) & 0xFFFD | (2 * (*(_BYTE *)(a2 + 160) & 1));
    }
LABEL_13:
    *(_WORD *)(a3 + 1) = v28;
    goto LABEL_14;
  }
  *(_WORD *)(a3 + 1) |= 2u;
  v26 = a1[2695];
  v27 = *(_DWORD *)(a2 + 284);
  LODWORD(v100[0]) = 1;
  wlan_reg_set_channel_params_for_pwrmode(v26, v27, 0, (__int64)v100, 0, a4, a5, a6, a7, a8, a9, a10, a11);
  v28 = *(unsigned __int16 *)(a3 + 1);
  if ( LODWORD(v100[0]) != 1 )
    goto LABEL_12;
LABEL_14:
  v35 = v28 & 0xFFFFFFFE | *(_WORD *)(a2 + 7266) & 1;
  *(_WORD *)(a3 + 1) = v35;
  v36 = v35 & 0xFFFFFF7F | (((*(unsigned __int16 *)(a2 + 7266) >> 7) & 1) << 7);
  *(_WORD *)(a3 + 1) = v36;
  v33 = v36 & 0xFFFFFCFF | ((HIBYTE(*(unsigned __int16 *)(a2 + 7266)) & 3) << 8);
  v29 = (unsigned __int16 *)(a2 + 7266);
  *(_WORD *)(a3 + 1) = v33;
  v34 = *(unsigned __int16 *)(a2 + 7266);
LABEL_15:
  v37 = v33 & 0xFFFFFFDF | (32 * ((v34 >> 5) & 1));
  *(_WORD *)(a3 + 1) = v37;
  v38 = (v37 & 2) == 0;
  v39 = v37 & 0xFFFFFFBF | (((*v29 >> 6) & 1) << 6);
  *(_WORD *)(a3 + 1) = v39;
  v40 = v39 & 0xFFFFFFF3 | (4 * ((*v29 >> 2) & 3));
  if ( v38 )
    LOWORD(v40) = v40 & 0xFFBD;
  v41 = *(_BYTE *)(a3 + 3);
  *(_WORD *)(a3 + 1) = v40;
  v42 = *(_BYTE *)(a1[1] + 1270LL);
  v43 = v41 & 0xFC | v42 & 3;
  *(_BYTE *)(a3 + 3) = v43;
  v44 = *(_BYTE *)(a1[1] + 1270LL) & 0x1C;
  *(_BYTE *)(a3 + 3) = v44 | v43 & 0xE3;
  *(_BYTE *)(a3 + 3) = *(_BYTE *)(a1[1] + 1270LL) & 0xE0 | v42 & 3 | v44;
  v45 = a1[1];
  v101[0] = 16;
  cfg_str = wlan_mlme_get_cfg_str((void *)(a3 + 4), v45 + 2856, v101, a4, a5, a6, a7, a8, a9, a10, a11);
  if ( !cfg_str )
  {
    if ( !a2 )
    {
LABEL_36:
      v55 = 0;
      v76 = *(_DWORD *)(a3 + 20) & 0xFFFFFFFE | *(_WORD *)(a1[1] + 1271LL) & 1;
      *(_DWORD *)(a3 + 20) = v76;
      v77 = v76 & 0xFFFFFFF9 | (2 * ((*(unsigned __int16 *)(a1[1] + 1271LL) >> 1) & 3));
      *(_DWORD *)(a3 + 20) = v77;
      v78 = v77 & 0xFFFFFCFF | ((HIBYTE(*(unsigned __int16 *)(a1[1] + 1271LL)) & 3) << 8);
      *(_DWORD *)(a3 + 20) = v78;
      v79 = v78 & 0xFFFEFFFF | ((*(_DWORD *)(v14 + 2677) & 1) << 16);
      *(_DWORD *)(a3 + 20) = v79;
      v80 = v79 & 0xFFFDFFFF | (((*(_DWORD *)(v14 + 2677) >> 1) & 1) << 17);
      *(_DWORD *)(a3 + 20) = v80;
      v81 = v80 & 0xFFFBFFFF | (((*(_DWORD *)(v14 + 2677) >> 2) & 1) << 18);
      *(_DWORD *)(a3 + 20) = v81;
      v82 = v81 & 0xFFF7FFFF | (((*(_DWORD *)(v14 + 2677) >> 3) & 1) << 19);
      *(_DWORD *)(a3 + 20) = v82;
      v83 = v82 & 0xFFEFFFFF | (((*(_DWORD *)(v14 + 2677) >> 4) & 1) << 20);
      *(_DWORD *)(a3 + 20) = v83;
      v84 = v83 & 0xFFDFFFFF | (((*(_DWORD *)(v14 + 2677) >> 5) & 1) << 21);
      *(_DWORD *)(a3 + 20) = v84;
      v85 = v84 & 0xFF3FFFFF | (((*(_DWORD *)(v14 + 2677) >> 6) & 3) << 22);
      *(_DWORD *)(a3 + 20) = v85;
      v86 = v85 & 0xFEFFFFFF | (((*(_DWORD *)(v14 + 2677) >> 8) & 1) << 24);
      *(_DWORD *)(a3 + 20) = v86;
      v87 = v86 & 0xFDFFFFFF | (((*(_DWORD *)(v14 + 2677) >> 9) & 1) << 25);
      *(_DWORD *)(a3 + 20) = v87;
      v88 = v87 & 0xE3FFFFFF | (((*(_DWORD *)(v14 + 2677) >> 10) & 7) << 26);
      *(_DWORD *)(a3 + 20) = v88;
      v89 = (*(_DWORD *)(v14 + 2677) << 16) & 0xE0000000 | v88 & 0x1FFFFFFF;
      v90 = *(unsigned __int16 *)(a3 + 24);
      *(_DWORD *)(a3 + 20) = v89;
      v91 = v90 & 0xFFFFFFF8 | *(_WORD *)(v14 + 2679) & 7;
      *(_WORD *)(a3 + 24) = v91;
      v92 = v91 & 0xFFFFFFE7 | (8 * ((*(unsigned __int16 *)(v14 + 2679) >> 3) & 3));
      *(_WORD *)(a3 + 24) = v92;
      LOWORD(v92) = v92 & 0xFF9F | (32 * ((*(_WORD *)(v14 + 2679) >> 5) & 3));
      *(_WORD *)(a3 + 24) = v92;
      *(_WORD *)(a3 + 24) = v92 & 0xFE7F | *(_WORD *)(v14 + 2679) & 0x180;
      v93 = *(_BYTE *)(a3 + 26) & 0xFE | *(_BYTE *)(v14 + 2678) & 1;
      *(_BYTE *)(a3 + 26) = v93;
      v94 = v93 & 0xFFFFFFFD | (2 * ((*(unsigned __int8 *)(v14 + 2678) >> 1) & 1));
      *(_BYTE *)(a3 + 26) = v94;
      v95 = v94 & 0xFFFFFFFB | (4 * ((*(unsigned __int8 *)(v14 + 2678) >> 2) & 1));
      *(_BYTE *)(a3 + 26) = v95;
      v96 = v95 & 0xFFFFFFF7 | (8 * ((*(unsigned __int8 *)(v14 + 2678) >> 3) & 1));
      *(_BYTE *)(a3 + 26) = v96;
      v97 = v96 & 0xFFFFFFEF | (16 * ((*(unsigned __int8 *)(v14 + 2678) >> 4) & 1));
      *(_BYTE *)(a3 + 26) = v97;
      v98 = v97 & 0xFFFFFFDF | (32 * ((*(unsigned __int8 *)(v14 + 2678) >> 5) & 1));
      *(_BYTE *)(a3 + 26) = v98;
      *(_BYTE *)(a3 + 26) = v98 & 0xBF | *(_BYTE *)(v14 + 2678) & 0x40;
      *(_BYTE *)a3 = 1;
      goto LABEL_37;
    }
    if ( *(unsigned __int8 *)(a2 + 8635) > 1u )
    {
      v56 = a1[1];
      v57 = *(unsigned __int8 *)(v56 + 2770);
      if ( *(_BYTE *)(v56 + 2770) && !*(_DWORD *)(a2 + 7036) && wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a2 + 284)) )
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: Disabling high HT MCS [%d]",
          v58,
          v59,
          v60,
          v61,
          v62,
          v63,
          v64,
          v65,
          "populate_dot11f_ht_caps",
          v57);
        *(_BYTE *)(a3 + 5) = *(unsigned __int8 *)(a3 + 5) >> v57;
        v66 = *(unsigned __int8 *)(a2 + 8635);
        if ( v66 >= 2 )
          v66 = 2;
        goto LABEL_28;
      }
    }
    else
    {
      *(_WORD *)(a3 + 1) &= ~0x80u;
    }
    v66 = *(unsigned __int8 *)(a2 + 8635);
LABEL_28:
    if ( v66 <= 1 )
    {
      *(_BYTE *)(a3 + 4 + v66) = 0;
      if ( !v66 )
        *(_BYTE *)(a3 + 5) = 0;
    }
    wlan_ll_lt_sap_get_mcs(a1[2694], *(unsigned __int8 *)(a2 + 10), a3 + 4);
    if ( *(_DWORD *)(a2 + 88) == 2 )
    {
      v75 = a1[1];
      if ( *(_BYTE *)(v75 + 1280) == 1
        && (*(_BYTE *)(a2 + 8653) & 1) == 0
        && (~*(unsigned __int16 *)(a2 + 7266) & 0xC) != 0 )
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: Add SM power save IE: %d",
          v67,
          v68,
          v69,
          v70,
          v71,
          v72,
          v73,
          v74,
          "populate_dot11f_ht_caps",
          *(unsigned __int8 *)(v75 + 1281));
        *(_WORD *)(a3 + 1) = *(_WORD *)(a3 + 1) & 0xFFF3 | (4 * (*(_BYTE *)(a1[1] + 1281LL) & 3));
      }
    }
    goto LABEL_36;
  }
  v55 = cfg_str;
  qdf_trace_msg(
    0x35u,
    2u,
    "%s: Failed to retrieve nItem from CFG status: %d",
    v47,
    v48,
    v49,
    v50,
    v51,
    v52,
    v53,
    v54,
    "populate_dot11f_ht_caps",
    cfg_str);
LABEL_37:
  _ReadStatusReg(SP_EL0);
  return v55;
}
