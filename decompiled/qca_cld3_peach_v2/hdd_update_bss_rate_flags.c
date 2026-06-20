__int64 __fastcall hdd_update_bss_rate_flags(__int64 a1, __int64 a2, int a3)
{
  return ucfg_mlme_update_bss_rate_flags(
           a2,
           *(unsigned __int8 *)(a1 + 8),
           a3,
           (*(_BYTE *)(a1 + 771) & 4) != 0,
           (*(_BYTE *)(a1 + 771) & 0x40) != 0,
           (*(_BYTE *)(a1 + 771) & 2) != 0,
           *(_BYTE *)(a1 + 771) & 1);
}
