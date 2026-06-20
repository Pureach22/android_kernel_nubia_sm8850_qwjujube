__int64 __fastcall gpio_keys_show_GamekeyStatus(__int64 a1, __int64 a2, char *a3, __int64 a4, __int64 a5, __int64 a6)
{
  _DWORD *v6; // x9
  __int64 v8; // x8
  _DWORD *v9; // x20
  __int64 v10; // x9
  int value_cansleep; // w0
  unsigned int v12; // w8
  int v13; // w20
  __int64 v14; // x0
  int raw_value; // w0
  bool v16; // zf
  unsigned int v17; // w20

  v6 = *(_DWORD **)(a1 + 152);
  v8 = *(unsigned int *)(*(_QWORD *)v6 + 8LL);
  if ( (int)v8 < 1 )
  {
LABEL_13:
    v17 = -1;
  }
  else
  {
    v9 = v6 + 68;
    while ( 1 )
    {
      v10 = *((_QWORD *)v9 - 25);
      if ( v10 )
      {
        if ( **((_WORD **)v9 - 22) == 15 && *(_DWORD *)(v10 + 24) == 5 )
          break;
      }
      --v8;
      v9 += 68;
      if ( !v8 )
        goto LABEL_13;
    }
    value_cansleep = gpiod_get_value_cansleep(*((_QWORD *)v9 - 23));
    v12 = *v9;
    v13 = value_cansleep;
    v14 = gpio_to_desc(v12);
    raw_value = gpiod_get_raw_value(v14);
    if ( v13 )
      v16 = 1;
    else
      v16 = raw_value == 0;
    v17 = !v16;
  }
  printk(&unk_844D, v17, a3, a4, a5, a6);
  return snprintf(a3, 4u, "%d\n", v17);
}
