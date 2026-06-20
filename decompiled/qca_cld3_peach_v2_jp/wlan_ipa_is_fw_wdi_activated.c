bool __fastcall wlan_ipa_is_fw_wdi_activated(__int64 a1)
{
  return (*(_BYTE *)(a1 + 3440) & 1) == 0;
}
