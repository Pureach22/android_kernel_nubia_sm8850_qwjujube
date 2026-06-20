__int64 __fastcall sde_hw_ctl_cesta_flush(__int64 result, _DWORD *a2)
{
  __int64 v3; // x19
  unsigned int v4; // w8
  int v5; // w9
  unsigned int v6; // w21
  int v7; // w4

  if ( result && a2 )
  {
    v3 = result;
    v4 = ((int)(a2[1] << 29) >> 31) & 0x80010000 | __rbit32(a2[1] & 3);
    if ( (a2[1] & 8) != 0 )
    {
      v4 |= 6u;
    }
    else
    {
      v5 = a2[2];
      if ( (unsigned int)(v5 - 3) < 2 || v5 == 1 )
      {
        v4 |= 2u;
      }
      else if ( v5 == 2 )
      {
        v4 |= 4u;
      }
    }
    result = sde_reg_write(result, (unsigned int)(4 * *a2 + 768), v4 | 1, "CTL_CESTA_FLUSH + (cfg->index * 0x4)");
    if ( (a2[1] & 8) != 0 )
    {
      result = sde_reg_read(v3, 832);
      if ( ((unsigned int)result & (unsigned int)(1LL << *a2)) != 0 )
      {
        v6 = 0;
        do
        {
          usleep_range_state(50, 60, 2);
          result = sde_reg_read(v3, 832);
          v7 = result & (1LL << *a2);
          if ( !v7 )
            break;
        }
        while ( v6++ < 0x13 );
        if ( v7 )
          return printk(&unk_22183A, "sde_hw_ctl_cesta_flush");
      }
    }
  }
  return result;
}
