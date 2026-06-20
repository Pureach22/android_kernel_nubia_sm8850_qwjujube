__int64 __fastcall cam_vfe_top_ver3_reserve(__int64 a1, __int64 a2)
{
  unsigned int v2; // w8
  int v3; // w9
  __int64 v4; // x19
  unsigned int v5; // w8
  __int64 v7; // x23
  __int64 v8; // x20
  __int64 v9; // x23
  __int64 v10; // x20
  unsigned int v11; // w0
  char v12; // w9
  __int64 v13; // x11
  __int64 v14; // x23
  __int64 v15; // x20
  __int64 v16; // x19
  __int64 v17; // x20

  if ( !a1 || !a2 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_top_ver3_reserve",
      438,
      "Error, Invalid input arguments");
    return (unsigned int)-22;
  }
  LOBYTE(v2) = debug_mdl;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    goto LABEL_48;
  v3 = *(_DWORD *)(a1 + 1088);
  if ( !v3 )
    return (unsigned int)-22;
  while ( 1 )
  {
    v2 = *(_DWORD *)(a2 + 56);
    if ( *(_QWORD *)(a1 + 28) == (v2 | 0x100000000LL) )
    {
      v4 = a1 + 24;
      goto LABEL_35;
    }
    if ( v3 == 1 )
      return (unsigned int)-22;
    if ( *(_DWORD *)(a1 + 180) == v2 && *(_DWORD *)(a1 + 184) == 1 )
    {
      v4 = a1 + 176;
      goto LABEL_35;
    }
    if ( v3 == 2 )
      return (unsigned int)-22;
    if ( *(_DWORD *)(a1 + 332) == v2 && *(_DWORD *)(a1 + 336) == 1 )
    {
      v4 = a1 + 328;
      goto LABEL_35;
    }
    if ( v3 == 3 )
      return (unsigned int)-22;
    if ( *(_DWORD *)(a1 + 484) == v2 && *(_DWORD *)(a1 + 488) == 1 )
    {
      v4 = a1 + 480;
      goto LABEL_35;
    }
    if ( v3 == 4 )
      return (unsigned int)-22;
    if ( *(_DWORD *)(a1 + 636) == v2 && *(_DWORD *)(a1 + 640) == 1 )
    {
      v4 = a1 + 632;
      goto LABEL_35;
    }
    if ( v3 == 5 )
      return (unsigned int)-22;
    if ( *(_DWORD *)(a1 + 788) == v2 && *(_DWORD *)(a1 + 792) == 1 )
    {
      v4 = a1 + 784;
      goto LABEL_35;
    }
    if ( v3 == 6 )
      return (unsigned int)-22;
    if ( *(_DWORD *)(a1 + 940) == v2 && *(_DWORD *)(a1 + 944) == 1 )
      break;
    if ( v3 != 7 )
    {
      __break(0x5512u);
LABEL_48:
      v16 = a2;
      v17 = a1;
      ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v2 & 8,
        4,
        "cam_vfe_top_ver3_reserve",
        446,
        "res id %d",
        *(_DWORD *)(a2 + 56));
      a2 = v16;
      a1 = v17;
      v3 = *(_DWORD *)(v17 + 1088);
      if ( v3 )
        continue;
    }
    return (unsigned int)-22;
  }
  v4 = a1 + 936;
LABEL_35:
  if ( !v2 )
  {
    v14 = a1;
    v15 = a2;
    v5 = cam_vfe_camif_ver3_acquire_resource(v4);
    if ( v5 )
      return v5;
    v2 = *(_DWORD *)(v15 + 56);
    a2 = v15;
    a1 = v14;
  }
  if ( v2 - 3 <= 6 )
  {
    v7 = a1;
    v8 = a2;
    v5 = cam_vfe_camif_lite_ver3_acquire_resource(v4);
    if ( v5 )
      return v5;
    v2 = *(_DWORD *)(v8 + 56);
    a2 = v8;
    a1 = v7;
  }
  if ( v2 != 2 || (v9 = a1, v10 = a2, v11 = cam_vfe_fe_ver1_acquire_resource(v4), a2 = v10, v5 = v11, a1 = v9, !v5) )
  {
    v5 = 0;
    *(_QWORD *)(v4 + 48) = *(_QWORD *)(a2 + 72);
    v12 = debug_mdl;
    v13 = *(_QWORD *)(a2 + 8);
    *(_DWORD *)(v4 + 8) = 2;
    *(_QWORD *)(v4 + 56) = v13;
    *(_QWORD *)(a2 + 48) = v4;
    if ( (v12 & 8) != 0 && !debug_priority )
    {
      ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v12 & 8,
        4,
        "cam_vfe_top_ver3_reserve",
        493,
        "VFE[%u] Res [id:%d name:%s] reserved",
        *(_DWORD *)(*(_QWORD *)(a1 + 8) + 4LL),
        *(_DWORD *)(a2 + 56),
        (const char *)(v4 + 128));
      return 0;
    }
  }
  return v5;
}
