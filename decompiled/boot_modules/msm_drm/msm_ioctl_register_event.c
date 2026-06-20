__int64 __fastcall msm_ioctl_register_event(__int64 a1, unsigned int *a2, __int64 a3)
{
  __int64 v4; // x26
  __int64 v7; // x0
  int v8; // w21
  __int64 v9; // x0
  __int64 *v10; // x8
  __int64 *v11; // x21
  __int64 v12; // x23
  __int64 v13; // x24
  __int64 v14; // x8
  __int64 v15; // x10
  __int64 v16; // x8
  __int64 v17; // x0
  __int64 *v18; // x8
  __int64 *v19; // x9
  int v20; // w24
  int v21; // w4
  int v22; // w5
  __int64 v23; // x20
  unsigned int v24; // w22
  __int64 v26; // x24
  __int64 v27; // x0
  __int64 v28; // x25
  __int64 v29; // x2
  __int64 (__fastcall *v30)(__int64, __int64, __int64, __int64); // x8
  __int64 v31; // x0
  __int64 **v32; // x8
  __int64 **v33; // x1
  __int64 v34; // x9

  v4 = *(_QWORD *)(a1 + 56);
  v7 = drm_mode_object_find(a1, 0, *a2, a2[1]);
  if ( !v7 )
  {
    v24 = -2;
LABEL_20:
    _drm_err("unsupported event %x object %x object id %d\n", a2[2], a2[1], *a2);
    return v24;
  }
  v8 = *(_DWORD *)(v7 + 4);
  drm_mode_object_put(v7);
  if ( v8 != -1061109568 && v8 != -858993460 )
  {
    v24 = -95;
    goto LABEL_20;
  }
  v9 = raw_spin_lock_irqsave(a1 + 424);
  v10 = *(__int64 **)(v4 + 5664);
  v11 = (__int64 *)(v4 + 5664);
  if ( v10 == (__int64 *)(v4 + 5664) )
  {
LABEL_5:
    raw_spin_unlock_irqrestore(a1 + 424, v9);
    v12 = _kmalloc_cache_noprof(_drm_dev_dbg, 3520, 112);
    if ( !v12 )
      return (unsigned int)-12;
    v13 = *(_QWORD *)(a1 + 56);
    *(_DWORD *)(v12 + 72) = a2[2];
    v14 = *(_QWORD *)a2;
    v15 = *((_QWORD *)a2 + 1);
    *(_QWORD *)(v12 + 32) = a3;
    *(_QWORD *)(v12 + 16) = v12 + 72;
    *(_QWORD *)(v12 + 80) = v14;
    *(_QWORD *)(v12 + 88) = v15;
    v16 = *((_QWORD *)a2 + 3);
    *(_QWORD *)(v12 + 96) = *((_QWORD *)a2 + 2);
    *(_QWORD *)(v12 + 104) = v16;
    v17 = raw_spin_lock_irqsave(a1 + 424);
    v18 = *(__int64 **)(v13 + 5664);
    v19 = (__int64 *)(v13 + 5664);
    if ( v18 == (__int64 *)(v13 + 5664) )
    {
      raw_spin_unlock_irqrestore(a1 + 424, v17);
    }
    else
    {
      v20 = 0;
      do
      {
        if ( *((_DWORD *)v18 + 8) == a2[2] && *((_DWORD *)v18 + 10) == *a2 )
          ++v20;
        v18 = (__int64 *)*v18;
      }
      while ( v18 != v19 );
      raw_spin_unlock_irqrestore(a1 + 424, v17);
      if ( v20 )
        goto LABEL_29;
    }
    v26 = *(_QWORD *)(*(_QWORD *)(a1 + 56) + 8LL);
    v27 = drm_mode_object_find(a1, a3, *a2, a2[1]);
    if ( v27 )
    {
      v28 = v27;
      v29 = a2[2];
      v30 = *(__int64 (__fastcall **)(__int64, __int64, __int64, __int64))(*(_QWORD *)v26 + 176LL);
      if ( *((_DWORD *)v30 - 1) != -1489659158 )
        __break(0x8228u);
      v24 = v30(v26, v27, v29, 1);
      drm_mode_object_put(v28);
      if ( !v24 )
      {
LABEL_29:
        v31 = raw_spin_lock_irqsave(a1 + 424);
        v32 = (__int64 **)(v12 + 40);
        v33 = *(__int64 ***)(v4 + 5672);
        v34 = v31;
        if ( (__int64 *)(v12 + 40) == v11 || v33 == v32 || *v33 != v11 )
        {
          _list_add_valid_or_report(v12 + 40, v33);
        }
        else
        {
          *(_QWORD *)(v4 + 5672) = v32;
          *(_QWORD *)(v12 + 40) = v11;
          *(_QWORD *)(v12 + 48) = v33;
          *v33 = (__int64 *)v32;
        }
        raw_spin_unlock_irqrestore(a1 + 424, v34);
        return 0;
      }
    }
    else
    {
      v24 = -2;
    }
    _drm_err("failed to enable event %x object %x object id %d\n", a2[2], a2[1], *a2);
    kfree(v12);
    return v24;
  }
  while ( 1 )
  {
    if ( *(v10 - 1) == a3 )
    {
      v21 = *((_DWORD *)v10 + 8);
      if ( v21 == a2[2] )
      {
        v22 = *((_DWORD *)v10 + 10);
        if ( v22 == *a2 )
          break;
      }
    }
    v10 = (__int64 *)*v10;
    if ( v10 == v11 )
      goto LABEL_5;
  }
  v23 = v9;
  _drm_dev_dbg(0, 0, 0, "duplicate request for event %x obj id %d\n", v21, v22);
  raw_spin_unlock_irqrestore(a1 + 424, v23);
  return (unsigned int)-114;
}
