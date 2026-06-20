__int64 __fastcall sub_2C44E8(__int64 a1, __int64 a2)
{
  _ReadStatusReg(CNTVCTSS_EL0);
  _ReadStatusReg(CNTVCTSS_EL0);
  return wlan_cm_enable_roaming_on_connected_sta(a1, a2);
}
