__int64 __fastcall cm_connect_fetch_candidates(__int64 a1, __int64 a2, unsigned int *a3, __int64 *a4, unsigned int *a5)
{
  unsigned int v10; // w26
  unsigned __int8 *rsnxe_data_from_ie_ptr; // x0
  char v12; // w0
  unsigned int v13; // w8
  char v14; // w22
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 result; // x0
  __int64 v24; // x0
  __int64 v25; // x21
  unsigned int v26; // w8
  int v27; // w9
  __int16 v28; // w8
  int v29; // w8
  __int64 v30; // x22
  __int64 v31; // x0
  const void *v32; // x22
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  int sta_mlo_conn_band_bmp; // w6
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  __int16 v50; // w8
  __int16 v51; // w10
  int v52; // w9
  __int64 scan_result; // x0
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  unsigned int v62; // w27
  __int64 v63; // x22
  __int64 v64; // x0
  __int64 cmpt_obj; // x0
  __int64 v66; // x23
  _QWORD *v67; // x1
  unsigned int v68; // w24
  unsigned __int8 v69; // w26
  __int64 entry; // x0
  __int64 v71; // x1
  __int64 v72; // x2
  __int64 v73; // x3
  __int64 v74; // x28
  __int64 v75; // x25
  bool v76; // zf
  __int64 v77; // x10
  int v78; // w11
  int v79; // w0
  _QWORD v80[2]; // [xsp+8h] [xbp-28h] BYREF
  _QWORD v81[3]; // [xsp+18h] [xbp-18h] BYREF

  v81[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(unsigned __int8 *)(*(_QWORD *)a2 + 168LL);
  rsnxe_data_from_ie_ptr = wlan_get_rsnxe_data_from_ie_ptr(*((unsigned __int8 **)a3 + 21), a3[40]);
  v12 = wlan_cm_6ghz_allowed_for_akm(
          *(_QWORD *)(a1 + 80),
          a3[24],
          *((_WORD *)a3 + 64),
          (__int64)rsnxe_data_from_ie_ptr,
          *((unsigned __int8 *)a3 + 200),
          (a3[48] & 2) != 0);
  v13 = a3[17];
  v14 = v12;
  if ( v13 && (v12 & 1) == 0 && (wlan_reg_is_6ghz_chan_freq(v13) & 1) != 0 )
  {
    qdf_trace_msg(
      0x68u,
      4u,
      "%s: vdev %d cm_id 0x%x: 6ghz freq (%d) given and 6Ghz not allowed for the security in connect req",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "cm_connect_fetch_candidates",
      v10,
      *a3,
      a3[17]);
    result = 4;
LABEL_109:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v24 = _qdf_mem_malloc(0x2D8u, "cm_connect_fetch_candidates", 1584);
  if ( !v24 )
  {
    result = 2;
    goto LABEL_109;
  }
  v25 = v24;
  if ( a3[4] | *((unsigned __int16 *)a3 + 10) )
  {
    *(_BYTE *)(v24 + 16) = 1;
    v26 = a3[4];
    *(_WORD *)(v24 + 74) = *((_WORD *)a3 + 10);
    *(_DWORD *)(v24 + 70) = v26;
  }
  v27 = *(unsigned int *)((char *)a3 + 61);
  *(_WORD *)(v24 + 68) = *(_WORD *)((char *)a3 + 65);
  *(_DWORD *)(v24 + 64) = v27;
  *(_BYTE *)(v24 + 17) = 1;
  qdf_mem_copy((void *)(v24 + 100), a3 + 7, 0x21u);
  if ( a3[17] )
  {
    *(_WORD *)(v25 + 18) = 1;
    *(_DWORD *)(v25 + 268) = a3[17];
  }
  if ( (v14 & 1) == 0 )
    *(_WORD *)v25 |= 0x20u;
  if ( *((_BYTE *)a3 + 816) == 1 )
    *(_WORD *)v25 &= ~0x20u;
  if ( (a3[48] & 7) != 0 )
  {
    *(_WORD *)v25 |= 8u;
    goto LABEL_23;
  }
  *(_DWORD *)(v25 + 40) = a3[21];
  *(_DWORD *)(v25 + 48) = a3[23];
  *(_DWORD *)(v25 + 44) = a3[24];
  *(_DWORD *)(v25 + 52) = a3[22];
  *(_DWORD *)(v25 + 56) = a3[33];
  v28 = *((_WORD *)a3 + 64);
  if ( (v28 & 0x40) != 0 )
  {
    v29 = 2;
  }
  else
  {
    if ( (v28 & 0x80) == 0 )
    {
      *(_DWORD *)(v25 + 24) = 0;
      goto LABEL_23;
    }
    v29 = 1;
  }
  *(_DWORD *)(v25 + 24) = v29;
LABEL_23:
  v30 = *(_QWORD *)(a1 + 80);
  *(_DWORD *)(v25 + 20) = 1;
  *(_WORD *)v25 = *(_WORD *)v25 & 0xFFFE | wlan_mlme_adaptive_11r_enabled(v30) & 1;
  if ( !*(_DWORD *)(*(_QWORD *)a2 + 16LL) )
  {
    if ( (a3[204] & 1) == 0 )
      ((void (__fastcall *)(__int64, __int64))wlan_cm_dual_sta_roam_update_connect_channels)(v30, v25);
    *(_DWORD *)(v25 + 28) = a3[49];
    if ( *((_BYTE *)a3 + 216) == 1 )
    {
      if ( a3[120] )
      {
        LOWORD(v81[0]) = 0;
        v31 = _qdf_mem_malloc(0x20u, "cm_create_fils_realm_hash", 779);
        if ( v31 )
        {
          v32 = (const void *)v31;
          v80[0] = a3 + 121;
          qdf_get_hash((__int64)"sha256", 1u, (__int64)v80, a3 + 120);
          qdf_mem_copy(v81, v32, 2u);
          _qdf_mem_free((__int64)v32);
          *(_BYTE *)(v25 + 60) = 1;
          qdf_trace_msg(
            0x68u,
            8u,
            "%s: vdev %d cm_id 0x%x: creating realm based on fils info",
            v33,
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            "cm_update_fils_scan_filter",
            *((unsigned __int8 *)a3 + 8),
            *a3);
          qdf_mem_copy((void *)(v25 + 61), v81, 2u);
        }
      }
    }
    *(_BYTE *)(v25 + 723) = *(_BYTE *)(*(_QWORD *)a2 + 160LL);
  }
  sta_mlo_conn_band_bmp = (unsigned __int8)wlan_mlme_get_sta_mlo_conn_band_bmp(*(_QWORD *)(a1 + 80));
  *(_DWORD *)(v25 + 712) = sta_mlo_conn_band_bmp;
  if ( *((_BYTE *)a3 + 816) == 1 )
  {
    v50 = *(_WORD *)v25;
    *(_DWORD *)(v25 + 712) = sta_mlo_conn_band_bmp | 0x70;
    *(_WORD *)v25 = v50 | 0x40;
    v51 = *((_WORD *)a3 + 411);
    v52 = *(unsigned int *)((char *)a3 + 818);
    *(_WORD *)v25 = v50 | 0xC0;
    *(_WORD *)(v25 + 721) = v51;
    *(_DWORD *)(v25 + 717) = v52;
    *(_BYTE *)(v25 + 716) = *((_BYTE *)a3 + 817);
  }
  qdf_trace_msg(
    0x68u,
    8u,
    "%s: vdev %d cm_id 0x%x: band bitmap: 0x%x",
    v42,
    v43,
    v44,
    v45,
    v46,
    v47,
    v48,
    v49,
    "cm_update_mlo_filter",
    *((unsigned __int8 *)a3 + 8),
    *a3);
  scan_result = scm_get_scan_result(a1, v25);
  if ( !scan_result )
  {
    *a5 = 0;
    _qdf_mem_free(v25);
    goto LABEL_108;
  }
  v62 = *(_DWORD *)(scan_result + 16);
  v63 = scan_result;
  qdf_trace_msg(
    0x68u,
    8u,
    "%s: vdev %d cm_id 0x%x: num_entries found %d",
    v54,
    v55,
    v56,
    v57,
    v58,
    v59,
    v60,
    v61,
    "cm_connect_fetch_candidates",
    v10,
    *a3,
    v62);
  *a5 = v62;
  if ( !v62 )
    goto LABEL_105;
  if ( *(_DWORD *)(*(_QWORD *)a2 + 16LL) )
    goto LABEL_105;
  if ( (a3[204] & 1) != 0 )
    goto LABEL_105;
  cm_calculate_scores(a2, a1, v25, v63, a3[1] == 0);
  v64 = *(_QWORD *)(a1 + 80);
  v80[0] = 0;
  v81[0] = 0;
  if ( !v64
    || (cmpt_obj = wlan_psoc_mlme_get_cmpt_obj(v64)) == 0
    || (v66 = cmpt_obj, !*(_BYTE *)(cmpt_obj + 2057))
    || a3[1]
    || *((_QWORD *)a3 + 125)
    || (a3[262] & 1) != 0
    || (qdf_list_peek_front((_QWORD *)v63, v80), (v67 = (_QWORD *)v80[0]) == nullptr) )
  {
LABEL_105:
    _qdf_mem_free(v25);
    if ( *(_DWORD *)(v63 + 16) )
    {
      result = 0;
      *a4 = v63;
      goto LABEL_109;
    }
    scm_purge_scan_results(v63);
LABEL_108:
    result = 13;
    goto LABEL_109;
  }
  v68 = 0;
  v69 = 0;
  while ( 1 )
  {
    entry = qdf_list_peek_next((_QWORD *)v63, v67, v81);
    v74 = *(_QWORD *)(v80[0] + 24LL);
    if ( *(_DWORD *)(v74 + 1912) | *(unsigned __int16 *)(v74 + 1916) )
      v75 = v74 + 1912;
    else
      v75 = 0;
    if ( *(_BYTE *)(v74 + 112) )
      v76 = v75 == 0;
    else
      v76 = 1;
    if ( v76 )
      goto LABEL_47;
    if ( !v68 )
      break;
LABEL_56:
    if ( *(_BYTE *)(v74 + 1918) )
    {
      if ( *(_BYTE *)(v74 + 1960) == 1 )
      {
        entry = cm_get_entry((_QWORD *)v63, v74 + 1920, v75);
        if ( !entry )
        {
          if ( *(unsigned __int8 *)(v66 + 2057) <= (unsigned int)v69 )
          {
            *(_BYTE *)(v74 + 1960) = 0;
          }
          else
          {
            entry = cm_fill_nontx_scan_params(a3 + 262, v74 + 1920, v68, *(unsigned __int16 *)(v74 + 1926));
            if ( (_DWORD)entry != 6 && (_DWORD)entry )
              goto LABEL_105;
            if ( (a3[262] & 1) == 0 )
              *((_BYTE *)a3 + 1048) = 1;
          }
        }
      }
      if ( *(unsigned __int8 *)(v74 + 1918) >= 2u )
      {
        if ( *(_BYTE *)(v74 + 2008) == 1 )
        {
          entry = cm_get_entry((_QWORD *)v63, v74 + 1968, v75);
          if ( !entry )
          {
            if ( *(unsigned __int8 *)(v66 + 2057) <= (unsigned int)v69 )
            {
              *(_BYTE *)(v74 + 2008) = 0;
            }
            else
            {
              entry = cm_fill_nontx_scan_params(a3 + 262, v74 + 1968, v68, *(unsigned __int16 *)(v74 + 1974));
              if ( (_DWORD)entry != 6 && (_DWORD)entry )
                goto LABEL_105;
              if ( (a3[262] & 1) == 0 )
                *((_BYTE *)a3 + 1048) = 1;
            }
          }
        }
        if ( *(unsigned __int8 *)(v74 + 1918) >= 3u )
        {
          if ( *(_BYTE *)(v74 + 2056) == 1 )
          {
            entry = cm_get_entry((_QWORD *)v63, v74 + 2016, v75);
            if ( !entry )
            {
              if ( *(unsigned __int8 *)(v66 + 2057) <= (unsigned int)v69 )
              {
                *(_BYTE *)(v74 + 2056) = 0;
              }
              else
              {
                entry = cm_fill_nontx_scan_params(a3 + 262, v74 + 2016, v68, *(unsigned __int16 *)(v74 + 2022));
                if ( (_DWORD)entry != 6 && (_DWORD)entry )
                  goto LABEL_105;
                if ( (a3[262] & 1) == 0 )
                  *((_BYTE *)a3 + 1048) = 1;
              }
            }
          }
          if ( *(unsigned __int8 *)(v74 + 1918) >= 4u )
          {
            if ( *(_BYTE *)(v74 + 2104) == 1 )
            {
              entry = cm_get_entry((_QWORD *)v63, v74 + 2064, v75);
              if ( !entry )
              {
                if ( *(unsigned __int8 *)(v66 + 2057) <= (unsigned int)v69 )
                {
                  *(_BYTE *)(v74 + 2104) = 0;
                }
                else
                {
                  entry = cm_fill_nontx_scan_params(a3 + 262, v74 + 2064, v68, *(unsigned __int16 *)(v74 + 2070));
                  if ( (_DWORD)entry != 6 && (_DWORD)entry )
                    goto LABEL_105;
                  if ( (a3[262] & 1) == 0 )
                    *((_BYTE *)a3 + 1048) = 1;
                }
              }
            }
            if ( *(unsigned __int8 *)(v74 + 1918) > 4u )
              goto LABEL_110;
          }
        }
      }
    }
    v79 = cm_fill_nontx_scan_params(a3 + 262, v74 + 1, v68, *(unsigned int *)(v74 + 1192));
    if ( v79 != 6 && v79 )
      goto LABEL_105;
LABEL_47:
    v67 = (_QWORD *)v81[0];
    ++v69;
    v81[0] = 0;
    v80[0] = v67;
    if ( !v67 )
      goto LABEL_105;
  }
  if ( !*(_BYTE *)(v74 + 132) )
  {
LABEL_46:
    v68 = 0;
    goto LABEL_47;
  }
  v77 = 0;
  while ( v77 != 1088 )
  {
    if ( *(_BYTE *)(v74 + v77 + 162) == 1 )
    {
      v78 = *(unsigned __int8 *)(v74 + v77 + 163);
      if ( v78 != 255 && (!*(_BYTE *)(v74 + v77 + 163) || v78 == *(unsigned __int8 *)(v74 + 112)) )
      {
        v68 = *(_DWORD *)(v74 + v77 + 156);
        if ( v68 )
          goto LABEL_56;
        goto LABEL_47;
      }
    }
    v77 += 32;
    if ( 32LL * *(unsigned __int8 *)(v74 + 132) == v77 )
      goto LABEL_46;
  }
LABEL_110:
  __break(0x5512u);
  return cm_fill_nontx_scan_params(entry, v71, v72, v73);
}
