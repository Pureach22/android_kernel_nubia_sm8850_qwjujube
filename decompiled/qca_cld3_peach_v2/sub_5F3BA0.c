__int64 __fastcall sub_5F3BA0(__int64 a1, __int64 a2, __int64 a3)
{
  _ReadStatusReg(CNTVCTSS_EL0);
  _ReadStatusReg(CNTVCTSS_EL0);
  _ReadStatusReg(CNTVCTSS_EL0);
  _ReadStatusReg(CNTVCTSS_EL0);
  _ReadStatusReg(CNTVCTSS_EL0);
  _ReadStatusReg(CNTVCTSS_EL0);
  _ReadStatusReg(CNTVCTSS_EL0);
  _ReadStatusReg(CNTVCTSS_EL0);
  *(_BYTE *)(a3 + 1837) = a2;
  return pmo_set_wow_event_bitmap(a1, a2, a3);
}
