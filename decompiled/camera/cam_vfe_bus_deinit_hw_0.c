__int64 __fastcall cam_vfe_bus_deinit_hw_0(__int64 a1)
{
  __int64 result; // x0

  if ( a1 )
  {
    if ( *(_DWORD *)(a1 + 624) )
    {
      result = ((__int64 (__fastcall *)(_QWORD))cam_irq_controller_unsubscribe_irq)(*(_QWORD *)(a1 + 32));
      *(_DWORD *)(a1 + 624) = 0;
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
      "cam_vfe_bus_deinit_hw",
      1170,
      "Error: Invalid args");
    return 4294967274LL;
  }
  return result;
}
