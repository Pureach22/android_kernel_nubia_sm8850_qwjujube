__int64 __fastcall cam_vfe_bus_ver3_handle_rup_irq(__int64 a1, __int64 *a2)
{
  __int64 v2; // x19
  unsigned int v4; // w20

  v2 = *a2;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    v4 = a1;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_vfe_bus_ver3_handle_rup_irq",
      3372,
      "Enter, VFE:%u",
      *(_DWORD *)(v2 + 8));
    a1 = v4;
  }
  if ( (unsigned int)cam_irq_controller_handle_irq(a1, *(_QWORD *)(v2 + 32), 1) == 1 )
    return 0;
  else
    return 4294967274LL;
}
