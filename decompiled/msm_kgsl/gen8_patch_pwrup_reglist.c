__int64 __fastcall gen8_patch_pwrup_reglist(__int64 a1)
{
  __int64 v1; // x25
  int *v2; // x9
  __int64 v3; // x8
  unsigned int v4; // w13
  int v5; // w10
  __int64 v6; // x24
  unsigned int v7; // w8
  unsigned __int16 v8; // w11
  int v9; // w11
  void *v10; // x10
  _DWORD *v11; // x12
  _DWORD *v12; // x27
  unsigned int v13; // w8
  int v14; // w10
  int v15; // w9
  void *v16; // x11
  void **v17; // x26
  char v18; // w8
  _DWORD *v19; // x19
  char v20; // w20
  unsigned __int64 v21; // x21
  _DWORD *v22; // x23
  _DWORD *v23; // x28
  int v24; // w0
  int v25; // w8
  unsigned __int64 v26; // x21
  unsigned int v27; // t1
  int v28; // w9
  void *v29; // x10
  _BOOL4 v32; // w11
  _BOOL4 v35; // w10
  __int64 v36; // x28
  __int64 v37; // x20
  __int64 v38; // x8
  __int64 v39; // x19
  unsigned __int64 v40; // x26
  int v41; // w8
  _BOOL4 v42; // w9
  _BOOL4 v43; // w8
  unsigned __int64 v44; // x25
  char *v45; // x23
  __int64 v46; // x21
  unsigned __int64 v47; // x19
  _DWORD *v48; // x23
  __int64 v49; // x21
  unsigned int v50; // t1
  unsigned __int64 v51; // x19
  _DWORD *v52; // x23
  __int64 v53; // x21
  unsigned int v54; // t1
  __int64 result; // x0
  unsigned int v56; // [xsp+8h] [xbp-68h]
  __int64 v57; // [xsp+8h] [xbp-68h]
  _DWORD *v58; // [xsp+10h] [xbp-60h]
  unsigned int v59; // [xsp+18h] [xbp-58h]
  __int64 v60; // [xsp+20h] [xbp-50h]
  void *v61; // [xsp+38h] [xbp-38h] BYREF
  __int64 v62; // [xsp+40h] [xbp-30h]
  void *v63; // [xsp+48h] [xbp-28h] BYREF
  __int64 v64; // [xsp+50h] [xbp-20h]
  __int64 v65; // [xsp+58h] [xbp-18h]
  __int64 v66; // [xsp+60h] [xbp-10h]
  __int64 v67; // [xsp+68h] [xbp-8h]

  v1 = a1;
  v67 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(int **)(a1 + 14264);
  v3 = *(_QWORD *)(a1 + 20464);
  v4 = *(_DWORD *)(a1 + 24612);
  v65 = 0;
  v66 = 0;
  v5 = *v2;
  v6 = *(_QWORD *)(v3 + 8);
  v7 = __rbit32(v4);
  v63 = nullptr;
  v64 = 0;
  v61 = nullptr;
  v62 = 0;
  v59 = v4;
  if ( v5 > 526335 )
  {
    if ( v5 != 526592 )
    {
      v8 = 2048;
      goto LABEL_6;
    }
LABEL_8:
    v10 = &gen8_2_0_ifpc_pwrup_reglist;
    v9 = 72;
    goto LABEL_10;
  }
  if ( (unsigned int)(v5 - 524800) < 2 )
    goto LABEL_8;
  v8 = 768;
LABEL_6:
  if ( v5 == (v8 | 0x80000) )
  {
    v61 = &gen8_3_0_ifpc_pwrup_reglist;
    v9 = 55;
    goto LABEL_11;
  }
  v10 = &gen8_ifpc_pwrup_reglist;
  v9 = 59;
LABEL_10:
  v61 = v10;
LABEL_11:
  v60 = a1 + 24544;
  v11 = *(_DWORD **)(a1 + 24552);
  *(_BYTE *)(v6 + 12) = v9;
  v12 = (_DWORD *)(v6 + 16);
  v13 = __clz(v7);
  v14 = **(_DWORD **)(a1 + 14264);
  LODWORD(v62) = v9;
  v15 = 45;
  if ( v14 > 526335 )
  {
    v16 = &gen8_3_0_pwrup_reglist;
    if ( v14 == 526336 )
      goto LABEL_19;
    if ( v14 != 526592 )
    {
LABEL_18:
      v15 = 48;
      v16 = &gen8_pwrup_reglist;
      goto LABEL_19;
    }
LABEL_17:
    v15 = 48;
    v16 = &gen8_2_0_pwrup_reglist;
    goto LABEL_19;
  }
  if ( (unsigned int)(v14 - 524800) < 2 )
    goto LABEL_17;
  v16 = &gen8_3_0_pwrup_reglist;
  if ( v14 != 525056 )
    goto LABEL_18;
LABEL_19:
  v17 = &v61;
  v58 = v11;
  v56 = v13 << 16;
  v18 = 1;
  v63 = v16;
  LODWORD(v64) = v15;
  *(_BYTE *)(v6 + 13) = v15;
  do
  {
    v19 = *v17;
    v20 = v18;
    if ( *((_DWORD *)v17 + 2) )
    {
      v21 = 0;
      do
      {
        v22 = v12 + 2;
        *v12 = v19[v21];
        v12[1] = kgsl_regmap_read(v1 + 13200);
        ++v21;
        v12 += 2;
      }
      while ( v21 < *((unsigned int *)v17 + 2) );
      v12 = v22;
    }
    v23 = v58;
    if ( v19 == (_DWORD *)&gen8_3_0_ifpc_pwrup_reglist
      || v19 == (_DWORD *)&gen8_ifpc_pwrup_reglist
      || v19 == (_DWORD *)&gen8_2_0_ifpc_pwrup_reglist )
    {
      v24 = adreno_coresight_patch_pwrup_reglist(v1, v12);
      v12 += (unsigned int)(2 * v24);
      *(_BYTE *)(v6 + 12) += v24;
    }
    mutex_lock(v1 + 24560);
    v25 = *v58;
    if ( *v58 )
    {
      v26 = 0;
      do
      {
        if ( (v23[1] & 1) != 0 && *((_BYTE *)v23 + 12) == 1 )
        {
          v28 = v23[4];
          if ( v28 )
          {
            v29 = *v17;
            v32 = *v17 == &gen8_ifpc_pwrup_reglist
               || v29 == &gen8_3_0_ifpc_pwrup_reglist
               || v29 == &gen8_2_0_ifpc_pwrup_reglist;
            if ( v28 == 1 && v32 )
            {
              *v12 = v25;
              v12[1] = kgsl_regmap_read(v1 + 13200);
              v12 += 2;
              ++*(_BYTE *)(v6 + 12);
            }
            else
            {
              v35 = v29 == &gen8_pwrup_reglist || v29 == &gen8_3_0_pwrup_reglist || v29 == &gen8_2_0_pwrup_reglist;
              if ( v28 == 2 && v35 )
              {
                *v12 = v25;
                v12[1] = kgsl_regmap_read(v1 + 13200);
                v12 += 2;
                ++*(_BYTE *)(v6 + 13);
              }
            }
          }
        }
        v27 = v23[5];
        v23 += 5;
        v25 = v27;
        ++v26;
      }
      while ( v26 < v27 );
    }
    mutex_unlock(v1 + 24560);
    v17 = &v63;
    v18 = 0;
  }
  while ( (v20 & 1) != 0 );
  v36 = 1;
  v37 = v60;
  LODWORD(v38) = v56 & 0x70000;
  if ( v59 )
    v38 = (unsigned int)v38;
  else
    v38 = 458752;
  *(_WORD *)(v60 + 4) = 0;
  v57 = v38;
  while ( 2 )
  {
    v39 = v1;
    v40 = 0;
    v41 = **(_DWORD **)(v1 + 14264);
    v42 = (v41 & 0xFFFFFFFE) != 524800;
    v43 = v41 != 526592;
    if ( v43 && v42 )
      v44 = 216;
    else
      v44 = 248;
    if ( v43 && v42 )
      v45 = (char *)&gen8_0_0_pwrup_extlist;
    else
      v45 = (char *)&gen8_2_0_pwrup_extlist;
    v46 = (v36 << 12) | v57;
    do
    {
      if ( v44 < v40 + 4 )
LABEL_104:
        __break(1u);
      if ( (*(unsigned int *)&v45[v40 + 4] & (unsigned __int64)(1LL << v36)) != 0 )
      {
        if ( v36 == 3 )
        {
          if ( (*(_BYTE *)(*(_QWORD *)(v39 + 14264) + 33LL) & 0x40) == 0 )
            goto LABEL_72;
        }
        else if ( (v36 & 6) == 4 && (*(_BYTE *)(*(_QWORD *)(v39 + 14264) + 34LL) & 4) == 0 )
        {
          goto LABEL_72;
        }
        *v12 = (_DWORD)v36 << 12;
        if ( v44 <= v40 )
          goto LABEL_104;
        v12[1] = *(_DWORD *)&v45[v40];
        if ( v46 != *(_DWORD *)v37 )
        {
          kgsl_regmap_write(v39 + 13200, (unsigned int)v46);
          __dsb(0xFu);
          *(_DWORD *)v37 = v46;
        }
        v12[2] = kgsl_regmap_read(v39 + 13200);
        v12 += 3;
        v37 = v60;
        ++*(_WORD *)(v60 + 4);
      }
LABEL_72:
      v40 += 8LL;
    }
    while ( v44 != v40 );
    ++v36;
    v1 = v39;
    if ( v36 != 8 )
      continue;
    break;
  }
  mutex_lock(v39 + 24560);
  if ( *v58 )
  {
    v47 = 0;
    v48 = v58 + 5;
    v49 = v57 | 0x1000;
    do
    {
      if ( (*(v48 - 4) & 2) != 0 && *((_BYTE *)v48 - 8) == 1 && *(v48 - 1) )
      {
        *v12 = 4096;
        v12[1] = *(v48 - 5);
        if ( v49 != *(_DWORD *)v37 )
        {
          kgsl_regmap_write(v1 + 13200, (unsigned int)v49);
          __dsb(0xFu);
          *(_DWORD *)v37 = v49;
        }
        v12[2] = kgsl_regmap_read(v1 + 13200);
        v12 += 3;
        v37 = v60;
        ++*(_WORD *)(v60 + 4);
      }
      v50 = *v48;
      v48 += 5;
      ++v47;
    }
    while ( v47 < v50 );
    if ( *v58 )
    {
      v51 = 0;
      v52 = v58 + 5;
      v53 = v57 | 0x2000;
      do
      {
        if ( (*(v52 - 4) & 4) != 0 && *((_BYTE *)v52 - 8) == 1 && *(v52 - 1) )
        {
          *v12 = 0x2000;
          v12[1] = *(v52 - 5);
          if ( v53 != *(_DWORD *)v37 )
          {
            kgsl_regmap_write(v1 + 13200, (unsigned int)v53);
            __dsb(0xFu);
            *(_DWORD *)v37 = v53;
          }
          v12[2] = kgsl_regmap_read(v1 + 13200);
          v12 += 3;
          v37 = v60;
          ++*(_WORD *)(v60 + 4);
        }
        v54 = *v52;
        v52 += 5;
        ++v51;
      }
      while ( v51 < v54 );
    }
  }
  result = mutex_unlock(v1 + 24560);
  if ( *(_DWORD *)v37 )
  {
    result = kgsl_regmap_write(v1 + 13200, 0);
    __dsb(0xFu);
    *(_DWORD *)v37 = 0;
  }
  *(_WORD *)(v6 + 14) = *(_WORD *)(v37 + 4);
  _ReadStatusReg(SP_EL0);
  return result;
}
