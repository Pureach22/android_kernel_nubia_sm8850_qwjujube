void sub_8998()
{
  _ReadStatusReg(CNTVCTSS_EL0);
  JUMPOUT(0x84CC);
}
