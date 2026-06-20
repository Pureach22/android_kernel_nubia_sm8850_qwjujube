__int64 __fastcall usb_gen_phy_init(_QWORD *a1)
{
  _QWORD *v2; // x20
  unsigned __int64 v3; // x19
  __int64 result; // x0
  unsigned int v5; // w0
  unsigned int v6; // w20

  v2 = *(_QWORD **)(*a1 + 152LL);
  if ( v2[48] <= 0xFFFFFFFFFFFFF000LL && (unsigned int)regulator_enable() )
    dev_err(*a1, "Failed to enable power\n");
  v3 = v2[47];
  if ( v3 > 0xFFFFFFFFFFFFF000LL )
    goto LABEL_5;
  result = clk_prepare(v2[47]);
  if ( (_DWORD)result )
    return result;
  v5 = clk_enable(v3);
  if ( v5 )
  {
    v6 = v5;
    clk_unprepare(v3);
    return v6;
  }
  else
  {
LABEL_5:
    result = v2[49];
    if ( result )
    {
      gpiod_set_value_cansleep(result, 1);
      usleep_range_state(10000, 20000, 2);
      gpiod_set_value_cansleep(v2[49], 0);
      usleep_range_state(10000, 30000, 2);
      return 0;
    }
  }
  return result;
}
