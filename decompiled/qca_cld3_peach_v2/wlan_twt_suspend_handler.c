__int64 __fastcall wlan_twt_suspend_handler(__int64 a1)
{
  wlan_twt_psoc_set_pmo_disable(a1, 1);
  return 0;
}
