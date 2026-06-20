__int64 __fastcall cam_vfe_resource_stop(__int64 a1)
{
  int v1; // w8
  __int64 result; // x0
  __int64 v4; // x21
  __int64 v5; // x22
  __int64 v6; // x9
  int v7; // w0
  int v8; // w1

  if ( a1 )
  {
    v1 = *(_DWORD *)(a1 + 8);
    if ( (unsigned int)(v1 - 1) < 2 )
      return 0;
    v4 = *(_QWORD *)(a1 + 24);
    v5 = *(_QWORD *)(v4 + 72);
    if ( (*(_BYTE *)(v4 + 22810) & 1) == 0 && *(_BYTE *)(v4 + 22811) == 1 )
    {
      v6 = *(_QWORD *)(v4 + 24);
      if ( (*(_BYTE *)(v6 + 780) & 1) == 0 && (unsigned int)(*(_DWORD *)(v4 + 22672) - 1) <= 1 )
      {
        v7 = cam_io_r_mb(*(_QWORD *)v4 + *(unsigned int *)(v6 + 64) + *(_QWORD *)(*(_QWORD *)(v5 + 16) + 256LL));
        cam_io_w_mb(
          v7 & 0xFFFFFEFF,
          *(_QWORD *)v4 + *(unsigned int *)(*(_QWORD *)(v4 + 24) + 64LL) + *(_QWORD *)(*(_QWORD *)(v5 + 16) + 256LL));
        v1 = *(_DWORD *)(a1 + 8);
      }
    }
    if ( v1 == 4 )
      *(_DWORD *)(a1 + 8) = 2;
    if ( *(_DWORD *)(v4 + 100) )
    {
      ((void (__fastcall *)(_QWORD))cam_irq_controller_unsubscribe_irq)(*(_QWORD *)(v4 + 112));
      *(_DWORD *)(v4 + 100) = 0;
    }
    v8 = *(_DWORD *)(v4 + 104);
    *(_DWORD *)(v4 + 22804) = 0;
    if ( v8 )
    {
      ((void (__fastcall *)(_QWORD))cam_irq_controller_unsubscribe_irq)(*(_QWORD *)(v4 + 112));
      *(_DWORD *)(v4 + 104) = 0;
    }
    if ( *(_DWORD *)(v4 + 96) )
    {
      ((void (__fastcall *)(_QWORD))cam_irq_controller_unsubscribe_irq)(*(_QWORD *)(v4 + 112));
      *(_DWORD *)(v4 + 96) = 0;
    }
    if ( (*(_BYTE *)(v5 + 10504) & 1) == 0 )
      *(_DWORD *)(v4 + 22728) = 0;
    result = 0;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_vfe_resource_stop",
        2851,
        "VFE:%u Res: %s Stopped",
        *(_DWORD *)(*(_QWORD *)(a1 + 16) + 4LL),
        (const char *)(a1 + 128));
      return 0;
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_resource_stop",
      2795,
      "Error, Invalid input arguments");
    return 4294967274LL;
  }
  return result;
}
