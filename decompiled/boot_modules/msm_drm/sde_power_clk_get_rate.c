__int64 __fastcall sde_power_clk_get_rate(__int64 a1, char *s2)
{
  int v2; // w20
  __int64 v3; // x22
  int v5; // w21
  __int64 v6; // x24

  if ( a1 )
  {
    v2 = *(_DWORD *)(a1 + 32);
    if ( v2 )
    {
      v3 = *(_QWORD *)(a1 + 40);
      v5 = 0;
      while ( 1 )
      {
        v6 = v3 + 120LL * v5;
        if ( !strcmp((const char *)(v6 + 8), s2) )
          break;
        if ( v2 == ++v5 )
          return -22;
      }
      return clk_get_rate(*(_QWORD *)v6);
    }
    else
    {
      return -22;
    }
  }
  else
  {
    printk(&unk_27E885, "sde_power_clk_get_rate");
    return -22;
  }
}
