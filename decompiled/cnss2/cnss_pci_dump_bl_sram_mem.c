__int64 __fastcall cnss_pci_dump_bl_sram_mem(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  unsigned int v9; // w22
  int v10; // w20
  __int64 result; // x0
  __int64 v12; // x1
  __int64 v13; // x2
  __int64 v14; // x3
  __int64 v15; // x4
  __int64 v16; // x5
  __int64 v17; // x6
  __int64 v18; // x7
  int v19; // w8
  int v20; // w26
  unsigned int v21; // w25
  unsigned int v22; // w21
  __int64 v23; // x3
  __int64 v24; // x4
  __int64 v25; // x5
  __int64 v26; // x6
  __int64 v27; // x7
  __int64 v28; // x7
  unsigned __int64 StatusReg; // x21
  const char *v30; // x1
  __int64 v31; // x3
  __int64 v32; // x4
  __int64 v33; // x5
  __int64 v34; // x6
  __int64 v35; // x7
  __int64 v36; // x3
  __int64 v37; // x4
  __int64 v38; // x5
  __int64 v39; // x6
  __int64 v40; // x7
  __int64 v41; // x3
  __int64 v42; // x4
  __int64 v43; // x5
  __int64 v44; // x6
  __int64 v45; // x7
  __int64 v46; // x3
  __int64 v47; // x4
  __int64 v48; // x5
  __int64 v49; // x6
  __int64 v50; // x7
  __int64 v51; // x3
  __int64 v52; // x4
  __int64 v53; // x5
  __int64 v54; // x6
  __int64 v55; // x7
  unsigned __int64 v56; // x27
  const char *v57; // x1
  unsigned int v58; // w22
  unsigned int v59; // w24
  const char *v60; // x1
  __int64 v61; // x3
  __int64 v62; // x4
  __int64 v63; // x5
  __int64 v64; // x6
  __int64 v65; // x7
  __int64 v66; // x3
  __int64 v67; // x4
  __int64 v68; // x5
  __int64 v69; // x6
  __int64 v70; // x7
  const char *v71; // x1
  unsigned int exec_env; // w0
  __int64 v73; // x6
  __int64 v74; // x7
  __int64 v75; // x0
  const char *v76; // x1
  const char *v77; // x5
  const char *v78; // x1
  __int64 v79; // x3
  __int64 v80; // x4
  __int64 v81; // x5
  unsigned int i; // w26
  const char *v83; // x1
  unsigned int v84; // w20
  unsigned int v85; // w0
  unsigned int v86; // w20
  __int64 v87; // x3
  __int64 v88; // x4
  __int64 v89; // x5
  __int64 v90; // x6
  __int64 v91; // x7
  __int64 v92; // x3
  __int64 v93; // x4
  __int64 v94; // x5
  __int64 v95; // x7
  __int64 v96; // x3
  __int64 v97; // x4
  __int64 v98; // x5
  __int64 v99; // x6
  __int64 v100; // x7
  __int64 v101; // x7
  const char *v102; // x1
  const char *v103; // x1
  __int64 v104; // x7
  const char *v105; // x1
  char v106; // [xsp+0h] [xbp-50h]
  char v107; // [xsp+0h] [xbp-50h]
  char v108; // [xsp+0h] [xbp-50h]
  char v109; // [xsp+0h] [xbp-50h]
  char v110; // [xsp+0h] [xbp-50h]
  unsigned int v111; // [xsp+18h] [xbp-38h]
  __int64 v112; // [xsp+20h] [xbp-30h] BYREF
  unsigned int v113; // [xsp+28h] [xbp-28h] BYREF
  __int64 v114; // [xsp+2Ch] [xbp-24h] BYREF
  __int64 v115; // [xsp+34h] [xbp-1Ch] BYREF
  unsigned int v116; // [xsp+3Ch] [xbp-14h] BYREF
  _QWORD v117[2]; // [xsp+40h] [xbp-10h] BYREF

  v9 = 27328520;
  v10 = 20987288;
  v117[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v116 = 0;
  result = cnss_pci_soc_reset_cause_reg_dump(a1, a2, a3, a4, a5, a6, a7, a8);
  v19 = *(_DWORD *)(a1 + 24);
  if ( v19 <= 4361 )
  {
    switch ( v19 )
    {
      case 4353:
        v10 = 20987224;
        v21 = 25165824;
        v20 = 44;
        v22 = 80;
        break;
      case 4355:
        v10 = 20987296;
        v21 = 25165824;
        v20 = 48;
        v22 = 40;
        break;
      case 4359:
LABEL_9:
        v21 = 25165824;
        v20 = 48;
        v22 = 40;
        goto LABEL_19;
      default:
        goto LABEL_46;
    }
    v9 = 26279944;
  }
  else
  {
    if ( v19 <= 4368 )
    {
      if ( v19 != 4362 )
      {
        if ( v19 != 4366 )
          goto LABEL_46;
        v10 = 20985408;
        v20 = 4096;
        v21 = 25591808;
        v22 = 40;
        goto LABEL_19;
      }
      goto LABEL_9;
    }
    if ( v19 == 4369 )
    {
      result = cnss_pci_check_link_status(a1, v12, v13, v14, v15, v16, v17, v18);
      if ( (_DWORD)result )
        goto LABEL_46;
      HIDWORD(v117[0]) = 0;
      cnss_pci_reg_read((_QWORD *)a1, 28312584, (_DWORD *)v117 + 1, v23, v24, v25, v26, v27);
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
      {
        v30 = "irq";
      }
      else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        v30 = "soft_irq";
      }
      else
      {
        v30 = (const char *)(StatusReg + 2320);
      }
      v86 = HIDWORD(v117[0]);
      LODWORD(v117[0]) = 0;
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v30,
        "cnss_pci_fetch_pbl_base_size",
        7u,
        7u,
        "spare_reg2= %d\n",
        HIDWORD(v117[0]),
        v28,
        v106);
      cnss_pci_reg_read((_QWORD *)a1, v86, v117, v87, v88, v89, v90, v91);
      if ( LODWORD(v117[0]) != -1430532899 )
      {
        if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
        {
          v103 = "irq";
        }
        else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
        {
          v103 = "soft_irq";
        }
        else
        {
          v103 = (const char *)(StatusReg + 2320);
        }
        result = cnss_debug_ipc_log_print(
                   cnss_ipc_log_context,
                   v103,
                   "cnss_pci_fetch_pbl_base_size",
                   3u,
                   3u,
                   "Memory corrupted, invalid magic number: 0x%x\n",
                   LODWORD(v117[0]),
                   v95,
                   v109);
        goto LABEL_46;
      }
      v115 = 0;
      cnss_pci_reg_read((_QWORD *)a1, v86 + 8, &v115, v92, v93, v94, 2864434397LL, v95);
      cnss_pci_reg_read((_QWORD *)a1, v86 + 4, (_DWORD *)&v115 + 1, v96, v97, v98, v99, v100);
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
      {
        v102 = "irq";
      }
      else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        v102 = "soft_irq";
      }
      else
      {
        v102 = (const char *)(StatusReg + 2320);
      }
      v10 = v115;
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v102,
        "cnss_pci_fetch_pbl_base_size",
        7u,
        7u,
        "pbl_log_sram_start= %d\n",
        (unsigned int)v115,
        v101,
        v109);
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
      {
        v105 = "irq";
      }
      else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        v105 = "soft_irq";
      }
      else
      {
        v105 = (const char *)(StatusReg + 2320);
      }
      v22 = HIDWORD(v115);
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v105,
        "cnss_pci_fetch_pbl_base_size",
        7u,
        7u,
        "pbl_log_max_size= %d\n",
        HIDWORD(v115),
        v104,
        v110);
      v21 = 25165824;
      v20 = 4096;
    }
    else
    {
      if ( v19 != 4370 )
        goto LABEL_46;
      v9 = 27807752;
      v21 = 26214400;
      v20 = 4096;
      v22 = 40;
      v10 = 21019224;
    }
  }
LABEL_19:
  result = cnss_pci_check_link_status(a1, v12, v13, v14, v15, v16, v17, v18);
  if ( !(_DWORD)result )
  {
    v117[0] = 0;
    v114 = 0;
    v113 = 0;
    cnss_pci_reg_read((_QWORD *)a1, 28311800, (_DWORD *)v117 + 1, v31, v32, v33, v34, v35);
    cnss_pci_reg_read((_QWORD *)a1, 31515192, v117, v36, v37, v38, v39, v40);
    cnss_pci_reg_read((_QWORD *)a1, 31515196, (_DWORD *)&v114 + 1, v41, v42, v43, v44, v45);
    cnss_pci_reg_read((_QWORD *)a1, 31599412, &v114, v46, v47, v48, v49, v50);
    cnss_pci_reg_read((_QWORD *)a1, v9, &v113, v51, v52, v53, v54, v55);
    v56 = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(v56 + 16) & 0xF0000) != 0 )
    {
      v57 = "irq";
    }
    else if ( (*(_DWORD *)(v56 + 16) & 0xFF00) != 0 )
    {
      v57 = "soft_irq";
    }
    else
    {
      v57 = (const char *)(v56 + 2320);
    }
    v58 = v117[0];
    v59 = HIDWORD(v114);
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v57,
      "cnss_pci_dump_bl_sram_mem",
      7u,
      7u,
      "TCSR_PBL_LOGGING: 0x%08x PCIE_BHI_ERRDBG: Start: 0x%08x Size:0x%08x\n",
      HIDWORD(v117[0]),
      LODWORD(v117[0]),
      SBYTE4(v114));
    if ( (*(_DWORD *)(v56 + 16) & 0xF0000) != 0 )
    {
      v60 = "irq";
    }
    else if ( (*(_DWORD *)(v56 + 16) & 0xFF00) != 0 )
    {
      v60 = "soft_irq";
    }
    else
    {
      v60 = (const char *)(v56 + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v60,
      "cnss_pci_dump_bl_sram_mem",
      7u,
      7u,
      "PBL_WLAN_BOOT_CFG: 0x%08x PBL_BOOTSTRAP_STATUS: 0x%08x\n",
      (unsigned int)v114,
      v113,
      v107);
    if ( *(_DWORD *)(a1 + 24) == 4369 )
    {
      v112 = 0;
      cnss_pci_reg_read((_QWORD *)a1, 28312584, &v112, v61, v62, v63, v64, v65);
      cnss_pci_reg_read((_QWORD *)a1, 28312588, (_DWORD *)&v112 + 1, v66, v67, v68, v69, v70);
      if ( (*(_DWORD *)(v56 + 16) & 0xF0000) != 0 )
      {
        v71 = "irq";
      }
      else if ( (*(_DWORD *)(v56 + 16) & 0xFF00) != 0 )
      {
        v71 = "soft_irq";
      }
      else
      {
        v71 = (const char *)(v56 + 2320);
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v71,
        "cnss_pci_dump_bl_sram_mem",
        7u,
        7u,
        "TCSR_SPARE_REG2: 0x%08x TCSR_SPARE_REG3: 0x%08x\n",
        (unsigned int)v112,
        HIDWORD(v112),
        v108);
    }
    exec_env = mhi_get_exec_env(*(_QWORD *)(a1 + 344));
    if ( exec_env <= 7 && ((1 << exec_env) & 0x94) != 0 )
    {
      v75 = cnss_ipc_log_context;
      if ( (*(_DWORD *)(v56 + 16) & 0xF0000) != 0 )
      {
        v76 = "irq";
      }
      else if ( (*(_DWORD *)(v56 + 16) & 0xFF00) != 0 )
      {
        v76 = "soft_irq";
      }
      else
      {
        v76 = (const char *)(v56 + 2320);
      }
      v77 = "Avoid Dumping PBL log data in Mission mode\n";
    }
    else
    {
      v111 = v20;
      if ( (*(_DWORD *)(v56 + 16) & 0xF0000) != 0 )
      {
        v78 = "irq";
      }
      else if ( (*(_DWORD *)(v56 + 16) & 0xFF00) != 0 )
      {
        v78 = "soft_irq";
      }
      else
      {
        v78 = (const char *)(v56 + 2320);
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v78,
        "cnss_pci_dump_bl_sram_mem",
        7u,
        7u,
        "Dumping PBL log data\n",
        v73,
        v74,
        v108);
      if ( v22 )
      {
        for ( i = 0; i < v22; i += 4 )
        {
          if ( (unsigned int)cnss_pci_reg_read((_QWORD *)a1, v10 + i, &v116, v79, v80, v81, v73, v74) )
            break;
          v83 = "irq";
          if ( (*(_DWORD *)(v56 + 16) & 0xF0000) == 0 )
          {
            if ( (*(_DWORD *)(v56 + 16) & 0xFF00) != 0 )
              v83 = "soft_irq";
            else
              v83 = (const char *)(v56 + 2320);
          }
          cnss_debug_ipc_log_print(
            cnss_ipc_log_context,
            v83,
            "cnss_pci_dump_bl_sram_mem",
            7u,
            7u,
            "SRAM[0x%x] = 0x%x\n",
            v10 + i,
            v116,
            v108);
        }
      }
      if ( v59 >= v111 )
        v84 = v111;
      else
        v84 = v59;
      if ( v58 >> 22 < 5 || v58 > v21 || v84 + v58 > v21 )
      {
        v75 = cnss_ipc_log_context;
        if ( (*(_DWORD *)(v56 + 16) & 0xF0000) != 0 )
        {
          v76 = "irq";
        }
        else if ( (*(_DWORD *)(v56 + 16) & 0xFF00) != 0 )
        {
          v76 = "soft_irq";
        }
        else
        {
          v76 = (const char *)(v56 + 2320);
        }
        v77 = "Invalid SBL log data\n";
      }
      else
      {
        v85 = mhi_get_exec_env(*(_QWORD *)(a1 + 344));
        if ( v85 > 7 || ((1 << v85) & 0x94) == 0 )
        {
          result = cnss_pci_dump_sbl_log(a1, v58, v84);
          goto LABEL_46;
        }
        v75 = cnss_ipc_log_context;
        if ( (*(_DWORD *)(v56 + 16) & 0xF0000) != 0 )
        {
          v76 = "irq";
        }
        else if ( (*(_DWORD *)(v56 + 16) & 0xFF00) != 0 )
        {
          v76 = "soft_irq";
        }
        else
        {
          v76 = (const char *)(v56 + 2320);
        }
        v77 = "Avoid Dumping SBL log data in Mission mode\n";
      }
    }
    result = cnss_debug_ipc_log_print(v75, v76, "cnss_pci_dump_bl_sram_mem", 3u, 3u, v77, v73, v74, v108);
  }
LABEL_46:
  _ReadStatusReg(SP_EL0);
  return result;
}
