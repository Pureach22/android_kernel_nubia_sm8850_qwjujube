__int64 __fastcall msm_property_install_blob(__int64 result, const char *a2, int a3, unsigned int a4)
{
  __int64 v4; // x20
  __int64 v5; // x21
  const char *v6; // x19
  __int64 v7; // x22
  __int64 v8; // x8
  __int64 v9; // x1
  __int64 v10; // x19

  if ( !result )
    return result;
  ++*(_DWORD *)(result + 40);
  if ( !a2 )
  {
    a2 = "null";
    return _drm_err("invalid argument(s), %s\n", a2);
  }
  if ( *(_DWORD *)(result + 36) <= a4 )
    return _drm_err("invalid argument(s), %s\n", a2);
  v4 = *(_QWORD *)(result + 16);
  v5 = a4;
  if ( !*(_QWORD *)(v4 + 8LL * a4) )
  {
    v6 = a2;
    v7 = result;
    v8 = drm_property_create(*(_QWORD *)(result + 8), a3 | 0x10u, a2, 0);
    result = v7;
    *(_QWORD *)(v4 + 8 * v5) = v8;
    if ( !v8 )
    {
      _drm_err("create %s property failed\n", v6);
      result = v7;
    }
  }
  *(_QWORD *)(*(_QWORD *)(result + 24) + 16 * v5) = 0;
  *(_BYTE *)(*(_QWORD *)(result + 24) + 16 * v5 + 8) = 1;
  v9 = *(_QWORD *)(v4 + 8 * v5);
  if ( v9 )
  {
    v10 = result;
    result = drm_object_attach_property(*(_QWORD *)result, v9, -1);
    ++*(_DWORD *)(v10 + 44);
  }
  return result;
}
