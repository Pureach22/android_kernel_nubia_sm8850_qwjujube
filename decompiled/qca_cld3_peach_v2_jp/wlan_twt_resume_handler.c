__int64 __fastcall wlan_twt_resume_handler(__int64 a1)
{
  wlan_twt_psoc_set_pmo_enable(a1, 1);
  return 0;
}
