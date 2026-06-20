__int64 __fastcall wlan_hdd_add_ht_cap_info(__int64 a1, __int64 a2, __int64 a3)
{
  int v4; // w0

  if ( (*(_BYTE *)(a1 + 467) & 1) == 0 )
    return 0;
  scnprintf(
    a2,
    a3,
    "ht_cap_info = %x\n"
    "ampdu_params_info = %x\n"
    "extended_ht_cap_info = %x\n"
    "tx_BF_cap_info = %x\n"
    "antenna_selection_info = %x\n"
    "ht_rx_higest = %x\n"
    "ht_tx_params = %x\n",
    *(unsigned __int16 *)(a1 + 429),
    *(unsigned __int8 *)(a1 + 431),
    *(unsigned __int16 *)(a1 + 448),
    *(_DWORD *)(a1 + 450),
    *(unsigned __int8 *)(a1 + 454),
    *(unsigned __int16 *)(a1 + 442),
    *(unsigned __int8 *)(a1 + 444));
  return v4 & (unsigned int)~(v4 >> 31);
}
