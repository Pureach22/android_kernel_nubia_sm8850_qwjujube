__int64 __fastcall sub_1F027C(__int64 a1)
{
  __int64 v1; // x10
  __int64 v2; // x13

  return wlan_reg_chan_has_dfs_attribute_for_freq(a1, v2 + __ROR8__(v1, 46));
}
