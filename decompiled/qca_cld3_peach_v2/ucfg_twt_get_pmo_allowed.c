__int64 __fastcall ucfg_twt_get_pmo_allowed(__int64 a1)
{
  return wlan_twt_get_pmo_allowed(a1) & 1;
}
