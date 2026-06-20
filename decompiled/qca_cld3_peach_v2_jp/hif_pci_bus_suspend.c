__int64 __fastcall hif_pci_bus_suspend(__int64 a1)
{
  unsigned int v2; // w20
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  int v11; // w0

  hif_apps_irqs_disable(a1);
  v2 = hif_drain_fw_diag_ce(a1);
  if ( v2 )
    qdf_trace_msg(
      0x3Du,
      2u,
      "%s: draining fw_diag_ce not got cleaned %d",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "hif_pci_bus_suspend",
      v2);
  v11 = hif_try_complete_tasks(a1);
  if ( v2 == -11 || v11 )
  {
    hif_apps_irqs_enable(a1);
    return 4294967280LL;
  }
  else
  {
    hif_cancel_deferred_target_sleep(a1);
    *(_BYTE *)(a1 + 3988) = 1;
    return 0;
  }
}
