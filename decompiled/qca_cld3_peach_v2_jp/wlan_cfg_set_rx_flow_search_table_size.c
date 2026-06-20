__int64 __fastcall wlan_cfg_set_rx_flow_search_table_size(__int64 result, __int16 a2)
{
  *(_WORD *)(result + 700) = a2;
  return result;
}
