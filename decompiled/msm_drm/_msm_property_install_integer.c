__int64 __fastcall msm_property_install_integer(
        __int64 result,
        const char *a2,
        unsigned int a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        unsigned int a7,
        char a8)
{
  __int64 v8; // x20
  char v9; // w21
  __int64 v10; // x22
  const char *v11; // x19
  __int64 v12; // x23
  __int64 v13; // x24
  __int64 range; // x0
  __int64 v15; // x8
  __int64 v16; // x1
  __int64 v17; // x19

  if ( !result )
    return result;
  ++*(_DWORD *)(result + 40);
  if ( !a2 )
  {
    a2 = "null";
    return _drm_err("invalid argument(s), %s\n", a2);
  }
  if ( *(_DWORD *)(result + 32) <= a7 )
    return _drm_err("invalid argument(s), %s\n", a2);
  v8 = *(_QWORD *)(result + 16);
  v9 = a8 & 1;
  v10 = a7;
  if ( !*(_QWORD *)(v8 + 8LL * a7) )
  {
    v11 = a2;
    v12 = result;
    v13 = a6;
    range = drm_property_create_range(*(_QWORD *)(result + 8), a3, a2);
    a6 = v13;
    v15 = range;
    result = v12;
    *(_QWORD *)(v8 + 8 * v10) = v15;
    if ( !v15 )
    {
      _drm_err("create %s property failed\n", v11);
      a6 = v13;
      result = v12;
    }
  }
  *(_QWORD *)(*(_QWORD *)(result + 24) + 16 * v10) = a6;
  *(_BYTE *)(*(_QWORD *)(result + 24) + 16 * v10 + 8) = v9;
  v16 = *(_QWORD *)(v8 + 8 * v10);
  if ( v16 )
  {
    v17 = result;
    result = drm_object_attach_property(*(_QWORD *)result, v16, a6);
    ++*(_DWORD *)(v17 + 44);
  }
  return result;
}
