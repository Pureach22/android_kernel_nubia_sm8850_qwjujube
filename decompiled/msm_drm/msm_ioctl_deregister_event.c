__int64 __fastcall msm_ioctl_deregister_event(__int64 a1, unsigned int *a2, __int64 a3)
{
  __int64 v4; // x22
  __int64 v7; // x0
  int v8; // w23
  __int64 v9; // x0
  __int64 *v10; // x8
  __int64 *v11; // x10
  __int64 v12; // x22
  int v13; // w12
  __int64 *v14; // x9
  __int64 **v15; // x10
  __int64 *v16; // x0
  __int64 v17; // x22
  __int64 v18; // x0
  __int64 *v19; // x8
  __int64 *v20; // x9
  int v21; // w22
  unsigned int v22; // w20
  __int64 v24; // x22
  __int64 v25; // x0
  __int64 v26; // x21
  __int64 v27; // x2
  _DWORD *v28; // x8
  __int64 *v29; // x10

  v4 = *(_QWORD *)(a1 + 56);
  v7 = drm_mode_object_find(a1, 0, *a2, a2[1]);
  if ( !v7 )
  {
    v22 = -2;
LABEL_23:
    _drm_err("unsupported event %x object %x object id %d\n", a2[2], a2[1], *a2);
    return v22;
  }
  v8 = *(_DWORD *)(v7 + 4);
  drm_mode_object_put(v7);
  if ( v8 != -1061109568 && v8 != -858993460 )
  {
    v22 = -95;
    goto LABEL_23;
  }
  v9 = raw_spin_lock_irqsave(a1 + 424);
  v10 = *(__int64 **)(v4 + 5664);
  v11 = (__int64 *)(v4 + 5664);
  v12 = v9;
  if ( v10 == v11 )
  {
LABEL_21:
    raw_spin_unlock_irqrestore(a1 + 424, v9);
    return (unsigned int)-2;
  }
  else
  {
    while ( 1 )
    {
      v13 = *((_DWORD *)v10 + 8);
      v14 = v10;
      v10 = (__int64 *)*v10;
      if ( v13 == a2[2] && *((_DWORD *)v14 + 10) == *a2 && *(v14 - 1) == a3 )
        break;
      if ( v10 == v11 )
        goto LABEL_21;
    }
    v15 = (__int64 **)v14[1];
    v16 = v14 - 5;
    if ( *v15 == v14 && (__int64 *)v10[1] == v14 )
    {
      v10[1] = (__int64)v15;
      *v15 = v10;
    }
    else
    {
      _list_del_entry_valid_or_report(v14);
      v16 = v29;
    }
    *v14 = 0xDEAD000000000100LL;
    v14[1] = 0xDEAD000000000122LL;
    kfree(v16);
    raw_spin_unlock_irqrestore(a1 + 424, v12);
    v17 = *(_QWORD *)(a1 + 56);
    v18 = raw_spin_lock_irqsave(a1 + 424);
    v19 = *(__int64 **)(v17 + 5664);
    v20 = (__int64 *)(v17 + 5664);
    if ( v19 == (__int64 *)(v17 + 5664) )
    {
      raw_spin_unlock_irqrestore(a1 + 424, v18);
    }
    else
    {
      v21 = 0;
      do
      {
        if ( *((_DWORD *)v19 + 8) == a2[2] && *((_DWORD *)v19 + 10) == *a2 )
          ++v21;
        v19 = (__int64 *)*v19;
      }
      while ( v19 != v20 );
      raw_spin_unlock_irqrestore(a1 + 424, v18);
      if ( v21 )
        return 0;
    }
    v24 = *(_QWORD *)(*(_QWORD *)(a1 + 56) + 8LL);
    v25 = drm_mode_object_find(a1, a3, *a2, a2[1]);
    if ( v25 )
    {
      v26 = v25;
      v27 = a2[2];
      v28 = *(_DWORD **)(*(_QWORD *)v24 + 176LL);
      if ( *(v28 - 1) != -1489659158 )
        __break(0x8228u);
      v22 = ((__int64 (__fastcall *)(__int64, __int64, __int64, _QWORD))v28)(v24, v25, v27, 0);
      drm_mode_object_put(v26);
    }
    else
    {
      return (unsigned int)-2;
    }
  }
  return v22;
}
