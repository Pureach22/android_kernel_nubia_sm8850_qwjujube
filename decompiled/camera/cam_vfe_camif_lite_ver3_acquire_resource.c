__int64 __fastcall cam_vfe_camif_lite_ver3_acquire_resource(__int64 a1, __int64 a2)
{
  __int64 v2; // x9
  unsigned int v3; // w8
  char v4; // w10

  if ( a1 )
  {
    v2 = *(_QWORD *)(a1 + 24);
    v3 = 0;
    *(_DWORD *)(v2 + 48) = *(_DWORD *)(a2 + 80);
    *(_QWORD *)(v2 + 96) = *(_QWORD *)(a2 + 24);
    v4 = debug_mdl;
    *(_QWORD *)(v2 + 104) = *(_QWORD *)(a2 + 16);
    *(_BYTE *)(a1 + 144) = 0;
    if ( (v4 & 8) != 0 && !debug_priority )
    {
      ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v4 & 8,
        4,
        "cam_vfe_camif_lite_ver3_acquire_resource",
        244,
        "Acquired VFE:%d CAMIF LITE:%d %s sync_mode=%d",
        *(_DWORD *)(*(_QWORD *)(a1 + 16) + 4LL),
        *(_DWORD *)(a1 + 4),
        (const char *)(a1 + 128),
        *(_DWORD *)(v2 + 48));
      return 0;
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_camif_lite_ver3_acquire_resource",
      228,
      "Error Invalid input arguments");
    return (unsigned int)-22;
  }
  return v3;
}
