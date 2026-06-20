__int64 __fastcall wma_set_fw_wlan_feat_caps(__int64 result)
{
  g_fw_wlan_feat_caps |= 1 << result;
  return result;
}
