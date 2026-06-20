__int64 __fastcall drm_dp_port_set_pdt(__int64 a1, unsigned __int8 a2, unsigned __int64 a3)
{
  int v3; // w20
  unsigned int v5; // w22
  int v6; // w8
  __int64 v7; // x21
  unsigned int v8; // w23
  __int64 result; // x0
  __int64 v10; // x8
  int v11; // w8
  unsigned __int64 v12; // x20
  char v13; // w8
  __int64 *v14; // x8
  size_t v15; // x0
  __int64 v16; // x20
  unsigned int v17; // w9
  size_t v18; // x2
  __int64 v19; // x8
  __int64 v21; // x8
  __int64 v22; // x1
  __int64 v23; // x1
  unsigned __int64 StatusReg; // x23
  __int64 v25; // x24
  __int64 (__fastcall *v26)(_QWORD, _QWORD, _QWORD); // x0
  __int64 v27; // x8
  __int64 v28; // x0
  unsigned int v34; // w8
  _QWORD v35[2]; // [xsp+0h] [xbp-10h] BYREF

  v3 = a2;
  v5 = a3 & 1;
  v35[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(unsigned __int8 *)(a1 + 12);
  v7 = *(_QWORD *)(a1 + 1632);
  if ( v6 == a2 && *(unsigned __int8 *)(a1 + 10) == v5 )
    goto LABEL_18;
  if ( *(_BYTE *)(a1 + 12) )
  {
    if ( v6 == 2 && (*(_BYTE *)(a1 + 10) & 1) != 0 )
    {
      v8 = a3;
      mutex_lock(v7 + 800);
      drm_dp_mst_topology_put_mstb(*(_QWORD **)(a1 + 40));
      *(_QWORD *)(a1 + 40) = 0;
      mutex_unlock(v7 + 800);
    }
    else
    {
      if ( a2 && ((a2 == 2) & (unsigned __int8)a3) == 0 )
      {
        result = 0;
        *(_BYTE *)(a1 + 12) = a2;
        *(_BYTE *)(a1 + 10) = v5;
        goto LABEL_42;
      }
      v8 = a3;
      i2c_del_adapter(a1 + 56);
    }
    a3 = v8;
  }
  *(_BYTE *)(a1 + 12) = v3;
  *(_BYTE *)(a1 + 10) = v5;
  if ( !v3 )
  {
LABEL_18:
    result = 0;
    goto LABEL_42;
  }
  if ( v3 != 2 || (a3 & 1) == 0 )
  {
    v14 = *(__int64 **)(*(_QWORD *)(*(_QWORD *)(a1 + 1632) + 104LL) + 8LL);
    *(_QWORD *)(a1 + 56) = &_this_module;
    v12 = a1 + 56;
    v7 = *(_QWORD *)(a1 + 48);
    *(_QWORD *)(a1 + 72) = &drm_dp_mst_i2c_algo;
    *(_QWORD *)(a1 + 80) = a1 + 48;
    *(_QWORD *)(a1 + 264) = v14;
    *(_DWORD *)(a1 + 164) = 3;
    *(_QWORD *)(a1 + 912) = v14[93];
    if ( !v7 )
    {
      v7 = v14[14];
      if ( !v7 )
        v7 = *v14;
    }
    v15 = strnlen((const char *)v7, 0x30u);
    if ( v15 != -1 )
    {
      if ( v15 == 48 )
        a3 = 48;
      else
        a3 = v15 + 1;
      if ( a3 < 0x31 )
      {
        sized_strscpy(a1 + 1092, v7);
        result = i2c_add_adapter(a1 + 56);
        if ( (result & 0x80000000) != 0 )
          *(_BYTE *)(a1 + 12) = 0;
        goto LABEL_42;
      }
      goto LABEL_46;
    }
    _fortify_panic(2, -1, 0);
LABEL_45:
    __break(1u);
LABEL_46:
    _fortify_panic(7, 48, a3);
    goto LABEL_47;
  }
  v10 = *(_QWORD *)(a1 + 1616);
  v35[0] = 0;
  v5 = *(unsigned __int8 *)(v10 + 32);
  v11 = (int)(v5 - 1 + (((v5 - 1) & 0x8000) >> 15)) >> 1;
  if ( v5 < 2 )
  {
    v12 = v11;
    v13 = 4;
    LOBYTE(v35[0]) = 0;
  }
  else
  {
    v12 = v11;
    if ( (unsigned int)v11 >= 8 )
    {
LABEL_47:
      _fortify_panic(17, 8, v12 + 1);
      goto LABEL_48;
    }
    memcpy(v35, (const void *)(*(_QWORD *)(a1 + 1616) + 24LL), v11 + 1LL);
    v13 = 4 * (v5 & 1);
  }
  if ( v12 > 7 )
    goto LABEL_45;
  *((_BYTE *)v35 + v12) |= *(unsigned __int8 *)(a1 + 8) << v13;
  v16 = _kmalloc_cache_noprof(_kmalloc_cache_noprof, 3520, 96);
  if ( v16 )
  {
    while ( 1 )
    {
      v17 = (unsigned __int8)(v5 + 1);
      *(_BYTE *)(v16 + 32) = v5 + 1;
      if ( v17 < 2 )
        break;
      v18 = (unsigned __int8)(v5 + 1) >> 1;
      if ( v17 >= 0x92 )
      {
LABEL_48:
        _fortify_panic(17, 72, v18);
      }
      else if ( (unsigned __int8)(v5 + 1) < 0x12u )
      {
        memcpy((void *)(v16 + 24), v35, v18);
        break;
      }
      _fortify_panic(16, 72, v18);
      StatusReg = _ReadStatusReg(SP_EL0);
      v25 = *(_QWORD *)(StatusReg + 80);
      v26 = _kmalloc_cache_noprof;
      *(_QWORD *)(StatusReg + 80) = &drm_dp_add_mst_branch_device__alloc_tag;
      v16 = _kmalloc_cache_noprof(v26, 3520, 96);
      *(_QWORD *)(StatusReg + 80) = v25;
      if ( !v16 )
        goto LABEL_50;
    }
    *(_QWORD *)(v16 + 40) = v16 + 40;
    *(_QWORD *)(v16 + 48) = v16 + 40;
    *(_DWORD *)v16 = 1;
    *(_DWORD *)(v16 + 4) = 1;
    mutex_lock(v7 + 800);
    v19 = *(_QWORD *)(a1 + 1632);
    _X0 = (unsigned int *)(a1 + 4);
    *(_QWORD *)(a1 + 40) = v16;
    *(_QWORD *)(v16 + 56) = a1;
    *(_QWORD *)(v16 + 64) = v19;
    __asm { PRFM            #0x11, [X0] }
    do
      v34 = __ldxr(_X0);
    while ( __stxr(v34 + 1, _X0) );
    if ( v34 )
    {
      if ( (((v34 + 1) | v34) & 0x80000000) == 0 )
      {
LABEL_38:
        v21 = *(_QWORD *)(*(_QWORD *)(a1 + 1632) + 104LL);
        if ( v21 )
          v22 = *(_QWORD *)(v21 + 8);
        else
          v22 = 0;
        _drm_dev_dbg(0, v22, 1, "port %p (%d)\n", (const void *)a1, *(_DWORD *)(a1 + 4));
        mutex_unlock(v7 + 800);
        result = 1;
        goto LABEL_42;
      }
      v23 = 1;
    }
    else
    {
      v23 = 2;
    }
    refcount_warn_saturate(_X0, v23);
    goto LABEL_38;
  }
LABEL_50:
  v27 = *(_QWORD *)(v7 + 104);
  if ( v27 )
    v28 = *(_QWORD *)(v27 + 8);
  else
    v28 = 0;
  dev_err(v28, "[drm] *ERROR* Failed to create MSTB for port %p", (const void *)a1);
  result = 4294967284LL;
  *(_BYTE *)(a1 + 12) = 0;
LABEL_42:
  _ReadStatusReg(SP_EL0);
  return result;
}
