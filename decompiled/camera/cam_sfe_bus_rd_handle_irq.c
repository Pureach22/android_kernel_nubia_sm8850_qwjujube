__int64 __fastcall cam_sfe_bus_rd_handle_irq(__int64 a1, __int64 *a2)
{
  __int64 v2; // x19
  unsigned int v4; // w20

  v2 = *a2;
  if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
  {
    v4 = a1;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 0x40000000,
      4,
      "cam_sfe_bus_rd_handle_irq",
      365,
      "Top Bus RD IRQ Received");
    a1 = v4;
  }
  if ( (unsigned int)cam_irq_controller_handle_irq(a1, *(_QWORD *)(v2 + 376), 0) == 1 )
    return 0;
  else
    return 4294967274LL;
}
