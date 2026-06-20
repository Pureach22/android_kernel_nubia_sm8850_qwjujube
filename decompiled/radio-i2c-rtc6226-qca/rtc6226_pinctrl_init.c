__int64 __fastcall rtc6226_pinctrl_init(_QWORD *a1)
{
  unsigned __int64 v2; // x0
  unsigned __int64 v3; // x0
  unsigned __int64 v4; // x0
  __int64 result; // x0

  v2 = devm_pinctrl_get(a1[436] + 32LL);
  a1[185] = v2;
  if ( !v2 || v2 >= 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_CCD3, "rtc6226_pinctrl_init");
    return *((unsigned int *)a1 + 370);
  }
  v3 = ((__int64 (*)(void))pinctrl_lookup_state)();
  a1[186] = v3;
  if ( !v3 || v3 >= 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_CF6E, "rtc6226_pinctrl_init");
    result = a1[186];
LABEL_12:
    a1[186] = 0;
    return result;
  }
  v4 = pinctrl_lookup_state(a1[185], "pmx_fm_suspend");
  a1[187] = v4;
  if ( !v4 || v4 >= 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_D4FD, "rtc6226_pinctrl_init");
    result = a1[187];
    a1[187] = 0;
    goto LABEL_12;
  }
  return 0;
}
