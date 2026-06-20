__int64 __fastcall gf_hw_reset(__int64 a1, int a2)
{
  void *v2; // x0
  __int64 v3; // x19
  __int64 v5; // x0
  __int64 v6; // x0

  if ( !a1 )
  {
    v2 = &unk_9404;
    LODWORD(v3) = -19;
LABEL_9:
    printk(v2);
    return (unsigned int)v3;
  }
  if ( (*(_DWORD *)(a1 + 64) & 0x80000000) != 0 )
  {
    v2 = &unk_9234;
    LODWORD(v3) = 0;
    goto LABEL_9;
  }
  LODWORD(v3) = a2;
  printk(&unk_8F41);
  v5 = gpio_to_desc(*(unsigned int *)(a1 + 64));
  gpiod_set_raw_value(v5, 0);
  usleep_range_state(10000, 10100, 2);
  v6 = gpio_to_desc(*(unsigned int *)(a1 + 64));
  gpiod_set_raw_value(v6, 1);
  if ( (_DWORD)v3 )
  {
    v3 = (unsigned int)v3;
    do
    {
      --v3;
      _const_udelay(4295000);
    }
    while ( v3 );
  }
  return (unsigned int)v3;
}
