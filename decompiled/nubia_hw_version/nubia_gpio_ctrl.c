__int64 __fastcall nubia_gpio_ctrl(__int64 a1)
{
  __int64 v2; // x0
  _QWORD *v3; // x20
  unsigned __int64 v4; // x0
  unsigned __int64 v5; // x0
  const char *v6; // x1
  __int64 *v7; // x21
  unsigned __int64 v8; // x0
  __int64 v9; // x21

  v2 = devm_kmalloc(a1 + 16, 24, 3520);
  if ( !v2 )
  {
    LODWORD(v9) = -12;
    return (unsigned int)v9;
  }
  v3 = (_QWORD *)v2;
  v4 = devm_pinctrl_get(a1 + 16);
  *v3 = v4;
  if ( !v4 || v4 >= 0xFFFFFFFFFFFFF001LL )
  {
    dev_err(a1 + 16, "Cannot get hw gpio pinctrl\n");
    v9 = *v3;
    goto LABEL_14;
  }
  v5 = ((__int64 (*)(void))pinctrl_lookup_state)();
  v6 = "Cannot get hw gpio pullup pinctrl state\n";
  v3[1] = v5;
  v7 = v3 + 1;
  if ( !v5
    || v5 > 0xFFFFFFFFFFFFF000LL
    || (v8 = pinctrl_lookup_state(*v3, "pull_down_default"),
        v6 = "Cannot get hw gpio pulldown pinctrl state\n",
        v3[2] = v8,
        v7 = v3 + 2,
        !v8)
    || v8 > 0xFFFFFFFFFFFFF000LL )
  {
    dev_err(a1 + 16, v6);
    v9 = *v7;
    devm_pinctrl_put(*v3);
LABEL_14:
    devm_kfree(a1 + 16, v3);
    return (unsigned int)v9;
  }
  if ( (unsigned int)pinctrl_select_state(*v3) )
    dev_err(a1 + 16, "set hw gpio pullup state fail:\n");
  LODWORD(v9) = 0;
  *(_QWORD *)(a1 + 168) = v3;
  return (unsigned int)v9;
}
