__int64 __fastcall _cam_irq_controller_read_registers(__int64 result)
{
  __int64 v1; // x19
  int v2; // w8
  __int64 v3; // x21
  __int64 v4; // x23
  char v5; // w9
  const char *v6; // x8
  __int64 v7; // x8

  v1 = result;
  if ( *(_DWORD *)(result + 24) )
  {
    v2 = 0;
    do
    {
      v3 = *(_QWORD *)(v1 + 32) + 112LL * v2;
      v4 = v2;
      if ( *(_DWORD *)(v3 + 52) )
      {
        result = cam_io_r(*(_QWORD *)(v1 + 16) + *(unsigned int *)(v3 + 12));
        *(_DWORD *)(*(_QWORD *)(v1 + 40) + 4 * v4) = result;
        if ( (debug_mdl & 0x800000) != 0 && !debug_priority )
          result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                     3,
                     debug_mdl & 0x800000,
                     4,
                     "__cam_irq_controller_read_registers",
                     962,
                     "(%s) Read irq status%d (0x%x) = 0x%x",
                     (const char *)v1,
                     v4,
                     *(_DWORD *)(*(_QWORD *)(v1 + 32) + 112LL * (int)v4 + 12),
                     *(_DWORD *)(*(_QWORD *)(v1 + 40) + 4 * v4));
        if ( (*(_DWORD *)(v3 + 52) & *(_DWORD *)(*(_QWORD *)(v1 + 40) + 4 * v4)) != 0 )
        {
          v5 = 1;
          v6 = "Y";
          goto LABEL_13;
        }
        if ( *(_BYTE *)(v3 + 108) == 1 )
        {
          v5 = 0;
          v6 = "N";
LABEL_13:
          *(_BYTE *)(v3 + 108) = v5;
          if ( (debug_mdl & 0x800000) != 0 && !debug_priority )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 0x800000,
              4,
              "__cam_irq_controller_read_registers",
              988,
              "(%s) Write irq clear%d (0x%x) = 0x%x (dirty=%s)",
              (const char *)v1,
              v4,
              *(_DWORD *)(*(_QWORD *)(v1 + 32) + 112LL * (int)v4 + 8),
              *(_DWORD *)(*(_QWORD *)(v1 + 40) + 4 * v4),
              v6);
          result = cam_io_w(
                     *(unsigned int *)(*(_QWORD *)(v1 + 40) + 4 * v4),
                     *(_QWORD *)(v1 + 16) + *(unsigned int *)(v3 + 8));
        }
      }
      else
      {
        *(_DWORD *)(*(_QWORD *)(v1 + 40) + 4LL * v2) = 0;
      }
      v2 = v4 + 1;
    }
    while ( (unsigned int)(v4 + 1) < *(_DWORD *)(v1 + 24) );
  }
  v7 = *(unsigned int *)(v1 + 48);
  if ( (_DWORD)v7 )
  {
    if ( (*(_BYTE *)(v1 + 325) & 1) == 0 )
    {
      result = cam_io_w_mb(*(unsigned int *)(v1 + 52), *(_QWORD *)(v1 + 16) + v7);
      if ( (debug_mdl & 0x800000) != 0 && !debug_priority )
        return ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                 3,
                 debug_mdl & 0x800000,
                 4,
                 "__cam_irq_controller_read_registers",
                 997,
                 "Global Clear done from %s",
                 (const char *)v1);
    }
  }
  return result;
}
