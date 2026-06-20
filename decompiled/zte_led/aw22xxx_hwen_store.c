__int64 __fastcall aw22xxx_hwen_store(__int64 a1, int a2, char *s, __int64 a4)
{
  __int64 v5; // x20
  __int64 v7; // x0
  __int64 v8; // x0
  unsigned int v9; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 152);
  v9 = 0;
  if ( sscanf(s, "%x", &v9) == 1 && v9 < 2 )
  {
    if ( v9 == 1 )
    {
      aw22xxx_hw_reset(v5 - 16);
    }
    else
    {
      printk(&unk_130E1, "aw22xxx_hw_off");
      if ( v5 == 16 || (v7 = *(unsigned int *)(v5 + 720), (v7 & 0x80000000) != 0) )
      {
        dev_err(*(_QWORD *)(v5 - 8), "%s:  failed\n", "aw22xxx_hw_off");
      }
      else
      {
        v8 = gpio_to_desc(v7);
        gpiod_set_raw_value_cansleep(v8, 0);
        usleep_range_state(1000, 1500, 2);
      }
    }
  }
  else
  {
    printk(&unk_12D0C, "aw22xxx_hwen_store");
    a4 = -22;
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
