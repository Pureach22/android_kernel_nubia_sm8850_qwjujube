__int64 __fastcall sde_perf_power_parse_dt(__int64 a1, __int64 a2)
{
  int *v4; // x21
  int v5; // w0
  unsigned int v6; // w19
  __int64 result; // x0
  int v8; // w0
  const char *v9; // x8
  char *v10; // x1
  int v11; // w0
  const char *v12; // x8
  char *v13; // x1
  int v14; // w0
  const char *v15; // x8
  char *v16; // x1
  int v17; // w0
  double v18; // d0
  const char *v19; // x8
  int v20; // w9
  int v21; // w8
  int v22; // w9
  int v23; // w8
  int v24; // w9
  int v25; // w8
  int v26; // w9
  int v27; // w8
  int v28; // w9
  int v29; // w8
  int v30; // w9
  int v31; // w8
  int v32; // w9
  int v33; // w8
  int v34; // w9
  int v35; // w8
  int v36; // w9
  int v37; // w8
  int v38; // w9
  int v39; // w8
  int v40; // w9
  int v41; // w8
  int v42; // w9
  int v43; // w8
  int v44; // w9
  int v45; // w8
  int v46; // w9
  int v47; // w8
  int v48; // w9
  int v49; // w8
  int v50; // w9
  int v51; // w8
  int v52; // w9
  int v53; // w8
  int v54; // w9
  int v55; // w22
  int v56; // w8
  int v57; // w9
  int v58; // w8
  int v59; // w9
  __int64 v60; // x0
  int v61; // w0
  __int64 v62; // x0
  int v63; // w0
  int v64; // w8
  int v65; // w9
  int v66; // w8
  __int64 v67; // x25
  __int64 v68; // x0
  __int64 v69; // x22
  __int64 v70; // x0
  __int64 v71; // x22
  __int64 v72; // x22
  __int64 v73; // x26
  int v74; // w22
  unsigned __int64 v75; // x25
  int *v76; // x21
  unsigned __int64 v77; // x0
  __int64 v78; // x20
  unsigned __int64 v79; // x0
  __int64 v80; // x20
  unsigned __int64 v81; // x0
  __int64 v82; // x20
  int v83; // w3
  int v84; // w4
  char v86; // w20
  unsigned __int64 StatusReg; // x22
  __int64 v88; // x23
  unsigned __int64 v94; // x9
  unsigned __int64 v97; // x9
  const char *v98; // [xsp+8h] [xbp-98h] BYREF
  __int64 v99; // [xsp+10h] [xbp-90h] BYREF
  __int64 v100; // [xsp+18h] [xbp-88h]
  __int64 v101; // [xsp+20h] [xbp-80h]
  __int16 v102; // [xsp+28h] [xbp-78h]
  __int64 v103; // [xsp+30h] [xbp-70h] BYREF
  __int64 v104; // [xsp+38h] [xbp-68h]
  __int64 v105; // [xsp+40h] [xbp-60h]
  __int64 v106; // [xsp+48h] [xbp-58h]
  __int64 v107; // [xsp+50h] [xbp-50h]
  __int64 v108; // [xsp+58h] [xbp-48h]
  __int64 v109; // [xsp+60h] [xbp-40h]
  __int64 v110; // [xsp+68h] [xbp-38h]
  __int64 v111; // [xsp+70h] [xbp-30h]
  __int64 v112; // [xsp+78h] [xbp-28h]
  _QWORD v113[4]; // [xsp+80h] [xbp-20h] BYREF

  v113[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v112 = 0;
  memset(v113, 0, 24);
  v110 = 0;
  v111 = 0;
  v108 = 0;
  v109 = 0;
  v106 = 0;
  v107 = 0;
  v104 = 0;
  v105 = 0;
  v103 = 0;
  v102 = 0;
  v100 = 0;
  v101 = 0;
  v99 = 0;
  v4 = (int *)_kvmalloc_node_noprof(19968, 0, 3520, 0xFFFFFFFFLL);
  if ( !v4 )
    goto LABEL_167;
  while ( 1 )
  {
    LODWORD(v98) = 0;
    v5 = validate_dt_entry(a1, &sde_perf_prop, 26, &v103, &v98);
    if ( v5 )
      goto LABEL_5;
    v5 = validate_dt_entry(a1, &unk_A228, 1, (char *)v113 + 4, 0);
    if ( v5 )
      goto LABEL_5;
    v5 = read_dt_entry(a1, &sde_perf_prop, 26, &v103, &v99, v4);
    if ( v5 )
      goto LABEL_5;
    v98 = nullptr;
    v8 = of_property_read_string(a1, off_A0B0, &v98);
    v9 = v98;
    v10 = off_A0C8;
    if ( v8 )
      v9 = "6.0";
    *(_QWORD *)(a2 + 21728) = v9;
    v11 = of_property_read_string(a1, v10, &v98);
    v12 = v98;
    v13 = off_A0E0;
    if ( v11 )
      v12 = "1.0";
    *(_QWORD *)(a2 + 21736) = v12;
    v14 = of_property_read_string(a1, v13, &v98);
    v15 = v98;
    v16 = off_A0F8;
    if ( v14 )
      v15 = "NV12/5/1/1.23 AB24/5/1/1.23 XB24/5/1/1.23";
    *(_QWORD *)(a2 + 21744) = v15;
    v17 = of_property_read_string(a1, v16, &v98);
    v19 = v98;
    v20 = (unsigned __int8)v99;
    if ( v17 )
      v19 = "NV12/5/1/1.25 AB24/5/1/1.25 XB24/5/1/1.25";
    *(_QWORD *)(a2 + 21752) = v19;
    if ( v20 == 1 )
      v21 = *v4;
    else
      v21 = 7000000;
    v22 = BYTE1(v99);
    *(_DWORD *)(a2 + 21704) = v21;
    if ( v22 == 1 )
      v23 = v4[192];
    else
      v23 = 7000000;
    v24 = BYTE2(v99);
    *(_DWORD *)(a2 + 21708) = v23;
    if ( v24 == 1 )
      v25 = v4[384];
    else
      v25 = 7000000;
    v26 = BYTE3(v99);
    *(_DWORD *)(a2 + 21712) = v25;
    if ( v26 == 1 )
      v27 = v4[576];
    else
      v27 = 7000000;
    v28 = BYTE4(v99);
    *(_DWORD *)(a2 + 21716) = v27;
    if ( v28 == 1 )
      v29 = v4[768];
    else
      v29 = 7000000;
    v30 = BYTE1(v100);
    *(_DWORD *)(a2 + 21720) = v29;
    if ( v30 == 1 )
      v31 = v4[1728];
    else
      v31 = 2;
    v32 = HIBYTE(v100);
    *(_DWORD *)(a2 + 21760) = v31;
    if ( v32 == 1 )
      v33 = v4[2880];
    else
      v33 = 2;
    v34 = BYTE2(v100);
    *(_DWORD *)(a2 + 21764) = v33;
    if ( v34 == 1 )
      v35 = v4[1920];
    else
      v35 = 3;
    v36 = BYTE3(v100);
    *(_DWORD *)(a2 + 21768) = v35;
    if ( v36 == 1 )
      v37 = v4[2112];
    else
      v37 = 4;
    v38 = BYTE4(v100);
    *(_DWORD *)(a2 + 21772) = v37;
    if ( v38 == 1 )
      v39 = v4[2304];
    else
      v39 = 8;
    v40 = BYTE5(v100);
    *(_DWORD *)(a2 + 21776) = v39;
    if ( v40 == 1 )
      v41 = v4[2496];
    else
      v41 = 1;
    v42 = BYTE6(v100);
    *(_DWORD *)(a2 + 21780) = v41;
    if ( v42 == 1 )
      v43 = v4[2688];
    else
      v43 = 1;
    v44 = BYTE2(v101);
    *(_DWORD *)(a2 + 21784) = v43;
    if ( v44 == 1 )
      v45 = v4[3456];
    else
      v45 = 25;
    v46 = (unsigned __int8)v101;
    *(_DWORD *)(a2 + 21788) = v45;
    if ( v46 == 1 )
      v47 = v4[3072];
    else
      v47 = 4;
    v48 = BYTE1(v101);
    *(_DWORD *)(a2 + 21872) = v47;
    if ( v48 == 1 )
      v49 = v4[3264];
    else
      v49 = 64;
    v50 = BYTE3(v101);
    *(_DWORD *)(a2 + 21876) = v49;
    if ( v50 == 1 )
      v51 = v4[3648];
    else
      v51 = 2;
    v52 = BYTE4(v101);
    *(_DWORD *)(a2 + 21884) = v51;
    if ( v52 == 1 )
      v53 = v4[3840];
    else
      v53 = 32;
    v54 = BYTE5(v101);
    *(_DWORD *)(a2 + 21880) = v53;
    if ( v54 == 1 )
    {
      v55 = HIDWORD(v113[0]);
      if ( HIDWORD(v113[0]) >= 2 )
      {
        v56 = v4[4032];
        v57 = v4[4033];
        *(_BYTE *)(a2 + 21840) = v56 != 0;
        *(_BYTE *)(a2 + 21841) = v57 != 0;
        if ( (_drm_debug & 4) != 0 )
          v18 = _drm_dev_dbg(0, 0, 0, "cdp usage:%d rd:%d wr:%d\n", 0, v56 != 0, v57 != 0);
        if ( (v55 & 0xFFFFFFFE) != 2 )
        {
          v58 = v4[4034];
          v59 = v4[4035];
          *(_BYTE *)(a2 + 21842) = v58 != 0;
          *(_BYTE *)(a2 + 21843) = v59 != 0;
          if ( (_drm_debug & 4) != 0 )
            _drm_dev_dbg(0, 0, 0, "cdp usage:%d rd:%d wr:%d\n", 1, v58 != 0, v59 != 0, v18);
        }
      }
      _X8 = (unsigned __int64 *)(a2 + 22008);
      __asm { PRFM            #0x11, [X8] }
      do
        v94 = __ldxr(_X8);
      while ( __stxr(v94 | 1, _X8) );
    }
    if ( BYTE6(v101) == 1 )
      v60 = (unsigned int)v4[4224];
    else
      v60 = 0;
    v61 = sde_set_possible_cpu_mask(v60);
    _ZF = HIBYTE(v101) == 1;
    *(_QWORD *)(a2 + 21848) = v61;
    if ( _ZF )
      v62 = (unsigned int)v4[4416];
    else
      v62 = 0;
    v63 = sde_set_possible_cpu_mask(v62);
    _ZF = (unsigned __int8)v102 == 1;
    *(_QWORD *)(a2 + 21856) = v63;
    if ( _ZF )
      v64 = v4[4608];
    else
      v64 = -1;
    v65 = HIBYTE(v102);
    *(_DWORD *)(a2 + 21864) = v64;
    if ( v65 == 1 )
      v66 = v4[4800];
    else
      v66 = -1;
    *(_DWORD *)(a2 + 21868) = v66;
    kvfree(v4);
    v103 = 0;
    v104 = 0;
    LODWORD(v99) = 0;
    v4 = (int *)_kvmalloc_node_noprof(3072, 0, 3520, 0xFFFFFFFFLL);
    if ( !v4 )
      goto LABEL_167;
    v5 = validate_dt_entry(a1, &sde_qos_prop, 4, &v103, 0);
    if ( v5 )
      goto LABEL_5;
    v5 = read_dt_entry(a1, &sde_qos_prop, 4, &v103, &v99, v4);
    if ( v5 )
      goto LABEL_5;
    if ( (unsigned __int8)v99 == 1 )
    {
      v67 = (unsigned int)v103;
      v68 = _kvmalloc_node_noprof(4LL * (unsigned int)v103, 0, 3520, 0xFFFFFFFFLL);
      *(_QWORD *)(a2 + 21832) = v68;
      if ( !v68 )
        goto LABEL_171;
      if ( (_DWORD)v67 )
      {
        v69 = 0;
        while ( v69 != 64 )
        {
          *(_DWORD *)(*(_QWORD *)(a2 + 21832) + 4 * v69) = v4[v69];
          if ( (_drm_debug & 4) != 0 )
            _drm_dev_dbg(
              0,
              0,
              0,
              "qos usage:%d refresh rate:0x%x\n",
              v69,
              *(_DWORD *)(*(_QWORD *)(a2 + 21832) + 4 * v69));
          if ( v67 == ++v69 )
            goto LABEL_97;
        }
        goto LABEL_166;
      }
    }
    else
    {
      LODWORD(v67) = 1;
    }
LABEL_97:
    *(_DWORD *)(a2 + 21824) = v67;
    *(_QWORD *)(a2 + 21800) = _kvmalloc_node_noprof(144LL * (unsigned int)v67, 0, 3520, 0xFFFFFFFFLL);
    *(_QWORD *)(a2 + 21808) = _kvmalloc_node_noprof(144LL * (unsigned int)v67, 0, 3520, 0xFFFFFFFFLL);
    v70 = _kvmalloc_node_noprof(144LL * (unsigned int)v67, 0, 3520, 0xFFFFFFFFLL);
    *(_QWORD *)(a2 + 21816) = v70;
    if ( !v70 || !*(_QWORD *)(a2 + 21808) || !*(_QWORD *)(a2 + 21800) )
    {
LABEL_171:
      kvfree(*(_QWORD *)(a2 + 21832));
      kvfree(*(_QWORD *)(a2 + 21816));
      kvfree(*(_QWORD *)(a2 + 21800));
      kvfree(*(_QWORD *)(a2 + 21808));
      v5 = -12;
LABEL_5:
      v6 = v5;
      kvfree(v4);
      result = v6;
      goto LABEL_168;
    }
    if ( BYTE1(v99) == 1 && HIDWORD(v103) >= (unsigned int)(18 * v67) && SHIDWORD(v103) >= 1 )
    {
      v71 = 0;
      while ( v71 != 64 )
      {
        *(_QWORD *)(*(_QWORD *)(a2 + 21800) + 8 * v71) = (unsigned int)v4[v71 + 192];
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(0, 0, 0, "danger usage:%i lut:0x%llx\n", v71, *(_QWORD *)(*(_QWORD *)(a2 + 21800) + 8 * v71));
        if ( ++v71 >= SHIDWORD(v103) )
          goto LABEL_108;
      }
      goto LABEL_166;
    }
LABEL_108:
    if ( BYTE2(v99) == 1 && (unsigned int)v104 >= 18 * (int)v67 && (int)v104 >= 1 )
    {
      v72 = 0;
      while ( v72 != 64 )
      {
        *(_QWORD *)(*(_QWORD *)(a2 + 21808) + 8 * v72) = (unsigned int)v4[v72 + 384];
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(0, 0, 0, "safe usage:%d lut:0x%llx\n", v72, *(_QWORD *)(*(_QWORD *)(a2 + 21808) + 8 * v72));
        if ( ++v72 >= (int)v104 )
          goto LABEL_116;
      }
      goto LABEL_166;
    }
LABEL_116:
    if ( BYTE3(v99) != 1 || (unsigned int)(18 * v67 - 1) >= HIDWORD(v104) )
      break;
    v73 = 8LL * (unsigned int)(18 * v67);
    v74 = 0;
    v75 = 0;
    while ( v75 != 256 )
    {
      *(_QWORD *)(*(_QWORD *)(a2 + 21816) + v75) = (unsigned int)v4[v75 / 4 + 577]
                                                 | ((unsigned __int64)(unsigned int)v4[v75 / 4 + 576] << 32);
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(0, 0, 0, "creq usage:%d lut:0x%llx\n", v74, *(_QWORD *)(*(_QWORD *)(a2 + 21816) + v75));
      v75 += 8LL;
      ++v74;
      if ( v73 == v75 )
        goto LABEL_123;
    }
LABEL_166:
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v88 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &sde_perf_parse_dt__alloc_tag;
    v4 = (int *)_kvmalloc_node_noprof(19968, 0, 3520, 0xFFFFFFFFLL);
    *(_QWORD *)(StatusReg + 80) = v88;
    if ( !v4 )
      goto LABEL_167;
  }
LABEL_123:
  kvfree(v4);
  v103 = 0;
  LOWORD(v98) = 0;
  LODWORD(v99) = 0;
  v76 = (int *)_kvmalloc_node_noprof(1536, 0, 3520, 0xFFFFFFFFLL);
  if ( !v76 )
  {
LABEL_167:
    result = 4294967284LL;
    goto LABEL_168;
  }
  if ( (unsigned int)validate_dt_entry(a1, &uidle_prop, 2, &v103, &v99)
    || (unsigned int)read_dt_entry(a1, &uidle_prop, 2, &v103, &v98, v76) )
  {
    goto LABEL_126;
  }
  if ( BYTE1(v98) == 1 && ((unsigned __int8)v98 & 1) != 0 )
  {
    v83 = *v76;
    v84 = v76[192];
    *(_DWORD *)(a2 + 21904) = 1;
    *(_DWORD *)(a2 + 21908) = v83;
    if ( v83 )
      _ZF = v84 == 0;
    else
      _ZF = 1;
    *(_DWORD *)(a2 + 21912) = v84;
    v86 = !_ZF;
    if ( _ZF )
      printk(&unk_224E9A, "sde_uidle_parse_dt");
    if ( *(_DWORD *)a2 >> 30 == 3 )
    {
      _X8 = (unsigned __int64 *)(a2 + 21920);
      __asm { PRFM            #0x11, [X8] }
      do
        v97 = __ldxr(_X8);
      while ( __stxr(v97 | 8, _X8) );
      if ( (v86 & 1) != 0 )
        goto LABEL_130;
    }
    else if ( (v86 & 1) != 0 )
    {
      goto LABEL_130;
    }
  }
  else if ( (_drm_debug & 4) != 0 )
  {
    _drm_dev_dbg(0, 0, 0, "offset/len missing, will disable uidle:%d,%d\n", BYTE1(v98), (unsigned __int8)v98);
  }
LABEL_126:
  if ( *(_DWORD *)(a2 + 21976) )
  {
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "wrong dt entries, will disable uidle\n");
    *(_DWORD *)(a2 + 21976) = 0;
  }
LABEL_130:
  kvfree(v76);
  if ( !of_find_node_by_name(0, "cache-controller") )
  {
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "cache controller missing, will disable img cache\n");
LABEL_148:
    result = 0;
    goto LABEL_168;
  }
  if ( (*(_QWORD *)(a2 + 21696) & 1) == 0 )
    goto LABEL_136;
  v77 = llcc_slice_getd(16);
  v78 = v77;
  if ( !v77 || v77 > 0xFFFFFFFFFFFFF000LL )
    goto LABEL_165;
  *(_QWORD *)(a2 + 21624) = v77;
  *(_DWORD *)(a2 + 21632) = 16;
  *(_DWORD *)(a2 + 21636) = llcc_get_slice_id(v77);
  *(_QWORD *)(a2 + 21640) = llcc_get_slice_size(v78);
  sde_core_perf_llcc_stale_configure(a2, v78);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "img cache:%d usecase_id:%d, scid:%d slice_size:%zu kb\n",
      0,
      16,
      *(_DWORD *)(a2 + 21636),
      *(_QWORD *)(a2 + 21640));
LABEL_136:
  if ( (*(_QWORD *)(a2 + 21696) & 2) == 0 )
  {
LABEL_141:
    if ( (*(_QWORD *)(a2 + 21696) & 4) != 0 )
    {
      v81 = llcc_slice_getd(53);
      v82 = v81;
      if ( !v81 || v81 > 0xFFFFFFFFFFFFF000LL )
        goto LABEL_165;
      *(_QWORD *)(a2 + 21672) = v81;
      *(_DWORD *)(a2 + 21680) = 53;
      *(_DWORD *)(a2 + 21684) = llcc_get_slice_id(v81);
      *(_QWORD *)(a2 + 21688) = llcc_get_slice_size(v82);
      sde_core_perf_llcc_stale_configure(a2, v82);
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(
          0,
          0,
          0,
          "img cache:%d usecase_id:%d, scid:%d slice_size:%zu kb\n",
          2,
          53,
          *(_DWORD *)(a2 + 21684),
          *(_QWORD *)(a2 + 21688));
    }
    goto LABEL_148;
  }
  v79 = llcc_slice_getd(54);
  v80 = v79;
  if ( v79 && v79 <= 0xFFFFFFFFFFFFF000LL )
  {
    *(_QWORD *)(a2 + 21648) = v79;
    *(_DWORD *)(a2 + 21656) = 54;
    *(_DWORD *)(a2 + 21660) = llcc_get_slice_id(v79);
    *(_QWORD *)(a2 + 21664) = llcc_get_slice_size(v80);
    sde_core_perf_llcc_stale_configure(a2, v80);
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(
        0,
        0,
        0,
        "img cache:%d usecase_id:%d, scid:%d slice_size:%zu kb\n",
        1,
        54,
        *(_DWORD *)(a2 + 21660),
        *(_QWORD *)(a2 + 21664));
    goto LABEL_141;
  }
LABEL_165:
  printk(&unk_277B70, "sde_cache_parse_dt");
  result = 4294967274LL;
LABEL_168:
  _ReadStatusReg(SP_EL0);
  return result;
}
