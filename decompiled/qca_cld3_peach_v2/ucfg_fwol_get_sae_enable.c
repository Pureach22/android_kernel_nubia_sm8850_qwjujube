__int64 __fastcall ucfg_fwol_get_sae_enable(__int64 a1)
{
  return *(unsigned __int8 *)(cfg_psoc_get_values(a1) + 1805);
}
