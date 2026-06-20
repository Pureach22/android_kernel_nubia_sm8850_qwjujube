__int64 __fastcall cam_vfe_rdi_resource_stop(__int64 a1)
{
  int v1; // w8
  __int64 v2; // x19

  if ( a1 )
  {
    v1 = *(_DWORD *)(a1 + 8);
    if ( (unsigned int)(v1 - 1) < 2 )
      return 0;
    v2 = *(_QWORD *)(a1 + 24);
    if ( v1 == 4 )
      *(_DWORD *)(a1 + 8) = 2;
    if ( *(_DWORD *)(v2 + 84) )
    {
      ((void (__fastcall *)(_QWORD))cam_irq_controller_unsubscribe_irq)(*(_QWORD *)(v2 + 88));
      *(_DWORD *)(v2 + 84) = 0;
    }
    if ( *(_DWORD *)(v2 + 80) )
    {
      ((void (__fastcall *)(_QWORD))cam_irq_controller_unsubscribe_irq)(*(_QWORD *)(v2 + 88));
      *(_DWORD *)(v2 + 80) = 0;
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
      "cam_vfe_rdi_resource_stop",
      317,
      "Error! Invalid input arguments");
    return 4294967274LL;
  }
}
