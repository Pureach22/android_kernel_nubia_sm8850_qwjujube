__int64 __fastcall sde_power_set_clk_retention(__int64 a1, char *s2)
{
  int v3; // w21
  __int64 v4; // x23
  int v5; // w22
  __int64 v6; // x25

  if ( !a1 )
    return printk(&unk_27E885, "sde_power_set_clk_retention");
  if ( !s2 )
    return printk(&unk_26326A, "sde_power_set_clk_retention");
  v3 = *(_DWORD *)(a1 + 32);
  if ( !v3 )
    return printk(&unk_246ED2, "sde_power_set_clk_retention");
  v4 = *(_QWORD *)(a1 + 40);
  v5 = 0;
  while ( 1 )
  {
    v6 = v4 + 120LL * v5;
    if ( !strcmp((const char *)(v6 + 8), s2) )
      break;
    if ( v3 == ++v5 )
      return printk(&unk_246ED2, "sde_power_set_clk_retention");
  }
  if ( *(_QWORD *)v6 )
    return qcom_clk_set_flags();
  else
    return printk(&unk_246ED2, "sde_power_set_clk_retention");
}
