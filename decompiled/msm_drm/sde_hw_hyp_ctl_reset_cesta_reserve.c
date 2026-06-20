__int64 __fastcall sde_hw_hyp_ctl_reset_cesta_reserve(__int64 result, int a2)
{
  int v2; // w20
  __int64 v3; // x19
  unsigned int v4; // w21

  if ( !result )
    return printk(&unk_223EAA, "sde_hw_hyp_ctl_reset_cesta_reserve");
  v2 = a2;
  if ( a2 )
  {
    v3 = result;
    v4 = 324;
    do
    {
      result = sde_reg_write(v3 + 32, v4, 0, "HYP_CTL_CESTA_RESERVE + (i * 0x80)");
      --v2;
      v4 += 128;
    }
    while ( v2 );
  }
  return result;
}
