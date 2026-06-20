__int64 __fastcall msm_unregister_fence_error_event(__int64 a1, unsigned __int64 a2)
{
  __int64 v2; // x19
  _QWORD *v4; // x9
  unsigned __int64 v5; // x8
  __int64 v6; // x10
  unsigned __int64 v7; // x0

  if ( !a1 || (v2 = *(_QWORD *)(a1 + 56)) == 0 )
  {
    _drm_err("Invalid drm_device.\n");
    return 4294967274LL;
  }
  if ( !a2 || a2 >= 0xFFFFFFFFFFFFF001LL )
  {
    _drm_err("Invalid client_entry handle.\n");
    return 4294967274LL;
  }
  mutex_lock(v2 + 5768);
  v4 = *(_QWORD **)(a2 + 32);
  v5 = a2 + 24;
  if ( *v4 == a2 + 24 && (v6 = *(_QWORD *)v5, *(_QWORD *)(*(_QWORD *)v5 + 8LL) == v5) )
  {
    v7 = a2;
    *(_QWORD *)(v6 + 8) = v4;
    *v4 = v6;
  }
  else
  {
    _list_del_entry_valid_or_report(a2 + 24);
    v7 = a2;
  }
  *(_QWORD *)(v7 + 24) = 0xDEAD000000000100LL;
  *(_QWORD *)(v7 + 32) = 0xDEAD000000000122LL;
  kfree(v7);
  mutex_unlock(v2 + 5768);
  return 0;
}
