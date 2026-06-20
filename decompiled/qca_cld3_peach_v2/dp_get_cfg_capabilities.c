__int64 __fastcall dp_get_cfg_capabilities(__int64 a1)
{
  return wlan_cfg_get_dp_caps(*(_QWORD *)(a1 + 40)) & 1;
}
