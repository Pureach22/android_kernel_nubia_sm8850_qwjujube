__int64 __fastcall ipahal_init(unsigned int a1, const void *a2, int a3, const void *a4)
{
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v10; // x0
  __int64 v11; // x0
  unsigned __int64 v12; // x1
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 (__fastcall *v15)(); // x8
  __int64 v16; // x9
  __int64 (__fastcall *v17)(); // x8
  __int64 (__fastcall *v18)(); // x9
  __int64 v19; // x8
  __int64 (__fastcall *v20)(); // x9
  __int64 (__fastcall *v21)(); // x8
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x0
  long double v25; // q0
  __int64 v26; // x0
  __int64 v27; // x0
  unsigned __int64 dir; // x0
  __int64 result; // x0
  _QWORD *v30; // x19
  void *v31; // x14
  __int64 v32; // x28
  __int64 v33; // x25
  char *v34; // x23
  const char *v35; // x15
  __int64 v36; // x8
  __int64 v37; // x21
  unsigned int v38; // w26
  unsigned __int64 v39; // x22
  bool v40; // zf
  _QWORD *v41; // x27
  const char *v43; // x24
  const char *v44; // x0
  __int64 v45; // x27
  const char *v46; // x0
  unsigned __int64 v47; // x8
  __int64 v48; // x10
  __int64 v49; // x8
  const char *v50; // x0
  __int64 v51; // x28
  const char *v52; // x0
  unsigned __int64 v53; // x20
  int v54; // w23
  __int64 v55; // x10
  __int64 v56; // x11
  __int64 v57; // x10
  unsigned int *v58; // x8
  bool v59; // zf
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
  __int64 v74; // x0
  __int64 v75; // x0
  __int64 v76; // x0
  __int64 v77; // x0
  __int64 v78; // x0
  __int64 v79; // x0
  __int64 v80; // x0
  __int64 v81; // x0
  __int64 v82; // x0
  int v83; // w8
  __int64 v84; // x0
  __int64 v85; // x0
  __int64 v86; // x0
  __int64 v87; // x0
  __int64 v88; // x0
  long double v89; // q0
  __int64 v90; // x0
  __int64 v91; // x0
  __int64 v92; // x0
  __int64 v93; // x0
  unsigned int v94; // w19
  __int64 v95; // x0
  __int64 v96; // x0
  __int64 v97; // x0
  __int64 v98; // x0
  unsigned int v99; // [xsp+Ch] [xbp-54h]
  __int64 v100; // [xsp+18h] [xbp-48h]
  __int64 v101; // [xsp+18h] [xbp-48h]
  __int64 v102; // [xsp+20h] [xbp-40h]
  __int64 v103; // [xsp+28h] [xbp-38h]

  _ReadStatusReg(SP_EL0);
  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(
      ipc_logbuf,
      "ipahal %s:%d Entry - IPA HW TYPE=%d base=%pK ipa_pdev=%pK\n",
      "ipahal_init",
      2526,
      a1,
      a2,
      a4);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(
      ipc_logbuf_low,
      "ipahal %s:%d Entry - IPA HW TYPE=%d base=%pK ipa_pdev=%pK\n",
      "ipahal_init",
      2526,
      a1,
      a2,
      a4);
  }
  v10 = _kmalloc_cache_noprof(_kmalloc_cache_noprof, 3520, 72);
  ipahal_ctx = v10;
  if ( v10 )
  {
    if ( a1 <= 9 )
    {
      printk(&unk_3C8A39, "ipahal_init");
      if ( ipa3_get_ipc_logbuf() )
      {
        v75 = ipa3_get_ipc_logbuf();
        ipc_log_string(v75, "ipahal %s:%d ipahal supported on IPAv3 and later only\n", "ipahal_init", 2536);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v76 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v76, "ipahal %s:%d ipahal supported on IPAv3 and later only\n", "ipahal_init", 2536);
      }
    }
    else if ( a1 >= 0x1A )
    {
      printk(&unk_3AE767, "ipahal_init");
      if ( ipa3_get_ipc_logbuf() )
      {
        v77 = ipa3_get_ipc_logbuf();
        ipc_log_string(v77, "ipahal %s:%d invalid IPA HW type (%d)\n", "ipahal_init", 2542, a1);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v78 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v78, "ipahal %s:%d invalid IPA HW type (%d)\n", "ipahal_init", 2542, a1);
      }
    }
    else if ( a2 )
    {
      if ( a4 )
      {
        *(_DWORD *)v10 = a1;
        *(_QWORD *)(v10 + 8) = a2;
        *(_DWORD *)(v10 + 16) = a3;
        *(_QWORD *)(v10 + 32) = a4;
        if ( (unsigned int)ipahal_reg_init(a1) )
        {
          printk(&unk_3A8A37, "ipahal_init");
          if ( ipa3_get_ipc_logbuf() )
          {
            v84 = ipa3_get_ipc_logbuf();
            ipc_log_string(v84, "ipahal %s:%d failed to init ipahal reg\n", "ipahal_init", 2565);
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v85 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(v85, "ipahal %s:%d failed to init ipahal reg\n", "ipahal_init", 2565);
          }
        }
        else
        {
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v11 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(v11, "ipahal %s:%d Entry - HW_TYPE=%d\n", "ipahal_imm_cmd_init", 1089, a1);
          }
          v99 = a1;
          if ( a1 != 10 )
          {
            v30 = ipahal_imm_cmd_objs;
            v31 = &_crc_ipa_wdi_opt_dpath_add_ctrl_filter_req;
            v32 = 0;
            v33 = -6104;
            v34 = (char *)&unk_120C0;
            v35 = "ipahal_imm_cmd_init";
            v36 = 10;
            v37 = 4488;
            do
            {
              v38 = 0;
              v39 = 0;
              v102 = v32;
              v103 = v36 + 1;
              do
              {
                if ( v37 + v39 <= 0x2970 )
                  v12 = 10608 - (v37 + v39);
                else
                  v12 = 0;
                if ( v12 <= 0x17 )
                  goto LABEL_189;
                if ( *(_QWORD *)&v34[v39] )
                  v40 = 0;
                else
                  v40 = *(_QWORD *)&v34[v39 + 8] == 0;
                v41 = (_QWORD *)((char *)&v30[v39 / 8] + (_QWORD)v31);
                if ( v40 && *(_QWORD *)&v34[v39 + 16] == 0 )
                {
                  v47 = 6528 - (v32 + v39);
                  if ( v32 + v39 + 4080 > 0x2970 )
                    v47 = 0;
                  if ( v47 <= 0x17 )
                    goto LABEL_190;
                  v48 = v30[v39 / 8 + 511];
                  v49 = v30[v39 / 8 + 512];
                  *v41 = v30[v39 / 8 + 510];
                  v41[1] = v48;
                  v41[2] = v49;
                }
                else
                {
                  if ( v33 + v39 < 0xFFFFFFFFFFFFD690LL )
                    goto LABEL_188;
                  v43 = v35;
                  if ( !LOWORD(v30[v39 / 8 + 563]) )
                  {
                    ipahal_imm_cmd_name_str(v38);
                    printk(&unk_3F103B, v43);
                    if ( ipa3_get_ipc_logbuf() )
                    {
                      v101 = ipa3_get_ipc_logbuf();
                      v50 = ipahal_imm_cmd_name_str(v38);
                      ipc_log_string(
                        v101,
                        "ipahal %s:%d imm_cmd=%s with zero opcode ipa_ver=%d\n",
                        "ipahal_imm_cmd_init",
                        1112,
                        v50,
                        v103);
                    }
                    if ( ipa3_get_ipc_logbuf_low() )
                    {
                      v51 = ipa3_get_ipc_logbuf_low();
                      v52 = ipahal_imm_cmd_name_str(v38);
                      ipc_log_string(v51, "ipahal %s:%d imm_cmd=%s with zero opcode ipa_ver=%d\n", v43, 1112, v52, v103);
                    }
                    __break(0x800u);
                    v32 = v102;
                    v31 = &_crc_ipa_wdi_opt_dpath_add_ctrl_filter_req;
                  }
                  if ( (v37 + v39) >> 4 > 0x296 )
                  {
LABEL_188:
                    __break(1u);
LABEL_189:
                    _fortify_panic(22, v12, 24);
LABEL_190:
                    _fortify_panic(16, v12, 24);
LABEL_191:
                    _fortify_panic(22, 0, 40);
                  }
                  v35 = v43;
                  if ( !*v41 )
                  {
                    ipahal_imm_cmd_name_str(v38);
                    printk(&unk_3CB51C, v43);
                    if ( ipa3_get_ipc_logbuf() )
                    {
                      v100 = ipa3_get_ipc_logbuf();
                      v44 = ipahal_imm_cmd_name_str(v38);
                      ipc_log_string(
                        v100,
                        "ipahal %s:%d imm_cmd=%s with NULL construct func ipa_ver=%d\n",
                        v43,
                        1118,
                        v44,
                        v103);
                    }
                    if ( ipa3_get_ipc_logbuf_low() )
                    {
                      v45 = ipa3_get_ipc_logbuf_low();
                      v46 = ipahal_imm_cmd_name_str(v38);
                      ipc_log_string(
                        v45,
                        "ipahal %s:%d imm_cmd=%s with NULL construct func ipa_ver=%d\n",
                        v43,
                        1118,
                        v46,
                        v103);
                    }
                    v31 = &_crc_ipa_wdi_opt_dpath_add_ctrl_filter_req;
                    v35 = v43;
                    __break(0x800u);
                  }
                }
                v39 += 24LL;
                ++v38;
              }
              while ( v39 != 408 );
              v37 += 408;
              v33 += 408;
              v30 += 51;
              v32 += 408;
              v36 = v103;
              v34 += 408;
            }
            while ( v103 != v99 );
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v13 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(v13, "ipahal %s:%d Entry - HW_TYPE=%d\n", "ipahal_pkt_status_init", 1852, v99);
          }
          if ( v99 != 10 )
          {
            v53 = 0;
            v54 = 11;
            while ( v53 != 600 )
            {
              v58 = &ipahal_pkt_status_objs[v53 / 4 + 110];
              if ( *(_QWORD *)v58 )
                v59 = 0;
              else
                v59 = *(_QWORD *)&ipahal_pkt_status_objs[v53 / 4 + 112] == 0;
              if ( v59
                && *(_QWORD *)&ipahal_pkt_status_objs[v53 / 4 + 114] == 0
                && *(_QWORD *)&ipahal_pkt_status_objs[v53 / 4 + 116] == 0
                && *(_QWORD *)&ipahal_pkt_status_objs[v53 / 4 + 118] == 0 )
              {
                v55 = *(_QWORD *)&ipahal_pkt_status_objs[v53 / 4 + 104];
                v56 = *(_QWORD *)&ipahal_pkt_status_objs[v53 / 4 + 106];
                *(_QWORD *)&ipahal_pkt_status_objs[v53 / 4 + 118] = *(_QWORD *)&ipahal_pkt_status_objs[v53 / 4 + 108];
                *(_QWORD *)&ipahal_pkt_status_objs[v53 / 4 + 114] = v55;
                *(_QWORD *)&ipahal_pkt_status_objs[v53 / 4 + 116] = v56;
                v57 = *(_QWORD *)&ipahal_pkt_status_objs[v53 / 4 + 102];
                *(_QWORD *)v58 = *(_QWORD *)&ipahal_pkt_status_objs[v53 / 4 + 100];
                *(_QWORD *)&ipahal_pkt_status_objs[v53 / 4 + 112] = v57;
              }
              else
              {
                if ( !*v58 )
                {
                  printk(&unk_3C2B04, "ipahal_pkt_status_init");
                  if ( ipa3_get_ipc_logbuf() )
                  {
                    v65 = ipa3_get_ipc_logbuf();
                    ipc_log_string(
                      v65,
                      "ipahal %s:%d Packet Status with zero size ipa_ver=%d\n",
                      "ipahal_pkt_status_init",
                      1887,
                      v54);
                  }
                  if ( ipa3_get_ipc_logbuf_low() )
                  {
                    v66 = ipa3_get_ipc_logbuf_low();
                    ipc_log_string(
                      v66,
                      "ipahal %s:%d Packet Status with zero size ipa_ver=%d\n",
                      "ipahal_pkt_status_init",
                      1887,
                      v54);
                  }
                  __break(0x800u);
                }
                if ( v53 - 592 < 0xFFFFFFFFFFFFFBF0LL )
                  goto LABEL_188;
                if ( !*(_QWORD *)&ipahal_pkt_status_objs[v53 / 4 + 112] )
                {
                  printk(&unk_3A8AC3, "ipahal_pkt_status_init");
                  if ( ipa3_get_ipc_logbuf() )
                  {
                    v67 = ipa3_get_ipc_logbuf();
                    ipc_log_string(
                      v67,
                      "ipahal %s:%d Packet Status without Parse func ipa_ver=%d\n",
                      "ipahal_pkt_status_init",
                      1893,
                      v54);
                  }
                  if ( ipa3_get_ipc_logbuf_low() )
                  {
                    v68 = ipa3_get_ipc_logbuf_low();
                    ipc_log_string(
                      v68,
                      "ipahal %s:%d Packet Status without Parse func ipa_ver=%d\n",
                      "ipahal_pkt_status_init",
                      1893,
                      v54);
                  }
                  __break(0x800u);
                }
                if ( v53 - 584 < 0xFFFFFFFFFFFFFBF0LL )
                  goto LABEL_188;
                if ( !*(_QWORD *)&ipahal_pkt_status_objs[v53 / 4 + 114] )
                {
                  printk(&unk_3D17B3, "ipahal_pkt_status_init");
                  if ( ipa3_get_ipc_logbuf() )
                  {
                    v69 = ipa3_get_ipc_logbuf();
                    ipc_log_string(
                      v69,
                      "ipahal %s:%d Packet Status without Parse_thin func ipa_ver=%d\n",
                      "ipahal_pkt_status_init",
                      1899,
                      v54);
                  }
                  if ( ipa3_get_ipc_logbuf_low() )
                  {
                    v70 = ipa3_get_ipc_logbuf_low();
                    ipc_log_string(
                      v70,
                      "ipahal %s:%d Packet Status without Parse_thin func ipa_ver=%d\n",
                      "ipahal_pkt_status_init",
                      1899,
                      v54);
                  }
                  __break(0x800u);
                }
                if ( v53 - 576 < 0xFFFFFFFFFFFFFBF0LL )
                  goto LABEL_188;
                if ( !*(_QWORD *)&ipahal_pkt_status_objs[v53 / 4 + 116] )
                {
                  printk(&unk_3FFDDE, "ipahal_pkt_status_init");
                  if ( ipa3_get_ipc_logbuf() )
                  {
                    v71 = ipa3_get_ipc_logbuf();
                    ipc_log_string(
                      v71,
                      "ipahal %s:%d Packet Status without parse_gen func ipa_ver=%d\n",
                      "ipahal_pkt_status_init",
                      1905,
                      v54);
                  }
                  if ( ipa3_get_ipc_logbuf_low() )
                  {
                    v72 = ipa3_get_ipc_logbuf_low();
                    ipc_log_string(
                      v72,
                      "ipahal %s:%d Packet Status without parse_gen func ipa_ver=%d\n",
                      "ipahal_pkt_status_init",
                      1905,
                      v54);
                  }
                  __break(0x800u);
                }
                if ( v53 - 568 < 0xFFFFFFFFFFFFFBF0LL )
                  goto LABEL_188;
                if ( !*(_QWORD *)&ipahal_pkt_status_objs[v53 / 4 + 118] )
                {
                  printk(&unk_3AE7E5, "ipahal_pkt_status_init");
                  if ( ipa3_get_ipc_logbuf() )
                  {
                    v63 = ipa3_get_ipc_logbuf();
                    ipc_log_string(
                      v63,
                      "ipahal %s:%d Packet Status without parse_frag func ipa_ver=%d\n",
                      "ipahal_pkt_status_init",
                      1911,
                      v54);
                  }
                  if ( ipa3_get_ipc_logbuf_low() )
                  {
                    v64 = ipa3_get_ipc_logbuf_low();
                    ipc_log_string(
                      v64,
                      "ipahal %s:%d Packet Status without parse_frag func ipa_ver=%d\n",
                      "ipahal_pkt_status_init",
                      1911,
                      v54);
                  }
                  __break(0x800u);
                }
              }
              v53 += 40LL;
              ++v54;
              if ( 40LL * v99 - 400 == v53 )
                goto LABEL_17;
            }
            goto LABEL_191;
          }
LABEL_17:
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v14 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(v14, "ipahal %s:%d Entry - HW_TYPE=%d\n", "ipahal_qmap_init", 2752, v99);
          }
          v15 = (__int64 (__fastcall *)())qword_10EF8;
          if ( !qword_10EF8 )
          {
            v15 = off_10EF0;
            qword_10EF8 = (__int64)off_10EF0;
          }
          v16 = qword_10F00;
          if ( !qword_10F00 )
          {
            v16 = (__int64)v15;
            qword_10F00 = (__int64)v15;
          }
          v17 = (__int64 (__fastcall *)())qword_10F08;
          if ( !qword_10F08 )
          {
            v17 = (__int64 (__fastcall *)())v16;
            qword_10F08 = v16;
          }
          v18 = off_10F10;
          if ( !off_10F10 )
          {
            v18 = v17;
            off_10F10 = v17;
          }
          v19 = qword_10F18;
          if ( !qword_10F18 )
          {
            v19 = (__int64)v18;
            qword_10F18 = (__int64)v18;
          }
          v20 = (__int64 (__fastcall *)())qword_10F20;
          if ( !qword_10F20 )
          {
            v20 = (__int64 (__fastcall *)())v19;
            qword_10F20 = v19;
          }
          v21 = off_10F28;
          if ( !off_10F28 )
          {
            v21 = v20;
            off_10F28 = v20;
          }
          if ( !qword_10F30 )
            qword_10F30 = (__int64)v21;
          if ( ipa3_get_ipc_logbuf() )
          {
            v22 = ipa3_get_ipc_logbuf();
            ipc_log_string(v22, "ipahal %s:%d Entry - HW_TYPE=%d\n", "ipahal_hdr_init", 2418, v99);
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v23 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(v23, "ipahal %s:%d Entry - HW_TYPE=%d\n", "ipahal_hdr_init", 2418, v99);
          }
          hdr_funcs_0 = ipahal_cp_hdr_to_hw_buff_v3;
          hdr_funcs_1 = ipahal_cp_proc_ctx_to_hw_buff_v3;
          hdr_funcs_2 = ipahal_get_proc_ctx_needed_len_v3;
          if ( ipa3_get_ipc_logbuf() )
          {
            v24 = ipa3_get_ipc_logbuf();
            ipc_log_string(v24, "ipahal %s:%d Exit\n", "ipahal_hdr_init", 2435);
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v26 = ipa3_get_ipc_logbuf_low();
            v25 = ipc_log_string(v26, "ipahal %s:%d Exit\n", "ipahal_hdr_init", 2435);
          }
          if ( (unsigned int)((__int64 (__fastcall *)(_QWORD, long double))ipahal_fltrt_init)(v99, v25) )
          {
            printk(&unk_3E531B, "ipahal_init");
            if ( ipa3_get_ipc_logbuf() )
            {
              v86 = ipa3_get_ipc_logbuf();
              ipc_log_string(v86, "ipahal %s:%d failed to init ipahal flt rt\n", "ipahal_init", 2591);
            }
            if ( ipa3_get_ipc_logbuf_low() )
            {
              v87 = ipa3_get_ipc_logbuf_low();
              ipc_log_string(v87, "ipahal %s:%d failed to init ipahal flt rt\n", "ipahal_init", 2591);
            }
          }
          else
          {
            if ( (unsigned int)ipahal_hw_stats_init(v99) )
            {
              printk(&unk_3DD2D0, "ipahal_init");
              if ( ipa3_get_ipc_logbuf() )
              {
                v88 = ipa3_get_ipc_logbuf();
                ipc_log_string(v88, "ipahal %s:%d failed to init ipahal hw stats\n", "ipahal_init", 2597);
              }
              if ( ipa3_get_ipc_logbuf_low() )
              {
                v90 = ipa3_get_ipc_logbuf_low();
                v89 = ipc_log_string(v90, "ipahal %s:%d failed to init ipahal hw stats\n", "ipahal_init", 2597);
              }
            }
            else
            {
              if ( !(unsigned int)ipahal_nat_init(v99) )
              {
                v27 = ipc_log_context_create(50, "ipa_regs", 0x10000);
                *(_QWORD *)(ipahal_ctx + 64) = v27;
                if ( !v27 )
                {
                  printk(&unk_3D171A, "ipahal_init");
                  if ( ipa3_get_ipc_logbuf() )
                  {
                    v95 = ipa3_get_ipc_logbuf();
                    ipc_log_string(
                      v95,
                      "ipahal %s:%d failed to create IPA regdump log, continue...\n",
                      "ipahal_init",
                      2612);
                  }
                  if ( ipa3_get_ipc_logbuf_low() )
                  {
                    v96 = ipa3_get_ipc_logbuf_low();
                    ipc_log_string(
                      v96,
                      "ipahal %s:%d failed to create IPA regdump log, continue...\n",
                      "ipahal_init",
                      2612);
                  }
                }
                dir = debugfs_create_dir("ipahal", 0);
                *(_QWORD *)(ipahal_ctx + 24) = dir;
                if ( dir && dir < 0xFFFFFFFFFFFFF001LL )
                {
                  result = 0;
                }
                else
                {
                  printk(&unk_3D7576, "ipahal_debugfs_init");
                  if ( ipa3_get_ipc_logbuf() )
                  {
                    v97 = ipa3_get_ipc_logbuf();
                    ipc_log_string(
                      v97,
                      "ipahal %s:%d fail to create ipahal debugfs folder\n",
                      "ipahal_debugfs_init",
                      1990);
                  }
                  if ( ipa3_get_ipc_logbuf_low() )
                  {
                    v98 = ipa3_get_ipc_logbuf_low();
                    ipc_log_string(
                      v98,
                      "ipahal %s:%d fail to create ipahal debugfs folder\n",
                      "ipahal_debugfs_init",
                      1990);
                  }
                  debugfs_remove(*(_QWORD *)(ipahal_ctx + 24));
                  result = 0;
                  *(_QWORD *)(ipahal_ctx + 24) = 0;
                }
                goto LABEL_177;
              }
              printk(&unk_3FFCC6, "ipahal_init");
              if ( ipa3_get_ipc_logbuf() )
              {
                v91 = ipa3_get_ipc_logbuf();
                ipc_log_string(v91, "ipahal %s:%d failed to init ipahal NAT\n", "ipahal_init", 2603);
              }
              if ( ipa3_get_ipc_logbuf_low() )
              {
                v92 = ipa3_get_ipc_logbuf_low();
                v89 = ipc_log_string(v92, "ipahal %s:%d failed to init ipahal NAT\n", "ipahal_init", 2603);
              }
            }
            ipahal_fltrt_destroy(v89);
          }
        }
        v83 = -14;
        goto LABEL_174;
      }
      printk(&unk_3FCF64, "ipahal_init");
      if ( ipa3_get_ipc_logbuf() )
      {
        v81 = ipa3_get_ipc_logbuf();
        ipc_log_string(v81, "ipahal %s:%d invalid IPA platform device\n", "ipahal_init", 2554);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v82 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v82, "ipahal %s:%d invalid IPA platform device\n", "ipahal_init", 2554);
      }
    }
    else
    {
      printk(&unk_3CE83D, "ipahal_init");
      if ( ipa3_get_ipc_logbuf() )
      {
        v79 = ipa3_get_ipc_logbuf();
        ipc_log_string(v79, "ipahal %s:%d invalid memory io mapping addr\n", "ipahal_init", 2548);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v80 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v80, "ipahal %s:%d invalid memory io mapping addr\n", "ipahal_init", 2548);
      }
    }
    v83 = -22;
LABEL_174:
    v93 = ipahal_ctx;
    v94 = v83;
    if ( *(_QWORD *)(ipahal_ctx + 64) )
    {
      ipc_log_context_destroy(*(_QWORD *)(ipahal_ctx + 64));
      v93 = ipahal_ctx;
    }
    kfree(v93);
    ipahal_ctx = 0;
    result = v94;
    goto LABEL_177;
  }
  printk(&unk_3B3BDC, "ipahal_init");
  if ( ipa3_get_ipc_logbuf() )
  {
    v73 = ipa3_get_ipc_logbuf();
    ipc_log_string(v73, "ipahal %s:%d kzalloc err for ipahal_ctx\n", "ipahal_init", 2530);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v74 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v74, "ipahal %s:%d kzalloc err for ipahal_ctx\n", "ipahal_init", 2530);
  }
  result = 4294967284LL;
LABEL_177:
  _ReadStatusReg(SP_EL0);
  return result;
}
