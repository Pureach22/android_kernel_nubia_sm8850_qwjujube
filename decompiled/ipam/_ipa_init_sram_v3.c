__int64 ipa_init_sram_v3()
{
  __int64 v0; // x8
  __int64 v1; // x19
  int v2; // w20
  int v3; // w21
  int v4; // w0
  __int64 v5; // x19
  __int64 v6; // x9
  __int64 v7; // x8
  int v8; // w20
  int v9; // w21
  int v10; // w0
  int v11; // w19
  __int64 v12; // x0
  __int64 v13; // x2
  __int64 v14; // x0
  int v15; // w8
  int v16; // w10
  int v17; // w8
  int v18; // w10
  int v19; // w11
  int v20; // w10
  int v21; // w10
  int v22; // w11
  int v23; // w10
  int v24; // w10
  int v25; // w11
  int v26; // w10
  int v27; // w10
  int v28; // w11
  int v29; // w10
  int v30; // w10
  int v31; // w11
  int v32; // w10
  int v33; // w10
  int v34; // w11
  int v35; // w10
  int v36; // w10
  int v37; // w11
  int v38; // w10
  int v39; // w10
  int v40; // w11
  int v41; // w10
  int v42; // w10
  int v43; // w11
  int v44; // w10
  int v45; // w10
  int v46; // w11
  int v47; // w10
  int v48; // w10
  int v49; // w11
  int v50; // w10
  int v51; // w10
  int v52; // w11
  int v53; // w10
  int v54; // w10
  int v55; // w11
  int v56; // w10
  int v57; // w10
  int v58; // w11
  int v59; // w10
  int v60; // w10
  int v61; // w11
  int v62; // w10
  int v63; // w10
  int v64; // w11
  int v65; // w10
  int v66; // w10
  int v67; // w11
  int v68; // w10
  int v69; // w10
  int v70; // w11
  int v71; // w10
  int v72; // w10
  int v73; // w11
  int v74; // w10
  __int64 v75; // x10
  __int64 v76; // x9
  int v77; // w9
  int v78; // w10
  int v79; // w9
  __int64 v80; // x10
  unsigned int v81; // w9
  int v82; // w9
  int v83; // w10
  int v84; // w9
  int v85; // w9
  int v86; // w11
  int v87; // w9
  int v88; // w9
  int v89; // w11
  int v90; // w9
  __int64 v91; // x9
  int v92; // w10
  int v93; // w9
  int v94; // w10
  int v95; // w9
  int v96; // w11
  int v97; // w9
  int v98; // w9
  int v99; // w10
  int v100; // w9
  int v101; // w9
  int v102; // w10
  int v103; // w9
  int v104; // w9
  int v105; // w11
  int v106; // w9
  int v107; // w9
  int v108; // w11
  int v109; // w9
  int v110; // w9
  int v111; // w10
  int v112; // w9
  unsigned int v113; // w11
  int v114; // w9
  int v115; // w10
  int v116; // w9
  __int64 v117; // x10
  int v118; // w9
  int v119; // w10
  int v120; // w9
  __int64 v121; // x8
  __int64 v123; // x8
  __int64 v124; // x0
  __int64 v125; // x0

  v0 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v1 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v1 )
    {
      v2 = *(_DWORD *)(ipa3_ctx + 28640);
      v3 = *(_DWORD *)(*(_QWORD *)(ipa3_ctx + 34176) + 36LL);
      v4 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))ipahal_get_reg_mn_ofst)(
             64,
             0,
             *(unsigned __int16 *)(ipa3_ctx + 29522) >> 2);
      ipc_log_string(
        v1,
        "ipa %s:%d ipa_wrapper_base(0x%08X) ipa_reg_base_ofst(0x%08X) IPA_SW_AREA_RAM_DIRECT_ACCESS_n(0x%08X) smem_restri"
        "cted_bytes(0x%08X) smem_sz(0x%08X)\n",
        "_ipa_init_sram_v3",
        5650,
        v2,
        v3,
        v4,
        *(unsigned __int16 *)(ipa3_ctx + 29522),
        *(unsigned __int16 *)(ipa3_ctx + 29520));
      v0 = ipa3_ctx;
    }
    v5 = *(_QWORD *)(v0 + 34160);
    if ( v5 )
    {
      v6 = *(_QWORD *)(v0 + 34176);
      v7 = v0 + 28640;
      v8 = *(_DWORD *)v7;
      v9 = *(_DWORD *)(v6 + 36);
      v10 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))ipahal_get_reg_mn_ofst)(
              64,
              0,
              *(unsigned __int16 *)(v7 + 882) >> 2);
      ipc_log_string(
        v5,
        "ipa %s:%d ipa_wrapper_base(0x%08X) ipa_reg_base_ofst(0x%08X) IPA_SW_AREA_RAM_DIRECT_ACCESS_n(0x%08X) smem_restri"
        "cted_bytes(0x%08X) smem_sz(0x%08X)\n",
        "_ipa_init_sram_v3",
        5650,
        v8,
        v9,
        v10,
        *(unsigned __int16 *)(ipa3_ctx + 29522),
        *(unsigned __int16 *)(ipa3_ctx + 29520));
      v0 = ipa3_ctx;
    }
  }
  v11 = *(_DWORD *)(*(_QWORD *)(v0 + 34176) + 36LL) + *(_DWORD *)(v0 + 28640);
  v12 = v11
      + (unsigned int)((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))ipahal_get_reg_mn_ofst)(
                        64,
                        0,
                        *(unsigned __int16 *)(v0 + 29522) >> 2);
  if ( arm64_use_ng_mappings )
    v13 = 0x68000000000F13LL;
  else
    v13 = 0x68000000000713LL;
  v14 = ioremap_prot(v12, *(unsigned __int16 *)(ipa3_ctx + 29520), v13);
  if ( v14 )
  {
    v15 = *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + 4LL);
    v16 = v15 - 8;
    v17 = v15 - 5;
    if ( v16 >= 0 )
      v17 = v16;
    *(_DWORD *)(v14 + 4LL * (v17 >> 2)) = -559038737;
    v18 = *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + 4LL);
    v19 = v18 - 4;
    v20 = v18 - 1;
    if ( v19 >= 0 )
      v20 = v19;
    *(_DWORD *)(v14 + 4LL * (v20 >> 2)) = -559038737;
    v21 = *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + 16LL);
    v22 = v21 - 8;
    v23 = v21 - 5;
    if ( v22 >= 0 )
      v23 = v22;
    *(_DWORD *)(v14 + 4LL * (v23 >> 2)) = -559038737;
    v24 = *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + 16LL);
    v25 = v24 - 4;
    v26 = v24 - 1;
    if ( v25 >= 0 )
      v26 = v25;
    *(_DWORD *)(v14 + 4LL * (v26 >> 2)) = -559038737;
    v27 = *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + 28LL);
    v28 = v27 - 8;
    v29 = v27 - 5;
    if ( v28 >= 0 )
      v29 = v28;
    *(_DWORD *)(v14 + 4LL * (v29 >> 2)) = -559038737;
    v30 = *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + 28LL);
    v31 = v30 - 4;
    v32 = v30 - 1;
    if ( v31 >= 0 )
      v32 = v31;
    *(_DWORD *)(v14 + 4LL * (v32 >> 2)) = -559038737;
    v33 = *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + 40LL);
    v34 = v33 - 8;
    v35 = v33 - 5;
    if ( v34 >= 0 )
      v35 = v34;
    *(_DWORD *)(v14 + 4LL * (v35 >> 2)) = -559038737;
    v36 = *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + 40LL);
    v37 = v36 - 4;
    v38 = v36 - 1;
    if ( v37 >= 0 )
      v38 = v37;
    *(_DWORD *)(v14 + 4LL * (v38 >> 2)) = -559038737;
    v39 = *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + 72LL);
    v40 = v39 - 8;
    v41 = v39 - 5;
    if ( v40 >= 0 )
      v41 = v40;
    *(_DWORD *)(v14 + 4LL * (v41 >> 2)) = -559038737;
    v42 = *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + 72LL);
    v43 = v42 - 4;
    v44 = v42 - 1;
    if ( v43 >= 0 )
      v44 = v43;
    *(_DWORD *)(v14 + 4LL * (v44 >> 2)) = -559038737;
    v45 = *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + 84LL);
    v46 = v45 - 8;
    v47 = v45 - 5;
    if ( v46 >= 0 )
      v47 = v46;
    *(_DWORD *)(v14 + 4LL * (v47 >> 2)) = -559038737;
    v48 = *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + 84LL);
    v49 = v48 - 4;
    v50 = v48 - 1;
    if ( v49 >= 0 )
      v50 = v49;
    *(_DWORD *)(v14 + 4LL * (v50 >> 2)) = -559038737;
    v51 = *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + 116LL);
    v52 = v51 - 8;
    v53 = v51 - 5;
    if ( v52 >= 0 )
      v53 = v52;
    *(_DWORD *)(v14 + 4LL * (v53 >> 2)) = -559038737;
    v54 = *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + 116LL);
    v55 = v54 - 4;
    v56 = v54 - 1;
    if ( v55 >= 0 )
      v56 = v55;
    *(_DWORD *)(v14 + 4LL * (v56 >> 2)) = -559038737;
    v57 = *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + 128LL);
    v58 = v57 - 8;
    v59 = v57 - 5;
    if ( v58 >= 0 )
      v59 = v58;
    *(_DWORD *)(v14 + 4LL * (v59 >> 2)) = -559038737;
    v60 = *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + 128LL);
    v61 = v60 - 4;
    v62 = v60 - 1;
    if ( v61 >= 0 )
      v62 = v61;
    *(_DWORD *)(v14 + 4LL * (v62 >> 2)) = -559038737;
    v63 = *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + 140LL);
    v64 = v63 - 8;
    v65 = v63 - 5;
    if ( v64 >= 0 )
      v65 = v64;
    *(_DWORD *)(v14 + 4LL * (v65 >> 2)) = -559038737;
    v66 = *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + 140LL);
    v67 = v66 - 4;
    v68 = v66 - 1;
    if ( v67 >= 0 )
      v68 = v67;
    *(_DWORD *)(v14 + 4LL * (v68 >> 2)) = -559038737;
    v69 = *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + 160LL);
    v70 = v69 - 8;
    v71 = v69 - 5;
    if ( v70 >= 0 )
      v71 = v70;
    *(_DWORD *)(v14 + 4LL * (v71 >> 2)) = -559038737;
    v72 = *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + 160LL);
    v73 = v72 - 4;
    v74 = v72 - 1;
    if ( v73 >= 0 )
      v74 = v73;
    *(_DWORD *)(v14 + 4LL * (v74 >> 2)) = -559038737;
    v75 = ipa3_ctx;
    v76 = **(_QWORD **)(ipa3_ctx + 34176);
    if ( *(_DWORD *)(v76 + 284) )
    {
      *(_DWORD *)(v14 + (*(_DWORD *)(v76 + 280) & 0xFFFFFFFC)) = 0;
      v75 = ipa3_ctx;
    }
    if ( !v75 )
      goto LABEL_65;
    if ( (unsigned int)(*(_DWORD *)(v75 + 32240) - 17) <= 3 )
    {
      v77 = *(_DWORD *)(**(_QWORD **)(v75 + 34176) + 180LL);
      v78 = v77 - 16;
      v79 = v77 - 13;
      if ( v78 >= 0 )
        v79 = v78;
      *(_DWORD *)(v14 + 4LL * (v79 >> 2)) = -559038737;
      v75 = ipa3_ctx;
      if ( !ipa3_ctx )
      {
LABEL_65:
        v91 = 0;
        goto LABEL_74;
      }
    }
    v80 = v75 + 32240;
    v81 = *(_DWORD *)v80;
    if ( *(_DWORD *)v80 < 0xEu )
    {
LABEL_72:
      v91 = ipa3_ctx;
      if ( ipa3_ctx && (unsigned int)(*(_DWORD *)(ipa3_ctx + 32240) - 17) > 0xFFFFFFFB )
      {
LABEL_79:
        if ( *(_DWORD *)(v91 + 32240) != 21 )
          goto LABEL_89;
        v101 = *(_DWORD *)(**(_QWORD **)(v91 + 34176) + 212LL);
        v102 = v101 - 8;
        v103 = v101 - 5;
        if ( v102 >= 0 )
          v103 = v102;
        *(_DWORD *)(v14 + 4LL * (v103 >> 2)) = -559038737;
        v104 = *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + 212LL);
        v105 = v104 - 4;
        v106 = v104 - 1;
        if ( v105 >= 0 )
          v106 = v105;
        *(_DWORD *)(v14 + 4LL * (v106 >> 2)) = -559038737;
        v107 = *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + 320LL);
        v108 = v107 - 8;
        v109 = v107 - 5;
        if ( v108 >= 0 )
          v109 = v108;
        *(_DWORD *)(v14 + 4LL * (v109 >> 2)) = -559038737;
        v110 = *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + 320LL);
        v111 = v110 - 4;
        v112 = v110 - 1;
        if ( v111 >= 0 )
          v112 = v111;
        *(_DWORD *)(v14 + 4LL * (v112 >> 2)) = -559038737;
        v91 = ipa3_ctx;
        if ( ipa3_ctx )
        {
LABEL_89:
          v113 = *(_DWORD *)(v91 + 32240);
          if ( v113 < 0x15 )
          {
            v117 = 244;
            if ( v113 > 0xB )
              v117 = 280;
          }
          else
          {
            v114 = *(_DWORD *)(**(_QWORD **)(v91 + 34176) + 288LL);
            v115 = v114 - 8;
            v116 = v114 - 5;
            if ( v115 >= 0 )
              v116 = v115;
            v117 = 288;
            *(_DWORD *)(v14 + 4LL * (v116 >> 2)) = -559038737;
            v91 = ipa3_ctx;
          }
          goto LABEL_96;
        }
LABEL_93:
        v117 = 244;
LABEL_96:
        v118 = *(_DWORD *)(**(_QWORD **)(v91 + 34176) + v117);
        v119 = v118 - 4;
        v120 = v118 - 1;
        if ( v119 >= 0 )
          v120 = v119;
        *(_DWORD *)(v14 + 4LL * (v120 >> 2)) = -559038737;
        if ( ipa3_ctx && *(_DWORD *)(ipa3_ctx + 32240) >= 0x18u )
        {
          v121 = **(_QWORD **)(ipa3_ctx + 34176);
          if ( *(_DWORD *)(v121 + 284) )
            *(_DWORD *)(v14 + (*(_DWORD *)(v121 + 280) & 0xFFFFFFFC)) = -1412567295;
        }
        iounmap();
        return 0;
      }
LABEL_74:
      v95 = *(_DWORD *)(**(_QWORD **)(v91 + 34176) + 196LL);
      v96 = v95 - 8;
      v97 = v95 - 5;
      if ( v96 >= 0 )
        v97 = v96;
      *(_DWORD *)(v14 + 4LL * (v97 >> 2)) = -559038737;
      v98 = *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + 196LL);
      v99 = v98 - 4;
      v100 = v98 - 1;
      if ( v99 >= 0 )
        v100 = v99;
      *(_DWORD *)(v14 + 4LL * (v100 >> 2)) = -559038737;
      v91 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_93;
      goto LABEL_79;
    }
    if ( v81 > 0x10 )
    {
      v92 = *(_DWORD *)(**(_QWORD **)(v80 + 1936) + 296LL);
      if ( v81 <= 0x14 )
      {
        v93 = v92 - 16;
LABEL_71:
        *(_DWORD *)(v14 + 4LL * (v93 / 4)) = -559038737;
        goto LABEL_72;
      }
      v90 = v92 - 8;
      v94 = v92 - 5;
      if ( v90 < 0 )
        v90 = v94;
    }
    else
    {
      v82 = *(_DWORD *)(**(_QWORD **)(v80 + 1936) + 288LL);
      v83 = v82 - 8;
      v84 = v82 - 5;
      if ( v83 >= 0 )
        v84 = v83;
      *(_DWORD *)(v14 + 4LL * (v84 >> 2)) = -559038737;
      v85 = *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + 288LL);
      v86 = v85 - 4;
      v87 = v85 - 1;
      if ( v86 >= 0 )
        v87 = v86;
      *(_DWORD *)(v14 + 4LL * (v87 >> 2)) = -559038737;
      v88 = *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + 296LL);
      v89 = v88 - 8;
      v90 = v88 - 5;
      if ( v89 >= 0 )
        v90 = v89;
    }
    *(_DWORD *)(v14 + 4LL * (v90 >> 2)) = -559038737;
    v93 = *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + 296LL) - 4;
    goto LABEL_71;
  }
  printk(&unk_3A5EB7, "_ipa_init_sram_v3");
  v123 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v124 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v124 )
    {
      ipc_log_string(v124, "ipa %s:%d fail to ioremap IPA SRAM\n", "_ipa_init_sram_v3", 5659);
      v123 = ipa3_ctx;
    }
    v125 = *(_QWORD *)(v123 + 34160);
    if ( v125 )
      ipc_log_string(v125, "ipa %s:%d fail to ioremap IPA SRAM\n", "_ipa_init_sram_v3", 5659);
  }
  return 4294967284LL;
}
