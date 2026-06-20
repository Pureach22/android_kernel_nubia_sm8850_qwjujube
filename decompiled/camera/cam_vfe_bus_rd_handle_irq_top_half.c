__int64 __fastcall cam_vfe_bus_rd_handle_irq_top_half(__int64 a1, _DWORD **a2)
{
  __int64 v2; // x9
  char v3; // w8
  __int64 result; // x0
  __int64 v5; // x0

  if ( *a2 )
  {
    v2 = *((_QWORD *)*a2 + 3);
    v3 = debug_mdl;
    result = 0;
    *(_DWORD *)(v2 + 112) = *a2[2];
    if ( (v3 & 8) != 0 && !debug_priority )
    {
      ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v3 & 8,
        4,
        "cam_vfe_bus_rd_handle_irq_top_half",
        290,
        "VFE:%d Bus RD IRQ status_0: 0x%X",
        **(_DWORD **)(v2 + 8),
        *a2[2]);
      return 0;
    }
  }
  else
  {
    if ( (unsigned int)__ratelimit(&cam_vfe_bus_rd_handle_irq_top_half__rs, "cam_vfe_bus_rd_handle_irq_top_half") )
      v5 = 3;
    else
      v5 = 2;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      v5,
      8,
      1,
      "cam_vfe_bus_rd_handle_irq_top_half",
      282,
      "No resource");
    return 4294967277LL;
  }
  return result;
}
