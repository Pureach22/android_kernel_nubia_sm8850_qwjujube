__int64 ipa3_post_init()
{
  __int64 v0; // x8
  __int64 result; // x0
  __int64 v2; // x0
  __int64 v3; // x0
  __int64 v4; // x0
  __int64 inited; // x0
  __int64 v6; // x8
  __int64 v7; // x0
  int num_pipes; // w0
  __int64 v9; // x8
  __int64 v10; // x9
  int v11; // w4
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x8
  __int64 v15; // x0
  __int64 v16; // x8
  __int64 v17; // x0
  __int64 v18; // x8
  __int64 v19; // x8
  __int64 v20; // x0
  unsigned int v21; // w19
  __int64 v22; // x0
  __int64 v23; // x8
  __int64 v24; // x0
  __int64 (*v25)(void); // x8
  __int64 v26; // x0
  __int64 v27; // x8
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x0
  __int64 v31; // x0
  __int64 v32; // x0
  __int64 v33; // x0
  __int64 v34; // x8
  __int64 v35; // x0
  unsigned int dma_task_for_gsi; // w0
  unsigned int v37; // w0
  __int64 v38; // x0
  unsigned int v39; // w8
  __int64 v40; // x0
  __int64 v41; // x8
  __int64 v42; // x0
  __int64 v43; // x0
  __int64 is_ep_support_flt; // x0
  _QWORD *v45; // x8
  _QWORD *v46; // x9
  __int64 v47; // x8
  __int64 v48; // x0
  __int64 v49; // x8
  __int64 v50; // x0
  __int64 v51; // x0
  __int64 v52; // x0
  __int64 v53; // x8
  __int64 v54; // x0
  __int64 v55; // x0
  __int64 v56; // x8
  __int64 v57; // x0
  __int64 v58; // x0
  __int64 v59; // x8
  __int64 v60; // x0
  unsigned __int64 v61; // x19
  __int64 v62; // x20
  char v63; // w8
  __int64 v64; // x9
  char v65; // w21
  __int64 v66; // x9
  __int64 v67; // x26
  __int64 v68; // x8
  int v69; // w9
  __int64 isr; // x0
  bool v71; // zf
  __int64 v72; // x0
  __int64 v73; // x8
  __int64 v74; // x0
  __int64 v75; // x0
  __int64 v76; // x8
  __int64 v77; // x0
  __int64 v78; // x8
  __int64 v79; // x0
  int v80; // w0
  __int64 v81; // x8
  __int64 v82; // x0
  __int64 v83; // x0
  int v84; // w19
  __int64 v85; // x0
  __int64 v86; // x8
  __int64 v87; // x0
  __int64 v88; // x0
  __int64 v89; // x8
  __int64 v90; // x0
  __int64 v91; // x8
  __int64 v92; // x0
  __int64 v93; // x0
  __int64 v94; // x8
  __int64 v95; // x0
  __int64 v96; // x0
  __int64 v97; // x8
  __int64 v98; // x0
  __int64 v99; // x0
  int v100; // w19
  __int64 v101; // x8
  __int64 v102; // x0
  __int64 v103; // x0
  __int64 v104; // x0
  __int64 v105; // x8
  __int64 v106; // x0
  int v107; // w19
  __int64 v108; // x0
  __int64 v109; // x8
  __int64 v110; // x0
  __int64 v111; // x0
  __int64 v112; // x8
  __int64 v113; // x0
  __int64 v114; // x0
  __int64 v115; // x8
  __int64 v116; // x0
  int v117; // w19
  __int64 v118; // x8
  __int64 v119; // x0
  __int64 v120; // x0
  __int64 v121; // x8
  __int64 v122; // x0
  int v123; // w19
  __int64 v124; // x8
  __int64 v125; // x0
  __int64 v126; // x0
  __int64 v127; // x8
  __int64 v128; // x0
  int v129; // w19
  __int64 v130; // x8
  __int64 v131; // x0
  __int64 v132; // x0
  __int64 v133; // x8
  __int64 v134; // x0
  int v135; // w19
  __int64 v136; // x8
  __int64 v137; // x0
  __int64 v138; // x8
  __int64 v139; // x0
  int v140; // w19
  __int64 v141; // x8
  __int64 v142; // x0
  int v143; // w0
  __int64 v144; // x8
  __int64 v145; // x0
  __int64 v146; // x0
  int v147; // w19
  __int64 v148; // x8
  __int64 v149; // x0
  __int64 v150; // x0
  __int64 v151; // x0
  __int64 v152; // x8
  __int64 v153; // x0
  __int64 v154; // x0
  __int64 v155; // x0
  __int64 v156; // x0
  __int64 v157; // x0
  __int64 device_msi_addr; // x0
  __int64 v159; // x0
  __int64 v160; // x8
  __int64 v161; // x0
  __int64 v162; // x1
  unsigned __int64 StatusReg; // x19
  __int64 v164; // x20
  __int64 (__fastcall *v165)(_QWORD, _QWORD, _QWORD); // x0
  _QWORD v166[4]; // [xsp+18h] [xbp-D8h] BYREF
  __int64 (__fastcall *v167)(); // [xsp+38h] [xbp-B8h]
  __int64 v168; // [xsp+40h] [xbp-B0h] BYREF
  __int64 v169; // [xsp+48h] [xbp-A8h]
  __int64 v170; // [xsp+50h] [xbp-A0h]
  __int64 v171; // [xsp+58h] [xbp-98h]
  __int64 v172; // [xsp+60h] [xbp-90h]
  __int64 v173; // [xsp+68h] [xbp-88h]
  __int64 v174; // [xsp+70h] [xbp-80h]
  __int64 v175; // [xsp+78h] [xbp-78h]
  __int64 v176; // [xsp+80h] [xbp-70h]
  __int128 v177; // [xsp+88h] [xbp-68h]
  void *v178; // [xsp+98h] [xbp-58h]
  __int64 v179; // [xsp+A0h] [xbp-50h]
  __int64 v180; // [xsp+A8h] [xbp-48h]
  __int64 v181; // [xsp+B0h] [xbp-40h]
  __int64 (*v182)(); // [xsp+B8h] [xbp-38h]
  __int64 (__fastcall *v183)(); // [xsp+C0h] [xbp-30h]
  void (*v184)(); // [xsp+C8h] [xbp-28h]
  __int64 (__fastcall *v185)(); // [xsp+D0h] [xbp-20h]
  __int64 v186; // [xsp+D8h] [xbp-18h]
  __int64 v187; // [xsp+E0h] [xbp-10h]

  v187 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v0 = ipa3_ctx;
  v167 = nullptr;
  memset(v166, 0, sizeof(v166));
  if ( !ipa3_ctx )
  {
    result = 4294967290LL;
    goto LABEL_5;
  }
  if ( (*(_BYTE *)(ipa3_ctx + 43637) & 1) != 0 )
    goto LABEL_3;
  v185 = nullptr;
  v186 = 0;
  v183 = nullptr;
  v184 = nullptr;
  v181 = 0;
  v182 = nullptr;
  v179 = 0;
  v180 = 0;
  v178 = nullptr;
  v176 = 0;
  v177 = 0u;
  v174 = 0;
  v175 = 0;
  v172 = 0;
  v173 = 0;
  v170 = 0;
  v171 = 0;
  v168 = 0;
  v169 = 0;
  v2 = *(_QWORD *)(ipa3_ctx + 34152);
  if ( v2 )
  {
    ipc_log_string(v2, "ipa %s:%d active clients = %d\n", "ipa3_post_init", 7939, *(_DWORD *)(ipa3_ctx + 30552));
    v0 = ipa3_ctx;
  }
  v3 = *(_QWORD *)(v0 + 34160);
  if ( v3 )
  {
    v3 = ipc_log_string(v3, "ipa %s:%d active clients = %d\n", "ipa3_post_init", 7939, *(_DWORD *)(v0 + 30552));
    v0 = ipa3_ctx;
  }
  if ( *(_DWORD *)(v0 + 32240) != 14 )
    v3 = ipa3_proxy_clk_vote(0);
  ipa_save_gsi_ver(v3);
  v4 = *(unsigned int *)(ipa3_ctx + 32240);
  if ( (_DWORD)v4 != 10
    && (unsigned int)ipahal_init(
                       v4,
                       *(_QWORD *)(ipa3_ctx + 28632),
                       *(unsigned int *)(ipa3_ctx + 28648),
                       *(_QWORD *)(ipa3_ctx + 34216)) )
  {
    v22 = printk(&unk_3BD600, "ipa3_post_init");
    v23 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v24 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v24 )
      {
        ipc_log_string(v24, "ipa %s:%d fail to init ipahal\n", "ipa3_post_init", 7955);
        v23 = ipa3_ctx;
      }
      v22 = *(_QWORD *)(v23 + 34160);
      if ( v22 )
        v22 = ipc_log_string(v22, "ipa %s:%d fail to init ipahal\n", "ipa3_post_init", 7955);
    }
    v21 = -14;
    goto LABEL_229;
  }
  inited = ipa3_init_hw();
  if ( (_DWORD)inited )
  {
    v15 = printk(&unk_3F72DF, "ipa3_post_init");
    v19 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v20 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v20 )
      {
        ipc_log_string(v20, "ipa %s:%d :error initializing HW\n", "ipa3_post_init", 7963);
        v19 = ipa3_ctx;
      }
      v15 = *(_QWORD *)(v19 + 34160);
      if ( v15 )
        v15 = ipc_log_string(v15, "ipa %s:%d :error initializing HW\n", "ipa3_post_init", 7963);
    }
    goto LABEL_36;
  }
  v6 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v7 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v7 )
    {
      ipc_log_string(v7, "ipa %s:%d IPA HW initialization sequence completed", "ipa3_post_init", 7967);
      v6 = ipa3_ctx;
    }
    inited = *(_QWORD *)(v6 + 34160);
    if ( inited )
      inited = ipc_log_string(inited, "ipa %s:%d IPA HW initialization sequence completed", "ipa3_post_init", 7967);
  }
  num_pipes = ipa3_get_num_pipes(inited);
  v9 = ipa3_ctx;
  v10 = ipa3_ctx + 0x8000;
  *(_DWORD *)(ipa3_ctx + 34308) = num_pipes;
  if ( v9 )
  {
    v11 = num_pipes;
    v12 = *(_QWORD *)(v10 + 1384);
    if ( v12 )
    {
      ipc_log_string(v12, "ipa %s:%d IPA Pipes num %u\n", "ipa3_post_init", 7970, v11);
      v9 = ipa3_ctx;
    }
    v13 = *(_QWORD *)(v9 + 34160);
    if ( v13 )
    {
      ipc_log_string(v13, "ipa %s:%d IPA Pipes num %u\n", "ipa3_post_init", 7970, *(_DWORD *)(v9 + 34308));
      v9 = ipa3_ctx;
    }
  }
  v14 = v9 + 0x8000;
  if ( *(_DWORD *)(v14 + 1540) >= 0x25u )
  {
    v15 = printk(&unk_3B19C4, "ipa3_post_init");
    v16 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v17 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v17 )
      {
        ipc_log_string(
          v17,
          "ipa %s:%d IPA has more pipes then supported has %d, max %d\n",
          "ipa3_post_init",
          7973,
          *(_DWORD *)(ipa3_ctx + 34308),
          36);
        v16 = ipa3_ctx;
      }
      v18 = v16 + 0x8000;
      v15 = *(_QWORD *)(v18 + 1392);
      if ( v15 )
        v15 = ipc_log_string(
                v15,
                "ipa %s:%d IPA has more pipes then supported has %d, max %d\n",
                "ipa3_post_init",
                7973,
                *(_DWORD *)(v18 + 1540),
                36);
    }
LABEL_36:
    v21 = -19;
    goto LABEL_37;
  }
  v25 = *(__int64 (**)(void))(*(_QWORD *)(v14 + 1408) + 48LL);
  if ( *((_DWORD *)v25 - 1) != -440107680 )
    __break(0x8228u);
  v26 = v25();
  v27 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v28 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v28 )
    {
      ipc_log_string(
        v28,
        "ipa %s:%d SRAM, size: 0x%x, restricted bytes: 0x%x\n",
        "ipa3_post_init",
        7980,
        *(unsigned __int16 *)(ipa3_ctx + 29520),
        *(unsigned __int16 *)(ipa3_ctx + 29522));
      v27 = ipa3_ctx;
    }
    v26 = *(_QWORD *)(v27 + 34160);
    if ( v26 )
    {
      v26 = ipc_log_string(
              v26,
              "ipa %s:%d SRAM, size: 0x%x, restricted bytes: 0x%x\n",
              "ipa3_post_init",
              7980,
              *(unsigned __int16 *)(v27 + 29520),
              *(unsigned __int16 *)(v27 + 29522));
      v27 = ipa3_ctx;
    }
    if ( v27 )
    {
      v29 = *(_QWORD *)(v27 + 34152);
      if ( v29 )
      {
        ipc_log_string(
          v29,
          "ipa %s:%d ip4_rt_hash=%u ip4_rt_nonhash=%u\n",
          "ipa3_post_init",
          7983,
          *(unsigned __int8 *)(v27 + 30464),
          *(unsigned __int8 *)(v27 + 30466));
        v27 = ipa3_ctx;
      }
      v26 = *(_QWORD *)(v27 + 34160);
      if ( v26 )
      {
        v26 = ipc_log_string(
                v26,
                "ipa %s:%d ip4_rt_hash=%u ip4_rt_nonhash=%u\n",
                "ipa3_post_init",
                7983,
                *(unsigned __int8 *)(v27 + 30464),
                *(unsigned __int8 *)(v27 + 30466));
        v27 = ipa3_ctx;
      }
      if ( v27 )
      {
        v30 = *(_QWORD *)(v27 + 34152);
        if ( v30 )
        {
          ipc_log_string(
            v30,
            "ipa %s:%d ip6_rt_hash=%u ip6_rt_nonhash=%u\n",
            "ipa3_post_init",
            7986,
            *(unsigned __int8 *)(v27 + 30465),
            *(unsigned __int8 *)(v27 + 30467));
          v27 = ipa3_ctx;
        }
        v26 = *(_QWORD *)(v27 + 34160);
        if ( v26 )
        {
          v26 = ipc_log_string(
                  v26,
                  "ipa %s:%d ip6_rt_hash=%u ip6_rt_nonhash=%u\n",
                  "ipa3_post_init",
                  7986,
                  *(unsigned __int8 *)(v27 + 30465),
                  *(unsigned __int8 *)(v27 + 30467));
          v27 = ipa3_ctx;
        }
        if ( v27 )
        {
          v31 = *(_QWORD *)(v27 + 34152);
          if ( v31 )
          {
            ipc_log_string(
              v31,
              "ipa %s:%d ip4_flt_hash=%u ip4_flt_nonhash=%u\n",
              "ipa3_post_init",
              7990,
              *(unsigned __int8 *)(v27 + 30468),
              *(unsigned __int8 *)(v27 + 30470));
            v27 = ipa3_ctx;
          }
          v26 = *(_QWORD *)(v27 + 34160);
          if ( v26 )
          {
            v26 = ipc_log_string(
                    v26,
                    "ipa %s:%d ip4_flt_hash=%u ip4_flt_nonhash=%u\n",
                    "ipa3_post_init",
                    7990,
                    *(unsigned __int8 *)(v27 + 30468),
                    *(unsigned __int8 *)(v27 + 30470));
            v27 = ipa3_ctx;
          }
          if ( v27 )
          {
            v32 = *(_QWORD *)(v27 + 34152);
            if ( v32 )
            {
              ipc_log_string(
                v32,
                "ipa %s:%d ip6_flt_hash=%u ip6_flt_nonhash=%u\n",
                "ipa3_post_init",
                7994,
                *(unsigned __int8 *)(v27 + 30469),
                *(unsigned __int8 *)(v27 + 30471));
              v27 = ipa3_ctx;
            }
            v26 = *(_QWORD *)(v27 + 34160);
            if ( v26 )
            {
              v26 = ipc_log_string(
                      v26,
                      "ipa %s:%d ip6_flt_hash=%u ip6_flt_nonhash=%u\n",
                      "ipa3_post_init",
                      7994,
                      *(unsigned __int8 *)(v27 + 30469),
                      *(unsigned __int8 *)(v27 + 30471));
              v27 = ipa3_ctx;
            }
          }
        }
      }
    }
  }
  if ( *(unsigned __int16 *)(v27 + 29524) > (unsigned int)*(unsigned __int16 *)(v27 + 29520) )
  {
    v33 = printk(&unk_3D5010, "ipa3_post_init");
    v34 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v35 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v35 )
      {
        ipc_log_string(
          v35,
          "ipa %s:%d SW expect more core memory, needed %d, avail %d\n",
          "ipa3_post_init",
          7998,
          *(unsigned __int16 *)(ipa3_ctx + 29524),
          *(unsigned __int16 *)(ipa3_ctx + 29520));
        v34 = ipa3_ctx;
      }
      v33 = *(_QWORD *)(v34 + 34160);
      if ( v33 )
        v33 = ipc_log_string(
                v33,
                "ipa %s:%d SW expect more core memory, needed %d, avail %d\n",
                "ipa3_post_init",
                7998,
                *(unsigned __int16 *)(v34 + 29524),
                *(unsigned __int16 *)(v34 + 29520));
    }
    v21 = -12;
    v22 = ipahal_destroy(v33);
    goto LABEL_229;
  }
  dma_task_for_gsi = ipa3_allocate_dma_task_for_gsi(v26);
  if ( dma_task_for_gsi )
  {
    v21 = dma_task_for_gsi;
    v15 = printk(&unk_3A60B3, "ipa3_post_init");
    v49 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v50 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v50 )
      {
        ipc_log_string(v50, "ipa %s:%d failed to allocate dma task\n", "ipa3_post_init", 8005);
        v49 = ipa3_ctx;
      }
      v15 = *(_QWORD *)(v49 + 34160);
      if ( v15 )
      {
        v51 = ipc_log_string(v15, "ipa %s:%d failed to allocate dma task\n", "ipa3_post_init", 8005);
        v22 = ipahal_destroy(v51);
        goto LABEL_229;
      }
    }
LABEL_37:
    v22 = ipahal_destroy(v15);
LABEL_229:
    ipa3_proxy_clk_unvote(v22);
    result = v21;
    goto LABEL_5;
  }
  v37 = ((__int64 (*)(void))ipa3_allocate_coal_close_frame)();
  if ( v37 )
  {
    v21 = v37;
    v52 = printk(&unk_3D208A, "ipa3_post_init");
    v53 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v54 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v54 )
      {
        ipc_log_string(v54, "ipa %s:%d failed to allocate coal frame cmd\n", "ipa3_post_init", 8011);
        v53 = ipa3_ctx;
      }
      v52 = *(_QWORD *)(v53 + 34160);
      if ( v52 )
        v52 = ipc_log_string(v52, "ipa %s:%d failed to allocate coal frame cmd\n", "ipa3_post_init", 8011);
    }
    goto LABEL_228;
  }
  if ( (unsigned int)ipa3_nat_ipv6ct_init_devices() )
  {
    v55 = printk(&unk_3C9330, "ipa3_post_init");
    v56 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v57 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v57 )
      {
        ipc_log_string(v57, "ipa %s:%d unable to init NAT and IPv6CT devices\n", "ipa3_post_init", 8016);
        v56 = ipa3_ctx;
      }
      v55 = *(_QWORD *)(v56 + 34160);
      if ( v55 )
        v55 = ipc_log_string(v55, "ipa %s:%d unable to init NAT and IPv6CT devices\n", "ipa3_post_init", 8016);
    }
    goto LABEL_227;
  }
  v38 = ipa3_alloc_pkt_init();
  if ( (_DWORD)v38 )
  {
    v58 = printk(&unk_3F1893, "ipa3_post_init");
    v59 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v60 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v60 )
      {
        ipc_log_string(v60, "ipa %s:%d Failed to alloc pkt_init payload\n", "ipa3_post_init", 8023);
        v59 = ipa3_ctx;
      }
      v58 = *(_QWORD *)(v59 + 34160);
      if ( v58 )
        v58 = ipc_log_string(v58, "ipa %s:%d Failed to alloc pkt_init payload\n", "ipa3_post_init", 8023);
    }
    goto LABEL_226;
  }
  v39 = *(_DWORD *)(ipa3_ctx + 32240);
  if ( v39 >= 0x15 )
  {
    v38 = ipa_alloc_pkt_init_ex();
    if ( (_DWORD)v38 )
    {
      v88 = printk(&unk_3C32D9, "ipa3_post_init");
      v89 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v90 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v90 )
        {
          ipc_log_string(v90, "ipa %s:%d Failed to alloc pkt_init_ex payload\n", "ipa3_post_init", 8031);
          v89 = ipa3_ctx;
        }
        v88 = *(_QWORD *)(v89 + 34160);
        if ( v88 )
          v88 = ipc_log_string(v88, "ipa %s:%d Failed to alloc pkt_init_ex payload\n", "ipa3_post_init", 8031);
      }
      goto LABEL_225;
    }
    v39 = *(_DWORD *)(ipa3_ctx + 32240);
  }
  if ( v39 >= 0xC )
    v38 = ipa3_enable_dcd();
  v40 = ipa_init_ep_flt_bitmap(v38);
  v41 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v42 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v42 )
    {
      ipc_log_string(
        v42,
        "ipa %s:%d EP with flt support bitmap 0x%llx (%u pipes)\n",
        "ipa3_post_init",
        8048,
        *(_QWORD *)(ipa3_ctx + 17488),
        *(_DWORD *)(ipa3_ctx + 17496));
      v41 = ipa3_ctx;
    }
    v40 = *(_QWORD *)(v41 + 34160);
    if ( v40 )
      v40 = ipc_log_string(
              v40,
              "ipa %s:%d EP with flt support bitmap 0x%llx (%u pipes)\n",
              "ipa3_post_init",
              8048,
              *(_QWORD *)(v41 + 17488),
              *(_DWORD *)(v41 + 17496));
  }
  v43 = ipa3_set_resorce_groups_min_max_limits(v40);
  is_ep_support_flt = ipa3_set_resorce_groups_config(v43);
  v45 = (_QWORD *)ipa3_ctx;
  *(_QWORD *)(ipa3_ctx + 28584) = 0x1000000400000000LL;
  v45[3577] = 0;
  v45[3576] = 0x1000000400000000LL;
  v46 = (_QWORD *)ipa3_ctx;
  v45[3574] = 0;
  v45[3575] = 0;
  v45[3578] = 0;
  v46[3809] = v46 + 3809;
  v46[3810] = v46 + 3809;
  v46[3811] = v46 + 3811;
  v46[3812] = v46 + 3811;
  v47 = ipa3_ctx;
  if ( !*(_DWORD *)(ipa3_ctx + 34308) )
  {
LABEL_93:
    if ( (*(_BYTE *)(v47 + 43308) & 1) != 0 )
    {
      if ( v47 )
      {
        v48 = *(_QWORD *)(v47 + 34152);
        if ( v48 )
        {
          ipc_log_string(v48, "ipa %s:%d Initialization of ipa interrupts skipped\n", "ipa3_post_init", 8108);
          v47 = ipa3_ctx;
        }
        is_ep_support_flt = *(_QWORD *)(v47 + 34160);
        if ( is_ep_support_flt )
          is_ep_support_flt = ipc_log_string(
                                is_ep_support_flt,
                                "ipa %s:%d Initialization of ipa interrupts skipped\n",
                                "ipa3_post_init",
                                8108);
      }
    }
    else
    {
      is_ep_support_flt = ipa3_init_interrupts();
      if ( (_DWORD)is_ep_support_flt )
      {
        printk(&unk_3C663C, "ipa3_post_init");
        v91 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v92 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v92 )
          {
            ipc_log_string(v92, "ipa %s:%d ipa initialization of interrupts failed\n", "ipa3_post_init", 8103);
            v91 = ipa3_ctx;
          }
          v93 = *(_QWORD *)(v91 + 34160);
          if ( v93 )
            ipc_log_string(v93, "ipa %s:%d ipa initialization of interrupts failed\n", "ipa3_post_init", 8103);
        }
LABEL_223:
        ((void (__fastcall *)(__int64))ipa3_remove_interrupt_handler)(13);
        v88 = ipa3_interrupts_destroy((unsigned int)dword_1F7DCC, *(_QWORD *)(ipa3_ctx + 34208) + 16LL);
        if ( *(_DWORD *)(ipa3_ctx + 32240) >= 0x15u )
          v88 = ipa3_free_pkt_init_ex(v88);
LABEL_225:
        v58 = ipa3_free_pkt_init(v88);
LABEL_226:
        v55 = ipa3_nat_ipv6ct_destroy_devices(v58);
LABEL_227:
        v52 = ipa3_free_coal_close_frame(v55);
        v21 = -19;
LABEL_228:
        v111 = ipa3_free_dma_task_for_gsi(v52);
        v22 = ipahal_destroy(v111);
        goto LABEL_229;
      }
    }
    v68 = ipa3_ctx;
    v69 = *(_DWORD *)(ipa3_ctx + 32240);
    if ( (v69 & 0xFFFFFFFE) == 0xC && (*(_BYTE *)(ipa3_ctx + 32260) & 1) == 0 )
    {
      is_ep_support_flt = ipa3_disable_prefetch(19);
      v68 = ipa3_ctx;
      v69 = *(_DWORD *)(ipa3_ctx + 32240);
    }
    if ( (v69 & 0xFFFFFFFE) == 0xC && *(_BYTE *)(v68 + 32260) == 1 )
    {
      is_ep_support_flt = ipa3_disable_prefetch(43);
      v68 = ipa3_ctx;
    }
    v185 = nullptr;
    v186 = 0;
    v183 = nullptr;
    v184 = nullptr;
    v181 = 0;
    v182 = nullptr;
    v179 = 0;
    v180 = 0;
    v178 = nullptr;
    v176 = 0;
    v177 = 0u;
    v174 = 0;
    v175 = 0;
    v172 = 0;
    v173 = 0;
    v170 = 0;
    v171 = 0;
    v169 = 0;
    LODWORD(v168) = *(_DWORD *)(v68 + 32252);
    HIDWORD(v168) = dword_1F7DE8;
    LODWORD(v169) = 1;
    v172 = (unsigned int)dword_1F7DB4;
    v173 = (unsigned int)dword_1F7DB8;
    if ( *(_DWORD *)(v68 + 32248) == 3 )
    {
      LODWORD(v171) = dword_1F7DC8;
      isr = ipa3_get_isr(is_ep_support_flt);
      v68 = ipa3_ctx;
      v175 = (unsigned int)dword_1F7DC4;
      v176 = isr;
      v174 = (unsigned int)dword_1F7DC0;
    }
    else
    {
      LODWORD(v171) = dword_1F7DD0;
    }
    v179 = 0;
    v180 = 0;
    v182 = ipa3_active_clks_status;
    v183 = ipa3_handle_gsi_differ_irq;
    v184 = ipa3_inc_client_enable_clks_no_log;
    v71 = *(_BYTE *)(v68 + 32260) == 1;
    v178 = &ipa_gsi_notify_cb;
    v185 = ipa3_dec_client_disable_clks_no_log;
    if ( v71 )
    {
      LOBYTE(v177) = 1;
      *(_QWORD *)((char *)&v177 + 4) = qword_1F7E08;
    }
    BYTE1(v186) = byte_1F7E06;
    LOBYTE(v186) = HIBYTE(word_1F7EF0);
    v72 = gsi_register_device(&v168, v68 + 43296);
    if ( (_DWORD)v72 )
    {
      v84 = v72;
      v85 = printk(&unk_3C024F, "ipa3_post_init");
      v86 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v87 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v87 )
        {
          ipc_log_string(v87, "ipa %s:%d :gsi register error - %d\n", "ipa3_post_init", 8160, v84);
          v86 = ipa3_ctx;
        }
        v85 = *(_QWORD *)(v86 + 34160);
        if ( v85 )
          v85 = ipc_log_string(v85, "ipa %s:%d :gsi register error - %d\n", "ipa3_post_init", 8160, v84);
      }
    }
    else
    {
      v73 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v74 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v74 )
        {
          ipc_log_string(v74, "ipa %s:%d IPA gsi is registered\n", "ipa3_post_init", 8164);
          v73 = ipa3_ctx;
        }
        v72 = *(_QWORD *)(v73 + 34160);
        if ( v72 )
          v72 = ipc_log_string(v72, "ipa %s:%d IPA gsi is registered\n", "ipa3_post_init", 8164);
      }
      if ( (_DWORD)v168 == 5 && (v72 = ipa3_alloc_gsi_channel(v72), (_DWORD)v72) )
      {
        printk(&unk_3D7DC8, "ipa3_post_init");
        v97 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v98 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v98 )
          {
            ipc_log_string(v98, "ipa %s:%d Failed to alloc the GSI channels\n", "ipa3_post_init", 8171);
            v97 = ipa3_ctx;
          }
          v99 = *(_QWORD *)(v97 + 34160);
          if ( v99 )
            ipc_log_string(v99, "ipa %s:%d Failed to alloc the GSI channels\n", "ipa3_post_init", 8171);
        }
      }
      else
      {
        if ( *(_BYTE *)(ipa3_ctx + 45390) == 1 )
          v72 = napi_enable(ipa3_ctx + 48128);
        v75 = ipa3_setup_apps_pipes(v72);
        if ( (_DWORD)v75 )
        {
          printk(&unk_3FD6DA, "ipa3_post_init");
          v94 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v95 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v95 )
            {
              ipc_log_string(v95, "ipa %s:%d :failed to setup IPA-Apps pipes\n", "ipa3_post_init", 8180);
              v94 = ipa3_ctx;
            }
            v96 = *(_QWORD *)(v94 + 34160);
            if ( v96 )
              ipc_log_string(v96, "ipa %s:%d :failed to setup IPA-Apps pipes\n", "ipa3_post_init", 8180);
          }
        }
        else
        {
          v76 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v77 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v77 )
            {
              ipc_log_string(v77, "ipa %s:%d IPA GPI pipes were connected\n", "ipa3_post_init", 8184);
              v76 = ipa3_ctx;
            }
            v75 = *(_QWORD *)(v76 + 34160);
            if ( v75 )
            {
              v75 = ipc_log_string(v75, "ipa %s:%d IPA GPI pipes were connected\n", "ipa3_post_init", 8184);
              v76 = ipa3_ctx;
            }
          }
          if ( *(_BYTE *)(v76 + 32261) != 1 )
          {
LABEL_172:
            v80 = ipa3_uc_interface_init(v75);
            if ( v80 )
            {
              v100 = -v80;
              printk(&unk_3E31C1, "ipa3_post_init");
              v101 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v102 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v102 )
                {
                  ipc_log_string(v102, "ipa %s:%d :ipa Uc interface init failed (%d)\n", "ipa3_post_init", 8199, v100);
                  v101 = ipa3_ctx;
                }
                v103 = *(_QWORD *)(v101 + 34160);
                if ( v103 )
                  ipc_log_string(v103, "ipa %s:%d :ipa Uc interface init failed (%d)\n", "ipa3_post_init", 8199, v100);
              }
            }
            else
            {
              v81 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v82 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v82 )
                {
                  ipc_log_string(v82, "ipa %s:%d :ipa Uc interface init ok\n", "ipa3_post_init", 8201);
                  v81 = ipa3_ctx;
                }
                v83 = *(_QWORD *)(v81 + 34160);
                if ( v83 )
                  ipc_log_string(v83, "ipa %s:%d :ipa Uc interface init ok\n", "ipa3_post_init", 8201);
              }
            }
            v166[0] = ipa3_uc_is_loaded;
            v167 = ipa3_uc_holb_client_handler;
            v104 = ipa3_uc_register_handlers(0, v166);
            if ( *(_BYTE *)(ipa3_ctx + 51105) == 1 )
            {
              v104 = ipa3_setup_tput_pipe(v104);
              if ( (_DWORD)v104 )
              {
                v104 = printk(&unk_3B7859, "ipa3_post_init");
                v112 = ipa3_ctx;
                if ( ipa3_ctx )
                {
                  v113 = *(_QWORD *)(ipa3_ctx + 34152);
                  if ( v113 )
                  {
                    ipc_log_string(
                      v113,
                      "ipa %s:%d :Failed configuring throughput moniter ep\n",
                      "ipa3_post_init",
                      8209);
                    v112 = ipa3_ctx;
                  }
                  v104 = *(_QWORD *)(v112 + 34160);
                  if ( v104 )
                    v104 = ipc_log_string(
                             v104,
                             "ipa %s:%d :Failed configuring throughput moniter ep\n",
                             "ipa3_post_init",
                             8209);
                }
              }
              else
              {
                v105 = ipa3_ctx;
                if ( ipa3_ctx )
                {
                  v106 = *(_QWORD *)(ipa3_ctx + 34152);
                  if ( v106 )
                  {
                    ipc_log_string(v106, "ipa %s:%d :Throughput moniter ep configured\n", "ipa3_post_init", 8211);
                    v105 = ipa3_ctx;
                  }
                  v104 = *(_QWORD *)(v105 + 34160);
                  if ( v104 )
                    v104 = ipc_log_string(v104, "ipa %s:%d :Throughput moniter ep configured\n", "ipa3_post_init", 8211);
                }
              }
            }
            v114 = ipa3_wdi_init(v104);
            if ( (_DWORD)v114 )
            {
              v117 = -(int)v114;
              v114 = printk(&unk_3BD621, "ipa3_post_init");
              v118 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v119 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v119 )
                {
                  ipc_log_string(v119, "ipa %s:%d :wdi init failed (%d)\n", "ipa3_post_init", 8216, v117);
                  v118 = ipa3_ctx;
                }
                v114 = *(_QWORD *)(v118 + 34160);
                if ( v114 )
                  v114 = ipc_log_string(v114, "ipa %s:%d :wdi init failed (%d)\n", "ipa3_post_init", 8216, v117);
              }
            }
            else
            {
              v115 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v116 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v116 )
                {
                  ipc_log_string(v116, "ipa %s:%d :wdi init ok\n", "ipa3_post_init", 8218);
                  v115 = ipa3_ctx;
                }
                v114 = *(_QWORD *)(v115 + 34160);
                if ( v114 )
                  v114 = ipc_log_string(v114, "ipa %s:%d :wdi init ok\n", "ipa3_post_init", 8218);
              }
            }
            v120 = ipa3_wigig_init_i(v114);
            if ( (_DWORD)v120 )
            {
              v123 = -(int)v120;
              v120 = printk(&unk_3B4696, "ipa3_post_init");
              v124 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v125 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v125 )
                {
                  ipc_log_string(v125, "ipa %s:%d :wigig init failed (%d)\n", "ipa3_post_init", 8222, v123);
                  v124 = ipa3_ctx;
                }
                v120 = *(_QWORD *)(v124 + 34160);
                if ( v120 )
                  v120 = ipc_log_string(v120, "ipa %s:%d :wigig init failed (%d)\n", "ipa3_post_init", 8222, v123);
              }
            }
            else
            {
              v121 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v122 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v122 )
                {
                  ipc_log_string(v122, "ipa %s:%d :wigig init ok\n", "ipa3_post_init", 8224);
                  v121 = ipa3_ctx;
                }
                v120 = *(_QWORD *)(v121 + 34160);
                if ( v120 )
                  v120 = ipc_log_string(v120, "ipa %s:%d :wigig init ok\n", "ipa3_post_init", 8224);
              }
            }
            v126 = ipa3_ntn_init(v120);
            if ( (_DWORD)v126 )
            {
              v129 = -(int)v126;
              v126 = printk(&unk_3DDC19, "ipa3_post_init");
              v130 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v131 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v131 )
                {
                  ipc_log_string(v131, "ipa %s:%d :ntn init failed (%d)\n", "ipa3_post_init", 8228, v129);
                  v130 = ipa3_ctx;
                }
                v126 = *(_QWORD *)(v130 + 34160);
                if ( v126 )
                  v126 = ipc_log_string(v126, "ipa %s:%d :ntn init failed (%d)\n", "ipa3_post_init", 8228, v129);
              }
            }
            else
            {
              v127 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v128 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v128 )
                {
                  ipc_log_string(v128, "ipa %s:%d :ntn init ok\n", "ipa3_post_init", 8230);
                  v127 = ipa3_ctx;
                }
                v126 = *(_QWORD *)(v127 + 34160);
                if ( v126 )
                  v126 = ipc_log_string(v126, "ipa %s:%d :ntn init ok\n", "ipa3_post_init", 8230);
              }
            }
            v132 = ipa_hw_stats_init(v126);
            if ( (_DWORD)v132 )
            {
              v135 = v132;
              v132 = printk(&unk_3E5BFA, "ipa3_post_init");
              v136 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v137 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v137 )
                {
                  ipc_log_string(v137, "ipa %s:%d fail to init stats %d\n", "ipa3_post_init", 8241, v135);
                  v136 = ipa3_ctx;
                }
                v132 = *(_QWORD *)(v136 + 34160);
                if ( v132 )
                  v132 = ipc_log_string(v132, "ipa %s:%d fail to init stats %d\n", "ipa3_post_init", 8241, v135);
              }
            }
            else
            {
              v133 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v134 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v134 )
                {
                  ipc_log_string(v134, "ipa %s:%d :stats init ok\n", "ipa3_post_init", 8243);
                  v133 = ipa3_ctx;
                }
                v132 = *(_QWORD *)(v133 + 34160);
                if ( v132 )
                  v132 = ipc_log_string(v132, "ipa %s:%d :stats init ok\n", "ipa3_post_init", 8243);
              }
            }
            if ( *(_DWORD *)(ipa3_ctx + 32240) >= 0x11u )
            {
              v132 = ipa_init_flt_rt_stats(v132);
              if ( (_DWORD)v132 )
              {
                v140 = v132;
                v132 = printk(&unk_3E0548, "ipa3_post_init");
                v141 = ipa3_ctx;
                if ( ipa3_ctx )
                {
                  v142 = *(_QWORD *)(ipa3_ctx + 34152);
                  if ( v142 )
                  {
                    ipc_log_string(v142, "ipa %s:%d fail to init FnR stats %d\n", "ipa3_post_init", 8248, v140);
                    v141 = ipa3_ctx;
                  }
                  v132 = *(_QWORD *)(v141 + 34160);
                  if ( v132 )
                    v132 = ipc_log_string(v132, "ipa %s:%d fail to init FnR stats %d\n", "ipa3_post_init", 8248, v140);
                }
              }
              else
              {
                v138 = ipa3_ctx;
                if ( ipa3_ctx )
                {
                  v139 = *(_QWORD *)(ipa3_ctx + 34152);
                  if ( v139 )
                  {
                    ipc_log_string(v139, "ipa %s:%d :FnR stats init ok\n", "ipa3_post_init", 8250);
                    v138 = ipa3_ctx;
                  }
                  v132 = *(_QWORD *)(v138 + 34160);
                  if ( v132 )
                    v132 = ipc_log_string(v132, "ipa %s:%d :FnR stats init ok\n", "ipa3_post_init", 8250);
                }
              }
            }
            v143 = ipa_drop_stats_init(v132);
            if ( v143 )
            {
              v147 = v143;
              printk(&unk_3E5BFA, "ipa3_post_init");
              v148 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v149 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v149 )
                {
                  ipc_log_string(v149, "ipa %s:%d fail to init stats %d\n", "ipa3_post_init", 8255, v147);
                  v148 = ipa3_ctx;
                }
                v150 = *(_QWORD *)(v148 + 34160);
                if ( v150 )
                  ipc_log_string(v150, "ipa %s:%d fail to init stats %d\n", "ipa3_post_init", 8255, v147);
              }
            }
            else
            {
              v144 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v145 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v145 )
                {
                  ipc_log_string(v145, "ipa %s:%d :stats init ok\n", "ipa3_post_init", 8257);
                  v144 = ipa3_ctx;
                }
                v146 = *(_QWORD *)(v144 + 34160);
                if ( v146 )
                  ipc_log_string(v146, "ipa %s:%d :stats init ok\n", "ipa3_post_init", 8257);
              }
            }
            v151 = atomic_notifier_chain_register(&panic_notifier_list, &ipa3_panic_blk);
            ipa3_debugfs_init(v151);
            v152 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v153 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v153 )
              {
                ipc_log_string(v153, "ipa %s:%d :mpm init init ok\n", "ipa3_post_init", 8268);
                v152 = ipa3_ctx;
              }
              v154 = *(_QWORD *)(v152 + 34160);
              if ( v154 )
              {
                ipc_log_string(v154, "ipa %s:%d :mpm init init ok\n", "ipa3_post_init", 8268);
                v152 = ipa3_ctx;
              }
            }
            mutex_lock(v152 + 29472);
            v155 = ipa3_ctx + 29472;
            *(_BYTE *)(ipa3_ctx + 43637) = 1;
            v156 = mutex_unlock(v155);
            v157 = ipa3_setup_uc_act_tbl(v156);
            ipa_trigger_ipa_ready_cbs(v157);
            complete_all(ipa3_ctx + 43656);
            device_msi_addr = gsi_query_device_msi_addr(ipa3_ctx + 51248);
            if ( *(_QWORD *)(ipa3_ctx + 51248) )
              device_msi_addr = ipa_gsi_map_unmap_gsi_msi_addr(device_msi_addr);
            v159 = ipa_tlpd_stats_init(device_msi_addr);
            if ( !(_DWORD)v159 )
            {
              v160 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v161 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v161 )
                {
                  ipc_log_string(v161, "ipa %s:%d Fail to init tlpd ipa lnx module", "ipa3_post_init", 8288);
                  v160 = ipa3_ctx;
                }
                v159 = *(_QWORD *)(v160 + 34160);
                if ( v159 )
                  v159 = ipc_log_string(v159, "ipa %s:%d Fail to init tlpd ipa lnx module", "ipa3_post_init", 8288);
              }
            }
            ipa_ssr_driver_dump_init(v159);
            ((void (__fastcall *)(const char *, __int64, __int64))ipa_ssr_driver_dump_register_region)(
              "ipa_ctx",
              ipa3_ctx,
              52544);
            ((void (__fastcall *)(const char *, _QWORD, _QWORD))ipa_ssr_driver_dump_register_region)(
              "ipc_logs",
              *(_QWORD *)(ipa3_ctx + 34152),
              *(unsigned int *)(*(_QWORD *)(ipa3_ctx + 34152) + 128LL));
            ((void (__fastcall *)(const char *, _QWORD, __int64))ipa_ssr_driver_dump_register_region)(
              "gsi_ctx",
              gsi_ctx,
              29272);
            printk(&unk_3A6119, v162);
            result = _kmalloc_cache_noprof(_kmalloc_cache_noprof, 3520, 72);
            if ( result )
              goto LABEL_316;
            goto LABEL_5;
          }
          v75 = ipa3_teth_bridge_driver_init();
          if ( !(_DWORD)v75 )
          {
            v78 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v79 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v79 )
              {
                ipc_log_string(v79, "ipa %s:%d teth_bridge initialized", "ipa3_post_init", 8194);
                v78 = ipa3_ctx;
              }
              v75 = *(_QWORD *)(v78 + 34160);
              if ( v75 )
                v75 = ipc_log_string(v75, "ipa %s:%d teth_bridge initialized", "ipa3_post_init", 8194);
            }
            goto LABEL_172;
          }
          v107 = -(int)v75;
          v108 = printk(&unk_3A91D6, "ipa3_post_init");
          v109 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v110 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v110 )
            {
              ipc_log_string(v110, "ipa %s:%d :teth_bridge init failed (%d)\n", "ipa3_post_init", 8190, v107);
              v109 = ipa3_ctx;
            }
            v108 = *(_QWORD *)(v109 + 34160);
            if ( v108 )
              v108 = ipc_log_string(v108, "ipa %s:%d :teth_bridge init failed (%d)\n", "ipa3_post_init", 8190, v107);
          }
          ipa3_teardown_apps_pipes(v108);
        }
      }
      v85 = gsi_deregister_device(*(_QWORD *)(ipa3_ctx + 43296), 0);
    }
    ipa3_destroy_flt_tbl_idrs(v85);
    goto LABEL_223;
  }
  v61 = 0;
  _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    is_ep_support_flt = ipa_is_ep_support_flt((unsigned int)v61);
    if ( (is_ep_support_flt & 1) != 0 )
      break;
LABEL_120:
    v47 = ipa3_ctx;
    if ( ++v61 >= *(unsigned int *)(ipa3_ctx + 34308) )
      goto LABEL_93;
  }
  if ( v61 <= 0x23 )
  {
    v62 = 0;
    v63 = 1;
    do
    {
      v65 = v63;
      v66 = ipa3_ctx + 304 * v61 + 152 * v62;
      v67 = v66 + 17640;
      *(_QWORD *)(v66 + 17640) = v66 + 17640;
      *(_QWORD *)(v66 + 17648) = v66 + 17640;
      *(_BYTE *)(v66 + 17660) = *(_BYTE *)(ipa3_ctx + v62 + 30468) ^ 1;
      if ( *(_BYTE *)(ipa3_ctx + v62 + 30470) == 1
        && (v61 == (unsigned int)ipa_get_ep_mapping(48)
         || v61 == (unsigned int)ipa_get_ep_mapping(116)
         || v61 == (unsigned int)ipa_get_ep_mapping(102)
         || (is_ep_support_flt = ipa_get_ep_mapping(108), v61 == (unsigned int)is_ep_support_flt)
         || *(_DWORD *)(ipa3_ctx + 32248) == 4
         && (is_ep_support_flt = ipa_get_ep_mapping(62), v61 == (unsigned int)is_ep_support_flt)) )
      {
        *(_BYTE *)(v67 + 21) = 0;
        is_ep_support_flt = _kmalloc_cache_noprof(of_property_read_variable_u32_array, 3520, 24);
        if ( is_ep_support_flt )
        {
          __break(0x800u);
          *(_QWORD *)(is_ep_support_flt + 16) = v67;
          is_ep_support_flt = list_add();
        }
      }
      else
      {
        *(_BYTE *)(v67 + 21) = 1;
      }
      *(_WORD *)(v67 + 144) = 0;
      v63 = 0;
      v64 = ipa3_ctx + 24 * v62;
      v62 = 1;
      *(_QWORD *)(v67 + 136) = v64 + 28584;
    }
    while ( (v65 & 1) != 0 );
    goto LABEL_120;
  }
  __break(0x5512u);
  StatusReg = _ReadStatusReg(SP_EL0);
  v164 = *(_QWORD *)(StatusReg + 80);
  v165 = _kmalloc_cache_noprof;
  *(_QWORD *)(StatusReg + 80) = &ipa3_post_init__alloc_tag_834;
  result = _kmalloc_cache_noprof(v165, 3520, 72);
  *(_QWORD *)(StatusReg + 80) = v164;
  if ( !result )
    goto LABEL_5;
LABEL_316:
  *(_QWORD *)(result + 16) = ipa3_ctx;
  strcpy((char *)(result + 24), "ipa3_ctx");
  *(_DWORD *)(result + 56) = 52544;
  list_add();
LABEL_3:
  result = 0;
LABEL_5:
  _ReadStatusReg(SP_EL0);
  return result;
}
