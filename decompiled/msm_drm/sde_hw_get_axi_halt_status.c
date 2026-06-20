__int64 __fastcall sde_hw_get_axi_halt_status(__int64 a1)
{
  __int64 v2; // x20
  __int64 v3; // x0
  __int64 v4; // x20

  v2 = ktime_get(a1);
  v3 = sde_reg_read(a1, 0x20Cu);
  if ( (v3 & 1) != 0 )
  {
LABEL_5:
    if ( (v3 & 1) != 0 )
      return 0;
  }
  else
  {
    v4 = v2 + 4000000;
    while ( ktime_get(v3) <= v4 )
    {
      usleep_range_state(26, 100, 2);
      __yield();
      v3 = sde_reg_read(a1, 0x20Cu);
      if ( (v3 & 1) != 0 )
        goto LABEL_5;
    }
    if ( (sde_reg_read(a1, 0x20Cu) & 1) != 0 )
      return 0;
  }
  if ( (~(unsigned int)sde_reg_read(a1, 0x20Cu) & 0x30) != 0 )
  {
    printk(&unk_2749C5, 4294967186LL);
    return 4294967186LL;
  }
  return 0;
}
