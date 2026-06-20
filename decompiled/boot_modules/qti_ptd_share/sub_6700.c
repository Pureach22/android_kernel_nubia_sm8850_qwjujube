void __noreturn sub_6700()
{
  _ReadStatusReg(CNTVCTSS_EL0);
  _ReadStatusReg(CNTVCTSS_EL0);
  JUMPOUT(0x6710);
}
