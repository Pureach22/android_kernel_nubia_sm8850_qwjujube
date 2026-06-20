__int64 __fastcall cam_vfe_camif_ver2_acquire_resource(__int64 a1, __int64 a2)
{
  unsigned int v2; // w6
  __int64 v3; // x10
  __int64 v4; // x8
  unsigned int v5; // w8

  v2 = *(_DWORD *)(*(_QWORD *)(a2 + 88) + 76LL);
  if ( v2 >= 8 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_camif_validate_pix_pattern",
      192,
      "Error! Invalid pix pattern:%d",
      v2);
    return (unsigned int)-22;
  }
  else
  {
    v3 = *(_QWORD *)(a1 + 24);
    v4 = v3 + 20480;
    *(_DWORD *)(v3 + 22628) = *(_DWORD *)(a2 + 80);
    *(_DWORD *)(v3 + 22636) = *(_DWORD *)(*(_QWORD *)(a2 + 88) + 76LL);
    *(_DWORD *)(v3 + 22632) = *(_DWORD *)(*(_QWORD *)(a2 + 88) + 128LL);
    *(_DWORD *)(v3 + 22640) = *(_DWORD *)(*(_QWORD *)(a2 + 88) + 84LL);
    *(_DWORD *)(v3 + 22648) = *(_DWORD *)(*(_QWORD *)(a2 + 88) + 88LL);
    *(_DWORD *)(v3 + 22644) = *(_DWORD *)(*(_QWORD *)(a2 + 88) + 108LL);
    *(_DWORD *)(v3 + 22652) = *(_DWORD *)(*(_QWORD *)(a2 + 88) + 112LL);
    *(_QWORD *)(v3 + 48) = *(_QWORD *)(a2 + 24);
    *(_QWORD *)(v3 + 56) = *(_QWORD *)(a2 + 16);
    LODWORD(v3) = *(_DWORD *)(a2 + 64);
    *(_QWORD *)(v4 + 2176) = 0;
    *(_DWORD *)(v4 + 2200) = v3;
    if ( *(_DWORD *)(a2 + 64) )
      *(_DWORD *)(v4 + 2196) = *(_DWORD *)(a2 + 60);
    v5 = 0;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_vfe_camif_ver2_acquire_resource",
        284,
        "hw id:%d pix_pattern:%d dsp_mode=%d",
        *(unsigned int *)(*(_QWORD *)(a1 + 16) + 4LL));
      return 0;
    }
  }
  return v5;
}
