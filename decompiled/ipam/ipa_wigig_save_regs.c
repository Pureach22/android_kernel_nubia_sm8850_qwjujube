__int64 ipa_wigig_save_regs()
{
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v2; // x8
  __int64 v3; // x26
  __int64 v4; // x19
  __int64 v5; // x25
  int v6; // w22
  char v7; // w23
  int v8; // w10
  long double v9; // q0
  int v10; // w0
  __int64 v11; // x8
  long double v12; // q0
  __int64 v13; // x0
  long double v14; // q0
  __int64 v15; // x0
  __int64 v16; // x27
  __int64 v17; // x20
  __int64 v18; // x2
  __int64 v19; // x0
  __int64 v20; // x19
  __int64 v21; // x2
  __int64 v22; // x0
  __int64 v23; // x21
  __int64 v24; // x2
  __int64 v25; // x0
  __int64 v26; // x27
  __int64 v27; // x2
  __int64 v28; // x0
  __int64 v29; // x20
  __int64 v30; // x28
  __int64 v31; // x2
  __int64 v32; // x0
  __int64 v33; // x2
  __int64 v34; // x0
  __int64 v35; // x22
  __int64 v36; // x2
  __int64 v37; // x0
  __int64 v38; // x2
  __int64 v39; // x0
  __int64 v40; // x0
  __int64 v41; // x0
  __int64 v42; // x0
  long double v43; // q0
  __int64 v44; // x0
  _BYTE *v45; // x8
  unsigned int v46; // w0
  long double v47; // q0
  __int64 v48; // x8
  __int64 v49; // x2
  __int64 v50; // x0
  __int64 v51; // x19
  __int64 v52; // x2
  __int64 v53; // x0
  __int64 v54; // x20
  __int64 v55; // x0
  long double v56; // q0
  __int64 v57; // x0
  __int64 v58; // x0
  long double v59; // q0
  __int64 v60; // x0
  __int64 v61; // x0
  __int64 v62; // x0
  __int64 v63; // x0
  __int64 v64; // x0
  unsigned int v65; // w20
  __int64 v66; // x0
  __int64 v67; // x0
  __int64 v68; // x0
  __int64 v69; // x0
  __int64 v70; // x0
  __int64 v71; // x0
  __int64 v72; // x0
  __int64 v73; // x0
  __int64 v74; // x0
  __int64 v75; // x0
  __int64 v76; // x0
  __int64 v77; // x0
  __int64 v78; // x0
  __int64 v79; // x0
  __int64 v80; // x0
  __int64 v81; // x0
  __int64 v82; // x0
  __int64 v83; // x0
  __int64 v84; // x0
  __int64 v85; // x0
  __int64 v86; // x0
  __int64 v87; // x0
  int v88; // w22
  __int64 v89; // x0
  __int64 v90; // x0
  __int64 v91; // x0
  __int64 v92; // x0
  __int64 v93; // x0
  __int64 v94; // x0
  __int64 v95; // x0
  __int64 v96; // x0
  __int64 v98; // x0
  __int64 v99; // [xsp+8h] [xbp-18h]
  _QWORD v100[2]; // [xsp+10h] [xbp-10h] BYREF

  v100[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(ipc_logbuf, "ipa_wigig %s:%d Start collecting pipes information\n", "ipa_wigig_save_regs", 989);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipa_wigig %s:%d Start collecting pipes information\n", "ipa_wigig_save_regs", 989);
  }
  v2 = ipa_wigig_ctx;
  if ( !ipa_wigig_ctx )
  {
    printk(&unk_3CE6D1, "ipa_wigig_save_regs");
    if ( ipa3_get_ipc_logbuf() )
    {
      v66 = ipa3_get_ipc_logbuf();
      ipc_log_string(v66, "ipa_wigig %s:%d wigig ctx is not initialized\n", "ipa_wigig_save_regs", 992);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v67 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v67, "ipa_wigig %s:%d wigig ctx is not initialized\n", "ipa_wigig_save_regs", 992);
    }
    v65 = -1;
    goto LABEL_171;
  }
  if ( (*(_BYTE *)(ipa_wigig_ctx + 910) & 1) != 0 )
  {
    v3 = 0;
    v4 = 0;
    v5 = 760;
    while ( ((*(unsigned __int8 *)(v2 + 910) >> v4) & 1) == 0 )
    {
LABEL_13:
      v5 += 28;
      ++v4;
      v3 += 64;
      if ( v5 == 900 )
      {
        if ( arm64_use_ng_mappings )
          v49 = 0x68000000000F13LL;
        else
          v49 = 0x68000000000713LL;
        v50 = ioremap_prot(*(_QWORD *)(v2 + 96), 4, v49);
        if ( v50 )
        {
          v51 = v50;
          if ( arm64_use_ng_mappings )
            v52 = 0x68000000000F13LL;
          else
            v52 = 0x68000000000713LL;
          v53 = ioremap_prot(*(_QWORD *)(ipa_wigig_ctx + 88), 4, v52);
          if ( v53 )
          {
            v54 = v53;
            if ( ipa3_get_ipc_logbuf() )
            {
              v55 = ipa3_get_ipc_logbuf();
              ipc_log_string(v55, "ipa_wigig %s:%d collecting int_gen_rx_pa info\n", "ipa_wigig_save_regs", 1087);
            }
            if ( ipa3_get_ipc_logbuf_low() )
            {
              v57 = ipa3_get_ipc_logbuf_low();
              v56 = ipc_log_string(v57, "ipa_wigig %s:%d collecting int_gen_rx_pa info\n", "ipa_wigig_save_regs", 1087);
            }
            *(_DWORD *)(ipa_wigig_ctx + 904) = readl_relaxed(v51, v56);
            if ( ipa3_get_ipc_logbuf() )
            {
              v58 = ipa3_get_ipc_logbuf();
              ipc_log_string(v58, "ipa_wigig %s:%d collecting int_gen_tx_pa info\n", "ipa_wigig_save_regs", 1091);
            }
            if ( ipa3_get_ipc_logbuf_low() )
            {
              v60 = ipa3_get_ipc_logbuf_low();
              v59 = ipc_log_string(v60, "ipa_wigig %s:%d collecting int_gen_tx_pa info\n", "ipa_wigig_save_regs", 1091);
            }
            *(_DWORD *)(ipa_wigig_ctx + 900) = readl_relaxed(v54, v59);
            if ( ipa3_get_ipc_logbuf() )
            {
              v61 = ipa3_get_ipc_logbuf();
              ipc_log_string(v61, "ipa_wigig %s:%d Finish collecting pipes info\n", "ipa_wigig_save_regs", 1095);
            }
            if ( ipa3_get_ipc_logbuf_low() )
            {
              v62 = ipa3_get_ipc_logbuf_low();
              ipc_log_string(v62, "ipa_wigig %s:%d Finish collecting pipes info\n", "ipa_wigig_save_regs", 1095);
            }
            if ( ipa3_get_ipc_logbuf() )
            {
              v63 = ipa3_get_ipc_logbuf();
              ipc_log_string(v63, "ipa_wigig %s:%d exit\n", "ipa_wigig_save_regs", 1096);
            }
            if ( ipa3_get_ipc_logbuf_low() )
            {
              v64 = ipa3_get_ipc_logbuf_low();
              ipc_log_string(v64, "ipa_wigig %s:%d exit\n", "ipa_wigig_save_regs", 1096);
            }
            iounmap(v54);
            v65 = 0;
          }
          else
          {
            printk(&unk_3F0D8E, "ipa_wigig_save_regs");
            if ( ipa3_get_ipc_logbuf() )
            {
              v72 = ipa3_get_ipc_logbuf();
              ipc_log_string(v72, "ipa_wigig %s:%d couldn't ioremap gen tx address\n", "ipa_wigig_save_regs", 1082);
            }
            if ( ipa3_get_ipc_logbuf_low() )
            {
              v73 = ipa3_get_ipc_logbuf_low();
              ipc_log_string(v73, "ipa_wigig %s:%d couldn't ioremap gen tx address\n", "ipa_wigig_save_regs", 1082);
            }
            v65 = -22;
          }
          iounmap(v51);
          goto LABEL_171;
        }
        printk(&unk_3D164A, "ipa_wigig_save_regs");
        if ( ipa3_get_ipc_logbuf() )
        {
          v70 = ipa3_get_ipc_logbuf();
          ipc_log_string(v70, "ipa_wigig %s:%d couldn't ioremap gen rx address\n", "ipa_wigig_save_regs", 1076);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v71 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v71, "ipa_wigig %s:%d couldn't ioremap gen rx address\n", "ipa_wigig_save_regs", 1076);
          goto LABEL_109;
        }
LABEL_170:
        v65 = -22;
        goto LABEL_171;
      }
    }
    if ( ipa3_get_ipc_logbuf() )
    {
      v13 = ipa3_get_ipc_logbuf();
      ipc_log_string(v13, "ipa_wigig %s:%d \n", "ipa_wigig_get_regs_addr", 872);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v15 = ipa3_get_ipc_logbuf_low();
      v14 = ipc_log_string(v15, "ipa_wigig %s:%d \n", "ipa_wigig_get_regs_addr", 872);
    }
    v16 = ipa_wigig_ctx;
    if ( !ipa_wigig_ctx )
    {
      if ( ipa3_get_ipc_logbuf() )
      {
        v74 = ipa3_get_ipc_logbuf();
        ipc_log_string(v74, "ipa_wigig %s:%d wigig ctx is not initialized\n", "ipa_wigig_get_regs_addr", 881);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v75 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v75, "ipa_wigig %s:%d wigig ctx is not initialized\n", "ipa_wigig_get_regs_addr", 881);
      }
      goto LABEL_166;
    }
    if ( (*(_BYTE *)(ipa_wigig_ctx + 910) & 1) == 0 )
    {
      if ( ipa3_get_ipc_logbuf() )
      {
        v76 = ipa3_get_ipc_logbuf();
        ipc_log_string(
          v76,
          "ipa_wigig %s:%d must connect rx pipe before connecting any client\n",
          "ipa_wigig_get_regs_addr",
          888);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v77 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          v77,
          "ipa_wigig %s:%d must connect rx pipe before connecting any client\n",
          "ipa_wigig_get_regs_addr",
          888);
      }
      goto LABEL_166;
    }
    if ( *(_BYTE *)(ipa_wigig_ctx + 908) == 1 )
    {
      v100[0] = 0;
      if ( (unsigned int)ipa_wigig_get_pipe_smmu_info(v100, (unsigned int)v4, v14) )
        goto LABEL_166;
      v17 = v100[0];
      v99 = v4;
      if ( arm64_use_ng_mappings )
        v18 = 0x68000000000F13LL;
      else
        v18 = 0x68000000000713LL;
      v19 = ioremap_prot(*(_QWORD *)((char *)&unk_20 + v100[0]), 4, v18);
      if ( !v19 )
      {
        if ( ipa3_get_ipc_logbuf() )
        {
          v80 = ipa3_get_ipc_logbuf();
          ipc_log_string(
            v80,
            "ipa_wigig %s:%d couldn't ioremap desc ring head address\n",
            "ipa_wigig_get_regs_addr",
            901);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v81 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            v81,
            "ipa_wigig %s:%d couldn't ioremap desc ring head address\n",
            "ipa_wigig_get_regs_addr",
            901);
        }
        goto LABEL_162;
      }
      v20 = v19;
      if ( arm64_use_ng_mappings )
        v21 = 0x68000000000F13LL;
      else
        v21 = 0x68000000000713LL;
      v22 = ioremap_prot(*(__int64 *)((char *)&qword_28 + v17), 4, v21);
      if ( !v22 )
      {
        if ( ipa3_get_ipc_logbuf() )
        {
          v86 = ipa3_get_ipc_logbuf();
          ipc_log_string(
            v86,
            "ipa_wigig %s:%d couldn't ioremap desc ring tail address\n",
            "ipa_wigig_get_regs_addr",
            909);
        }
        v29 = v20;
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v98 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            v98,
            "ipa_wigig %s:%d couldn't ioremap desc ring tail address\n",
            "ipa_wigig_get_regs_addr",
            909);
        }
        LODWORD(v4) = v99;
        goto LABEL_161;
      }
      v23 = v22;
      if ( arm64_use_ng_mappings )
        v24 = 0x68000000000F13LL;
      else
        v24 = 0x68000000000713LL;
      v25 = ioremap_prot(*(_QWORD *)((char *)&unk_50 + v17), 4, v24);
      if ( !v25 )
      {
        v29 = v20;
        if ( ipa3_get_ipc_logbuf() )
        {
          v89 = ipa3_get_ipc_logbuf();
          ipc_log_string(
            v89,
            "ipa_wigig %s:%d couldn't ioremap status ring head address\n",
            "ipa_wigig_get_regs_addr",
            917);
        }
        LODWORD(v4) = v99;
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v90 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            v90,
            "ipa_wigig %s:%d couldn't ioremap status ring head address\n",
            "ipa_wigig_get_regs_addr",
            917);
        }
        goto LABEL_160;
      }
      v26 = v25;
      if ( arm64_use_ng_mappings )
        v27 = 0x68000000000F13LL;
      else
        v27 = 0x68000000000713LL;
      v28 = ioremap_prot(*(__int64 *)((char *)&qword_58 + v17), 4, v27);
      if ( !v28 )
      {
        v29 = v20;
        if ( ipa3_get_ipc_logbuf() )
        {
          v91 = ipa3_get_ipc_logbuf();
          ipc_log_string(
            v91,
            "ipa_wigig %s:%d couldn't ioremap status ring tail address\n",
            "ipa_wigig_get_regs_addr",
            925);
        }
        LODWORD(v4) = v99;
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v88 = 925;
LABEL_158:
          v92 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            v92,
            "ipa_wigig %s:%d couldn't ioremap status ring tail address\n",
            "ipa_wigig_get_regs_addr",
            v88);
        }
        goto LABEL_159;
      }
      v29 = v20;
      v4 = v99;
      v30 = v28;
      if ( !ipa3_get_ipc_logbuf() )
        goto LABEL_59;
    }
    else
    {
      if ( arm64_use_ng_mappings )
        v31 = 0x68000000000F13LL;
      else
        v31 = 0x68000000000713LL;
      v32 = ioremap_prot(*(_QWORD *)(ipa_wigig_ctx + v3 + 144), 4, v31);
      if ( !v32 )
      {
        if ( ipa3_get_ipc_logbuf() )
        {
          v78 = ipa3_get_ipc_logbuf();
          ipc_log_string(
            v78,
            "ipa_wigig %s:%d couldn't ioremap desc ring head address\n",
            "ipa_wigig_get_regs_addr",
            937);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v79 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            v79,
            "ipa_wigig %s:%d couldn't ioremap desc ring head address\n",
            "ipa_wigig_get_regs_addr",
            937);
        }
LABEL_162:
        if ( ipa3_get_ipc_logbuf() )
        {
          v93 = ipa3_get_ipc_logbuf();
          ipc_log_string(
            v93,
            "ipa_wigig %s:%d couldn't get regs information idx %d\n",
            "ipa_wigig_get_regs_addr",
            976,
            v4);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v94 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            v94,
            "ipa_wigig %s:%d couldn't get regs information idx %d\n",
            "ipa_wigig_get_regs_addr",
            976,
            v4);
        }
LABEL_166:
        printk(&unk_3AE69A, "ipa_wigig_save_regs");
        if ( ipa3_get_ipc_logbuf() )
        {
          v95 = ipa3_get_ipc_logbuf();
          ipc_log_string(
            v95,
            "ipa_wigig %s:%d couldn't get registers information on client %d\n",
            "ipa_wigig_save_regs",
            1015,
            v4);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v96 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            v96,
            "ipa_wigig %s:%d couldn't get registers information on client %d\n",
            "ipa_wigig_save_regs",
            1015,
            v4);
        }
        goto LABEL_170;
      }
      v29 = v32;
      if ( arm64_use_ng_mappings )
        v33 = 0x68000000000F13LL;
      else
        v33 = 0x68000000000713LL;
      v34 = ioremap_prot(*(_QWORD *)(v16 + v3 + 152), 4, v33);
      if ( !v34 )
      {
        if ( ipa3_get_ipc_logbuf() )
        {
          v82 = ipa3_get_ipc_logbuf();
          ipc_log_string(
            v82,
            "ipa_wigig %s:%d couldn't ioremap desc ring tail address\n",
            "ipa_wigig_get_regs_addr",
            944);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v83 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            v83,
            "ipa_wigig %s:%d couldn't ioremap desc ring tail address\n",
            "ipa_wigig_get_regs_addr",
            944);
        }
        goto LABEL_161;
      }
      v35 = v16 + v3;
      v23 = v34;
      if ( arm64_use_ng_mappings )
        v36 = 0x68000000000F13LL;
      else
        v36 = 0x68000000000713LL;
      v37 = ioremap_prot(*(_QWORD *)(v16 + v3 + 176), 4, v36);
      if ( !v37 )
      {
        if ( ipa3_get_ipc_logbuf() )
        {
          v84 = ipa3_get_ipc_logbuf();
          ipc_log_string(
            v84,
            "ipa_wigig %s:%d couldn't ioremap status ring head address\n",
            "ipa_wigig_get_regs_addr",
            952);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v85 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            v85,
            "ipa_wigig %s:%d couldn't ioremap status ring head address\n",
            "ipa_wigig_get_regs_addr",
            952);
        }
LABEL_160:
        iounmap(v23);
LABEL_161:
        iounmap(v29);
        goto LABEL_162;
      }
      v26 = v37;
      if ( arm64_use_ng_mappings )
        v38 = 0x68000000000F13LL;
      else
        v38 = 0x68000000000713LL;
      v39 = ioremap_prot(*(_QWORD *)(v35 + 184), 4, v38);
      if ( !v39 )
      {
        if ( ipa3_get_ipc_logbuf() )
        {
          v87 = ipa3_get_ipc_logbuf();
          ipc_log_string(
            v87,
            "ipa_wigig %s:%d couldn't ioremap status ring tail address\n",
            "ipa_wigig_get_regs_addr",
            960);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v88 = 960;
          goto LABEL_158;
        }
LABEL_159:
        iounmap(v26);
        goto LABEL_160;
      }
      v30 = v39;
      if ( !ipa3_get_ipc_logbuf() )
        goto LABEL_59;
    }
    v40 = ipa3_get_ipc_logbuf();
    ipc_log_string(v40, "ipa_wigig %s:%d exit\n", "ipa_wigig_get_regs_addr", 966);
LABEL_59:
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v41 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v41, "ipa_wigig %s:%d exit\n", "ipa_wigig_get_regs_addr", 966);
    }
    if ( ipa3_get_ipc_logbuf() )
    {
      v42 = ipa3_get_ipc_logbuf();
      ipc_log_string(v42, "ipa_wigig %s:%d collecting pipe info of index %d\n", "ipa_wigig_save_regs", 1019, v4);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v44 = ipa3_get_ipc_logbuf_low();
      v43 = ipc_log_string(v44, "ipa_wigig %s:%d collecting pipe info of index %d\n", "ipa_wigig_save_regs", 1019, v4);
    }
    if ( v5 == 760 )
    {
      *(_BYTE *)(ipa_wigig_ctx + 760) = 0;
    }
    else
    {
      v45 = (_BYTE *)(ipa_wigig_ctx + v5);
      *v45 = 1;
      v45[1] = v4 + 1;
    }
    v46 = readl_relaxed(v29, v43);
    v48 = ipa_wigig_ctx + v5;
    *(_DWORD *)(ipa_wigig_ctx + v5 + 4) = v46;
    if ( v5 == 760 )
    {
      v6 = -65536;
      v7 = 16;
    }
    else
    {
      v6 = 0xFFFF;
      v7 = 0;
      if ( (*(_BYTE *)(v48 + 1) & 1) != 0 )
        v8 = -65536;
      else
        v8 = 0xFFFF;
      *(_WORD *)(v48 + 8) = (v8 & v46) >> (16 * (*(_BYTE *)(v48 + 1) & 1));
    }
    *(_DWORD *)(ipa_wigig_ctx + v5 + 12) = readl_relaxed(v23, v47);
    v10 = readl_relaxed(v26, v9);
    v11 = ipa_wigig_ctx + v5;
    *(_DWORD *)(v11 + 16) = v10;
    *(_WORD *)(v11 + 20) = (v10 & (unsigned int)v6) >> v7;
    *(_DWORD *)(ipa_wigig_ctx + v5 + 24) = readl_relaxed(v30, v12);
    iounmap(v29);
    iounmap(v23);
    iounmap(v26);
    iounmap(v30);
    v2 = ipa_wigig_ctx;
    goto LABEL_13;
  }
  printk(&unk_3C5CE6, "ipa_wigig_save_regs");
  if ( ipa3_get_ipc_logbuf() )
  {
    v68 = ipa3_get_ipc_logbuf();
    ipc_log_string(
      v68,
      "ipa_wigig %s:%d must connect rx pipe before connecting any client\n",
      "ipa_wigig_save_regs",
      998);
  }
  if ( !ipa3_get_ipc_logbuf_low() )
    goto LABEL_170;
  v69 = ipa3_get_ipc_logbuf_low();
  ipc_log_string(v69, "ipa_wigig %s:%d must connect rx pipe before connecting any client\n", "ipa_wigig_save_regs", 998);
LABEL_109:
  v65 = -22;
LABEL_171:
  _ReadStatusReg(SP_EL0);
  return v65;
}
