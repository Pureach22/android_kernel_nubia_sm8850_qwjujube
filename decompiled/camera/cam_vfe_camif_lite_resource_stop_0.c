__int64 __fastcall cam_vfe_camif_lite_resource_stop_0(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x20
  __int64 v4; // x19

  if ( a1 )
  {
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      v4 = a1;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_vfe_camif_lite_resource_stop",
        684,
        "VFE:%d CAMIF LITE:%d %s Stop",
        *(_DWORD *)(*(_QWORD *)(a1 + 16) + 4LL),
        *(_DWORD *)(a1 + 4),
        (const char *)(a1 + 128));
      a1 = v4;
    }
    if ( (unsigned int)(*(_DWORD *)(a1 + 8) - 1) < 2 )
      return 0;
    v1 = *(_QWORD *)(a1 + 24);
    v2 = a1;
    cam_io_w_mb(0, *(_QWORD *)v1 + *(unsigned int *)(*(_QWORD *)(v1 + 16) + 8LL));
    if ( *(_DWORD *)(v2 + 8) == 4 )
      *(_DWORD *)(v2 + 8) = 2;
    if ( *(int *)(v1 + 116) >= 1 )
    {
      ((void (__fastcall *)(_QWORD))cam_irq_controller_unsubscribe_irq)(*(_QWORD *)(v1 + 128));
      *(_DWORD *)(v1 + 116) = 0;
    }
    if ( *(int *)(v1 + 120) >= 1 )
    {
      ((void (__fastcall *)(_QWORD))cam_irq_controller_unsubscribe_irq)(*(_QWORD *)(v1 + 128));
      *(_DWORD *)(v1 + 120) = 0;
    }
    if ( *(int *)(v1 + 112) < 1 )
    {
      return 0;
    }
    else
    {
      ((void (__fastcall *)(_QWORD))cam_irq_controller_unsubscribe_irq)(*(_QWORD *)(v1 + 128));
      *(_DWORD *)(v1 + 112) = 0;
      return 0;
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_camif_lite_resource_stop",
      677,
      "Invalid input arguments");
    return 4294967274LL;
  }
}
