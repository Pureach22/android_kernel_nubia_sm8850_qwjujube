__int64 __fastcall sme_is_feature_supported_by_fw(__int64 a1)
{
  return wma_get_fw_wlan_feat_caps(a1) & 1;
}
