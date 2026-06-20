__int64 __fastcall hif_pci_prevent_linkdown(
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
  const char *v12; // x4
  __int64 result; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7

  if ( (a2 & 1) != 0 )
    v12 = "disable";
  else
    v12 = "enable";
  qdf_trace_msg(
    0x3Du,
    5u,
    "%s: wlan: %s pcie power collapse",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "hif_pci_prevent_linkdown",
    v12);
  hif_runtime_prevent_linkdown(a1, a2);
  result = pld_wlan_pm_control(*(_QWORD *)(*(_QWORD *)(a1 + 576) + 40LL), a2);
  if ( (_DWORD)result )
    return qdf_trace_msg(
             0x3Du,
             2u,
             "%s: Failed pld_wlan_pm_control; errno %d",
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             v21,
             "hif_pci_prevent_linkdown",
             (unsigned int)result);
  return result;
}
