bool __fastcall ucfg_pmo_is_fw_debug_enable(__int64 a1)
{
  return *(_DWORD *)(cfg_psoc_get_values(a1) + 10624) != 0;
}
