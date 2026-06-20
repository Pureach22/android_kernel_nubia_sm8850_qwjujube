__int64 __fastcall wmi_unified_wlan_profile_hist_intvl_cmd_send(__int64 a1)
{
  __int64 (*v1)(void); // x8

  v1 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 728) + 1912LL);
  if ( !v1 )
    return 16;
  if ( *((_DWORD *)v1 - 1) != 1153340399 )
    __break(0x8228u);
  return v1();
}
