__int64 __fastcall spi_geni_transfer_one(__int64 a1, __int64 a2, const void **a3)
{
  __int64 v4; // x28
  __int64 v6; // x19
  __int64 v7; // x21
  unsigned __int64 v8; // x22
  int v9; // w8
  __int64 v10; // x0
  __int64 v11; // x8
  __int64 v12; // x9
  unsigned int v13; // w21
  __int64 v14; // x27
  __int64 v15; // x8
  unsigned int v16; // w26
  int v17; // w0
  int *v18; // x8
  __int64 v19; // x8
  unsigned int v20; // w24
  unsigned int v21; // w0
  __int64 v22; // x2
  unsigned int v23; // w21
  __int64 v24; // x0
  int v25; // w0
  int v26; // w24
  unsigned int v27; // w25
  __int64 v28; // x9
  __int64 v29; // x0
  const void *v30; // x22
  int v31; // w10
  int v32; // w24
  unsigned int v33; // w8
  const void *v34; // x8
  unsigned int v35; // w9
  int v36; // w25
  int v37; // w3
  unsigned __int64 v38; // x25
  unsigned int v39; // w14
  int v40; // w21
  unsigned int v41; // w25
  int v42; // w26
  _QWORD *v43; // x23
  __int64 v44; // x1
  __int64 v45; // x1
  _QWORD *v46; // x21
  char *v47; // x22
  unsigned int v48; // w21
  int v49; // w8
  unsigned int v50; // w9
  __int64 v51; // x5
  __int64 v52; // x23
  __int64 v53; // x28
  __int64 v54; // x25
  unsigned int v55; // w27
  int v56; // w8
  __int64 v57; // x0
  char *v58; // x24
  unsigned int v59; // w21
  int v60; // w8
  unsigned int v61; // w9
  __int64 v62; // x5
  __int64 v63; // x22
  unsigned int v64; // w25
  __int64 v65; // x0
  int v66; // w10
  unsigned __int64 v67; // x23
  unsigned int v68; // w8
  int v69; // w8
  __int64 v70; // x0
  __int64 v71; // x10
  __int64 v72; // x8
  unsigned int v73; // w22
  char v74; // w28
  unsigned int v75; // w26
  int v76; // w0
  __int64 v77; // x8
  int v78; // w25
  int v79; // w24
  int spi_clk_cfg; // w0
  int v81; // w27
  unsigned int v82; // w9
  unsigned int v83; // w23
  const void *v84; // x10
  int v85; // w13
  int v86; // w24
  __int64 *v87; // x10
  int v88; // w10
  int v89; // w10
  bool v90; // zf
  int v91; // w10
  __int64 v92; // x0
  __int64 v93; // x27
  __int64 v94; // x8
  unsigned __int64 v95; // x22
  unsigned int v96; // w25
  char v97; // w8
  unsigned int v98; // w8
  int v99; // w9
  unsigned int v100; // w21
  int v101; // w9
  int v102; // w8
  _BOOL4 v103; // w24
  int v104; // w8
  const void *v105; // x2
  __int64 v106; // x25
  _DWORD *v107; // x8
  int v108; // w2
  int v109; // w3
  int v110; // w4
  __int64 v111; // x9
  __int64 v112; // x0
  __int64 v113; // x8
  int v114; // w9
  __int64 (__fastcall *v115)(_QWORD); // x10
  unsigned __int64 v116; // x8
  __int64 v117; // x8
  __int64 v118; // x8
  unsigned int v119; // w8
  unsigned __int64 v120; // x26
  unsigned int v121; // w23
  unsigned __int64 *v122; // x27
  unsigned int v123; // w25
  __int64 v124; // x24
  int v125; // w22
  size_t v126; // x21
  __int64 v127; // x0
  unsigned __int64 v128; // x0
  unsigned __int64 v129; // x3
  const void *v130; // x1
  __int64 v131; // x8
  char *v132; // x2
  void *v133; // x0
  unsigned __int64 v134; // x28
  __int64 v135; // x0
  unsigned __int64 v136; // x10
  unsigned __int64 v137; // x9
  int v138; // w10
  int v139; // w8
  __int64 v140; // x10
  unsigned __int64 v141; // x21
  __int64 v142; // x0
  __int64 v143; // x8
  int v144; // w9
  __int64 (__fastcall *v145)(_QWORD); // x10
  unsigned __int64 v146; // x8
  __int64 v147; // x8
  __int64 v148; // x8
  __int64 v149; // x0
  __int64 (__fastcall *v150)(_QWORD); // x8
  int v151; // w8
  __int64 v152; // x9
  int v153; // w3
  __int64 v154; // x8
  __int64 v155; // x0
  __int64 (__fastcall *v156)(_QWORD); // x8
  int v157; // w3
  __int64 v158; // x0
  void (__fastcall *v159)(_QWORD); // x8
  __int64 v160; // x0
  __int64 (__fastcall *v161)(_QWORD); // x8
  int v162; // w21
  char v163; // w23
  int v164; // w22
  int v165; // w21
  __int64 v166; // x21
  int v167; // w20
  int v168; // w19
  unsigned __int64 v169; // x3
  unsigned __int64 v170; // x4
  __int64 v171; // x0
  __int64 v172; // x0
  __int64 v173; // x0
  __int64 v174; // x0
  __int64 v175; // x0
  void (__fastcall *v176)(_QWORD); // x8
  __int64 v177; // x0
  __int64 v178; // x19
  int i; // w21
  __int64 v180; // x8
  __int64 v181; // x8
  __int64 v182; // x8
  int v183; // w24
  __int64 v184; // x0
  __int64 v185; // x0
  void (__fastcall *v186)(_QWORD); // x8
  int v188; // [xsp+18h] [xbp-48h]
  unsigned int v189; // [xsp+1Ch] [xbp-44h]
  int v190; // [xsp+20h] [xbp-40h]
  unsigned __int64 v191; // [xsp+20h] [xbp-40h]
  __int64 v192; // [xsp+28h] [xbp-38h]
  __int64 v193; // [xsp+30h] [xbp-30h]
  char v194; // [xsp+30h] [xbp-30h]
  unsigned __int64 v195; // [xsp+38h] [xbp-28h]
  __int64 v196; // [xsp+40h] [xbp-20h]
  __int64 v197; // [xsp+48h] [xbp-18h] BYREF
  _QWORD v198[2]; // [xsp+50h] [xbp-10h] BYREF

  v4 = a1;
  v198[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 152);
  v7 = *(_QWORD *)(v6 + 488);
  if ( v7 )
  {
    if ( *(_DWORD *)(v6 + 496) )
    {
      v8 = sched_clock(a1);
      ipc_log_string(v7, "%s:start at %llu nsec(%llu usec)\n", "spi_geni_transfer_one", v8, v8 / 0x3E8);
      if ( *a3 )
        goto LABEL_9;
    }
    else
    {
      v8 = 0;
      if ( *a3 )
        goto LABEL_9;
    }
  }
  else
  {
    v8 = -22;
    if ( *a3 )
      goto LABEL_9;
  }
  if ( !a3[1] )
  {
    dev_err(*(_QWORD *)(v6 + 200), "Invalid xfer both tx rx are NULL\n");
    goto LABEL_191;
  }
LABEL_9:
  v9 = *((_DWORD *)a3 + 4);
  v10 = *(_QWORD *)(v6 + 200);
  if ( !v9 )
  {
    dev_err(v10, "Zero length transfer\n");
LABEL_191:
    LODWORD(v38) = -22;
    goto LABEL_418;
  }
  if ( *(_DWORD *)(v10 + 500) == 2 )
  {
    ipc_log_string(*(_QWORD *)(v6 + 472), "%s: device is PM suspended\n", "spi_geni_transfer_one");
    v65 = *(_QWORD *)(v6 + 200);
    if ( v65 )
    {
      dev_err(v65, "%s: device is PM suspended\n", "spi_geni_transfer_one");
      if ( *(_QWORD *)(v6 + 200) )
        goto LABEL_133;
    }
    else
    {
      printk(&unk_F156);
      if ( *(_QWORD *)(v6 + 200) )
      {
LABEL_133:
        spi_trace_log();
        LODWORD(v38) = -13;
        goto LABEL_418;
      }
    }
    LODWORD(v38) = -13;
    goto LABEL_418;
  }
  v11 = (unsigned int)(8000 * v9) / *((_DWORD *)a3 + 22);
  v12 = *(unsigned int *)(v6 + 520);
  if ( !(_DWORD)v12 )
  {
    v12 = 250;
    if ( *(_BYTE *)(v4 + 959) )
      v12 = 50;
  }
  v13 = v12 + v11;
  ipc_log_string(*(_QWORD *)(v6 + 472), "current xfer_timeout:%lu ms.\n", v12 + v11);
  if ( *(_QWORD *)(v6 + 200) )
    spi_trace_log();
  v14 = _msecs_to_jiffies(v13);
  v195 = v8;
  if ( *(_DWORD *)(v6 + 452) == 3 )
  {
    *(_QWORD *)(v6 + 456) = 0;
    v15 = *(_QWORD *)(v6 + 304);
    *(_DWORD *)(v6 + 464) = 0;
    *(_BYTE *)(v6 + 448) = 0;
    *(_DWORD *)(v6 + 384) = 0;
    *(_DWORD *)(v6 + 416) = 0;
    v16 = *(unsigned __int8 *)(a2 + 924);
    v196 = v15;
    v197 = 0;
    if ( v16 >= 0x10 )
    {
      v16 = *(unsigned __int8 *)(a2 + 925);
      if ( v16 >= 0x10 )
      {
        v16 = *(unsigned __int8 *)(a2 + 926);
        if ( v16 >= 0x10 )
        {
          v16 = *(unsigned __int8 *)(a2 + 927);
          if ( v16 >= 0x10 )
          {
            ipc_log_string(*(_QWORD *)(v6 + 472), "%s Failed to get the chip select number\n", "setup_gsi_xfer");
            if ( *(_QWORD *)(v6 + 200) )
              spi_trace_log();
            LODWORD(v38) = -1;
            goto LABEL_406;
          }
        }
      }
    }
    if ( *(_BYTE *)(v6 + 503) == 1 && *(_BYTE *)(v6 + 512) == 1 )
    {
      ipc_log_string(*(_QWORD *)(v6 + 472), "%s doing gsi lock, due to levm gsi reset\n", "setup_gsi_xfer");
      if ( *(_QWORD *)(v6 + 200) )
        spi_trace_log();
      v17 = spi_geni_lock_bus(v4);
      if ( v17 )
      {
        LODWORD(v38) = v17;
        ipc_log_string(*(_QWORD *)(v6 + 472), "%s lock bus failed: %d\n", "setup_gsi_xfer", v17);
        if ( *(_QWORD *)(v6 + 200) )
          spi_trace_log();
        goto LABEL_406;
      }
      *(_BYTE *)(v6 + 512) = 0;
    }
    v18 = *(int **)(a2 + 960);
    if ( v18 )
    {
      v188 = *v18;
      v190 = v18[1];
    }
    else
    {
      v188 = 0;
      v190 = 0;
    }
    if ( *(_DWORD *)(v6 + 528) != 9 )
    {
      v39 = 0;
      v40 = 0;
      goto LABEL_137;
    }
    v34 = a3[1];
    if ( *a3 )
    {
      v35 = *((unsigned __int16 *)a3 + 36);
      v36 = (v35 >> 3) & 0xF;
      if ( !v34 )
      {
        v40 = 0;
        if ( v36 != 1 )
          goto LABEL_97;
        goto LABEL_135;
      }
      v37 = (v35 >> 7) & 0xF;
      if ( v36 != v37 )
      {
        ipc_log_string(*(_QWORD *)(v6 + 472), "tx_nbits %d, rx_nbits %d\n", v36, v37);
        if ( *(_QWORD *)(v6 + 200) )
        {
LABEL_52:
          spi_trace_log();
          LODWORD(v38) = -22;
          goto LABEL_406;
        }
LABEL_339:
        LODWORD(v38) = -22;
        goto LABEL_406;
      }
    }
    else
    {
      if ( !v34 )
      {
        ipc_log_string(*(_QWORD *)(v6 + 472), "Neither tx_buf nor rx_buf provided.\n");
        if ( *(_QWORD *)(v6 + 200) )
          goto LABEL_52;
        goto LABEL_339;
      }
      v36 = (*((unsigned __int16 *)a3 + 36) >> 7) & 0xF;
    }
    v40 = 8;
    if ( v36 != 1 )
    {
LABEL_97:
      if ( v36 != 4 )
      {
        if ( v36 != 2 )
        {
          ipc_log_string(*(_QWORD *)(v6 + 472), "Unexpected bus width: %u\n", v36);
          if ( *(_QWORD *)(v6 + 200) )
            spi_trace_log();
          goto LABEL_136;
        }
        ipc_log_string(*(_QWORD *)(v6 + 472), "Dual lane not supported.\n");
        if ( *(_QWORD *)(v6 + 200) )
          goto LABEL_404;
        goto LABEL_393;
      }
      if ( *(_BYTE *)(v6 + 532) )
        v39 = 256;
      else
        v39 = 512;
LABEL_137:
      v66 = *((unsigned __int8 *)a3 + 74);
      v189 = v16;
      v192 = v14;
      v193 = v4;
      if ( *(_DWORD *)(v6 + 232) == v66 && *((_DWORD *)a3 + 22) == *(_DWORD *)(v6 + 228) )
      {
        v67 = 0;
        v68 = 1;
        goto LABEL_156;
      }
      *(_DWORD *)(v6 + 232) = v66;
      v69 = *(_DWORD *)(v6 + 464);
      v70 = *((unsigned int *)a3 + 22);
      v71 = *(_QWORD *)(v6 + 304);
      v198[0] = 0;
      v72 = v71 + 456LL * v69;
      *(_DWORD *)(v6 + 228) = v70;
      v73 = *(_DWORD *)(a2 + 944);
      LODWORD(v197) = 1;
      v67 = v72 + 32;
      if ( v72 == -32 || v67 > 0xFFFFFFFFFFFFF000LL )
      {
LABEL_153:
        if ( !v67 || v67 > 0xFFFFFFFFFFFFF000LL )
        {
          v57 = dev_err(*(_QWORD *)(v6 + 200), "%s:Err setting c0tre:%d\n", "setup_gsi_xfer", 0);
          LODWORD(v38) = v67;
          if ( (_DWORD)v67 )
            goto LABEL_406;
LABEL_296:
          if ( *(int *)(v6 + 456) < 1 )
          {
LABEL_300:
            v163 = 0;
            LODWORD(v38) = 0;
            v164 = 1;
          }
          else
          {
            v162 = 0;
            while ( 1 )
            {
              v57 = wait_for_completion_timeout(v6 + 384, v14);
              if ( !v57 )
                break;
              if ( ++v162 >= *(_DWORD *)(v6 + 456) )
                goto LABEL_300;
            }
            ipc_log_string(*(_QWORD *)(v6 + 472), "Tx[%d] timeout%lu\n", v162, 0);
            v173 = *(_QWORD *)(v6 + 200);
            if ( v173 )
              dev_err(v173, "Tx[%d] timeout%lu\n", v162, 0);
            else
              printk(&unk_E1D1);
            v57 = *(_QWORD *)(v6 + 200);
            if ( v57 )
              spi_trace_log();
            v164 = 0;
            LODWORD(v38) = -110;
            v163 = 1;
          }
          if ( *(int *)(v6 + 460) >= 1 )
          {
            v165 = 0;
            while ( 1 )
            {
              v57 = wait_for_completion_timeout(v6 + 416, v14);
              if ( !v57 )
                break;
              if ( ++v165 >= *(_DWORD *)(v6 + 460) )
                goto LABEL_305;
            }
            ipc_log_string(*(_QWORD *)(v6 + 472), "Rx[%d] timeout%lu\n", v165, 0);
            v174 = *(_QWORD *)(v6 + 200);
            if ( v174 )
              dev_err(v174, "Rx[%d] timeout%lu\n", v165, 0);
            else
              printk(&unk_EDEC);
            if ( *(_QWORD *)(v6 + 200) )
              spi_trace_log();
            LODWORD(v38) = -110;
            goto LABEL_412;
          }
LABEL_305:
          if ( (v163 & 1) == 0 && *(_BYTE *)(v6 + 448) == 1 )
          {
            LODWORD(v38) = -5;
            *(_BYTE *)(v6 + 448) = 0;
            goto LABEL_412;
          }
          if ( !v164 )
          {
LABEL_412:
            geni_spi_se_dump_dbg_regs(v6, *(_QWORD *)(v6 + 184), *(_QWORD *)(v6 + 472));
            v185 = *(_QWORD *)(v6 + 320);
            v186 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)v185 + 336LL);
            if ( v186 )
            {
              if ( *((_DWORD *)v186 - 1) != -403578064 )
                __break(0x8228u);
              v186(v185);
            }
            if ( *(_BYTE *)(v6 + 503) == 1 )
              *(_BYTE *)(v6 + 512) = 1;
            goto LABEL_418;
          }
          goto LABEL_309;
        }
        v66 = *(_DWORD *)(v6 + 232);
        v68 = 2;
LABEL_156:
        v191 = v67;
        if ( (v66 & 3) != 0 )
        {
          v82 = *((_DWORD *)a3 + 4);
          v83 = v82 / (v66 / 8 + 1);
          v84 = a3[1];
          if ( *a3 )
          {
LABEL_158:
            if ( v84 )
            {
              v85 = *(unsigned __int8 *)(v6 + 536);
              if ( *(_DWORD *)(v6 + 528) == 1 )
                v86 = 3;
              else
                v86 = 7;
              v197 = v68 | 0x100000000LL;
              v87 = &v197;
              if ( v85 == 1 && (v82 & 0xF) != 0 )
              {
                while ( 1 )
                {
                  if ( v82 > 0x10 )
                  {
                    v88 = 15;
                  }
                  else
                  {
                    if ( v82 < 9 )
                    {
                      v87 = &v197;
                      LODWORD(v197) = v68;
                      break;
                    }
                    v88 = 7;
                  }
                  v82 &= v88;
                  ++v68;
                  if ( !v82 )
                  {
                    LODWORD(v197) = v68;
                    goto LABEL_196;
                  }
                }
              }
            }
            else
            {
              v89 = *(unsigned __int8 *)(v6 + 536);
              v83 = 0;
              v86 = 1;
              LODWORD(v197) = v68;
              v90 = v89 == 1;
              v87 = &v197;
              if ( v90 && (v82 & 0xF) != 0 )
              {
                while ( 1 )
                {
                  if ( v82 > 0x10 )
                  {
                    v91 = 15;
                  }
                  else
                  {
                    if ( v82 < 9 )
                    {
                      v83 = 0;
                      LODWORD(v197) = v68;
                      v87 = &v197;
                      v86 = 1;
                      break;
                    }
                    v91 = 7;
                  }
                  v82 &= v91;
                  ++v68;
                  if ( !v82 )
                  {
                    v83 = 0;
                    LODWORD(v197) = v68;
                    v86 = 1;
                    goto LABEL_196;
                  }
                }
              }
            }
LABEL_195:
            *(_DWORD *)v87 = v68 + 1;
LABEL_196:
            v93 = v196 + 128;
            if ( ((_WORD)a3[9] & 4) == 0 && a3[14] != *(const void **)(v193 + 1280) )
              v39 |= 4u;
            v94 = *(_QWORD *)(v6 + 304) + 456LL * *(int *)(v6 + 464);
            v95 = v94 + 48;
            if ( v94 != -48 && v95 <= 0xFFFFFFFFFFFFF000LL )
            {
              v96 = v86;
              if ( *(_DWORD *)(v6 + 528) == 9 )
                v97 = 20;
              else
                v97 = 24;
              v98 = v39 << v97;
              if ( (v86 & 2) != 0 )
                v99 = 2099200;
              else
                v99 = 0x200000;
              v90 = v86 == 2;
              v100 = v86 == 2;
              v101 = v99 | (v100 << 8);
              v102 = v98 | (v189 << 8) | v86;
              v103 = v86 != 2;
              *(_DWORD *)v95 = v102;
              *(_DWORD *)(v95 + 4) = 0;
              if ( v90 )
                v104 = v101;
              else
                v104 = v101 + 1;
              *(_DWORD *)(v95 + 8) = v83;
              *(_DWORD *)(v95 + 12) = v104;
              ipc_log_string(
                *(_QWORD *)(v6 + 472),
                "go_tre: rx len %d flags 0x%x cs %d cmd %d eot %d eob %d chain %d\n",
                v83,
                v39,
                v189,
                v96,
                0,
                v100,
                v103);
              if ( *(_QWORD *)(v6 + 200) )
                spi_trace_log();
              ipc_log_string(
                *(_QWORD *)(v6 + 472),
                "go_tre: dword[0]:0x%x dword[1]:0x%x dword[2]:0x%x dword[3]:0x%x\n",
                *(_DWORD *)v95,
                *(_DWORD *)(v95 + 4),
                *(_DWORD *)(v95 + 8),
                *(_DWORD *)(v95 + 12));
              LOBYTE(v86) = v96;
              if ( *(_QWORD *)(v6 + 200) )
                spi_trace_log();
            }
            sg_init_table(v93, (unsigned int)v197);
            if ( HIDWORD(v197) )
              sg_init_table(v196 + 288, HIDWORD(v197));
            v106 = v193;
            if ( v191 )
            {
              v93 = v196 + 160;
              *(_QWORD *)(v196 + 128) = *(_QWORD *)(v196 + 128) & 3LL
                                      | (((unsigned __int64)(((__int64)(v191 << 8) >> 8) + 0x8000000000LL) >> 12 << 6)
                                       - 0x140000000LL);
              *(_DWORD *)(v196 + 136) = v191 & 0xFFF;
              *(_DWORD *)(v196 + 140) = 16;
            }
            v194 = v86;
            *(_QWORD *)v93 = *(_QWORD *)v93 & 3LL
                           | (((unsigned __int64)(((__int64)(v95 << 8) >> 8) + 0x8000000000LL) >> 12 << 6)
                            - 0x140000000LL);
            *(_DWORD *)(v93 + 8) = v95 & 0xFFF;
            *(_DWORD *)(v93 + 12) = 16;
            *(_QWORD *)(*(_QWORD *)(v6 + 304) + 456LL * *(int *)(v6 + 464) + 440) = v106;
            *(_QWORD *)(*(_QWORD *)(v6 + 304) + 456LL * *(int *)(v6 + 464) + 448) = a3;
            if ( (v86 & 2) != 0 )
            {
              v107 = (_DWORD *)(*(_QWORD *)(v6 + 304) + 456LL * *(int *)(v6 + 464));
              v38 = (unsigned __int64)(v107 + 28);
              if ( v107 == (_DWORD *)-112LL || v38 > 0xFFFFFFFFFFFFF000LL )
              {
                dev_err(*(_QWORD *)(v6 + 200), "Err setting up rx tre\n");
                if ( (_DWORD)v38 )
                  goto LABEL_406;
              }
              else
              {
                v108 = *((_DWORD *)a3 + 16);
                v109 = *((_DWORD *)a3 + 17);
                v110 = (_DWORD)a3[2] & 0xFFFFFF;
                *(_DWORD *)v38 = v108;
                v107[29] = v109;
                v107[30] = v110;
                v107[31] = 0x100000;
                ipc_log_string(
                  *(_QWORD *)(v6 + 472),
                  "dma_tre: dword[0]:0x%x dword[1]:0x%x dword[2]:0x%x dword[3]:0x%x\n",
                  v108,
                  v109,
                  v110,
                  0x100000);
                if ( *(_QWORD *)(v6 + 200) )
                  spi_trace_log();
                v111 = *(_QWORD *)(v196 + 288);
                *(_DWORD *)(v196 + 296) = v38 & 0xFFF;
                *(_QWORD *)(v196 + 288) = v111 & 3
                                        | (((unsigned __int64)(((__int64)(v38 << 8) >> 8) + 0x8000000000LL) >> 12 << 6)
                                         - 0x140000000LL);
                *(_DWORD *)(v196 + 300) = 16;
                v112 = *(_QWORD *)(v6 + 328);
                v113 = *(_QWORD *)(v6 + 304);
                v114 = *(_DWORD *)(v6 + 464);
                if ( v112 )
                {
                  if ( *(_QWORD *)v112
                    && (v115 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)v112 + 272LL)) != nullptr )
                  {
                    if ( *((_DWORD *)v115 - 1) != -1221891457 )
                      __break(0x822Au);
                    v112 = v115(v112);
                    v113 = *(_QWORD *)(v6 + 304);
                    v114 = *(_DWORD *)(v6 + 464);
                  }
                  else
                  {
                    v112 = 0;
                  }
                }
                *(_QWORD *)(v113 + 456LL * v114 + 432) = v112;
                v116 = *(_QWORD *)(*(_QWORD *)(v6 + 304) + 456LL * *(int *)(v6 + 464) + 432);
                if ( !v116 || v116 >= 0xFFFFFFFFFFFFF001LL )
                {
                  dev_err(*(_QWORD *)(v6 + 200), "Err setting up rx desc\n");
                  goto LABEL_336;
                }
                *(_QWORD *)(v116 + 40) = spi_gsi_rx_callback;
                v117 = *(_QWORD *)(v6 + 304) + 456LL * *(int *)(v6 + 464);
                *(_QWORD *)(*(_QWORD *)(v117 + 432) + 56LL) = v117 + 376;
                v118 = *(_QWORD *)(v6 + 304) + 456LL * *(int *)(v6 + 464);
                *(_QWORD *)(v118 + 408) = v118 + 440;
                ++*(_DWORD *)(v6 + 460);
              }
            }
            if ( (v86 & 1) != 0 )
            {
              if ( *(_BYTE *)(v6 + 536) == 1 )
              {
                v119 = *((_DWORD *)a3 + 4);
                if ( (v119 & 0xF) != 0 )
                {
                  v120 = 0;
                  v121 = 0;
                  v122 = (unsigned __int64 *)(v93 + 32);
                  v123 = 4;
                  v124 = 64;
                  while ( 1 )
                  {
                    if ( v119 < 0x11 )
                    {
                      if ( v119 < 9 )
                      {
                        v125 = 0;
                        LODWORD(v126) = v119;
                        *(_DWORD *)(v6 + 540) = v119;
                        v123 = v123 & 0xFFFFFFEB | 4;
                      }
                      else
                      {
                        v125 = v119 & 7;
                        LODWORD(v126) = v119 & 0x18;
                        v123 = v123 & 0xFFFFFFEB | 0x10;
                      }
LABEL_251:
                      if ( v120 >= 4 )
                        goto LABEL_419;
                      v130 = a3[7];
                      v131 = *(_QWORD *)(v6 + 304) + 456LL * *(int *)(v6 + 464);
                      v132 = (char *)*a3 + v121;
                      v133 = (void *)(v131 + v124);
                      v134 = v131 + 16 * v120 + 64;
                      goto LABEL_261;
                    }
                    v125 = v119 & 0xF;
                    v126 = v119 & 0xFFFFFFF0;
                    v123 = v123 & 0xFFFFFFEB | 0x10;
                    if ( ((_BYTE)a3[7] & 0xF) == 0 )
                      goto LABEL_251;
                    if ( (unsigned int)v126 > 0x10000 )
                      goto LABEL_339;
                    if ( !*(_QWORD *)(v6 + 552) )
                      break;
LABEL_257:
                    ipc_log_string(*(_QWORD *)(v6 + 472), "Using aligned address to tx first %d bytes\n", v126);
                    if ( *(_QWORD *)(v6 + 200) )
                      spi_trace_log();
                    memcpy(*(void **)(v6 + 544), *a3, v126);
                    if ( v120 >= 4 )
LABEL_419:
                      __break(0x5512u);
                    v130 = *(const void **)(v6 + 560);
                    v132 = *(char **)(v6 + 544);
                    v134 = *(_QWORD *)(v6 + 304) + 456LL * *(int *)(v6 + 464) + v124;
                    v133 = (void *)v134;
LABEL_261:
                    setup_dma_tre(v133, (int)v130, v132, (unsigned int)v126);
                    v119 = v125;
                    if ( !v134 || v134 > 0xFFFFFFFFFFFFF000LL )
                    {
                      dev_err(*(_QWORD *)(v6 + 200), "Err setting up split tx tre\n");
                      LODWORD(v38) = v134;
                      if ( !(_DWORD)v134 )
                        goto LABEL_271;
LABEL_406:
                      ipc_log_string(*(_QWORD *)(v6 + 472), "setup_gsi_xfer failed: %d\n", v38);
                      v184 = *(_QWORD *)(v6 + 200);
                      if ( v184 )
                        dev_err(v184, "setup_gsi_xfer failed: %d\n", v38);
                      else
                        printk(&unk_F774);
                      if ( *(_QWORD *)(v6 + 200) )
                        spi_trace_log();
                      *(_QWORD *)(v6 + 248) = 0;
                      goto LABEL_412;
                    }
                    v136 = *v122;
                    *((_DWORD *)v122 + 2) = v134 & 0xFFF;
                    ++v120;
                    v124 += 16;
                    *((_DWORD *)v122 + 3) = 16;
                    v137 = v136 & 3
                         | (((unsigned __int64)(((__int64)(v134 << 8) >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL);
                    if ( (v123 & 0x10) != 0 )
                      v138 = v126;
                    else
                      v138 = 0;
                    v121 += v138;
                    *v122 = v137;
                    v122 += 4;
                    if ( !v125 )
                      goto LABEL_271;
                  }
                  v127 = *(_QWORD *)(v6 + 288);
                  if ( v127 )
                  {
                    *(_QWORD *)(v6 + 560) = -1;
                    v128 = dma_alloc_attrs(v127, 65552, v6 + 560, 3264, 0);
                    *(_QWORD *)(v6 + 544) = v128;
                    if ( v128 )
                    {
                      v105 = (const void *)v128;
                      if ( v128 < 0xFFFFFFFFFFFFF001LL )
                      {
                        v129 = *(_QWORD *)(v6 + 560);
                        *(_QWORD *)(v6 + 552) = v128;
                        *(_QWORD *)(v6 + 568) = v129;
                        if ( (v129 & 0xF) != 0 )
                        {
                          v129 = (v129 + 15) & 0xFFFFFFFFFFFFFFF0LL;
                          v105 = (const void *)((v128 + 15) & 0xFFFFFFFFFFFFFFF0LL);
                          *(_QWORD *)(v6 + 560) = v129;
                          *(_QWORD *)(v6 + 544) = v105;
                        }
                        ipc_log_string(
                          *(_QWORD *)(v6 + 472),
                          "SPI aligned tx_buf addr:0x%p, dma addr:0x%p\n",
                          v105,
                          (const void *)v129);
                        if ( !*(_QWORD *)(v6 + 200) )
                        {
LABEL_256:
                          if ( !*(_QWORD *)(v6 + 552) )
                          {
                            LODWORD(v38) = -12;
                            goto LABEL_406;
                          }
                          goto LABEL_257;
                        }
LABEL_255:
                        spi_trace_log();
                        goto LABEL_256;
                      }
                    }
                  }
                  else
                  {
                    *(_QWORD *)(v6 + 544) = -22;
                  }
                  v135 = *(_QWORD *)(v6 + 472);
                  *(_QWORD *)(v6 + 552) = 0;
                  ipc_log_string(v135, "Tx DMA buffer allocation failed\n", v105);
                  if ( !*(_QWORD *)(v6 + 200) )
                    goto LABEL_256;
                  goto LABEL_255;
                }
              }
              v139 = *(_DWORD *)(v6 + 464);
              v140 = *(_QWORD *)(v6 + 304);
              *(_DWORD *)(v6 + 540) = 0;
              v141 = v140 + 456LL * v139 + 64;
              setup_dma_tre((void *)v141, (int)a3[7], (void *)*a3, *((unsigned int *)a3 + 4));
              if ( v141 && v141 <= 0xFFFFFFFFFFFFF000LL )
              {
                *(_QWORD *)(v93 + 32) = *(_QWORD *)(v93 + 32) & 3LL
                                      | (((unsigned __int64)(((__int64)(v141 << 8) >> 8) + 0x8000000000LL) >> 12 << 6)
                                       - 0x140000000LL);
                *(_DWORD *)(v93 + 40) = v141 & 0xFFF;
                *(_DWORD *)(v93 + 44) = 16;
LABEL_271:
                ++*(_DWORD *)(v6 + 456);
              }
              else
              {
                dev_err(*(_QWORD *)(v6 + 200), "Err setting up tx tre\n");
                LODWORD(v38) = v141;
                if ( (_DWORD)v141 )
                  goto LABEL_406;
              }
            }
            v142 = *(_QWORD *)(v6 + 320);
            v143 = *(_QWORD *)(v6 + 304);
            v144 = *(_DWORD *)(v6 + 464);
            if ( v142 )
            {
              v14 = v192;
              if ( *(_QWORD *)v142 && (v145 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)v142 + 272LL)) != nullptr )
              {
                if ( *((_DWORD *)v145 - 1) != -1221891457 )
                  __break(0x822Au);
                v142 = v145(v142);
                v143 = *(_QWORD *)(v6 + 304);
                v144 = *(_DWORD *)(v6 + 464);
              }
              else
              {
                v142 = 0;
              }
            }
            else
            {
              v14 = v192;
            }
            *(_QWORD *)(v143 + 456LL * v144 + 424) = v142;
            v146 = *(_QWORD *)(*(_QWORD *)(v6 + 304) + 456LL * *(int *)(v6 + 464) + 424);
            if ( v146 && v146 < 0xFFFFFFFFFFFFF001LL )
            {
              *(_QWORD *)(v146 + 40) = spi_gsi_tx_callback;
              v147 = *(_QWORD *)(v6 + 304) + 456LL * *(int *)(v6 + 464);
              *(_QWORD *)(*(_QWORD *)(v147 + 424) + 56LL) = v147 + 328;
              v148 = *(_QWORD *)(v6 + 304) + 456LL * *(int *)(v6 + 464);
              *(_QWORD *)(v148 + 360) = v148 + 440;
              v149 = *(_QWORD *)(*(_QWORD *)(v6 + 304) + 456LL * *(int *)(v6 + 464) + 424);
              v150 = *(__int64 (__fastcall **)(_QWORD))(v149 + 24);
              if ( *((_DWORD *)v150 - 1) != 1188179853 )
                __break(0x8228u);
              *(_DWORD *)(*(_QWORD *)(v6 + 304) + 456LL * *(int *)(v6 + 464) + 320) = v150(v149);
              v151 = *(_DWORD *)(v6 + 464);
              v152 = *(_QWORD *)(v6 + 304);
              v153 = *(_DWORD *)(v152 + 456LL * v151 + 320);
              if ( v153 < 0 )
              {
                dev_err(*(_QWORD *)(v6 + 200), "%s: dmaengine_submit failed (%d)\n", "setup_gsi_xfer", v153);
                v171 = *(_QWORD *)(v6 + 320);
              }
              else
              {
                if ( (v194 & 2) == 0 )
                {
                  v154 = v6 + 320;
LABEL_293:
                  v160 = *(_QWORD *)v154;
                  v161 = *(__int64 (__fastcall **)(_QWORD))(**(_QWORD **)v154 + 360LL);
                  if ( *((_DWORD *)v161 - 1) != 905352215 )
                    __break(0x8228u);
                  v57 = v161(v160);
                  ++*(_DWORD *)(v6 + 464);
                  goto LABEL_296;
                }
                v155 = *(_QWORD *)(v152 + 456LL * v151 + 432);
                v156 = *(__int64 (__fastcall **)(_QWORD))(v155 + 24);
                if ( *((_DWORD *)v156 - 1) != 1188179853 )
                  __break(0x8228u);
                *(_DWORD *)(*(_QWORD *)(v6 + 304) + 456LL * *(int *)(v6 + 464) + 324) = v156(v155);
                v157 = *(_DWORD *)(*(_QWORD *)(v6 + 304) + 456LL * *(int *)(v6 + 464) + 324);
                if ( (v157 & 0x80000000) == 0 )
                {
                  v158 = *(_QWORD *)(v6 + 320);
                  v159 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)v158 + 360LL);
                  if ( *((_DWORD *)v159 - 1) != 905352215 )
                    __break(0x8228u);
                  v159(v158);
                  v154 = v6 + 328;
                  goto LABEL_293;
                }
                dev_err(*(_QWORD *)(v6 + 200), "%s: dmaengine_submit failed (%d)\n", "setup_gsi_xfer", v157);
                v171 = *(_QWORD *)(v6 + 328);
              }
              v176 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)v171 + 336LL);
              if ( v176 )
              {
                if ( *((_DWORD *)v176 - 1) != -403578064 )
                  __break(0x8228u);
                v176(v171);
                LODWORD(v38) = -22;
                goto LABEL_406;
              }
              goto LABEL_339;
            }
            dev_err(*(_QWORD *)(v6 + 200), "Err setting up tx desc\n");
LABEL_336:
            LODWORD(v38) = -5;
            goto LABEL_406;
          }
        }
        else
        {
          v82 = *((_DWORD *)a3 + 4);
          v83 = 8 * v82 / v66;
          v84 = a3[1];
          if ( *a3 )
            goto LABEL_158;
        }
        if ( v84 )
        {
          LODWORD(v197) = v68;
          v87 = (__int64 *)((char *)&v197 + 4);
          v86 = 2;
          v68 = 0;
          goto LABEL_195;
        }
        v86 = 0;
        goto LABEL_196;
      }
      v74 = *((_BYTE *)a3 + 74);
      v75 = v39;
      if ( *(_BYTE *)(v6 + 503) == 1 )
      {
        v76 = readl_relaxed((unsigned int *)(*(_QWORD *)(v6 + 184) + 124LL));
        v77 = *(_QWORD *)(v6 + 184);
        v78 = v76;
        LODWORD(v198[0]) = v76;
        v79 = (unsigned __int16)readl_relaxed((unsigned int *)(v77 + 72)) >> 4;
      }
      else
      {
        spi_clk_cfg = get_spi_clk_cfg(v70, v6, v198, (char *)v198 + 4);
        if ( spi_clk_cfg )
        {
          v183 = spi_clk_cfg;
          dev_err(*(_QWORD *)(v6 + 200), "%s:Err setting clks:%d\n", "setup_config0_tre", spi_clk_cfg);
          v67 = v183;
LABEL_152:
          v39 = v75;
          goto LABEL_153;
        }
        v78 = v198[0];
        v79 = HIDWORD(v198[0]);
      }
      v81 = (v73 >> 5) & 1 | (16 * (v73 & 3));
      *(_DWORD *)v67 = (v40 << 14) | (v81 << 8) | (unsigned __int8)(v74 - 4) | 0x3000000;
      *(_DWORD *)(v67 + 4) = v190 | (v188 << 8);
      *(_DWORD *)(v67 + 8) = v79 | (v78 << 16);
      *(_DWORD *)(v67 + 12) = 2228225;
      ipc_log_string(
        *(_QWORD *)(v6 + 472),
        "config0_tre: flags 0x%x word %d pack %d freq %d idx %d div %d\n",
        v81,
        (unsigned __int8)(v74 - 4),
        3,
        *(_DWORD *)(v6 + 228),
        v78,
        v79);
      if ( *(_QWORD *)(v6 + 200) )
        spi_trace_log();
      ipc_log_string(
        *(_QWORD *)(v6 + 472),
        "config0_tre: cs_clk_delay %d inter_words_delay %d dummy_clk_cnt %d\n",
        v188,
        v190,
        v40);
      v14 = v192;
      if ( *(_QWORD *)(v6 + 200) )
        spi_trace_log();
      ipc_log_string(
        *(_QWORD *)(v6 + 472),
        "config0_tre: dword[0]:0x%x dword[1]:0x%x dword[2]:0x%x dword[3]:0x%x\n",
        *(_DWORD *)v67,
        *(_DWORD *)(v67 + 4),
        *(_DWORD *)(v67 + 8),
        *(_DWORD *)(v67 + 12));
      if ( *(_QWORD *)(v6 + 200) )
        spi_trace_log();
      goto LABEL_152;
    }
LABEL_135:
    if ( *(_BYTE *)(v6 + 532) != 1 )
    {
LABEL_136:
      v39 = 0;
      goto LABEL_137;
    }
    ipc_log_string(*(_QWORD *)(v6 + 472), "DDR not supported for single lane.\n");
    if ( *(_QWORD *)(v6 + 200) )
    {
LABEL_404:
      spi_trace_log();
      LODWORD(v38) = -93;
      goto LABEL_406;
    }
LABEL_393:
    LODWORD(v38) = -93;
    goto LABEL_406;
  }
  v19 = *(_QWORD *)(v6 + 184);
  *(_DWORD *)(v6 + 256) = 0;
  v20 = *(unsigned __int16 *)(a2 + 944);
  v21 = readl_relaxed((unsigned int *)(v19 + 604));
  v22 = *((unsigned __int8 *)a3 + 74);
  v23 = v21;
  if ( *(_DWORD *)(v6 + 232) != (_DWORD)v22 )
  {
    spi_setup_word_len(v6, v20, v22);
    LODWORD(v22) = *((unsigned __int8 *)a3 + 74);
    *(_DWORD *)(v6 + 232) = v22;
  }
  v24 = *((unsigned int *)a3 + 22);
  if ( (_DWORD)v24 != *(_DWORD *)(v6 + 228) )
  {
    v198[0] = 0;
    v25 = get_spi_clk_cfg(v24, v6, (char *)v198 + 4, v198);
    if ( v25 )
    {
      LODWORD(v38) = v25;
      dev_err(*(_QWORD *)(v6 + 200), "%s:Err setting clks:%d\n", "setup_fifo_xfer", v25);
LABEL_327:
      ipc_log_string(*(_QWORD *)(v6 + 472), "setup_fifo_xfer failed: %d\n", v38);
      v175 = *(_QWORD *)(v6 + 200);
      if ( v175 )
        dev_err(v175, "setup_fifo_xfer failed: %d\n", v38);
      else
        printk(&unk_E6CB);
      if ( *(_QWORD *)(v6 + 200) )
        spi_trace_log();
      v43 = (_QWORD *)(v6 + 248);
      goto LABEL_354;
    }
    v26 = v198[0];
    v27 = (16 * LODWORD(v198[0])) | 1;
    v28 = *(_QWORD *)(v6 + 184);
    v29 = BYTE4(v198[0]) & 7;
    *(_DWORD *)(v6 + 228) = *((_DWORD *)a3 + 22);
    writel_relaxed(v29, v28 + 124);
    writel_relaxed(v27, *(_QWORD *)(v6 + 184) + 72LL);
    ipc_log_string(
      *(_QWORD *)(v6 + 472),
      "%s: freq %d idx %d div %d\n",
      "setup_fifo_xfer",
      *((_DWORD *)a3 + 22),
      HIDWORD(v198[0]),
      v26);
    if ( *(_QWORD *)(v6 + 200) )
      spi_trace_log();
    LODWORD(v22) = *(_DWORD *)(v6 + 232);
  }
  *(_QWORD *)(v6 + 236) = 0;
  v30 = a3[1];
  if ( v30 )
    v31 = 3;
  else
    v31 = 1;
  if ( *a3 )
    v32 = v31;
  else
    v32 = 2 * (v30 != nullptr);
  if ( !*(_BYTE *)(v4 + 959) )
    v23 &= ~1u;
  if ( (v22 & 3) != 0 )
    v33 = *((_DWORD *)a3 + 4) / (unsigned int)((int)v22 / 8 + 1);
  else
    v33 = 8 * *((_DWORD *)a3 + 4) / (unsigned int)v22;
  v41 = v33 & 0xFFFFFF;
  if ( ((_WORD)a3[9] & 4) != 0 )
    v42 = 0;
  else
    v42 = 4 * (a3[14] != *(const void **)(v4 + 1280));
  *(_QWORD *)(v6 + 248) = a3;
  v43 = (_QWORD *)(v6 + 248);
  if ( (v32 & 1) != 0 )
  {
    v44 = *(_QWORD *)(v6 + 184) + 620LL;
    *(_DWORD *)(v6 + 236) = *((_DWORD *)a3 + 4);
    writel_relaxed(v41, v44);
  }
  if ( v30 )
  {
    writel_relaxed(v41, *(_QWORD *)(v6 + 184) + 624LL);
    *(_DWORD *)(v6 + 240) = *((_DWORD *)a3 + 4);
  }
  if ( *(_BYTE *)(v4 + 959) == 1 )
    *(_DWORD *)(v6 + 452) = 2;
  if ( (*(_BYTE *)(v6 + 513) & 1) != 0 || v41 <= *(_DWORD *)(v6 + 216) * *(_DWORD *)(v6 + 212) / *(_DWORD *)(v6 + 232) )
  {
    v45 = 1;
    *(_DWORD *)(v6 + 452) = 1;
  }
  else
  {
    v45 = *(unsigned int *)(v6 + 452);
  }
  geni_se_select_mode(v6, v45);
  if ( (*(_BYTE *)(v4 + 959) & 1) == 0 )
    writel_relaxed(v23, *(_QWORD *)(v6 + 184) + 604LL);
  writel(v42 | (unsigned int)(v32 << 27), *(_QWORD *)v6 + 1536LL);
  ipc_log_string(
    *(_QWORD *)(v6 + 472),
    "%s: trans_len %d xferlen%d tx_cfg 0x%x cmd 0x%x cs%d mode%d freq %d\n",
    "setup_fifo_xfer",
    v41,
    *((_DWORD *)a3 + 4),
    v23,
    v32,
    (*((unsigned __int16 *)a3 + 36) >> 2) & 1,
    *(_DWORD *)(v6 + 452),
    *((_DWORD *)a3 + 22));
  if ( *(_QWORD *)(v6 + 200) )
    spi_trace_log();
  if ( v30
    && *(_DWORD *)(v6 + 452) == 2
    && ((v46 = a3 + 8, LODWORD(v38) = geni_se_rx_dma_prep(v6, a3[1], *((unsigned int *)a3 + 4), a3 + 8), (_DWORD)v38)
     || !a3[1]) )
  {
    ipc_log_string(*(_QWORD *)(v6 + 472), "Failed to setup Rx dma %d\n", v38);
    v172 = *(_QWORD *)(v6 + 200);
    if ( v172 )
      dev_err(v172, "Failed to setup Rx dma %d\n", v38);
    else
      printk(&unk_E573);
    if ( *(_QWORD *)(v6 + 200) )
LABEL_396:
      spi_trace_log();
  }
  else
  {
    if ( (v32 & 1) != 0 )
    {
      v47 = (char *)*a3;
      if ( *a3 )
      {
        v48 = *((_DWORD *)a3 + 4);
        raw_spin_lock(v6 + 160);
        v49 = *(_DWORD *)(v6 + 524);
        if ( v49 >= (int)v48 )
          v50 = v48;
        else
          v50 = *(_DWORD *)(v6 + 524);
        if ( v49 <= 0 )
          v51 = v48;
        else
          v51 = v50;
        if ( (int)v51 < 17 )
        {
          LODWORD(v54) = 0;
        }
        else
        {
          v52 = v4;
          v53 = v14;
          v54 = 0;
          do
          {
            v55 = v51;
            _spi_dump_ipc(v6, "FIFO Tx", &v47[v54], v48, (unsigned int)v54, 16);
            v54 += 16;
            v51 = v55 - 16;
          }
          while ( v55 > 0x20 );
          v14 = v53;
          v4 = v52;
          v43 = (_QWORD *)(v6 + 248);
        }
        _spi_dump_ipc(v6, "FIFO Tx", &v47[(int)v54], v48, (unsigned int)v54, v51);
        raw_spin_unlock(v6 + 160);
      }
    }
    if ( (v32 & 1) == 0 )
      goto LABEL_103;
    v56 = *(_DWORD *)(v6 + 452);
    if ( v56 != 2 )
    {
      if ( v56 == 1 )
        writel_relaxed(*(unsigned int *)(v6 + 220), *(_QWORD *)(v6 + 184) + 2060LL);
      goto LABEL_103;
    }
    v46 = a3 + 7;
    LODWORD(v38) = geni_se_tx_dma_prep(v6, *a3, *((unsigned int *)a3 + 4), a3 + 7);
    if ( !(_DWORD)v38 && *a3 )
    {
LABEL_103:
      __dsb(0xFu);
      goto LABEL_104;
    }
    ipc_log_string(*(_QWORD *)(v6 + 472), "Failed to setup tx dma %d\n", v38);
    v177 = *(_QWORD *)(v6 + 200);
    if ( v177 )
      dev_err(v177, "Failed to setup tx dma %d\n", v38);
    else
      printk(&unk_EBB8);
    if ( *(_QWORD *)(v6 + 200) )
      goto LABEL_396;
  }
  *v46 = 0;
  if ( (_DWORD)v38 )
    goto LABEL_327;
LABEL_104:
  if ( *(_BYTE *)(v4 + 959) == 1 )
    *(_BYTE *)(v6 + 515) = 1;
  v57 = wait_for_completion_timeout(v6 + 256, v14);
  if ( *(_BYTE *)(v4 + 959) == 1 )
    *(_BYTE *)(v6 + 515) = 0;
  if ( !v57 )
  {
    ipc_log_string(
      *(_QWORD *)(v6 + 472),
      "Xfer[len %d tx %pK rx %pK n %d] timed out.\n",
      *((_DWORD *)a3 + 4),
      *a3,
      a3[1],
      *((unsigned __int8 *)a3 + 74));
    v92 = *(_QWORD *)(v6 + 200);
    if ( v92 )
      dev_err(
        v92,
        "Xfer[len %d tx %pK rx %pK n %d] timed out.\n",
        *((_DWORD *)a3 + 4),
        *a3,
        a3[1],
        *((unsigned __int8 *)a3 + 74));
    else
      printk(&unk_E3AC);
    if ( *(_QWORD *)(v6 + 200) )
      spi_trace_log();
    LODWORD(v38) = -110;
LABEL_354:
    *v43 = 0;
    v178 = *(_QWORD *)(v4 + 152);
    geni_spi_se_dump_dbg_regs(v178, *(_QWORD *)(v178 + 184), *(_QWORD *)(v178 + 472));
    if ( *(_DWORD *)(v178 + 452) == 1 )
      writel_relaxed(0, *(_QWORD *)(v178 + 184) + 2060LL);
    if ( (*(_BYTE *)(v4 + 959) & 1) == 0 )
    {
      *(_DWORD *)(v178 + 256) = 0;
      if ( a3[1] )
      {
        for ( i = readl_relaxed((unsigned int *)(*(_QWORD *)(v178 + 184) + 2052LL)) & 0x1FFFFFF; i; --i )
          readl_relaxed((unsigned int *)(*(_QWORD *)(v178 + 184) + 1920LL));
      }
      writel_relaxed(4, *(_QWORD *)v178 + 1540LL);
      __dsb(0xFu);
      if ( !wait_for_completion_timeout(v178 + 256, 250) )
      {
        v180 = *(_QWORD *)v178;
        *(_DWORD *)(v178 + 256) = 0;
        writel_relaxed(2, v180 + 1540);
        __dsb(0xFu);
        if ( !wait_for_completion_timeout(v178 + 256, 250) )
          dev_err(*(_QWORD *)(v178 + 200), "Failed to cancel/abort m_cmd\n");
      }
    }
    if ( *(_DWORD *)(v178 + 452) == 2 )
    {
      if ( *a3 && a3[7] )
      {
        v181 = *(_QWORD *)(v178 + 184);
        *(_DWORD *)(v178 + 256) = 0;
        writel_relaxed(1, v181 + 3160);
        if ( !wait_for_completion_timeout(v178 + 256, 250) )
          dev_err(*(_QWORD *)(v178 + 200), "DMA TX RESET failed\n");
        geni_se_tx_dma_unprep(v178, a3[7], *((unsigned int *)a3 + 4));
      }
      if ( a3[1] && a3[8] )
      {
        v182 = *(_QWORD *)(v178 + 184);
        *(_DWORD *)(v178 + 256) = 0;
        writel_relaxed(1, v182 + 3416);
        if ( !wait_for_completion_timeout(v178 + 256, 250) )
          dev_err(*(_QWORD *)(v178 + 200), "DMA RX RESET failed\n");
        geni_se_rx_dma_unprep(v178, a3[8], *((unsigned int *)a3 + 4));
      }
    }
    if ( *(_BYTE *)(v4 + 959) == 1 && (*(_BYTE *)(v178 + 505) & 1) == 0 )
      _pm_runtime_suspend(*(_QWORD *)(v178 + 200), 4);
    goto LABEL_418;
  }
  v58 = (char *)a3[1];
  if ( v58 )
  {
    v59 = *((_DWORD *)a3 + 4);
    raw_spin_lock(v6 + 160);
    v60 = *(_DWORD *)(v6 + 524);
    if ( v60 >= (int)v59 )
      v61 = v59;
    else
      v61 = *(_DWORD *)(v6 + 524);
    if ( v60 <= 0 )
      v62 = v59;
    else
      v62 = v61;
    if ( (int)v62 < 17 )
    {
      LODWORD(v63) = 0;
    }
    else
    {
      v63 = 0;
      do
      {
        v64 = v62;
        _spi_dump_ipc(v6, "FIFO Rx", &v58[v63], v59, (unsigned int)v63, 16);
        v63 += 16;
        v62 = v64 - 16;
      }
      while ( v64 > 0x20 );
    }
    _spi_dump_ipc(v6, "FIFO Rx", &v58[(int)v63], v59, (unsigned int)v63, v62);
    v57 = raw_spin_unlock(v6 + 160);
  }
  if ( *(_DWORD *)(v6 + 452) == 2 )
  {
    if ( *a3 )
      v57 = geni_se_tx_dma_unprep(v6, a3[7], *((unsigned int *)a3 + 4));
    if ( a3[1] )
      v57 = geni_se_rx_dma_unprep(v6, a3[8], *((unsigned int *)a3 + 4));
  }
LABEL_309:
  v166 = *(_QWORD *)(v6 + 488);
  if ( !v166 )
  {
LABEL_317:
    LODWORD(v38) = 0;
    goto LABEL_418;
  }
  LODWORD(v38) = 0;
  if ( v195 && *(_DWORD *)(v6 + 496) )
  {
    v167 = *((_DWORD *)a3 + 4);
    v168 = *(_DWORD *)(v6 + 228);
    v169 = sched_clock(v57) - v195;
    v170 = v169 / 0x3E8;
    if ( v167 )
    {
      if ( v168 )
        ipc_log_string(
          v166,
          "%s:took %llu nsec(%llu usec) for %u bytes with freq %u\n",
          "spi_geni_transfer_one",
          v169,
          v170,
          v167,
          v168);
      else
        ipc_log_string(v166, "%s:took %llu nsec(%llu usec) for %u bytes\n", "spi_geni_transfer_one", v169, v170, v167);
    }
    else
    {
      ipc_log_string(v166, "%s:took %llu nsec(%llu usec)\n", "spi_geni_transfer_one", v169, v170);
    }
    goto LABEL_317;
  }
LABEL_418:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v38;
}
