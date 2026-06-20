__int64 __fastcall hif_ce_prepare_epping_config(__int64 result, __int64 a2)
{
  *(_QWORD *)(a2 + 27400) = &host_ce_config_wlan_epping_irq;
  *(_QWORD *)(a2 + 27392) = &target_ce_config_wlan_epping;
  *(_DWORD *)(a2 + 27408) = 288;
  target_shadow_reg_cfg = &target_shadow_reg_cfg_epping;
  *(_DWORD *)(result + 656) = 12;
  return result;
}
