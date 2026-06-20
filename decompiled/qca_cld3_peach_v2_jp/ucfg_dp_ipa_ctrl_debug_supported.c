bool __fastcall ucfg_dp_ipa_ctrl_debug_supported(__int64 a1)
{
  return *(_BYTE *)(cfg_psoc_get_values(a1) + 4156) == 1;
}
