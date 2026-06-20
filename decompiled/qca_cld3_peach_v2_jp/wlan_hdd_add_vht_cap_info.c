__int64 __fastcall wlan_hdd_add_vht_cap_info(__int64 a1, __int64 a2, __int64 a3)
{
  int v4; // w0

  if ( (*(_BYTE *)(a1 + 467) & 2) == 0 )
    return 0;
  scnprintf(
    a2,
    a3,
    "vht_cap_info = %x\nrx_mcs_map = %x\nrx_highest = %x\ntx_mcs_map = %x\ntx_highest = %x\n",
    *(_DWORD *)(a1 + 455),
    *(unsigned __int16 *)(a1 + 459),
    *(unsigned __int16 *)(a1 + 461),
    *(unsigned __int16 *)(a1 + 463),
    *(unsigned __int16 *)(a1 + 465));
  return v4 & (unsigned int)~(v4 >> 31);
}
