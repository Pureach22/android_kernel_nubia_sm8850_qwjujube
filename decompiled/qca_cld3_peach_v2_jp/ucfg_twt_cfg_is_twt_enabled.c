__int64 __fastcall ucfg_twt_cfg_is_twt_enabled(__int64 a1)
{
  return wlan_twt_cfg_is_twt_enabled(a1) & 1;
}
