void sub_223F10()
{
  _ReadStatusReg(CNTVCTSS_EL0);
  _ReadStatusReg(CNTVCTSS_EL0);
  _ReadStatusReg(CNTVCTSS_EL0);
  _ReadStatusReg(CNTVCTSS_EL0);
  _ReadStatusReg(CNTVCTSS_EL0);
  _ReadStatusReg(CNTVCTSS_EL0);
  _ReadStatusReg(CNTVCTSS_EL0);
  JUMPOUT(0x221478);
}
