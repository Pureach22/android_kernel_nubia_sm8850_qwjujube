__int64 __fastcall lim_check_partner_link_for_cmn_akm(
        __int64 result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x26
  int v10; // w8
  __int64 v11; // x19
  __int64 v12; // x0
  __int64 v13; // x27
  _QWORD *curr_candidate_entry; // x0
  __int64 v15; // x22
  __int64 v16; // x21
  __int64 v17; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  unsigned int v26; // w8
  unsigned __int64 v27; // x28
  unsigned __int64 v28; // x20
  int *v29; // x24
  __int64 v30; // x4
  __int64 v31; // x5
  __int64 v32; // x6
  __int64 v33; // x7
  int v34; // w10
  unsigned __int64 v35; // x8
  unsigned __int8 *v36; // x9
  int v37; // w10
  int v38; // w8
  const char *v39; // x2
  __int64 v40; // x24
  __int64 v41; // x23
  char v42; // w20
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  __int64 v51; // x0
  __int64 v52; // x0
  unsigned __int8 *v53; // x22
  int v54; // w20
  __int64 v55; // x24
  int param; // w0
  __int16 v57; // w8
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  int v74; // w10
  unsigned int v75; // w8
  int v76; // w11
  unsigned __int8 *v77; // x9
  unsigned int v78; // w10
  int v79; // t1
  size_t v80; // x2
  _QWORD *scan_result; // x0
  double v82; // d0
  double v83; // d1
  double v84; // d2
  double v85; // d3
  double v86; // d4
  double v87; // d5
  double v88; // d6
  double v89; // d7
  double v90; // d0
  double v91; // d1
  double v92; // d2
  double v93; // d3
  double v94; // d4
  double v95; // d5
  double v96; // d6
  double v97; // d7
  _QWORD *v98; // x1
  unsigned __int8 v99; // w28
  const char *v100; // x24
  __int64 v101; // x25
  double v102; // d0
  double v103; // d1
  double v104; // d2
  double v105; // d3
  double v106; // d4
  double v107; // d5
  double v108; // d6
  double v109; // d7
  _QWORD *v110; // x23
  __int64 v111; // x8
  __int64 v112; // x4
  __int64 v113; // x5
  __int64 v114; // x6
  __int64 v115; // x7
  double v116; // d0
  double v117; // d1
  double v118; // d2
  double v119; // d3
  double v120; // d4
  double v121; // d5
  double v122; // d6
  double v123; // d7
  bool v124; // w0
  __int64 v125; // x14
  __int64 v126; // x20
  unsigned __int64 v127; // x22
  __int64 v128; // x8
  int v129; // w11
  int v130; // w8
  __int64 v132; // x8
  __int64 v133; // x27
  __int64 v134; // x0
  const char *v135; // x26
  __int64 v136; // x24
  __int64 v137; // x19
  void *v138; // x0
  unsigned __int64 v139; // x5
  __int64 v140; // x9
  unsigned __int64 v141; // x8
  __int64 v142; // x10
  int v143; // w12
  int v144; // w10
  const char *v146; // x2
  unsigned int v147; // w9
  unsigned __int64 v148; // x23
  __int64 v149; // x28
  unsigned __int64 v150; // x20
  unsigned __int8 v151; // w8
  __int64 v152; // x22
  unsigned __int64 i; // x24
  __int64 v155; // x9
  __int64 v156; // x27
  __int64 v157; // x0
  __int64 v158; // x19
  void *v159; // x0
  __int64 v160; // [xsp+0h] [xbp-60h]
  __int64 v161; // [xsp+8h] [xbp-58h]
  __int64 v162; // [xsp+10h] [xbp-50h]
  _QWORD *v163; // [xsp+18h] [xbp-48h]
  __int64 v164; // [xsp+20h] [xbp-40h]
  __int64 v165; // [xsp+28h] [xbp-38h]
  __int64 v166; // [xsp+30h] [xbp-30h]
  _QWORD *v167; // [xsp+38h] [xbp-28h] BYREF
  _QWORD *v168; // [xsp+40h] [xbp-20h] BYREF
  int v169; // [xsp+48h] [xbp-18h] BYREF
  __int16 v170; // [xsp+4Ch] [xbp-14h]
  __int64 v171; // [xsp+58h] [xbp-8h]

  v171 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_QWORD *)(result + 112);
  v170 = 0;
  v169 = 0;
  v10 = *(unsigned __int8 *)(v9 + 4368);
  v167 = nullptr;
  v168 = nullptr;
  if ( !v10 )
    goto LABEL_41;
  v11 = result;
  v12 = *(_QWORD *)(result + 16);
  v13 = *(_QWORD *)(v12 + 216);
  if ( v13 )
  {
    curr_candidate_entry = wlan_cm_get_curr_candidate_entry(v12, *(_DWORD *)(v11 + 4), a2, a3, a4, a5, a6, a7, a8, a9);
    if ( curr_candidate_entry )
    {
      v15 = (__int64)curr_candidate_entry;
      v16 = _qdf_mem_malloc(0x2D8u, "lim_check_partner_link_for_cmn_akm", 4685);
      if ( v16
        && (v17 = _qdf_mem_malloc(6LL * *(unsigned __int8 *)(v9 + 4368), "lim_check_partner_link_for_cmn_akm", 4692)) != 0 )
      {
        v26 = *(unsigned __int8 *)(v9 + 4368);
        v166 = v17;
        v164 = v15;
        if ( *(_BYTE *)(v9 + 4368) )
        {
          v27 = 0;
          v28 = 0;
          v29 = (int *)(v9 + 4376);
          while ( v27 != 4 )
          {
            if ( *((unsigned __int8 *)v29 + 6) != 255 )
            {
              if ( v28 > 5 )
                break;
              v36 = (unsigned __int8 *)(v16 + 70 + 6 * v28);
              v37 = *v29;
              *((_WORD *)v36 + 2) = *((_WORD *)v29 + 2);
              *(_DWORD *)v36 = v37;
              ++*(_BYTE *)(v16 + 16);
              v38 = *((unsigned __int16 *)v29 + 5);
              *(_DWORD *)(v16 + 268 + 4 * v28) = v38;
              ++*(_WORD *)(v16 + 18);
              if ( v28 == 5 )
                break;
              if ( v36 )
              {
                v30 = *v36;
                v31 = v36[1];
                v32 = v36[2];
                v33 = v36[5];
              }
              else
              {
                v32 = 0;
                v30 = 0;
                v31 = 0;
                v33 = 0;
              }
              LODWORD(v160) = v38;
              qdf_trace_msg(
                0x35u,
                8u,
                "%s: Filter BSSID: %02x:%02x:%02x:**:**:%02x, freq: %d",
                v18,
                v19,
                v20,
                v21,
                v22,
                v23,
                v24,
                v25,
                "lim_check_partner_link_for_cmn_akm",
                v30,
                v31,
                v32,
                v33,
                v160);
              v34 = *v29;
              v35 = v166 + 6 * v28++;
              *(_WORD *)(v35 + 4) = *((_WORD *)v29 + 2);
              *(_DWORD *)v35 = v34;
              v26 = *(unsigned __int8 *)(v9 + 4368);
            }
            ++v27;
            v29 += 12;
            if ( v27 >= v26 )
              goto LABEL_42;
          }
LABEL_117:
          __break(0x5512u);
        }
LABEL_42:
        if ( !*(_BYTE *)(v16 + 16) )
        {
          v41 = v166;
          v40 = 0;
          v42 = 1;
          goto LABEL_20;
        }
        v55 = *(_QWORD *)(v11 + 16);
        *(_DWORD *)(v16 + 40) = wlan_crypto_get_param(v55, 0);
        *(_DWORD *)(v16 + 48) = wlan_crypto_get_param(v55, 1u);
        *(_DWORD *)(v16 + 52) = wlan_crypto_get_param(v55, 2u);
        *(_DWORD *)(v16 + 44) = wlan_crypto_get_param(v55, 7u);
        param = wlan_crypto_get_param(v55, 3u);
        v57 = *(_WORD *)v16;
        *(_DWORD *)(v16 + 56) = param;
        *(_WORD *)v16 = v57 | 4;
        *(_BYTE *)(v16 + 723) = *(_BYTE *)(v55 + 160);
        wlan_vdev_get_bss_peer_mld_mac(*(_QWORD *)(v11 + 16), &v169, v58, v59, v60, v61, v62, v63, v64, v65);
        v41 = v166;
        *(_WORD *)v16 |= 0x40u;
        v74 = v169;
        *(_WORD *)(v16 + 721) = v170;
        *(_DWORD *)(v16 + 717) = v74;
        v75 = *(unsigned __int8 *)(v15 + 13);
        if ( *(_BYTE *)(v15 + 13) )
        {
          v76 = *(unsigned __int8 *)(v15 + 14);
          if ( *(_BYTE *)(v15 + 14) )
          {
            v77 = (unsigned __int8 *)(v15 + 15);
            v78 = v75 - 1;
            while ( (v76 | 0x20) == 0x20 )
            {
              if ( !v78 )
                goto LABEL_54;
              v79 = *v77++;
              v76 = v79;
              --v78;
            }
            if ( v75 >= 0x20 )
              v80 = 32;
            else
              v80 = *(unsigned __int8 *)(v15 + 13);
            *(_BYTE *)(v16 + 100) = v80;
            qdf_mem_copy((void *)(v16 + 101), (const void *)(v15 + 14), v80);
            ++*(_BYTE *)(v16 + 17);
          }
        }
LABEL_54:
        scan_result = scm_get_scan_result(v13, v16, v66, v67, v68, v69, v70, v71, v72, v73);
        v40 = (__int64)scan_result;
        if ( scan_result )
        {
          if ( *((_DWORD *)scan_result + 4) )
          {
            v163 = scan_result;
            qdf_list_peek_front(scan_result, &v168);
            v98 = v168;
            if ( v168 )
            {
              v99 = 0;
              v100 = "%s: Entry BSSID: %02x:%02x:%02x:**:**:%02x, freq %d";
              v101 = v9 + 4382;
              v162 = v9;
              v165 = v9 + 4376;
              while ( 1 )
              {
                qdf_list_peek_next(v163, v98, &v167);
                v110 = v168;
                v111 = v168[3];
                if ( v111 == -1 )
                {
                  v114 = 0;
                  v112 = 0;
                  v113 = 0;
                  v115 = 0;
                }
                else
                {
                  v112 = *(unsigned __int8 *)(v111 + 1);
                  v113 = *(unsigned __int8 *)(v111 + 2);
                  v114 = *(unsigned __int8 *)(v111 + 3);
                  v115 = *(unsigned __int8 *)(v111 + 6);
                }
                LODWORD(v160) = *(_DWORD *)(v111 + 1192);
                qdf_trace_msg(
                  0x35u,
                  8u,
                  v100,
                  v102,
                  v103,
                  v104,
                  v105,
                  v106,
                  v107,
                  v108,
                  v109,
                  "lim_check_partner_link_for_cmn_akm",
                  v112,
                  v113,
                  v114,
                  v115,
                  v160);
                v124 = scm_scan_entries_contain_cmn_akm(v164, v110[3], v116, v117, v118, v119, v120, v121, v122, v123);
                v125 = v165;
                if ( !v124 )
                {
                  if ( *(_BYTE *)(v9 + 4368) )
                    break;
                }
LABEL_78:
                LODWORD(v139) = *(unsigned __int8 *)(v16 + 16);
                if ( *(_BYTE *)(v16 + 16) && (_DWORD)v139 != v99 )
                {
                  v140 = v166;
                  v141 = 1;
                  do
                  {
                    v142 = v110[3];
                    v143 = *(_DWORD *)(v142 + 1);
                    v144 = *(unsigned __int16 *)(v142 + 5);
                    if ( *(_DWORD *)v140 == v143 && *(unsigned __int16 *)(v140 + 4) == v144 )
                    {
                      ++v99;
                      *(_WORD *)(v140 + 4) = 0;
                      *(_DWORD *)v140 = 0;
                    }
                    v139 = *(unsigned __int8 *)(v16 + 16);
                    if ( v141 >= v139 )
                      break;
                    v140 += 6;
                    ++v141;
                  }
                  while ( (_DWORD)v139 != v99 );
                }
                v98 = v167;
                v167 = nullptr;
                v168 = v98;
                if ( !v98 )
                  goto LABEL_94;
              }
              v126 = 0;
              v127 = 0;
              while ( v126 != 192 )
              {
                if ( *(unsigned __int8 *)(v101 + v126) != 255 )
                {
                  v128 = v110[3];
                  v129 = *(_DWORD *)(v128 + 1);
                  v130 = *(unsigned __int16 *)(v128 + 5);
                  if ( *(_DWORD *)(v125 + v126) == v129 && *(unsigned __int16 *)(v125 + v126 + 4) == v130 )
                  {
                    v132 = *(_QWORD *)(v11 + 112);
                    if ( v132 )
                    {
                      if ( v127 < *(unsigned __int8 *)(v132 + 4368) )
                      {
                        if ( v126 == 144 )
                          goto LABEL_117;
                        v133 = v132 + 4382;
                        if ( *(unsigned __int8 *)(v132 + 4382 + v126) != 255 )
                        {
                          v134 = *(_QWORD *)(v11 + 16);
                          v135 = v100;
                          v136 = v11;
                          v137 = v132 + v126;
                          mlo_mgr_clear_ap_link_info(v134, v132 + v126 + 4376);
                          v138 = (void *)(v137 + 4376);
                          v11 = v136;
                          v100 = v135;
                          v9 = v162;
                          qdf_mem_set(v138, 0x30u, 0);
                          v125 = v165;
                          *(_BYTE *)(v133 + v126) = -1;
                        }
                      }
                    }
                  }
                }
                ++v127;
                v126 += 48;
                if ( v127 >= *(unsigned __int8 *)(v9 + 4368) )
                  goto LABEL_78;
              }
              goto LABEL_117;
            }
            LODWORD(v139) = *(unsigned __int8 *)(v16 + 16);
            v99 = 0;
LABEL_94:
            if ( (_DWORD)v139 == v99
              || (qdf_trace_msg(
                    0x35u,
                    8u,
                    "%s: Unique entries found (%d), actual partner links (%d)",
                    v90,
                    v91,
                    v92,
                    v93,
                    v94,
                    v95,
                    v96,
                    v97,
                    "lim_check_partner_link_for_cmn_akm",
                    v99),
                  v147 = *(unsigned __int8 *)(v16 + 16),
                  !*(_BYTE *)(v16 + 16)) )
            {
              v42 = 1;
            }
            else
            {
              v148 = 0;
              v149 = v9 + 4376;
              v161 = v11;
              do
              {
                v150 = v166 + 6 * v148;
                if ( *(_DWORD *)v150 | *(unsigned __int16 *)(v150 + 4) )
                {
                  v151 = *(_BYTE *)(v9 + 4368);
                  if ( v151 )
                  {
                    v152 = 0;
                    for ( i = 0; i < v151; ++i )
                    {
                      if ( v152 == 192 )
                        goto LABEL_117;
                      if ( *(unsigned __int8 *)(v9 + 4382 + v152) != 255
                        && *(_DWORD *)(v149 + v152) == *(_DWORD *)v150
                        && *(unsigned __int16 *)(v149 + v152 + 4) == *(unsigned __int16 *)(v150 + 4) )
                      {
                        v155 = *(_QWORD *)(v11 + 112);
                        if ( v155 )
                        {
                          if ( i < *(unsigned __int8 *)(v155 + 4368) )
                          {
                            if ( v152 == 144 )
                              goto LABEL_117;
                            v156 = v155 + 4382;
                            if ( *(unsigned __int8 *)(v155 + 4382 + v152) != 255 )
                            {
                              v157 = *(_QWORD *)(v11 + 16);
                              v158 = v155 + v152;
                              mlo_mgr_clear_ap_link_info(v157, v155 + v152 + 4376);
                              v159 = (void *)(v158 + 4376);
                              v11 = v161;
                              qdf_mem_set(v159, 0x30u, 0);
                              *(_BYTE *)(v156 + v152) = -1;
                              v151 = *(_BYTE *)(v9 + 4368);
                            }
                          }
                        }
                      }
                      v152 += 48;
                    }
                    v147 = *(unsigned __int8 *)(v16 + 16);
                  }
                }
                ++v148;
                v42 = 1;
              }
              while ( v148 < v147 );
            }
            v40 = (__int64)v163;
            v15 = v164;
            v41 = v166;
LABEL_20:
            _qdf_mem_free(v16);
            _qdf_mem_free(v41);
            if ( v40 )
              scm_purge_scan_results(v40, v43, v44, v45, v46, v47, v48, v49, v50);
            v51 = *(_QWORD *)(v15 + 1320);
            if ( v51 )
              _qdf_mem_free(v51);
            v52 = *(_QWORD *)(v15 + 1896);
            if ( v52 )
              _qdf_mem_free(v52);
            result = _qdf_mem_free(v15);
            if ( (v42 & 1) != 0 )
              goto LABEL_41;
            v53 = *(unsigned __int8 **)(v11 + 112);
            if ( !v53 )
              goto LABEL_41;
            goto LABEL_31;
          }
          v146 = "%s: No partner entries found";
        }
        else
        {
          v146 = "%s: Empty scan list";
        }
        qdf_trace_msg(0x35u, 8u, v146, v82, v83, v84, v85, v86, v87, v88, v89, "lim_check_partner_link_for_cmn_akm");
      }
      else
      {
        v40 = 0;
        v41 = 0;
      }
      v42 = 0;
      goto LABEL_20;
    }
    v39 = "%s: Current candidate NULL";
  }
  else
  {
    v39 = "%s: PDEV NULL";
  }
  result = qdf_trace_msg(0x35u, 2u, v39, a2, a3, a4, a5, a6, a7, a8, a9, "lim_check_partner_link_for_cmn_akm");
  v53 = *(unsigned __int8 **)(v11 + 112);
  if ( !v53 )
    goto LABEL_41;
LABEL_31:
  v54 = v53[4368];
  v53[4368] = 0;
  if ( v54 )
  {
    if ( v53[4382] != 255 )
    {
      mlo_mgr_clear_ap_link_info(*(_QWORD *)(v11 + 16), v53 + 4376);
      result = (__int64)qdf_mem_set(v53 + 4376, 0x30u, 0);
      v53[4382] = -1;
    }
    if ( v54 != 1 )
    {
      if ( v53[4430] != 255 )
      {
        mlo_mgr_clear_ap_link_info(*(_QWORD *)(v11 + 16), v53 + 4424);
        result = (__int64)qdf_mem_set(v53 + 4424, 0x30u, 0);
        v53[4430] = -1;
      }
      if ( v54 != 2 )
      {
        if ( v53[4478] != 255 )
        {
          mlo_mgr_clear_ap_link_info(*(_QWORD *)(v11 + 16), v53 + 4472);
          result = (__int64)qdf_mem_set(v53 + 4472, 0x30u, 0);
          v53[4478] = -1;
        }
        if ( v54 != 3 )
          goto LABEL_117;
      }
    }
  }
LABEL_41:
  _ReadStatusReg(SP_EL0);
  return result;
}
