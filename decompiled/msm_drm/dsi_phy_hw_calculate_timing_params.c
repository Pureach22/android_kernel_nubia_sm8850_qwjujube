__int64 __fastcall dsi_phy_hw_calculate_timing_params(__int64 a1, __int64 a2, unsigned int *a3, __int64 a4, char a5)
{
  __int64 v10; // x25
  unsigned int v11; // w21
  __int64 v12; // x8
  _DWORD *v13; // x9
  __int64 v14; // x8
  __int64 v15; // x8
  unsigned __int64 v16; // x8
  unsigned int v17; // w9
  unsigned int v18; // w10
  int v19; // w8
  _DWORD *v20; // x8
  int v21; // w4
  int v22; // w8
  unsigned int v23; // w10
  unsigned int v24; // w4
  unsigned int v25; // w5
  unsigned __int64 v26; // x8
  int v27; // w6
  unsigned int v28; // w10
  unsigned int v29; // w9
  unsigned int v30; // w11
  unsigned int v31; // w4
  unsigned int v32; // w5
  unsigned __int64 v33; // x8
  int v34; // w6
  unsigned int v35; // w4
  unsigned int v36; // w5
  unsigned __int64 v37; // x8
  int v38; // w6
  unsigned int v39; // w4
  unsigned __int64 v40; // x8
  int v41; // w6
  double v42; // d0
  unsigned int v43; // w0
  unsigned int v44; // w22
  unsigned int v45; // w7
  unsigned int v46; // w8
  unsigned int v47; // w4
  signed __int64 v48; // x10
  signed __int64 v49; // x11
  signed __int64 v50; // x9
  char v51; // cc
  __int64 v52; // x24
  __int64 v53; // x9
  __int64 v54; // x22
  int v55; // w23
  double v56; // d0
  const char *v57; // x2
  __int64 v58; // x3
  long double v59; // q0
  __int64 v60; // x10
  unsigned __int64 v61; // x9
  __int64 (__fastcall *v62)(__int64, __int64, long double); // x9
  __int64 v63; // x0
  int v64; // w0
  int v65; // w9
  unsigned int v66; // kr08_4
  int v67; // w8
  const char *v68; // x2
  int v69; // w3
  long double v70; // q0
  __int64 v71; // x24
  __int64 v72; // x10
  __int64 v73; // x11
  __int64 v74; // x10
  __int64 v75; // x11
  __int64 v76; // x10
  __int64 v77; // x22
  __int64 v78; // x23
  unsigned __int64 v79; // x10
  __int64 (__fastcall *v80)(__int64, __int64, __int64, long double); // x10
  __int64 v81; // x0
  __int64 v82; // x1
  __int64 (__fastcall *v83)(__int64, __int64); // x8
  __int64 v84; // x0
  int v85; // w0
  unsigned int v86; // kr0C_4
  int v87; // w9
  __int64 v88; // x12
  __int64 v89; // x13
  __int64 v90; // x15
  __int64 v91; // x12
  __int64 v92; // x15
  unsigned __int64 v93; // x12
  __int64 v94; // x16
  __int64 v95; // x15
  __int64 v96; // x16
  __int64 v97; // x10
  unsigned __int64 v98; // x11
  unsigned __int64 v99; // x13
  __int64 v100; // x14
  __int64 v101; // x15
  unsigned __int64 v102; // x10
  unsigned __int64 v103; // x11
  unsigned __int64 v104; // x14
  unsigned __int64 v105; // x10
  unsigned __int64 v106; // x7
  unsigned __int64 v107; // x11
  unsigned __int64 v108; // x4
  __int64 v109; // x22
  int v110; // w8
  double v111; // d0
  unsigned int v112; // w0
  __int64 v113; // x3
  unsigned int v114; // w0
  __int64 v115; // x3
  unsigned int v116; // w0
  __int64 v117; // x3
  unsigned int v118; // w0
  __int64 v119; // x3
  unsigned int v120; // w0
  __int64 v121; // x3
  unsigned int v122; // w0
  __int64 v123; // x3
  unsigned int v124; // w0
  __int64 v125; // x3
  _DWORD *v126; // x8
  _QWORD v128[3]; // [xsp+18h] [xbp-198h] BYREF
  __int64 v129; // [xsp+30h] [xbp-180h]
  __int64 v130; // [xsp+38h] [xbp-178h]
  __int64 v131; // [xsp+40h] [xbp-170h]
  __int64 v132; // [xsp+48h] [xbp-168h]
  int v133; // [xsp+50h] [xbp-160h]
  _QWORD s[43]; // [xsp+58h] [xbp-158h] BYREF

  s[42] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a1 + 392);
  v11 = a3[13];
  v133 = 0;
  v131 = 0;
  v132 = 0;
  v129 = 0;
  v130 = 0;
  memset(v128, 0, sizeof(v128));
  memset(s, 0, 0x150u);
  if ( *(_BYTE *)(a2 + 72) == 1 && (v12 = *(_QWORD *)(a2 + 80)) != 0 )
  {
    v13 = (_DWORD *)(v12 + 160);
  }
  else
  {
    v13 = (_DWORD *)a2;
    if ( *(_BYTE *)(a2 + 73) == 1 )
    {
      v14 = *(_QWORD *)(a2 + 88);
      v13 = (_DWORD *)(v14 + 500);
      if ( !v14 )
        v13 = (_DWORD *)a2;
    }
  }
  v15 = *a3;
  if ( (unsigned int)v15 >= 8 )
    __break(0x5512u);
  if ( (a5 & 1) != 0 )
  {
    v16 = *(_QWORD *)(a2 + 48);
  }
  else
  {
    v17 = (*(_DWORD *)(a2 + 28) + *(_DWORD *)(a2 + 24) + *(_DWORD *)(a2 + 32) + *(_DWORD *)(a2 + 36))
        * (*(_DWORD *)(a2 + 4) + *v13 + *(_DWORD *)(a2 + 12) + *(_DWORD *)(a2 + 8));
    v18 = ((a3[1] >> 1) & 1) + (a3[1] & 1) + ((a3[1] >> 2) & 1) + ((a3[1] >> 3) & 1);
    v19 = *(_DWORD *)(a2 + 44) * bits_per_pixel[v15];
    v16 = v17 % v18 * v19 / v18 + v17 / v18 * v19;
    if ( v11 == 1 )
      v16 = 7 * (v16 >> 4) + ((7 * (v16 & 0xF)) >> 4);
  }
  *(_QWORD *)((char *)&v128[1] + 4) = 0x14000003E8LL;
  LODWORD(s[24]) = 100;
  LODWORD(s[6]) = 60;
  *(_QWORD *)((char *)v128 + 4) = 0xA000000C0LL;
  s[0] = 0x5F00000026LL;
  HIDWORD(s[25]) = 255;
  HIDWORD(s[19]) = 255;
  LODWORD(v128[0]) = (v16 + 999999) / 0xF4240;
  LODWORD(s[18]) = 50;
  LODWORD(s[21]) = 50;
  v20 = *(_DWORD **)v10;
  if ( !*(_QWORD *)v10 )
    goto LABEL_143;
  if ( *(v20 - 1) != 2030470624 )
    __break(0x8228u);
  ((void (__fastcall *)(_QWORD *, _QWORD))v20)(v128, v11);
  if ( a1 )
    v21 = *(_DWORD *)(a1 + 28);
  else
    v21 = -1;
  _drm_dev_dbg(
    0,
    0,
    0,
    "[msm-dsi-debug]: DSI_%d: BIT CLOCK = %d, tlpx_numer_ns=%d, treot_ns=%d\n",
    v21,
    LODWORD(v128[0]),
    HIDWORD(v128[1]),
    LODWORD(v128[2]));
  v22 = LODWORD(v128[0]) * LODWORD(s[0]) - 1;
  v23 = 8 * HIDWORD(v128[1]);
  if ( v11 != 1 )
  {
    v45 = (v22 + v23) / v23;
    v46 = HIDWORD(s[0]) * LODWORD(v128[0]) / v23;
    s[1] = __PAIR64__(v46, v45);
    v47 = v45
        + ((unsigned __int64)(((((unsigned __int64)(HIDWORD(v128[2]) * (v46 - v45)) << 20)
                              * (unsigned __int128)0x28F5C28F5C28F5DuLL) >> 64)
                            + 0xFFFFF) >> 20);
    LODWORD(s[2]) = v47;
    if ( v47 <= 0xFF )
    {
      BYTE4(s[2]) = v45
                  + ((unsigned __int64)(((((unsigned __int64)(HIDWORD(v128[2]) * (v46 - v45)) << 20)
                                        * (unsigned __int128)0x28F5C28F5C28F5DuLL) >> 64)
                                      + 0xFFFFF) >> 20);
      v48 = (unsigned __int64)(v23 * v47) << 20;
      v49 = v48 / SLODWORD(v128[0]);
      v50 = v48 % SLODWORD(v128[0]);
      v52 = v50 + v49;
      v51 = (v50 + v49 < 0) ^ __OFADD__(v50, v49);
      v53 = v50 + v49 + 0xFFFFF;
      if ( !v51 )
        v53 = v52;
      v54 = v53 >> 20;
      if ( a1 )
      {
        _drm_dev_dbg(
          0,
          0,
          0,
          "[msm-dsi-debug]: DSI_%d: CLK_PREPARE:mipi_min=%d, mipi_max=%d, rec_min=%d, rec_max=%d\n",
          *(_DWORD *)(a1 + 28),
          LODWORD(s[0]),
          HIDWORD(s[0]),
          v45,
          v46);
        v55 = *(_DWORD *)(a1 + 28);
      }
      else
      {
        v55 = -1;
        _drm_dev_dbg(
          0,
          0,
          0,
          "[msm-dsi-debug]: DSI_%d: CLK_PREPARE:mipi_min=%d, mipi_max=%d, rec_min=%d, rec_max=%d\n",
          -1,
          LODWORD(s[0]),
          HIDWORD(s[0]),
          v45,
          v46);
      }
      *(double *)&v59 = _drm_dev_dbg(
                          0,
                          0,
                          0,
                          "[msm-dsi-debug]: DSI_%d:  reg_value=%d, actual=%lld\n",
                          v55,
                          BYTE4(s[2]),
                          v54);
      v60 = *(_QWORD *)(a1 + 392);
      v61 = 315621375 - v52;
      if ( v52 <= 314572800 )
        v61 = 314572800 - v52;
      LODWORD(s[3]) = v61 >> 20;
      v62 = *(__int64 (__fastcall **)(__int64, __int64, long double))(v60 + 8);
      if ( v62 )
      {
        v63 = (314572800 - v52) * LODWORD(v128[0]) / SHIDWORD(v128[1]);
        if ( *((_DWORD *)v62 - 1) != 63768381 )
          __break(0x8229u);
        v64 = v62(v63, 0x100000, v59);
        if ( v64 <= 255 )
          v65 = 255;
        else
          v65 = 511;
        s[4] = __PAIR64__(v65, v64);
        v66 = (v65 - v64) * v129 + 100 * v64 + 99;
        LODWORD(s[5]) = v66 / 0x64;
        if ( v66 >> 10 < 0x19 )
        {
          BYTE4(s[5]) = v66 / 0x64;
          if ( a1 )
            v67 = *(_DWORD *)(a1 + 28);
          else
            v67 = -1;
          *(double *)&v70 = _drm_dev_dbg(
                              0,
                              0,
                              0,
                              "[msm-dsi-debug]: DSI_%d: CLK_ZERO:mipi_min=%d, mipi_max=%d, rec_min=%d, rec_max=%d, reg_val=%d\n",
                              v67,
                              LODWORD(s[3]),
                              HIDWORD(s[3]),
                              v64,
                              v65,
                              (unsigned __int8)(v66 / 0x64));
          v71 = *(_QWORD *)(a1 + 392);
          v72 = 12582912LL * HIDWORD(v128[1]) / SLODWORD(v128[0]);
          if ( v72 <= 0 )
            v73 = -(-v72 & 0xFFFFF);
          else
            v73 = v72 & 0xFFFFF;
          v74 = v72 + v73;
          v75 = v74 + 110100480;
          v76 = v74 + 111149055;
          v77 = v75 - ((unsigned __int64)LODWORD(v128[2]) << 20);
          if ( v75 >= 0 )
            v78 = v75;
          else
            v78 = v76;
          v79 = v77 + 0xFFFFF;
          if ( v77 >= 0 )
            v79 = v75 - ((unsigned __int64)LODWORD(v128[2]) << 20);
          HIDWORD(s[6]) = v79 >> 20;
          v80 = *(__int64 (__fastcall **)(__int64, __int64, __int64, long double))(v71 + 16);
          if ( v80 )
          {
            v81 = ((LODWORD(v128[0]) * (__int64)SLODWORD(s[6])) << 20) / SHIDWORD(v128[1]);
            if ( v81 <= 0 )
              v82 = -(-v81 & 0xFFFFF);
            else
              v82 = v81 & 0xFFFFF;
            if ( *((_DWORD *)v80 - 1) != -767011687 )
              __break(0x822Au);
            LODWORD(s[7]) = v80(v81, v82, 0x100000, v70);
            v83 = *(__int64 (__fastcall **)(__int64, __int64))(v71 + 24);
            if ( v83 )
            {
              v84 = v77 * LODWORD(v128[0]) / SHIDWORD(v128[1]);
              if ( *((_DWORD *)v83 - 1) != 63768381 )
                __break(0x8228u);
              v85 = v83(v84, 0x100000);
              v86 = (v85 - LODWORD(s[7])) * HIDWORD(v129) + 100 * LODWORD(s[7]) + 99;
              HIDWORD(s[7]) = v85;
              LODWORD(s[8]) = v86 / 0x64;
              if ( v86 >> 10 < 0x19 )
              {
                BYTE4(s[8]) = v86 / 0x64;
                if ( a1 )
                  v87 = *(_DWORD *)(a1 + 28);
                else
                  v87 = -1;
                _drm_dev_dbg(
                  0,
                  0,
                  0,
                  "[msm-dsi-debug]: DSI_%d: CLK_TRAIL:mipi_min=%d, mipi_max=%d, rec_min=%d, rec_max=%d, reg_val=%d\n",
                  v87,
                  LODWORD(s[6]),
                  HIDWORD(s[6]),
                  LODWORD(s[7]),
                  v85,
                  (unsigned __int8)(v86 / 0x64));
                v88 = (__int64)((unsigned __int64)HIDWORD(v128[1]) << 22) / SLODWORD(v128[0]);
                v89 = 6291456LL * HIDWORD(v128[1]) / SLODWORD(v128[0]);
                if ( v88 <= 0 )
                  v90 = -(-v88 & 0xFFFFF);
                else
                  v90 = v88 & 0xFFFFF;
                v91 = v88 + v90;
                v92 = v91 + 41943040;
                v93 = v91 + 42991615;
                v94 = v92 * LODWORD(v128[0]);
                if ( v92 >= 0 )
                  v93 = v92;
                v95 = v89 + 89128960;
                v51 = v89 < -89128960;
                v96 = v94 / SHIDWORD(v128[1]);
                v97 = (v89 + 89128960) * LODWORD(v128[0]) / SHIDWORD(v128[1]);
                v98 = (unsigned __int64)(LODWORD(v128[0]) < 0x79uLL) << 21;
                v99 = v89 + 90177535;
                v100 = v96 - v98;
                if ( !v51 )
                  v99 = v95;
                if ( v100 <= 0 )
                  v101 = -(__int64)((v98 - v96) & 0xFFFFF);
                else
                  v101 = v100 & 0xFFFFF;
                s[9] = __PAIR64__(v99 >> 20, v93 >> 20);
                v102 = v97 - v98;
                v103 = ((unsigned __int64)(v101 + v100) >> 3) + 0xFFFFF;
                v104 = v102 >> 3;
                v105 = v102 >> 23;
                v106 = v103 >> 20;
                LODWORD(s[10]) = v103 >> 20;
                HIDWORD(s[10]) = v105;
                v107 = ((((v104 & 0x1FFFFFFFFFF00000LL) - (v103 & 0x3FFFFFFFFFF00000LL)) * (unsigned int)v130 / 0x64
                       + 0xFFFFF)
                      & 0x7FFFFFFFFF00000LL)
                     + (v103 & 0x3FFFFFFFFFF00000LL);
                v108 = v107 >> 20;
                LODWORD(s[11]) = v107 >> 20;
                if ( LODWORD(s[11]) <= 0xFF )
                {
                  BYTE4(s[11]) = v107 >> 20;
                  v109 = (__int64)(8 * HIDWORD(v128[1]) * v107) / SLODWORD(v128[0]);
                  if ( a1 )
                    v110 = *(_DWORD *)(a1 + 28);
                  else
                    v110 = -1;
                  v111 = _drm_dev_dbg(
                           0,
                           0,
                           0,
                           "[msm-dsi-debug]: DSI_%d: HS_PREP:mipi_min=%d, mipi_max=%d, rec_min=%d, rec_max=%d, reg_val=%d\n",
                           v110,
                           v93 >> 20,
                           v99 >> 20,
                           v106,
                           v105,
                           v108);
                  v112 = calc_hs_zero(a1, v128, s, v109, v111);
                  if ( v112 )
                  {
                    v44 = v112;
                    if ( a1 )
                      v113 = *(unsigned int *)(a1 + 28);
                    else
                      v113 = 0xFFFFFFFFLL;
                    drm_dev_printk(
                      0,
                      &unk_248D72,
                      "*ERROR* [msm-dsi-error]: DSI_%d: hs_zero calculations failed, rc=%d\n",
                      v113,
                      v112);
                  }
                  else
                  {
                    v114 = calc_hs_trail(a1, v128, s, v78 >> 20);
                    if ( v114 )
                    {
                      v44 = v114;
                      if ( a1 )
                        v115 = *(unsigned int *)(a1 + 28);
                      else
                        v115 = 0xFFFFFFFFLL;
                      drm_dev_printk(
                        0,
                        &unk_248D72,
                        "*ERROR* [msm-dsi-error]: DSI_%d: hs_trail calculations failed, rc=%d\n",
                        v115,
                        v114);
                    }
                    else
                    {
                      v116 = calc_hs_rqst(a1, v128, s);
                      if ( v116 )
                      {
                        v44 = v116;
                        if ( a1 )
                          v117 = *(unsigned int *)(a1 + 28);
                        else
                          v117 = 0xFFFFFFFFLL;
                        drm_dev_printk(
                          0,
                          &unk_248D72,
                          "*ERROR* [msm-dsi-error]: DSI_%d: hs_rqst calculations failed, rc=%d\n",
                          v117,
                          v116);
                      }
                      else
                      {
                        v118 = calc_hs_exit(a1, v128, s);
                        if ( v118 )
                        {
                          v44 = v118;
                          if ( a1 )
                            v119 = *(unsigned int *)(a1 + 28);
                          else
                            v119 = 0xFFFFFFFFLL;
                          drm_dev_printk(
                            0,
                            &unk_248D72,
                            "*ERROR* [msm-dsi-error]: DSI_%d: hs_exit calculations failed, rc=%d\n",
                            v119,
                            v118);
                        }
                        else
                        {
                          v120 = calc_hs_rqst_clk(a1, v128, s);
                          if ( v120 )
                          {
                            v44 = v120;
                            if ( a1 )
                              v121 = *(unsigned int *)(a1 + 28);
                            else
                              v121 = 0xFFFFFFFFLL;
                            drm_dev_printk(
                              0,
                              &unk_248D72,
                              "*ERROR* [msm-dsi-error]: DSI_%d: hs_rqst_clk calculations failed, rc=%d\n",
                              v121,
                              v120);
                          }
                          else
                          {
                            v122 = calc_clk_post(a1, v128, s);
                            if ( v122 )
                            {
                              v44 = v122;
                              if ( a1 )
                                v123 = *(unsigned int *)(a1 + 28);
                              else
                                v123 = 0xFFFFFFFFLL;
                              drm_dev_printk(
                                0,
                                &unk_248D72,
                                "*ERROR* [msm-dsi-error]: DSI_%d: clk_post calculations failed, rc=%d\n",
                                v123,
                                v122);
                            }
                            else
                            {
                              v124 = calc_clk_pre(a1, v128, s);
                              if ( !v124 )
                                goto LABEL_139;
                              v44 = v124;
                              if ( a1 )
                                v125 = *(unsigned int *)(a1 + 28);
                              else
                                v125 = 0xFFFFFFFFLL;
                              drm_dev_printk(
                                0,
                                &unk_248D72,
                                "*ERROR* [msm-dsi-error]: DSI_%d: clk_pre calculations failed, rc=%d\n",
                                v125,
                                v124);
                            }
                          }
                        }
                      }
                    }
                  }
                  if ( !a1 )
                    goto LABEL_59;
                  goto LABEL_87;
                }
                drm_dev_printk(
                  0,
                  &unk_248D72,
                  "*ERROR* [msm-dsi-error]: Incorrect %s rec value - %d\n",
                  "hs_prepare",
                  v108);
                if ( a1 )
                  v58 = *(unsigned int *)(a1 + 28);
                else
                  v58 = 0xFFFFFFFFLL;
                v68 = "*ERROR* [msm-dsi-error]: DSI_%d: hs_prepare calculations failed, rc=%d\n";
                goto LABEL_86;
              }
              drm_dev_printk(
                0,
                &unk_248D72,
                "*ERROR* [msm-dsi-error]: Incorrect %s rec value - %d\n",
                "clk_trail",
                v86 / 0x64);
            }
          }
          if ( a1 )
            v58 = *(unsigned int *)(a1 + 28);
          else
            v58 = 0xFFFFFFFFLL;
          v68 = "*ERROR* [msm-dsi-error]: DSI_%d: clk_trail calculations failed, rc=%d\n";
LABEL_86:
          v44 = -22;
          drm_dev_printk(0, &unk_248D72, v68, v58, 4294967274LL);
          if ( a1 )
            goto LABEL_87;
          goto LABEL_59;
        }
        drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Incorrect %s rec value - %d\n", "clk_zero", v66 / 0x64);
      }
      if ( a1 )
        v58 = *(unsigned int *)(a1 + 28);
      else
        v58 = 0xFFFFFFFFLL;
      v68 = "*ERROR* [msm-dsi-error]: DSI_%d: clk_zero calculations failed, rc=%d\n";
      goto LABEL_86;
    }
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Incorrect %s rec value - %d\n", "clk_prepare", v47);
    if ( a1 )
      v58 = *(unsigned int *)(a1 + 28);
    else
      v58 = 0xFFFFFFFFLL;
    v68 = "*ERROR* [msm-dsi-error]: DSI_%d: clk_prepare calculations failed, rc=%d\n";
    goto LABEL_86;
  }
  v24 = (v22 + 7 * HIDWORD(v128[1])) / (unsigned int)(7 * HIDWORD(v128[1]));
  v25 = HIDWORD(s[0]) * LODWORD(v128[0]) / (unsigned int)(7 * HIDWORD(v128[1]));
  s[1] = __PAIR64__(v25, v24);
  v26 = (unsigned __int64)(((((unsigned __int64)(HIDWORD(v128[2]) * (v25 - v24)) << 20)
                           * (unsigned __int128)0x28F5C28F5C28F5DuLL) >> 64)
                         + 0xFFFFF) >> 20;
  v27 = v24 + v26;
  LODWORD(s[2]) = v24 + v26;
  if ( v24 + (unsigned int)v26 >= 0x100 )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Incorrect %s rec value - %d\n", "cphy_clk_prepare", v27);
    v56 = _drm_dev_dbg(
            0,
            0,
            0,
            "[msm-dsi-debug]: CPHY_CLK_PREPARE: rec_min=%d, rec_max=%d, reg_val=%d\n",
            LODWORD(s[1]),
            HIDWORD(s[1]),
            BYTE4(s[2]));
    v57 = "*ERROR* [msm-dsi-error]: clk_prepare calculations failed, rc=%d\n";
    goto LABEL_58;
  }
  BYTE4(s[2]) = v24 + v26;
  _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: CPHY_CLK_PREPARE: rec_min=%d, rec_max=%d, reg_val=%d\n", v24, v25, v27);
  v28 = 0x1C0u % LODWORD(v128[0]) * HIDWORD(v128[1]) / LODWORD(v128[0]) + 0x1C0u / LODWORD(v128[0]) * HIDWORD(v128[1]);
  v29 = 262 - (7u % LODWORD(v128[0]) * HIDWORD(v128[1]) / LODWORD(v128[0]) + 7u / LODWORD(v128[0]) * HIDWORD(v128[1]));
  v30 = 7 * HIDWORD(v128[1]);
  HIDWORD(s[39]) = v28;
  if ( v29 >= v28 )
    v29 = 0x1C0u % LODWORD(v128[0]) * HIDWORD(v128[1]) / LODWORD(v128[0]) + 0x1C0u / LODWORD(v128[0]) * HIDWORD(v128[1]);
  LODWORD(s[39]) = v29;
  v31 = (v30 + v29 * LODWORD(v128[0]) - 1) / v30;
  v32 = v28 * LODWORD(v128[0]) / v30;
  s[40] = __PAIR64__(v32, v31);
  v33 = (unsigned __int64)(((((unsigned __int64)(HIDWORD(v132) * (v32 - v31)) << 20)
                           * (unsigned __int128)0x28F5C28F5C28F5DuLL) >> 64)
                         + 0xFFFFF) >> 20;
  v34 = v31 + v33;
  LODWORD(s[41]) = v31 + v33;
  if ( v31 + (unsigned int)v33 >= 0x100 )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Incorrect %s rec value - %d\n", "cphy_clk_pre", v34);
    v56 = _drm_dev_dbg(
            0,
            0,
            0,
            "[msm-dsi-debug]: CPHY_CLK_PRE: rec_min=%d, rec_max=%d, reg_val=%d\n",
            LODWORD(s[40]),
            HIDWORD(s[40]),
            BYTE4(s[41]));
    v57 = "*ERROR* [msm-dsi-error]: clk_pre calculations failed, rc=%d\n";
    goto LABEL_58;
  }
  BYTE4(s[41]) = v31 + v33;
  _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: CPHY_CLK_PRE: rec_min=%d, rec_max=%d, reg_val=%d\n", v31, v32, v34);
  LODWORD(s[36]) = 7u % LODWORD(v128[0]) * HIDWORD(v128[1]) / LODWORD(v128[0])
                 + 7u / LODWORD(v128[0]) * HIDWORD(v128[1]);
  v35 = (7 * HIDWORD(v128[1]) + LODWORD(s[36]) * LODWORD(v128[0]) - 1) / (unsigned int)(7 * HIDWORD(v128[1]));
  HIDWORD(s[36]) = 0xE0u % LODWORD(v128[0]) * HIDWORD(v128[1]) / LODWORD(v128[0])
                 + 0xE0u / LODWORD(v128[0]) * HIDWORD(v128[1]);
  v36 = HIDWORD(s[36]) * LODWORD(v128[0]) / (unsigned int)(7 * HIDWORD(v128[1]));
  s[37] = __PAIR64__(v36, v35);
  v37 = (unsigned __int64)(((((unsigned __int64)(v133 * (v36 - v35)) << 20) * (unsigned __int128)0x28F5C28F5C28F5DuLL) >> 64)
                         + 0xFFFFF) >> 20;
  v38 = v35 + v37;
  LODWORD(s[38]) = v35 + v37;
  if ( v35 + (unsigned int)v37 >= 0x100 )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Incorrect %s rec value - %d\n", "cphy_clk_post", v38);
    v56 = _drm_dev_dbg(
            0,
            0,
            0,
            "[msm-dsi-debug]: CPHY_CLK_POST: rec_min=%d, rec_max=%d, reg_val=%d\n",
            LODWORD(s[37]),
            HIDWORD(s[37]),
            BYTE4(s[38]));
    v57 = "*ERROR* [msm-dsi-error]: clk_zero calculations failed, rc=%d\n";
    goto LABEL_58;
  }
  BYTE4(s[38]) = v35 + v37;
  _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: CPHY_CLK_POST: rec_min=%d, rec_max=%d, reg_val=%d\n", v35, v36, v38);
  v39 = (LODWORD(v128[0]) * LODWORD(s[18]) - 1) / (unsigned int)(7 * HIDWORD(v128[1]));
  LODWORD(s[19]) = v39;
  v40 = (unsigned __int64)(((((unsigned __int64)((HIDWORD(s[19]) - v39) * HIDWORD(v131)) << 20)
                           * (unsigned __int128)0x28F5C28F5C28F5DuLL) >> 64)
                         + 0xFFFFF) >> 20;
  v41 = v39 + v40;
  LODWORD(s[20]) = v39 + v40;
  if ( v39 + (unsigned int)v40 >= 0x100 )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Incorrect %s rec value - %d\n", "cphy_hs_rqst", v41);
    v56 = _drm_dev_dbg(
            0,
            0,
            0,
            "[msm-dsi-debug]: CPHY_HS_RQST: rec_min=%d, rec_max=%d, reg_val=%d\n",
            LODWORD(s[19]),
            HIDWORD(s[19]),
            BYTE4(s[20]));
    v57 = "*ERROR* [msm-dsi-error]: hs_rqst calculations failed, rc=%d\n";
LABEL_58:
    v44 = -22;
    drm_dev_printk(0, &unk_248D72, v57, 4294967274LL, v56);
    if ( a1 )
      goto LABEL_87;
LABEL_59:
    v69 = -1;
LABEL_88:
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: DSI_%d: Timing calc failed, rc=%d\n", v69, v44);
    goto LABEL_144;
  }
  BYTE4(s[20]) = v39 + v40;
  v42 = _drm_dev_dbg(
          0,
          0,
          0,
          "[msm-dsi-debug]: CPHY_HS_RQST: rec_min=%d, rec_max=%d, reg_val=%d\n",
          v39,
          HIDWORD(s[19]),
          v41);
  v43 = calc_cphy_hs_exit(v128, s, v42);
  if ( v43 )
  {
    v44 = v43;
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: hs_exit calculations failed, rc=%d\n", v43);
    if ( !a1 )
      goto LABEL_59;
LABEL_87:
    v69 = *(_DWORD *)(a1 + 28);
    goto LABEL_88;
  }
LABEL_139:
  v126 = *(_DWORD **)(v10 + 48);
  if ( !v126 )
  {
LABEL_143:
    v44 = -22;
    goto LABEL_144;
  }
  if ( *(v126 - 1) != 1502731785 )
    __break(0x8228u);
  ((void (__fastcall *)(__int64, _QWORD *, _QWORD))v126)(a4, s, v11);
  v44 = 0;
LABEL_144:
  _ReadStatusReg(SP_EL0);
  return v44;
}
