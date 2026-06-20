__int64 __fastcall gpio_keys_gpio_report_event(unsigned int **a1)
{
  unsigned int *v1; // x19
  unsigned int *v2; // x23
  unsigned int v4; // w24
  unsigned int v5; // w20
  __int64 v6; // x0
  int raw_value; // w22
  __int64 v8; // x0
  __int64 result; // x0
  __int64 v10; // x3
  __int64 v11; // x4
  __int64 v12; // x5
  int v13; // w22
  int value_cansleep; // w0
  _BOOL4 v15; // w8
  unsigned int *v16; // x9
  _BOOL4 v17; // w21
  __int64 v18; // x4
  __int64 v19; // x5
  __int64 v20; // x2
  void *v21; // x0
  __int64 v22; // x1
  __int64 v23; // x3

  v2 = *a1;
  v1 = a1[1];
  v4 = (*a1)[6];
  if ( v4 <= 1 )
    v5 = 1;
  else
    v5 = (*a1)[6];
  if ( ((_DWORD)a1[25] & 0x80000000) != 0 )
  {
LABEL_8:
    v13 = *(unsigned __int16 *)a1[3];
    value_cansleep = gpiod_get_value_cansleep(a1[2]);
    if ( v13 == 15 && v4 == 5 )
    {
      v15 = value_cansleep == 0;
    }
    else
    {
      if ( value_cansleep < 0 )
        return dev_err(*((_QWORD *)v1 + 82), "failed to get gpio state: %d\n", value_cansleep);
      if ( v4 == 3 )
      {
        if ( !value_cansleep )
          return input_event(v1, 0, 0, 0);
        input_event(v1, 3, *v2, v2[11]);
        v20 = *v2;
        v23 = v2[11];
        v21 = &unk_8354;
        v22 = 3;
LABEL_21:
        printk(v21, v22, v20, v23, v18, v19);
        return input_event(v1, 0, 0, 0);
      }
      v15 = value_cansleep;
    }
    v16 = a1[3];
    v17 = v15;
    input_event(v1, v5, *(unsigned __int16 *)v16, v15);
    v20 = *v2;
    v21 = &unk_87B8;
    v22 = v5;
    v23 = v17;
    goto LABEL_21;
  }
  v6 = gpio_to_desc(*((unsigned int *)a1 + 49));
  raw_value = gpiod_get_raw_value(v6);
  v8 = gpio_to_desc(*((unsigned int *)a1 + 50));
  result = gpiod_get_raw_value(v8);
  if ( (raw_value == 0) == ((_DWORD)result == 0) )
    return printk(&unk_886D, "nb_key_is_need_report", raw_value == 0, v10, v11, v12);
  if ( nb_key_is_need_report_stat_rec != (((_DWORD)result == 0) | (2 * (raw_value == 0))) )
  {
    nb_key_is_need_report_stat_rec = ((_DWORD)result == 0) | (2 * (raw_value == 0));
    goto LABEL_8;
  }
  return result;
}
