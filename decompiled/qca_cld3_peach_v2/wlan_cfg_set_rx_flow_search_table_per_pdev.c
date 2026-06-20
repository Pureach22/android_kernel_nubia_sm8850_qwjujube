__int64 __fastcall wlan_cfg_set_rx_flow_search_table_per_pdev(__int64 result, char a2)
{
  *(_BYTE *)(result + 699) = a2;
  return result;
}
