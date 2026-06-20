__int64 __fastcall hw_fence_dbg_create_join_fence(__int64 a1, __int64 a2, __int64 a3)
{
  void *v3; // x30
  void *v4; // x26
  unsigned int *v5; // x21
  unsigned int *v7; // x20
  unsigned int *v8; // x19
  unsigned int *v9; // x8
  unsigned int *v10; // x27
  char *v11; // x28
  unsigned __int64 v12; // x24
  unsigned __int64 v13; // x8
  __int64 v14; // x20
  _QWORD *v15; // x23
  unsigned __int64 v16; // x22
  __int64 v17; // x0
  __int64 v18; // x0
  _DWORD *v19; // x8
  _QWORD *v20; // x0
  __int64 result; // x0
  __int64 v22; // x0
  __int64 v23; // x4
  __int64 v24; // x25
  __int64 v25; // x8
  __int64 v26; // x0
  __int64 v27; // x4
  __int64 v28; // x8
  __int64 v29; // x0
  __int64 v30; // x8
  __int64 v31; // x0
  __int64 v32; // x0
  __int64 v33; // x19
  unsigned __int64 StatusReg; // x19
  __int64 v36; // x22
  __int64 (__fastcall *v37)(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD); // x0
  int v43; // w8
  char *v44; // [xsp+20h] [xbp-50h]
  __int64 v45; // [xsp+28h] [xbp-48h]
  void *v46; // [xsp+30h] [xbp-40h]
  __int64 v47; // [xsp+38h] [xbp-38h] BYREF
  __int64 v48; // [xsp+40h] [xbp-30h] BYREF
  __int64 *v49; // [xsp+48h] [xbp-28h]
  __int64 v50; // [xsp+50h] [xbp-20h]
  __int64 v51; // [xsp+58h] [xbp-18h]
  _QWORD v52[2]; // [xsp+60h] [xbp-10h] BYREF

  v4 = v3;
  v52[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v51 = 0;
  v52[0] = 0;
  v49 = nullptr;
  v50 = 0;
  v48 = 0;
  v47 = 0;
  if ( !a1 || (v5 = *(unsigned int **)(a1 + 32)) == nullptr )
  {
    printk(&unk_2A0F5, "hw_fence_dbg_create_join_fence", 1206, v3, a1);
    result = -22;
    goto LABEL_49;
  }
  mutex_lock(v5 + 136);
  v7 = v5 + 132;
  v8 = v5 + 132;
  v9 = v5 + 132;
  while ( 1 )
  {
    v9 = *(unsigned int **)v9;
    if ( v9 == v7 )
      break;
    if ( *(v9 - 16) == 65 )
    {
      v10 = v9 - 16;
      goto LABEL_8;
    }
  }
  v10 = nullptr;
LABEL_8:
  mutex_unlock(v5 + 136);
  mutex_lock(v5 + 136);
  while ( 1 )
  {
    v8 = *(unsigned int **)v8;
    if ( v8 == v7 )
      break;
    if ( *(v8 - 16) == 66 )
    {
      v11 = (char *)(v8 - 16);
      goto LABEL_13;
    }
  }
  v11 = nullptr;
LABEL_13:
  mutex_unlock(v5 + 136);
  if ( !v10
    || !v11
    || (v12 = *((_QWORD *)v10 + 3)) == 0
    || v12 > 0xFFFFFFFFFFFFF000LL
    || (v13 = *((_QWORD *)v11 + 3)) == 0
    || v13 >= 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_2B1DF, "hw_fence_dbg_create_join_fence", 1217, v4, 65);
    result = -22;
    goto LABEL_49;
  }
  v14 = _kmalloc_cache_noprof(dma_fence_init, 3520, 24);
  if ( !v14 )
  {
LABEL_48:
    result = -12;
    goto LABEL_49;
  }
  while ( 1 )
  {
    v15 = (_QWORD *)_kmalloc_cache_noprof(dma_fence_init, 3520, 24);
    if ( !v15 )
    {
      v20 = (_QWORD *)v14;
LABEL_47:
      kfree(v20);
      goto LABEL_48;
    }
    v44 = v11;
    v45 = a3;
    v16 = 0;
    a3 = 1;
    v46 = v4;
    v4 = &hw_fence_dbg_ops;
    v11 = "_phandle_with_args";
    _ReadStatusReg(SP_EL0);
LABEL_22:
    v17 = _kmalloc_cache_noprof(_list_add_valid_or_report, 3520, 4);
    *(_QWORD *)(v14 + v16) = v17;
    if ( v17 )
    {
      v18 = _kmalloc_cache_noprof(_arch_copy_to_user, 3520, 200);
      if ( v18 )
        break;
    }
    if ( v16 <= 0x17 )
    {
      kfree(*(_QWORD *)(v14 + v16));
      kfree(v15[v16 / 8]);
      if ( !v16 )
        goto LABEL_32;
      if ( v16 - 8 <= 0x17 )
      {
        kfree(*(_QWORD *)(v14 + v16 - 8));
        kfree(v15[v16 / 8 - 1]);
        if ( v16 == 8 )
          goto LABEL_32;
        if ( v16 - 16 <= 0x17 )
        {
          kfree(*(_QWORD *)(v14 + v16 - 16));
          kfree(v15[v16 / 8 - 2]);
LABEL_32:
          kfree(v14);
          v20 = v15;
          goto LABEL_47;
        }
      }
    }
    __break(1u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v36 = *(_QWORD *)(StatusReg + 80);
    v37 = dma_fence_init;
    *(_QWORD *)(StatusReg + 80) = &hw_fence_dbg_create_join_fence__alloc_tag;
    v14 = _kmalloc_cache_noprof(v37, 3520, 24);
    *(_QWORD *)(StatusReg + 80) = v36;
    if ( !v14 )
      goto LABEL_48;
  }
  v19 = *(_DWORD **)(v14 + v16);
  v15[v16 / 8] = v18;
  *v19 = 0;
  dma_fence_init(v15[v16 / 8], &hw_fence_dbg_ops, *(_QWORD *)(v14 + v16), *((_QWORD *)v10 + 1), a3);
  v16 += 8LL;
  ++a3;
  if ( v16 != 24 )
    goto LABEL_22;
  v22 = dma_fence_array_create(3, v15, *((_QWORD *)v10 + 1), 4, 0);
  if ( v22 )
  {
    v24 = v22;
    v25 = *v15;
    v26 = *((_QWORD *)v10 + 3);
    v49 = &v47;
    v50 = v25;
    if ( (unsigned int)msm_hw_fence_create(v26, &v48) )
      goto LABEL_42;
    ((void (__fastcall *)(unsigned int *, unsigned __int64, _QWORD, __int64, __int64, _QWORD, _QWORD, _QWORD, _DWORD))hw_fence_update_queue)(
      v5,
      v12,
      *((_QWORD *)v10 + 1),
      1,
      v47,
      0,
      0,
      0,
      0);
    v28 = v15[1];
    v29 = *((_QWORD *)v10 + 3);
    v49 = &v47;
    v50 = v28;
    if ( (unsigned int)msm_hw_fence_create(v29, &v48)
      || (((void (__fastcall *)(unsigned int *, unsigned __int64, _QWORD, __int64, __int64, _QWORD, _QWORD, _QWORD, _DWORD))hw_fence_update_queue)(
            v5,
            v12,
            *((_QWORD *)v10 + 1),
            2,
            v47,
            0,
            0,
            0,
            0),
          v30 = v15[2],
          v31 = *((_QWORD *)v10 + 3),
          v49 = &v47,
          v50 = v30,
          (unsigned int)msm_hw_fence_create(v31, &v48)) )
    {
LABEL_42:
      printk(&unk_2391F, "hw_fence_dbg_create_join_fence", 1270, v46, v27);
      v33 = -22;
    }
    else
    {
      ((void (__fastcall *)(unsigned int *, unsigned __int64, _QWORD, __int64, __int64, _QWORD, _QWORD, _QWORD, _DWORD))hw_fence_update_queue)(
        v5,
        v12,
        *((_QWORD *)v10 + 1),
        3,
        v47,
        0,
        0,
        0,
        0);
      v32 = *((_QWORD *)v44 + 3);
      v52[0] = v24;
      msm_hw_fence_wait_update_v2(v32, v52, 0, 0, 1, 1);
      hw_fence_ipcc_trigger_signal(v5, v5[158], v5[157], 0);
      usleep_range_state(v5[129], v5[129] + 5, 2);
      v33 = v45;
    }
    _X0 = (unsigned int *)(v24 + 56);
    __asm { PRFM            #0x11, [X0] }
    do
      v43 = __ldxr(_X0);
    while ( __stlxr(v43 - 1, _X0) );
    if ( v43 == 1 )
    {
      __dmb(9u);
      dma_fence_release();
    }
    else if ( v43 <= 0 )
    {
      refcount_warn_saturate();
    }
    kfree(v14);
    result = v33;
  }
  else
  {
    printk(&unk_2770D, "hw_fence_dbg_create_join_fence", 1258, v46, v23);
    cleanup_fences(2, v15, v14);
    result = -22;
  }
LABEL_49:
  _ReadStatusReg(SP_EL0);
  return result;
}
