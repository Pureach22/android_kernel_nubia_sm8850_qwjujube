__int64 __fastcall gen8_start(__int64 a1)
{
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v2; // x11
  __int64 v3; // x28
  __int64 v5; // x9
  __int64 v6; // x10
  __int64 v7; // x26
  __int64 v8; // x21
  unsigned int v9; // w12
  unsigned int v10; // w8
  int v11; // w25
  unsigned int v12; // w23
  int v13; // w22
  int v14; // w8
  unsigned int v15; // w8
  int v16; // w24
  int v17; // w20
  int v18; // w10
  unsigned int v19; // w21
  int v20; // w21
  int v21; // w20
  __int64 v22; // x20
  _DWORD *v23; // x25
  unsigned int v24; // w26
  __int64 v25; // x23
  _DWORD *v26; // x8
  unsigned int v27; // w24
  _DWORD *v28; // x25
  __int64 v29; // x26
  unsigned int v30; // w20
  __int64 v31; // x22
  _DWORD *v32; // x8
  unsigned int v33; // w24
  _DWORD *v34; // x22
  int v35; // w21
  _DWORD *v36; // x8
  int v37; // w10
  int v38; // w20
  int v39; // w8
  __int64 v40; // x8
  _DWORD *v41; // x21
  int v42; // w20
  int v43; // w22
  int v44; // w22
  int v45; // w21
  unsigned __int64 v46; // x0
  char slice_id; // w22
  unsigned __int64 v48; // x0
  int v49; // w20
  unsigned int v50; // w22
  __int64 v51; // x1
  int v52; // w8
  int v54; // [xsp+Ch] [xbp-44h]
  int v55; // [xsp+10h] [xbp-40h]
  int v56; // [xsp+14h] [xbp-3Ch]
  unsigned int v57; // [xsp+14h] [xbp-3Ch]
  __int64 v58; // [xsp+18h] [xbp-38h]
  unsigned int v59; // [xsp+24h] [xbp-2Ch]
  unsigned __int64 v60; // [xsp+28h] [xbp-28h]
  _BYTE *v61; // [xsp+30h] [xbp-20h]
  _QWORD v62[2]; // [xsp+40h] [xbp-10h] BYREF

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = _ReadStatusReg(SP_EL0);
  v3 = a1 + 24544;
  v62[1] = *(_QWORD *)(StatusReg + 1808);
  v5 = *(_QWORD *)(a1 + 14264);
  v6 = *(_QWORD *)(a1 + 20464);
  v7 = a1 + 20437;
  v62[0] = 0;
  v58 = v5;
  v8 = *(_QWORD *)(v6 + 8);
  v9 = *(_DWORD *)(v2 + 148);
  v60 = v2;
  v56 = *(_DWORD *)(v2 + 152);
  v59 = v9;
  *(_DWORD *)(a1 + 24544) = -1;
  if ( v9 >= 0x64 )
    sched_set_fifo(v2);
  *(_BYTE *)(a1 + 13372) = 0;
  kgsl_regmap_write(a1 + 13200, 0xFFFFFFFFLL);
  kgsl_regmap_write(a1 + 13200, *(unsigned int *)(a1 + 14256));
  kgsl_regmap_write(a1 + 13200, *(unsigned int *)(a1 + 14260));
  kgsl_regmap_write(a1 + 13200, *(unsigned int *)(a1 + 14256));
  kgsl_regmap_write(a1 + 13200, *(unsigned int *)(a1 + 14260));
  if ( *(_BYTE *)(v7 + 3) == 1 )
  {
    if ( *(_DWORD *)v3 )
    {
      kgsl_regmap_write(a1 + 13200, 0);
      __dsb(0xFu);
      *(_DWORD *)v3 = 0;
    }
    kgsl_regmap_write(a1 + 13200, *(unsigned int *)(a1 + 14256));
    kgsl_regmap_write(a1 + 13200, *(unsigned int *)(a1 + 14260));
    kgsl_regmap_write(a1 + 13200, *(unsigned int *)(a1 + 14256));
    kgsl_regmap_write(a1 + 13200, *(unsigned int *)(a1 + 14260));
  }
  kgsl_regmap_write(a1 + 13200, 4294963200LL);
  kgsl_regmap_write(a1 + 13200, 0x1FFFF);
  kgsl_regmap_write(a1 + 13200, 4294963200LL);
  kgsl_regmap_write(a1 + 13200, 0x1FFFF);
  kgsl_regmap_write(a1 + 13200, 4294963200LL);
  kgsl_regmap_write(a1 + 13200, 0x1FFFF);
  kgsl_regmap_write(a1 + 13200, 4294963200LL);
  kgsl_regmap_write(a1 + 13200, 0x1FFFF);
  if ( *(unsigned __int16 *)(v8 + 14) > (unsigned int)*(unsigned __int16 *)(v3 + 4) )
  {
    kgsl_regmap_write(a1 + 13200, 1);
    kgsl_regmap_write(a1 + 13200, 1);
  }
  kgsl_regmap_write(a1 + 13200, 4);
  if ( *(_BYTE *)v7 == 1 )
    kgsl_regmap_rmw(a1 + 13200, 130113, 65280, 9728);
  if ( (of_property_read_variable_u32_array(
          *(_QWORD *)(*(_QWORD *)(a1 + 11168) + 760LL),
          "qcom,min-access-length",
          (char *)v62 + 4,
          1,
          0)
      & 0x80000000) != 0 )
    HIDWORD(v62[0]) = 32;
  of_property_read_variable_u32_array(*(_QWORD *)(*(_QWORD *)(a1 + 11168) + 760LL), "qcom,ubwc-mode", v62, 1, 0);
  v10 = LODWORD(v62[0]) - 3;
  if ( (unsigned int)(LODWORD(v62[0]) - 3) > 3 )
  {
    v11 = 0;
    v12 = 0;
    v54 = 0;
    v55 = 0;
    v13 = 0;
  }
  else
  {
    v11 = dword_17DEA4[v10];
    v12 = dword_17DEB4[v10];
    v54 = dword_17DEC4[v10];
    v55 = dword_17DF04[v10];
    v13 = dword_17DEF4[v10];
  }
  v14 = *(_DWORD *)(v7 + 215);
  if ( v14 )
  {
    v15 = v14 - 13;
    v16 = (v15 >> 2) & 1;
    v17 = v15 & 3;
  }
  else
  {
    v16 = 0;
    __break(0x800u);
    LOBYTE(v15) = 1;
    v17 = 1;
  }
  v18 = *(_DWORD *)v3;
  v19 = 32 * (v15 & 0xF);
  HIDWORD(v62[0]) = HIDWORD(v62[0]) == 64;
  if ( v18 != 0x2000 )
  {
    kgsl_regmap_write(a1 + 13200, 0x2000);
    __dsb(0xFu);
    *(_DWORD *)v3 = 0x2000;
  }
  v61 = (_BYTE *)v7;
  kgsl_regmap_write(a1 + 13200, v19);
  if ( *(_DWORD *)v3 != 4096 )
  {
    kgsl_regmap_write(a1 + 13200, 4096);
    __dsb(0xFu);
    *(_DWORD *)v3 = 4096;
  }
  kgsl_regmap_write(a1 + 13200, v19);
  v20 = 2 * v17;
  if ( *(_DWORD *)v3 != 4096 )
  {
    kgsl_regmap_write(a1 + 13200, 4096);
    __dsb(0xFu);
    *(_DWORD *)v3 = 4096;
  }
  kgsl_regmap_write(a1 + 13200, v12 | (8 * v16) | v20);
  v21 = BYTE4(v62[0]) & 1 | v54 | v55 | v13 | (16 * v11) | (8 * v11);
  if ( *(_DWORD *)v3 != 4096 )
  {
    kgsl_regmap_write(a1 + 13200, 4096);
    __dsb(0xFu);
    *(_DWORD *)v3 = 4096;
  }
  v57 = v56 - 120;
  kgsl_regmap_write(a1 + 13200, v21 | v12);
  if ( *(_DWORD *)v3 )
  {
    kgsl_regmap_write(a1 + 13200, 0);
    __dsb(0xFu);
    *(_DWORD *)v3 = 0;
  }
  kgsl_regmap_write(a1 + 13200, (v16 << 10) | (8 * (BYTE4(v62[0]) & 1)) | v20 | 0x20u);
  kgsl_regmap_write(a1 + 13200, (16 * v16) | (8 * (BYTE4(v62[0]) & 1)) | (unsigned int)v20);
  kgsl_regmap_multi_write(a1 + 13200, &gen8_0_0_bicubic_regs, 19);
  kgsl_regmap_write(a1 + 13200, *(_DWORD *)(v7 + 3551) & 0x7F | 0x80u);
  v22 = 0;
  v23 = *(_DWORD **)(*(_QWORD *)(a1 + 14264) + 168LL);
  do
  {
    if ( v22 == 3 )
    {
      if ( (*(_BYTE *)(*(_QWORD *)(a1 + 14264) + 33LL) & 0x40) == 0 )
        goto LABEL_29;
    }
    else if ( (v22 & 6) == 4 && (*(_BYTE *)(*(_QWORD *)(a1 + 14264) + 34LL) & 4) == 0 )
    {
      goto LABEL_29;
    }
    if ( *v23 )
    {
      v24 = 1;
      v25 = v22 << 12;
      v26 = v23;
      do
      {
        if ( ((unsigned int)v26[2] & (unsigned __int64)(1LL << v22)) != 0 )
        {
          v27 = v26[1];
          if ( v25 != *(_DWORD *)v3 )
          {
            kgsl_regmap_write(a1 + 13200, (unsigned int)v25);
            __dsb(0xFu);
            *(_DWORD *)v3 = v25;
          }
          kgsl_regmap_write(a1 + 13200, v27);
        }
        v26 = &v23[3 * v24++];
      }
      while ( *v26 );
    }
LABEL_29:
    ++v22;
  }
  while ( v22 != 8 );
  if ( *(_BYTE *)(v3 + 64) != 1 )
    goto LABEL_59;
  v28 = *(_DWORD **)(a1 + 24552);
  mutex_lock(a1 + 24560);
  v29 = 0;
  while ( 2 )
  {
    if ( v29 == 3 )
    {
      if ( (*(_BYTE *)(*(_QWORD *)(a1 + 14264) + 33LL) & 0x40) != 0 )
      {
LABEL_50:
        if ( *v28 )
        {
          v30 = 1;
          v31 = v29 << 12;
          v32 = v28;
          do
          {
            if ( *((_BYTE *)v32 + 12) == 1 && ((unsigned int)v32[1] & (unsigned __int64)(1LL << v29)) != 0 )
            {
              v33 = v32[2];
              if ( v31 != *(_DWORD *)v3 )
              {
                kgsl_regmap_write(a1 + 13200, (unsigned int)v31);
                __dsb(0xFu);
                *(_DWORD *)v3 = v31;
              }
              kgsl_regmap_write(a1 + 13200, v33);
            }
            v32 = &v28[5 * v30++];
          }
          while ( *v32 );
        }
      }
    }
    else if ( (v29 & 6) != 4 || (*(_BYTE *)(*(_QWORD *)(a1 + 14264) + 34LL) & 4) != 0 )
    {
      goto LABEL_50;
    }
    if ( ++v29 != 8 )
      continue;
    break;
  }
  mutex_unlock(a1 + 24560);
LABEL_59:
  if ( *(_DWORD *)v3 )
  {
    kgsl_regmap_write(a1 + 13200, 0);
    __dsb(0xFu);
    *(_DWORD *)v3 = 0;
  }
  kgsl_regmap_write(a1 + 13200, *(_DWORD *)(v58 + 156) & 0xFFFFFFF | 0x40000000u);
  kgsl_regmap_write(a1 + 13200, 0x40000000);
  if ( (*(_QWORD *)(a1 + 14240) & 0x200) != 0 )
  {
    if ( *(_DWORD *)v3 != 4096 )
    {
      kgsl_regmap_write(a1 + 13200, 4096);
      __dsb(0xFu);
      *(_DWORD *)v3 = 4096;
    }
    kgsl_regmap_write(a1 + 13200, 1);
    if ( *(_DWORD *)v3 )
    {
      kgsl_regmap_write(a1 + 13200, 0);
      __dsb(0xFu);
      *(_DWORD *)v3 = 0;
    }
  }
  kgsl_regmap_write(a1 + 13200, 4278190080LL);
  kgsl_regmap_rmw(a1 + 13200, 130112, 255, 32);
  kgsl_regmap_write(a1 + 13200, 1);
  v34 = *(_DWORD **)(*(_QWORD *)(a1 + 14264) + 160LL);
  if ( *(_DWORD *)v3 != 4096 )
  {
    kgsl_regmap_write(a1 + 13200, 4096);
    __dsb(0xFu);
    *(_DWORD *)v3 = 4096;
  }
  kgsl_regmap_write(a1 + 13200, 4294901771LL);
  if ( *(_DWORD *)v3 != 0x2000 )
  {
    kgsl_regmap_write(a1 + 13200, 0x2000);
    __dsb(0xFu);
    *(_DWORD *)v3 = 0x2000;
  }
  kgsl_regmap_write(a1 + 13200, 4294901771LL);
  if ( v61[3] == 1 )
  {
    if ( *(_DWORD *)v3 != 12288 )
    {
      kgsl_regmap_write(a1 + 13200, 12288);
      __dsb(0xFu);
      *(_DWORD *)v3 = 12288;
    }
    kgsl_regmap_write(a1 + 13200, 4294901771LL);
  }
  if ( *(_DWORD *)v3 )
  {
    kgsl_regmap_write(a1 + 13200, 0);
    __dsb(0xFu);
    *(_DWORD *)v3 = 0;
  }
  if ( *v34 )
  {
    v35 = -1;
    v36 = v34;
    do
    {
      v37 = v36[1];
      v38 = v36[2] - v37;
      kgsl_regmap_write(a1 + 13200, v37 & 0x3FFFF | ((unsigned __int16)(v38 & 0x1FFF) << 18) | (v36[3] << 31));
      v39 = v35 + 2;
      ++v35;
      v36 = &v34[4 * v39];
    }
    while ( *v36 );
    v40 = v35;
  }
  else
  {
    LOWORD(v38) = 0;
    v40 = -1;
  }
  v41 = &v34[4 * v40];
  v42 = (v38 & 0x1FFF) << 18;
  v43 = v41[1] & 0x3FFFF | (v41[3] << 31);
  if ( *(_DWORD *)v3 != 4096 )
  {
    kgsl_regmap_write(a1 + 13200, 4096);
    __dsb(0xFu);
    *(_DWORD *)v3 = 4096;
  }
  kgsl_regmap_write(a1 + 13200, v43 | (unsigned int)v42);
  v44 = v41[1] & 0x3FFFF | (v41[3] << 31);
  if ( *(_DWORD *)v3 != 0x2000 )
  {
    kgsl_regmap_write(a1 + 13200, 0x2000);
    __dsb(0xFu);
    *(_DWORD *)v3 = 0x2000;
  }
  kgsl_regmap_write(a1 + 13200, v44 | (unsigned int)v42);
  if ( v61[3] == 1 )
  {
    v45 = v41[1] & 0x3FFFF | (v41[3] << 31);
    if ( *(_DWORD *)v3 != 12288 )
    {
      kgsl_regmap_write(a1 + 13200, 12288);
      __dsb(0xFu);
      *(_DWORD *)v3 = 12288;
    }
    kgsl_regmap_write(a1 + 13200, v45 | (unsigned int)v42);
  }
  if ( *(_DWORD *)v3 )
  {
    kgsl_regmap_write(a1 + 13200, 0);
    __dsb(0xFu);
    *(_DWORD *)v3 = 0;
  }
  v46 = *(_QWORD *)(a1 + 20824);
  if ( v46 && v46 <= 0xFFFFFFFFFFFFF000LL && v61[395] == 1 && !(unsigned int)llcc_slice_activate() )
  {
    slice_id = llcc_get_slice_id(*(_QWORD *)(a1 + 20824));
    kgsl_regmap_write(
      a1 + 13200,
      slice_id & 0x3F
    | ((slice_id & 0x3F) << 18) & 0xC0FC003F
    | ((slice_id & 0x3F) << 24)
    | ((slice_id & 0x3F) << 12)
    | ((slice_id & 0x3F) << 6));
    kgsl_regmap_write(
      a1 + 13200,
      (((slice_id & 0x3F) << 16) | ((slice_id & 0x3F) << 10)) & 0xF03FFFFF | ((slice_id & 0x3F) << 22) | 0x100);
  }
  v48 = *(_QWORD *)(a1 + 20840);
  if ( v48 && v48 <= 0xFFFFFFFFFFFFF000LL && v61[411] == 1 )
    llcc_slice_activate();
  if ( *(_DWORD *)v3 != 4096 )
  {
    kgsl_regmap_write(a1 + 13200, 4096);
    __dsb(0xFu);
    *(_DWORD *)v3 = 4096;
  }
  kgsl_regmap_write(a1 + 13200, 111);
  if ( *(_DWORD *)v3 != 4096 )
  {
    kgsl_regmap_write(a1 + 13200, 4096);
    __dsb(0xFu);
    *(_DWORD *)v3 = 4096;
  }
  kgsl_regmap_write(a1 + 13200, 132661119);
  if ( *(_DWORD *)v3 != 4096 )
  {
    kgsl_regmap_write(a1 + 13200, 4096);
    __dsb(0xFu);
    *(_DWORD *)v3 = 4096;
  }
  kgsl_regmap_write(a1 + 13200, 1919);
  v49 = 2;
  v50 = 0x2000;
  while ( 2 )
  {
    if ( v49 == 3 )
    {
      if ( (*(_BYTE *)(*(_QWORD *)(a1 + 14264) + 33LL) & 0x40) != 0 )
        goto LABEL_114;
    }
    else if ( (v49 & 6) != 4 || (*(_BYTE *)(*(_QWORD *)(a1 + 14264) + 34LL) & 4) != 0 )
    {
LABEL_114:
      if ( v50 != *(_DWORD *)v3 )
      {
        kgsl_regmap_write(a1 + 13200, v50);
        __dsb(0xFu);
        *(_DWORD *)v3 = v50;
      }
      kgsl_regmap_write(a1 + 13200, 15);
      if ( v50 != *(_DWORD *)v3 )
      {
        kgsl_regmap_write(a1 + 13200, v50);
        __dsb(0xFu);
        *(_DWORD *)v3 = v50;
      }
      kgsl_regmap_write(a1 + 13200, 132661119);
      if ( v50 != *(_DWORD *)v3 )
      {
        kgsl_regmap_write(a1 + 13200, v50);
        __dsb(0xFu);
        *(_DWORD *)v3 = v50;
      }
      kgsl_regmap_write(a1 + 13200, 1919);
    }
    ++v49;
    v50 += 4096;
    if ( v49 != 8 )
      continue;
    break;
  }
  if ( *(_DWORD *)v3 )
  {
    kgsl_regmap_write(a1 + 13200, 0);
    __dsb(0xFu);
    *(_DWORD *)v3 = 0;
  }
  kgsl_regmap_write(a1 + 13200, 8323199);
  kgsl_regmap_write(a1 + 13200, 0);
  kgsl_regmap_write(a1 + 13200, 4026531840LL);
  kgsl_regmap_write(a1 + 13200, 0);
  if ( (*(_QWORD *)(a1 + 104) & 1LL) != 0 )
    v51 = 4294963200LL;
  else
    v51 = 0x10000000;
  kgsl_regmap_write(a1 + 13200, v51);
  v52 = **(_DWORD **)(a1 + 14264);
  if ( (unsigned int)(v52 - 524800) >= 2 && v52 != 526592 )
    gen8_hwcg_set(a1, 1);
  __dsb(0xFu);
  *(_BYTE *)(a1 + 13372) = 1;
  if ( v59 >= 0x64 )
    sched_set_normal(v60, v57);
  _ReadStatusReg(SP_EL0);
  return 0;
}
