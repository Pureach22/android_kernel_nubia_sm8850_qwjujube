__int64 __fastcall sde_cp_crtc_install_immutable_property(__int64 *a1, const char *a2, unsigned int a3)
{
  __int64 result; // x0
  __int64 v7; // x21
  __int64 v8; // x24
  __int64 v9; // x23
  __int64 range; // x0
  __int64 v11; // x2
  __int64 *v12; // x1

  if ( a3 >= 0x34 )
    return _drm_err("invalid feature %d max %d\n", a3, 52);
  result = _kmalloc_cache_noprof(_drm_dev_dbg, 3520, 104);
  v7 = result;
  if ( result )
  {
    v8 = *(_QWORD *)(*a1 + 56);
    v9 = *(_QWORD *)(*(_QWORD *)(v8 + 5224) + 8LL * a3);
    if ( !v9 )
    {
      range = drm_property_create_range();
      if ( !range )
      {
        _drm_err("property create failed: %s\n", a2);
        return kfree(v7);
      }
      v9 = range;
      *(_QWORD *)(*(_QWORD *)(v8 + 5224) + 8LL * a3) = range;
    }
    drm_object_attach_property(a1 + 14, v9, 0);
    result = v7 + 40;
    *(_QWORD *)(v7 + 56) = v7 + 56;
    *(_QWORD *)(v7 + 64) = v7 + 56;
    *(_QWORD *)(v7 + 72) = v7 + 72;
    *(_QWORD *)(v7 + 80) = v7 + 72;
    v11 = a1[565];
    *(_DWORD *)v7 = *(_DWORD *)(v9 + 16);
    *(_DWORD *)(v7 + 4) = *(_DWORD *)(v9 + 48);
    *(_DWORD *)(v7 + 8) = a3;
    *(_BYTE *)(v7 + 88) = a3 < 0x32;
    v12 = a1 + 565;
    if ( *(__int64 **)(v11 + 8) != a1 + 565 || (__int64 *)result == v12 || v11 == result )
    {
      return _list_add_valid_or_report(result, v12);
    }
    else
    {
      *(_QWORD *)(v11 + 8) = result;
      *(_QWORD *)(v7 + 40) = v11;
      *(_QWORD *)(v7 + 48) = v12;
      *v12 = result;
    }
  }
  return result;
}
