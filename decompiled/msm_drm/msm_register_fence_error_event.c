__int64 __fastcall msm_register_fence_error_event(__int64 a1, __int64 *a2, __int64 a3)
{
  __int64 v3; // x19
  __int64 v6; // x0
  _QWORD *v7; // x22
  __int64 v8; // x9
  _QWORD *v9; // x0
  _QWORD *v10; // x2
  _QWORD *v11; // x1

  if ( !a1 || (v3 = *(_QWORD *)(a1 + 56)) == 0 )
  {
    _drm_err("Invalid drm_device.\n");
    return -22;
  }
  if ( !a2 )
  {
    _drm_err("invalid msm_fence_error_ops.\n");
    return -22;
  }
  v6 = _kmalloc_cache_noprof(_drm_debug, 3520, 40);
  if ( v6 )
  {
    v7 = (_QWORD *)v6;
    mutex_lock(v3 + 5768);
    v8 = *a2;
    v7[2] = a3;
    v9 = v7 + 3;
    *v7 = v8;
    v10 = *(_QWORD **)(v3 + 5816);
    v11 = (_QWORD *)(v3 + 5816);
    if ( v10[1] != v3 + 5816 || v9 == v11 || v10 == v9 )
    {
      _list_add_valid_or_report(v9, v11);
    }
    else
    {
      v10[1] = v9;
      v7[3] = v10;
      v7[4] = v11;
      *v11 = v9;
    }
    mutex_unlock(v3 + 5768);
    return (__int64)v7;
  }
  else
  {
    _drm_err("invalid client_entry.\n");
    return -12;
  }
}
