__int64 __fastcall sde_rm_ext_blk_create_reserve_lm(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 i; // x21
  __int64 v9; // x24
  __int64 v10; // x0
  __int64 *v11; // x1
  int v12; // w8
  int v13; // w9
  __int64 v14; // x0
  __int64 v15; // x8
  int v16; // w9
  __int64 v17; // x8
  __int64 v18; // x2
  __int64 *v19; // x1
  unsigned int v20; // w20
  void *v21; // x0
  __int64 v22; // x9

  if ( !a1 || !a2 || !a3 || !a4 )
  {
    v21 = &unk_27D28A;
LABEL_30:
    printk(v21, "sde_rm_ext_blk_create_reserve_lm");
    return (unsigned int)-22;
  }
  if ( *(_DWORD *)(a2 + 32) >= 0xFu )
  {
    v21 = &unk_2352C0;
    goto LABEL_30;
  }
  mutex_lock(a1 + 280);
  v9 = a1 + 8;
  for ( i = *(_QWORD *)(a1 + 8); i != v9; i = *(_QWORD *)i )
  {
    if ( (*(_BYTE *)(i + 28) & 1) == 0 && *(_DWORD *)(i + 20) == *(_DWORD *)(a3 + 24) )
    {
      if ( i )
        goto LABEL_19;
      break;
    }
  }
  v10 = _kmalloc_cache_noprof(wake_up_process, 3520, 32);
  i = v10;
  if ( v10 )
  {
    v11 = *(__int64 **)(a1 + 16);
    v12 = *(_DWORD *)(a1 + 276) + 1;
    *(_DWORD *)(a1 + 276) = v12;
    v13 = *(_DWORD *)(a3 + 24);
    *(_DWORD *)(v10 + 16) = v12;
    *(_DWORD *)(v10 + 20) = v13;
    if ( v10 == v9 || v11 == (__int64 *)v10 || *v11 != v9 )
      goto LABEL_32;
    *(_QWORD *)(a1 + 16) = v10;
    *(_QWORD *)v10 = v9;
    *(_QWORD *)(v10 + 8) = v11;
    *v11 = v10;
    while ( 1 )
    {
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(0, 0, 0, "create rsvp %d for enc %d\n", *(_DWORD *)(i + 16), *(_DWORD *)(i + 20));
LABEL_19:
      v14 = _kmalloc_cache_noprof(_drm_debug, 3520, 48);
      if ( !v14 )
        break;
      v15 = *(unsigned int *)(a2 + 32);
      v16 = *(_DWORD *)(a2 + 36);
      *(_QWORD *)(v14 + 40) = a4;
      *(_QWORD *)(v14 + 16) = i;
      *(_DWORD *)(v14 + 32) = v15;
      *(_DWORD *)(v14 + 36) = v16;
      if ( (unsigned int)v15 < 0x10 )
      {
        v17 = a1 + 16 * v15;
        v18 = v17 + 24;
        v19 = *(__int64 **)(v17 + 32);
        if ( v14 == v17 + 24 || v19 == (__int64 *)v14 || *v19 != v18 )
        {
          _list_add_valid_or_report(v14, v19);
          v14 = v22;
        }
        else
        {
          *(_QWORD *)(v17 + 32) = v14;
          *(_QWORD *)v14 = v18;
          *(_QWORD *)(v14 + 8) = v19;
          *v19 = v14;
        }
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(
            0,
            0,
            0,
            "create blk %d %d for rsvp %d enc %d\n",
            *(_DWORD *)(v14 + 32),
            *(_DWORD *)(v14 + 36),
            *(_DWORD *)(i + 16),
            *(_DWORD *)(i + 20));
        v20 = 0;
        goto LABEL_35;
      }
      __break(0x5512u);
LABEL_32:
      _list_add_valid_or_report(i, v11);
    }
  }
  kfree(i);
  kfree(0);
  v20 = -12;
LABEL_35:
  mutex_unlock(a1 + 280);
  return v20;
}
