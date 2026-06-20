__int64 __fastcall sde_power_clk_get_clk(__int64 a1, char *s2)
{
  int v2; // w20
  __int64 v3; // x22
  int v5; // w21
  const char *v6; // x24

  if ( a1 )
  {
    v2 = *(_DWORD *)(a1 + 32);
    if ( v2 )
    {
      v3 = *(_QWORD *)(a1 + 40);
      v5 = 0;
      while ( 1 )
      {
        v6 = (const char *)(v3 + 120LL * v5);
        if ( !strcmp(v6 + 8, s2) )
          break;
        if ( v2 == ++v5 )
          return 0;
      }
      return *(_QWORD *)v6;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    printk(&unk_27E885, "sde_power_clk_get_clk");
    return 0;
  }
}
