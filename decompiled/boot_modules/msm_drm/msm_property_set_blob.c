__int64 __fastcall msm_property_set_blob(__int64 a1, _QWORD *a2, __int64 a3, __int64 a4, unsigned int a5)
{
  bool v6; // zf
  char v7; // w21
  unsigned int *v8; // x19
  __int64 v9; // x2
  _QWORD *v10; // x8
  __int64 v12; // x23
  unsigned int *blob; // x0
  unsigned int v15; // w0
  unsigned int v16; // w20
  _QWORD *v17; // x8

  if ( !a1 || !a2 || *(_DWORD *)(a1 + 36) <= a5 )
  {
    _drm_err("invalid argument(s)\n");
    return 4294967274LL;
  }
  if ( a3 )
    v6 = a4 == 0;
  else
    v6 = 1;
  v7 = v6;
  if ( v6 )
  {
    v8 = nullptr;
    v9 = 0;
    v10 = (_QWORD *)(*(_QWORD *)(a1 + 16) + 8LL * a5);
  }
  else
  {
    v12 = a1;
    blob = (unsigned int *)drm_property_create_blob(*(_QWORD *)(a1 + 8), a4, a3);
    v8 = blob;
    if ( !blob || (unsigned __int64)blob >= 0xFFFFFFFFFFFFF001LL )
    {
      _drm_err("failed to create blob, %d\n", (_DWORD)blob);
      return (unsigned int)v8;
    }
    v9 = *blob;
    a1 = v12;
    v10 = (_QWORD *)(*(_QWORD *)(v12 + 16) + 8LL * a5);
  }
  v15 = drm_object_property_set_value(*(_QWORD *)a1, *v10, v9);
  if ( v15 )
  {
    v16 = v15;
    _drm_err("failed to set blob to property\n");
    if ( (v7 & 1) == 0 )
      drm_property_blob_put(v8);
    return v16;
  }
  else
  {
    v17 = a2;
    if ( *a2 )
    {
      drm_property_blob_put(*a2);
      v17 = a2;
    }
    *v17 = v8;
    return 0;
  }
}
