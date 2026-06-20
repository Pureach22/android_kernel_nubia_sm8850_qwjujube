__int64 __fastcall ucfg_mlme_get_vendor_handoff_control_caps(__int64 a1)
{
  return wlan_mlme_get_vendor_handoff_control_caps(a1) & 1;
}
