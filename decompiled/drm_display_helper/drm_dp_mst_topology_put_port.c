__int64 __fastcall drm_dp_mst_topology_put_port(_QWORD *a1)
{
  __int64 v2; // x8
  __int64 v3; // x1
  __int64 result; // x0
  __int64 v5; // x20
  _QWORD *v6; // x2
  _QWORD *v7; // x1
  _QWORD *v8; // x0
  int v14; // w8

  _X19 = (__int64)a1;
  v2 = *(_QWORD *)(a1[204] + 104LL);
  if ( v2 )
    v3 = *(_QWORD *)(v2 + 8);
  else
    v3 = 0;
  result = _drm_dev_dbg(0, v3, 1, "port %p (%d)\n", a1, *(_DWORD *)a1 - 1);
  __asm { PRFM            #0x11, [X19] }
  do
    v14 = __ldxr((unsigned int *)_X19);
  while ( __stlxr(v14 - 1, (unsigned int *)_X19) );
  if ( v14 == 1 )
  {
    __dmb(9u);
    if ( *(_BYTE *)(_X19 + 9) == 1 )
    {
      return drm_dp_mst_put_port_malloc(_X19);
    }
    else
    {
      v5 = *(_QWORD *)(_X19 + 1632);
      drm_edid_free(*(_QWORD *)(_X19 + 1640));
      mutex_lock(v5 + 1120);
      v6 = *(_QWORD **)(v5 + 1088);
      v7 = (_QWORD *)(v5 + 1088);
      v8 = (_QWORD *)(_X19 + 24);
      if ( v6[1] != v5 + 1088 || v8 == v7 || v6 == v8 )
      {
        _list_add_valid_or_report(v8);
      }
      else
      {
        v6[1] = v8;
        *(_QWORD *)(_X19 + 24) = v6;
        *(_QWORD *)(_X19 + 32) = v7;
        *v7 = v8;
      }
      mutex_unlock(v5 + 1120);
      return queue_work_on(32, *(_QWORD *)(v5 + 1168), v5 + 1176);
    }
  }
  else if ( v14 <= 0 )
  {
    return refcount_warn_saturate(_X19, 3);
  }
  return result;
}
