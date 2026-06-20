__int64 __fastcall sub_20E100(__int64 a1, __int64 a2)
{
  __asm { LDLAR           X18, [X12] }
  return wlan_reg_get_5g_bonded_channel_state_for_pwrmode(a1, a2);
}
