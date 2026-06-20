__int64 __fastcall cam_vfe_fe_ver1_acquire_resource(__int64 a1, __int64 a2)
{
  unsigned int v4; // w6
  __int64 v5; // x10
  __int64 result; // x0
  int v7; // w12
  char v8; // w9

  v4 = *(_DWORD *)(*(_QWORD *)(a2 + 88) + 76LL);
  if ( v4 >= 8 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_fe_validate_pix_pattern",
      65,
      "Error! Invalid pix pattern:%d",
      v4);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_fe_ver1_acquire_resource",
      175,
      "pix validation failed: id:%d pix_pattern %d",
      *(_DWORD *)(*(_QWORD *)(a1 + 16) + 4LL),
      *(_DWORD *)(*(_QWORD *)(a2 + 88) + 76LL));
    return 4294967274LL;
  }
  else
  {
    v5 = *(_QWORD *)(a1 + 24);
    result = 0;
    *(_DWORD *)(v5 + 48) = *(_DWORD *)(a2 + 80);
    *(_DWORD *)(v5 + 56) = *(_DWORD *)(*(_QWORD *)(a2 + 88) + 76LL);
    *(_DWORD *)(v5 + 52) = *(_DWORD *)(*(_QWORD *)(a2 + 88) + 128LL);
    *(_DWORD *)(v5 + 60) = *(_DWORD *)(*(_QWORD *)(a2 + 88) + 84LL);
    *(_DWORD *)(v5 + 68) = *(_DWORD *)(*(_QWORD *)(a2 + 88) + 88LL);
    *(_DWORD *)(v5 + 64) = *(_DWORD *)(*(_QWORD *)(a2 + 88) + 108LL);
    v7 = *(_DWORD *)(*(_QWORD *)(a2 + 88) + 112LL);
    v8 = debug_mdl;
    *(_QWORD *)(v5 + 76) = 0;
    *(_DWORD *)(v5 + 72) = v7;
    if ( (v8 & 8) != 0 && !debug_priority )
    {
      ((void (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
        3,
        v8 & 8,
        4,
        "cam_vfe_fe_ver1_acquire_resource",
        191,
        "hw id:%d pix_pattern:%d dsp_mode=%d",
        *(unsigned int *)(*(_QWORD *)(a1 + 16) + 4LL));
      return 0;
    }
  }
  return result;
}
