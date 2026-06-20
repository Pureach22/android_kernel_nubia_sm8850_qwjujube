__int64 __fastcall drm_dp_atomic_find_time_slots(__int64 a1, __int64 a2, __int64 a3, int a4)
{
  unsigned __int64 private_obj_state; // x0
  unsigned int v9; // w20
  int v10; // w8
  __int64 v11; // x8
  __int64 *v12; // x22
  __int64 *v13; // x8
  __int64 v14; // x23
  int v15; // w7
  int v16; // w25
  int v17; // w26
  __int64 v18; // x8
  __int64 v19; // x1
  __int64 v20; // x8
  __int64 v21; // x1
  __int64 v23; // x8
  __int64 v24; // x1
  __int64 v25; // x0
  __int64 v26; // x2
  __int64 v28; // x1
  const char *v29; // x1
  const char **v30; // x8
  const char *v31; // x2
  __int64 v32; // x8
  __int64 v33; // x0
  unsigned int v39; // w8

  private_obj_state = drm_atomic_get_private_obj_state();
  v9 = private_obj_state;
  if ( private_obj_state >= 0xFFFFFFFFFFFFF001LL )
    return v9;
  v10 = *(_DWORD *)(*(_QWORD *)(a3 + 1624) + 152LL);
  if ( v10 >= *(_DWORD *)(a1 + 40) )
    v11 = 0;
  else
    v11 = *(_QWORD *)(*(_QWORD *)(a1 + 48) + 40LL * v10 + 24);
  v12 = (__int64 *)(private_obj_state + 56);
  *(_DWORD *)(private_obj_state + 24) |= 1 << *(_DWORD *)(*(_QWORD *)(v11 + 8) + 160LL);
  v13 = (__int64 *)(private_obj_state + 56);
  do
  {
    v13 = (__int64 *)*v13;
    if ( v13 == v12 )
    {
      v14 = 0;
      goto LABEL_12;
    }
  }
  while ( *(v13 - 4) != a3 );
  v14 = (__int64)(v13 - 4);
  if ( v13 == (__int64 *)&unk_20 )
  {
LABEL_12:
    v15 = 0;
    v16 = 0;
    v17 = 1;
LABEL_13:
    v9 = (unsigned int)(*(_DWORD *)(private_obj_state + 76) + (a4 << 12) - 1) / *(_DWORD *)(private_obj_state + 76);
    v18 = *(_QWORD *)(a2 + 104);
    if ( v18 )
      v19 = *(_QWORD *)(v18 + 8);
    else
      v19 = 0;
    _drm_dev_dbg(
      0,
      v19,
      4,
      "[CONNECTOR:%d:%s] [MST PORT:%p] TU %d -> %d\n",
      *(_DWORD *)(*(_QWORD *)(a3 + 1624) + 64LL),
      *(const char **)(*(_QWORD *)(a3 + 1624) + 96LL),
      (const void *)a3,
      v15,
      v9);
    v20 = *(_QWORD *)(a2 + 104);
    if ( v20 )
      v21 = *(_QWORD *)(v20 + 8);
    else
      v21 = 0;
    _drm_dev_dbg(
      0,
      v21,
      4,
      "[CONNECTOR:%d:%s] [MST PORT:%p] PBN %d -> %d\n",
      *(_DWORD *)(*(_QWORD *)(a3 + 1624) + 64LL),
      *(const char **)(*(_QWORD *)(a3 + 1624) + 96LL),
      (const void *)a3,
      v16,
      a4);
    if ( !v17 )
    {
LABEL_30:
      *(_DWORD *)(v14 + 12) = v9;
      *(_DWORD *)(v14 + 16) = a4;
      return v9;
    }
    v14 = _kmalloc_cache_noprof(prepare_to_wait_event, 3520, 48);
    if ( !v14 )
      return (unsigned int)-12;
    _X0 = (unsigned int *)(a3 + 4);
    __asm { PRFM            #0x11, [X0] }
    do
      v39 = __ldxr(_X0);
    while ( __stxr(v39 + 1, _X0) );
    if ( v39 )
    {
      if ( (((v39 + 1) | v39) & 0x80000000) == 0 )
      {
LABEL_23:
        v23 = *(_QWORD *)(*(_QWORD *)(a3 + 1632) + 104LL);
        if ( v23 )
          v24 = *(_QWORD *)(v23 + 8);
        else
          v24 = 0;
        _drm_dev_dbg(0, v24, 1, "port %p (%d)\n", (const void *)a3, *(_DWORD *)(a3 + 4));
        *(_QWORD *)v14 = a3;
        v25 = v14 + 32;
        *(_BYTE *)(v14 + 8) = -1;
        *(_DWORD *)(v14 + 24) = 0;
        v26 = *v12;
        if ( *(__int64 **)(*v12 + 8) != v12 || (__int64 *)v25 == v12 || v26 == v25 )
        {
          _list_add_valid_or_report(v25);
        }
        else
        {
          *(_QWORD *)(v26 + 8) = v25;
          *(_QWORD *)(v14 + 32) = v26;
          *(_QWORD *)(v14 + 40) = v12;
          *v12 = v25;
        }
        goto LABEL_30;
      }
      v28 = 1;
    }
    else
    {
      v28 = 2;
    }
    refcount_warn_saturate(_X0, v28);
    goto LABEL_23;
  }
  if ( (*((_BYTE *)v13 - 12) & 1) == 0 )
  {
    v15 = *((_DWORD *)v13 - 5);
    v16 = *((_DWORD *)v13 - 4);
    v17 = 0;
    goto LABEL_13;
  }
  v29 = (const char *)dev_driver_string(*(_QWORD *)(*(_QWORD *)(a2 + 104) + 8LL));
  v30 = *(const char ***)(*(_QWORD *)(a2 + 104) + 8LL);
  v31 = v30[14];
  if ( !v31 )
    v31 = *v30;
  _warn_printk("%s %s: [drm] %s", v29, v31, "drm_WARN_ON(payload->delete)");
  __break(0x800u);
  v32 = *(_QWORD *)(a2 + 104);
  if ( v32 )
    v33 = *(_QWORD *)(v32 + 8);
  else
    v33 = 0;
  dev_err(
    v33,
    "[drm] *ERROR* cannot allocate and release time slots on [MST PORT:%p] in the same state\n",
    (const void *)a3);
  return (unsigned int)-22;
}
