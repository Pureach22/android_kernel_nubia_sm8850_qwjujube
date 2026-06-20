void __noreturn sub_8DA0()
{
  _ReadStatusReg(CNTVCTSS_EL0);
  JUMPOUT(0x8DA8);
}
