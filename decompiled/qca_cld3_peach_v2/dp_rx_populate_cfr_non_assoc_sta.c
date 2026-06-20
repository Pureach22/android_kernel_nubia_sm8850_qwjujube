__int64 __fastcall dp_rx_populate_cfr_non_assoc_sta(__int64 result, __int64 a2, __int64 a3)
{
  if ( *(_BYTE *)(result + 95936) == 1 && *(_BYTE *)(a2 + 14216) == 1 )
    return dp_rx_mon_populate_cfr_ppdu_info(result, a2, a3);
  return result;
}
