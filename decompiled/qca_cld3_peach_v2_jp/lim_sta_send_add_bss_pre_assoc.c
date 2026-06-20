__int64 __fastcall lim_sta_send_add_bss_pre_assoc(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x28
  __int64 v13; // x23
  __int64 v14; // x0
  __int64 v15; // x19
  __int64 v16; // x0
  __int64 v17; // x22
  char *v18; // x25
  int ielen_from_bss_description; // w24
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  _WORD *v28; // x24
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  char v37; // w8
  int v38; // w8
  char ht_capability; // w0
  bool v40; // w26
  int v41; // w8
  unsigned int v42; // w20
  int v43; // w8
  __int64 v44; // x7
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  __int16 v53; // w8
  int v54; // w8
  __int64 v55; // x23
  char v56; // w8
  char v57; // w8
  int v58; // w8
  int v59; // w8
  int v60; // w9
  __int64 v61; // x8
  char v62; // w8
  char v63; // w8
  __int16 v64; // w2
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  int v81; // w8
  unsigned int v82; // w0
  __int64 v84; // [xsp+10h] [xbp-10h]
  __int64 v85; // [xsp+18h] [xbp-8h]

  v10 = *(_QWORD *)(a2 + 112);
  if ( v10 )
  {
    v13 = *(_QWORD *)(a1 + 8);
    v14 = _qdf_mem_malloc(0xD80u, "lim_sta_send_add_bss_pre_assoc", 4310);
    if ( v14 )
    {
      v15 = v14;
      v16 = _qdf_mem_malloc(0x138u, "lim_sta_send_add_bss_pre_assoc", 4315);
      if ( !v16 )
      {
        v42 = 2;
LABEL_120:
        _qdf_mem_free(v15);
        return v42;
      }
      v17 = v16;
      v18 = (char *)(a2 + 7024);
      ielen_from_bss_description = (unsigned __int16)wlan_get_ielen_from_bss_description(v10 + 4364);
      qdf_mem_set((void *)v15, 0xD80u, 0);
      if ( ielen_from_bss_description && (unsigned int)sir_parse_beacon_ie(a1, v15) )
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: APCapExtract: Beacon parsing error!",
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          "lim_extract_ap_capabilities");
      v85 = v13;
      if ( *(_BYTE *)(a1 + 8884) )
        lim_decide_sta_protection_on_assoc(a1, v15, a2);
      v28 = (_WORD *)(v15 + 1201);
      qdf_mem_copy((void *)v17, (const void *)(v10 + 4366), 6u);
      *(_WORD *)(v17 + 14) = *(_WORD *)(v10 + 4380);
      v37 = *(_BYTE *)(v15 + 83);
      *(_BYTE *)(v17 + 292) = 0;
      *(_BYTE *)(v17 + 16) = v37;
      *(_DWORD *)(v17 + 8) = *(_DWORD *)(v10 + 4384);
      *(_BYTE *)(v17 + 12) = (*(_WORD *)(v15 + 10) & 0x400) != 0;
      *(_BYTE *)(v17 + 13) = *(_BYTE *)(a2 + 7162);
      v38 = *(unsigned __int8 *)(a2 + 154);
      if ( (unsigned int)(v38 - 7) < 7 || v38 == 5 || (v40 = 0, !*(_BYTE *)(a2 + 154)) )
      {
        ht_capability = lim_get_ht_capability(a1, 12, a2);
        v40 = ht_capability != 0;
        if ( *(_BYTE *)(v15 + 1200) )
        {
          *(_BYTE *)(v17 + 17) = *(_BYTE *)(v15 + 1200);
          if ( *(_BYTE *)(v15 + 1260) )
          {
            if ( ht_capability && (*v28 & 2) != 0 )
              v41 = (*(_DWORD *)(v15 + 1262) >> 2) & 1;
            else
              v41 = 0;
            *(_DWORD *)(v17 + 296) = v41;
          }
        }
      }
      if ( !*(_BYTE *)(a2 + 7170)
        || (!*(_BYTE *)(v15 + 2484) || *(__int16 *)(v15 + 2490) == -1 || *(__int16 *)(v15 + 2494) == -1)
        && (!*(_BYTE *)(v15 + 2544) || *(__int16 *)(v15 + 2550) == -1 || *(__int16 *)(v15 + 2554) == -1) )
      {
        v84 = 0;
        *(_BYTE *)(v17 + 294) = 0;
      }
      else
      {
        *(_BYTE *)(v17 + 294) = 1;
        if ( *(_BYTE *)(v15 + 2500) )
        {
          v84 = v15 + 2500;
        }
        else if ( *(_BYTE *)(v15 + 2560) )
        {
          v84 = v15 + 2560;
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: VHT Operation is present in vendor Specific IE",
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            v36,
            "lim_sta_send_add_bss_pre_assoc");
        }
        else
        {
          v84 = 0;
        }
        v43 = (*(_DWORD *)(v17 + 160) >> 23) & 7;
        *(_DWORD *)(v17 + 296) = *(_DWORD *)(a2 + 7176);
        *(_BYTE *)(v17 + 52) = v43;
      }
      if ( *(_BYTE *)(a2 + 8676) == 1 && *(_BYTE *)(v15 + 2640) )
      {
        lim_update_bss_he_capable(a1, v17);
        lim_add_bss_he_cfg(v17, a2);
      }
      *(_BYTE *)(v17 + 28) = 1;
      qdf_mem_copy((void *)(v17 + 20), (const void *)(v10 + 4366), 6u);
      v53 = *(_WORD *)(*(_QWORD *)(a1 + 8) + 3204LL);
      *(_WORD *)(v17 + 26) = 0;
      *(_WORD *)(v17 + 39) = 0;
      *(_WORD *)(v17 + 36) = v53;
      *(_BYTE *)(v17 + 124) = 0;
      v54 = *(unsigned __int8 *)(a2 + 154);
      if ( (unsigned int)(v54 - 7) >= 7 && v54 != 5 && *(_BYTE *)(a2 + 154) || !*(_BYTE *)(v15 + 1200) )
      {
        v57 = *v18;
        if ( (*v18 & 2) == 0 )
        {
LABEL_102:
          if ( (v57 & 1) == 0 || !*(_BYTE *)(v15 + 2467) && !*(_BYTE *)(v17 + 41) )
          {
            v63 = 0;
            goto LABEL_110;
          }
LABEL_109:
          v63 = 1;
LABEL_110:
          *(_BYTE *)(v17 + 38) = v63;
          lim_populate_peer_rate_set(
            a1,
            (_BYTE *)(v17 + 56),
            (_BYTE *)(v15 + 1204),
            0,
            a2,
            v15 + 2484,
            (char *)(v15 + 2640),
            v45,
            v46,
            v47,
            v48,
            v49,
            v50,
            v51,
            v52,
            v44,
            0,
            v10 + 4364);
          *(_DWORD *)(v17 + 128) = *(_DWORD *)(a2 + 424);
          *(_BYTE *)(v17 + 293) = *(_BYTE *)(a2 + 7032);
          *(_BYTE *)(v17 + 151) = *(_BYTE *)(a2 + 10);
          *(_BYTE *)(v17 + 132) = *(_BYTE *)(a2 + 8);
          if ( (*v18 & 0x10) != 0 )
          {
            *(_BYTE *)(v17 + 18) = 1;
            *(_BYTE *)(v17 + 125) = 1;
          }
          v64 = *(_WORD *)(a2 + 8);
          *(_DWORD *)(a2 + 72) = 20;
          qdf_trace(53, 0, v64, 20);
          if ( cds_is_5_mhz_enabled(v65, v66, v67, v68, v69, v70, v71, v72) )
          {
            v81 = 5;
          }
          else
          {
            if ( !cds_is_10_mhz_enabled(v73, v74, v75, v76, v77, v78, v79, v80) )
            {
LABEL_117:
              if ( **(_BYTE **)(a2 + 9976) == 1 )
                *(_BYTE *)(v17 + 308) = 1;
              v82 = wma_pre_assoc_req(v17);
              lim_process_sta_add_bss_rsp_pre_assoc(a1, v17, a2, v82);
              _qdf_mem_free(v17);
              v42 = 0;
              goto LABEL_120;
            }
            v81 = 6;
          }
          *(_DWORD *)(v17 + 296) = v81;
          *(_DWORD *)(v17 + 44) = v81;
          goto LABEL_117;
        }
LABEL_104:
        if ( *(_BYTE *)(v15 + 2469) || *(_BYTE *)(v17 + 41) )
          goto LABEL_109;
        goto LABEL_102;
      }
      *(_BYTE *)(v17 + 41) = 1;
      if ( *(_BYTE *)(a2 + 7170)
        && (*(_BYTE *)(v15 + 2484) && *(__int16 *)(v15 + 2490) != -1 && *(__int16 *)(v15 + 2494) != -1
         || *(_BYTE *)(v15 + 2544) && *(__int16 *)(v15 + 2550) != -1 && *(__int16 *)(v15 + 2554) != -1) )
      {
        v55 = v15 + 2484;
        *(_BYTE *)(v17 + 135) = 1;
        if ( *(_BYTE *)(v15 + 2484) )
          goto LABEL_52;
        if ( *(_BYTE *)(v15 + 2544) )
        {
          v55 = v15 + 2544;
LABEL_52:
          if ( v55 )
          {
            if ( ((*(_WORD *)(v55 + 1) & 0x800) != 0 || (*(_BYTE *)(v55 + 3) & 8) != 0)
              && (*(_BYTE *)(a2 + 7269) & 0x10) != 0 )
            {
              *(_BYTE *)(v17 + 140) = 1;
            }
            if ( (*(_BYTE *)(v55 + 3) & 8) != 0 && (*(_BYTE *)(a2 + 7270) & 0x10) != 0 )
              *(_BYTE *)(v17 + 142) = 1;
            if ( (*(_WORD *)(v55 + 1) & 0x1000) != 0 && (*(_BYTE *)(a2 + 7269) & 8) != 0 )
              *(_BYTE *)(v17 + 141) = 1;
          }
LABEL_64:
          if ( *(_BYTE *)(a2 + 8676) == 1 && *(_BYTE *)(v15 + 2640) )
            lim_intersect_ap_he_caps(a2, v17, v15, 0, v10 + 4364);
          v56 = !v40;
          if ( (*v28 & 2) == 0 )
            v56 = 1;
          if ( (v56 & 1) != 0 )
          {
            *(_DWORD *)(v17 + 44) = 0;
          }
          else
          {
            *(_DWORD *)(v17 + 44) = (*(_DWORD *)(v15 + 1262) >> 2) & 1;
            if ( v84 && *(_BYTE *)(v17 + 135) && *(_BYTE *)(v84 + 1) )
              *(_DWORD *)(v17 + 44) = *(unsigned __int8 *)(v84 + 1) + 1;
          }
          *(_DWORD *)(v17 + 48) = ((unsigned __int16)*v28 >> 2) & 3;
          *(_BYTE *)(v17 + 53) = (*(_BYTE *)(v15 + 1203) >> 2) & 7;
          if ( (*(_WORD *)(a2 + 7266) & 0x20) != 0 )
            v58 = (*(unsigned __int8 *)v28 >> 5) & 1;
          else
            LOBYTE(v58) = 0;
          *(_BYTE *)(v17 + 55) = v58;
          if ( (*(_WORD *)(a2 + 7266) & 0x40) != 0 )
            v59 = (*(unsigned __int8 *)v28 >> 6) & 1;
          else
            LOBYTE(v59) = 0;
          *(_BYTE *)(v17 + 54) = v59;
          v60 = *(unsigned __int8 *)(v17 + 140);
          *(_BYTE *)(v17 + 52) = *(_BYTE *)(v15 + 1203) & 3;
          if ( v60 && *(_BYTE *)(v85 + 2679) == 1 )
          {
            LOBYTE(v61) = 0;
            *(_BYTE *)(v17 + 148) = 0;
            goto LABEL_101;
          }
          if ( (*(_BYTE *)(a2 + 7236) & 1) != 0 )
            v62 = *(_BYTE *)v28 & 1;
          else
            v62 = 0;
          *(_BYTE *)(v17 + 148) = v62;
          if ( *(_BYTE *)(v15 + 2484) )
          {
            v61 = v15 + 2484;
            if ( v15 == -2484 )
              goto LABEL_101;
          }
          else
          {
            if ( *(_BYTE *)(v15 + 2544) )
              v61 = v15 + 2544;
            else
              v61 = v55;
            if ( !v61 )
            {
LABEL_101:
              *(_BYTE *)(v17 + 149) = v61;
              v57 = *v18;
              if ( (*v18 & 2) == 0 )
                goto LABEL_102;
              goto LABEL_104;
            }
          }
          if ( (*(_BYTE *)(a2 + 7236) & 2) != 0 )
            LODWORD(v61) = (*(unsigned __int8 *)(v61 + 1) >> 4) & 1;
          else
            LOBYTE(v61) = 0;
          goto LABEL_101;
        }
      }
      v55 = 0;
      goto LABEL_64;
    }
    return 2;
  }
  else
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Lim Join request is NULL",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "lim_sta_send_add_bss_pre_assoc");
    return 16;
  }
}
