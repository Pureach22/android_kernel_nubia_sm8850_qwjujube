__int64 __fastcall wlan_mlme_get_vendor_handoff_control_caps(__int64 a1)
{
  return (*(unsigned __int8 *)(a1 + 24) >> 5) & 1;
}
