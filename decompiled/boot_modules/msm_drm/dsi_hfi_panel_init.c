__int64 __fastcall dsi_hfi_panel_init(__int64 a1, __int64 a2)
{
  __int64 v2; // x25
  _QWORD *cmd_buf; // x0
  __int64 v6; // x24
  __int64 v7; // x27
  __int64 v8; // x20
  unsigned __int64 v9; // x23
  __int64 v10; // x28
  int v11; // w22
  unsigned int v12; // w8
  __int64 v13; // x8
  int v14; // w8
  __int64 result; // x0
  __int64 v16; // x10
  int v17; // w11
  int v18; // w9
  int v19; // w11
  int v20; // w10
  int v21; // w8
  int v22; // w10
  __int64 v23; // x9
  int v24; // w8
  int v25; // w9
  int v26; // w10
  int v27; // w9
  int v28; // w8
  int v29; // w19
  int v30; // w0
  int v31; // w8
  int v32; // w19
  int phandle_count; // w0
  signed int v34; // w8
  int v35; // w0
  int v36; // w8
  unsigned __int64 v37; // x22
  __int64 v38; // x20
  _DWORD *v39; // x28
  _BYTE *v40; // x3
  __int64 v41; // x4
  __int64 v42; // x8
  char v43; // w9
  char v44; // w8
  __int64 v45; // x9
  int v46; // w8
  __int64 v47; // x1
  __int64 v48; // x0
  int v49; // w8
  int v50; // w7
  __int64 v51; // x25
  __int64 v52; // x9
  unsigned int count; // w23
  __int64 payload_addr; // x0
  unsigned int v55; // w0
  int v56; // w7
  unsigned int v57; // w23
  unsigned int appended; // w0
  int v59; // w7
  unsigned int v60; // w0
  unsigned int v61; // w21
  unsigned __int64 StatusReg; // x19
  __int64 v63; // x22
  unsigned int v64; // w19
  char v65; // [xsp+0h] [xbp-140h]
  char v66; // [xsp+0h] [xbp-140h]
  char v67; // [xsp+0h] [xbp-140h]
  int v68; // [xsp+10h] [xbp-130h]
  int v69; // [xsp+14h] [xbp-12Ch]
  unsigned int v70; // [xsp+18h] [xbp-128h]
  int v71; // [xsp+1Ch] [xbp-124h]
  int v72; // [xsp+20h] [xbp-120h]
  int v73; // [xsp+24h] [xbp-11Ch]
  int v74; // [xsp+28h] [xbp-118h]
  int v75; // [xsp+2Ch] [xbp-114h]
  int panel_backlight_type; // [xsp+30h] [xbp-110h]
  int v77; // [xsp+34h] [xbp-10Ch]
  int v78; // [xsp+38h] [xbp-108h]
  int v79; // [xsp+3Ch] [xbp-104h]
  int v80; // [xsp+40h] [xbp-100h]
  int v81; // [xsp+44h] [xbp-FCh]
  int v82; // [xsp+48h] [xbp-F8h]
  int v83; // [xsp+4Ch] [xbp-F4h]
  int v84; // [xsp+50h] [xbp-F0h]
  int v85; // [xsp+54h] [xbp-ECh]
  int v86; // [xsp+58h] [xbp-E8h]
  int v87; // [xsp+5Ch] [xbp-E4h]
  int v88; // [xsp+60h] [xbp-E0h]
  int v89; // [xsp+64h] [xbp-DCh]
  unsigned int v90; // [xsp+68h] [xbp-D8h]
  int v91; // [xsp+6Ch] [xbp-D4h]
  int v92; // [xsp+70h] [xbp-D0h]
  int v93; // [xsp+74h] [xbp-CCh]
  int v94; // [xsp+78h] [xbp-C8h]
  int v95; // [xsp+7Ch] [xbp-C4h]
  __int64 v96; // [xsp+80h] [xbp-C0h]
  __int64 v97; // [xsp+88h] [xbp-B8h]
  unsigned int v98; // [xsp+90h] [xbp-B0h]
  __int64 *v99; // [xsp+98h] [xbp-A8h]
  unsigned int v100; // [xsp+A0h] [xbp-A0h] BYREF
  int v101; // [xsp+A4h] [xbp-9Ch] BYREF
  unsigned __int64 v102; // [xsp+A8h] [xbp-98h]
  int v103; // [xsp+B0h] [xbp-90h]
  int v104; // [xsp+B4h] [xbp-8Ch]
  int v105; // [xsp+B8h] [xbp-88h]
  int v106; // [xsp+BCh] [xbp-84h]
  int v107; // [xsp+C0h] [xbp-80h]
  int v108; // [xsp+C4h] [xbp-7Ch]
  int v109; // [xsp+C8h] [xbp-78h]
  int v110; // [xsp+CCh] [xbp-74h]
  int v111; // [xsp+D0h] [xbp-70h]
  int v112; // [xsp+D4h] [xbp-6Ch]
  int v113; // [xsp+D8h] [xbp-68h]
  int v114; // [xsp+DCh] [xbp-64h]
  int v115; // [xsp+E0h] [xbp-60h]
  int v116; // [xsp+E4h] [xbp-5Ch]
  int v117; // [xsp+E8h] [xbp-58h]
  int v118; // [xsp+ECh] [xbp-54h]
  int v119; // [xsp+F0h] [xbp-50h]
  int v120; // [xsp+F4h] [xbp-4Ch]
  int v121; // [xsp+F8h] [xbp-48h]
  int v122; // [xsp+FCh] [xbp-44h]
  int v123; // [xsp+100h] [xbp-40h]
  int v124; // [xsp+104h] [xbp-3Ch]
  int v125; // [xsp+108h] [xbp-38h]
  int v126; // [xsp+10Ch] [xbp-34h]
  int v127; // [xsp+110h] [xbp-30h]
  int v128; // [xsp+114h] [xbp-2Ch]
  int v129; // [xsp+118h] [xbp-28h]
  int v130; // [xsp+11Ch] [xbp-24h]
  int v131; // [xsp+120h] [xbp-20h]
  int v132; // [xsp+124h] [xbp-1Ch] BYREF
  __int64 v133; // [xsp+128h] [xbp-18h]
  __int64 v134; // [xsp+130h] [xbp-10h]

  v134 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || (v2 = *(_QWORD *)(a1 + 1688)) == 0 )
  {
    result = 4294967274LL;
    goto LABEL_146;
  }
  strcmp(*(const char **)(a1 + 40), "primary");
  cmd_buf = hfi_adapter_get_cmd_buf(*(_QWORD *)(v2 + 8));
  LODWORD(v6) = *(_DWORD *)(a2 + 1432);
  v7 = (__int64)cmd_buf;
  if ( !(_DWORD)v6 )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: No timing modes - panel init failed");
    goto LABEL_144;
  }
  if ( !*(_QWORD *)(a1 + 1224) && (unsigned int)dsi_hfi_host_alloc_cmd_tx_buffer(a1) )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to allocate sde mapped buffer\n");
    goto LABEL_144;
  }
  v8 = _kvmalloc_node_noprof(56, 0, 3520, 0xFFFFFFFFLL);
  if ( !v8 )
  {
LABEL_143:
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to allocate addr_map");
    goto LABEL_144;
  }
  while ( 1 )
  {
    *(_DWORD *)(v8 + 16) = 4096;
    hfi_adapter_buffer_alloc(v8);
    if ( !*(_QWORD *)v8 || !*(_QWORD *)(v8 + 8) )
      goto LABEL_134;
    v9 = 300LL * (unsigned int)v6;
    v10 = _kmalloc_noprof(v9, 3520);
    if ( !v10 )
      goto LABEL_133;
    v11 = 1;
    v98 = v6;
    v12 = *(_DWORD *)(a2 + 1256) - 1;
    if ( *(_DWORD *)(a2 + 2228) )
      LODWORD(v6) = 1;
    else
      LODWORD(v6) = 2;
    if ( v12 <= 4 )
      v11 = dword_286A0C[v12];
    v13 = *(unsigned int *)(a2 + 1248);
    if ( (unsigned int)v13 > 5 )
      v14 = 3;
    else
      v14 = dword_286A20[v13];
    v16 = *(unsigned int *)(a2 + 1244);
    v95 = v14;
    v17 = 3;
    if ( (unsigned int)v16 <= 5 )
      v17 = dword_286A20[v16];
    v18 = *(_DWORD *)(a2 + 1324);
    v94 = v17;
    if ( v18 == 1 )
      v19 = 2;
    else
      v19 = 1;
    if ( v18 == 2 )
      v20 = 3;
    else
      v20 = v19;
    if ( *(_DWORD *)(a2 + 1352) == 2 )
      v21 = 4;
    else
      v21 = 1;
    v91 = v20;
    v92 = v21;
    v22 = 15;
    if ( (*(_BYTE *)(*(_QWORD *)(a1 + 264) + 1974LL) & 1) == 0 )
      v22 = *(_DWORD *)(a1 + 1608);
    v93 = v22;
    v23 = *(unsigned int *)(a2 + 1224);
    v90 = **(_DWORD **)a2;
    if ( v90 )
      v24 = 16;
    else
      v24 = 15;
    if ( (unsigned int)v23 > 7 )
      v25 = 6;
    else
      v25 = dword_29D300[v23];
    v89 = v25;
    v87 = *(_DWORD *)(a2 + 1240);
    v88 = *(_DWORD *)(a2 + 1328);
    v86 = *(_DWORD *)(a2 + 1336);
    v80 = *(_DWORD *)(a2 + 1228) & 0xF;
    v84 = *(unsigned __int8 *)(a2 + 1273);
    v85 = *(_DWORD *)(a2 + 1340);
    if ( v80 )
      v26 = 2;
    else
      v26 = 1;
    if ( *(_BYTE *)(a2 + 1273) )
      v27 = 2;
    else
      v27 = 1;
    v83 = *(unsigned __int8 *)(a2 + 1344);
    v28 = v24 + v26 + v27;
    if ( *(_BYTE *)(a2 + 1321) )
      ++v28;
    v81 = *(_DWORD *)(a2 + 1484);
    v82 = *(_DWORD *)(a2 + 1480);
    v78 = *(unsigned __int8 *)(a2 + 1321);
    v79 = *(_DWORD *)(a2 + 1708);
    v77 = *(unsigned __int8 *)(a2 + 1322);
    if ( *(_BYTE *)(a2 + 1322) )
      v29 = v28 + 1;
    else
      v29 = v28;
    panel_backlight_type = dsi_get_panel_backlight_type(a2, "primary");
    if ( panel_backlight_type )
      ++v29;
    v30 = dsi_get_panel_backlight_type(a2, "secondary");
    a2 = *(unsigned __int8 *)(a2 + 1512);
    v75 = v30;
    v31 = v30 ? v29 + 1 : v29;
    v32 = (_DWORD)a2 ? v31 + 1 : v31;
    phandle_count = dsi_display_get_phandle_count(a1, "qcom,dsi-ctrl-num");
    v34 = phandle_count - 1;
    if ( phandle_count < 1 )
    {
      v72 = 0;
      v96 = 0;
    }
    else
    {
      if ( (unsigned int)v34 > 4 )
        goto LABEL_142;
      v72 = dword_286A38[v34];
      LODWORD(v96) = dword_286A60[v34];
      HIDWORD(v96) = dword_286A4C[v34];
    }
    v73 = phandle_count;
    if ( phandle_count )
      ++v32;
    v35 = dsi_display_get_phandle_count(a1, "qcom,dsi-phy-num");
    v97 = v7;
    v99 = (__int64 *)v8;
    v74 = a2;
    if ( v35 < 1 )
      goto LABEL_70;
    if ( v35 == 1 )
      break;
    if ( v35 == 2 )
    {
      v96 = 1;
      goto LABEL_70;
    }
LABEL_142:
    __break(1u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v63 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &dsi_hfi_panel_init__alloc_tag;
    v8 = _kvmalloc_node_noprof(56, 0, 3520, 0xFFFFFFFFLL);
    *(_QWORD *)(StatusReg + 80) = v63;
    if ( !v8 )
      goto LABEL_143;
  }
  HIDWORD(v96) = 0;
LABEL_70:
  a2 = 0;
  v70 = v6;
  v71 = v11;
  if ( v35 )
    v36 = v32 + 1;
  else
    v36 = v32;
  v68 = v36;
  v69 = v35;
  if ( v98 <= 1 )
    v7 = 1;
  else
    v7 = v98;
  do
  {
    v37 = 300LL * (int)a2;
    if ( v9 <= v37 )
      goto LABEL_142;
    v6 = *(_QWORD *)(a1 + 824) + 192LL * (int)a2;
    v38 = v10;
    v39 = (_DWORD *)(v10 + 300LL * (int)a2);
    v40 = *(_BYTE **)(a1 + 1248);
    v41 = v99[1];
    *v39 = *(_DWORD *)(v6 + 176);
    if ( v9 <= v37 + 4 )
      goto LABEL_142;
    v39[1] = *(_QWORD *)(v6 + 48);
    if ( v9 <= v37 + 8 )
      goto LABEL_142;
    v39[2] = *(_DWORD *)(v6 + 52);
    if ( v9 <= v37 + 12 )
      goto LABEL_142;
    v39[3] = *(_DWORD *)(v6 + 44);
    if ( v9 <= v37 + 16 )
      goto LABEL_142;
    v39[4] = *(_DWORD *)(*(_QWORD *)(v6 + 184) + 2372LL);
    if ( v9 <= v37 + 20 )
      goto LABEL_142;
    v39[5] = *(_DWORD *)(*(_QWORD *)(v6 + 184) + 2376LL);
    if ( v9 <= v37 + 24 )
      goto LABEL_142;
    v39[6] = *(_DWORD *)(v6 + 8);
    if ( v9 <= v37 + 28 )
      goto LABEL_142;
    v39[7] = *(_DWORD *)v6;
    if ( v9 <= v37 + 32 )
      goto LABEL_142;
    v39[8] = *(_DWORD *)(v6 + 24);
    if ( v9 <= v37 + 36 )
      goto LABEL_142;
    v39[9] = *(_DWORD *)(v6 + 12);
    if ( v9 <= v37 + 40 )
      goto LABEL_142;
    v39[10] = *(_DWORD *)(v6 + 4);
    if ( v9 <= v37 + 56 )
      goto LABEL_142;
    v39[14] = *(_DWORD *)(v6 + 16);
    if ( v9 <= v37 + 60 )
      goto LABEL_142;
    v39[15] = *(_DWORD *)(v6 + 8);
    if ( v9 <= v37 + 64 )
      goto LABEL_142;
    v39[16] = *(_DWORD *)(v6 + 36);
    if ( v9 <= v37 + 68 )
      goto LABEL_142;
    v39[17] = *(_DWORD *)(v6 + 28);
    if ( v9 <= v37 + 80 )
      goto LABEL_142;
    v39[20] = *(_DWORD *)(v6 + 32);
    if ( *(_BYTE *)(v6 + 72) == 1 )
    {
      if ( v9 <= v37 + 84 )
        goto LABEL_142;
      v42 = *(_QWORD *)(v6 + 184);
      v43 = *(_BYTE *)(v42 + 2622);
      v44 = *(_BYTE *)(v42 + 2623);
      v39[21] = 1;
      if ( v9 <= v37 + 88 )
        goto LABEL_142;
      v39[22] = v43 & 0xF | (16 * (v44 & 0xF));
      if ( v9 <= v37 + 92 )
        goto LABEL_142;
      v39[23] = *(unsigned __int8 *)(*(_QWORD *)(v6 + 184) + 2632LL);
      if ( v9 <= v37 + 96 )
        goto LABEL_142;
      v39[24] = *(unsigned __int16 *)(*(_QWORD *)(v6 + 184) + 2502LL);
      if ( v9 <= v37 + 100 )
        goto LABEL_142;
      v39[25] = *(unsigned __int16 *)(*(_QWORD *)(v6 + 184) + 2500LL);
      if ( v9 <= v37 + 104 )
        goto LABEL_142;
      v39[26] = *(_DWORD *)(*(_QWORD *)(v6 + 184) + 2664LL);
      if ( v9 <= v37 + 108 )
        goto LABEL_142;
      v39[27] = *(unsigned __int8 *)(*(_QWORD *)(v6 + 184) + 2497LL);
      if ( v9 <= v37 + 112 )
        goto LABEL_142;
      v39[28] = *(_DWORD *)(*(_QWORD *)(v6 + 184) + 2688LL);
      if ( v9 <= v37 + 116 )
        goto LABEL_142;
      v39[29] = *(unsigned __int16 *)(*(_QWORD *)(v6 + 184) + 2512LL);
      if ( v9 <= v37 + 120 )
        goto LABEL_142;
      v39[30] = *(_DWORD *)(*(_QWORD *)(v6 + 184) + 2676LL);
      if ( v9 <= v37 + 124 )
        goto LABEL_142;
      v45 = 32;
      v39[31] = *(_DWORD *)(*(_QWORD *)(v6 + 184) + 2672LL);
      v46 = *(unsigned __int8 *)(*(_QWORD *)(v6 + 184) + 2522LL);
    }
    else
    {
      v46 = 0;
      v45 = 21;
    }
    if ( v9 <= v37 + v45 * 4 )
      goto LABEL_142;
    v39[v45] = v46;
    if ( v9 <= v37 + 132 )
      goto LABEL_142;
    v39[33] = 1;
    if ( v9 <= v37 + 136 )
      goto LABEL_142;
    v39[34] = *(_DWORD *)(*(_QWORD *)(v6 + 184) + 2480LL);
    if ( v9 <= v37 + 140 )
      goto LABEL_142;
    v39[35] = *(_DWORD *)(*(_QWORD *)(v6 + 184) + 2484LL);
    if ( v9 <= v37 + 144 )
      goto LABEL_142;
    v39[36] = *(_DWORD *)(*(_QWORD *)(v6 + 184) + 2488LL);
    if ( v9 <= v37 + 148 )
      goto LABEL_142;
    v39[37] = 0;
    hfi_panel_fill_dcs_cmds(a1, *(_QWORD *)(v6 + 184), (__int64)v39, v40, v41);
    if ( v9 <= v37 + 240 )
      goto LABEL_142;
    v39[60] = *(_DWORD *)(*(_QWORD *)(v6 + 184) + 2368LL);
    if ( v9 <= v37 + 244 )
      goto LABEL_142;
    v39[61] = **(_DWORD **)(*(_QWORD *)(v6 + 184) + 2360LL);
    if ( v9 <= v37 + 248 )
      goto LABEL_142;
    v39[62] = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v6 + 184) + 2360LL) + 4LL);
    if ( v9 <= v37 + 252 )
      goto LABEL_142;
    v39[63] = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v6 + 184) + 2360LL) + 8LL);
    if ( v9 <= v37 + 256 )
      goto LABEL_142;
    v39[64] = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v6 + 184) + 2360LL) + 12LL);
    if ( v9 <= v37 + 260 )
      goto LABEL_142;
    v39[65] = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v6 + 184) + 2360LL) + 16LL);
    if ( v9 <= v37 + 264 )
      goto LABEL_142;
    v39[66] = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v6 + 184) + 2360LL) + 20LL);
    if ( v9 <= v37 + 268 )
      goto LABEL_142;
    v39[67] = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v6 + 184) + 2360LL) + 24LL);
    if ( v9 <= v37 + 272 )
      goto LABEL_142;
    v39[68] = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v6 + 184) + 2360LL) + 28LL);
    if ( v9 <= v37 + 276 )
      goto LABEL_142;
    v39[69] = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v6 + 184) + 2360LL) + 32LL);
    if ( v9 <= v37 + 280 )
      goto LABEL_142;
    v39[70] = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v6 + 184) + 2360LL) + 36LL);
    if ( v9 <= v37 + 284 )
      goto LABEL_142;
    v39[71] = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v6 + 184) + 2360LL) + 40LL);
    if ( v9 <= v37 + 288 )
      goto LABEL_142;
    v39[72] = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v6 + 184) + 2360LL) + 44LL);
    if ( v9 <= v37 + 292 )
      goto LABEL_142;
    v39[73] = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v6 + 184) + 2360LL) + 48LL);
    if ( v9 <= v37 + 296 )
      goto LABEL_142;
    a2 = (unsigned int)(a2 + 1);
    v39[74] = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v6 + 184) + 2360LL) + 52LL);
    v10 = v38;
  }
  while ( (_DWORD)v7 != (_DWORD)a2 );
  v48 = hfi_util_kv_helper_alloc(4096, v47);
  v49 = sde_dbg_base_evtlog;
  *(_QWORD *)(v2 + 16) = v48;
  sde_evtlog_log(v49, "dsi_hfi_panel_init", 1170, -1, 50331649, 13107, -1059143953, v50, v65);
  v8 = (__int64)v99;
  v51 = *(_QWORD *)(a1 + 1688);
  v101 = 0;
  v100 = v98;
  v52 = *v99;
  v102 = *(_QWORD *)(a1 + 1240);
  v132 = 0;
  v133 = v52;
  if ( !v51 )
  {
    v7 = v97;
    v57 = -22;
    goto LABEL_132;
  }
  hfi_util_kv_helper_reset(*(unsigned int **)(v51 + 16));
  hfi_util_kv_helper_add(*(unsigned int **)(v51 + 16), 0x1040001u, (__int64)&v100);
  hfi_util_kv_helper_add(*(unsigned int **)(v51 + 16), 0x3040025u, (__int64)&v101);
  hfi_util_kv_helper_add(*(unsigned int **)(v51 + 16), 0x3040026u, (__int64)&v132);
  count = hfi_util_kv_helper_get_count(*(_QWORD *)(v51 + 16));
  payload_addr = hfi_util_kv_helper_get_payload_addr(*(_QWORD *)(v51 + 16));
  v7 = v97;
  v55 = hfi_adapter_add_prop_array(v97, 0x3000001u, 0, 1u, payload_addr, count, 4 * count + 28);
  if ( v55 )
  {
    v57 = v55;
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Failed to add caps to buffer, rc = %d", v55);
LABEL_132:
    drm_dev_printk(
      0,
      &unk_248D72,
      "*ERROR* [msm-dsi-error]: failed to append HFI_COMMAND_PANEL_INIT_PANEL_CAPS: rc = %d",
      v57);
    goto LABEL_133;
  }
  sde_evtlog_log(sde_dbg_base_evtlog, "dsi_hfi_panel_init", 1177, -1, 50331650, 17476, -1059143953, v56, v66);
  appended = dsi_hfi_append_panel_timing_caps(v97, a1, v10);
  if ( appended )
  {
    drm_dev_printk(
      0,
      &unk_248D72,
      "*ERROR* [msm-dsi-error]: failed to append HFI_COMMAND_PANEL_INIT_TIMING_CAPS: rc = %d",
      appended);
LABEL_133:
    kfree(v10);
LABEL_134:
    kfree(v8);
LABEL_144:
    result = hfi_adapter_release_cmd_buf(v7);
    if ( (_DWORD)result )
    {
      v64 = result;
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to release command buffer\n");
      result = v64;
    }
  }
  else
  {
    sde_evtlog_log(sde_dbg_base_evtlog, "dsi_hfi_panel_init", 1184, -1, 50331651, 21845, -1059143953, v59, v67);
    v101 = v68;
    v102 = __PAIR64__(v70, v90);
    v103 = v89;
    v104 = v80;
    v105 = 1;
    v106 = v71;
    v107 = v95;
    v108 = v94;
    v109 = v87;
    v110 = v84;
    v111 = v78;
    v112 = v77;
    v113 = v91;
    v114 = v88;
    v115 = v86;
    v116 = v85;
    v117 = v83;
    v118 = v92;
    v119 = v82;
    v120 = v81;
    v121 = v79;
    v122 = panel_backlight_type;
    v123 = v75;
    v124 = v74;
    v125 = v93;
    v126 = v73;
    v127 = 0;
    v128 = v72;
    v129 = v69;
    v130 = HIDWORD(v96);
    v131 = v96;
    v60 = dsi_hfi_append_panel_generic_caps(v97, a1, &v101);
    if ( v60 )
    {
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: failed to append HFI_COMMAND_PANEL_INIT_GENERIC_CAPS: rc = %d",
        v60);
      goto LABEL_133;
    }
    v61 = hfi_adapter_set_cmd_buf(v97);
    sde_evtlog_log(sde_dbg_base_evtlog, "dsi_hfi_panel_init", 1193, -1, 50331649, 50331650, 50331651, v61, 102);
    if ( v61 )
    {
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to send panel init: rc = %d", v61);
      goto LABEL_133;
    }
    result = 0;
  }
LABEL_146:
  _ReadStatusReg(SP_EL0);
  return result;
}
