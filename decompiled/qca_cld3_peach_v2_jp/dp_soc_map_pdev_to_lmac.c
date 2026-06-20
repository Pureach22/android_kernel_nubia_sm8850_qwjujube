__int64 __fastcall dp_soc_map_pdev_to_lmac(__int64 a1, unsigned __int8 a2, unsigned int a3)
{
  ((void (__fastcall *)(_QWORD, _QWORD))wlan_cfg_set_hw_mac_idx)(*(_QWORD *)(a1 + 40), a2);
  ((void (__fastcall *)(_QWORD, _QWORD, _QWORD))wlan_cfg_set_pdev_idx)(*(_QWORD *)(a1 + 40), a2, a3);
  return 0;
}
