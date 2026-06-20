__int64 __fastcall hif_pci_enable_power_management(
        __int64 a1,
        char a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 result; // x0
  const char *v21; // x2

  if ( !a1 )
  {
    v21 = "%s: hif_ctx null";
    return qdf_trace_msg(0x3Du, 2u, v21, a3, a4, a5, a6, a7, a8, a9, a10, "hif_pci_enable_power_management");
  }
  if ( (unsigned int)hif_get_conparam(a1) == 5 )
  {
    qdf_trace_msg(
      0x3Du,
      5u,
      "%s: Enable power gating for FTM mode",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "hif_pci_enable_power_management");
    return pld_pci_write_config_dword(*(_QWORD *)(a1 + 30768), 0x80u, *(_DWORD *)(a1 + 31176));
  }
  hif_rtpm_start(a1);
  if ( (a2 & 1) == 0 )
    pld_pci_write_config_dword(*(_QWORD *)(a1 + 30768), 0x80u, *(_DWORD *)(a1 + 31176));
  result = ce_srng_based(a1);
  if ( (result & 1) == 0 )
  {
    result = hif_pci_target_sleep_state_adjust(a1, 1, 0);
    if ( (result & 0x80000000) != 0 )
    {
      v21 = "%s: Failed to set target to sleep";
      return qdf_trace_msg(0x3Du, 2u, v21, a3, a4, a5, a6, a7, a8, a9, a10, "hif_pci_enable_power_management");
    }
  }
  return result;
}
