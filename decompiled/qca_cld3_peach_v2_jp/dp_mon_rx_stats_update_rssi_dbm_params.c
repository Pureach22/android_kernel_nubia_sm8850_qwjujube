__int64 __fastcall dp_mon_rx_stats_update_rssi_dbm_params(__int64 result, __int64 a2)
{
  *(_DWORD *)(a2 + 392) = *(_DWORD *)(result + 39312);
  *(_BYTE *)(a2 + 396) = *(_BYTE *)(result + 39288);
  *(_WORD *)(a2 + 202) = *(_DWORD *)(result + 39312);
  return result;
}
