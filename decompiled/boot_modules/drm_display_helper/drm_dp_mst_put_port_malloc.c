__int64 __fastcall drm_dp_mst_put_port_malloc(__int64 a1)
{
  __int64 v2; // x8
  __int64 v3; // x1
  __int64 result; // x0
  __int64 v6; // x4
  __int64 v7; // x8
  __int64 v8; // x1
  __int64 v9; // x20
  int v15; // w8

  v2 = *(_QWORD *)(*(_QWORD *)(a1 + 1632) + 104LL);
  if ( v2 )
    v3 = *(_QWORD *)(v2 + 8);
  else
    v3 = 0;
  _X20 = (unsigned int *)(a1 + 4);
  result = _drm_dev_dbg(0, v3, 1, "port %p (%d)\n", (const void *)a1, *(_DWORD *)(a1 + 4) - 1);
  __asm { PRFM            #0x11, [X20] }
  do
    v15 = __ldxr(_X20);
  while ( __stlxr(v15 - 1, _X20) );
  if ( v15 == 1 )
  {
    __dmb(9u);
    v6 = *(_QWORD *)(a1 + 1616);
    v7 = *(_QWORD *)(*(_QWORD *)(v6 + 64) + 104LL);
    if ( v7 )
      v8 = *(_QWORD *)(v7 + 8);
    else
      v8 = 0;
    v9 = v6 + 4;
    _drm_dev_dbg(0, v8, 1, "mstb %p (%d)\n", (const void *)v6, *(_DWORD *)(v6 + 4) - 1);
    kref_put(v9, drm_dp_free_mst_branch_device);
    return kfree(a1);
  }
  else if ( v15 <= 0 )
  {
    return refcount_warn_saturate(a1 + 4, 3);
  }
  return result;
}
