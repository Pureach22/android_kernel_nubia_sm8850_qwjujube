__int64 __fastcall hif_pci_display_stats(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  if ( !a1 )
    return qdf_trace_msg(0x3Du, 2u, "%s: hif_ctx null", a2, a3, a4, a5, a6, a7, a8, a9, "hif_pci_display_stats");
  hif_display_ce_stats(a1);
  return hif_print_pci_stats(a1);
}
