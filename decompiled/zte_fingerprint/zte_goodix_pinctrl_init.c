__int64 __fastcall zte_goodix_pinctrl_init(unsigned int *a1)
{
  unsigned __int64 v2; // x0
  const char *v3; // x1
  unsigned int *v4; // x20
  unsigned __int64 v5; // x0
  unsigned __int64 v6; // x0
  __int64 result; // x0

  printk(&unk_8D5F);
  v2 = devm_pinctrl_get(*((_QWORD *)a1 + 3) + 16LL);
  v3 = "Target does not use pinctrl\n";
  *((_QWORD *)a1 + 15) = v2;
  v4 = a1 + 30;
  if ( v2 )
  {
    if ( v2 <= 0xFFFFFFFFFFFFF000LL )
    {
      v5 = ((__int64 (*)(void))pinctrl_lookup_state)();
      v3 = "Can not get goodix_active pinstate\n";
      *((_QWORD *)a1 + 16) = v5;
      v4 = a1 + 32;
      if ( v5 )
      {
        if ( v5 <= 0xFFFFFFFFFFFFF000LL )
        {
          v6 = pinctrl_lookup_state(*((_QWORD *)a1 + 15), "goodix_suspend");
          v3 = "Can not get goodix_suspend pinstate\n";
          *((_QWORD *)a1 + 17) = v6;
          v4 = a1 + 34;
          if ( v6 )
          {
            if ( v6 < 0xFFFFFFFFFFFFF001LL )
              return 0;
          }
        }
      }
    }
  }
  dev_err(*((_QWORD *)a1 + 3) + 16LL, v3);
  result = *v4;
  *((_QWORD *)a1 + 15) = 0;
  return result;
}
