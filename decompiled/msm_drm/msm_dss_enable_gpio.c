__int64 __fastcall msm_dss_enable_gpio(__int64 a1, int a2, int a3)
{
  __int64 v3; // x30
  __int64 v5; // x22
  __int64 v6; // x24
  __int64 v7; // x25
  __int64 i; // x21
  unsigned int v9; // w20
  unsigned int v10; // w23
  __int64 v11; // x0
  __int64 v12; // x8
  __int64 v13; // x20
  unsigned int *v14; // x19
  __int64 v16; // x0
  unsigned int v17; // t1
  int v19; // w21
  __int64 v20; // x0

  if ( !a3 )
  {
    v12 = (unsigned int)(a2 - 1);
    if ( a2 - 1 >= 0 )
    {
      v13 = v12 + 1;
      v14 = (unsigned int *)(a1 + 40LL * (unsigned int)v12);
      do
      {
        v17 = *v14;
        v14 -= 10;
        v16 = v17;
        if ( v17 )
          gpio_free(v16);
      }
      while ( v13-- > 1 );
    }
    return 0;
  }
  if ( a2 < 1 )
    return 0;
  v5 = v3;
  v6 = 0;
  v7 = (unsigned int)a2;
  for ( i = a1 + 8; ; i += 40 )
  {
    v9 = gpio_request(*(unsigned int *)(i - 8));
    if ( (v9 & 0x80000000) != 0 )
      break;
    v10 = *(_DWORD *)(i - 4);
    v11 = gpio_to_desc(*(unsigned int *)(i - 8));
    gpiod_set_raw_value(v11, v10);
    if ( v7 == ++v6 )
      return v9;
  }
  printk(&unk_22ECE5, v5);
  if ( (_DWORD)v6 )
  {
    v19 = v6 + 1;
    do
    {
      v20 = *(unsigned int *)(a1 + 40LL * (unsigned int)(v19 - 2));
      if ( (_DWORD)v20 )
        gpio_free(v20);
      --v19;
    }
    while ( v19 > 1 );
  }
  return v9;
}
