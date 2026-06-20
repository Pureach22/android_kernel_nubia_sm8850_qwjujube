__int64 __fastcall sde_cp_crtc_install_enum_property(
        __int64 *a1,
        unsigned int a2,
        __int64 a3,
        __int64 a4,
        const char *a5)
{
  __int64 result; // x0
  __int64 v9; // x21
  __int64 v10; // x26
  __int64 v11; // x25
  __int64 v12; // x0
  __int64 v13; // x2
  __int64 *v14; // x1

  if ( a2 >= 0x34 )
    return _drm_err("invalid feature %d max %d\n", a2, 52);
  result = _kmalloc_cache_noprof(_drm_dev_dbg, 3520, 104);
  v9 = result;
  if ( result )
  {
    v10 = *(_QWORD *)(*a1 + 56);
    v11 = *(_QWORD *)(*(_QWORD *)(v10 + 5224) + 8LL * a2);
    if ( !v11 )
    {
      v12 = drm_property_create_enum();
      if ( !v12 )
      {
        _drm_err("property create failed: %s\n", a5);
        return kfree(v9);
      }
      v11 = v12;
      *(_QWORD *)(*(_QWORD *)(v10 + 5224) + 8LL * a2) = v12;
    }
    drm_object_attach_property(a1 + 14, v11, 0);
    result = v9 + 40;
    *(_QWORD *)(v9 + 56) = v9 + 56;
    *(_QWORD *)(v9 + 64) = v9 + 56;
    *(_QWORD *)(v9 + 72) = v9 + 72;
    *(_QWORD *)(v9 + 80) = v9 + 72;
    v13 = a1[565];
    *(_DWORD *)v9 = *(_DWORD *)(v11 + 16);
    *(_DWORD *)(v9 + 4) = *(_DWORD *)(v11 + 48);
    *(_DWORD *)(v9 + 8) = a2;
    *(_BYTE *)(v9 + 88) = a2 < 0x32;
    v14 = a1 + 565;
    if ( *(__int64 **)(v13 + 8) != a1 + 565 || (__int64 *)result == v14 || v13 == result )
    {
      return _list_add_valid_or_report(result, v14);
    }
    else
    {
      *(_QWORD *)(v13 + 8) = result;
      *(_QWORD *)(v9 + 40) = v13;
      *(_QWORD *)(v9 + 48) = v14;
      *v14 = result;
    }
  }
  return result;
}
