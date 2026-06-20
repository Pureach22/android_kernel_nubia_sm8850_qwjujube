__int64 __fastcall nubia_gpio_ctrl1(__int64 a1)
{
  _QWORD *v1; // x8

  v1 = *(_QWORD **)(a1 + 168);
  if ( v1 )
  {
    if ( v1[2] )
    {
      return pinctrl_select_state(*v1);
    }
    else
    {
      printk(&unk_72B1);
      return 4294967274LL;
    }
  }
  else
  {
    dev_err(a1 + 16, "Cannot get hw gpio info\n");
    return 4294967274LL;
  }
}
