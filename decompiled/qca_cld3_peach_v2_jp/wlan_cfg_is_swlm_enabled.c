bool __fastcall wlan_cfg_is_swlm_enabled(__int64 a1)
{
  return *(_BYTE *)(a1 + 749) != 0;
}
