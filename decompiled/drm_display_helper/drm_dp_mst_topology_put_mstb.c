__int64 __fastcall drm_dp_mst_topology_put_mstb(_QWORD *a1)
{
  __int64 v2; // x8
  __int64 v3; // x1
  __int64 result; // x0
  _QWORD *v5; // x20
  __int64 v6; // x21
  _QWORD *v7; // x2
  _QWORD *v8; // x1
  int v14; // w8

  _X19 = a1;
  v2 = *(_QWORD *)(a1[8] + 104LL);
  if ( v2 )
    v3 = *(_QWORD *)(v2 + 8);
  else
    v3 = 0;
  result = _drm_dev_dbg(0, v3, 1, "mstb %p (%d)\n", a1, *(_DWORD *)a1 - 1);
  __asm { PRFM            #0x11, [X19] }
  do
    v14 = __ldxr((unsigned int *)_X19);
  while ( __stlxr(v14 - 1, (unsigned int *)_X19) );
  if ( v14 == 1 )
  {
    __dmb(9u);
    v5 = _X19 + 1;
    v6 = _X19[8];
    _X19[1] = _X19 + 1;
    _X19[2] = _X19 + 1;
    mutex_lock(v6 + 1120);
    v7 = *(_QWORD **)(v6 + 1104);
    v8 = (_QWORD *)(v6 + 1104);
    if ( v7[1] != v6 + 1104 || v5 == v8 || v7 == v5 )
    {
      _list_add_valid_or_report(_X19 + 1);
    }
    else
    {
      v7[1] = v5;
      _X19[1] = v7;
      _X19[2] = v8;
      *v8 = v5;
    }
    mutex_unlock(v6 + 1120);
    return queue_work_on(32, *(_QWORD *)(v6 + 1168), v6 + 1176);
  }
  else if ( v14 <= 0 )
  {
    return refcount_warn_saturate(_X19, 3);
  }
  return result;
}
