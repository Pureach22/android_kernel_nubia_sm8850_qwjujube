__int64 __fastcall ipa_lnx_stats_ioctl(__int64 a1, int a2, __int64 a3)
{
  __int64 v4; // x23
  int eth_inst_stats; // w19
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x0
  unsigned __int64 StatusReg; // x12
  unsigned __int64 v23; // x8
  unsigned __int64 v24; // x8
  unsigned __int64 v30; // x9
  unsigned __int64 v31; // x2
  unsigned __int64 v32; // x8
  unsigned __int64 v34; // x9
  char v35; // w8
  unsigned int v36; // w21
  int v37; // w27
  __int64 ep_mapping; // x0
  unsigned int v39; // w22
  unsigned int ep_reg_idx; // w0
  __int64 v41; // x8
  __int64 *v42; // x0
  __int64 v43; // x8
  __int64 *v44; // x20
  int generic_stats; // w0
  int clock_stats; // w0
  int wlan_inst_stats; // w0
  int v48; // w0
  int usb_inst_stats; // w0
  unsigned __int64 v50; // x20
  unsigned __int64 v51; // x0
  void *v52; // x19
  __int64 v53; // x23
  unsigned __int64 v54; // x8
  unsigned __int64 v55; // x9
  unsigned __int64 v56; // x9
  unsigned __int64 v58; // x8
  __int64 v59; // x0
  unsigned __int64 v60; // x8
  unsigned __int64 v62; // x9
  __int64 v63; // x0
  __int64 v64; // x0
  __int64 v65; // x0
  __int64 v66; // x0
  __int64 v67; // x0
  __int64 v68; // x0
  __int64 v69; // x0
  __int64 v70; // x0
  __int64 v71; // x0
  __int64 v72; // x0
  __int64 v73; // x0
  __int64 ipc_logbuf; // x0
  __int64 v75; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v77; // x0
  __int64 v79; // x0
  __int64 v80; // x0
  __int64 v81; // x0
  __int64 v82; // x0
  __int64 v83; // x0
  int v84; // w9
  int max_num_pipes; // w0
  unsigned int v86; // w21
  unsigned int v87; // w0
  char v88; // w8
  __int64 v89; // x21
  char v90; // w8
  unsigned int v91; // w27
  char *v92; // x9
  unsigned __int64 v93; // x25
  unsigned __int64 v94; // x26
  _DWORD *v95; // x8
  int v96; // w11
  int v97; // w10
  _DWORD *v98; // x24
  int ipa_client_type_from_eth_type; // w0
  __int64 v100; // x26
  int v101; // w0
  int v102; // w9
  unsigned int v103; // w23
  __int64 v104; // x0
  __int64 v105; // x0
  __int64 v106; // x0
  __int64 v107; // x8
  __int64 v108; // x0
  unsigned int v109; // w20
  __int64 v110; // x0
  __int64 v111; // x0
  __int64 v112; // x0
  __int64 v113; // x8
  __int64 v114; // x0
  unsigned int v115; // w21
  __int64 v116; // x8
  __int64 v117; // x9
  char *v118; // x11
  unsigned __int64 v119; // x12
  _DWORD *v120; // x10
  int v121; // w9
  int v122; // w10
  _DWORD *v123; // x8
  int v124; // w11
  unsigned __int64 v125; // x8
  unsigned __int64 v126; // x8
  unsigned __int64 v128; // x9
  __int64 v129; // x0
  unsigned __int64 v130; // x8
  unsigned __int64 v132; // x9
  __int64 v133; // x0
  __int64 v134; // x0
  __int64 v135; // x0
  __int64 v136; // x0
  __int64 v137; // x0
  __int64 v138; // x0
  __int64 v139; // x0
  __int64 v140; // x0
  __int64 v141; // x0
  __int64 v142; // x0
  __int64 v143; // x0
  __int64 v144; // x0
  __int64 v145; // x0
  __int64 v146; // x0
  __int64 v147; // x0
  __int64 v148; // x0
  __int64 v149; // x0
  __int64 v150; // x0
  __int64 v151; // x0
  __int64 v152; // x0
  __int64 v153; // x0
  __int64 v154; // x0
  __int64 v155; // x0
  __int64 v156; // x0
  __int64 v157; // x0
  __int64 v158; // x0
  __int64 v159; // x0
  __int64 v160; // x0
  __int64 v161; // x0
  __int64 v162; // x0
  __int64 v163; // x0
  __int64 v164; // x0
  __int64 v165; // x0
  __int64 v166; // x0
  __int64 v167; // x0
  __int64 v168; // x0
  __int64 v169; // x0
  __int64 v170; // x0
  __int64 v171; // x0
  __int64 v172; // x0
  __int64 v173; // x0
  __int64 v174; // x0
  __int64 v175; // x0
  __int64 v176; // x0
  __int64 v177; // x0
  __int64 v178; // x0
  __int64 v179; // x0
  __int64 v180; // x0
  __int64 v181; // x0
  __int64 v182; // x0
  __int64 v183; // x0
  __int64 v184; // x0
  __int64 v185; // x0
  __int64 v186; // x0
  __int64 v187; // x0
  __int64 v188; // x0
  __int64 v189; // x0
  __int64 v190; // x0
  __int64 v191; // x0
  __int64 v192; // x0
  __int64 v193; // x0
  __int64 v194; // [xsp+0h] [xbp-20h]
  unsigned __int64 v195; // [xsp+8h] [xbp-18h]
  __int64 v196; // [xsp+10h] [xbp-10h]
  char v197; // [xsp+1Ch] [xbp-4h]

  if ( (a2 & 0xFF00) != 0x7200 )
  {
    v73 = printk(&unk_3FE7E1, "ipa_lnx_stats_ioctl");
    ipc_logbuf = ipa3_get_ipc_logbuf(v73);
    if ( ipc_logbuf )
    {
      v75 = ipa3_get_ipc_logbuf(ipc_logbuf);
      ipc_logbuf = ipc_log_string(v75, "ipa-lnx-stats %s:%d IOC type mismatch %d\n", "ipa_lnx_stats_ioctl", 1749, a2);
    }
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low(ipc_logbuf);
    if ( ipc_logbuf_low )
    {
      v77 = ipa3_get_ipc_logbuf_low(ipc_logbuf_low);
      ipc_log_string(v77, "ipa-lnx-stats %s:%d IOC type mismatch %d\n", "ipa_lnx_stats_ioctl", 1749, a2);
    }
    return -25;
  }
  v4 = (__int64)&off_1F7000;
  if ( !ipa3_ctx )
  {
    v79 = printk(&unk_3AA4B4, "ipa_lnx_stats_ioctl");
    v80 = ipa3_get_ipc_logbuf(v79);
    if ( v80 )
    {
      v81 = ipa3_get_ipc_logbuf(v80);
      v80 = ipc_log_string(
              v81,
              "ipa-lnx-stats %s:%d IPA driver is not up, rejecting the ioctl\n",
              "ipa_lnx_stats_ioctl",
              1754);
    }
    v82 = ipa3_get_ipc_logbuf_low(v80);
    if ( v82 )
    {
      v83 = ipa3_get_ipc_logbuf_low(v82);
      ipc_log_string(
        v83,
        "ipa-lnx-stats %s:%d IPA driver is not up, rejecting the ioctl\n",
        "ipa_lnx_stats_ioctl",
        1754);
    }
    return -1;
  }
  mutex_lock(&ipa_lnx_ctx_mutex);
  if ( a2 <= -1073188347 )
  {
    if ( a2 > -1073188349 )
    {
      if ( a2 == -1073188348 )
      {
        eth_inst_stats = ipa_get_eth_inst_stats(a3);
        if ( eth_inst_stats )
        {
          v63 = printk(&unk_3D8CDC, "ipa_lnx_stats_ioctl");
          v64 = ipa3_get_ipc_logbuf(v63);
          if ( v64 )
          {
            v65 = ipa3_get_ipc_logbuf(v64);
            v64 = ipc_log_string(v65, "ipa-lnx-stats %s:%d ipa get eth inst stats fail", "ipa_lnx_stats_ioctl", 1783);
          }
          v66 = ipa3_get_ipc_logbuf_low(v64);
          if ( v66 )
          {
            v67 = ipa3_get_ipc_logbuf_low(v66);
            ipc_log_string(v67, "ipa-lnx-stats %s:%d ipa get eth inst stats fail", "ipa_lnx_stats_ioctl", 1783);
          }
        }
      }
      else
      {
        eth_inst_stats = ipa_get_usb_inst_stats(a3);
        if ( eth_inst_stats )
        {
          v17 = printk(&unk_3EF89B, "ipa_lnx_stats_ioctl");
          v18 = ipa3_get_ipc_logbuf(v17);
          if ( v18 )
          {
            v19 = ipa3_get_ipc_logbuf(v18);
            v18 = ipc_log_string(v19, "ipa-lnx-stats %s:%d ipa get usb inst stats fail", "ipa_lnx_stats_ioctl", 1788);
          }
          v20 = ipa3_get_ipc_logbuf_low(v18);
          if ( v20 )
          {
            v21 = ipa3_get_ipc_logbuf_low(v20);
            ipc_log_string(v21, "ipa-lnx-stats %s:%d ipa get usb inst stats fail", "ipa_lnx_stats_ioctl", 1788);
          }
        }
      }
      goto LABEL_157;
    }
    if ( a2 != -1073450489 )
    {
      if ( a2 == -1073188349 )
      {
        eth_inst_stats = ipa_get_wlan_inst_stats(a3);
        if ( eth_inst_stats )
        {
          v7 = printk(&unk_3C155A, "ipa_lnx_stats_ioctl");
          v8 = ipa3_get_ipc_logbuf(v7);
          if ( v8 )
          {
            v9 = ipa3_get_ipc_logbuf(v8);
            v8 = ipc_log_string(v9, "ipa-lnx-stats %s:%d ipa get wlan inst stats fail", "ipa_lnx_stats_ioctl", 1778);
          }
          v10 = ipa3_get_ipc_logbuf_low(v8);
          if ( v10 )
          {
            v11 = ipa3_get_ipc_logbuf_low(v10);
            ipc_log_string(v11, "ipa-lnx-stats %s:%d ipa get wlan inst stats fail", "ipa_lnx_stats_ioctl", 1778);
          }
        }
        goto LABEL_157;
      }
      goto LABEL_80;
    }
    goto LABEL_46;
  }
  if ( a2 <= -1064799744 )
  {
    if ( a2 == -1073188346 )
    {
LABEL_156:
      eth_inst_stats = 0;
      goto LABEL_157;
    }
    if ( a2 == -1072139774 )
    {
      eth_inst_stats = ipa_get_clock_stats(a3);
      if ( eth_inst_stats )
      {
        v12 = printk(&unk_3A4143, "ipa_lnx_stats_ioctl");
        v13 = ipa3_get_ipc_logbuf(v12);
        if ( v13 )
        {
          v14 = ipa3_get_ipc_logbuf(v13);
          v13 = ipc_log_string(v14, "ipa-lnx-stats %s:%d ipa get clock stats fail", "ipa_lnx_stats_ioctl", 1773);
        }
        v15 = ipa3_get_ipc_logbuf_low(v13);
        if ( v15 )
        {
          v16 = ipa3_get_ipc_logbuf_low(v15);
          ipc_log_string(v16, "ipa-lnx-stats %s:%d ipa get clock stats fail", "ipa_lnx_stats_ioctl", 1773);
        }
      }
      goto LABEL_157;
    }
LABEL_80:
    eth_inst_stats = -25;
LABEL_157:
    mutex_unlock(&ipa_lnx_ctx_mutex);
    return eth_inst_stats;
  }
  if ( a2 == -1064799743 )
  {
    eth_inst_stats = ipa_get_generic_stats(a3);
    if ( eth_inst_stats )
    {
      v68 = printk(&unk_3B01D8, "ipa_lnx_stats_ioctl");
      v69 = ipa3_get_ipc_logbuf(v68);
      if ( v69 )
      {
        v70 = ipa3_get_ipc_logbuf(v69);
        v69 = ipc_log_string(v70, "ipa-lnx-stats %s:%d ipa get generic stats fail", "ipa_lnx_stats_ioctl", 1768);
      }
      v71 = ipa3_get_ipc_logbuf_low(v69);
      if ( v71 )
      {
        v72 = ipa3_get_ipc_logbuf_low(v71);
        ipc_log_string(v72, "ipa-lnx-stats %s:%d ipa get generic stats fail", "ipa_lnx_stats_ioctl", 1768);
      }
    }
    goto LABEL_157;
  }
  if ( a2 != -1037274624 )
    goto LABEL_80;
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v23 = a3, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
    v23 = a3 & (a3 << 8 >> 8);
  if ( v23 >= 0x7FFFFFFDD5LL )
  {
    v31 = 556;
    goto LABEL_170;
  }
  v194 = a3 << 8;
  v24 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v30 = *(_QWORD *)(StatusReg + 8);
  _WriteStatusReg(TTBR1_EL1, v30 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
  _WriteStatusReg(TTBR0_EL1, v30);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v24);
  v195 = StatusReg;
  v31 = _arch_copy_from_user(ipa_lnx_agent_ctx, a3 & 0xFF7FFFFFFFFFFFFFLL, 556);
  v32 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v34 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
  _WriteStatusReg(TTBR0_EL1, v34 - 4096);
  _WriteStatusReg(TTBR1_EL1, v34);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v32);
  if ( v31 )
  {
LABEL_170:
    if ( v31 >= 0x22D )
    {
LABEL_215:
      v193 = _fortify_panic(15, 0, v31);
      return ipa_stats_ioctl_open(v193);
    }
    memset(ipa_lnx_agent_ctx, 0, 0x22Cu);
    v143 = printk(&unk_3C7866, "ipa_stats_get_alloc_info");
    v144 = ipa3_get_ipc_logbuf(v143);
    if ( v144 )
    {
      v145 = ipa3_get_ipc_logbuf(v144);
      v144 = ipc_log_string(v145, "ipa-lnx-stats %s:%d copy from user failed", "ipa_stats_get_alloc_info", 1514);
    }
    v146 = ipa3_get_ipc_logbuf_low(v144);
    if ( v146 )
    {
      v147 = ipa3_get_ipc_logbuf_low(v146);
      ipc_log_string(v147, "ipa-lnx-stats %s:%d copy from user failed", "ipa_stats_get_alloc_info", 1514);
    }
LABEL_175:
    v148 = printk(&unk_3AD5A3, "ipa_lnx_stats_ioctl");
    v149 = ipa3_get_ipc_logbuf(v148);
    if ( v149 )
    {
      v150 = ipa3_get_ipc_logbuf(v149);
      v149 = ipc_log_string(v150, "ipa-lnx-stats %s:%d ipa get alloc info fail", "ipa_lnx_stats_ioctl", 1763);
    }
    v151 = ipa3_get_ipc_logbuf_low(v149);
    if ( v151 )
    {
      v152 = ipa3_get_ipc_logbuf_low(v151);
      ipc_log_string(v152, "ipa-lnx-stats %s:%d ipa get alloc info fail", "ipa_lnx_stats_ioctl", 1763);
    }
    eth_inst_stats = -14;
    goto LABEL_157;
  }
  v196 = a3;
  v35 = dword_2011F8;
  if ( (dword_2011F8 & 1) != 0 )
  {
    v36 = 0;
    a3 = 0;
    do
    {
      ep_mapping = ipa_get_ep_mapping(v36);
      if ( (_DWORD)ep_mapping != -1 && (v36 & 0xF9) != 0x41 && v36 != 63 && (v36 & 1) != 0 )
      {
        v39 = ep_mapping;
        ep_reg_idx = ipahal_get_ep_reg_idx(ep_mapping);
        v41 = *(_QWORD *)(ipa3_ctx + 43800);
        if ( v41 )
        {
          if ( ep_reg_idx >= 2 )
            goto LABEL_45;
          v37 = *(_DWORD *)(v41 + 4LL * ep_reg_idx + 63896);
          if ( ((unsigned int)ipahal_get_ep_bit(v39) & v37) != 0 )
            a3 = (unsigned int)(a3 + 1);
          else
            a3 = (unsigned int)a3;
        }
      }
      ++v36;
    }
    while ( v36 != 134 );
    v84 = *(_DWORD *)(ipa3_ctx + 34912);
    v35 = dword_2011F8;
    dword_2011FC = a3;
    dword_201200 = v84;
    a3 = v196;
  }
  if ( (v35 & 2) != 0 )
  {
    max_num_pipes = ipa3_get_max_num_pipes();
    v35 = dword_2011F8;
    dword_201204 = max_num_pipes;
  }
  if ( (v35 & 4) == 0 )
    goto LABEL_104;
  v86 = ipa_get_ep_mapping(13);
  v87 = ipa_get_ep_mapping(12);
  if ( v86 == -1 || v87 == -1 )
    goto LABEL_103;
  if ( v86 <= 0x23 )
  {
    a3 = v196;
    if ( !*(_DWORD *)(ipa3_ctx + 168 + 480LL * v86) )
      goto LABEL_103;
    if ( v87 <= 0x23 )
    {
      a3 = v196;
      if ( *(_DWORD *)(ipa3_ctx + 168 + 480LL * v87) )
      {
        dword_201208 = 1;
        dword_201254 = 1;
        qword_20124C = 0x100000002LL;
        qword_20121C = 0xC0000000DLL;
        dword_201234 = 13;
        dword_201240 = 12;
        if ( (ipa_wdi_is_tx1_used() & 1) != 0 )
        {
          dword_201224 = 119;
          dword_201238 = 119;
          LODWORD(qword_20124C) = qword_20124C + 1;
          ++HIDWORD(qword_20124C);
        }
        goto LABEL_104;
      }
LABEL_103:
      dword_201208 = 0;
LABEL_104:
      v88 = dword_2011F8;
      if ( (dword_2011F8 & 8) != 0 )
      {
        v89 = 0;
        v90 = 1;
        a3 = 172;
        dword_20120C = 0;
        while ( 2 )
        {
          v91 = 0;
          v92 = (char *)&ipa_lnx_agent_ctx[16 * v89];
          v93 = 0;
          v197 = v90;
          *(_QWORD *)(v92 + 220) = 0;
          *((_DWORD *)v92 + 57) = 0;
          do
          {
            if ( (ipa_eth_client_exist(v91, (unsigned int)v89, v31) & 1) != 0 && (unsigned int)dword_20120C <= 1 )
            {
              v94 = (unsigned __int64)(unsigned int)dword_20120C << 6;
              v95 = (_DWORD *)((char *)ipa_lnx_agent_ctx + v94);
              v96 = *(_DWORD *)((char *)&ipa_lnx_agent_ctx[57] + v94);
              v97 = *(_DWORD *)((char *)&ipa_lnx_agent_ctx[56] + v94) + 1;
              v95[55] += 2;
              v95[56] = v97;
              v95[57] = v96 + 1;
              if ( v93 > 2 )
                goto LABEL_45;
              if ( v94 + 4 * v93 + 196 > 0x22C )
                goto LABEL_214;
              v98 = v95 + 43;
              v95[v93 + 49] = v91;
              ipa_client_type_from_eth_type = ipa_eth_get_ipa_client_type_from_eth_type(v91, 0);
              if ( ipa_client_type_from_eth_type >= 134 )
              {
                v103 = ipa_client_type_from_eth_type;
                v104 = printk(&unk_3B5737, "ipa_stats_get_alloc_info");
                v105 = ipa3_get_ipc_logbuf(v104);
                if ( v105 )
                {
                  v106 = ipa3_get_ipc_logbuf(v105);
                  v105 = ipc_log_string(
                           v106,
                           "ipa-lnx-stats %s:%d Eth tx client type not found",
                           "ipa_stats_get_alloc_info",
                           1608);
                }
                v107 = ipa3_get_ipc_logbuf_low(v105);
                ipa_client_type_from_eth_type = v103;
                if ( v107 )
                {
                  v108 = ipa3_get_ipc_logbuf_low(v103);
                  ipc_log_string(
                    v108,
                    "ipa-lnx-stats %s:%d Eth tx client type not found",
                    "ipa_stats_get_alloc_info",
                    1608);
                  ipa_client_type_from_eth_type = v103;
                }
              }
              v100 = v94 | 0xAC;
              if ( v100 + 8 * v93 > 0x22C )
                goto LABEL_214;
              v4 = 2 * v93;
              v98[2 * v93] = ipa_client_type_from_eth_type;
              v101 = ipa_eth_get_ipa_client_type_from_eth_type(v91, 1);
              if ( v101 >= 134 )
              {
                v109 = v101;
                v110 = printk(&unk_3E6DB1, "ipa_stats_get_alloc_info");
                v111 = ipa3_get_ipc_logbuf(v110);
                if ( v111 )
                {
                  v112 = ipa3_get_ipc_logbuf(v111);
                  v111 = ipc_log_string(
                           v112,
                           "ipa-lnx-stats %s:%d Eth rx client type not found",
                           "ipa_stats_get_alloc_info",
                           1620);
                }
                v113 = ipa3_get_ipc_logbuf_low(v111);
                v101 = v109;
                a3 = 172;
                if ( v113 )
                {
                  v114 = ipa3_get_ipc_logbuf_low(v109);
                  ipc_log_string(
                    v114,
                    "ipa-lnx-stats %s:%d Eth rx client type not found",
                    "ipa_stats_get_alloc_info",
                    1620);
                  v101 = v109;
                }
              }
              if ( v100 + 4 * (v4 | 1uLL) > 0x22C )
              {
LABEL_214:
                __break(1u);
                goto LABEL_215;
              }
              v102 = dword_20120C;
              v98[v4 | 1] = v101;
              ++v93;
              dword_20120C = v102 + 1;
            }
            if ( v91 > 4 )
              break;
            ++v91;
          }
          while ( (int)v93 < 3 );
          v90 = 0;
          v89 = 1;
          if ( (v197 & 1) != 0 )
            continue;
          break;
        }
        a3 = v196;
        v88 = dword_2011F8;
      }
      if ( (v88 & 0x10) != 0 )
      {
        v115 = 0;
        a3 = 0;
        v4 = 0x100000002LL;
        dword_201210 = 0;
        do
        {
          if ( (((__int64 (__fastcall *)(_QWORD))ipa_usb_is_teth_prot_connected)(v115) & 1) != 0 )
          {
            if ( (unsigned int)a3 > 1 )
              goto LABEL_45;
            v116 = (int)a3;
            ipa_lnx_agent_ctx[(int)a3] = v115;
            if ( v115 != 4 )
            {
              v117 = (__int64)(int)a3 << 6;
              v118 = (char *)ipa_lnx_agent_ctx + v117;
              v119 = v117 | 0x12C;
              v120 = (_DWORD *)((char *)&ipa_lnx_agent_ctx[75] + v117);
              if ( v115 == 5 )
              {
                *(_QWORD *)(v118 + 348) = 0x100000002LL;
                *((_DWORD *)v118 + 89) = 1;
                if ( v119 > 0x22C )
                  goto LABEL_214;
                if ( (v117 | 0x12CuLL) > 0x22C )
                  goto LABEL_214;
                *v120 = 20;
                if ( (v117 | 0x130uLL) > 0x22C )
                  goto LABEL_214;
                v121 = 20;
                v122 = 21;
              }
              else
              {
                *(_QWORD *)(v118 + 348) = 0x100000002LL;
                *((_DWORD *)v118 + 89) = 1;
                if ( v119 > 0x22C )
                  goto LABEL_214;
                if ( (v117 | 0x12CuLL) > 0x22C )
                  goto LABEL_214;
                *v120 = 18;
                if ( (v117 | 0x130uLL) > 0x22C )
                  goto LABEL_214;
                v121 = 18;
                v122 = 19;
              }
              a3 = (unsigned int)(a3 + 1);
              v123 = &ipa_lnx_agent_ctx[16 * v116];
              v124 = dword_201210;
              v123[76] = v122;
              v123[81] = v122;
              v123[84] = v121;
              dword_201210 = v124 + 1;
            }
          }
          if ( v115 > 4 )
            break;
          ++v115;
        }
        while ( (int)a3 < 2 );
        a3 = v196;
        v88 = dword_2011F8;
      }
      if ( (v88 & 0x20) != 0 )
        dword_201214 = 0;
      if ( (v88 & 0x40) != 0 )
        dword_201218 = 5;
      if ( (*(_BYTE *)(v195 + 70) & 0x20) != 0 || (v125 = a3, (*(_QWORD *)v195 & 0x4000000) != 0) )
        v125 = a3 & (v194 >> 8);
      if ( v125 <= 0x7FFFFFFDD4LL )
      {
        v126 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v128 = *(_QWORD *)(v195 + 8);
        _WriteStatusReg(TTBR1_EL1, v128 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
        _WriteStatusReg(TTBR0_EL1, v128);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v126);
        v129 = _arch_copy_to_user(a3 & 0xFF7FFFFFFFFFFFFFLL, ipa_lnx_agent_ctx, 556);
        v130 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v132 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
        _WriteStatusReg(TTBR0_EL1, v132 - 4096);
        _WriteStatusReg(TTBR1_EL1, v132);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v130);
        if ( !v129 )
          goto LABEL_156;
      }
      v133 = printk(&unk_3B576A, "ipa_stats_get_alloc_info");
      v134 = ipa3_get_ipc_logbuf(v133);
      if ( v134 )
      {
        v135 = ipa3_get_ipc_logbuf(v134);
        v134 = ipc_log_string(v135, "ipa-lnx-stats %s:%d copy to user failed", "ipa_stats_get_alloc_info", 1735);
      }
      v136 = ipa3_get_ipc_logbuf_low(v134);
      if ( v136 )
      {
        v137 = ipa3_get_ipc_logbuf_low(v136);
        ipc_log_string(v137, "ipa-lnx-stats %s:%d copy to user failed", "ipa_stats_get_alloc_info", 1735);
      }
      goto LABEL_175;
    }
  }
LABEL_45:
  __break(0x5512u);
LABEL_46:
  v42 = (__int64 *)memdup_user(a3, 64);
  if ( (unsigned __int64)v42 < 0xFFFFFFFFFFFFF001LL )
  {
    v43 = *v42;
    v44 = v42;
    if ( (*v42 & 1) != 0 )
    {
      generic_stats = ipa_get_generic_stats(v42[1]);
      if ( generic_stats )
      {
        eth_inst_stats = generic_stats;
        v158 = printk(&unk_3B01D8, "ipa_lnx_stats_ioctl");
        v159 = ipa3_get_ipc_logbuf(v158);
        if ( v159 )
        {
          v160 = ipa3_get_ipc_logbuf(v159);
          v159 = ipc_log_string(v160, "ipa-lnx-stats %s:%d ipa get generic stats fail", "ipa_lnx_stats_ioctl", 1811);
        }
        v161 = ipa3_get_ipc_logbuf_low(v159);
        if ( v161 )
        {
          v162 = ipa3_get_ipc_logbuf_low(v161);
          ipc_log_string(v162, "ipa-lnx-stats %s:%d ipa get generic stats fail", "ipa_lnx_stats_ioctl", 1811);
        }
        goto LABEL_157;
      }
      v43 = *v44;
    }
    if ( (v43 & 2) != 0 )
    {
      clock_stats = ipa_get_clock_stats(v44[2]);
      if ( clock_stats )
      {
        eth_inst_stats = clock_stats;
        v163 = printk(&unk_3A4143, "ipa_lnx_stats_ioctl");
        v164 = ipa3_get_ipc_logbuf(v163);
        if ( v164 )
        {
          v165 = ipa3_get_ipc_logbuf(v164);
          v164 = ipc_log_string(v165, "ipa-lnx-stats %s:%d ipa get clock stats fail", "ipa_lnx_stats_ioctl", 1818);
        }
        v166 = ipa3_get_ipc_logbuf_low(v164);
        if ( v166 )
        {
          v167 = ipa3_get_ipc_logbuf_low(v166);
          ipc_log_string(v167, "ipa-lnx-stats %s:%d ipa get clock stats fail", "ipa_lnx_stats_ioctl", 1818);
        }
        goto LABEL_157;
      }
      v43 = *v44;
    }
    if ( (v43 & 4) != 0 )
    {
      wlan_inst_stats = ipa_get_wlan_inst_stats(v44[3]);
      if ( wlan_inst_stats )
      {
        eth_inst_stats = wlan_inst_stats;
        v168 = printk(&unk_3C155A, "ipa_lnx_stats_ioctl");
        v169 = ipa3_get_ipc_logbuf(v168);
        if ( v169 )
        {
          v170 = ipa3_get_ipc_logbuf(v169);
          v169 = ipc_log_string(v170, "ipa-lnx-stats %s:%d ipa get wlan inst stats fail", "ipa_lnx_stats_ioctl", 1825);
        }
        v171 = ipa3_get_ipc_logbuf_low(v169);
        if ( v171 )
        {
          v172 = ipa3_get_ipc_logbuf_low(v171);
          ipc_log_string(v172, "ipa-lnx-stats %s:%d ipa get wlan inst stats fail", "ipa_lnx_stats_ioctl", 1825);
        }
        goto LABEL_157;
      }
      v43 = *v44;
    }
    if ( (v43 & 8) != 0 )
    {
      v48 = ipa_get_eth_inst_stats(v44[4]);
      if ( v48 )
      {
        eth_inst_stats = v48;
        v173 = printk(&unk_3D8CDC, "ipa_lnx_stats_ioctl");
        v174 = ipa3_get_ipc_logbuf(v173);
        if ( v174 )
        {
          v175 = ipa3_get_ipc_logbuf(v174);
          v174 = ipc_log_string(v175, "ipa-lnx-stats %s:%d ipa get eth inst stats fail", "ipa_lnx_stats_ioctl", 1832);
        }
        v176 = ipa3_get_ipc_logbuf_low(v174);
        if ( v176 )
        {
          v177 = ipa3_get_ipc_logbuf_low(v176);
          ipc_log_string(v177, "ipa-lnx-stats %s:%d ipa get eth inst stats fail", "ipa_lnx_stats_ioctl", 1832);
        }
        goto LABEL_157;
      }
      v43 = *v44;
    }
    if ( (v43 & 0x10) != 0 )
    {
      usb_inst_stats = ipa_get_usb_inst_stats(v44[5]);
      if ( usb_inst_stats )
      {
        eth_inst_stats = usb_inst_stats;
        v178 = printk(&unk_3EF89B, "ipa_lnx_stats_ioctl");
        v179 = ipa3_get_ipc_logbuf(v178);
        if ( v179 )
        {
          v180 = ipa3_get_ipc_logbuf(v179);
          v179 = ipc_log_string(v180, "ipa-lnx-stats %s:%d ipa get usb inst stats fail", "ipa_lnx_stats_ioctl", 1839);
        }
        v181 = ipa3_get_ipc_logbuf_low(v179);
        if ( v181 )
        {
          v182 = ipa3_get_ipc_logbuf_low(v181);
          ipc_log_string(v182, "ipa-lnx-stats %s:%d ipa get usb inst stats fail", "ipa_lnx_stats_ioctl", 1839);
        }
        goto LABEL_157;
      }
      v43 = *v44;
    }
    if ( (v43 & 0x40) == 0 )
      goto LABEL_156;
    v50 = v44[7];
    v51 = memdup_user(v50, 864);
    if ( v51 >= 0xFFFFFFFFFFFFF001LL )
    {
      v183 = printk(&unk_3C7866, "ipa_get_page_recycle_stats");
      v184 = ipa3_get_ipc_logbuf(v183);
      if ( v184 )
      {
        v185 = ipa3_get_ipc_logbuf(v184);
        v184 = ipc_log_string(v185, "ipa-lnx-stats %s:%d copy from user failed", "ipa_get_page_recycle_stats", 1474);
      }
      v186 = ipa3_get_ipc_logbuf_low(v184);
      if ( v186 )
      {
        v187 = ipa3_get_ipc_logbuf_low(v186);
        ipc_log_string(v187, "ipa-lnx-stats %s:%d copy from user failed", "ipa_get_page_recycle_stats", 1474);
      }
      eth_inst_stats = -12;
    }
    else
    {
      v52 = (void *)v51;
      mutex_lock(*(_QWORD *)(v4 + 2056) + 52392LL);
      memcpy(v52, (const void *)(*(_QWORD *)(v4 + 2056) + 51456LL), 0x360u);
      v53 = *(_QWORD *)(v4 + 2056);
      memset((void *)(v53 + 51456), 0, 0x360u);
      mutex_unlock(v53 + 52392);
      v54 = _ReadStatusReg(SP_EL0);
      if ( (*(_BYTE *)(v54 + 70) & 0x20) != 0 || (v55 = v50, (*(_QWORD *)v54 & 0x4000000) != 0) )
        v55 = v50 & ((__int64)(v50 << 8) >> 8);
      if ( v55 <= 0x7FFFFFFCA0LL )
      {
        v56 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v58 = *(_QWORD *)(v54 + 8);
        _WriteStatusReg(TTBR1_EL1, v58 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
        _WriteStatusReg(TTBR0_EL1, v58);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v56);
        v59 = _arch_copy_to_user(v50 & 0xFF7FFFFFFFFFFFFFLL, v52, 864);
        v60 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v62 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
        _WriteStatusReg(TTBR0_EL1, v62 - 4096);
        _WriteStatusReg(TTBR1_EL1, v62);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v60);
        if ( !v59 )
        {
          kfree(v52);
          goto LABEL_156;
        }
      }
      v153 = printk(&unk_3B576A, "ipa_get_page_recycle_stats");
      v154 = ipa3_get_ipc_logbuf(v153);
      if ( v154 )
      {
        v155 = ipa3_get_ipc_logbuf(v154);
        v154 = ipc_log_string(v155, "ipa-lnx-stats %s:%d copy to user failed", "ipa_get_page_recycle_stats", 1491);
      }
      v156 = ipa3_get_ipc_logbuf_low(v154);
      if ( v156 )
      {
        v157 = ipa3_get_ipc_logbuf_low(v156);
        ipc_log_string(v157, "ipa-lnx-stats %s:%d copy to user failed", "ipa_get_page_recycle_stats", 1491);
      }
      kfree(v52);
      eth_inst_stats = -14;
    }
    v188 = printk(&unk_3DECB8, "ipa_lnx_stats_ioctl");
    v189 = ipa3_get_ipc_logbuf(v188);
    if ( v189 )
    {
      v190 = ipa3_get_ipc_logbuf(v189);
      v189 = ipc_log_string(v190, "ipa-lnx-stats %s:%d ipa get page recycle stats fail\n", "ipa_lnx_stats_ioctl", 1855);
    }
    v191 = ipa3_get_ipc_logbuf_low(v189);
    if ( v191 )
    {
      v192 = ipa3_get_ipc_logbuf_low(v191);
      ipc_log_string(v192, "ipa-lnx-stats %s:%d ipa get page recycle stats fail\n", "ipa_lnx_stats_ioctl", 1855);
    }
    goto LABEL_157;
  }
  v138 = printk(&unk_3C7866, "ipa_lnx_stats_ioctl");
  v139 = ipa3_get_ipc_logbuf(v138);
  if ( v139 )
  {
    v140 = ipa3_get_ipc_logbuf(v139);
    v139 = ipc_log_string(v140, "ipa-lnx-stats %s:%d copy from user failed", "ipa_lnx_stats_ioctl", 1803);
  }
  v141 = ipa3_get_ipc_logbuf_low(v139);
  if ( v141 )
  {
    v142 = ipa3_get_ipc_logbuf_low(v141);
    ipc_log_string(v142, "ipa-lnx-stats %s:%d copy from user failed", "ipa_lnx_stats_ioctl", 1803);
  }
  mutex_unlock(&ipa_lnx_ctx_mutex);
  return -12;
}
