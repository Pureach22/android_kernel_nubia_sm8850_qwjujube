__int64 __fastcall zs_create_pool(__int64 a1)
{
  __int64 v2; // x19
  __int64 v3; // x0
  __int64 v4; // x0
  __int64 v5; // x0
  unsigned __int64 v6; // x8
  __int64 v7; // x0
  __int64 v8; // x21
  __int64 v9; // x26
  int v10; // w28
  unsigned int v11; // w10
  unsigned int v12; // w11
  bool v13; // cc
  int v14; // w17
  unsigned int v15; // w12
  bool v16; // cc
  unsigned int v17; // w11
  unsigned int v18; // w12
  int v19; // w14
  bool v20; // cc
  unsigned int v21; // w11
  bool v22; // cc
  bool v23; // cc
  int v24; // w11
  bool v25; // cc
  unsigned int v26; // w24
  __int64 v29; // x0
  __int64 v30; // [xsp+18h] [xbp-28h] BYREF
  __int64 v31; // [xsp+20h] [xbp-20h]
  __int64 v32; // [xsp+28h] [xbp-18h]
  __int64 v33; // [xsp+30h] [xbp-10h]
  __int64 v34; // [xsp+38h] [xbp-8h]

  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = _kmalloc_cache_noprof(_cpuhp_remove_state, 3520, 2136);
  if ( !v2 )
    goto LABEL_55;
  *(_QWORD *)(v2 + 2088) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(v2 + 2096) = v2 + 2096;
  *(_QWORD *)(v2 + 2104) = v2 + 2096;
  *(_QWORD *)(v2 + 2112) = async_free_zspage;
  *(_QWORD *)(v2 + 2120) = 0;
  *(_DWORD *)(v2 + 2128) = 0;
  v3 = kstrdup(a1, 3264);
  *(_QWORD *)v2 = v3;
  if ( !v3
    || (v32 = 0,
        v33 = 0,
        v30 = 0,
        v31 = 0,
        v4 = _kmem_cache_create_args("zs_handle", 8, &v30, 0),
        (*(_QWORD *)(v2 + 2048) = v4) == 0) )
  {
LABEL_54:
    zs_destroy_pool(v2);
    v2 = 0;
    goto LABEL_55;
  }
  v32 = 0;
  v33 = 0;
  v30 = 0;
  v31 = 0;
  v5 = _kmem_cache_create_args("zspage", 56, &v30, 0);
  *(_QWORD *)(v2 + 2056) = v5;
  if ( !v5 )
  {
    kmem_cache_destroy(*(_QWORD *)(v2 + 2048));
    *(_QWORD *)(v2 + 2048) = 0;
    goto LABEL_54;
  }
  v6 = 0;
  v7 = 0;
  v8 = 255;
  v9 = 4096;
  _ReadStatusReg(SP_EL0);
  do
  {
    if ( ((unsigned int)v9 & ((_DWORD)v9 - 1)) != 0 )
    {
      v11 = 0x1000u % (unsigned __int16)v9;
      v12 = 0x2000u % (unsigned __int16)v9;
      v13 = v11 > v12;
      if ( v11 >= v12 )
        v11 = 0x2000u % (unsigned __int16)v9;
      if ( v13 )
        v14 = 2;
      else
        v14 = 1;
      v15 = 0x3000u % (unsigned __int16)v9;
      v16 = v11 > v15;
      if ( v11 >= v15 )
        v11 = 0x3000u % (unsigned __int16)v9;
      v17 = 0x4000u % (unsigned __int16)v9;
      v18 = 0x5000u % (unsigned __int16)v9;
      if ( v16 )
        v19 = 3;
      else
        v19 = v14;
      v20 = v11 > v17;
      if ( v11 >= v17 )
        v11 = 0x4000u % (unsigned __int16)v9;
      v21 = 0x6000u % (unsigned __int16)v9;
      if ( v20 )
        v19 = 4;
      v22 = v11 > v18;
      if ( v11 >= v18 )
        v11 = 0x5000u % (unsigned __int16)v9;
      if ( v22 )
        v19 = 5;
      v23 = v11 > v21;
      if ( v11 >= v21 )
        v11 = 0x6000u % (unsigned __int16)v9;
      if ( v23 )
        v24 = 6;
      else
        v24 = v19;
      v25 = v11 > 0x7000u % (unsigned __int16)v9;
      if ( v11 >= 0x7000u % (unsigned __int16)v9 )
        v11 = 0x7000u % (unsigned __int16)v9;
      if ( v25 )
        v24 = 7;
      if ( v11 <= 0x8000u % (unsigned __int16)v9 )
        v10 = v24;
      else
        v10 = 8;
    }
    else
    {
      v10 = 1;
    }
    v26 = ((unsigned __int8)(v10 & 0xF) << 12) / (unsigned int)(unsigned __int16)v9;
    if ( v10 != 1 && v26 != 1 && huge_class_size == 0 )
      huge_class_size = v9 - 7;
    if ( !v7 )
      goto LABEL_51;
    if ( v6 < 0xD0 )
      __break(1u);
    if ( *(_DWORD *)(v7 + 208) == v10 && *(_DWORD *)(v7 + 204) == v26 )
    {
      *(_QWORD *)(v2 + 8 * v8) = v7;
    }
    else
    {
LABEL_51:
      v7 = _kmalloc_cache_noprof(kfree, 3520, 328);
      if ( !v7 )
        goto LABEL_54;
      *(_DWORD *)(v7 + 200) = v9;
      *(_DWORD *)(v7 + 204) = v26;
      *(_DWORD *)(v7 + 208) = v10;
      *(_DWORD *)(v7 + 212) = v8 - 1;
      *(_DWORD *)v7 = 0;
      *(_QWORD *)(v2 + 8 * v8) = v7;
      *(_QWORD *)(v7 + 8) = v7 + 8;
      *(_QWORD *)(v7 + 16) = v7 + 8;
      *(_QWORD *)(v7 + 24) = v7 + 24;
      *(_QWORD *)(v7 + 32) = v7 + 24;
      *(_QWORD *)(v7 + 40) = v7 + 40;
      *(_QWORD *)(v7 + 48) = v7 + 40;
      *(_QWORD *)(v7 + 56) = v7 + 56;
      *(_QWORD *)(v7 + 64) = v7 + 56;
      *(_QWORD *)(v7 + 72) = v7 + 72;
      *(_QWORD *)(v7 + 80) = v7 + 72;
      *(_QWORD *)(v7 + 88) = v7 + 88;
      *(_QWORD *)(v7 + 96) = v7 + 88;
      *(_QWORD *)(v7 + 104) = v7 + 104;
      *(_QWORD *)(v7 + 112) = v7 + 104;
      *(_QWORD *)(v7 + 120) = v7 + 120;
      *(_QWORD *)(v7 + 128) = v7 + 120;
      *(_QWORD *)(v7 + 136) = v7 + 136;
      *(_QWORD *)(v7 + 144) = v7 + 136;
      *(_QWORD *)(v7 + 152) = v7 + 152;
      *(_QWORD *)(v7 + 160) = v7 + 152;
      *(_QWORD *)(v7 + 168) = v7 + 168;
      *(_QWORD *)(v7 + 176) = v7 + 168;
      v6 = 328;
      *(_QWORD *)(v7 + 184) = v7 + 184;
      *(_QWORD *)(v7 + 192) = v7 + 184;
    }
    v9 -= 16;
    --v8;
  }
  while ( v9 != 16 );
  v29 = shrinker_alloc(0, "mm-zspool:%s", *(const char **)v2);
  *(_QWORD *)(v2 + 2080) = v29;
  if ( v29 )
  {
    *(_QWORD *)(v29 + 8) = zs_shrinker_scan;
    **(_QWORD **)(v2 + 2080) = zs_shrinker_count;
    *(_QWORD *)(*(_QWORD *)(v2 + 2080) + 16LL) = 0;
    *(_QWORD *)(*(_QWORD *)(v2 + 2080) + 88LL) = v2;
    shrinker_register(*(_QWORD *)(v2 + 2080));
  }
LABEL_55:
  _ReadStatusReg(SP_EL0);
  return v2;
}
