__int64 __fastcall hif_deconfigure_ext_group_interrupts(_BYTE *a1)
{
  __int64 result; // x0

  if ( !a1 || (a1[586] & 1) == 0 )
    return qdf_trace_msg(
             61,
             2,
             "%s: scn(%pk) is NULL or grp irq not configured",
             "hif_deconfigure_ext_group_interrupts",
             a1);
  result = hif_grp_irq_deconfigure((__int64)a1);
  a1[586] = 0;
  return result;
}
