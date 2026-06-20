__int64 __fastcall gmu_core_map_gmu(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int a5,
        __int16 a6)
{
  unsigned int v6; // w20
  int v9; // w8
  __int64 v10; // x25
  int v11; // w8
  __int64 v12; // x26
  unsigned __int8 v14; // w27
  int v15; // w22
  int v16; // w20
  __int64 v17; // x0
  int v18; // w8
  int v19; // w24
  int v20; // w27
  unsigned int v21; // w28
  int v22; // w20
  __int64 v23; // x0
  __int64 v24; // x10
  __int64 *v25; // x24
  __int64 v26; // x11
  __int64 v27; // x8
  unsigned int v28; // w10
  __int64 *v29; // x9
  __int64 v30; // x22
  int v31; // w23
  int v32; // w8
  int v33; // w24
  __int64 result; // x0
  __int64 v35; // x3
  unsigned int v36; // w19
  unsigned int v37; // w21
  __int64 v38; // x20
  unsigned int v39; // w8
  __int64 v40; // x10
  unsigned int v41; // w10
  unsigned int v42; // w19

  v6 = a3;
  if ( a4 != 4 || (v9 = **(_DWORD **)(a1 + 14264), v9 == 203264) || (unsigned int)(v9 - 703) > 0xFFFFFF98 )
  {
    v30 = *(_QWORD *)(a1 + 8224) + 24LL * a4;
    if ( HIBYTE(a6) <= 0xCu )
      v31 = 4096;
    else
      v31 = 1 << SHIBYTE(a6);
    if ( !a3 )
    {
      v32 = 1 << a6;
      if ( (unsigned __int8)a6 <= 0xCu )
        v32 = 4096;
      v6 = (v32 + *(_DWORD *)(v30 + 8) - 1) & -v32;
    }
    v33 = *(_DWORD *)(a2 + 40);
    result = gmu_core_map_memdesc(*(_QWORD *)(a1 + 1552), a2, v6, a5);
    if ( (_DWORD)result )
    {
      v35 = *(_QWORD *)(a2 + 40);
      v36 = result;
      dev_err(
        *(_QWORD *)(a1 + 1544) + 16LL,
        "Unable to map GMU kernel block: addr:0x%08x size:0x%llx :%d\n",
        v6,
        v35,
        result);
      return v36;
    }
    else
    {
      *(_DWORD *)(a2 + 184) = v6;
      *(_DWORD *)(v30 + 8) = v6 + ((v31 + v33 - 1) & -v31);
    }
    return result;
  }
  v10 = *(_QWORD *)(a1 + 8224);
  v11 = 1 << SHIBYTE(a6);
  v12 = *(_QWORD *)(a1 + 1544);
  v14 = a6;
  if ( HIBYTE(a6) <= 0xCu )
    v11 = 4096;
  v15 = (v11 + *(_DWORD *)(a2 + 40) - 1) & -v11;
  raw_spin_lock(v10 + 108);
  if ( v6 )
    goto LABEL_16;
  if ( v14 <= 0xCu )
    v16 = 4096;
  else
    v16 = 1 << v14;
  v17 = rb_first(v10 + 112);
  v18 = *(_DWORD *)(v10 + 96);
  v19 = v16 - 1;
  v20 = -v16;
  v6 = (v18 + v16 - 1) & -v16;
  if ( v17 )
  {
    do
    {
      v21 = *(_DWORD *)(v17 + 24);
      if ( v6 + v15 <= v21 )
        goto LABEL_15;
      v22 = *(_DWORD *)(v17 + 28);
      v17 = rb_next();
      v6 = (v21 + v19 + v22) & v20;
    }
    while ( v17 );
    v18 = *(_DWORD *)(v10 + 96);
  }
  if ( v6 + v15 > *(_DWORD *)(v10 + 100) + v18 )
  {
LABEL_44:
    raw_spin_unlock(v10 + 108);
    dev_err(v12 + 16, "Insufficient VA space size: %x\n", v15);
    return 4294967284LL;
  }
LABEL_15:
  if ( !v6 )
    goto LABEL_44;
LABEL_16:
  v23 = _kmalloc_cache_noprof(idr_find, 10496, 32);
  if ( !v23 )
  {
    v42 = -12;
    goto LABEL_49;
  }
  *(_DWORD *)(v23 + 24) = v6;
  *(_DWORD *)(v23 + 28) = v15;
  v25 = (__int64 *)(v10 + 112);
  v24 = *(_QWORD *)(v10 + 112);
  if ( v24 )
  {
    while ( 1 )
    {
      while ( 1 )
      {
        v27 = v24;
        v28 = *(_DWORD *)(v24 + 24);
        if ( v6 + v15 > v28 )
          break;
        v26 = 16;
        v24 = *(_QWORD *)(v27 + 16);
        if ( !v24 )
          goto LABEL_23;
      }
      if ( *(_DWORD *)(v27 + 28) + v28 > v6 )
        break;
      v26 = 8;
      v24 = *(_QWORD *)(v27 + 8);
      if ( !v24 )
      {
LABEL_23:
        v29 = (__int64 *)(v27 + v26);
        goto LABEL_34;
      }
    }
    kfree(v23);
    v42 = -17;
LABEL_49:
    raw_spin_unlock(v10 + 108);
    dev_err(v12 + 16, "Could not insert va: %x size %x\n", v6, v15);
    return v42;
  }
  v27 = 0;
  v29 = (__int64 *)(v10 + 112);
LABEL_34:
  *(_QWORD *)v23 = v27;
  *(_QWORD *)(v23 + 8) = 0;
  *(_QWORD *)(v23 + 16) = 0;
  *v29 = v23;
  rb_insert_color();
  raw_spin_unlock(v10 + 108);
  result = gmu_core_map_memdesc(*(_QWORD *)(a1 + 1552), a2, v6, a5);
  if ( !(_DWORD)result )
  {
    *(_DWORD *)(a2 + 184) = v6;
    return result;
  }
  v37 = result;
  dev_err(v12 + 16, "Unable to map GMU kernel block: addr:0x%08x size:0x%llx :%d\n", v6, *(_QWORD *)(a2 + 40), result);
  raw_spin_lock(v10 + 108);
  v38 = *v25;
  if ( !*v25 )
    goto LABEL_47;
  v39 = *(_DWORD *)(a2 + 184);
  while ( 1 )
  {
    v41 = *(_DWORD *)(v38 + 24);
    if ( v39 + v15 > v41 )
      break;
    v40 = 16;
LABEL_40:
    v38 = *(_QWORD *)(v38 + v40);
    if ( !v38 )
      goto LABEL_47;
  }
  if ( *(_DWORD *)(v38 + 28) + v41 <= v39 )
  {
    v40 = 8;
    goto LABEL_40;
  }
  rb_erase(v38, v10 + 112);
LABEL_47:
  raw_spin_unlock(v10 + 108);
  kfree(v38);
  return v37;
}
