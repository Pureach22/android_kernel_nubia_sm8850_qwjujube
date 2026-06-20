__int64 __fastcall wlan_hdd_cfg80211_update_vendor_channel(__int64 a1, __int64 *a2, __int64 a3, unsigned int a4)
{
  __int64 *v6; // x19
  __int64 v8; // x0
  __int64 result; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  const char *v27; // x2
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  int v36; // w19
  const char *v37; // x2
  int v38; // w25
  int v39; // w8
  unsigned int v40; // w26
  unsigned __int16 *v41; // x9
  unsigned int v42; // w10
  __int64 v43; // x10
  __int64 v44; // x20
  __int64 v45; // x20
  int v46; // w9
  unsigned int v47; // w8
  unsigned __int16 *v48; // x10
  unsigned int v49; // w11
  __int64 v50; // x11
  __int64 v51; // x20
  __int64 v52; // x20
  unsigned int v53; // w19
  __int64 v54; // x0
  __int64 v55; // x20
  int v56; // w27
  unsigned int v57; // w21
  unsigned __int16 *v58; // x28
  int v59; // w9
  unsigned int v60; // w10
  unsigned int *v61; // x8
  __int64 v62; // x8
  unsigned int v63; // w9
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  __int64 v72; // x8
  __int64 v73; // x0
  int v74; // w27
  unsigned int v75; // w22
  unsigned __int16 *v76; // x28
  int v77; // w8
  unsigned int v78; // w9
  unsigned int *v79; // x9
  __int64 v80; // x8
  unsigned int v81; // w9
  double v82; // d0
  double v83; // d1
  double v84; // d2
  double v85; // d3
  double v86; // d4
  double v87; // d5
  double v88; // d6
  double v89; // d7
  __int64 v90; // x24
  __int64 v91; // x24
  unsigned int v92; // w0
  unsigned int v93; // w21
  unsigned int v94; // w22
  double v95; // d0
  double v96; // d1
  double v97; // d2
  double v98; // d3
  double v99; // d4
  double v100; // d5
  double v101; // d6
  double v102; // d7
  __int64 v103; // x23
  double v104; // d0
  double v105; // d1
  double v106; // d2
  double v107; // d3
  double v108; // d4
  double v109; // d5
  double v110; // d6
  double v111; // d7
  const char *v112; // x2
  unsigned int *v113; // x21
  __int64 v114; // x4
  __int64 *v115; // x22
  double v116; // d0
  double v117; // d1
  double v118; // d2
  double v119; // d3
  double v120; // d4
  double v121; // d5
  double v122; // d6
  double v123; // d7
  unsigned int v124; // w1
  __int64 v125; // x0
  unsigned int v126; // w1
  double v127; // d0
  double v128; // d1
  double v129; // d2
  double v130; // d3
  double v131; // d4
  double v132; // d5
  double v133; // d6
  double v134; // d7
  double v135; // d0
  double v136; // d1
  double v137; // d2
  double v138; // d3
  double v139; // d4
  double v140; // d5
  double v141; // d6
  double v142; // d7
  int v143; // w0
  unsigned int v144; // w8
  bool is_24ghz_ch_freq; // w8
  __int64 v146; // x0
  int v147; // w8
  __int64 v148; // x21
  unsigned int v149; // w0
  __int64 v150; // x22
  unsigned int v151; // w23
  unsigned int v152; // w0
  unsigned int updated; // w19
  double v154; // d0
  double v155; // d1
  double v156; // d2
  double v157; // d3
  double v158; // d4
  double v159; // d5
  double v160; // d6
  double v161; // d7
  unsigned int v162; // w21
  unsigned __int16 v163; // w0
  __int64 v164; // x1
  __int64 v165; // x21
  double v166; // d0
  double v167; // d1
  double v168; // d2
  double v169; // d3
  double v170; // d4
  double v171; // d5
  double v172; // d6
  double v173; // d7
  unsigned __int64 v180; // x10
  __int64 v181; // [xsp+0h] [xbp-1B0h]
  __int64 v182; // [xsp+8h] [xbp-1A8h]
  char v183; // [xsp+10h] [xbp-1A0h]
  int v184; // [xsp+14h] [xbp-19Ch]
  __int64 v185; // [xsp+18h] [xbp-198h] BYREF
  __int64 v186; // [xsp+20h] [xbp-190h] BYREF
  __int64 v187; // [xsp+28h] [xbp-188h]
  __int64 v188; // [xsp+30h] [xbp-180h]
  __int64 v189; // [xsp+38h] [xbp-178h]
  __int64 v190; // [xsp+40h] [xbp-170h]
  __int64 v191; // [xsp+48h] [xbp-168h]
  __int64 v192; // [xsp+50h] [xbp-160h]
  __int64 v193; // [xsp+58h] [xbp-158h]
  __int64 v194; // [xsp+60h] [xbp-150h]
  __int64 v195; // [xsp+68h] [xbp-148h]
  __int64 v196; // [xsp+70h] [xbp-140h]
  __int64 v197; // [xsp+78h] [xbp-138h]
  __int64 v198; // [xsp+80h] [xbp-130h]
  __int64 v199; // [xsp+88h] [xbp-128h]
  __int64 v200; // [xsp+90h] [xbp-120h]
  __int64 v201; // [xsp+98h] [xbp-118h]
  __int64 v202; // [xsp+A0h] [xbp-110h] BYREF
  __int64 v203; // [xsp+A8h] [xbp-108h]
  __int64 v204; // [xsp+B0h] [xbp-100h]
  __int64 v205; // [xsp+B8h] [xbp-F8h]
  __int64 v206; // [xsp+C0h] [xbp-F0h]
  __int64 v207; // [xsp+C8h] [xbp-E8h]
  __int64 v208; // [xsp+D0h] [xbp-E0h]
  __int64 v209; // [xsp+D8h] [xbp-D8h]
  __int64 v210; // [xsp+E0h] [xbp-D0h]
  __int64 v211; // [xsp+E8h] [xbp-C8h]
  __int64 v212; // [xsp+F0h] [xbp-C0h]
  __int64 v213; // [xsp+F8h] [xbp-B8h]
  __int64 v214; // [xsp+100h] [xbp-B0h]
  __int64 v215; // [xsp+108h] [xbp-A8h]
  __int64 v216; // [xsp+110h] [xbp-A0h]
  __int64 v217; // [xsp+118h] [xbp-98h]
  __int64 v218; // [xsp+120h] [xbp-90h] BYREF
  __int64 v219; // [xsp+128h] [xbp-88h]
  _WORD *v220; // [xsp+130h] [xbp-80h]
  __int64 v221; // [xsp+138h] [xbp-78h]
  __int64 v222; // [xsp+140h] [xbp-70h]
  __int64 v223; // [xsp+148h] [xbp-68h]
  __int64 v224; // [xsp+150h] [xbp-60h]
  __int64 v225; // [xsp+158h] [xbp-58h]
  __int64 v226; // [xsp+160h] [xbp-50h]
  _WORD *v227; // [xsp+168h] [xbp-48h]
  __int64 v228; // [xsp+170h] [xbp-40h]
  __int64 v229; // [xsp+178h] [xbp-38h]
  __int64 v230; // [xsp+180h] [xbp-30h]
  __int64 v231; // [xsp+188h] [xbp-28h]
  __int64 v232; // [xsp+190h] [xbp-20h]
  __int64 v233; // [xsp+198h] [xbp-18h]
  __int64 v234; // [xsp+1A0h] [xbp-10h]

  v6 = a2;
  v234 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = a2[4];
  v185 = 0;
  result = _osif_vdev_sync_op_start(v8, &v185, "wlan_hdd_cfg80211_update_vendor_channel");
  if ( (_DWORD)result )
    goto LABEL_51;
  if ( a1 )
  {
    v6 = *(__int64 **)(v6[4] + 55512);
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: enter",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "__wlan_hdd_cfg80211_update_vendor_channel");
    v18 = _wlan_hdd_validate_context(a1 + 1536, "__wlan_hdd_cfg80211_update_vendor_channel");
    if ( (_DWORD)v18 )
      goto LABEL_50;
    if ( (unsigned int)hdd_get_conparam(v18) == 5 )
    {
      v27 = "%s: Command not allowed in FTM mode";
LABEL_8:
      qdf_trace_msg(0x33u, 2u, v27, v19, v20, v21, v22, v23, v24, v25, v26, "__wlan_hdd_cfg80211_update_vendor_channel");
      LODWORD(v18) = -22;
      goto LABEL_50;
    }
    if ( (v6[552] & 8) == 0 )
    {
      v27 = "%s: already timeout happened for acs";
      goto LABEL_8;
    }
  }
  else
  {
    __break(0x800u);
  }
  _X8 = (unsigned __int64 *)(v6 + 552);
  __asm { PRFM            #0x11, [X8] }
  do
    v180 = __ldxr(_X8);
  while ( __stxr(v180 & 0xFFFFFFFFFFFFFFF7LL, _X8) );
  v200 = 0;
  v201 = 0;
  v198 = 0;
  v199 = 0;
  v196 = 0;
  v197 = 0;
  v194 = 0;
  v195 = 0;
  v192 = 0;
  v193 = 0;
  v190 = 0;
  v191 = 0;
  v188 = 0;
  v189 = 0;
  v186 = 0;
  v187 = 0;
  if ( (unsigned int)_nla_parse(&v186, 15, a3, a4, &acs_chan_config_policy, 31, 0) )
  {
    v36 = -22;
    v37 = "%s: Invalid ATTR";
LABEL_48:
    qdf_trace_msg(0x33u, 2u, v37, v28, v29, v30, v31, v32, v33, v34, v35, "hdd_parse_vendor_acs_chan_config");
    goto LABEL_49;
  }
  if ( v187 )
    v38 = *(unsigned __int8 *)(v187 + 4);
  else
    v38 = 255;
  if ( !(v195 | v188) )
  {
    v36 = -22;
    v37 = "%s: Both channel list and frequency list are empty";
    goto LABEL_48;
  }
  if ( v195 )
  {
    v232 = 0;
    v233 = 0;
    v230 = 0;
    v231 = 0;
    v228 = 0;
    v229 = 0;
    v226 = 0;
    v227 = nullptr;
    v224 = 0;
    v225 = 0;
    v222 = 0;
    v223 = 0;
    v220 = nullptr;
    v221 = 0;
    v218 = 0;
    v219 = 0;
    v216 = 0;
    v217 = 0;
    v214 = 0;
    v215 = 0;
    v212 = 0;
    v213 = 0;
    v210 = 0;
    v211 = 0;
    v208 = 0;
    v209 = 0;
    v206 = 0;
    v207 = 0;
    v204 = 0;
    v205 = 0;
    v202 = 0;
    v203 = 0;
    if ( (unsigned int)_nla_parse(&v218, 15, a3, a4, &acs_chan_config_policy, 31, 0) )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Invalid ATTR",
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        "hdd_extract_external_acs_frequencies");
    }
    else
    {
      v39 = (unsigned __int16)(*v227 - 4);
      if ( (unsigned int)v39 >= 4 )
      {
        v40 = 0;
        v41 = v227 + 2;
        do
        {
          v42 = *v41;
          if ( v42 < 4 )
            break;
          if ( v39 < v42 )
            break;
          ++v40;
          v43 = (v42 + 3) & 0x1FFFC;
          v39 -= v43;
          v41 = (unsigned __int16 *)((char *)v41 + v43);
        }
        while ( v39 > 3 );
        if ( v40 )
        {
          if ( v40 < 0x67 )
          {
            v54 = _qdf_mem_malloc(24 * v40, "hdd_extract_external_acs_frequencies", 20978);
            if ( v54 )
            {
              v55 = v54;
              v56 = (unsigned __int16)(*v227 - 4);
              if ( (unsigned int)v56 < 4 )
              {
LABEL_96:
                v184 = v38;
                v91 = v55;
                goto LABEL_98;
              }
              v57 = 0;
              v58 = v227 + 2;
              while ( 1 )
              {
                v63 = *v58;
                if ( v63 < 4 || v56 < v63 )
                  goto LABEL_96;
                if ( ((__int16)v58[1] & 0x80000000) == 0 )
                  break;
                if ( (unsigned int)_nla_parse(
                                     &v202,
                                     15,
                                     v58 + 2,
                                     (unsigned __int16)(v63 - 4),
                                     &acs_chan_list_policy,
                                     31,
                                     0) )
                  goto LABEL_121;
                if ( v205 )
                  *(_BYTE *)(v55 + 24LL * v57) = *(_BYTE *)(v205 + 4);
                v72 = v55 + 24LL * v57;
                if ( v212 )
                  *(_DWORD *)(v72 + 4) = *(_DWORD *)(v212 + 4);
                if ( v213 )
                  *(_DWORD *)(v72 + 8) = *(_DWORD *)(v213 + 4);
                if ( v214 )
                  *(_DWORD *)(v72 + 12) = *(_DWORD *)(v214 + 4);
                if ( v215 )
                  *(_DWORD *)(v72 + 16) = *(_DWORD *)(v215 + 4);
                if ( v210 )
                {
                  v59 = *(unsigned __int8 *)(v210 + 4);
                  v60 = v57;
                  *(_BYTE *)(v72 + 20) = v59;
                }
                else
                {
                  v59 = *(unsigned __int8 *)(v72 + 20);
                  v60 = v57;
                }
                v61 = (unsigned int *)(v55 + 24LL * v60);
                LODWORD(v182) = v59;
                LODWORD(v181) = v61[4];
                qdf_trace_msg(
                  0x33u,
                  8u,
                  "%s: index %d, pri_chan_freq %u, ht_sec_chan_freq %u seg0_freq %u seg1_freq %u width %u",
                  v64,
                  v65,
                  v66,
                  v67,
                  v68,
                  v69,
                  v70,
                  v71,
                  "hdd_extract_external_acs_frequencies",
                  v57++,
                  v61[1],
                  v61[2],
                  v61[3],
                  v181,
                  v182);
                v62 = (*v58 + 3) & 0x1FFFC;
                v56 -= v62;
                v58 = (unsigned __int16 *)((char *)v58 + v62);
                if ( v56 <= 3 )
                  goto LABEL_96;
              }
              do_trace_netlink_extack("NLA_F_NESTED is missing");
LABEL_121:
              v165 = jiffies;
              if ( hdd_extract_external_acs_frequencies___last_ticks_941 - jiffies + 125 < 0 )
              {
                qdf_trace_msg(
                  0x33u,
                  2u,
                  "%s: nla_parse failed",
                  v64,
                  v65,
                  v66,
                  v67,
                  v68,
                  v69,
                  v70,
                  v71,
                  "hdd_extract_external_acs_frequencies");
                hdd_extract_external_acs_frequencies___last_ticks_941 = v165;
              }
              _qdf_mem_free(v55);
              goto LABEL_33;
            }
          }
          else
          {
            v44 = jiffies;
            if ( hdd_extract_external_acs_frequencies___last_ticks_939 - jiffies + 125 < 0 )
            {
              qdf_trace_msg(
                0x33u,
                2u,
                "%s: Error: Exceeded max channels: %u",
                v28,
                v29,
                v30,
                v31,
                v32,
                v33,
                v34,
                v35,
                "hdd_extract_external_acs_frequencies",
                102);
              hdd_extract_external_acs_frequencies___last_ticks_939 = v44;
            }
          }
          v36 = -12;
          goto LABEL_34;
        }
      }
      v45 = jiffies;
      if ( hdd_extract_external_acs_frequencies___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Error: channel count is zero",
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          "hdd_extract_external_acs_frequencies");
        hdd_extract_external_acs_frequencies___last_ticks = v45;
      }
    }
LABEL_33:
    v36 = -22;
LABEL_34:
    v37 = "%s: Failed to extract frequencies";
    goto LABEL_48;
  }
  v232 = 0;
  v233 = 0;
  v230 = 0;
  v231 = 0;
  v228 = 0;
  v229 = 0;
  v226 = 0;
  v227 = nullptr;
  v224 = 0;
  v225 = 0;
  v222 = 0;
  v223 = 0;
  v220 = nullptr;
  v221 = 0;
  v218 = 0;
  v219 = 0;
  v216 = 0;
  v217 = 0;
  v214 = 0;
  v215 = 0;
  v212 = 0;
  v213 = 0;
  v210 = 0;
  v211 = 0;
  v208 = 0;
  v209 = 0;
  v206 = 0;
  v207 = 0;
  v204 = 0;
  v205 = 0;
  v202 = 0;
  v203 = 0;
  if ( (unsigned int)_nla_parse(&v218, 15, a3, a4, &acs_chan_config_policy, 31, 0) )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Invalid ATTR",
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      "hdd_extract_external_acs_channels");
LABEL_46:
    v36 = -22;
LABEL_47:
    v37 = "%s: Failed to extract channels";
    goto LABEL_48;
  }
  v46 = (unsigned __int16)(*v220 - 4);
  if ( (unsigned int)v46 < 4 )
    goto LABEL_44;
  v47 = 0;
  v48 = v220 + 2;
  do
  {
    v49 = *v48;
    if ( v49 < 4 )
      break;
    if ( v46 < v49 )
      break;
    ++v47;
    v50 = (v49 + 3) & 0x1FFFC;
    v46 -= v50;
    v48 = (unsigned __int16 *)((char *)v48 + v50);
  }
  while ( v46 > 3 );
  if ( !v47 )
  {
LABEL_44:
    v52 = jiffies;
    if ( hdd_extract_external_acs_channels___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Error: channel count is zero",
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        "hdd_extract_external_acs_channels");
      hdd_extract_external_acs_channels___last_ticks = v52;
    }
    goto LABEL_46;
  }
  if ( v47 >= 0x67 )
  {
    v51 = jiffies;
    if ( hdd_extract_external_acs_channels___last_ticks_944 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Error: Exceeded max channels: %u",
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        "hdd_extract_external_acs_channels",
        102);
      hdd_extract_external_acs_channels___last_ticks_944 = v51;
    }
    goto LABEL_95;
  }
  v183 = v47;
  v73 = _qdf_mem_malloc(24 * v47, "hdd_extract_external_acs_channels", 21074);
  if ( !v73 )
  {
LABEL_95:
    v36 = -12;
    goto LABEL_47;
  }
  v55 = v73;
  v184 = v38;
  v74 = (unsigned __int16)(*v220 - 4);
  if ( (unsigned int)v74 >= 4 )
  {
    v75 = 0;
    v76 = v220 + 2;
    while ( 1 )
    {
      v81 = *v76;
      if ( v81 < 4 || v74 < v81 )
        goto LABEL_97;
      if ( ((__int16)v76[1] & 0x80000000) == 0 )
        break;
      if ( (unsigned int)_nla_parse(&v202, 15, v76 + 2, (unsigned __int16)(v81 - 4), &acs_chan_list_policy, 31, 0) )
        goto LABEL_132;
      if ( v205 )
        *(_BYTE *)(v55 + 24LL * v75) = *(_BYTE *)(v205 + 4);
      v90 = v55 + 24LL * v75;
      if ( v206 )
        *(_DWORD *)(v90 + 4) = wlan_reg_legacy_chan_to_freq(
                                 *(_QWORD *)(a1 + 1544),
                                 *(unsigned __int8 *)(v206 + 4),
                                 v82,
                                 v83,
                                 v84,
                                 v85,
                                 v86,
                                 v87,
                                 v88,
                                 v89);
      if ( v207 )
        *(_DWORD *)(v90 + 8) = wlan_reg_legacy_chan_to_freq(
                                 *(_QWORD *)(a1 + 1544),
                                 *(unsigned __int8 *)(v207 + 4),
                                 v82,
                                 v83,
                                 v84,
                                 v85,
                                 v86,
                                 v87,
                                 v88,
                                 v89);
      if ( v208 )
        *(_DWORD *)(v90 + 12) = wlan_reg_legacy_chan_to_freq(
                                  *(_QWORD *)(a1 + 1544),
                                  *(unsigned __int8 *)(v208 + 4),
                                  v82,
                                  v83,
                                  v84,
                                  v85,
                                  v86,
                                  v87,
                                  v88,
                                  v89);
      if ( v209 )
        *(_DWORD *)(v90 + 16) = wlan_reg_legacy_chan_to_freq(
                                  *(_QWORD *)(a1 + 1544),
                                  *(unsigned __int8 *)(v209 + 4),
                                  v82,
                                  v83,
                                  v84,
                                  v85,
                                  v86,
                                  v87,
                                  v88,
                                  v89);
      if ( v210 )
      {
        v77 = *(unsigned __int8 *)(v210 + 4);
        v78 = v75;
        *(_BYTE *)(v90 + 20) = v77;
      }
      else
      {
        v77 = *(unsigned __int8 *)(v90 + 20);
        v78 = v75;
      }
      v79 = (unsigned int *)(v55 + 24LL * v78);
      LODWORD(v182) = v77;
      LODWORD(v181) = v79[4];
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: index %d, pri_chan_freq %u, ht_sec_chan_freq %u seg0_freq %u seg1_freq %u width %u",
        v82,
        v83,
        v84,
        v85,
        v86,
        v87,
        v88,
        v89,
        "hdd_extract_external_acs_channels",
        v75++,
        v79[1],
        v79[2],
        v79[3],
        v181,
        v182);
      v80 = (*v76 + 3) & 0x1FFFC;
      v74 -= v80;
      v76 = (unsigned __int16 *)((char *)v76 + v80);
      if ( v74 <= 3 )
        goto LABEL_97;
    }
    do_trace_netlink_extack("NLA_F_NESTED is missing");
LABEL_132:
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: nla_parse failed",
      v82,
      v83,
      v84,
      v85,
      v86,
      v87,
      v88,
      v89,
      "hdd_extract_external_acs_channels");
    _qdf_mem_free(v55);
    goto LABEL_46;
  }
LABEL_97:
  LOBYTE(v40) = v183;
  v91 = v55;
  while ( 1 )
  {
LABEL_98:
    v92 = hdd_map_nl_chan_width(*(unsigned __int8 *)(v91 + 20));
    v93 = *(_DWORD *)(v91 + 4);
    v94 = v92;
    if ( (unsigned int)wlan_hdd_validate_operation_channel(*(_QWORD *)(*v6 + 24), v93) )
      goto LABEL_104;
    v103 = v6[34];
    if ( (wlansap_is_channel_in_nol_list(v103, v93, 0) & 1) == 0 )
      break;
    v112 = "%s: channel %d is in nol";
LABEL_103:
    qdf_trace_msg(0x33u, 4u, v112, v104, v105, v106, v107, v108, v109, v110, v111, "wlan_hdd_validate_acs_channel", v93);
LABEL_104:
    if ( (unsigned __int8)v40 == 1 )
    {
      v113 = (unsigned int *)(v91 + 4);
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: invalid channel frequ %u received from app",
        v95,
        v96,
        v97,
        v98,
        v99,
        v100,
        v101,
        v102,
        "__wlan_hdd_cfg80211_update_vendor_channel",
        *(unsigned int *)(v91 + 4));
      v114 = 0;
      *(_DWORD *)(v91 + 4) = 0;
      goto LABEL_108;
    }
    v91 += 24;
    LOBYTE(v40) = v40 - 1;
    if ( !v91 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: no available channel/chanlist %d/%pK",
        v95,
        v96,
        v97,
        v98,
        v99,
        v100,
        v101,
        v102,
        "__wlan_hdd_cfg80211_update_vendor_channel",
        (unsigned __int8)v40,
        0);
      _qdf_mem_free(v55);
      LODWORD(v18) = -22;
      goto LABEL_50;
    }
  }
  if ( (wlansap_is_channel_leaking_in_nol(v103, v93, v94) & 1) != 0 )
  {
    v112 = "%s: channel freq %d is leaking in nol";
    goto LABEL_103;
  }
  v113 = (unsigned int *)(v91 + 4);
  v114 = *(unsigned int *)(v91 + 4);
LABEL_108:
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: received primary channel freq as %d",
    v104,
    v105,
    v106,
    v107,
    v108,
    v109,
    v110,
    v111,
    "__wlan_hdd_cfg80211_update_vendor_channel",
    v114);
  v115 = *(__int64 **)(*v6 + 24);
  if ( (unsigned int)qdf_mc_timer_get_current_state((__int64)(v6 + 271)) == 21 )
    qdf_mc_timer_stop((__int64)(v6 + 271));
  v124 = *v113;
  if ( !*v113 )
  {
    v124 = 2437;
    *v113 = 2437;
  }
  if ( v184 == 2 )
  {
    v162 = wlan_reg_freq_to_chan(v115[1], v124, v116, v117, v118, v119, v120, v121, v122, v123);
    *((_DWORD *)v6 + 495) = *(_DWORD *)(v91 + 4);
    v163 = hdd_map_nl_chan_width(*(unsigned __int8 *)(v91 + 20));
    *((_WORD *)v6 + 729) = v163;
    v164 = *((unsigned __int8 *)v6 + 8);
    *((_DWORD *)v6 + 186) = v163;
    wlan_hdd_set_sap_csa_reason(*v115, v164, 7);
    hdd_switch_sap_channel(v6, v162, 1);
    goto LABEL_129;
  }
  if ( v184 == 1 )
  {
    v148 = v115[2];
    v149 = wlan_reg_freq_to_chan(v115[1], v124, v116, v117, v118, v119, v120, v121, v122, v123);
    v150 = v6[34];
    v151 = v149;
    v152 = hdd_map_nl_chan_width(*(unsigned __int8 *)(v91 + 20));
    wlan_sap_update_next_channel(v150, v151, v152);
    updated = sme_update_new_channel_event(v148, *((unsigned __int8 *)v6 + 8));
  }
  else
  {
    if ( v184 )
    {
      qdf_trace_msg(
        0x33u,
        4u,
        "%s: invalid reason for timer invoke",
        v116,
        v117,
        v118,
        v119,
        v120,
        v121,
        v122,
        v123,
        "hdd_update_acs_channel");
    }
    else
    {
      *((_DWORD *)v6 + 180) = v124;
      v125 = v115[1];
      v126 = *(_DWORD *)(v91 + 12);
      LOBYTE(v202) = 0;
      LODWORD(v218) = 0;
      *((_BYTE *)v6 + 733) = wlan_reg_freq_to_chan(v125, v126, v116, v117, v118, v119, v120, v121, v122, v123);
      *((_BYTE *)v6 + 734) = wlan_reg_freq_to_chan(
                               v115[1],
                               *(_DWORD *)(v91 + 16),
                               v127,
                               v128,
                               v129,
                               v130,
                               v131,
                               v132,
                               v133,
                               v134);
      *((_BYTE *)v6 + 732) = wlan_reg_freq_to_chan(
                               v115[1],
                               *(_DWORD *)(v91 + 8),
                               v135,
                               v136,
                               v137,
                               v138,
                               v139,
                               v140,
                               v141,
                               v142);
      v143 = hdd_map_nl_chan_width(*(unsigned __int8 *)(v91 + 20));
      v144 = *((_DWORD *)v6 + 180);
      *((_DWORD *)v6 + 182) = v143;
      is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(v144);
      v146 = *v115;
      if ( is_24ghz_ch_freq )
      {
        ucfg_mlme_get_channel_bonding_24ghz(v146, (int *)&v218);
        v147 = v218 != 0;
      }
      else
      {
        if ( (unsigned int)wlan_mlme_get_vht_channel_width(v146, &v202) )
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Failed to set channel_width",
            v166,
            v167,
            v168,
            v169,
            v170,
            v171,
            v172,
            v173,
            "hdd_update_acs_sap_config");
        v147 = (unsigned __int8)v202;
      }
      *((_DWORD *)v6 + 186) = v147;
      *((_DWORD *)v6 + 495) = *(_DWORD *)(v91 + 4);
      *((_WORD *)v6 + 729) = hdd_map_nl_chan_width(*(unsigned __int8 *)(v91 + 20));
      *((_DWORD *)v6 + 497) = *(_DWORD *)(v91 + 12);
      *((_DWORD *)v6 + 498) = *(_DWORD *)(v91 + 16);
      *((_DWORD *)v6 + 496) = *(_DWORD *)(v91 + 8);
      wlan_hdd_cfg80211_acs_ch_select_evt(v6, 1);
    }
LABEL_129:
    updated = 0;
  }
  qdf_trace_msg(0x33u, 8u, "%s: exit", v154, v155, v156, v157, v158, v159, v160, v161, "hdd_update_acs_channel");
  v36 = qdf_status_to_os_return(updated);
  _qdf_mem_free(v55);
LABEL_49:
  LODWORD(v18) = v36;
LABEL_50:
  v53 = v18;
  _osif_vdev_sync_op_stop(v185, "wlan_hdd_cfg80211_update_vendor_channel");
  result = v53;
LABEL_51:
  _ReadStatusReg(SP_EL0);
  return result;
}
