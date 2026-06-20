__int64 __fastcall target_if_consume_spectral_report_gen3(
        __int64 a1,
        __int64 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int (*v12)(void); // x8
  __int64 v13; // x21
  __int64 v14; // x21
  unsigned __int64 v15; // x23
  __int64 v16; // x21
  __int64 v17; // x20
  __int64 v18; // x21
  __int64 v19; // x22
  __int64 v20; // x21
  __int64 v21; // x22
  _DWORD *v22; // x8
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x22
  __int64 v32; // x22
  _DWORD *v33; // x8
  __int64 v34; // x0
  __int64 result; // x0
  __int64 v36; // x22
  __int64 v37; // x27
  int v38; // w11
  int v39; // w8
  bool v40; // cf
  __int64 v41; // x21
  int v42; // w8
  unsigned int v43; // w28
  int v44; // w8
  int v45; // w8
  __int64 v46; // x24
  const char *v47; // x2
  __int64 v48; // x22
  __int64 v49; // x8
  const char *v50; // x2
  __int64 v51; // x22
  __int64 v52; // x8
  __int64 v53; // x8
  const char *v54; // x2
  __int64 v55; // x9
  __int64 v56; // x0
  int v57; // w11
  int v58; // w9
  int v59; // w10
  int v60; // w12
  int v61; // w13
  __int64 v62; // x11
  __int64 v63; // x22
  int v64; // w10
  int v65; // w12
  unsigned int v66; // w24
  _QWORD *v67; // x0
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7
  __int64 v76; // x23
  __int64 v77; // x0
  unsigned int *v78; // x8
  char v79; // w28
  unsigned __int8 v80; // w23
  unsigned int v81; // w1
  double v82; // d0
  double v83; // d1
  double v84; // d2
  double v85; // d3
  double v86; // d4
  double v87; // d5
  double v88; // d6
  double v89; // d7
  __int64 v90; // x22
  __int64 v91; // x9
  int bin_count_after_len_adj; // w24
  unsigned int v93; // w8
  _QWORD *vdev; // x0
  __int64 v95; // x23
  __int64 cmpt_obj; // x0
  unsigned int *v97; // x8
  char v98; // w27
  unsigned __int8 v99; // w8
  _DWORD *v100; // x9
  __int16 v101; // w0
  __int16 v102; // w9
  int v103; // w8
  int v104; // w11
  __int64 v105; // x1
  int v106; // w10
  unsigned int (__fastcall *v107)(__int64, __int64, __int64); // x8
  __int64 v108; // x22
  __int64 v109; // x9
  __int64 v110; // x11
  int v111; // w13
  __int64 v112; // x13
  __int64 v113; // x12
  __int64 v114; // x8
  int v115; // w11
  unsigned int (__fastcall *v116)(_QWORD); // x8
  __int64 v117; // x22
  double v118; // d0
  double v119; // d1
  double v120; // d2
  double v121; // d3
  double v122; // d4
  double v123; // d5
  double v124; // d6
  double v125; // d7
  __int64 v126; // [xsp+0h] [xbp-160h]
  __int16 v127; // [xsp+8h] [xbp-158h]
  unsigned int v128; // [xsp+8h] [xbp-158h]
  char v129[4]; // [xsp+14h] [xbp-14Ch] BYREF
  __int64 v130; // [xsp+18h] [xbp-148h] BYREF
  __int64 v131; // [xsp+20h] [xbp-140h] BYREF
  __int64 v132; // [xsp+28h] [xbp-138h] BYREF
  __int64 v133; // [xsp+30h] [xbp-130h]
  __int64 v134; // [xsp+38h] [xbp-128h]
  __int64 v135; // [xsp+40h] [xbp-120h]
  __int64 v136; // [xsp+48h] [xbp-118h]
  __int64 v137; // [xsp+50h] [xbp-110h]
  __int64 v138; // [xsp+58h] [xbp-108h]
  __int64 v139; // [xsp+60h] [xbp-100h]
  __int64 v140; // [xsp+68h] [xbp-F8h]
  __int64 v141; // [xsp+70h] [xbp-F0h] BYREF
  __int64 v142; // [xsp+78h] [xbp-E8h]
  __int64 v143; // [xsp+80h] [xbp-E0h]
  __int64 v144; // [xsp+88h] [xbp-D8h]
  __int64 v145; // [xsp+90h] [xbp-D0h]
  __int64 v146; // [xsp+98h] [xbp-C8h]
  __int64 v147; // [xsp+A0h] [xbp-C0h]
  __int64 v148; // [xsp+A8h] [xbp-B8h]
  __int64 v149; // [xsp+B0h] [xbp-B0h]
  __int64 v150; // [xsp+B8h] [xbp-A8h]
  __int64 v151; // [xsp+C0h] [xbp-A0h]
  __int64 v152; // [xsp+C8h] [xbp-98h]
  __int64 v153; // [xsp+D0h] [xbp-90h]
  __int64 v154; // [xsp+D8h] [xbp-88h]
  __int64 v155; // [xsp+E0h] [xbp-80h]
  __int64 v156; // [xsp+E8h] [xbp-78h]
  __int64 v157; // [xsp+F0h] [xbp-70h]
  __int64 v158; // [xsp+F8h] [xbp-68h]
  __int64 v159; // [xsp+100h] [xbp-60h]
  _BYTE v160[32]; // [xsp+108h] [xbp-58h] BYREF
  __int64 v161; // [xsp+128h] [xbp-38h]
  __int64 v162; // [xsp+130h] [xbp-30h]
  __int64 v163; // [xsp+138h] [xbp-28h]
  __int64 v164; // [xsp+140h] [xbp-20h]
  __int64 v165; // [xsp+148h] [xbp-18h]
  __int64 v166; // [xsp+150h] [xbp-10h]

  v166 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *(unsigned int (**)(void))(a1 + 168);
  v13 = *a2;
  v164 = 0;
  v165 = 0;
  v162 = 0;
  v163 = 0;
  v161 = 0;
  v159 = 0;
  memset(v160, 0, sizeof(v160));
  v157 = 0;
  v158 = 0;
  v155 = 0;
  v156 = 0;
  v153 = 0;
  v154 = 0;
  v151 = 0;
  v152 = 0;
  v149 = 0;
  v150 = 0;
  v147 = 0;
  v148 = 0;
  v146 = 0;
  v144 = 0;
  v145 = 0;
  v142 = 0;
  v143 = 0;
  v140 = 0;
  v141 = 0;
  v138 = 0;
  v139 = 0;
  v136 = 0;
  v137 = 0;
  v134 = 0;
  v135 = 0;
  v132 = 0;
  v133 = 0;
  v130 = 0;
  v131 = 0;
  v129[0] = 0;
  if ( v12 )
  {
    if ( *((_DWORD *)v12 - 1) != 264716637 )
      __break(0x8228u);
    if ( v12() )
    {
      v14 = jiffies;
      if ( target_if_consume_spectral_report_gen3___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x56u,
          2u,
          "%s: Byte-swap on Spectral headers failed",
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          "target_if_consume_spectral_report_gen3");
        target_if_consume_spectral_report_gen3___last_ticks = v14;
      }
      goto LABEL_18;
    }
  }
  if ( *(unsigned __int16 *)(v13 + 6) << 16 != -100532224 )
  {
    ++*(_QWORD *)(a1 + 1200);
    v18 = jiffies;
    if ( target_if_consume_spectral_report_gen3___last_ticks_61 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x56u,
        2u,
        "%s: Wrong tag/sig in sscan summary",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "target_if_consume_spectral_report_gen3");
      target_if_consume_spectral_report_gen3___last_ticks_61 = v18;
    }
    goto LABEL_18;
  }
  if ( !v13 )
  {
    qdf_trace_msg(
      0x56u,
      2u,
      "%s: Argument(data) is null.",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "target_if_get_detector_id_sscan_summary_report_gen3");
LABEL_18:
    LODWORD(v17) = 255;
    goto LABEL_19;
  }
  v15 = ((unsigned __int64)*(unsigned int *)(v13 + 8) >> 29) & 3;
  if ( (unsigned int)v15 >= *(unsigned __int8 *)(a1 + 1412) )
  {
    ++*(_QWORD *)(a1 + 1240);
    qdf_trace_msg(
      0x56u,
      2u,
      "%s: Invalid detector id %u, expected is 0/1/2",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "target_if_consume_spectral_report_gen3",
      (unsigned int)v15);
    goto LABEL_18;
  }
  if ( (_DWORD)v15 == 3 )
  {
    v16 = jiffies;
    if ( target_if_get_spectral_mode___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x56u,
        2u,
        "%s: Invalid detector id %d",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "target_if_get_spectral_mode",
        3);
      target_if_get_spectral_mode___last_ticks = v16;
    }
    LODWORD(v17) = 255;
    goto LABEL_26;
  }
  v17 = *(unsigned int *)(a1 + 4 * v15 + 1400);
  if ( (unsigned int)v17 >= 2 )
  {
LABEL_26:
    v21 = jiffies;
    if ( target_if_consume_spectral_report_gen3___last_ticks_64 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x56u,
        2u,
        "%s: No valid Spectral mode for detector id %u",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "target_if_consume_spectral_report_gen3",
        (unsigned int)v15);
      target_if_consume_spectral_report_gen3___last_ticks_64 = v21;
    }
    goto LABEL_19;
  }
  v22 = *(_DWORD **)(a1 + 40);
  if ( *(v22 - 1) != 362784388 )
    __break(0x8228u);
  if ( !((unsigned int (__fastcall *)(__int64, _QWORD))v22)(a1, (unsigned int)v17) )
  {
    v32 = jiffies;
    if ( target_if_consume_spectral_report_gen3___last_ticks_66 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x56u,
        4u,
        "%s: Spectral scan is not active",
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        "target_if_consume_spectral_report_gen3");
      target_if_consume_spectral_report_gen3___last_ticks_66 = v32;
    }
    goto LABEL_36;
  }
  if ( (unsigned int)target_if_spectral_is_finite_scan(a1, v17, v129, v23, v24, v25, v26, v27, v28, v29, v30) )
  {
    v31 = jiffies;
    if ( target_if_consume_spectral_report_gen3___last_ticks_68 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x56u,
        2u,
        "%s: Failed to check scan is finite",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "target_if_consume_spectral_report_gen3");
      target_if_consume_spectral_report_gen3___last_ticks_68 = v31;
    }
    goto LABEL_19;
  }
  if ( v129[0] == 1
    && (unsigned int)target_if_spectral_finite_scan_update((_QWORD *)a1, v17, a3, a4, a5, a6, a7, a8, a9, a10) )
  {
    v36 = jiffies;
    if ( target_if_consume_spectral_report_gen3___last_ticks_70 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x56u,
        2u,
        "%s: Failed to update scan count",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "target_if_consume_spectral_report_gen3");
      target_if_consume_spectral_report_gen3___last_ticks_70 = v36;
    }
    goto LABEL_19;
  }
  target_if_consume_sscan_summary_report_gen3(v13, &v130, a1 + 1392);
  v37 = a1 + 1184;
  v38 = *((_DWORD *)a2 + 12);
  v39 = *(_DWORD *)(a1 + 1184 + 4 * v17) - 3;
  v40 = *(_DWORD *)(a1 + 1184 + 4 * v17) != 3;
  v41 = v13 + *(unsigned __int8 *)(a1 + 1396) + 24;
  WORD1(v152) = *((_DWORD *)a2 + 11);
  WORD2(v152) = v38;
  if ( (v39 == 1 || !v40) && *(_BYTE *)(a1 + 1398 + v17) == 1 )
  {
    v42 = *(_DWORD *)(a1 + 4 * v17 + 1376);
    if ( v42 == 2 )
    {
      BYTE1(v161) = v130;
      BYTE1(v162) = BYTE5(v130);
      BYTE3(v161) = BYTE4(v130);
      v52 = *(int *)(v41 + 4);
      if ( (v52 & 0xFFFF0000) != 0xFA030000 )
      {
        ++*(_QWORD *)(a1 + 1200);
        v63 = jiffies;
        if ( target_if_consume_spectral_report_gen3___last_ticks_83 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x56u,
            2u,
            "%s: Unexpected tag/sig in sfft, detid= %u",
            a3,
            a4,
            a5,
            a6,
            a7,
            a8,
            a9,
            a10,
            "target_if_consume_spectral_report_gen3",
            (unsigned int)v15);
          target_if_consume_spectral_report_gen3___last_ticks_83 = v63;
        }
        goto LABEL_19;
      }
      v53 = 4 * v52;
      v128 = WORD1(v130);
      v46 = v53 & 0x3FFFC;
      v126 = v53;
      if ( ((unsigned int)v53 & 0x3FFFC) <= 0xF )
      {
        v47 = "%s: Wrong TLV length %u, detector id = %u";
        goto LABEL_54;
      }
      target_if_process_sfft_report_gen3(v41, &v132, a1 + 1392);
      if ( HIDWORD(v133) != (_DWORD)v15 )
      {
        v90 = jiffies;
        if ( target_if_consume_spectral_report_gen3___last_ticks_85 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x56u,
            2u,
            "%s: Different detid in ssummary(%u) and sfft(%u)",
            a3,
            a4,
            a5,
            a6,
            a7,
            a8,
            a9,
            a10,
            "target_if_consume_spectral_report_gen3",
            (unsigned int)v15);
          target_if_consume_spectral_report_gen3___last_ticks_85 = v90;
        }
        goto LABEL_19;
      }
      if ( (unsigned int)v15 > *(unsigned __int8 *)(a1 + 1412) )
      {
        v49 = *(_QWORD *)(a1 + 1240);
        v50 = "%s: Invalid detector id %u, expected is 1";
        goto LABEL_60;
      }
      v91 = *(unsigned __int8 *)(a1 + 1397);
      HIDWORD(v161) = v17;
      bin_count_after_len_adj = target_if_spectral_get_bin_count_after_len_adj(
                                  v46 - v91,
                                  *(unsigned __int8 *)(a1 + 80LL * (unsigned int)v17 + 676),
                                  a1 + 1344,
                                  &v131);
      v93 = *(_DWORD *)(v37 + 4 * v17) - 3;
      LODWORD(v164) = v132;
      if ( v93 > 1
        || *(_BYTE *)(a1 + 1398 + v17) != 1
        || !(unsigned int)target_if_160mhz_delivery_state_change(
                            (_QWORD *)a1,
                            v17,
                            v15,
                            a3,
                            a4,
                            a5,
                            a6,
                            a7,
                            a8,
                            a9,
                            a10) )
      {
        BYTE1(v141) = v128 >> 1;
        vdev = target_if_spectral_get_vdev((__int64 *)a1, v17, a3, a4, a5, a6, a7, a8, a9, a10);
        if ( vdev )
        {
          v95 = (__int64)vdev;
          cmpt_obj = wlan_vdev_mlme_get_cmpt_obj((__int64)vdev, v68, v69, v70, v71, v72, v73, v74, v75);
          if ( cmpt_obj )
          {
            v98 = *(_BYTE *)(cmpt_obj + 417);
            if ( v98 )
            {
              wlan_objmgr_vdev_release_ref(v95, 0x1Bu, v97, a3, a4, a5, a6, a7, a8, a9, a10);
              if ( (v98 & 1) != 0 )
              {
                v99 = 0;
              }
              else if ( (v98 & 2) != 0 )
              {
                v99 = 1;
              }
              else if ( (v98 & 4) != 0 )
              {
                v99 = 2;
              }
              else if ( (v98 & 8) != 0 )
              {
                v99 = 3;
              }
              else if ( (v98 & 0x10) != 0 )
              {
                v99 = 4;
              }
              else if ( (v98 & 0x20) != 0 )
              {
                v99 = 5;
              }
              else
              {
                v99 = 6;
                if ( (v98 & 0x40) == 0 )
                  v99 = 7;
              }
              LODWORD(v147) = bin_count_after_len_adj;
              v115 = *((_DWORD *)a2 + v99 + 2);
              v116 = *(unsigned int (__fastcall **)(_QWORD))(a1 + 176);
              WORD1(v144) = WORD2(v137);
              HIWORD(v142) = 4 * v126;
              HIWORD(v153) = v115;
              v151 = v41 + 24;
              if ( v116 )
              {
                if ( *((_DWORD *)v116 - 1) != 2084076869 )
                  __break(0x8228u);
                if ( v116(a1 + 1392) )
                {
                  v117 = jiffies;
                  if ( target_if_consume_spectral_report_gen3___last_ticks_88 - jiffies + 125 < 0 )
                  {
                    qdf_trace_msg(
                      0x56u,
                      2u,
                      "%s: Byte-swap on the FFT bins failed",
                      a3,
                      a4,
                      a5,
                      a6,
                      a7,
                      a8,
                      a9,
                      a10,
                      "target_if_consume_spectral_report_gen3");
                    target_if_consume_spectral_report_gen3___last_ticks_88 = v117;
                  }
                  goto LABEL_19;
                }
              }
              goto LABEL_149;
            }
          }
          goto LABEL_111;
        }
        v81 = 4;
LABEL_92:
        qdf_trace_msg(
          0x56u,
          v81,
          "%s: First vdev is NULL",
          v68,
          v69,
          v70,
          v71,
          v72,
          v73,
          v74,
          v75,
          "target_if_consume_spectral_report_gen3",
          v126);
        reset_160mhz_delivery_state_machine((_QWORD *)a1, v17, v82, v83, v84, v85, v86, v87, v88, v89);
        goto LABEL_41;
      }
LABEL_19:
      v19 = jiffies;
      if ( target_if_consume_spectral_report_gen3___last_ticks_90 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x56u,
          2u,
          "%s: Error while processing Spectral report",
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          "target_if_consume_spectral_report_gen3");
        target_if_consume_spectral_report_gen3___last_ticks_90 = v19;
      }
LABEL_21:
      if ( (_DWORD)v17 != 255 )
      {
        if ( (unsigned int)v17 >= 2 )
        {
          v20 = jiffies;
          if ( reset_160mhz_delivery_state_machine___last_ticks - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x56u,
              2u,
              "%s: Invalid Spectral mode %d",
              a3,
              a4,
              a5,
              a6,
              a7,
              a8,
              a9,
              a10,
              "reset_160mhz_delivery_state_machine",
              (unsigned int)v17);
            reset_160mhz_delivery_state_machine___last_ticks = v20;
          }
          goto LABEL_41;
        }
LABEL_36:
        if ( (unsigned int)(*(_DWORD *)(a1 + 1184 + 4LL * (unsigned int)v17) - 3) <= 1 )
        {
          v33 = *(_DWORD **)(a1 + 1288);
          v34 = *(_QWORD *)a1;
          if ( *(v33 - 1) != 1779743641 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64, _QWORD))v33)(v34, (unsigned int)v17);
          if ( (unsigned int)(*(_DWORD *)(a1 + 1184 + 4LL * (unsigned int)v17) - 3) <= 1 )
            *(_DWORD *)(a1 + 4LL * (unsigned int)v17 + 1376) = 0;
        }
      }
LABEL_41:
      result = 0xFFFFFFFFLL;
      goto LABEL_42;
    }
    if ( v42 )
    {
      v54 = "%s: Spectral state machine in undefined state";
LABEL_67:
      qdf_trace_msg(0x56u, 2u, v54, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_consume_spectral_report_gen3", v126);
      goto LABEL_19;
    }
  }
  v43 = WORD1(v130);
  LOBYTE(v161) = v130;
  LOBYTE(v162) = BYTE5(v130);
  BYTE2(v161) = BYTE4(v130);
  v44 = *(_DWORD *)(v41 + 4);
  if ( (v44 & 0xFFFF0000) != 0xFA030000 )
  {
    ++*(_QWORD *)(a1 + 1200);
    v48 = jiffies;
    if ( target_if_consume_spectral_report_gen3___last_ticks_72 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x56u,
        2u,
        "%s: Unexpected tag/sig in sfft, detid= %u",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "target_if_consume_spectral_report_gen3",
        (unsigned int)v15);
      target_if_consume_spectral_report_gen3___last_ticks_72 = v48;
    }
    goto LABEL_19;
  }
  v45 = 4 * v44;
  v46 = *(_QWORD *)&v45 & 0x3FFFCLL;
  if ( (v45 & 0x3FFFCu) <= 0xF )
  {
    v47 = "%s: Wrong TLV length %u, detector id = %d";
LABEL_54:
    qdf_trace_msg(
      0x56u,
      2u,
      v47,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "target_if_consume_spectral_report_gen3",
      (unsigned int)v46,
      (unsigned int)v15,
      v126);
    goto LABEL_19;
  }
  v127 = v45;
  target_if_process_sfft_report_gen3(v41, &v132, a1 + 1392);
  if ( HIDWORD(v133) != (_DWORD)v15 )
  {
    v51 = jiffies;
    if ( target_if_consume_spectral_report_gen3___last_ticks_75 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x56u,
        2u,
        "%s: Different detid in ssummary(%u) and sfft(%u)",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "target_if_consume_spectral_report_gen3",
        (unsigned int)v15);
      target_if_consume_spectral_report_gen3___last_ticks_75 = v51;
    }
    goto LABEL_19;
  }
  if ( (unsigned int)v15 > *(unsigned __int8 *)(a1 + 1412) )
  {
    v49 = *(_QWORD *)(a1 + 1240);
    v50 = "%s: Invalid detector id %u, expected is 0/2";
LABEL_60:
    *(_QWORD *)(a1 + 1240) = v49 + 1;
    qdf_trace_msg(
      0x56u,
      2u,
      v50,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "target_if_consume_spectral_report_gen3",
      (unsigned int)v15,
      v126);
    goto LABEL_19;
  }
  v55 = *(unsigned __int8 *)(a1 + 1397);
  HIDWORD(v161) = v17;
  v56 = target_if_spectral_get_bin_count_after_len_adj(
          v46 - v55,
          *(unsigned __int8 *)(a1 + 80LL * (unsigned int)v17 + 676),
          a1 + 1344,
          &v131);
  v57 = *((_DWORD *)a2 + 10);
  v58 = v132;
  v59 = *(_DWORD *)(a1 + 1368 + 4 * v17);
  HIDWORD(v164) = v57;
  HIDWORD(v162) = v59;
  HIDWORD(v163) = v132;
  if ( v57 )
  {
    v60 = *(_DWORD *)(a1 + 1368) + v57 + *(_DWORD *)(a1 + 1352);
    v61 = *(_DWORD *)(a1 + 1372) + v57 + *(_DWORD *)(a1 + 1356);
    v62 = *(_QWORD *)(a1 + 1360) + 1LL;
    *(_DWORD *)(a1 + 1352) = v60;
    *(_DWORD *)(a1 + 1356) = v61;
    *(_QWORD *)(a1 + 1360) = v62;
  }
  else
  {
    v62 = *(_QWORD *)(a1 + 1360);
  }
  v64 = *(_DWORD *)(a1 + 1352 + 4 * v17);
  v65 = *(_DWORD *)(v37 + 4 * v17);
  *(_DWORD *)(a1 + 1368 + 4 * v17) = v58;
  v126 = v56;
  LODWORD(v163) = v64;
  LODWORD(v143) = v64 + v58;
  LODWORD(v165) = v62;
  if ( (unsigned int)(v65 - 3) <= 1
    && *(_BYTE *)(a1 + v17 + 1398) == 1
    && (unsigned int)target_if_160mhz_delivery_state_change((_QWORD *)a1, v17, v15, a3, a4, a5, a6, a7, a8, a9, a10) )
  {
    goto LABEL_19;
  }
  v66 = v43 >> 1;
  LOBYTE(v141) = v43 >> 1;
  v67 = target_if_spectral_get_vdev((__int64 *)a1, v17, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !v67 )
  {
    v81 = 8;
    goto LABEL_92;
  }
  v76 = (__int64)v67;
  v77 = wlan_vdev_mlme_get_cmpt_obj((__int64)v67, v68, v69, v70, v71, v72, v73, v74, v75);
  if ( !v77 || (v79 = *(_BYTE *)(v77 + 417)) == 0 )
  {
LABEL_111:
    v54 = "%s: Vdev rxchainmask is zero.";
    goto LABEL_67;
  }
  wlan_objmgr_vdev_release_ref(v76, 0x1Bu, v78, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( (v79 & 1) != 0 )
  {
    v80 = 0;
  }
  else if ( (v79 & 2) != 0 )
  {
    v80 = 1;
  }
  else if ( (v79 & 4) != 0 )
  {
    v80 = 2;
  }
  else if ( (v79 & 8) != 0 )
  {
    v80 = 3;
  }
  else if ( (v79 & 0x10) != 0 )
  {
    v80 = 4;
  }
  else if ( (v79 & 0x20) != 0 )
  {
    v80 = 5;
  }
  else if ( (v79 & 0x40) != 0 )
  {
    v80 = 6;
  }
  else
  {
    v80 = 7;
  }
  v100 = *(_DWORD **)(a1 + 128);
  LOWORD(v144) = WORD2(v137);
  if ( *(v100 - 1) != 362784388 )
    __break(0x8229u);
  v101 = ((__int64 (__fastcall *)(__int64, _QWORD))v100)(a1, (unsigned int)v17);
  v102 = *(_DWORD *)(a1 + 780);
  v103 = *(_DWORD *)(v37 + 4 * v17);
  v104 = *(_DWORD *)(a1 + 784);
  v105 = v41 + 24;
  LOWORD(v152) = v101;
  HIWORD(v152) = v102;
  v106 = *((_DWORD *)a2 + v80 + 2);
  LOWORD(v153) = v104;
  WORD2(v153) = v106;
  if ( (unsigned int)(v103 - 3) > 1 || (*(_BYTE *)(a1 + v17 + 1398) & 1) != 0 )
  {
    v149 = v41 + 24;
    LODWORD(v146) = v126;
    WORD2(v142) = 4 * v127;
    goto LABEL_125;
  }
  if ( !*(_QWORD *)a1 )
  {
    v54 = "%s: pdev is null";
    goto LABEL_67;
  }
  v109 = *(_QWORD *)(*(_QWORD *)a1 + 80LL);
  if ( !v109 )
  {
    v54 = "%s: psoc is null";
    goto LABEL_67;
  }
  HIWORD(v153) = v106;
  BYTE1(v161) = v130;
  v110 = a1 + 14LL * (unsigned int)v17;
  BYTE3(v161) = BYTE4(v130);
  LODWORD(v164) = v132;
  v111 = *(unsigned __int8 *)(v110 + 1414);
  BYTE1(v141) = v66;
  WORD1(v144) = WORD2(v137);
  WORD2(v142) = 2 * v127;
  HIWORD(v142) = 2 * v127;
  if ( v111 != 1 )
    goto LABEL_21;
  v112 = *(unsigned __int16 *)(v110 + 1424);
  v113 = v105 + v131 * *(unsigned __int16 *)(v110 + 1416);
  LODWORD(v146) = *(unsigned __int16 *)(v110 + 1418);
  v149 = v113;
  LODWORD(v113) = *(unsigned __int16 *)(v110 + 1426);
  v151 = v105 + v131 * v112;
  LODWORD(v147) = v113;
  if ( v103 == 4 && (*(_BYTE *)(v109 + 22) & 0x10) != 0 )
  {
    v114 = v105 + v131 * *(unsigned __int16 *)(v110 + 1420);
    HIDWORD(v146) = *(unsigned __int16 *)(v110 + 1422);
    v150 = v114;
  }
LABEL_125:
  v107 = *(unsigned int (__fastcall **)(__int64, __int64, __int64))(a1 + 176);
  if ( v107 )
  {
    if ( *((_DWORD *)v107 - 1) != 2084076869 )
      __break(0x8228u);
    if ( v107(a1 + 1392, v105, v126) )
    {
      v108 = jiffies;
      if ( target_if_consume_spectral_report_gen3___last_ticks_81 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x56u,
          2u,
          "%s: Byte-swap on the FFT bins failed",
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          "target_if_consume_spectral_report_gen3");
        target_if_consume_spectral_report_gen3___last_ticks_81 = v108;
      }
      goto LABEL_19;
    }
  }
LABEL_149:
  if ( (spectral_debug_level & 0x1400) != 0 )
    target_if_dump_fft_report_gen3(a1, (unsigned int)v17, v41, &v132);
  qdf_mem_copy(&v160[4], (const void *)(a1 + 802), 0x14u);
  target_if_spectral_create_samp_msg((char *)a1, (char *)&v141, v118, v119, v120, v121, v122, v123, v124, v125);
  result = 0;
LABEL_42:
  _ReadStatusReg(SP_EL0);
  return result;
}
