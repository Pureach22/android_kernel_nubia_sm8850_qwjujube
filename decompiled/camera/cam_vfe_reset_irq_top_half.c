__int64 __fastcall cam_vfe_reset_irq_top_half(__int64 a1, __int64 *a2)
{
  __int64 v2; // x19

  v2 = *a2;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_vfe_reset_irq_top_half",
      75,
      "TOP_IRQ_STATUS_0 = 0x%x",
      *(_DWORD *)a2[2]);
  complete(v2 + 56);
  return 4294967274LL;
}
