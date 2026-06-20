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
  bool v40; // w23
  int v41; // w8
  unsigned int v42; // w20
  int v43; // w8
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  __int16 v52; // w8
  int v53; // w8
  __int64 v54; // x27
  char v55; // w8
  char v56; // w8
  int v57; // w8
  int v58; // w8
  int v59; // w9
  __int64 v60; // x8
  char v61; // w8
  char v62; // w8
  __int16 v63; // w2
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7
  int v80; // w8
  unsigned int v81; // w0
  __int64 v83; // [xsp+10h] [xbp-10h]
  __int64 v84; // [xsp+18h] [xbp-8h]

  v10 = *(_QWORD *)(a2 + 112);
  if ( v10 )
  {
    v13 = *(_QWORD *)(a1 + 8);
    v14 = _qdf_mem_malloc(0x1A08u, "lim_sta_send_add_bss_pre_assoc", 4310);
    if ( v14 )
    {
      v15 = v14;
      v16 = _qdf_mem_malloc(0x368u, "lim_sta_send_add_bss_pre_assoc", 4315);
      if ( !v16 )
      {
        v42 = 2;
LABEL_128:
        _qdf_mem_free(v15);
        return v42;
      }
      v17 = v16;
      v84 = v13;
      v18 = (char *)(a2 + 7024);
      ielen_from_bss_description = (unsigned __int16)wlan_get_ielen_from_bss_description(v10 + 4548);
      qdf_mem_set((void *)v15, 0x1A08u, 0);
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
      if ( *(_BYTE *)(a1 + 8884) )
        lim_decide_sta_protection_on_assoc(a1, v15, a2);
      v28 = (_WORD *)(v15 + 1201);
      qdf_mem_copy((void *)v17, (const void *)(v10 + 4550), 6u);
      *(_WORD *)(v17 + 14) = *(_WORD *)(v10 + 4564);
      v37 = *(_BYTE *)(v15 + 83);
      *(_BYTE *)(v17 + 848) = 0;
      *(_BYTE *)(v17 + 16) = v37;
      *(_DWORD *)(v17 + 8) = *(_DWORD *)(v10 + 4568);
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
            *(_DWORD *)(v17 + 852) = v41;
          }
        }
      }
      if ( !*(_BYTE *)(a2 + 7170)
        || (!*(_BYTE *)(v15 + 2484) || *(__int16 *)(v15 + 2490) == -1 || *(__int16 *)(v15 + 2494) == -1)
        && (!*(_BYTE *)(v15 + 2544) || *(__int16 *)(v15 + 2550) == -1 || *(__int16 *)(v15 + 2554) == -1) )
      {
        v83 = 0;
        *(_BYTE *)(v17 + 850) = 0;
      }
      else
      {
        *(_BYTE *)(v17 + 850) = 1;
        if ( *(_BYTE *)(v15 + 2500) )
        {
          v83 = v15 + 2500;
        }
        else if ( *(_BYTE *)(v15 + 2560) )
        {
          v83 = v15 + 2560;
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
          v83 = 0;
        }
        v43 = (*(_DWORD *)(v17 + 176) >> 23) & 7;
        *(_DWORD *)(v17 + 852) = *(_DWORD *)(a2 + 7176);
        *(_BYTE *)(v17 + 56) = v43;
      }
      if ( *(_BYTE *)(a2 + 8676) == 1 && *(_BYTE *)(v15 + 2640) )
      {
        lim_update_bss_he_capable(a1, v17);
        lim_add_bss_he_cfg(v17, a2);
      }
      if ( a2 && *(_BYTE *)(a2 + 10071) == 1 && *(_BYTE *)(v15 + 2740) )
      {
        lim_update_bss_eht_capable(a1, v17);
        lim_add_bss_eht_cfg(v17, a2);
      }
      *(_BYTE *)(v17 + 32) = 1;
      qdf_mem_copy((void *)(v17 + 24), (const void *)(v10 + 4550), 6u);
      v52 = *(_WORD *)(*(_QWORD *)(a1 + 8) + 3404LL);
      *(_WORD *)(v17 + 30) = 0;
      *(_WORD *)(v17 + 43) = 0;
      *(_WORD *)(v17 + 40) = v52;
      *(_BYTE *)(v17 + 140) = 0;
      v53 = *(unsigned __int8 *)(a2 + 154);
      if ( (unsigned int)(v53 - 7) >= 7 && v53 != 5 && *(_BYTE *)(a2 + 154) || !*(_BYTE *)(v15 + 1200) )
      {
        v56 = *v18;
        if ( (*v18 & 2) == 0 )
        {
LABEL_110:
          if ( (v56 & 1) == 0 || !*(_BYTE *)(v15 + 2467) && !*(_BYTE *)(v17 + 45) )
          {
            v62 = 0;
            goto LABEL_118;
          }
LABEL_117:
          v62 = 1;
LABEL_118:
          *(_BYTE *)(v17 + 42) = v62;
          lim_populate_peer_rate_set(
            a1,
            (char *)(v17 + 60),
            (_BYTE *)(v15 + 1204),
            0,
            a2,
            v15 + 2484,
            (char *)(v15 + 2640),
            v15 + 2740,
            v44,
            v45,
            v46,
            v47,
            v48,
            v49,
            v50,
            v51,
            0,
            v10 + 4548);
          *(_DWORD *)(v17 + 144) = *(_DWORD *)(a2 + 424);
          *(_BYTE *)(v17 + 849) = *(_BYTE *)(a2 + 7032);
          *(_BYTE *)(v17 + 167) = *(_BYTE *)(a2 + 10);
          *(_BYTE *)(v17 + 148) = *(_BYTE *)(a2 + 8);
          if ( (*v18 & 0x10) != 0 )
          {
            *(_BYTE *)(v17 + 18) = 1;
            *(_BYTE *)(v17 + 141) = 1;
          }
          v63 = *(_WORD *)(a2 + 8);
          *(_DWORD *)(a2 + 72) = 20;
          qdf_trace(53, 0, v63, 20);
          if ( cds_is_5_mhz_enabled(v64, v65, v66, v67, v68, v69, v70, v71) )
          {
            v80 = 5;
          }
          else
          {
            if ( !cds_is_10_mhz_enabled(v72, v73, v74, v75, v76, v77, v78, v79) )
            {
LABEL_125:
              if ( **(_BYTE **)(a2 + 9976) == 1 )
                *(_BYTE *)(v17 + 864) = 1;
              v81 = wma_pre_assoc_req(v17);
              lim_process_sta_add_bss_rsp_pre_assoc(a1, v17, a2, v81);
              _qdf_mem_free(v17);
              v42 = 0;
              goto LABEL_128;
            }
            v80 = 6;
          }
          *(_DWORD *)(v17 + 852) = v80;
          *(_DWORD *)(v17 + 48) = v80;
          goto LABEL_125;
        }
LABEL_112:
        if ( *(_BYTE *)(v15 + 2469) || *(_BYTE *)(v17 + 45) )
          goto LABEL_117;
        goto LABEL_110;
      }
      *(_BYTE *)(v17 + 45) = 1;
      if ( *(_BYTE *)(a2 + 7170)
        && (*(_BYTE *)(v15 + 2484) && *(__int16 *)(v15 + 2490) != -1 && *(__int16 *)(v15 + 2494) != -1
         || *(_BYTE *)(v15 + 2544) && *(__int16 *)(v15 + 2550) != -1 && *(__int16 *)(v15 + 2554) != -1) )
      {
        v54 = v15 + 2484;
        *(_BYTE *)(v17 + 151) = 1;
        if ( *(_BYTE *)(v15 + 2484) )
          goto LABEL_56;
        if ( *(_BYTE *)(v15 + 2544) )
        {
          v54 = v15 + 2544;
LABEL_56:
          if ( v54 )
          {
            if ( ((*(_WORD *)(v54 + 1) & 0x800) != 0 || (*(_BYTE *)(v54 + 3) & 8) != 0)
              && (*(_BYTE *)(a2 + 7269) & 0x10) != 0 )
            {
              *(_BYTE *)(v17 + 156) = 1;
            }
            if ( (*(_BYTE *)(v54 + 3) & 8) != 0 && (*(_BYTE *)(a2 + 7270) & 0x10) != 0 )
              *(_BYTE *)(v17 + 158) = 1;
            if ( (*(_WORD *)(v54 + 1) & 0x1000) != 0 && (*(_BYTE *)(a2 + 7269) & 8) != 0 )
              *(_BYTE *)(v17 + 157) = 1;
          }
LABEL_68:
          if ( *(_BYTE *)(a2 + 8676) == 1 && *(_BYTE *)(v15 + 2640) )
            lim_intersect_ap_he_caps(a2, v17, v15, 0, v10 + 4548);
          if ( a2 && *(_BYTE *)(a2 + 10071) == 1 && *(_BYTE *)(v15 + 2740) )
            lim_intersect_ap_eht_caps(a2, v17, v15, 0);
          v55 = !v40;
          if ( (*v28 & 2) == 0 )
            v55 = 1;
          if ( (v55 & 1) != 0 )
          {
            *(_DWORD *)(v17 + 48) = 0;
          }
          else
          {
            *(_DWORD *)(v17 + 48) = (*(_DWORD *)(v15 + 1262) >> 2) & 1;
            if ( v83 && *(_BYTE *)(v17 + 151) && *(_BYTE *)(v83 + 1) )
              *(_DWORD *)(v17 + 48) = *(unsigned __int8 *)(v83 + 1) + 1;
          }
          *(_DWORD *)(v17 + 52) = ((unsigned __int16)*v28 >> 2) & 3;
          *(_BYTE *)(v17 + 57) = (*(_BYTE *)(v15 + 1203) >> 2) & 7;
          if ( (*(_WORD *)(a2 + 7266) & 0x20) != 0 )
            v57 = (*(unsigned __int8 *)v28 >> 5) & 1;
          else
            LOBYTE(v57) = 0;
          *(_BYTE *)(v17 + 59) = v57;
          if ( (*(_WORD *)(a2 + 7266) & 0x40) != 0 )
            v58 = (*(unsigned __int8 *)v28 >> 6) & 1;
          else
            LOBYTE(v58) = 0;
          *(_BYTE *)(v17 + 58) = v58;
          v59 = *(unsigned __int8 *)(v17 + 156);
          *(_BYTE *)(v17 + 56) = *(_BYTE *)(v15 + 1203) & 3;
          if ( v59 && *(_BYTE *)(v84 + 2883) == 1 )
          {
            LOBYTE(v60) = 0;
            *(_BYTE *)(v17 + 164) = 0;
            goto LABEL_109;
          }
          if ( (*(_BYTE *)(a2 + 7236) & 1) != 0 )
            v61 = *(_BYTE *)v28 & 1;
          else
            v61 = 0;
          *(_BYTE *)(v17 + 164) = v61;
          if ( *(_BYTE *)(v15 + 2484) )
          {
            v60 = v15 + 2484;
            if ( v15 == -2484 )
              goto LABEL_109;
          }
          else
          {
            if ( *(_BYTE *)(v15 + 2544) )
              v60 = v15 + 2544;
            else
              v60 = v54;
            if ( !v60 )
            {
LABEL_109:
              *(_BYTE *)(v17 + 165) = v60;
              v56 = *v18;
              if ( (*v18 & 2) == 0 )
                goto LABEL_110;
              goto LABEL_112;
            }
          }
          if ( (*(_BYTE *)(a2 + 7236) & 2) != 0 )
            LODWORD(v60) = (*(unsigned __int8 *)(v60 + 1) >> 4) & 1;
          else
            LOBYTE(v60) = 0;
          goto LABEL_109;
        }
      }
      v54 = 0;
      goto LABEL_68;
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
