__int64 __fastcall sme_ese_send_beacon_req_scan_results(
        _QWORD *a1,
        unsigned __int8 a2,
        unsigned int a3,
        unsigned int a4,
        _QWORD *a5,
        char a6,
        unsigned __int8 a7)
{
  _WORD *v7; // x19
  _QWORD *v8; // x20
  __int64 v11; // x22
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  const char *v20; // x2
  __int64 v21; // x28
  int v22; // w23
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  int v31; // w8
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 *v40; // x24
  __int64 v41; // x12
  char *v42; // x19
  __int64 *v43; // x25
  __int64 *v44; // x21
  _WORD *v45; // x23
  __int64 *v46; // x20
  _DWORD *v47; // x22
  __int64 v48; // x26
  int v49; // w27
  int v50; // w27
  _QWORD *v51; // x10
  unsigned int v52; // w8
  const char *v53; // x2
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  __int64 v71; // [xsp+0h] [xbp-2B0h]
  __int64 v72; // [xsp+8h] [xbp-2A8h]
  _WORD *v73; // [xsp+18h] [xbp-298h]
  _WORD *v74; // [xsp+20h] [xbp-290h]
  _WORD *v75; // [xsp+28h] [xbp-288h]
  _WORD *v76; // [xsp+30h] [xbp-280h]
  _WORD *v77; // [xsp+38h] [xbp-278h]
  _WORD *v78; // [xsp+40h] [xbp-270h]
  _WORD *v79; // [xsp+48h] [xbp-268h]
  __int64 v81; // [xsp+58h] [xbp-258h]
  unsigned int v82; // [xsp+64h] [xbp-24Ch]
  _WORD *v83; // [xsp+C0h] [xbp-1F0h]
  char v84; // [xsp+CCh] [xbp-1E4h]
  __int64 v85; // [xsp+D0h] [xbp-1E0h]
  int v87; // [xsp+E0h] [xbp-1D0h]
  int v89; // [xsp+104h] [xbp-1ACh]
  __int64 v90; // [xsp+108h] [xbp-1A8h]
  _WORD *v91; // [xsp+110h] [xbp-1A0h]
  _WORD *v92; // [xsp+118h] [xbp-198h]
  char v93; // [xsp+124h] [xbp-18Ch]
  _DWORD *v94; // [xsp+128h] [xbp-188h]
  _BYTE *v95; // [xsp+130h] [xbp-180h]
  _BYTE *v96; // [xsp+138h] [xbp-178h]
  _BYTE *v97; // [xsp+140h] [xbp-170h]
  __int64 v98; // [xsp+148h] [xbp-168h]
  unsigned int v99; // [xsp+154h] [xbp-15Ch] BYREF
  __int64 s[43]; // [xsp+158h] [xbp-158h] BYREF

  s[41] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v99 = 0;
  if ( a2 < 6u )
  {
    v8 = a1;
    v11 = (__int64)&a1[68 * a2 + 2186];
    memset(s, 0, 0x148u);
    if ( !v11 )
    {
      v20 = "%s: rrm_ctx is NULL";
      goto LABEL_7;
    }
    v98 = (__int64)v8;
    if ( !a5 && !a6 )
    {
      v20 = "%s: Beacon report xmit Ind to HDD Failed";
LABEL_7:
      qdf_trace_msg(0x34u, 2u, v20, v12, v13, v14, v15, v16, v17, v18, v19, "sme_ese_send_beacon_req_scan_results");
      LODWORD(v7) = 16;
      goto LABEL_83;
    }
    v85 = _qdf_mem_malloc(0x180u, "sme_ese_send_beacon_req_scan_results", 308);
    if ( !v85 )
    {
      LODWORD(v7) = 2;
      goto LABEL_83;
    }
    if ( a5 )
      v21 = *a5;
    else
      v21 = 0;
    v22 = 0;
    v82 = a4;
    v83 = (_WORD *)(v11 + 436);
    v81 = v11;
    v84 = 2 * a6;
    v78 = (_WORD *)(v11 + 460);
    v79 = (_WORD *)(v11 + 448);
    v76 = (_WORD *)(v11 + 484);
    v77 = (_WORD *)(v11 + 472);
    v74 = (_WORD *)(v11 + 508);
    v75 = (_WORD *)(v11 + 496);
    v73 = (_WORD *)(v11 + 520);
    while ( 1 )
    {
      qdf_mem_set(s, 0x148u, 0);
      v31 = *(unsigned __int8 *)(v11 + 432);
      if ( !*(_BYTE *)(v11 + 432) )
        goto LABEL_24;
      v7 = v83;
      if ( *(_DWORD *)(v11 + 440) == a4 )
        goto LABEL_18;
      if ( v31 != 1 )
        break;
      v7 = nullptr;
LABEL_26:
      v93 = v31;
LABEL_27:
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: freq: %d MeasToken: %d",
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        "sme_ese_send_beacon_req_scan_results",
        a4,
        LOWORD(s[0]));
      if ( v21 )
      {
        v91 = v7;
        v40 = &s[1];
        v89 = (unsigned __int8)v22;
        v87 = v22;
        v41 = 0;
        v43 = &s[5];
        v42 = (char *)&s[1] + 6;
        v94 = (_DWORD *)&s[2] + 1;
        v95 = (char *)&s[1] + 5;
        v45 = (_WORD *)&s[4] + 1;
        v44 = &s[4];
        v47 = (_DWORD *)&s[3] + 1;
        v46 = &s[3];
        v92 = (_WORD *)&s[1] + 1;
        v96 = (char *)&s[1] + 4;
        v97 = (char *)&s[1] + 1;
        while ( 1 )
        {
          v48 = v98;
          v90 = v41;
          do
          {
            v49 = *(unsigned __int16 *)(v21 + 56);
            *(_BYTE *)v40 = wlan_reg_freq_to_chan(
                              *(_QWORD *)(v48 + 21632),
                              *(_DWORD *)(v21 + 84),
                              v32,
                              v33,
                              v34,
                              v35,
                              v36,
                              v37,
                              v38,
                              v39);
            *v97 = 0;
            if ( (v93 & 1) == 0 )
              *v92 = v91[5];
            *v96 = *(_DWORD *)(v21 + 76);
            *v95 = *(_BYTE *)(v21 + 80);
            *v94 = *(_DWORD *)(v21 + 88);
            *(_DWORD *)v46 = *(_DWORD *)(v21 + 64);
            *v47 = *(_DWORD *)(v21 + 68);
            *(_WORD *)v44 = *(_WORD *)(v21 + 72);
            *v45 = *(_WORD *)(v21 + 74);
            qdf_mem_copy(v42, (const void *)(v21 + 58), 6u);
            v48 = v98;
          }
          while ( (unsigned int)sir_beacon_ie_ese_bcn_report(v98, (unsigned int *)(v21 + 160), v49 - 102, v43, &v99) == 16 );
          *((_BYTE *)v40 + 28) = v99;
          v50 = 8;
          LODWORD(v72) = -*(char *)(v21 + 80);
          LODWORD(v71) = *(_DWORD *)(v21 + 84);
          qdf_trace_msg(
            0x34u,
            8u,
            "%s: Bssid%02x:%02x:%02x:**:**:%02x Freq:%d Rssi:%d",
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            "sme_ese_send_beacon_req_scan_results",
            *(unsigned __int8 *)(v21 + 58),
            *(unsigned __int8 *)(v21 + 59),
            *(unsigned __int8 *)(v21 + 60),
            *(unsigned __int8 *)(v21 + 63),
            v71,
            v72);
          ++BYTE3(s[0]);
          if ( v90 == 7 )
          {
            v51 = a5;
            goto LABEL_42;
          }
          v41 = v90 + 1;
          v51 = a5;
          v52 = v90 + 1 + v89;
          if ( v52 >= a7 )
            break;
          v21 = a5[v52];
          v40 = &s[5 * v41 + 1];
          v46 = v40 + 2;
          v92 = (_WORD *)v40 + 1;
          v47 = (_DWORD *)v40 + 5;
          v96 = (char *)v40 + 4;
          v97 = (char *)v40 + 1;
          v44 = v40 + 3;
          v45 = (_WORD *)v40 + 13;
          v42 = (char *)v40 + 6;
          v43 = v40 + 4;
          v94 = (_DWORD *)v40 + 3;
          v95 = (char *)v40 + 5;
          if ( !v21 )
          {
            a4 = v82;
            v8 = (_QWORD *)v98;
            v50 = v90 + 1;
            v11 = v81;
            v22 = v87;
            goto LABEL_38;
          }
        }
        v50 = v90 + 1;
LABEL_42:
        a4 = v82;
        v21 = 0;
        v8 = (_QWORD *)v98;
        v11 = v81;
        v22 = v50 + v87;
        if ( v51 && (unsigned __int8)(v50 + v87) < (unsigned int)a7 )
        {
          v53 = "%s: Move to the next BSS set in cur_result list";
          v21 = v51[(unsigned __int8)(v50 + v87)];
          goto LABEL_45;
        }
      }
      else
      {
        v50 = 0;
LABEL_38:
        v21 = 0;
        v22 += v50;
      }
      v53 = "%s: Reached to the max/last BSS in cur_result list";
LABEL_45:
      qdf_trace_msg(0x34u, 2u, v53, v32, v33, v34, v35, v36, v37, v38, v39, "sme_ese_send_beacon_req_scan_results");
      BYTE2(s[0]) = v84 | (v21 != 0);
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: SME Sending BcnRep to HDD numBss: %d j: %d bss_counter: %d flag: %d",
        v54,
        v55,
        v56,
        v57,
        v58,
        v59,
        v60,
        v61,
        "sme_ese_send_beacon_req_scan_results",
        BYTE3(s[0]),
        (unsigned __int8)v50,
        (unsigned __int8)v22,
        BYTE2(s[0]));
      *(_QWORD *)(v85 + 104) = s;
      LODWORD(v7) = csr_roam_call_callback(v8, a3, v85, 0x25u, 0, v62, v63, v64, v65, v66, v67, v68, v69);
      if ( (_BYTE)v50 )
      {
        if ( s[5] )
          _qdf_mem_free(s[5]);
        if ( (unsigned __int8)v50 != 1 )
        {
          if ( s[10] )
            _qdf_mem_free(s[10]);
          if ( (unsigned __int8)v50 != 2 )
          {
            if ( s[15] )
              _qdf_mem_free(s[15]);
            if ( (unsigned __int8)v50 != 3 )
            {
              if ( s[20] )
                _qdf_mem_free(s[20]);
              if ( (unsigned __int8)v50 != 4 )
              {
                if ( s[25] )
                  _qdf_mem_free(s[25]);
                if ( (unsigned __int8)v50 != 5 )
                {
                  if ( s[30] )
                    _qdf_mem_free(s[30]);
                  if ( (unsigned __int8)v50 != 6 )
                  {
                    if ( s[35] )
                      _qdf_mem_free(s[35]);
                    if ( (unsigned __int8)v50 != 7 )
                    {
                      if ( s[40] )
                        _qdf_mem_free(s[40]);
                      if ( (unsigned __int8)v50 != 8 )
                        goto LABEL_81;
                    }
                  }
                }
              }
            }
          }
        }
      }
      if ( !v21 )
        goto LABEL_82;
    }
    v7 = v79;
    if ( *(_DWORD *)(v11 + 452) != a4 )
    {
      if ( v31 == 2 )
      {
LABEL_24:
        v7 = nullptr;
LABEL_25:
        LOBYTE(v31) = 1;
        goto LABEL_26;
      }
      v7 = v78;
      if ( *(_DWORD *)(v11 + 464) != a4 )
      {
        if ( v31 == 3 )
          goto LABEL_24;
        v7 = v77;
        if ( *(_DWORD *)(v11 + 476) != a4 )
        {
          if ( v31 == 4 )
            goto LABEL_24;
          v7 = v76;
          if ( *(_DWORD *)(v11 + 488) != a4 )
          {
            if ( v31 == 5 )
              goto LABEL_24;
            v7 = v75;
            if ( *(_DWORD *)(v11 + 500) != a4 )
            {
              if ( v31 == 6 )
                goto LABEL_24;
              v7 = v74;
              if ( *(_DWORD *)(v11 + 512) != a4 )
              {
                if ( v31 == 7 )
                  goto LABEL_24;
                v7 = v73;
                if ( *(_DWORD *)(v11 + 524) != a4 )
                {
                  if ( v31 != 8 )
                    goto LABEL_81;
                  goto LABEL_24;
                }
              }
            }
          }
        }
      }
    }
LABEL_18:
    if ( v7 )
    {
      v93 = 0;
      LOWORD(s[0]) = *v7;
      goto LABEL_27;
    }
    goto LABEL_25;
  }
LABEL_81:
  __break(0x5512u);
LABEL_82:
  _qdf_mem_free(v85);
LABEL_83:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v7;
}
