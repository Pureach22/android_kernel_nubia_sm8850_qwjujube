__int64 __fastcall hif_pci_reset_soc(__int64 a1)
{
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7

  if ( *(_DWORD *)hif_get_target_info_handle(a1) == 1090519404 )
    return hif_pci_device_warm_reset(a1, v2, v3, v4, v5, v6, v7, v8, v9);
  else
    return hif_pci_device_reset(a1, v2, v3, v4, v5, v6, v7, v8, v9);
}
