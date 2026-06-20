__int64 __fastcall sde_hw_catalog_init(__int64 a1)
{
  __int64 v1; // x21
  __int64 v2; // x22
  _QWORD *v4; // x0
  __int64 v5; // x19
  int *v6; // x22
  int v7; // w0
  __int64 v8; // x8
  __int64 v9; // x8
  int v10; // w8
  int v11; // w8
  int v12; // w9
  int v13; // w8
  int v14; // w9
  int v15; // w8
  unsigned int v16; // w3
  __int64 v17; // x8
  _DWORD *v18; // x8
  char v19; // w9
  __int64 v20; // x8
  __int64 v21; // x10
  int v22; // w8
  unsigned int v23; // w22
  __int64 v24; // x0
  unsigned int v25; // w23
  __int64 v26; // x10
  int v27; // w8
  __int64 v28; // x10
  unsigned int v29; // w8
  unsigned int v30; // w22
  __int64 v31; // x0
  unsigned int v32; // w23
  __int64 v33; // x10
  int v34; // w8
  unsigned int v35; // w22
  __int64 v36; // x0
  unsigned int v37; // w23
  __int64 v38; // x0
  __int64 v39; // x0
  int v40; // w8
  const char *v41; // x23
  unsigned int v42; // w22
  unsigned int v43; // w24
  char v44; // w27
  const char *v45; // x25
  int v46; // w9
  __int64 v47; // x0
  __int64 v48; // x0
  __int64 v49; // x0
  unsigned __int64 v57; // x9
  unsigned __int64 v60; // x9
  unsigned __int64 v63; // x9
  unsigned __int64 v66; // x9
  unsigned __int64 v69; // x9
  unsigned __int64 v72; // x9
  unsigned __int64 v75; // x9
  unsigned __int64 v78; // x11
  int v79; // w9
  int v80; // w10
  __int64 v81; // x8
  __int64 v82; // x1
  unsigned int part_count; // w0
  unsigned int v84; // w24
  unsigned __int64 v85; // x23
  _DWORD *v86; // x22
  bool v87; // w24
  __int64 v88; // x0
  _BOOL4 v89; // w3
  char v90; // w9
  unsigned __int64 dt_props; // x0
  unsigned __int64 v92; // x22
  int dt_entry; // w23
  int v94; // w8
  int v95; // w8
  int v96; // w8
  int v97; // w8
  int v98; // w8
  __int64 v99; // x25
  __int64 v100; // x27
  __int64 v101; // x8
  int v102; // w24
  __int64 node_opts_by_path; // x0
  int v104; // w0
  int v105; // w8
  int v106; // w8
  int v107; // w8
  int v108; // w8
  unsigned int v109; // w3
  int v110; // w4
  int v111; // w8
  int v112; // w8
  int v113; // w8
  int v114; // w8
  int v115; // w9
  unsigned int v116; // w9
  __int64 v117; // x11
  __int64 v118; // x9
  _QWORD *v119; // x13
  __int64 v120; // x12
  __int64 v121; // x14
  int string; // w0
  const char *v123; // x23
  int v124; // w8
  int v125; // w0
  const char *v126; // x23
  int v127; // w8
  char *v128; // x1
  int v129; // w0
  const char *v130; // x23
  int v131; // w8
  unsigned __int64 v134; // x10
  unsigned __int64 v137; // x10
  unsigned __int64 v140; // x10
  unsigned __int64 v143; // x10
  unsigned __int64 v146; // x10
  unsigned __int64 v149; // x9
  unsigned __int64 v152; // x9
  unsigned __int64 v155; // x9
  unsigned __int64 v158; // x9
  unsigned __int64 v161; // x9
  unsigned __int64 v164; // x9
  unsigned __int64 v167; // x9
  unsigned __int64 v170; // x9
  unsigned __int64 v173; // x9
  __int64 v174; // [xsp+10h] [xbp-20h] BYREF
  char *s1[3]; // [xsp+18h] [xbp-18h] BYREF

  s1[2] = *(char **)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(*(_QWORD *)(a1 + 8) + 744LL);
  if ( !v1 )
  {
    v5 = -22;
    goto LABEL_102;
  }
  v2 = *(_QWORD *)(a1 + 56);
  v4 = (_QWORD *)_kvmalloc_node_noprof(22160, 0, 3520, 0xFFFFFFFFLL);
  v5 = (__int64)v4;
  if ( !v4 )
  {
    v5 = -12;
    goto LABEL_102;
  }
  if ( *(_DWORD *)(v2 + 5912) == 1 )
  {
    v4[2485] = 0x26BE3680FFFFFFFFLL;
    _X8 = v4 + 2751;
    __asm { PRFM            #0x11, [X8] }
    do
      v57 = __ldxr(_X8);
    while ( __stxr(v57 | 0x8000000000000LL, _X8) );
  }
  v4[2749] = v4 + 2749;
  v4[2750] = v4 + 2749;
  v174 = 0;
  s1[0] = nullptr;
  s1[1] = nullptr;
  v6 = (int *)_kvmalloc_node_noprof(3072, 0, 3520, 0xFFFFFFFFLL);
  if ( !v6 )
    goto LABEL_9;
  if ( (unsigned int)validate_dt_entry(v1, &sde_hw_prop, 4, s1, &v174)
    || (unsigned int)read_dt_entry(v1, &sde_hw_prop, 4, s1, (char *)&v174 + 4, v6) )
  {
    kvfree(v6);
LABEL_9:
    ((void (__fastcall *)(__int64))sde_hw_catalog_deinit)(v5);
    v5 = 0;
    goto LABEL_102;
  }
  if ( BYTE4(v174) == 1 )
  {
    v7 = *v6;
  }
  else if ( a1 && (v8 = *(_QWORD *)(a1 + 56)) != 0 && (v9 = *(_QWORD *)(v8 + 8)) != 0 )
  {
    v7 = readl_relaxed_8(*(_QWORD *)(v9 + 1752));
  }
  else
  {
    v7 = 0;
  }
  v10 = BYTE5(v174);
  *(_DWORD *)v5 = v7;
  if ( v10 == 1 )
    v11 = v6[192];
  else
    v11 = 0;
  v12 = BYTE6(v174);
  *(_DWORD *)(v5 + 52) = v11;
  if ( v12 == 1 )
    v13 = v6[384];
  else
    v13 = 0;
  v14 = HIBYTE(v174);
  *(_DWORD *)(v5 + 4) = v13;
  if ( v14 == 1 )
    v15 = v6[576];
  else
    v15 = 0;
  *(_DWORD *)(v5 + 12) = v15;
  kvfree(v6);
  v16 = *(_DWORD *)v5;
  _X8 = (unsigned __int64 *)(v5 + 22008);
  __asm { PRFM            #0x11, [X8] }
  do
    v60 = __ldxr(_X8);
  while ( __stxr(v60 | 0x1000, _X8) );
  _X8 = (unsigned __int64 *)(v5 + 22008);
  __asm { PRFM            #0x11, [X8] }
  do
    v63 = __ldxr(_X8);
  while ( __stxr(v63 | 0x4000000, _X8) );
  _X8 = (unsigned __int64 *)(v5 + 22008);
  __asm { PRFM            #0x11, [X8] }
  do
    v66 = __ldxr(_X8);
  while ( __stxr(v66 | 0x100000000LL, _X8) );
  _X8 = (unsigned __int64 *)(v5 + 22008);
  __asm { PRFM            #0x11, [X8] }
  do
    v69 = __ldxr(_X8);
  while ( __stxr(v69 | 0x200000000LL, _X8) );
  _X8 = (unsigned __int64 *)(v5 + 22008);
  __asm { PRFM            #0x11, [X8] }
  do
    v72 = __ldxr(_X8);
  while ( __stxr(v72 | 0x400000000LL, _X8) );
  _X8 = (unsigned __int64 *)(v5 + 22008);
  __asm { PRFM            #0x11, [X8] }
  do
    v75 = __ldxr(_X8);
  while ( __stxr(v75 | 0x80000, _X8) );
  v17 = 0;
  *(_DWORD *)(v5 + 640) = 92;
  *(_DWORD *)(v5 + 22148) = 4;
  *(_QWORD *)(v5 + 19984) = -1;
  *(_QWORD *)(v5 + 19992) = -1;
  *(_QWORD *)(v5 + 20000) = -1;
  *(_QWORD *)(v5 + 20008) = -1;
  *(_QWORD *)(v5 + 20016) = -1;
  *(_QWORD *)(v5 + 20024) = -1;
  *(_QWORD *)(v5 + 20032) = -1;
  *(_QWORD *)(v5 + 20040) = -1;
  *(_QWORD *)(v5 + 20048) = -1;
  *(_QWORD *)(v5 + 20056) = -1;
  *(_QWORD *)(v5 + 20064) = -1;
  *(_QWORD *)(v5 + 20072) = -1;
  *(_QWORD *)(v5 + 20080) = -1;
  *(_QWORD *)(v5 + 20088) = -1;
  *(_QWORD *)(v5 + 20096) = -1;
  while ( (*(_DWORD *)((char *)&sde_mdss_target_caps + v17) ^ v16) >> 16 )
  {
    v17 += 16;
    if ( v17 == 512 )
      goto LABEL_90;
  }
  v18 = *(_DWORD **)((char *)&sde_mdss_target_caps + v17 + 8);
  if ( !v18 )
  {
LABEL_90:
    printk(&unk_235C19, "_sde_hardware_pre_caps");
    v19 = 1;
    *(_DWORD *)(v5 + 21792) = 0xFFFF;
    LODWORD(v20) = -19;
    goto LABEL_35;
  }
  if ( *(v18 - 1) != -2013116691 )
    __break(0x8228u);
  ((void (__fastcall *)(__int64, _QWORD))v18)(v5, v16);
  v19 = 0;
  LODWORD(v20) = 0;
LABEL_35:
  if ( *(_DWORD *)(v5 + 4) >> 29 >= 3u )
  {
    _X10 = (unsigned __int64 *)(v5 + 22008);
    __asm { PRFM            #0x11, [X10] }
    do
      v78 = __ldxr(_X10);
    while ( __stxr(v78 | 0x20000, _X10) );
    if ( (v19 & 1) == 0 )
      goto LABEL_37;
LABEL_80:
    v46 = *(_DWORD *)(v5 + 21976);
    if ( !v46 )
      goto LABEL_149;
    goto LABEL_133;
  }
  if ( (v19 & 1) != 0 )
    goto LABEL_80;
LABEL_37:
  v21 = *(_QWORD *)(v5 + 22008);
  if ( (v21 & 0x40000) != 0 )
    v22 = 48;
  else
    v22 = 42;
  if ( (v21 & 0x800000000000LL) != 0 )
    v23 = v22 + 3;
  else
    v23 = v22;
  v24 = _kvmalloc_node_noprof(16 * v23, 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(v5 + 22032) = v24;
  if ( !v24 )
    goto LABEL_122;
  v25 = sde_copy_formats(v24, v23, 0, "AR24", 42);
  if ( (*(_QWORD *)(v5 + 22008) & 0x40000) != 0 )
    v25 += sde_copy_formats(*(_QWORD *)(v5 + 22032), v23, v25, "AR4H", 6);
  if ( (*(_QWORD *)(v5 + 22008) & 0x800000000000LL) != 0 )
    sde_copy_formats(*(_QWORD *)(v5 + 22032), v23, v25, "AB24", 3);
  v26 = *(_QWORD *)(v5 + 22008);
  if ( (v26 & 0x10000) != 0 )
    v27 = 55;
  else
    v27 = 54;
  _ZF = (v26 & 0x40000) == 0;
  v28 = *(_QWORD *)(v5 + 22008);
  v29 = v27 + (((unsigned int)v28 >> 17) & 1);
  if ( !_ZF )
    v29 += 6;
  if ( (v28 & 0x800000000000LL) != 0 )
    v30 = v29 + 3;
  else
    v30 = v29;
  v31 = _kvmalloc_node_noprof(16 * v30, 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(v5 + 22040) = v31;
  if ( !v31 )
  {
LABEL_121:
    kvfree(*(_QWORD *)(v5 + 22032));
LABEL_122:
    printk(&unk_270C7F, "sde_hardware_format_caps");
LABEL_123:
    LODWORD(v20) = 0;
    v46 = *(_DWORD *)(v5 + 21976);
    if ( !v46 )
      goto LABEL_149;
    goto LABEL_133;
  }
  v32 = sde_copy_formats(v31, v30, 0, "AR24", 54);
  if ( (*(_QWORD *)(v5 + 22008) & 0x10000) != 0 )
  {
    v32 += sde_copy_formats(*(_QWORD *)(v5 + 22040), v30, v32, "NV12", 1);
    if ( (*(_QWORD *)(v5 + 22008) & 0x20000) == 0 )
    {
LABEL_59:
      if ( (*(_QWORD *)(v5 + 22008) & 0x40000) == 0 )
        goto LABEL_60;
      goto LABEL_84;
    }
  }
  else if ( (*(_QWORD *)(v5 + 22008) & 0x20000) == 0 )
  {
    goto LABEL_59;
  }
  v32 += sde_copy_formats(*(_QWORD *)(v5 + 22040), v30, v32, "P210", 1);
  if ( (*(_QWORD *)(v5 + 22008) & 0x40000) == 0 )
  {
LABEL_60:
    if ( (*(_QWORD *)(v5 + 22008) & 0x800000000000LL) == 0 )
      goto LABEL_62;
    goto LABEL_61;
  }
LABEL_84:
  v32 += sde_copy_formats(*(_QWORD *)(v5 + 22040), v30, v32, "AR4H", 6);
  if ( (*(_QWORD *)(v5 + 22008) & 0x800000000000LL) != 0 )
LABEL_61:
    sde_copy_formats(*(_QWORD *)(v5 + 22040), v30, v32, "AB24", 3);
LABEL_62:
  v33 = *(_QWORD *)(v5 + 22008);
  if ( (v33 & 0x40000) != 0 )
    v34 = 48;
  else
    v34 = 42;
  if ( (v33 & 0x800000000000LL) != 0 )
    v35 = v34 + 3;
  else
    v35 = v34;
  v36 = _kvmalloc_node_noprof(16 * v35, 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(v5 + 22064) = v36;
  if ( !v36 )
  {
    kvfree(*(_QWORD *)(v5 + 22040));
    goto LABEL_121;
  }
  v37 = sde_copy_formats(v36, v35, 0, "AR24", 42);
  if ( (*(_QWORD *)(v5 + 22008) & 0x40000) != 0 )
    v37 += sde_copy_formats(*(_QWORD *)(v5 + 22064), v35, v37, "AR4H", 6);
  if ( (*(_QWORD *)(v5 + 22008) & 0x800000000000LL) != 0 )
    sde_copy_formats(*(_QWORD *)(v5 + 22064), v35, v37, "AB24", 3);
  v38 = _kvmalloc_node_noprof(784, 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(v5 + 22048) = v38;
  if ( !v38 )
  {
    printk(&unk_25B89D, "sde_hardware_format_caps");
    goto LABEL_132;
  }
  sde_copy_formats(v38, 49, 0, "RG16", 49);
  v39 = _kvmalloc_node_noprof(80, 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(v5 + 22056) = v39;
  if ( v39 )
  {
    sde_copy_formats(v39, 5, 0, "AB24", 5);
    v40 = *(_DWORD *)(v5 + 44);
    if ( v40 > 512 )
    {
      if ( v40 == 513 )
      {
        v44 = 0;
        v43 = 7;
        v45 = "NV12";
        v42 = 5;
        v41 = "AB24";
      }
      else
      {
        if ( v40 != 514 )
          goto LABEL_98;
        v44 = 0;
        if ( (*(_QWORD *)(v5 + 22008) & 0x20000) != 0 )
        {
          v43 = 10;
          v45 = "NV12";
          v42 = 8;
          v41 = "AB24";
        }
        else
        {
          v43 = 9;
          v45 = "NV12";
          v42 = 7;
          v41 = "AB24";
        }
      }
    }
    else if ( v40 == 256 )
    {
      v41 = nullptr;
      v42 = 0;
      v43 = 3;
      v44 = 1;
      v45 = "NV12";
    }
    else
    {
      if ( v40 != 512 )
        goto LABEL_98;
      v41 = nullptr;
      v42 = 0;
      v43 = 6;
      v44 = 1;
      v45 = "AB24";
    }
    v47 = _kvmalloc_node_noprof(16 * v43, 0, 3520, 0xFFFFFFFFLL);
    *(_QWORD *)(v5 + 22072) = v47;
    if ( !v47 )
    {
      printk(&unk_26D593, "sde_hardware_format_caps");
LABEL_130:
      kvfree(*(_QWORD *)(v5 + 22056));
      goto LABEL_131;
    }
    sde_copy_formats(v47, v43, 0, v45, v43);
    if ( (v44 & 1) == 0 )
    {
      v48 = _kvmalloc_node_noprof(16 * v42, 0, 3520, 0xFFFFFFFFLL);
      *(_QWORD *)(v5 + 22080) = v48;
      if ( !v48 )
      {
        printk(&unk_262DEF, "sde_hardware_format_caps");
LABEL_129:
        kvfree(*(_QWORD *)(v5 + 22072));
        goto LABEL_130;
      }
      sde_copy_formats(v48, v42, 0, v41, v42);
    }
LABEL_98:
    if ( (*(_DWORD *)(v5 + 56) & 0xFFFFFFFE) != 0x28 )
      goto LABEL_123;
    v49 = _kmalloc_cache_noprof(_drm_debug, 3520, 48);
    *(_QWORD *)(v5 + 22104) = v49;
    if ( v49 )
    {
      sde_copy_formats(v49, 3, 0, "AB24", 3);
      goto LABEL_123;
    }
    printk(&unk_2438D8, "sde_hardware_format_caps");
    kvfree(*(_QWORD *)(v5 + 22080));
    goto LABEL_129;
  }
LABEL_131:
  kvfree(*(_QWORD *)(v5 + 22048));
LABEL_132:
  kvfree(*(_QWORD *)(v5 + 22064));
  kvfree(*(_QWORD *)(v5 + 22040));
  kvfree(*(_QWORD *)(v5 + 22032));
  LODWORD(v20) = -12;
  v46 = *(_DWORD *)(v5 + 21976);
  if ( !v46 )
    goto LABEL_149;
LABEL_133:
  *(_QWORD *)(v5 + 21936) = 0x400000080LL;
  *(_DWORD *)(v5 + 21952) = 40;
  *(_BYTE *)(v5 + 21984) = 1;
  *(_QWORD *)(v5 + 21944) = 0x3200000006LL;
  *(_QWORD *)(v5 + 21960) = 0x5DC0000000FLL;
  if ( v46 <= 257 )
  {
    if ( v46 == 256 )
    {
      v79 = 12;
      v80 = 60;
    }
    else
    {
      if ( v46 != 257 )
        goto LABEL_149;
      _X9 = (unsigned __int64 *)(v5 + 21920);
      __asm { PRFM            #0x11, [X9] }
      do
        v140 = __ldxr(_X9);
      while ( __stxr(v140 | 2, _X9) );
      v79 = 13;
      v80 = 90;
    }
    *(_DWORD *)(v5 + 21956) = v79;
    *(_DWORD *)(v5 + 21968) = v80;
LABEL_149:
    if ( !(_DWORD)v20 )
      goto LABEL_150;
    goto LABEL_9;
  }
  if ( v46 != 258 )
  {
    if ( v46 == 259 )
    {
      _X9 = (unsigned __int64 *)(v5 + 21920);
      __asm { PRFM            #0x11, [X9] }
      do
        v146 = __ldxr(_X9);
      while ( __stxr(v146 | 2, _X9) );
      *(_QWORD *)(v5 + 21968) = 0xF0000000F0LL;
      *(_QWORD *)(v5 + 21956) = 0xFF0000000CLL;
      if ( !(_DWORD)v20 )
        goto LABEL_150;
      goto LABEL_9;
    }
    if ( v46 == 260 )
      goto LABEL_329;
    goto LABEL_149;
  }
  _X9 = (unsigned __int64 *)(v5 + 21920);
  __asm { PRFM            #0x11, [X9] }
  do
    v143 = __ldxr(_X9);
  while ( __stxr(v143 | 2, _X9) );
  *(_QWORD *)(v5 + 21956) = 0xFF0000000DLL;
  *(_QWORD *)(v5 + 21968) = 0xF00000005ALL;
  if ( (_DWORD)v20 )
    goto LABEL_9;
  while ( 1 )
  {
LABEL_150:
    LODWORD(s1[0]) = 0;
    if ( !a1 || (v81 = *(_QWORD *)(a1 + 8)) == 0 )
    {
      printk(&unk_243912, "sde_hw_check_qultivate_fuse");
      goto LABEL_9;
    }
    if ( (unsigned int)sde_hw_parse_fuse_configuration(v81 - 16, "disp_qultiv_fuse", s1) )
      break;
    if ( (socinfo_get_part_info(4) & 1) != 0 || (part_count = socinfo_get_part_count(4)) == 0 )
    {
      v85 = 0;
      v86 = nullptr;
      v87 = 1;
    }
    else
    {
      v84 = part_count;
      if ( (part_count & 0x80000000) != 0 )
        goto LABEL_9;
      v85 = 4LL * part_count;
      v86 = (_DWORD *)_kmalloc_noprof(v85, 3520);
      if ( !v86 )
        goto LABEL_9;
      socinfo_get_subpart_info(4, v86, v84);
      v87 = v85 < 4;
    }
    if ( *(_DWORD *)(v5 + 12) != 1 )
      goto LABEL_175;
    v88 = _kmalloc_cache_noprof(kthread_create_on_node, 3520, 12);
    if ( !v88 )
    {
      kfree(v86);
      goto LABEL_9;
    }
    LODWORD(v20) = 1;
    v89 = 1;
    if ( (BYTE3(s1[0]) & 0x20) != 0 )
      goto LABEL_172;
    if ( !v86 )
    {
      v89 = 0;
      goto LABEL_172;
    }
    if ( !v87 && v85 >= 4 )
    {
      v89 = *v86 == 7;
LABEL_172:
      *(_BYTE *)v88 = v89;
      *(_QWORD *)(v88 + 4) = 0x400000002LL;
      v90 = _drm_debug;
      *(_BYTE *)(v88 + 1) = 1;
      *(_QWORD *)(v5 + 19896) = v88;
      if ( (v90 & 4) != 0 )
        printk(&unk_270CB3, v89);
      else
        printk(&unk_25F666, "sde_hw_check_qultivate_fuse");
LABEL_175:
      kfree(v86);
      goto LABEL_176;
    }
LABEL_328:
    __break(1u);
LABEL_329:
    _X9 = (unsigned __int64 *)(v5 + 21920);
    __asm { PRFM            #0x11, [X9] }
    do
      v134 = __ldxr(_X9);
    while ( __stxr(v134 | 2, _X9) );
    *(_QWORD *)(v5 + 21968) = 0xF0000000F0LL;
    *(_QWORD *)(v5 + 21956) = 0xFF0000000CLL;
    _X9 = (unsigned __int64 *)(v5 + 21920);
    __asm { PRFM            #0x11, [X9] }
    do
      v137 = __ldxr(_X9);
    while ( __stxr(v137 | 4, _X9) );
    if ( (_DWORD)v20 )
      goto LABEL_9;
  }
  if ( (_drm_debug & 4) != 0 )
    printk(&unk_22F014, v82);
  else
    printk(&unk_235C7A, "sde_hw_check_qultivate_fuse");
LABEL_176:
  HIDWORD(v174) = 0;
  s1[0] = nullptr;
  dt_props = sde_get_dt_props(v1, 39, &sde_prop, 39, (char *)&v174 + 4);
  v92 = dt_props;
  if ( dt_props >= 0xFFFFFFFFFFFFF001LL )
  {
    dt_entry = dt_props;
    goto LABEL_308;
  }
  dt_entry = validate_dt_entry(v1, &unk_9EF8, 1, dt_props + 168, 0);
  if ( dt_entry )
    goto LABEL_306;
  dt_entry = read_dt_entry(v1, &sde_prop, 39, v92 + 64, v92, *(_QWORD *)(v92 + 320));
  if ( dt_entry )
    goto LABEL_306;
  *(_DWORD *)(v5 + 60) = 1;
  *(_QWORD *)(v5 + 80) = 1;
  snprintf((char *)(v5 + 64), 0x10u, "mdss_%u", 0);
  *(_DWORD *)(v5 + 644) = 1;
  *(_DWORD *)(v5 + 664) = 1;
  snprintf((char *)(v5 + 648), 0x10u, "top_%u", 0);
  *(_DWORD *)(v5 + 668) = **(_DWORD **)(v92 + 320);
  if ( *(_BYTE *)(v92 + 1) == 1 )
    v94 = *(_DWORD *)(*(_QWORD *)(v92 + 320) + 768LL);
  else
    v94 = 256;
  *(_DWORD *)(v5 + 672) = v94;
  if ( (*(_BYTE *)(v92 + 2) & 1) != 0 )
    v95 = *(_DWORD *)(*(_QWORD *)(v92 + 320) + 1536LL);
  else
    v95 = 2048;
  *(_DWORD *)(v5 + 21552) = v95;
  if ( *(_BYTE *)(v92 + 3) == 1 )
    v95 = *(_DWORD *)(*(_QWORD *)(v92 + 320) + 2304LL);
  *(_DWORD *)(v5 + 21556) = v95;
  if ( *(_BYTE *)(v92 + 4) == 1 )
    v95 = *(_DWORD *)(*(_QWORD *)(v92 + 320) + 3072LL);
  *(_DWORD *)(v5 + 21560) = v95;
  if ( *(_BYTE *)(v92 + 7) == 1 )
    v96 = *(_DWORD *)(*(_QWORD *)(v92 + 320) + 5376LL);
  else
    v96 = 2048;
  *(_DWORD *)(v5 + 21564) = v96;
  if ( *(_BYTE *)(v92 + 8) == 1 )
    v96 = *(_DWORD *)(*(_QWORD *)(v92 + 320) + 6144LL);
  *(_DWORD *)(v5 + 21568) = v96;
  if ( *(_BYTE *)(v92 + 5) == 1 )
    v97 = *(_DWORD *)(*(_QWORD *)(v92 + 320) + 3840LL);
  else
    v97 = 2048;
  *(_DWORD *)(v5 + 21576) = v97;
  if ( *(_BYTE *)(v92 + 6) == 1 )
    v98 = *(_DWORD *)(*(_QWORD *)(v92 + 320) + 4608LL);
  else
    v98 = 7;
  *(_DWORD *)(v5 + 21580) = v98;
  *(_DWORD *)(v5 + 696) = 2;
  if ( *(_BYTE *)(v92 + 9) == 1 )
  {
    LODWORD(v20) = *(_DWORD *)(v92 + 100);
    if ( (int)v20 >= 1 )
    {
      v99 = 0;
      v100 = 7172;
      do
      {
        if ( v99 == 64 )
          goto LABEL_327;
        v101 = *(_QWORD *)(v92 + 320);
        v102 = *(_DWORD *)(v101 + v100 - 4);
        if ( v102 )
        {
          LODWORD(v174) = 0;
          node_opts_by_path = of_find_node_opts_by_path("/memory", 0);
          if ( node_opts_by_path )
          {
            v104 = of_property_read_variable_u32_array(node_opts_by_path, "ddr_device_type", &v174, 1, 0);
            v105 = v174;
            if ( v104 < 0 )
              v105 = -2;
          }
          else
          {
            v105 = -2;
          }
          if ( v105 != v102 )
            goto LABEL_205;
          v101 = *(_QWORD *)(v92 + 320);
        }
        *(_DWORD *)(v5 + 696) = *(_DWORD *)(v101 + v100);
LABEL_205:
        v20 = *(int *)(v92 + 100);
        ++v99;
        v100 += 8;
      }
      while ( v99 < v20 );
    }
  }
  if ( *(_BYTE *)(v92 + 23) == 1 )
    v106 = *(_DWORD *)(*(_QWORD *)(v92 + 320) + 17664LL);
  else
    v106 = 0;
  *(_DWORD *)(v5 + 21600) = v106;
  *(_DWORD *)(v5 + 8) = *(_DWORD *)(*(_QWORD *)(v92 + 320) + 18432LL);
  if ( *(_BYTE *)(v92 + 10) == 1 )
    v107 = *(_DWORD *)(*(_QWORD *)(v92 + 320) + 7680LL);
  else
    v107 = 0;
  *(_DWORD *)(v5 + 700) = v107;
  if ( *(_BYTE *)(v92 + 11) == 1 )
    v108 = *(_DWORD *)(*(_QWORD *)(v92 + 320) + 8448LL);
  else
    v108 = 0;
  *(_DWORD *)(v5 + 704) = v108;
  *(_BYTE *)(v5 + 708) = *(_DWORD *)(*(_QWORD *)(v92 + 320) + 16128LL) != 0;
  *(_DWORD *)(v5 + 712) = *(_DWORD *)(*(_QWORD *)(v92 + 320) + 16896LL);
  v109 = *(_DWORD *)(*(_QWORD *)(v92 + 320) + 23808LL);
  *(_DWORD *)(v5 + 22120) = v109;
  v110 = *(_DWORD *)(*(_QWORD *)(v92 + 320) + 25344LL);
  *(_DWORD *)(v5 + 22124) = v110;
  v111 = *(_DWORD *)(*(_QWORD *)(v92 + 320) + 27648LL);
  if ( !v111 )
    v111 = 1310720;
  *(_DWORD *)(v5 + 716) = v111;
  v112 = *(_DWORD *)(*(_QWORD *)(v92 + 320) + 28416LL);
  if ( !v112 )
    v112 = 0x40000;
  *(_DWORD *)(v5 + 22132) = v112;
  if ( !v109 || !v110 )
  {
    if ( (_drm_debug & 4) != 0 )
      printk(&unk_232593, v109);
    else
      printk(&unk_27ABDB, "_sde_top_parse_dt_helper");
    *(_DWORD *)(v5 + 52) = 0;
  }
  *(_DWORD *)(v5 + 22128) = *(_DWORD *)(*(_QWORD *)(v92 + 320) + 29184LL);
  v113 = *(_DWORD *)(*(_QWORD *)(v92 + 320) + 26880LL);
  *(_DWORD *)(v5 + 22136) = v113;
  *(_BYTE *)(v5 + 720) = v113 != 0;
  if ( *(_BYTE *)(v92 + 26) == 1 )
  {
    LODWORD(v20) = *(_DWORD *)(v92 + 168);
    *(_DWORD *)(v5 + 21480) = v20;
    if ( (_DWORD)v20 )
    {
      *(_DWORD *)(v5 + 21484) = *(_DWORD *)(*(_QWORD *)(v92 + 320) + 19968LL);
      if ( (_DWORD)v20 != 1 )
      {
        *(_DWORD *)(v5 + 21488) = *(_DWORD *)(*(_QWORD *)(v92 + 320) + 19972LL);
        if ( (_DWORD)v20 != 2 )
        {
          *(_DWORD *)(v5 + 21492) = *(_DWORD *)(*(_QWORD *)(v92 + 320) + 19976LL);
          if ( (_DWORD)v20 != 3 )
          {
            *(_DWORD *)(v5 + 21496) = *(_DWORD *)(*(_QWORD *)(v92 + 320) + 19980LL);
            if ( (_DWORD)v20 != 4 )
            {
              *(_DWORD *)(v5 + 21500) = *(_DWORD *)(*(_QWORD *)(v92 + 320) + 19984LL);
              if ( (_DWORD)v20 != 5 )
              {
                *(_DWORD *)(v5 + 21504) = *(_DWORD *)(*(_QWORD *)(v92 + 320) + 19988LL);
                if ( (_DWORD)v20 != 6 )
                {
                  *(_DWORD *)(v5 + 21508) = *(_DWORD *)(*(_QWORD *)(v92 + 320) + 19992LL);
                  if ( (_DWORD)v20 != 7 )
                  {
                    *(_DWORD *)(v5 + 21512) = *(_DWORD *)(*(_QWORD *)(v92 + 320) + 19996LL);
                    if ( (_DWORD)v20 != 8 )
                    {
                      *(_DWORD *)(v5 + 21516) = *(_DWORD *)(*(_QWORD *)(v92 + 320) + 20000LL);
                      if ( (_DWORD)v20 != 9 )
                      {
                        *(_DWORD *)(v5 + 21520) = *(_DWORD *)(*(_QWORD *)(v92 + 320) + 20004LL);
                        if ( (_DWORD)v20 != 10 )
                        {
                          *(_DWORD *)(v5 + 21524) = *(_DWORD *)(*(_QWORD *)(v92 + 320) + 20008LL);
                          if ( (_DWORD)v20 != 11 )
                          {
                            *(_DWORD *)(v5 + 21528) = *(_DWORD *)(*(_QWORD *)(v92 + 320) + 20012LL);
                            if ( (_DWORD)v20 != 12 )
                            {
LABEL_327:
                              __break(0x5512u);
                              goto LABEL_328;
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  if ( *(_DWORD *)(*(_QWORD *)(v92 + 320) + 12288LL) )
  {
    _X8 = (unsigned __int64 *)(v5 + 22008);
    __asm { PRFM            #0x11, [X8] }
    do
      v149 = __ldxr(_X8);
    while ( __stxr(v149 | 0x8000, _X8) );
  }
  if ( *(_DWORD *)(*(_QWORD *)(v92 + 320) + 13056LL) )
  {
    _X8 = (unsigned __int64 *)(v5 + 22008);
    __asm { PRFM            #0x11, [X8] }
    do
      v152 = __ldxr(_X8);
    while ( __stxr(v152 | 2, _X8) );
  }
  if ( *(_DWORD *)(*(_QWORD *)(v92 + 320) + 14592LL) )
  {
    _X8 = (unsigned __int64 *)(v5 + 22008);
    __asm { PRFM            #0x11, [X8] }
    do
      v155 = __ldxr(_X8);
    while ( __stxr(v155 | 0x200, _X8) );
  }
  if ( *(_DWORD *)(*(_QWORD *)(v92 + 320) + 15360LL) )
  {
    _X8 = (unsigned __int64 *)(v5 + 22008);
    __asm { PRFM            #0x11, [X8] }
    do
      v158 = __ldxr(_X8);
    while ( __stxr(v158 | 0x4000, _X8) );
  }
  *(_DWORD *)(v5 + 21604) = *(_DWORD *)(*(_QWORD *)(v92 + 320) + 19200LL);
  if ( *(_DWORD *)(*(_QWORD *)(v92 + 320) + 20736LL) )
  {
    _X8 = (unsigned __int64 *)(v5 + 22008);
    __asm { PRFM            #0x11, [X8] }
    do
      v161 = __ldxr(_X8);
    while ( __stxr(v161 | 0x2000, _X8) );
  }
  *(_DWORD *)(v5 + 20) = *(_DWORD *)(*(_QWORD *)(v92 + 320) + 9984LL);
  *(_BYTE *)(v5 + 20120) = *(_DWORD *)(*(_QWORD *)(v92 + 320) + 21504LL) != 0;
  *(_DWORD *)(v5 + 21472) = *(_DWORD *)(*(_QWORD *)(v92 + 320) + 22272LL);
  *(_BYTE *)(v5 + 22016) = *(_DWORD *)(*(_QWORD *)(v92 + 320) + 26112LL) != 0;
  if ( *(_BYTE *)(v92 + 30) == 1 )
  {
    v114 = *(_DWORD *)(v92 + 184);
    v115 = v114 >= 0 ? *(_DWORD *)(v92 + 184) : v114 + 1;
    v116 = v115 >> 1;
    *(_DWORD *)(v5 + 20124) = v116;
    if ( (unsigned int)(v114 + 1) >= 3 )
    {
      v20 = 0;
      if ( v116 <= 1 )
        v116 = 1;
      v117 = 23044;
      v118 = 96LL * v116;
      while ( v20 != 1344 )
      {
        v119 = (_QWORD *)(v5 + 20128 + v20);
        v20 += 96;
        v120 = *(unsigned int *)(*(_QWORD *)(v92 + 320) + v117 - 4);
        *v119 = v120;
        v121 = *(unsigned int *)(*(_QWORD *)(v92 + 320) + v117);
        v117 += 8;
        v119[1] = v121 + v120;
        if ( v118 == v20 )
          goto LABEL_259;
      }
      goto LABEL_327;
    }
  }
LABEL_259:
  if ( *(_DWORD *)(*(_QWORD *)(v92 + 320) + 24576LL) )
  {
    _X8 = (unsigned __int64 *)(v5 + 22008);
    __asm { PRFM            #0x11, [X8] }
    do
      v164 = __ldxr(_X8);
    while ( __stxr(v164 | 0x100000000000LL, _X8) );
  }
  if ( *(_DWORD *)v5 >> 28 > 4u )
  {
    if ( (*(_DWORD *)v5 & 0x80000000) == 0 )
    {
      _X8 = (unsigned __int64 *)(v5 + 680);
      __asm { PRFM            #0x11, [X8] }
      do
        v173 = __ldxr(_X8);
      while ( __stxr(v173 | 0x80, _X8) );
    }
  }
  else
  {
    _X8 = (unsigned __int64 *)(v5 + 680);
    __asm { PRFM            #0x11, [X8] }
    do
      v167 = __ldxr(_X8);
    while ( __stxr(v167 | 0x40, _X8) );
  }
  if ( *(_DWORD *)(v5 + 22144) == 1 )
  {
    _X8 = (unsigned __int64 *)(v5 + 680);
    __asm { PRFM            #0x11, [X8] }
    do
      v170 = __ldxr(_X8);
    while ( __stxr(v170 | 0x1000, _X8) );
  }
  dt_entry = add_to_irq_offset_list(v5, 0, 1, *(unsigned int *)(v5 + 668));
  if ( dt_entry )
    goto LABEL_306;
  dt_entry = add_to_irq_offset_list(v5, 0, 2, *(unsigned int *)(v5 + 668));
  if ( dt_entry )
    goto LABEL_306;
  dt_entry = add_to_irq_offset_list(v5, 0, 3, *(unsigned int *)(v5 + 668));
  if ( dt_entry )
    goto LABEL_306;
  string = of_property_read_string(v1, off_9DB0, s1);
  if ( string )
  {
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "invalid %s node in device tree: %d\n", off_9DB0, string);
    goto LABEL_284;
  }
  v123 = s1[0];
  if ( !strcmp(s1[0], "qseedv3") )
  {
    v124 = 3;
LABEL_283:
    *(_DWORD *)(v5 + 16) = v124;
    goto LABEL_284;
  }
  if ( !strcmp(v123, "qseedv3lite") )
  {
    v124 = 22;
    goto LABEL_283;
  }
  if ( !strcmp(v123, "qseedv2") )
  {
    v124 = 2;
    goto LABEL_283;
  }
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "Unknown type %s for property %s\n", v123, off_9DB0);
LABEL_284:
  v125 = of_property_read_string(v1, off_9DE0, s1);
  if ( v125 )
  {
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "invalid %s node in device tree: %d\n", off_9DE0, v125);
    goto LABEL_294;
  }
  v126 = s1[0];
  if ( !strcmp(s1[0], "csc") )
  {
    v127 = 4;
LABEL_293:
    *(_DWORD *)(v5 + 21608) = v127;
    goto LABEL_294;
  }
  if ( !strcmp(v126, "csc-10bit") )
  {
    v127 = 5;
    goto LABEL_293;
  }
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "Unknown type %s for property %s\n", v126, off_9DE0);
LABEL_294:
  v128 = off_9E40;
  *(_DWORD *)(v5 + 24) = 0;
  v129 = of_property_read_string(v1, v128, s1);
  if ( v129 )
  {
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "invalid %s node in device tree: %d\n", off_9E40, v129);
    goto LABEL_297;
  }
  v130 = s1[0];
  if ( !strcmp(s1[0], "smart_dma_v2p5") )
  {
    v131 = 12;
LABEL_305:
    dt_entry = 0;
    *(_DWORD *)(v5 + 24) = v131;
    goto LABEL_306;
  }
  if ( !strcmp(v130, "smart_dma_v2") )
  {
    v131 = 11;
    goto LABEL_305;
  }
  if ( !strcmp(v130, "smart_dma_v1") )
  {
    printk(&unk_22171B, "sde_top_parse_dt");
  }
  else if ( (_drm_debug & 4) != 0 )
  {
    _drm_dev_dbg(0, 0, 0, "unknown smart dma version %s\n", v130);
  }
LABEL_297:
  dt_entry = 0;
LABEL_306:
  if ( v92 )
  {
    kvfree(*(_QWORD *)(v92 + 320));
    kvfree(v92);
  }
LABEL_308:
  if ( dt_entry )
    goto LABEL_9;
  if ( (unsigned int)sde_perf_power_parse_dt(v1, v5) )
    goto LABEL_9;
  if ( (unsigned int)sde_ctl_sspp_dspp_parse_dt(v1, v5) )
    goto LABEL_9;
  if ( (unsigned int)sde_ds_parse_dt(v1, v5) )
    goto LABEL_9;
  if ( (unsigned int)sde_dsc_parse_dt(v1, v5) )
    goto LABEL_9;
  if ( (unsigned int)sde_vdc_parse_dt(v1, v5) )
    goto LABEL_9;
  if ( (unsigned int)sde_pp_parse_dt(v1, v5) )
    goto LABEL_9;
  if ( (unsigned int)sde_mixer_parse_dt(v1, v5) )
    goto LABEL_9;
  if ( (unsigned int)sde_intf_parse_dt(v1, v5) )
    goto LABEL_9;
  if ( (unsigned int)sde_wb_parse_dt(v1, v5) )
    goto LABEL_9;
  if ( (unsigned int)sde_cdm_parse_dt(v1, v5) )
    goto LABEL_9;
  if ( (unsigned int)sde_dnsc_blur_parse_dt(v1, v5) )
    goto LABEL_9;
  if ( (unsigned int)sde_vbif_parse_dt(v1, v5) )
    goto LABEL_9;
  sde_parse_reg_dma_dt(v1, v5);
  if ( (unsigned int)sde_parse_merge_3d_dt(v1, v5)
    || (unsigned int)sde_qdss_parse_dt(v1, v5)
    || (unsigned int)sde_hardware_post_caps(v5)
    || (unsigned int)sde_hw_check_ssip_fuse(a1, v5) )
  {
    goto LABEL_9;
  }
LABEL_102:
  _ReadStatusReg(SP_EL0);
  return v5;
}
