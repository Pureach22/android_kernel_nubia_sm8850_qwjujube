__int64 __fastcall dp_get_pdev_for_mac_id(__int64 a1, int a2)
{
  if ( (unsigned int)wlan_cfg_per_pdev_lmac_ring(*(_QWORD *)(a1 + 40)) && a2 )
    return 0;
  else
    return *(_QWORD *)(a1 + 72);
}
