__int64 __fastcall wma_get_fw_wlan_feat_caps(char a1)
{
  return ((unsigned int)g_fw_wlan_feat_caps >> a1) & 1;
}
