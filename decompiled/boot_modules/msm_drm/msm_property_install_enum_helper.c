__int64 __fastcall msm_property_install_enum_helper(
        __int64 result,
        const char *a2,
        int a3,
        int a4,
        __int64 a5,
        unsigned int a6,
        unsigned int a7,
        unsigned int a8,
        char a9)
{
  __int64 v9; // x21
  __int64 v11; // x22
  __int64 v12; // x24
  __int64 v13; // x0
  const char *v14; // x20
  int v15; // w25
  __int64 v16; // x26
  unsigned int v17; // w27
  __int64 v18; // x0
  __int64 v19; // x8
  __int64 v20; // x1
  __int64 v21; // x19

  if ( result )
  {
    ++*(_DWORD *)(result + 40);
    if ( a2 && a5 && a6 && *(_DWORD *)(result + 32) > a8 )
    {
      v9 = *(_QWORD *)(result + 16);
      v11 = a8;
      if ( !*(_QWORD *)(v9 + 8LL * a8) )
      {
        v12 = result;
        v13 = *(_QWORD *)(result + 8);
        v14 = a2;
        v15 = a4;
        v16 = a5;
        v17 = a6;
        v18 = a4
            ? drm_property_create_bitmask(v13, a3 | 0x20u, a2, a5, a6, -1)
            : drm_property_create_enum(v13, a3 | 8u, a2, a5, a6);
        v19 = v18;
        *(_QWORD *)(v9 + 8 * v11) = v18;
        result = v12;
        a5 = v16;
        a4 = v15;
        a6 = v17;
        if ( !v19 )
        {
          _drm_err("create %s property failed\n", v14);
          a6 = v17;
          a4 = v15;
          a5 = v16;
          result = v12;
        }
      }
      *(_QWORD *)(*(_QWORD *)(result + 24) + 16 * v11) = 0;
      *(_BYTE *)(*(_QWORD *)(result + 24) + 16 * v11 + 8) = a9 & 1;
      if ( a7 < a6 && !a4 && a7 )
        *(_QWORD *)(*(_QWORD *)(result + 24) + 16 * v11) = *(int *)(a5 + 16LL * a7);
      v20 = *(_QWORD *)(v9 + 8 * v11);
      if ( v20 )
      {
        v21 = result;
        result = drm_object_attach_property(*(_QWORD *)result, v20, *(_QWORD *)(*(_QWORD *)(result + 24) + 16 * v11));
        ++*(_DWORD *)(v21 + 44);
      }
    }
    else
    {
      if ( !a2 )
        a2 = "null";
      return _drm_err("invalid argument(s), %s\n", a2);
    }
  }
  return result;
}
