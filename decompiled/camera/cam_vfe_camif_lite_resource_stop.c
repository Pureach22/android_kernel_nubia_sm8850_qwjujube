__int64 __fastcall cam_vfe_camif_lite_resource_stop(__int64 a1)
{
  int v1; // w8
  __int64 v2; // x19
  __int64 v3; // x19

  if ( a1 )
  {
    v1 = *(_DWORD *)(a1 + 8);
    if ( (unsigned int)(v1 - 1) < 2 )
      return 0;
    if ( v1 == 4 )
      *(_DWORD *)(a1 + 8) = 2;
    if ( *(_DWORD *)(a1 + 76) )
    {
      v2 = a1;
      ((void (__fastcall *)(_QWORD))cam_irq_controller_unsubscribe_irq)(*(_QWORD *)(a1 + 80));
      a1 = v2;
      *(_DWORD *)(v2 + 76) = 0;
    }
    if ( *(_DWORD *)(a1 + 72) )
    {
      v3 = a1;
      ((void (__fastcall *)(_QWORD))cam_irq_controller_unsubscribe_irq)(*(_QWORD *)(a1 + 80));
      *(_DWORD *)(v3 + 72) = 0;
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
      "cam_vfe_camif_lite_resource_stop",
      326,
      "Error! Invalid input arguments");
    return 4294967274LL;
  }
}
