__int64 __fastcall sde_hw_dnsc_blur_init(int a1, __int64 a2, int *a3)
{
  __int64 result; // x0
  __int64 v7; // x0
  int v8; // w8
  __int64 v9; // x8
  unsigned __int64 v10; // x22
  unsigned int v11; // w2
  int v12; // w8
  int v13; // w9
  int v14; // w4
  __int64 v15; // x19
  __int64 v16; // x1
  int v17; // w9
  int v18; // w8
  int v19; // w9
  int v20; // w8
  __int64 v21; // x8
  unsigned __int64 StatusReg; // x22
  __int64 v23; // x23
  double (*v24)(_QWORD, _QWORD, _QWORD, const char *, ...); // x0

  result = -22;
  if ( !a2 || !a3 )
    return result;
  v7 = _kmalloc_cache_noprof(_drm_dev_dbg, 3520, 120);
  if ( !v7 )
    return -12;
  while ( 1 )
  {
    v8 = a3[3156];
    if ( !v8 )
      goto LABEL_18;
    if ( a3[3162] == a1 )
    {
      v9 = 3158;
LABEL_7:
      v10 = (unsigned __int64)&a3[v9];
      goto LABEL_8;
    }
    if ( v8 == 1 )
      goto LABEL_18;
    if ( a3[3178] == a1 )
    {
      v9 = 3174;
      goto LABEL_7;
    }
    if ( v8 == 2 )
      goto LABEL_18;
    if ( a3[3194] == a1 )
    {
      v9 = 3190;
      goto LABEL_7;
    }
    if ( v8 == 3 )
      goto LABEL_18;
    if ( a3[3210] == a1 )
    {
      v9 = 3206;
      goto LABEL_7;
    }
    if ( v8 == 4 )
      goto LABEL_18;
    if ( a3[3226] == a1 )
    {
      v9 = 3222;
      goto LABEL_7;
    }
    if ( v8 == 5 )
      goto LABEL_18;
    if ( a3[3242] == a1 )
    {
      v9 = 3238;
      goto LABEL_7;
    }
    if ( v8 == 6 )
      goto LABEL_18;
    if ( a3[3258] == a1 )
      break;
    if ( v8 == 7 )
      goto LABEL_18;
    if ( a3[3274] == a1 )
    {
      v21 = 3270;
      goto LABEL_36;
    }
    if ( v8 == 8 )
      goto LABEL_18;
    if ( a3[3290] == a1 )
    {
      v21 = 3286;
      goto LABEL_36;
    }
    if ( v8 == 9 )
      goto LABEL_18;
    if ( a3[3306] == a1 )
    {
      v21 = 3302;
      goto LABEL_36;
    }
    if ( v8 == 10 )
      goto LABEL_18;
    if ( a3[3322] == a1 )
    {
      v21 = 3318;
      goto LABEL_36;
    }
    if ( v8 == 11 )
      goto LABEL_18;
    if ( a3[3338] == a1 )
    {
      v21 = 3334;
      goto LABEL_36;
    }
    if ( v8 == 12 )
      goto LABEL_18;
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v23 = *(_QWORD *)(StatusReg + 80);
    v24 = _drm_dev_dbg;
    *(_QWORD *)(StatusReg + 80) = &sde_hw_dnsc_blur_init__alloc_tag;
    v7 = _kmalloc_cache_noprof(v24, 3520, 120);
    *(_QWORD *)(StatusReg + 80) = v23;
    if ( !v7 )
      return -12;
  }
  v21 = 3254;
LABEL_36:
  v10 = (unsigned __int64)&a3[v21];
LABEL_8:
  v11 = *(_DWORD *)(v10 + 20);
  v12 = *(_DWORD *)(v10 + 24);
  v13 = *a3;
  *(_QWORD *)v7 = a2;
  *(_DWORD *)(v7 + 8) = v11;
  *(_DWORD *)(v7 + 12) = v12;
  *(_DWORD *)(v7 + 20) = v13;
  *(_DWORD *)(v7 + 24) = 0x40000;
  if ( !v10 || v10 >= 0xFFFFFFFFFFFFF001LL )
  {
LABEL_18:
    kfree(v7);
    return -22;
  }
  v14 = *(_DWORD *)(v7 + 16);
  *(_QWORD *)(v7 + 48) = sde_hw_dnsc_blur_setup;
  *(_QWORD *)(v7 + 72) = &sde_hw_dnsc_blur_dither_setup;
  *(_DWORD *)(v7 + 40) = a1;
  v15 = v7;
  *(_QWORD *)(v7 + 32) = v10;
  *(_QWORD *)(v7 + 96) = sde_hw_dnsc_blur_bind_pingpong_blk;
  sde_dbg_reg_register_dump_range((__int64)"sde", (const char *)v10, v11, v12 + v11, v14);
  v16 = *(_QWORD *)(v10 + 48);
  v17 = *(_DWORD *)(v16 + 20);
  if ( v17 )
  {
    v18 = *(_DWORD *)(v16 + 24);
    if ( v18 )
    {
      sde_dbg_reg_register_dump_range(
        (__int64)"sde",
        (const char *)v16,
        *(_DWORD *)(v15 + 8) + v17,
        *(_DWORD *)(v15 + 8) + v17 + v18,
        *(_DWORD *)(v15 + 16));
      v16 = *(_QWORD *)(v10 + 48);
    }
  }
  v19 = *(_DWORD *)(v16 + 48);
  if ( v19 )
  {
    v20 = *(_DWORD *)(v16 + 52);
    result = v15;
    if ( !v20 )
      return result;
    sde_dbg_reg_register_dump_range(
      (__int64)"sde",
      (const char *)(v16 + 28),
      *(_DWORD *)(v15 + 8) + v19,
      *(_DWORD *)(v15 + 8) + v19 + v20,
      *(_DWORD *)(v15 + 16));
  }
  return v15;
}
