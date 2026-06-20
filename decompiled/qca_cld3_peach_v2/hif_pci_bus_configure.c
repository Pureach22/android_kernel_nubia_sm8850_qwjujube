__int64 __fastcall hif_pci_bus_configure(__int64 a1)
{
  __int64 v2; // x21
  unsigned int v3; // w0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  unsigned int v12; // w20
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int v21; // w8
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  unsigned int v39; // w8
  unsigned int v40; // w0

  v2 = a1 + 24576;
  hif_ce_prepare_config(a1);
  *(_DWORD *)(v2 + 2728) = 0;
  *(_BYTE *)(v2 + 2792) = 1;
  *(_BYTE *)(v2 + 2733) = 0;
  *(_QWORD *)(a1 + 27376) = 0;
  *(_QWORD *)(a1 + 27352) = hif_sleep_entry;
  *(_QWORD *)(a1 + 27360) = a1;
  init_timer_key(a1 + 27312, _os_timer_shim_12, 0, 0, 0);
  *(_BYTE *)(v2 + 2792) = 1;
  v3 = hif_wlan_enable(a1);
  if ( v3 )
  {
    v12 = v3;
    qdf_trace_msg(
      0x3Du,
      2u,
      "%s: hif_wlan_enable error: %d",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "hif_pci_bus_configure",
      v3);
  }
  else
  {
    if ( (ce_srng_based(a1) & 1) != 0
      || *(_DWORD *)(a1 + 72)
      || (hif_pci_target_sleep_state_adjust(a1, 0, 1, v13, v14, v15, v16, v17, v18, v19, v20) & 0x80000000) == 0 )
    {
      v21 = *(_DWORD *)(a1 + 20);
      if ( v21 <= 0x29 && ((1LL << v21) & 0x29A63100000LL) != 0 && *(_DWORD *)(a1 + 72) == 1 )
        *(_BYTE *)(a1 + 650) = 1;
      v12 = hif_config_ce(a1);
      if ( !v12 )
      {
        v39 = *(_DWORD *)(a1 + 20);
        if ( v39 <= 0x29 && ((1LL << v39) & 0x29A63100000LL) != 0 && !*(_DWORD *)(a1 + 72) )
        {
          qdf_trace_msg(
            0x3Du,
            8u,
            "%s: Skip irq config for PCI based 8074 target",
            v22,
            v23,
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            "hif_pci_bus_configure");
          return 0;
        }
        v40 = hif_configure_irq(a1);
        if ( (v40 & 0x80000000) == 0 )
          return 0;
        v12 = v40;
        ((void (__fastcall *)(__int64))hif_unconfig_ce)(a1);
      }
    }
    else
    {
      v12 = -13;
    }
    hif_wlan_disable(a1);
  }
  timer_delete((timer_t)(a1 + 27312));
  timer_delete_sync(a1 + 27312);
  *(_BYTE *)(v2 + 2792) = 0;
  qdf_trace_msg(
    0x3Du,
    2u,
    "%s: Failed, status: %d",
    v30,
    v31,
    v32,
    v33,
    v34,
    v35,
    v36,
    v37,
    "hif_pci_bus_configure",
    v12);
  return v12;
}
