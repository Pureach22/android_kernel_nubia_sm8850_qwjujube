__int64 __fastcall cam_vfe_bus_ver3_stop_wm(__int64 a1)
{
  __int64 *v1; // x21
  __int64 v3; // x8
  __int64 v4; // x20
  int v5; // w8
  __int64 v6; // x8
  __int64 v7; // x8

  v1 = *(__int64 **)(a1 + 24);
  v3 = v1[7];
  v4 = *v1;
  if ( (*(_BYTE *)(v3 + 133) & 1) == 0 && *(_BYTE *)(v3 + 134) != 1 )
  {
    v6 = *(_QWORD *)(v4 + 16);
    goto LABEL_11;
  }
  v5 = *(_DWORD *)(v3 + 120);
  if ( (v5 & 1) != 0 )
  {
    cam_io_w_mb(0, *(_QWORD *)(v4 + 16) + *(_QWORD *)v4 + *(unsigned int *)(*(_QWORD *)(v4 + 80) + 16LL));
    cam_io_w_mb(0, *(_QWORD *)(*v1 + 16) + *((unsigned int *)v1 + 39) + *(unsigned int *)v1[1]);
    v5 = *(_DWORD *)(v1[7] + 120);
    if ( (v5 & 2) == 0 )
    {
LABEL_5:
      if ( (v5 & 4) == 0 )
        goto LABEL_12;
      goto LABEL_9;
    }
  }
  else if ( (v5 & 2) == 0 )
  {
    goto LABEL_5;
  }
  cam_io_w_mb(
    (unsigned int)(1 << *(_DWORD *)(*(_QWORD *)(*v1 + 80) + 88LL)),
    *(_QWORD *)(*v1 + 16) + *(_QWORD *)v4 + *(unsigned int *)(*(_QWORD *)(*v1 + 80) + 16LL));
  cam_io_w_mb(0, *(_QWORD *)(*v1 + 16) + *((unsigned int *)v1 + 39) + *(unsigned int *)v1[1]);
  if ( (*(_DWORD *)(v1[7] + 120) & 4) != 0 )
  {
LABEL_9:
    cam_io_w_mb(
      (unsigned int)(2 << *(_DWORD *)(*(_QWORD *)(*v1 + 80) + 88LL)),
      *(_QWORD *)(*v1 + 16) + *(_QWORD *)v4 + *(unsigned int *)(*(_QWORD *)(*v1 + 80) + 16LL));
    v6 = *(_QWORD *)(*v1 + 16);
LABEL_11:
    cam_io_w_mb(0, v6 + *((unsigned int *)v1 + 39) + *(unsigned int *)v1[1]);
  }
LABEL_12:
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_vfe_bus_ver3_stop_wm",
      1558,
      "Stop VFE:%u WM:%d %s hw_ctxt_mask:0x%x",
      *(_DWORD *)(*v1 + 8),
      *((_DWORD *)v1 + 30),
      (const char *)(a1 + 128),
      *(_DWORD *)(v1[7] + 120));
  *(_DWORD *)(a1 + 8) = 2;
  v7 = v1[7];
  *((_WORD *)v1 + 80) = 0;
  *((_BYTE *)v1 + 72) = 0;
  *((_BYTE *)v1 + 163) = 0;
  if ( (*(_BYTE *)(v7 + 133) & 1) != 0 || *(_BYTE *)(v7 + 134) == 1 )
  {
    *(_BYTE *)(v1[8] + 76) = 0;
    *(_BYTE *)(v1[8] + 36) = 0;
    *(_BYTE *)(v1[8] + 32) = 0;
    *(_BYTE *)(v1[8] + 156) = 0;
    *(_BYTE *)(v1[8] + 116) = 0;
    *(_BYTE *)(v1[8] + 112) = 0;
    *(_BYTE *)(v1[8] + 236) = 0;
    *(_BYTE *)(v1[8] + 196) = 0;
    *(_BYTE *)(v1[8] + 192) = 0;
  }
  *(_BYTE *)(v4 + 34672) = 0;
  return 0;
}
