__int64 __fastcall hal_tx_comp_get_release_reason_generic_be(__int64 a1)
{
  return (*(_DWORD *)(a1 + 8) >> 13) & 0xF;
}
