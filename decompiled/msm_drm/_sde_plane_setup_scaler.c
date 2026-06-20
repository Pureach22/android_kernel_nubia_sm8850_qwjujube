__int64 __fastcall sde_plane_setup_scaler(__int64 a1, __int64 a2, unsigned int *a3, char a4)
{
  __int64 v8; // x8
  unsigned int v9; // w23
  __int64 v10; // x0
  int v11; // w22
  char v12; // w8
  unsigned int v13; // w26
  unsigned int v14; // w25
  char v15; // w8
  int v16; // w27
  unsigned int v17; // w22
  __int64 v18; // x23
  unsigned int v19; // w24
  unsigned int v20; // w28
  int v21; // w19
  int v22; // w21
  char v23; // w10
  int v24; // w11
  unsigned int v25; // w8
  unsigned int v26; // w9
  unsigned int v27; // w12
  unsigned int v28; // w13
  unsigned int v29; // w14
  unsigned int v30; // w12
  __int64 v31; // x10
  __int64 v32; // x8
  __int64 v33; // x1
  __int64 v34; // x0
  int *v35; // x7
  unsigned int v36; // w8
  unsigned int v37; // w9
  int v38; // w9
  __int64 v39; // x10
  int v40; // w15
  int v41; // w11
  int v42; // w14
  int v43; // w12
  int v44; // w12
  int v45; // w14
  unsigned int v46; // w12
  unsigned int v47; // w13
  int v48; // w8
  __int64 v49; // x0
  __int64 v50; // x1
  __int64 blob; // x0
  __int64 v52; // x0
  __int64 v53; // x8
  __int64 v54; // x2
  __int64 v55; // x1
  __int64 v56; // x0
  int *v57; // x7
  __int64 v58; // x2
  unsigned int v59; // w8
  int v60; // w8
  __int64 v61; // x9
  int v62; // w8
  int v63; // w11
  __int64 v64; // x9
  int v65; // w13
  __int64 v66; // x10
  __int64 v67; // x8
  int v68; // w12
  int v69; // w9
  __int64 v70; // x8
  int v71; // w13
  __int64 v72; // x8
  int v73; // w10
  __int64 v74; // x8
  int v75; // w12
  __int64 v76; // x8
  int v77; // w9
  __int64 v78; // x8
  int v79; // w13
  __int64 v80; // x8
  int v81; // w10
  __int64 v82; // x8
  int v83; // w12
  __int64 v84; // x8
  int v85; // w9
  __int64 v86; // x8
  int v87; // w13
  __int64 v88; // x8
  int v89; // w10
  __int64 v90; // x9
  __int64 v91; // x9
  __int64 result; // x0
  __int64 (*v93)(void); // x8
  unsigned int *v94; // [xsp+48h] [xbp-18h]
  __int64 v95; // [xsp+50h] [xbp-10h]
  unsigned int v96; // [xsp+5Ch] [xbp-4h]

  if ( !a2 )
    return printk(&unk_26CF17, "_sde_plane_setup_scaler");
  memcpy((void *)(a1 + 2424), (const void *)(a2 + 1800), 0x238u);
  memcpy((void *)(a1 + 2992), (const void *)(a2 + 2368), 0x144u);
  if ( a1 && *(_QWORD *)a1 && (v8 = *(_QWORD *)(*(_QWORD *)a1 + 56LL)) != 0 )
    v9 = *(_DWORD *)(v8 + 5912);
  else
    v9 = 0;
  v10 = drm_format_info(*a3);
  v11 = *(unsigned __int8 *)(a2 + 848);
  *(_BYTE *)(a1 + 2320) = v11;
  v12 = *(_BYTE *)(a2 + 880);
  *(_BYTE *)(a1 + 2321) = v12;
  if ( v11 )
  {
    v13 = 1;
    if ( v12 )
    {
LABEL_9:
      v14 = 1;
      goto LABEL_12;
    }
  }
  else
  {
    v13 = *(unsigned __int8 *)(v10 + 18);
    if ( v12 )
      goto LABEL_9;
  }
  v14 = *(unsigned __int8 *)(v10 + 19);
LABEL_12:
  if ( (*(_DWORD *)(a1 + 1936) & 0x400008) == 0 )
  {
    if ( *(_DWORD *)(a2 + 2692) == 2 && (a4 & 1) == 0 )
    {
      LODWORD(v32) = *(unsigned __int8 *)(a1 + 4264);
      if ( (_DWORD)v32 != 1 )
        goto LABEL_131;
    }
    memset((void *)(a1 + 2992), 0, 0x144u);
    if ( (_drm_debug & 4) != 0 )
    {
      _drm_dev_dbg(0, 0, 0, "plane%d default config\n", *(_DWORD *)(a1 + 104));
      LOBYTE(v11) = *(_BYTE *)(a1 + 2320);
    }
    v33 = *(unsigned __int16 *)(a1 + 2300);
    v34 = *(unsigned __int16 *)(a1 + 2292);
    v35 = (int *)(a1 + 3284);
    v36 = (~(-1 << v11) + (int)v34) >> v11;
    v37 = 0x200000 % (unsigned int)v33 * v36 / (unsigned int)v33 + 0x200000 / (unsigned int)v33 * v36;
    *(_DWORD *)(a1 + 3012) = v37;
    *(_DWORD *)(a1 + 3024) = v37;
    *(_DWORD *)(a1 + 3016) = v37 / v13;
    *(_DWORD *)(a1 + 3020) = v37 / v13;
    if ( v36 != (_DWORD)v33 || (*((_QWORD *)a3 + 4) & 1) != 0 )
    {
      if ( v36 <= (unsigned int)v33 )
        v38 = 1;
      else
        v38 = 2;
      *(_DWORD *)(a1 + 3296) = v38;
      if ( (*((_QWORD *)a3 + 4) & 1) != 0 )
      {
        *v35 = 3;
        v39 = 3288;
      }
      else
      {
        *v35 = v38;
        v39 = 3288;
        v38 = 0;
      }
    }
    else
    {
      *(_QWORD *)(a1 + 3284) = 0x400000004LL;
      v38 = 4;
      v39 = 3296;
    }
    *(_DWORD *)(a1 + v39) = v38;
    if ( (*((_QWORD *)a3 + 4) & 1LL) != 0 )
      v54 = v36 & 0xFFFFFFFE;
    else
      v54 = v36;
    sde_plane_setup_pixel_ext(v34, v33, v54);
    v55 = *(unsigned __int16 *)(a1 + 2302);
    v56 = *(unsigned __int16 *)(a1 + 2294);
    v57 = (int *)(a1 + 3300);
    v58 = (unsigned int)((~(-1 << *(_BYTE *)(a1 + 2321)) + (int)v56) >> *(_BYTE *)(a1 + 2321));
    v59 = 0x200000 % (unsigned int)v55 * (unsigned int)v58 / (unsigned int)v55 + 0x200000 / (unsigned int)v55 * v58;
    *(_DWORD *)(a1 + 3044) = v59;
    *(_DWORD *)(a1 + 3056) = v59;
    *(_DWORD *)(a1 + 3048) = v59 / v14;
    *(_DWORD *)(a1 + 3052) = v59 / v14;
    if ( (_DWORD)v58 != (_DWORD)v55 || (*((_QWORD *)a3 + 4) & 1) != 0 )
    {
      if ( (unsigned int)v58 <= (unsigned int)v55 )
        v60 = 1;
      else
        v60 = 2;
      *(_DWORD *)(a1 + 3312) = v60;
      if ( (*((_QWORD *)a3 + 4) & 1) != 0 )
      {
        *v57 = 3;
        v61 = 3304;
      }
      else
      {
        *v57 = v60;
        v61 = 3304;
        v60 = 0;
      }
    }
    else
    {
      *(_QWORD *)(a1 + 3300) = 0x400000004LL;
      v60 = 4;
      v61 = 3312;
    }
    *(_DWORD *)(a1 + v61) = v60;
    sde_plane_setup_pixel_ext(v56, v55, v58);
    v62 = *(_DWORD *)(a1 + 3060);
    v63 = *(_DWORD *)(a1 + 3076);
    v64 = 3124;
    v65 = *(_DWORD *)(a1 + 3092);
    if ( v62 >= 0 )
      v64 = 3188;
    v66 = 3140;
    *(_DWORD *)(a1 + v64) = v62;
    v67 = 3220;
    if ( v63 >= 0 )
      v66 = 3204;
    v68 = *(_DWORD *)(a1 + 3108);
    if ( v65 < 0 )
      v67 = 3156;
    v69 = *(_DWORD *)(a1 + 3064);
    *(_DWORD *)(a1 + v66) = v63;
    *(_DWORD *)(a1 + v67) = v65;
    if ( v68 >= 0 )
      v70 = 3236;
    else
      v70 = 3172;
    v71 = *(_DWORD *)(a1 + 3080);
    *(_DWORD *)(a1 + v70) = v68;
    if ( v69 < 0 )
      v72 = 3128;
    else
      v72 = 3192;
    v73 = *(_DWORD *)(a1 + 3096);
    *(_DWORD *)(a1 + v72) = v69;
    if ( v71 < 0 )
      v74 = 3144;
    else
      v74 = 3208;
    v75 = *(_DWORD *)(a1 + 3112);
    *(_DWORD *)(a1 + v74) = v71;
    if ( v73 < 0 )
      v76 = 3160;
    else
      v76 = 3224;
    v77 = *(_DWORD *)(a1 + 3068);
    *(_DWORD *)(a1 + v76) = v73;
    if ( v75 < 0 )
      v78 = 3176;
    else
      v78 = 3240;
    v79 = *(_DWORD *)(a1 + 3084);
    *(_DWORD *)(a1 + v78) = v75;
    if ( v77 < 0 )
      v80 = 3132;
    else
      v80 = 3196;
    v81 = *(_DWORD *)(a1 + 3100);
    *(_DWORD *)(a1 + v80) = v77;
    if ( v79 < 0 )
      v82 = 3148;
    else
      v82 = 3212;
    v83 = *(_DWORD *)(a1 + 3116);
    *(_DWORD *)(a1 + v82) = v79;
    if ( v81 < 0 )
      v84 = 3164;
    else
      v84 = 3228;
    v85 = *(_DWORD *)(a1 + 3072);
    *(_DWORD *)(a1 + v84) = v81;
    if ( v83 < 0 )
      v86 = 3180;
    else
      v86 = 3244;
    v87 = *(_DWORD *)(a1 + 3088);
    *(_DWORD *)(a1 + v86) = v83;
    if ( v85 < 0 )
      v88 = 3136;
    else
      v88 = 3200;
    v89 = *(_DWORD *)(a1 + 3104);
    *(_DWORD *)(a1 + v88) = v85;
    if ( v87 < 0 )
      v90 = 3152;
    else
      v90 = 3216;
    LODWORD(v32) = *(_DWORD *)(a1 + 3120);
    *(_DWORD *)(a1 + v90) = v87;
    if ( v89 < 0 )
      v91 = 3168;
    else
      v91 = 3232;
    *(_DWORD *)(a1 + v91) = v89;
    if ( (v32 & 0x80000000) != 0 )
      goto LABEL_130;
    *(_DWORD *)(a1 + 3248) = v32;
    if ( v9 <= 2 )
      goto LABEL_132;
    goto LABEL_129;
  }
  if ( (a4 & 1) != 0 || (*(_BYTE *)(a1 + 4264) & 1) != 0 )
  {
    v15 = -22;
    goto LABEL_16;
  }
  v49 = a1 + 3344;
  v50 = a2 + 176;
  if ( *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 2208) + 32LL) + 16LL) == 22 )
  {
    blob = msm_property_get_blob(v49, v50, a1 + 2656);
    *(_QWORD *)(a1 + 2648) = blob;
    if ( !blob )
      goto LABEL_138;
LABEL_70:
    LODWORD(v32) = *(_DWORD *)(a2 + 2692);
    if ( (_DWORD)v32 == 4 )
      goto LABEL_131;
    v15 = 0;
    goto LABEL_16;
  }
  *(_QWORD *)(a1 + 2616) = msm_property_get_blob(v49, v50, a1 + 2624);
  *(_QWORD *)(a1 + 2632) = msm_property_get_blob(a1 + 3344, a2 + 176, a1 + 2640);
  v52 = msm_property_get_blob(a1 + 3344, a2 + 176, a1 + 2656);
  v53 = *(_QWORD *)(a1 + 2616);
  *(_QWORD *)(a1 + 2648) = v52;
  if ( !v53 )
  {
LABEL_138:
    v15 = -61;
    goto LABEL_16;
  }
  v15 = -61;
  if ( *(_QWORD *)(a1 + 2632) && v52 )
    goto LABEL_70;
LABEL_16:
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "_sde_plane_setup_scaler",
    1640,
    4,
    *(_DWORD *)(a1 + 104),
    a4 & 1,
    *(_DWORD *)(a2 + 2692),
    *(unsigned __int8 *)(a1 + 4264),
    v15);
  if ( !v13 || !v14 )
  {
    printk(&unk_22479C, "_sde_plane_setup_scaler3");
    if ( v9 <= 2 )
      goto LABEL_132;
    do
    {
LABEL_129:
      __break(0x5512u);
LABEL_130:
      *(_DWORD *)(a1 + 3184) = v32;
LABEL_131:
      ;
    }
    while ( v9 > 2 );
    goto LABEL_132;
  }
  v16 = *(_DWORD *)(a2 + 2740);
  v17 = *(unsigned __int16 *)(a1 + 2292);
  v96 = v9;
  v18 = *(_QWORD *)(a1 + 1936);
  v19 = *(unsigned __int16 *)(a1 + 2300);
  v20 = *(unsigned __int16 *)(a1 + 2302);
  v94 = a3;
  v95 = a2;
  if ( (v16 & 2) != 0 )
    v21 = *(unsigned __int16 *)(a1 + 2292);
  else
    v21 = *(unsigned __int16 *)(a1 + 2294);
  if ( (v16 & 2) != 0 )
    v22 = *(unsigned __int16 *)(a1 + 2294);
  else
    v22 = *(unsigned __int16 *)(a1 + 2292);
  memset((void *)(a1 + 2424), 0, 0x37Cu);
  v23 = *(_BYTE *)(a1 + 2321);
  v24 = ~(-1 << v23);
  v25 = (unsigned int)(v21 + v24) >> v23;
  v26 = (unsigned int)(v22 + ~(-1 << *(_BYTE *)(a1 + 2320))) >> *(_BYTE *)(a1 + 2320);
  v27 = v25 * (0x200000 % v20) / v20 + v25 * (0x200000 / v20);
  *(_DWORD *)(a1 + 2488) = v27;
  *(_DWORD *)(a1 + 2500) = v27;
  v28 = v26 * (0x200000 % v19) / v19 + v26 * (0x200000 / v19);
  *(_DWORD *)(a1 + 2456) = v28;
  *(_DWORD *)(a1 + 2468) = v28;
  *(_DWORD *)(a1 + 2492) = v27 / v14;
  *(_DWORD *)(a1 + 2496) = v27 / v14;
  *(_DWORD *)(a1 + 2460) = v28 / v13;
  *(_DWORD *)(a1 + 2464) = v28 / v13;
  if ( (v18 & 0x2000000) != 0 && (v16 & 2) != 0 )
  {
    *(_DWORD *)(a1 + 2536) = v26;
    v29 = v26;
    v30 = ((v17 >> (11 * ((unsigned __int16)v20 / 5u) + (unsigned __int8)(11 * ((unsigned __int16)v20 % 5u)) / 5u < v17))
         + v24) >> v23;
    v31 = *(_QWORD *)(a1 + 3320);
    *(_DWORD *)(a1 + 2552) = v30;
  }
  else
  {
    v31 = *(_QWORD *)(a1 + 3320);
    *(_DWORD *)(a1 + 2536) = v26;
    *(_DWORD *)(a1 + 2552) = v25;
    if ( (v16 & 2) != 0 )
      v29 = v26;
    else
      v29 = v25;
    if ( (v16 & 2) != 0 )
      v30 = v25;
    else
      v30 = v26;
  }
  *(_DWORD *)(a1 + 2504) = *(_DWORD *)(v31 + 116);
  v40 = *(_DWORD *)(v31 + 120);
  *(_DWORD *)(a1 + 3092) = v29;
  *(_DWORD *)(a1 + 3060) = v30;
  *(_DWORD *)(a1 + 2520) = v40;
  v9 = v96;
  v41 = v25 / v14;
  *(_DWORD *)(a1 + 2540) = v26 / v13;
  *(_DWORD *)(a1 + 2556) = v25 / v14;
  if ( (v16 & 2) != 0 )
    v42 = v25 / v14;
  else
    v42 = v26 / v13;
  *(_DWORD *)(a1 + 2508) = *(_DWORD *)(v31 + 116);
  v43 = *(_DWORD *)(v31 + 120);
  *(_DWORD *)(a1 + 3064) = v42;
  *(_DWORD *)(a1 + 2544) = v26 / v13;
  *(_DWORD *)(a1 + 2524) = v43;
  if ( (v16 & 2) != 0 )
    v44 = v26 / v13;
  else
    v44 = v25 / v14;
  *(_DWORD *)(a1 + 3096) = v44;
  *(_DWORD *)(a1 + 2560) = v41;
  *(_DWORD *)(a1 + 2512) = *(_DWORD *)(v31 + 116);
  *(_DWORD *)(a1 + 2528) = *(_DWORD *)(v31 + 120);
  if ( (v16 & 2) != 0 )
  {
    v45 = v26 / v13;
    v46 = v26;
    v47 = v25;
  }
  else
  {
    v45 = v25 / v14;
    v41 = v26 / v13;
    v46 = v25;
    v47 = v26;
  }
  *(_DWORD *)(a1 + 3100) = v45;
  *(_DWORD *)(a1 + 3068) = v41;
  *(_DWORD *)(a1 + 2548) = v26;
  *(_DWORD *)(a1 + 2564) = v25;
  *(_DWORD *)(a1 + 2516) = *(_DWORD *)(v31 + 116);
  v48 = *(_DWORD *)(v31 + 120);
  *(_DWORD *)(a1 + 3104) = v46;
  *(_DWORD *)(a1 + 3072) = v47;
  *(_DWORD *)(a1 + 2532) = v48;
  v32 = *((_QWORD *)v94 + 4);
  if ( (v32 & 1) == 0 && v21 == v20 && (v16 & 2) == 0 && v22 == v19 )
    goto LABEL_131;
  LODWORD(v32) = *(_DWORD *)(v95 + 1780);
  if ( (_DWORD)v32 )
    goto LABEL_131;
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "plane%d setting bilinear: src:%dx%d dst:%dx%d chroma:%dx%d fmt:%x\n",
      *(_DWORD *)(a1 + 104),
      v22,
      v21,
      v19,
      v20,
      v14,
      v13,
      *v94);
  *(_DWORD *)(a1 + 2568) = v19;
  *(_QWORD *)(a1 + 2576) = 0x300000003LL;
  *(_QWORD *)(a1 + 2584) = 0x100000001LL;
  LODWORD(v32) = 1;
  *(_DWORD *)(a1 + 2572) = v20;
  *(_DWORD *)(a1 + 2592) = 0;
  *(_DWORD *)(a1 + 2424) = 1;
  *(_DWORD *)(a1 + 2712) = 0;
  if ( v96 > 2 )
    goto LABEL_129;
LABEL_132:
  result = *(_QWORD *)(a1 + 2208);
  v93 = *(__int64 (**)(void))(result + 8LL * v9 + 688);
  if ( v93 )
  {
    if ( *((_DWORD *)v93 - 1) != 294386631 )
      __break(0x8228u);
    return v93();
  }
  return result;
}
