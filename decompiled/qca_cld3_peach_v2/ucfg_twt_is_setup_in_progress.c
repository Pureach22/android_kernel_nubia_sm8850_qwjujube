__int64 __fastcall ucfg_twt_is_setup_in_progress(__int64 a1, unsigned __int8 *a2, unsigned __int8 a3)
{
  return wlan_twt_is_setup_in_progress(a1, a2, a3) & 1;
}
