__int64 __fastcall cam_vfe_bus_rd_handle_irq_bottom_half(__int64 a1)
{
  __int64 v1; // x8
  int v2; // w9
  __int64 result; // x0
  __int64 v4; // x0
  const char *v5; // x5
  __int64 v6; // x1
  __int64 v7; // x6
  __int64 v8; // x4

  if ( a1 )
  {
    v1 = *(_QWORD *)(a1 + 24);
    v2 = *(_DWORD *)(v1 + 112);
    if ( (v2 & 2) != 0 )
    {
      result = 0;
      if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        v5 = "Received VFE:%d BUS RD RUP";
        v6 = debug_mdl & 8;
        v7 = **(unsigned int **)(v1 + 8);
        v8 = 310;
LABEL_16:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
          3,
          v6,
          4,
          "cam_vfe_bus_rd_handle_irq_bottom_half",
          v8,
          v5,
          v7);
        return 0;
      }
    }
    else
    {
      if ( (v2 & 4) == 0 )
      {
        if ( (v2 & 0x10000) == 0 )
          return 0;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_vfe_bus_rd_handle_irq_bottom_half",
          316,
          "Received VFE:%d BUS RD CCIF Violation",
          **(_DWORD **)(v1 + 8));
        return 3;
      }
      result = 0;
      if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        v5 = "Received VFE:%d BUS RD BUF DONE";
        v6 = debug_mdl & 8;
        v7 = **(unsigned int **)(v1 + 8);
        v8 = 313;
        goto LABEL_16;
      }
    }
  }
  else
  {
    if ( (unsigned int)__ratelimit(&cam_vfe_bus_rd_handle_irq_bottom_half__rs, "cam_vfe_bus_rd_handle_irq_bottom_half") )
      v4 = 3;
    else
      v4 = 2;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      v4,
      8,
      1,
      "cam_vfe_bus_rd_handle_irq_bottom_half",
      303,
      "No resource");
    return 4294967277LL;
  }
  return result;
}
