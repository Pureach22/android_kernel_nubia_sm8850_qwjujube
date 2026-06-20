__int64 __fastcall alpha_pll_pongo_elu_enable(__int64 a1)
{
  __int64 v2; // x19
  __int64 v3; // x1
  unsigned int *v4; // x20
  int v5; // w22
  __int64 result; // x0
  _QWORD v7[2]; // [xsp+0h] [xbp-10h] BYREF

  v7[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 24);
  v4 = (unsigned int *)(a1 - 48);
  v3 = *(unsigned int *)(a1 - 48);
  v7[0] = 0;
  v5 = regmap_read(v2, v3, (char *)v7 + 4);
  if ( !((unsigned int)regmap_read(v2, *v4 + *(unsigned __int8 *)(*((_QWORD *)v4 + 1) + 19LL), v7) | v5)
    && (v7[0] & 1) != 0
    && (v7[0] & 0x100000000LL) != 0 )
  {
    clk_hw_get_name(a1);
    printk(&unk_29592);
    result = 0;
  }
  else
  {
    result = regmap_update_bits_base(v2, *v4, 4, 4, 0, 0, 0);
    if ( !(_DWORD)result )
    {
      regmap_write(v2, *(_DWORD *)(a1 - 48) + (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(a1 - 40) + 19LL), 1);
      result = wait_for_pll(v4, 0x80000000LL, 0, "enable");
      if ( !(_DWORD)result )
      {
        result = regmap_update_bits_base(v2, *v4, 1, 1, 0, 0, 0);
        if ( !(_DWORD)result )
          __dsb(0xFu);
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
