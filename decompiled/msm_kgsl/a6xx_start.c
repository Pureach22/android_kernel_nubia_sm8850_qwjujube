__int64 __fastcall a6xx_start(__int64 a1)
{
  __int64 v2; // x24
  unsigned __int8 *v3; // x23
  __int64 v4; // x1
  unsigned int v5; // w20
  unsigned int v6; // w21
  unsigned int v7; // w8
  int *v8; // x8
  int v9; // w20
  const char *v10; // x0
  __int64 v11; // x0
  __int64 v12; // x1
  int v13; // w25
  int v14; // w27
  int v15; // w26
  _DWORD *v16; // x8
  int v17; // w8
  int v18; // w8
  unsigned int v19; // w8
  int v20; // w21
  int v21; // w28
  int v22; // w20
  int *v23; // x8
  int v24; // w23
  unsigned int v25; // w9
  int v26; // w23
  int v27; // w20
  int v28; // w8
  int *v29; // x8
  int v30; // w20
  unsigned int v31; // w9
  _DWORD *v32; // x20
  int v33; // w21
  _DWORD *v34; // x8
  unsigned __int64 v35; // x0
  int slice_id; // w0
  int v37; // w20
  __int64 v38; // x1
  int *v39; // x8
  int v40; // w21
  const char *v41; // x0
  unsigned __int64 v42; // x0
  int v43; // w0
  unsigned __int64 v44; // x0
  char v45; // w0
  int *v46; // x21
  int v47; // w20
  const char *v48; // x0
  const char *v49; // x0
  __int64 v50; // x1
  __int64 v51; // x26
  int v52; // w25
  __int64 v53; // x8
  int v54; // w21
  __int64 v55; // x2
  __int64 v56; // x2
  const char *v57; // x0
  const char *v58; // x0
  bool v59; // zf
  int v60; // w9
  unsigned int v61; // w8
  __int64 v62; // x2
  int v63; // w9
  unsigned int v64; // w8
  __int64 v65; // x2
  int v66; // w8
  int v67; // w20
  __int64 v68; // x3
  int v69; // w8
  int v70; // w9
  char v71; // w9
  int v72; // w8
  int v73; // w8
  int v74; // w0
  unsigned int v75; // w20
  __int64 v76; // x1
  int v77; // w8
  int v78; // w0
  int v79; // w8
  __int64 v80; // x1
  __int64 v81; // x8
  int *v82; // x25
  __int64 v83; // x24
  int v84; // w28
  unsigned int v85; // w26
  __int16 v86; // w21
  void **v87; // x9
  char v88; // w8
  __int64 v89; // x20
  unsigned int v90; // w27
  void **v91; // x8
  int v92; // w9
  __int16 v93; // w8
  _DWORD *v94; // x25
  unsigned int v95; // w23
  unsigned int i; // w26
  __int64 v97; // x28
  int v98; // w0
  __int16 v99; // w8
  _DWORD *v100; // x25
  unsigned int v101; // w23
  __int64 v102; // x26
  int v103; // w0
  __int16 v104; // w8
  _DWORD *v105; // x25
  unsigned int v106; // w23
  __int64 v107; // x26
  int v108; // w0
  __int16 v109; // w8
  _DWORD *v110; // x25
  unsigned int v111; // w23
  __int64 v112; // x26
  int v113; // w0
  int v114; // w1
  __int16 v115; // w8
  __int64 result; // x0
  const char *v117; // x0
  const char *v118; // x0
  const char *v119; // x0
  bool v120; // w8
  unsigned __int8 *v121; // [xsp+8h] [xbp-58h]
  __int64 v122; // [xsp+10h] [xbp-50h] BYREF
  _DWORD *v123; // [xsp+18h] [xbp-48h] BYREF
  __int64 v124; // [xsp+20h] [xbp-40h]
  _DWORD *v125; // [xsp+28h] [xbp-38h]
  __int64 v126; // [xsp+30h] [xbp-30h]
  _DWORD *v127; // [xsp+38h] [xbp-28h]
  __int64 v128; // [xsp+40h] [xbp-20h]
  _DWORD *v129; // [xsp+48h] [xbp-18h]
  __int64 v130; // [xsp+50h] [xbp-10h]
  __int64 v131; // [xsp+58h] [xbp-8h]

  v131 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 14264);
  v3 = (unsigned __int8 *)(a1 + 20434);
  v122 = 0;
  kgsl_regmap_write(a1 + 13200, 1);
  kgsl_regmap_write(a1 + 13200, 1);
  kgsl_regmap_write(a1 + 13200, 1);
  kgsl_regmap_write(a1 + 13200, 1);
  kgsl_regmap_write(a1 + 13200, 1);
  kgsl_regmap_write(a1 + 13200, 1);
  kgsl_regmap_write(a1 + 13200, 1);
  kgsl_regmap_write(a1 + 13200, 1);
  kgsl_regmap_write(a1 + 13200, 1);
  kgsl_regmap_write(a1 + 13200, 1);
  kgsl_regmap_write(a1 + 13200, 1);
  kgsl_regmap_write(a1 + 13200, 1);
  kgsl_regmap_multi_write(a1 + 13200, *(_QWORD *)(v2 + 144), *(unsigned int *)(v2 + 152));
  if ( (v3[223] & 1) != 0 )
    kgsl_regmap_write(a1 + 13200, 16908537);
  kgsl_regmap_write(a1 + 13200, 0xFFFFFFFFLL);
  kgsl_regmap_write(a1 + 13200, 4294967232LL);
  kgsl_regmap_write(a1 + 13200, 0x1FFFF);
  kgsl_regmap_write(a1 + 13200, 4294963200LL);
  kgsl_regmap_write(a1 + 13200, 0x1FFFF);
  kgsl_regmap_write(a1 + 13200, 4294963200LL);
  kgsl_regmap_write(a1 + 13200, 0x1FFFF);
  v4 = *(_QWORD *)(a1 + 14256);
  if ( v4 )
  {
    kgsl_regmap_write(a1 + 13200, v4);
    kgsl_regmap_write(a1 + 13200, 0);
    kgsl_regmap_write(
      a1 + 13200,
      (unsigned int)(*(_DWORD *)(*(_QWORD *)(a1 + 14264) + 64LL) + *(_DWORD *)(a1 + 14256) - 1));
    kgsl_regmap_write(a1 + 13200, 0);
  }
  v5 = 1075845910;
  v6 = 8388704;
  kgsl_regmap_write(a1 + 13200, 2052);
  kgsl_regmap_write(a1 + 13200, 4);
  v7 = **(_DWORD **)(a1 + 14264);
  if ( v7 - 610 >= 3 && v7 != 702 && v7 != 203264 )
  {
    if ( v7 <= 0x27F )
      v6 = 16777408;
    else
      v6 = 33554752;
    v5 = -2143275476;
  }
  kgsl_regmap_write(a1 + 13200, v6);
  kgsl_regmap_write(a1 + 13200, v5);
  v8 = *(int **)(a1 + 14264);
  v9 = *v8;
  if ( *v8 == 660
    || (v10 = *((const char **)v8 + 3)) != nullptr && !strcmp(v10, "qcom,adreno-gpu-a642l")
    || v9 == 662
    || v9 == 643 )
  {
    kgsl_regmap_write(a1 + 13200, 32);
    v9 = **(_DWORD **)(a1 + 14264);
  }
  if ( v9 == 663 )
  {
    kgsl_regmap_write(a1 + 13200, 0);
    kgsl_regmap_write(a1 + 13200, 0);
    kgsl_regmap_write(a1 + 13200, 32);
    v9 = **(_DWORD **)(a1 + 14264);
  }
  if ( v9 == 612 || v9 == 203264 || (v9 & 0xFFFFFFFE) == 0x262 )
  {
    kgsl_regmap_write(a1 + 13200, 48);
    v11 = a1 + 13200;
    v12 = 47;
  }
  else
  {
    v11 = a1 + 13200;
    if ( v9 == 702 )
    {
      kgsl_regmap_write(v11, 64);
      v11 = a1 + 13200;
      v12 = 63;
    }
    else
    {
      v12 = 128;
    }
  }
  kgsl_regmap_write(v11, v12);
  kgsl_regmap_write(a1 + 13200, *(unsigned int *)(v2 + 96));
  kgsl_regmap_write(a1 + 13200, 1);
  kgsl_regmap_write(a1 + 13200, 1);
  if ( (gmu_core_isenabled(a1) & 1) != 0 )
    gmu_core_regrmw(a1, 129090, 255, 4);
  if ( (gmu_core_isenabled(a1) & 1) != 0 && **(_DWORD **)(a1 + 14264) == 612 )
  {
    kgsl_regmap_write(a1 + 13200, 2043);
    kgsl_regmap_write(a1 + 13200, 16);
  }
  if ( (of_property_read_variable_u32_array(
          *(_QWORD *)(*(_QWORD *)(a1 + 11168) + 760LL),
          "qcom,min-access-length",
          (char *)&v122 + 4,
          1,
          0)
      & 0x80000000) != 0 )
    HIDWORD(v122) = 32;
  if ( (of_property_read_variable_u32_array(*(_QWORD *)(*(_QWORD *)(a1 + 11168) + 760LL), "qcom,ubwc-mode", &v122, 1, 0)
      & 0x80000000) != 0 )
    goto LABEL_35;
  v13 = 0;
  if ( (int)v122 > 2 )
  {
    if ( (_DWORD)v122 == 3 )
    {
      v14 = 0;
      v15 = 0;
      LODWORD(v122) = 0;
    }
    else
    {
      v14 = 0;
      v15 = 0;
      if ( (_DWORD)v122 != 4 )
        goto LABEL_44;
      v16 = *(_DWORD **)(a1 + 14264);
      LODWORD(v122) = 0;
      v14 = 2048;
      v15 = *v16 == 663;
    }
    v13 = 16;
    goto LABEL_44;
  }
  if ( (_DWORD)v122 == 1 )
  {
    v13 = 0;
    v14 = 0;
    v15 = 0;
    LODWORD(v122) = 1;
    goto LABEL_44;
  }
  v14 = 0;
  v15 = 0;
  if ( (_DWORD)v122 == 2 )
  {
LABEL_35:
    v13 = 0;
    v14 = 0;
    v15 = 0;
    LODWORD(v122) = 0;
  }
LABEL_44:
  v17 = **(_DWORD **)(a1 + 14264);
  if ( v17 == 680 || v17 == 663 )
    kgsl_regmap_write(a1 + 13200, 1);
  v18 = *(_DWORD *)(v3 + 218);
  v121 = v3;
  if ( v18 )
  {
    v19 = v18 - 13;
    v20 = (v19 >> 2) & 1;
    v21 = v19 & 3;
  }
  else
  {
    v21 = 0;
    v20 = 0;
    __break(0x800u);
  }
  v22 = HIDWORD(v122);
  v23 = *(int **)(a1 + 14264);
  HIDWORD(v122) = HIDWORD(v122) == 64;
  v24 = *v23;
  v25 = *v23 - 620;
  if ( v25 <= 0x28 && ((1LL << v25) & 0x10040000001LL) != 0
    || (v57 = *((const char **)v23 + 3)) != nullptr && !strcmp(v57, "qcom,adreno-gpu-a642l")
    || (unsigned int)(v24 - 621) <= 0x29 && ((1LL << ((unsigned __int8)v24 - 109)) & 0x20000400003LL) != 0 )
  {
    v26 = 32;
  }
  else
  {
    v26 = 32 * (v24 == 663);
  }
  v59 = v22 == 64;
  v27 = v15 << 12;
  v28 = v59;
  kgsl_regmap_write(a1 + 13200, v14 | v13 | (8 * v28) | (unsigned int)v122 | v27 | (2 * v21) | (v20 << 10));
  kgsl_regmap_write(a1 + 13200, (v15 << 6) | (16 * v20) | (8 * HIDWORD(v122)) | (unsigned int)v122 | (2 * v21));
  kgsl_regmap_write(a1 + 13200, v26 | (8 * HIDWORD(v122)) | (unsigned int)v122 | v27 | (2 * v21) | (v20 << 10));
  kgsl_regmap_write(a1 + 13200, (unsigned int)(v21 << 21) | (HIDWORD(v122) << 23));
  kgsl_regmap_write(a1 + 13200, *(_DWORD *)(v2 + 160) | 0x40000000u);
  kgsl_regmap_write(a1 + 13200, *(_DWORD *)(v121 + 3554) & 0xF | 0x80u);
  v29 = *(int **)(a1 + 14264);
  v30 = *v29;
  v31 = *v29 - 620;
  if ( v31 <= 0x28 && ((1LL << v31) & 0x10040000001LL) != 0
    || (v58 = *((const char **)v29 + 3)) != nullptr && !strcmp(v58, "qcom,adreno-gpu-a642l")
    || (unsigned int)(v30 - 621) <= 0x2A && ((1LL << ((unsigned __int8)v30 - 109)) & 0x60000400003LL) != 0 )
  {
    kgsl_regmap_write(a1 + 13200, 0);
    kgsl_regmap_write(a1 + 13200, 1071669236);
    kgsl_regmap_write(a1 + 13200, 1067510766);
    kgsl_regmap_write(a1 + 13200, 1062310893);
    kgsl_regmap_write(a1 + 13200, 1057113072);
  }
  if ( (v121[222] & 1) != 0 )
    kgsl_regmap_rmw(a1 + 13200, 40448, 0, 256);
  if ( *(_BYTE *)(v2 + 176) == 1 )
    kgsl_regmap_rmw(a1 + 13200, 40448, 0, 512);
  if ( **(_DWORD **)(a1 + 14264) == 702 )
    kgsl_regmap_write(a1 + 13200, 0x1000000);
  if ( (*(_QWORD *)(a1 + 14240) & 0x200) != 0 )
    kgsl_regmap_write(a1 + 13200, 1);
  kgsl_regmap_write(a1 + 13200, 4278190080LL);
  kgsl_regmap_rmw(a1 + 13200, 129089, 255, 32);
  kgsl_regmap_write(a1 + 13200, 1);
  v32 = *(_DWORD **)(*(_QWORD *)(a1 + 14264) + 168LL);
  kgsl_regmap_write(a1 + 13200, 11);
  if ( *v32 )
  {
    v33 = 1;
    v34 = v32;
    do
    {
      kgsl_regmap_write(
        a1 + 13200,
        v34[1] & 0x3FFFF | ((unsigned __int16)((v34[2] - v34[1]) & 0x1FFF) << 18) | (v34[3] << 31));
      v34 = &v32[4 * v33++];
    }
    while ( *v34 );
  }
  v35 = *(_QWORD *)(a1 + 20824);
  if ( v35 && v35 <= 0xFFFFFFFFFFFFF000LL && v121[398] == 1 && !(unsigned int)llcc_slice_activate() )
  {
    slice_id = llcc_get_slice_id(*(_QWORD *)(a1 + 20824));
    v37 = slice_id << 10;
    v38 = *(_DWORD *)(a1 + 68) == 1 ? 15362LL : 161794LL;
    if ( (kgsl_regmap_rmw(
            a1 + 13200,
            v38,
            0x1FFFFFF,
            slice_id | (((32 * slice_id) | slice_id | (slice_id << 10)) << 10) | (unsigned int)(32 * slice_id)),
          v39 = *(int **)(a1 + 14264),
          v40 = *v39,
          *v39 == 660)
      || (v41 = *((const char **)v39 + 3)) != nullptr && !strcmp(v41, "qcom,adreno-gpu-a642l")
      || (unsigned int)(v40 - 643) <= 0x14 && ((1 << (v40 + 125)) & 0x180001) != 0 )
    {
      kgsl_regmap_rmw(a1 + 13200, 15361, 32000, v37 | 0x100u);
    }
  }
  v42 = *(_QWORD *)(a1 + 20840);
  if ( v42
    && v42 <= 0xFFFFFFFFFFFFF000LL
    && v121[414] == 1
    && !(unsigned int)llcc_slice_activate()
    && *(_DWORD *)(a1 + 68) != 1 )
  {
    v43 = llcc_get_slice_id(*(_QWORD *)(a1 + 20840));
    kgsl_regmap_rmw(a1 + 13200, 161794, 1040187392, (unsigned int)(v43 << 25));
  }
  v44 = *(_QWORD *)(a1 + 20856);
  if ( v44
    && v44 <= 0xFFFFFFFFFFFFF000LL
    && v121[430] == 1
    && *(_DWORD *)(a1 + 68) == 1
    && !(unsigned int)llcc_slice_activate() )
  {
    v45 = llcc_get_slice_id(*(_QWORD *)(a1 + 20856));
    kgsl_regmap_rmw(a1 + 13200, 15362, 1015808, (unsigned __int8)(v45 & 0x1F) << 15);
  }
  if ( *(_DWORD *)(a1 + 68) != 1 )
    kgsl_regmap_write(a1 + 13200, 3);
  v46 = *(int **)(a1 + 14264);
  v47 = *v46;
  if ( *v46 == 662 )
  {
    kgsl_regmap_rmw(a1 + 13200, 15360, 960, 320);
    v46 = *(int **)(a1 + 14264);
    v47 = *v46;
  }
  if ( v47 == 660
    || (v48 = *((const char **)v46 + 3)) != nullptr && !strcmp(v48, "qcom,adreno-gpu-a642l")
    || v47 == 662
    || v47 == 643 )
  {
    kgsl_regmap_write(a1 + 13200, 1);
    kgsl_regmap_write(a1 + 13200, 0);
    v46 = *(int **)(a1 + 14264);
    v49 = *((const char **)v46 + 3);
    if ( (!v49 || strcmp(v49, "qcom,adreno-gpu-a642l")) && *v46 != 643 )
    {
      kgsl_regmap_write(a1 + 13200, 420102);
      v46 = *(int **)(a1 + 14264);
    }
  }
  if ( (*((_BYTE *)v46 + 33) & 8) != 0 )
    kgsl_regmap_write(a1 + 13200, 110);
  if ( (a6xx_set_secvid_set & 1) == 0 && *(_BYTE *)(a1 + 96) == 1 )
  {
    kgsl_regmap_write(a1 + 13200, 0);
    kgsl_regmap_write(a1 + 13200, 4026531840LL);
    kgsl_regmap_write(a1 + 13200, 0);
    v50 = (*(_QWORD *)(a1 + 104) & 1LL) != 0 ? 4294963200LL : 0x10000000LL;
    kgsl_regmap_write(a1 + 13200, v50);
    if ( (v121[222] & 0x40) != 0 )
      a6xx_set_secvid_set = 1;
  }
  v51 = *(_QWORD *)(a1 + 14264);
  v52 = *v121;
  if ( (gmu_core_isenabled(a1) & 1) == 0 )
    goto LABEL_161;
  if ( v52 )
  {
    v53 = *(_QWORD *)(a1 + 14264);
    v54 = *(_DWORD *)v53;
    if ( *(int *)v53 <= 620 )
    {
      if ( v54 > 617 )
      {
        if ( v54 != 618 && v54 != 619 )
          goto LABEL_271;
      }
      else if ( (unsigned int)(v54 - 615) >= 2 )
      {
        if ( v54 == 612 )
        {
          v55 = 34;
          goto LABEL_145;
        }
        goto LABEL_271;
      }
      v55 = 546;
      goto LABEL_145;
    }
    if ( v54 > 659 )
    {
      if ( v54 == 660 )
      {
        v55 = 0x20000;
        goto LABEL_145;
      }
      v59 = v54 == 662;
    }
    else
    {
      if ( v54 == 621 )
      {
        v55 = 131584;
        goto LABEL_145;
      }
      v59 = v54 == 622;
    }
    v55 = 131584;
    if ( v59 )
    {
LABEL_145:
      gmu_core_regwrite(a1, 146185, v55);
      v60 = **(_DWORD **)(a1 + 14264);
      v61 = v60 - 612;
      if ( (unsigned int)(v60 - 612) < 7 && ((0x59u >> v61) & 1) != 0 )
      {
        v62 = dword_152C08[v61];
      }
      else if ( v60 == 619 )
      {
        v62 = 273;
      }
      else
      {
        v62 = 65809;
      }
      gmu_core_regwrite(a1, 146186, v62);
      v63 = **(_DWORD **)(a1 + 14264);
      v64 = v63 - 612;
      if ( (unsigned int)(v63 - 612) < 7 && ((0x59u >> v64) & 1) != 0 )
      {
        v65 = dword_152C24[v64];
      }
      else if ( v63 == 619 )
      {
        v65 = 1365;
      }
      else
      {
        v65 = 21845;
      }
      gmu_core_regwrite(a1, 146187, v65);
      v56 = 2;
      v66 = **(_DWORD **)(a1 + 14264);
      if ( v66 != 620 && v66 != 640 )
        v56 = 2 * (unsigned int)(v66 == 650);
      goto LABEL_160;
    }
LABEL_271:
    v119 = *(const char **)(v53 + 24);
    if ( v119 )
      v120 = strcmp(v119, "qcom,adreno-gpu-a642l") == 0;
    else
      v120 = 0;
    v55 = 0x20000;
    if ( v54 != 643 && !v120 )
    {
      if ( v54 == 662 )
        v55 = 0x20000;
      else
        v55 = 131586;
    }
    goto LABEL_145;
  }
  gmu_core_regwrite(a1, 146185, 0);
  gmu_core_regwrite(a1, 146186, 0);
  gmu_core_regwrite(a1, 146187, 0);
  v56 = 0;
LABEL_160:
  gmu_core_regwrite(a1, 129026, v56);
LABEL_161:
  v67 = kgsl_regmap_read(a1 + 13200);
  if ( v52 )
    v68 = 0x20000;
  else
    v68 = 0;
  kgsl_regmap_rmw(a1 + 13200, 3642, 458752, v68);
  if ( !v52 || (v69 = **(_DWORD **)(a1 + 14264), v69 == 203264) )
  {
    kgsl_regmap_rmw(a1 + 13200, 15360, 458752, 0);
    v69 = **(_DWORD **)(a1 + 14264);
  }
  if ( v69 == 612 )
    goto LABEL_170;
  v70 = -1968657918;
  if ( v69 == 630 )
    goto LABEL_171;
  if ( v69 == 203264 )
  {
LABEL_170:
    v70 = -1431786878;
  }
  else
  {
    v70 = -1431786878;
    if ( (v69 & 0xFFFFFFFE) != 0x262 )
    {
      v70 = -1431655806;
      if ( v69 != 702 )
        v70 = -1968657790;
    }
  }
LABEL_171:
  if ( v67 == v70 )
    v71 = v52;
  else
    v71 = 0;
  if ( v67 )
    v72 = 1;
  else
    v72 = v52;
  if ( (v71 & 1) == 0 && v72 )
  {
    if ( (gmu_core_isenabled(a1) & 1) == 0
      || (v73 = **(_DWORD **)(a1 + 14264), (unsigned int)(v73 - 610) < 3)
      || v73 == 702
      || v73 == 203264 )
    {
      if ( (unsigned int)of_device_is_compatible(*(_QWORD *)(*(_QWORD *)(a1 + 11168) + 760LL)) )
      {
        v74 = kgsl_regmap_read(a1 + 13200);
        kgsl_regmap_write(a1 + 13200, v74 & 0xFFFFFFFE);
      }
      if ( !*(_DWORD *)(v51 + 136) )
      {
LABEL_195:
        if ( (gmu_core_isenabled(a1) & 1) == 0
          || (v77 = **(_DWORD **)(a1 + 14264), (unsigned int)(v77 - 610) < 3)
          || v77 == 702
          || v77 == 203264 )
        {
          if ( (unsigned int)of_device_is_compatible(*(_QWORD *)(*(_QWORD *)(a1 + 11168) + 760LL)) )
          {
            v78 = kgsl_regmap_read(a1 + 13200);
            kgsl_regmap_write(a1 + 13200, v78 | 1u);
          }
          if ( v52 )
          {
LABEL_202:
            v79 = **(_DWORD **)(a1 + 14264);
            if ( v79 != 612 )
            {
              v80 = 2326309378LL;
              if ( v79 == 630 )
              {
LABEL_212:
                kgsl_regmap_write(a1 + 13200, v80);
                goto LABEL_213;
              }
              if ( v79 != 203264 )
              {
                v80 = 2863180418LL;
                if ( (v79 & 0xFFFFFFFE) != 0x262 )
                {
                  if ( v79 == 702 )
                    v80 = 2863311490LL;
                  else
                    v80 = 2326309506LL;
                }
                goto LABEL_212;
              }
            }
            v80 = 2863180418LL;
            goto LABEL_212;
          }
        }
        else
        {
          gmu_core_regrmw(a1, 108672, 0, 1);
          if ( v52 )
            goto LABEL_202;
        }
        v80 = 0;
        goto LABEL_212;
      }
    }
    else
    {
      gmu_core_regrmw(a1, 108672, 1, 0);
      if ( !*(_DWORD *)(v51 + 136) )
        goto LABEL_195;
    }
    v75 = 0;
    do
    {
      if ( v52 )
        v76 = *(unsigned int *)(*(_QWORD *)(v51 + 128) + 8LL * (int)v75 + 4);
      else
        v76 = 0;
      kgsl_regmap_write(a1 + 13200, v76);
      ++v75;
    }
    while ( v75 < *(_DWORD *)(v51 + 136) );
    goto LABEL_195;
  }
LABEL_213:
  if ( (v121[3550] & 1) != 0 )
    goto LABEL_258;
  v81 = *(_QWORD *)(a1 + 20464);
  if ( !*(_QWORD *)(v81 + 24) )
    goto LABEL_258;
  v82 = *(int **)(a1 + 14264);
  v83 = *(_QWORD *)(v81 + 8);
  v129 = nullptr;
  v130 = 0;
  v84 = *v82;
  v123 = &a6xx_ifpc_pwrup_reglist;
  v124 = 36;
  v127 = nullptr;
  v128 = 0;
  v125 = nullptr;
  v126 = 0;
  if ( (unsigned int)(v84 - 620) <= 0x28 && ((1LL << ((unsigned __int8)v84 - 108)) & 0x10040000001LL) != 0
    || (v117 = *((const char **)v82 + 3)) != nullptr && !strcmp(v117, "qcom,adreno-gpu-a642l")
    || (v85 = 1, v86 = 72, (unsigned int)(v84 - 621) <= 0x2A)
    && ((1LL << ((unsigned __int8)v84 - 109)) & 0x60000400003LL) != 0 )
  {
    v85 = 2;
    v125 = &a650_ifpc_pwrup_reglist;
    v86 = 104;
    LODWORD(v126) = 16;
  }
  v87 = (void **)&(&v123)[2 * v85];
  v88 = v84 - 103;
  v89 = v83 + 16;
  v90 = v85 + 1;
  *v87 = &a6xx_pwrup_reglist;
  v87[1] = &_ksymtab_kgsl_gpu_frame_count + 6;
  if ( (unsigned int)(v84 - 615) > 0x2D )
    goto LABEL_264;
  if ( ((1LL << v88) & 0x1B) == 0 )
  {
    if ( ((1LL << v88) & 0x200800000020LL) != 0 )
    {
LABEL_222:
      v91 = (void **)&(&v123)[2 * v90];
      *v91 = &a650_pwrup_reglist;
      v92 = 6;
      goto LABEL_223;
    }
LABEL_264:
    v118 = *((const char **)v82 + 3);
    if ( (!v118 || strcmp(v118, "qcom,adreno-gpu-a642l"))
      && ((unsigned int)(v84 - 621) > 0x2A || ((1LL << ((unsigned __int8)v84 - 109)) & 0x60000400003LL) == 0) )
    {
      goto LABEL_224;
    }
    goto LABEL_222;
  }
  v91 = (void **)&(&v123)[2 * v90];
  *v91 = &a615_pwrup_reglist;
  v92 = 1;
LABEL_223:
  v90 = v85 + 2;
  *((_DWORD *)v91 + 2) = v92;
  *((_DWORD *)v91 + 3) = 0;
LABEL_224:
  v93 = v124;
  v94 = v123;
  if ( (_DWORD)v124 )
  {
    v95 = v124;
    for ( i = 0; i < v95; ++i )
    {
      v97 = v89;
      *(_DWORD *)v89 = v94[i];
      v89 += 8;
      *(_DWORD *)(v97 + 4) = kgsl_regmap_read(a1 + 13200);
    }
    v93 = 2 * v95;
  }
  *(_WORD *)(v83 + 12) += v93;
  if ( v94 == (_DWORD *)&a6xx_ifpc_pwrup_reglist || v94 == (_DWORD *)&a650_ifpc_pwrup_reglist )
  {
    v98 = adreno_coresight_patch_pwrup_reglist(a1, v89);
    v89 += 4LL * (unsigned int)(2 * v98);
    v86 += 2 * v98;
    *(_WORD *)(v83 + 12) += 2 * v98;
  }
  v99 = v126;
  v100 = v125;
  if ( (_DWORD)v126 )
  {
    v101 = 0;
    do
    {
      v102 = v89;
      *(_DWORD *)v89 = v100[v101];
      v89 += 8;
      *(_DWORD *)(v102 + 4) = kgsl_regmap_read(a1 + 13200);
      ++v101;
    }
    while ( v101 < (unsigned int)v126 );
    v99 = 2 * v126;
  }
  *(_WORD *)(v83 + 12) += v99;
  if ( v100 == (_DWORD *)&a6xx_ifpc_pwrup_reglist || v100 == (_DWORD *)&a650_ifpc_pwrup_reglist )
  {
    v103 = adreno_coresight_patch_pwrup_reglist(a1, v89);
    v89 += 4LL * (unsigned int)(2 * v103);
    v86 += 2 * v103;
    *(_WORD *)(v83 + 12) += 2 * v103;
  }
  if ( v90 != 2 )
  {
    v104 = v128;
    v105 = v127;
    if ( (_DWORD)v128 )
    {
      v106 = 0;
      do
      {
        v107 = v89;
        *(_DWORD *)v89 = v105[v106];
        v89 += 8;
        *(_DWORD *)(v107 + 4) = kgsl_regmap_read(a1 + 13200);
        ++v106;
      }
      while ( v106 < (unsigned int)v128 );
      v104 = 2 * v128;
    }
    *(_WORD *)(v83 + 12) += v104;
    if ( v105 == (_DWORD *)&a6xx_ifpc_pwrup_reglist || v105 == (_DWORD *)&a650_ifpc_pwrup_reglist )
    {
      v108 = adreno_coresight_patch_pwrup_reglist(a1, v89);
      v89 += 4LL * (unsigned int)(2 * v108);
      v86 += 2 * v108;
      *(_WORD *)(v83 + 12) += 2 * v108;
    }
    if ( v90 != 3 )
    {
      v109 = v130;
      v110 = v129;
      if ( (_DWORD)v130 )
      {
        v111 = 0;
        do
        {
          v112 = v89;
          *(_DWORD *)v89 = v110[v111];
          v89 += 8;
          *(_DWORD *)(v112 + 4) = kgsl_regmap_read(a1 + 13200);
          ++v111;
        }
        while ( v111 < (unsigned int)v130 );
        v109 = 2 * v130;
      }
      *(_WORD *)(v83 + 12) += v109;
      if ( v110 == (_DWORD *)&a6xx_ifpc_pwrup_reglist || v110 == (_DWORD *)&a650_ifpc_pwrup_reglist )
      {
        v113 = adreno_coresight_patch_pwrup_reglist(a1, v89);
        v89 += 4LL * (unsigned int)(2 * v113);
        v86 += 2 * v113;
        *(_WORD *)(v83 + 12) += 2 * v113;
      }
    }
  }
  if ( **(_DWORD **)(a1 + 14264) == 630 )
    v114 = 16;
  else
    v114 = 17;
  *(_DWORD *)v89 = v114;
  *(_DWORD *)(v89 + 4) = kgsl_regmap_read(a1 + 13200);
  *(_WORD *)(v83 + 12) += 2;
  *(_QWORD *)(v89 + 8) = 0x100000500LL;
  v115 = *(_WORD *)(v83 + 12);
  *(_WORD *)(v83 + 14) = v86;
  *(_WORD *)(v83 + 12) = v115 + 2;
  v121[3550] = 1;
LABEL_258:
  kgsl_regmap_write(a1 + 13200, 0);
  of_device_is_compatible(*(_QWORD *)(*(_QWORD *)(a1 + 11168) + 760LL));
  result = kgsl_regmap_write(a1 + 13200, 0);
  _ReadStatusReg(SP_EL0);
  return result;
}
