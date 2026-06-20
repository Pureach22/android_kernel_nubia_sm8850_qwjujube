unsigned __int64 __fastcall usb_gen_phy_shutdown(_QWORD *a1)
{
  _QWORD *v2; // x21
  unsigned __int64 v3; // x20
  unsigned __int64 result; // x0

  v2 = *(_QWORD **)(*a1 + 152LL);
  gpiod_set_value_cansleep(v2[49], 1);
  v3 = v2[47];
  if ( v3 <= 0xFFFFFFFFFFFFF000LL )
  {
    clk_disable(v2[47]);
    clk_unprepare(v3);
  }
  result = v2[48];
  if ( result <= 0xFFFFFFFFFFFFF000LL )
  {
    result = regulator_disable();
    if ( (_DWORD)result )
      return dev_err(*a1, "Failed to disable power\n");
  }
  return result;
}
