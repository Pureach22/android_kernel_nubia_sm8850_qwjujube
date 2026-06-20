__int64 __fastcall ucfg_twt_reset_active_command(__int64 a1, __int64 a2, __int64 a3)
{
  return ((__int64 (__fastcall *)(__int64, __int64, __int64, _QWORD))wlan_twt_set_command_in_progress)(a1, a2, a3, 0);
}
