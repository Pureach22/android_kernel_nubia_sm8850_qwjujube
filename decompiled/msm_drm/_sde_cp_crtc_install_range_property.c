__int64 __fastcall sde_cp_crtc_install_range_property(
        __int64 *a1,
        const char *a2,
        unsigned int a3,
        __int64 a4,
        __int64 a5,
        __int64 a6)
{
  __int64 result; // x0
  __int64 v11; // x21
  __int64 v12; // x27
  __int64 v13; // x26
  __int64 range; // x0
  __int64 v15; // x2
  __int64 *v16; // x1

  if ( a3 >= 0x34 )
    return _drm_err("invalid feature %d max %d\n", a3, 52);
  result = _kmalloc_cache_noprof(_drm_dev_dbg, 3520, 104);
  v11 = result;
  if ( result )
  {
    v12 = *(_QWORD *)(*a1 + 56);
    v13 = *(_QWORD *)(*(_QWORD *)(v12 + 5224) + 8LL * a3);
    if ( !v13 )
    {
      range = drm_property_create_range();
      if ( !range )
      {
        _drm_err("property create failed: %s\n", a2);
        return kfree(v11);
      }
      v13 = range;
      *(_QWORD *)(*(_QWORD *)(v12 + 5224) + 8LL * a3) = range;
    }
    drm_object_attach_property(a1 + 14, v13, a6);
    result = v11 + 40;
    *(_QWORD *)(v11 + 56) = v11 + 56;
    *(_QWORD *)(v11 + 64) = v11 + 56;
    *(_QWORD *)(v11 + 72) = v11 + 72;
    *(_QWORD *)(v11 + 80) = v11 + 72;
    v15 = a1[565];
    *(_DWORD *)v11 = *(_DWORD *)(v13 + 16);
    *(_DWORD *)(v11 + 4) = *(_DWORD *)(v13 + 48);
    *(_DWORD *)(v11 + 8) = a3;
    *(_BYTE *)(v11 + 88) = a3 < 0x32;
    v16 = a1 + 565;
    if ( *(__int64 **)(v15 + 8) != a1 + 565 || (__int64 *)result == v16 || v15 == result )
    {
      return _list_add_valid_or_report(result, v16);
    }
    else
    {
      *(_QWORD *)(v15 + 8) = result;
      *(_QWORD *)(v11 + 40) = v15;
      *(_QWORD *)(v11 + 48) = v16;
      *v16 = result;
    }
  }
  return result;
}
