__int64 __fastcall cnss_pci_collect_dump_info(
        __int64 a1,
        char a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v10; // x19
  __int64 v11; // x22
  __int64 v12; // x28
  int v13; // w8
  __int64 v14; // x6
  unsigned int v15; // w9
  unsigned int v16; // w23
  int v17; // w10
  __int64 v18; // x13
  __int64 v19; // x11
  unsigned __int64 v20; // x8
  const char *v21; // x1
  unsigned __int64 v22; // x8
  const char *v23; // x1
  unsigned __int64 v24; // x8
  __int64 v25; // x0
  const char *v26; // x1
  __int64 v27; // x1
  __int64 v28; // x2
  __int64 v29; // x3
  __int64 v30; // x4
  __int64 v31; // x5
  __int64 v32; // x1
  __int64 v33; // x2
  __int64 v34; // x3
  __int64 v35; // x4
  __int64 v36; // x5
  __int64 v37; // x6
  __int64 v38; // x7
  unsigned int v39; // w23
  __int16 v40; // w9
  const char *v41; // x8
  const char *v42; // x5
  unsigned __int64 v43; // x8
  __int16 v44; // w9
  const char *v45; // x8
  __int64 v47; // x1
  __int64 v48; // x2
  __int64 v49; // x3
  __int64 v50; // x4
  __int64 v51; // x5
  __int64 v52; // x6
  __int64 v53; // x7
  unsigned int v54; // w0
  __int16 v55; // w9
  const char *v56; // x8
  __int64 v57; // x1
  __int64 v58; // x2
  __int64 v59; // x3
  __int64 v60; // x4
  __int64 v61; // x5
  __int64 v62; // x6
  __int64 v63; // x7
  __int64 v64; // x1
  __int64 v65; // x2
  __int64 v66; // x3
  __int64 v67; // x4
  __int64 v68; // x5
  __int64 v69; // x6
  __int64 v70; // x7
  unsigned int v71; // w0
  __int64 v72; // x7
  unsigned __int64 v73; // x22
  const char *v74; // x1
  __int64 v75; // x8
  int v76; // w9
  __int64 v77; // x24
  __int64 v78; // x26
  __int64 v79; // x6
  __int64 v80; // x7
  unsigned __int64 v81; // x9
  int v82; // w8
  const char *v83; // x1
  __int64 v84; // x1
  __int64 v85; // x2
  __int64 v86; // x3
  __int64 v87; // x4
  __int64 v88; // x5
  __int64 v89; // x6
  __int64 v90; // x7
  __int64 v91; // x6
  __int64 v92; // x7
  const char *v93; // x1
  __int64 v94; // x1
  __int64 v95; // x2
  __int64 v96; // x3
  __int64 v97; // x4
  __int64 v98; // x5
  __int64 v99; // x6
  __int64 v100; // x7
  __int64 v101; // x7
  const char *v102; // x1
  __int64 v103; // x1
  __int64 v104; // x2
  __int64 v105; // x3
  __int64 v106; // x4
  __int64 v107; // x5
  __int64 v108; // x6
  __int64 v109; // x7
  unsigned __int64 StatusReg; // x8
  const char *v111; // x1
  const char *v112; // x1
  __int16 v113; // w9
  const char *v114; // x8
  __int16 v115; // w8
  const char *v116; // x9
  __int64 v117; // x7
  unsigned int v118; // w8
  unsigned int i; // w23
  __int64 v120; // x0
  const char *v121; // x1
  __int64 v122; // x6
  __int64 v123; // x7
  unsigned int v124; // w8
  unsigned int j; // w23
  int v126; // w10
  int v127; // w8
  unsigned __int64 v128; // x10
  unsigned int v129; // w23
  int v130; // w27
  int v131; // w8
  __int64 *v132; // x24
  int v133; // w8
  const char *v134; // x1
  int v135; // w8
  const char *v136; // x1
  __int64 v137; // x7
  const char *v138; // x1
  __int64 v139; // x8
  __int64 v140; // x0
  __int16 v141; // w9
  const char *v142; // x8
  __int16 v143; // w8
  const char *v144; // x9
  unsigned __int64 v145; // x8
  const char *v146; // x1
  __int16 v147; // w9
  const char *v148; // x8
  unsigned __int64 v155; // x10
  char v156; // [xsp+0h] [xbp-40h]
  char v157; // [xsp+0h] [xbp-40h]
  char v158; // [xsp+0h] [xbp-40h]
  char v159; // [xsp+0h] [xbp-40h]
  char v160; // [xsp+0h] [xbp-40h]
  unsigned __int64 v161; // [xsp+20h] [xbp-20h]
  __int64 v162; // [xsp+28h] [xbp-18h] BYREF
  __int64 v163; // [xsp+30h] [xbp-10h]
  __int64 v164; // [xsp+38h] [xbp-8h]

  v164 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a1 + 8);
  v11 = *(_QWORD *)(v10 + 272);
  v12 = v10 + 1728;
  if ( (*(_QWORD *)(v10 + 552) & 0x800) == 0 )
    goto LABEL_24;
  if ( (*(_QWORD *)(v10 + 552) & 0x40000) != 0 )
    goto LABEL_24;
  if ( v10 == -1728 )
    goto LABEL_24;
  v13 = *(_DWORD *)(v10 + 1720);
  if ( !v13 )
    goto LABEL_24;
  v14 = *(unsigned int *)(a1 + 24);
  v162 = 0;
  v163 = 0;
  v15 = 511616;
  if ( (unsigned int)(v14 - 4354) <= 0x10 )
  {
    if ( ((1 << (v14 - 2)) & 0x19120) != 0 )
    {
      v15 = *(_DWORD *)(v10 + 7756);
      v16 = *(unsigned __int16 *)(v10 + 7752);
      goto LABEL_8;
    }
    if ( (_DWORD)v14 == 4354 )
    {
      v16 = 384;
      goto LABEL_8;
    }
    if ( (_DWORD)v14 == 4355 )
    {
      v16 = *(unsigned __int16 *)(v10 + 7752);
      if ( *(_WORD *)(v10 + 7752) )
      {
        v15 = *(_DWORD *)(v10 + 7756);
      }
      else
      {
        v15 = 2096768;
        v16 = 384;
      }
      goto LABEL_8;
    }
  }
  if ( (_DWORD)v14 != 4353 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v111 = "irq";
    }
    else
    {
      v141 = *(_DWORD *)(StatusReg + 16);
      v142 = (const char *)(StatusReg + 2320);
      if ( (v141 & 0xFF00) != 0 )
        v111 = "soft_irq";
      else
        v111 = v142;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v111,
      "cnss_pci_send_hang_event",
      3u,
      3u,
      "Skip Hang Event Data as unsupported Device ID received: %d\n",
      v14,
      a8,
      v156);
    goto LABEL_24;
  }
  v16 = 384;
  v15 = 3145344;
LABEL_8:
  v17 = 0;
  while ( 1 )
  {
    v18 = v12 + 40LL * v17;
    if ( *(_DWORD *)(v18 + 28) == 1 )
    {
      v19 = *(_QWORD *)(v18 + 8);
      if ( v19 )
        break;
    }
    if ( v13 == ++v17 )
      goto LABEL_23;
  }
  if ( *(_QWORD *)v18 - (unsigned __int64)v16 >= v15 )
  {
    v162 = kmemdup_noprof(v19 + v15);
    if ( v162 )
    {
      LOWORD(v163) = v16;
LABEL_23:
      cnss_pci_call_driver_uevent((__int64 *)a1, 5u, (__int64)&v162, a4, a5, a6, v14, a8);
      kfree(v162);
      goto LABEL_24;
    }
    v145 = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(v145 + 16) & 0xF0000) != 0 )
    {
      v146 = "irq";
    }
    else
    {
      v147 = *(_DWORD *)(v145 + 16);
      v148 = (const char *)(v145 + 2320);
      if ( (v147 & 0xFF00) != 0 )
        v146 = "soft_irq";
      else
        v146 = v148;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v146,
      "cnss_pci_send_hang_event",
      7u,
      7u,
      "Hang data memory alloc failed\n",
      v14,
      a8,
      v156);
  }
  else
  {
    v20 = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(v20 + 16) & 0xF0000) != 0 )
    {
      v21 = "irq";
    }
    else
    {
      v113 = *(_DWORD *)(v20 + 16);
      v114 = (const char *)(v20 + 2320);
      if ( (v113 & 0xFF00) != 0 )
        v21 = "soft_irq";
      else
        v21 = v114;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v21,
      "cnss_pci_send_hang_event",
      7u,
      7u,
      "Invalid hang event params, offset:0x%x, length:0x%x\n",
      *(unsigned int *)(v10 + 7756),
      *(unsigned __int16 *)(v10 + 7752),
      v156);
  }
LABEL_24:
  if ( (*(_QWORD *)(a1 + 352) & 0x400) != 0 )
  {
    v24 = _ReadStatusReg(SP_EL0);
    v25 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(v24 + 16) & 0xF0000) != 0 )
    {
      v26 = "irq";
    }
    else
    {
      v40 = *(_DWORD *)(v24 + 16);
      v41 = (const char *)(v24 + 2320);
      if ( (v40 & 0xFF00) != 0 )
        v26 = "soft_irq";
      else
        v26 = v41;
    }
    v42 = "RAM dump is already collected, skip\n";
    goto LABEL_38;
  }
  if ( (*(_QWORD *)(a1 + 352) & 1) == 0 )
  {
    v22 = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(v22 + 16) & 0xF0000) != 0 )
    {
      v23 = "irq";
    }
    else
    {
      v44 = *(_DWORD *)(v22 + 16);
      v45 = (const char *)(v22 + 2320);
      if ( (v44 & 0xFF00) != 0 )
        v23 = "soft_irq";
      else
        v23 = v45;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v23,
      "cnss_pci_collect_dump_info",
      7u,
      7u,
      "MHI is not initialized, skip\n",
      a7,
      a8,
      v156);
    v39 = -22;
    goto LABEL_46;
  }
  if ( (cnss_is_device_powered_on(v10) & 1) == 0 )
  {
    v43 = _ReadStatusReg(SP_EL0);
    v25 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(v43 + 16) & 0xF0000) != 0 )
    {
      v26 = "irq";
    }
    else
    {
      v55 = *(_DWORD *)(v43 + 16);
      v56 = (const char *)(v43 + 2320);
      if ( (v55 & 0xFF00) != 0 )
        v26 = "soft_irq";
      else
        v26 = v56;
    }
    v42 = "Device is already powered off, skip\n";
LABEL_38:
    cnss_debug_ipc_log_print(v25, v26, "cnss_pci_collect_dump_info", 7u, 7u, v42, a7, a8, v156);
    goto LABEL_39;
  }
  if ( (a2 & 1) != 0 )
  {
    if ( (unsigned int)cnss_pci_check_link_status(a1, v27, v28, v29, v30, v31, a7, a8) )
    {
      v39 = 0;
      goto LABEL_49;
    }
    *(_DWORD *)(*(_QWORD *)(a1 + 344) + 328LL) >>= 1;
    goto LABEL_61;
  }
  mutex_lock(a1 + 600);
  v54 = cnss_pci_check_link_status(a1, v47, v48, v49, v50, v51, v52, v53);
  if ( !v54 )
    goto LABEL_59;
  v39 = v54;
  if ( v54 == -13 )
  {
    if ( (unsigned int)cnss_pci_resume_bus(a1) )
    {
      v39 = -13;
      goto LABEL_54;
    }
LABEL_59:
    mutex_unlock(a1 + 600);
LABEL_61:
    if ( !(unsigned int)cnss_pci_check_link_status(a1, v32, v33, v34, v35, v36, v37, v38) )
      mhi_debug_reg_dump(*(_QWORD *)(a1 + 344));
    cnss_pci_bhi_debug_reg_dump(a1, v57, v58, v59, v60, v61, v62, v63);
    cnss_pci_soc_scratch_reg_dump(a1, v64, v65, v66, v67, v68, v69, v70);
    cnss_pci_dump_misc_reg(a1);
    cnss_rddm_trigger_debug(a1);
    v71 = mhi_download_rddm_image(*(_QWORD *)(a1 + 344), a2 & 1);
    if ( v71 )
    {
      v73 = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(v73 + 16) & 0xF0000) != 0 )
      {
        v74 = "irq";
      }
      else if ( (*(_DWORD *)(v73 + 16) & 0xFF00) != 0 )
      {
        v74 = "soft_irq";
      }
      else
      {
        v74 = (const char *)(v73 + 2320);
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v74,
        "cnss_pci_collect_dump_info",
        3u,
        3u,
        "fatal: Failed to download RDDM image, err = %d\n",
        v71,
        v72,
        v156);
      if ( !(unsigned int)cnss_pci_check_link_status(a1, v84, v85, v86, v87, v88, v89, v90) )
        mhi_debug_reg_dump(*(_QWORD *)(a1 + 344));
      if ( (*(_DWORD *)(v73 + 16) & 0xF0000) != 0 )
      {
        v93 = "irq";
      }
      else if ( (*(_DWORD *)(v73 + 16) & 0xFF00) != 0 )
      {
        v93 = "soft_irq";
      }
      else
      {
        v93 = (const char *)(v73 + 2320);
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v93,
        "cnss_pci_collect_dump_info",
        7u,
        7u,
        "Sending Host Reset Req\n",
        v91,
        v92,
        v157);
      v39 = cnss_pci_check_link_status(a1, v94, v95, v96, v97, v98, v99, v100);
      if ( !v39 )
        v39 = mhi_force_reset(*(_QWORD *)(a1 + 344));
      if ( (*(_DWORD *)(v73 + 16) & 0xF0000) != 0 )
      {
        v102 = "irq";
      }
      else if ( (*(_DWORD *)(v73 + 16) & 0xFF00) != 0 )
      {
        v102 = "soft_irq";
      }
      else
      {
        v102 = (const char *)(v73 + 2320);
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v102,
        "cnss_pci_collect_dump_info",
        7u,
        7u,
        "Host Reset Req ret %d\n",
        v39,
        v101,
        v158);
      if ( !v39 )
      {
        _X8 = (unsigned __int64 *)(v10 + 552);
        __asm { PRFM            #0x11, [X8] }
        do
          v155 = __ldxr(_X8);
        while ( __stxr(v155 & 0xFFFFFFFFFFFFFDFFLL, _X8) );
        _cnss_start_rddm_timer(a1, (__int64)"cnss_pci_collect_dump_info", 0x1CE7u);
        cnss_rddm_trigger_check(a1);
        cnss_pci_dump_debug_reg(a1, v103, v104, v105, v106, v107, v108, v109);
        v39 = -11;
      }
LABEL_46:
      if ( (a2 & 1) != 0 )
        goto LABEL_49;
      goto LABEL_47;
    }
    cnss_rddm_trigger_check(a1);
    v75 = *(_QWORD *)(a1 + 344);
    v76 = *(_DWORD *)(v10 + 4144);
    v78 = *(_QWORD *)(v75 + 152);
    v77 = *(_QWORD *)(v75 + 160);
    *(_DWORD *)(v10 + 336) = 0;
    if ( v76 )
      cnss_pci_dump_qdss_reg(a1);
    mhi_dump_sfr(*(_QWORD *)(a1 + 344));
    v81 = _ReadStatusReg(SP_EL0);
    v82 = *(_DWORD *)(v81 + 16) & 0xF0000;
    if ( v11 )
    {
      v161 = v81;
      if ( v82 )
      {
        v83 = "irq";
      }
      else
      {
        v115 = *(_DWORD *)(v81 + 16);
        v116 = (const char *)(v81 + 2320);
        if ( (v115 & 0xFF00) != 0 )
          v83 = "soft_irq";
        else
          v83 = v116;
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v83,
        "cnss_pci_collect_dump_info",
        7u,
        7u,
        "Collect FW image dump segment, nentries %d\n",
        *(unsigned int *)(v78 + 16),
        v80,
        v156);
      v118 = *(_DWORD *)(v78 + 16);
      if ( v118 )
      {
        for ( i = 0; i < v118; ++i )
        {
          cnss_pci_add_dump_seg(
            a1,
            v11,
            0,
            i,
            *(_QWORD *)(*(_QWORD *)v78 + 32LL * (int)i),
            *(_QWORD *)(*(_QWORD *)v78 + 32LL * (int)i + 16),
            *(_QWORD *)(*(_QWORD *)v78 + 32LL * (int)i + 24));
          v118 = *(_DWORD *)(v78 + 16);
          v11 += 32;
        }
      }
      v120 = cnss_ipc_log_context;
      *(_DWORD *)(v10 + 336) += v118;
      if ( (*(_DWORD *)(v161 + 16) & 0xF0000) != 0 )
      {
        v121 = "irq";
      }
      else if ( (*(_DWORD *)(v161 + 16) & 0xFF00) != 0 )
      {
        v121 = "soft_irq";
      }
      else
      {
        v121 = (const char *)(v161 + 2320);
      }
      cnss_debug_ipc_log_print(
        v120,
        v121,
        "cnss_pci_collect_dump_info",
        7u,
        7u,
        "Collect RDDM image dump segment, nentries %d\n",
        *(unsigned int *)(v77 + 16),
        v117,
        v159);
      v124 = *(_DWORD *)(v77 + 16);
      if ( v124 )
      {
        for ( j = 0; j < v124; ++j )
        {
          cnss_pci_add_dump_seg(
            a1,
            v11,
            1,
            j,
            *(_QWORD *)(*(_QWORD *)v77 + 32LL * (int)j),
            *(_QWORD *)(*(_QWORD *)v77 + 32LL * (int)j + 16),
            *(_QWORD *)(*(_QWORD *)v77 + 32LL * (int)j + 24));
          v124 = *(_DWORD *)(v77 + 16);
          v11 += 32;
        }
      }
      v126 = *(_DWORD *)(v10 + 1720);
      v127 = *(_DWORD *)(v10 + 336) + v124;
      *(_DWORD *)(v10 + 336) = v127;
      if ( v126 )
      {
        v128 = v161;
        v129 = 0;
        v130 = 0;
        while ( 1 )
        {
          v132 = (__int64 *)(v12 + 40LL * v130);
          v133 = *((_DWORD *)v132 + 7);
          if ( v133 == 4 )
          {
            v136 = "irq";
            if ( (*(_DWORD *)(v128 + 16) & 0xF0000) == 0 )
            {
              if ( (*(_DWORD *)(v128 + 16) & 0xFF00) != 0 )
                v136 = "soft_irq";
              else
                v136 = (const char *)(v161 + 2320);
            }
            cnss_debug_ipc_log_print(
              cnss_ipc_log_context,
              v136,
              "cnss_pci_collect_dump_info",
              7u,
              7u,
              "Collect CAL memory dump segment\n",
              v122,
              v123,
              v160);
            v137 = v132[1];
            v138 = "irq";
            v139 = *v132;
            v162 = v132[2];
            *(_QWORD *)v11 = v162;
            *(_QWORD *)(v11 + 8) = v137;
            *(_QWORD *)(v11 + 16) = v139;
            v140 = cnss_ipc_log_context;
            *(_DWORD *)(v11 + 24) = 3;
            if ( (*(_DWORD *)(v161 + 16) & 0xF0000) == 0 )
            {
              if ( (*(_DWORD *)(v161 + 16) & 0xFF00) != 0 )
                v138 = "soft_irq";
              else
                v138 = (const char *)(v161 + 2320);
            }
            cnss_debug_ipc_log_print(
              v140,
              v138,
              "cnss_pci_add_dump_seg",
              7u,
              7u,
              "Seg: %x, va: %pK, dma: %pa, size: 0x%zx\n",
              v129,
              v137,
              (char)&v162);
            v131 = *(_DWORD *)(v10 + 336);
            v128 = v161;
            v11 += 32;
            ++v129;
          }
          else
          {
            if ( v133 != 1 )
              goto LABEL_117;
            v134 = "irq";
            v135 = *(_DWORD *)(v128 + 16) & 0xF0000;
            if ( (v132[4] & 0x40) == 0 )
            {
              if ( !v135 )
              {
                if ( (*(_DWORD *)(v128 + 16) & 0xFF00) != 0 )
                  v134 = "soft_irq";
                else
                  v134 = (const char *)(v161 + 2320);
              }
              cnss_debug_ipc_log_print(
                cnss_ipc_log_context,
                v134,
                "cnss_pci_collect_dump_info",
                7u,
                7u,
                "Skip remote heap dumps as it is non-contiguous\n",
                v122,
                v123,
                v160);
              v128 = v161;
              goto LABEL_117;
            }
            if ( !v135 )
            {
              if ( (*(_DWORD *)(v128 + 16) & 0xFF00) != 0 )
                v134 = "soft_irq";
              else
                v134 = (const char *)(v161 + 2320);
            }
            cnss_debug_ipc_log_print(
              cnss_ipc_log_context,
              v134,
              "cnss_pci_collect_dump_info",
              7u,
              7u,
              "Collect remote heap dump segment\n",
              v122,
              v123,
              v160);
            cnss_pci_add_dump_seg(a1, v11, 2, v129, v132[1], v132[2], *v132);
            v131 = *(_DWORD *)(v10 + 336);
            v128 = v161;
            v11 += 32;
            ++v129;
          }
          *(_DWORD *)(v10 + 336) = v131 + 1;
LABEL_117:
          if ( (unsigned int)++v130 >= *(_DWORD *)(v10 + 1720) )
          {
            v127 = *(_DWORD *)(v10 + 336);
            break;
          }
        }
      }
      if ( v127 >= 1 )
        *(_BYTE *)(v10 + 280) = 1;
      cnss_pci_set_mhi_state(a1, 10);
    }
    else
    {
      if ( v82 )
      {
        v112 = "irq";
      }
      else
      {
        v143 = *(_DWORD *)(v81 + 16);
        v144 = (const char *)(v81 + 2320);
        if ( (v143 & 0xFF00) != 0 )
          v112 = "soft_irq";
        else
          v112 = v144;
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v112,
        "cnss_pci_collect_dump_info",
        4u,
        4u,
        "FW image dump collection not setup",
        v79,
        v80,
        v156);
    }
    complete(v10 + 6616);
LABEL_39:
    v39 = 0;
    goto LABEL_46;
  }
LABEL_54:
  mutex_unlock(a1 + 600);
LABEL_47:
  if ( *(_BYTE *)(v10 + 7958) )
  {
    *(_BYTE *)(v10 + 7958) = 0;
    cnss_genl_send_xdump_bt_over_wl_resp(v39);
  }
LABEL_49:
  _ReadStatusReg(SP_EL0);
  return v39;
}
