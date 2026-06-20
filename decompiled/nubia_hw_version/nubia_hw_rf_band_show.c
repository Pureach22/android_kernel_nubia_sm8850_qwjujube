__int64 __fastcall nubia_hw_rf_band_show(int a1, int a2, char *s)
{
  _QWORD *v3; // x9
  __int64 v5; // x8
  const char *v6; // x3
  char *v7; // x19
  const char *v8; // x20

  if ( !s )
    return 0;
  if ( nubia_rf_gpio1_v == 2 )
  {
    if ( (unsigned int)_UNIQUE_ID_vermagic534[20] < 3 )
    {
      v3 = &unk_7A00;
      goto LABEL_12;
    }
LABEL_14:
    v6 = "unknow";
    goto LABEL_15;
  }
  if ( nubia_rf_gpio1_v != 1 )
  {
    if ( !nubia_rf_gpio1_v && (unsigned int)_UNIQUE_ID_vermagic534[20] < 3 )
    {
      v3 = &unk_79E8;
LABEL_12:
      v5 = v3[_UNIQUE_ID_vermagic534[20]];
      goto LABEL_13;
    }
    goto LABEL_14;
  }
  if ( _UNIQUE_ID_vermagic534[20] )
    goto LABEL_14;
  v5 = 6;
LABEL_13:
  v6 = (char *)&hw_rf_band_gpio_map + 20 * v5 + 8;
LABEL_15:
  if ( debug_value == 1 )
  {
    v7 = s;
    v8 = v6;
    printk(byte_763E, v6);
    v6 = v8;
    s = v7;
  }
  return snprintf(s, 0xCu, "%s", v6);
}
