__int64 __fastcall dp_soc_set_def_pdev(__int64 a1)
{
  ((void (__fastcall *)(_QWORD, __int64, _QWORD))wlan_cfg_set_pdev_idx)(*(_QWORD *)(a1 + 40), 255, 0);
  return ((__int64 (__fastcall *)(_QWORD, __int64, __int64))wlan_cfg_set_pdev_idx)(*(_QWORD *)(a1 + 40), 255, 1);
}
