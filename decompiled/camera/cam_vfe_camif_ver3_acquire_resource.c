__int64 __fastcall cam_vfe_camif_ver3_acquire_resource(__int64 a1, __int64 a2)
{
  __int64 v2; // x6
  __int64 v3; // x11
  __int64 v4; // x9
  int v5; // w7
  int v6; // w8
  int v7; // w10
  unsigned int v8; // w19

  v2 = *(unsigned int *)(*(_QWORD *)(a2 + 88) + 76LL);
  if ( (unsigned int)v2 >= 8 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_camif_ver3_validate_pix_pattern",
      196,
      "Error, Invalid pix pattern:%d",
      v2);
    v8 = -22;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_camif_ver3_acquire_resource",
      270,
      "Validate pix pattern failed, rc = %d",
      -22);
  }
  else
  {
    v3 = *(_QWORD *)(a1 + 24);
    v4 = v3 + 20480;
    *(_DWORD *)(v3 + 88) = *(_DWORD *)((char *)*(&off_44ED20 + v2) + *(_QWORD *)(v3 + 32));
    *(_DWORD *)(v3 + 22684) = *(_DWORD *)(a2 + 80);
    v5 = *(_DWORD *)(*(_QWORD *)(a2 + 88) + 76LL);
    *(_DWORD *)(v3 + 22692) = v5;
    v6 = *(_DWORD *)(*(_QWORD *)(a2 + 88) + 128LL);
    *(_DWORD *)(v3 + 22688) = v6;
    *(_DWORD *)(v3 + 22696) = *(_DWORD *)(*(_QWORD *)(a2 + 88) + 84LL);
    *(_DWORD *)(v3 + 22704) = *(_DWORD *)(*(_QWORD *)(a2 + 88) + 88LL);
    *(_DWORD *)(v3 + 22700) = *(_DWORD *)(*(_QWORD *)(a2 + 88) + 108LL);
    *(_DWORD *)(v3 + 22708) = *(_DWORD *)(*(_QWORD *)(a2 + 88) + 112LL);
    *(_BYTE *)(v3 + 22748) = *(_BYTE *)(a2 + 96);
    *(_BYTE *)(v3 + 22749) = *(_BYTE *)(a2 + 97);
    v7 = *(_DWORD *)(a2 + 64);
    *(_DWORD *)(v3 + 22744) = v7;
    *(_QWORD *)(v3 + 96) = *(_QWORD *)(a2 + 24);
    *(_QWORD *)(v3 + 104) = *(_QWORD *)(a2 + 16);
    *(_DWORD *)(v3 + 22736) = *(_DWORD *)(*(_QWORD *)(a2 + 88) + 156LL);
    LODWORD(v3) = *(_DWORD *)(*(_QWORD *)(a2 + 88) + 148LL);
    *(_QWORD *)(v4 + 2232) = 0;
    *(_DWORD *)(v4 + 2252) = v3;
    if ( v7 )
      *(_DWORD *)(v4 + 2260) = *(_DWORD *)(a2 + 60);
    v8 = 0;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_vfe_camif_ver3_acquire_resource",
        299,
        "VFE:%d CAMIF pix_pattern:%d dsp_mode=%d is_dual:%d dual_hw_idx:%d",
        *(_DWORD *)(*(_QWORD *)(a1 + 16) + 4LL),
        v5,
        v6,
        v7,
        *(_DWORD *)(v4 + 2260));
      return 0;
    }
  }
  return v8;
}
