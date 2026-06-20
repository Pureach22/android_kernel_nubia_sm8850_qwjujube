__int64 __fastcall cam_vfe_camif_ver3_resource_stop(__int64 a1)
{
  int v1; // w8
  __int64 v2; // x19
  __int64 v3; // x20
  int v4; // w0
  int v5; // w0
  int v6; // w8

  if ( a1 )
  {
    v1 = *(_DWORD *)(a1 + 8);
    if ( (unsigned int)(v1 - 1) < 2 )
      return 0;
    v2 = *(_QWORD *)(a1 + 24);
    if ( (unsigned int)(*(_DWORD *)(v2 + 22688) - 1) <= 1 )
    {
      v3 = a1;
      v4 = cam_io_r_mb(*(_QWORD *)v2 + *(unsigned int *)(*(_QWORD *)(v2 + 24) + 52LL));
      cam_io_w_mb(
        v4 & (unsigned int)~(1 << *(_DWORD *)(*(_QWORD *)(v2 + 32) + 44LL)),
        *(_QWORD *)v2 + *(unsigned int *)(*(_QWORD *)(v2 + 24) + 52LL));
      v1 = *(_DWORD *)(v3 + 8);
      a1 = v3;
    }
    if ( v1 == 4 )
      *(_DWORD *)(a1 + 8) = 2;
    v5 = cam_io_r_mb(*(_QWORD *)v2 + *(unsigned int *)(*(_QWORD *)(v2 + 24) + 80LL));
    v6 = *(_DWORD *)(*(_QWORD *)(v2 + 32) + 92LL);
    if ( (v6 & v5) != 0 )
      cam_io_w_mb(v5 & (unsigned int)~v6, *(_QWORD *)v2 + *(unsigned int *)(*(_QWORD *)(v2 + 24) + 80LL));
    if ( *(_DWORD *)(v2 + 116) )
    {
      ((void (__fastcall *)(_QWORD))cam_irq_controller_unsubscribe_irq)(*(_QWORD *)(v2 + 128));
      *(_DWORD *)(v2 + 116) = 0;
    }
    if ( *(_DWORD *)(v2 + 120) )
    {
      ((void (__fastcall *)(_QWORD))cam_irq_controller_unsubscribe_irq)(*(_QWORD *)(v2 + 128));
      *(_DWORD *)(v2 + 120) = 0;
    }
    if ( *(_DWORD *)(v2 + 112) )
    {
      ((void (__fastcall *)(_QWORD))cam_irq_controller_unsubscribe_irq)(*(_QWORD *)(v2 + 128));
      *(_DWORD *)(v2 + 112) = 0;
      return 0;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_camif_ver3_resource_stop",
      709,
      "Error, Invalid input arguments");
    return 4294967274LL;
  }
}
